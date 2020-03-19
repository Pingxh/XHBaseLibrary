//
//  UIFont+Config.h
//  YioksNike
//
//  Created by PingXuhui on 2018/8/13.
//  Copyright © 2018年 Ping. All rights reserved.
//

#import <UIKit/UIKit.h>

#define FONT_SCREEN_WIDTH(WIDTH) WIDTH * [UIScreen mainScreen].bounds.size.width / 414.0

@interface UIFont (Config)

+ (UIFont *)PingFangSCRegular:(CGFloat)font;

+ (UIFont *)PingFangSCMedium:(CGFloat)font;

+ (UIFont *)PingFangSCLight:(CGFloat)font;

@end
