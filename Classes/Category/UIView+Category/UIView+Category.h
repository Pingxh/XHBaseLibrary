//
//  UIView+Category.h
//  RSADemo
//
//  Created by PingXuhui on 2018/6/8.
//  Copyright © 2018年 Ive. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Category)

/**
 * 判断一个控件是否真正显示在主窗口
 */
- (BOOL)isShowingOnKeyWindow;

/**
 * setCornerRadius   给view设置圆角
 * @param value      圆角大小
 * @param rectCorner 圆角位置
 **/
- (void)setCornerRadius:(CGFloat)value addRectCorners:(UIRectCorner)rectCorner;

@end
