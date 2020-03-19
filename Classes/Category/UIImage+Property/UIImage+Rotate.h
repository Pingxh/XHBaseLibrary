//
//  UIImage+Rotate.h
//  EastAsiaOilCard
//
//  Created by PingXuhui on 2018/2/5.
//  Copyright © 2018年 PingXuhui. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Rotate)

/** 纠正图片的方向 */
/// 纠正图片的方向
- (UIImage *)fixOrientation;

/** 按给定的方向旋转图片 */
/// 按给定的方向旋转图片
- (UIImage*)rotate:(UIImageOrientation)orient;

/** 垂直翻转 */
/// 垂直翻转
- (UIImage *)flipVertical;

/** 水平翻转 */
/// 水平翻转
- (UIImage *)flipHorizontal;

/** 将图片旋转degrees角度 */
/// 将图片旋转degrees角度
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/** 将图片旋转radians弧度 */
/// 将图片旋转radians弧度
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;

@end
