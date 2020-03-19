//
//  UIFont+Config.m
//  YioksNike
//
//  Created by PingXuhui on 2018/8/13.
//  Copyright © 2018年 Ping. All rights reserved.
//

#import "UIFont+Config.h"
#import <objc/runtime.h>

@implementation UIFont (Config)

+ (void)load {
    // 获取替换后的类方法
    Method newMethod = class_getClassMethod([self class], @selector(adjustFont:));
    // 获取替换前的类方法
    Method method = class_getClassMethod([self class], @selector(systemFontOfSize:));
    // 交换类方法, 交换两个方法的IMP指针，(IMP代表了方法的具体的实现）
    method_exchangeImplementations(newMethod, method);
}

+ (UIFont *)adjustFont:(CGFloat)fontSize {
    UIFont *newFont = nil;
    newFont = [UIFont adjustFont:FONT_SCREEN_WIDTH(fontSize)];
    return newFont;
}


+ (UIFont *)PingFangSCRegular:(CGFloat)font {
    return [UIFont fontWithName:@"PingFangSC-Regular" size:FONT_SCREEN_WIDTH(font)];
}

+ (UIFont *)PingFangSCMedium:(CGFloat)font {
    return [UIFont fontWithName:@"PingFangSC-Medium" size:FONT_SCREEN_WIDTH(font)];
}

+ (UIFont *)PingFangSCLight:(CGFloat)font {
    return [UIFont fontWithName:@"PingFangSC-Light" size:FONT_SCREEN_WIDTH(font)];
}

@end
