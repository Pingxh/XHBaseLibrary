//
//  UIResponder+Category.m
//  EastAsiaOilCard
//
//  Created by PingXuhui on 2018/2/1.
//  Copyright © 2018年 PingXuhui. All rights reserved.
//

#import "UIResponder+Category.h"

static __weak id currentFirstResponder;
@implementation UIResponder (Category)

// MARK: 获取当前正在输入的控件
+(id)currentFirstResponder {
    currentFirstResponder = nil;
    [[UIApplication sharedApplication] sendAction:@selector(findFirstResponder:) to:nil from:nil forEvent:nil];
    return currentFirstResponder;
}

-(void)findFirstResponder:(id)sender {
    currentFirstResponder = self;
}

@end
