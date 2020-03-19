//
//  UIImage+Category.h
//  NewCampusEdition
//
//  Created by PingXuhui on 2017/5/24.
//  Copyright © 2017年 PingXuhui. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 渐变类型

 - GradientTypeTopToBottom: 从上到下
 - GradientTypeLeftToRight: 从左到右
 - GradientTypeUpleftToLowright: 左上到右下
 - GradientTypeUprightToLowleft: 右上到左下
 */
typedef NS_ENUM(NSUInteger, GradientType) {
    GradientTypeTopToBottom = 0,//从上到下
    GradientTypeLeftToRight = 1,//从左到右
    GradientTypeUpleftToLowright = 2,//左上到右下
    GradientTypeUprightToLowleft = 3,//右上到左下
};

typedef NS_ENUM(NSUInteger, ColorType) {
    ColorTypeDefault = 0,//默认
    ColorTypeCustom = 1,//自定义
};

typedef void(^GIFImageBlock) (UIImage *GIFImage);


@interface UIImage (Category)

#pragma mark - 视频帧

/// 获取视频某一帧
+ (UIImage*) thumbnailImageForVideo:(NSURL *)videoURL atTime:(NSTimeInterval)time;

#pragma mark - 图片颜色/ 渐变色
/**
 获取渐变色背景图片

 @param colors 色值数组 UIColor 类型
 @param gradientType 渐变方向
 @param imgSize 大小
 @return 返回渐变色图片
 */
+ (UIImage *)gradientColorImageFromColors:(NSArray*)colors gradientType:(GradientType)gradientType imgSize:(CGSize)imgSize;

/**
 获取渐变色背景图片,渐变色已设置固定值，可以统一调用
 
 @param gradientType 渐变方向
 @param size 大小
 @return 返回渐变色图片
 */
+ (UIImage *)gradientType:(GradientType)gradientType imageSize:(CGSize)size;


/**
 渐变色

 @param colorAry 色值color
 @param gradientType <#gradientType description#>
 @param size <#size description#>
 @return <#return value description#>
 */
+ (UIImage *)gradientColorArray:(NSArray *)colorAry gradientType:(GradientType)gradientType imageSize:(CGSize)size;

/**
 颜色转换为图片

 @param color <#color description#>
 @return <#return value description#>
 */
+ (UIImage*)createImageWithColor:(UIColor *)color;

/**
 CAGradientLayer 渐变色
 
 @param view <#view description#>
 @param fromHexColorStr <#fromHexColorStr description#>
 @param toHexColorStr <#toHexColorStr description#>
 @return <#return value description#>
 */
+ (CAGradientLayer *)setGradualChangingColor:(UILabel *)view fromColor:(NSString *)fromHexColorStr toColor:(NSString *)toHexColorStr;

#pragma mark - 图片指定大小 / 切图 
/**
 *将图片缩放到指定的CGSize大小
 * UIImage image 原始的图片
 * CGSize size 要缩放到的大小
 */
+(UIImage*)image:(UIImage *)image scaleToSize:(CGSize)size;

/**
 *从图片中按指定的位置大小截取图片的一部分
 * UIImage image 原始的图片
 * CGRect rect 要截取的区域
 */
+ (UIImage *)imageFromImage:(UIImage *)image inRect:(CGRect)rect;
//
/**
 按形状切割图像

 @param radius radius
 @param rect 尺寸
 @param image 要切割的图片
 @return <#return value description#>
 */
+ (UIImage*)cutImageWithRadius:(int)radius inRect:(CGRect)rect fromImage:(UIImage *)image;

+ (UIImage*)circleImage:(UIImage*) image withParam:(CGFloat) inset;

#pragma mark - UIImage GIF

/**
 根据本地GIF图片名，获取GIF image对象

 @param name <#name description#>
 @return <#return value description#>
 */
+ (UIImage *)imageWithGIFNamed:(NSString *)name;

/**
 根据一个GIF图片的data数据，获取GIF image 对象

 @param data <#data description#>
 @return <#return value description#>
 */
+ (UIImage *)imageWithGIFData:(NSData *)data;

/**
 根据一个GIF图片的URL，获取GIF image对象

 @param url <#url description#>
 @param imageBlock <#imageBlock description#>
 */
+ (void)imageWithGIFUrl:(NSString *)url gifImageBlock:(GIFImageBlock)imageBlock;

/**
 传入需要的占位图尺寸 获取占位图
 @param size 需要的站位图尺寸
 @return 占位图
 */
+ (UIImage *)placeholderImageWithSize:(CGSize)size;

/**
 传入需要的占位图尺寸 获取占位图
 @param size 需要的站位图尺寸
 @return 占位图
 */
+ (UIImage *)placeholderImageWithSize:(CGSize)size imageNamed:(NSString *)name;

/**
 设置默认图片 v2.0
 
 @param image UIImage
 @param vi UIImageView
 @return UIImage
 */
+ (UIImage *)placeholderImage:(UIImage *)image withView:(UIImageView *)vi;

/**
 根据字符串生成二维码

 @param dataString 要生成二维码的字符串
 @return <#return value description#>
 */
+ (UIImage *)generateImageForQRCode:(NSString *)dataString;

/**
*  根据CIImage生成指定大小的UIImage
*
*  @param image CIImage
*  @param size  图片宽度
*/
+ (UIImage *)createNonInterpolatedUIImageFormCIImage:(CIImage *)image withSize:(CGFloat)size;

@end
