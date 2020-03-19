//
//  NSString+Category.h
//  YioksNike
//
//  Created by PingXuhui on 2019/3/20.
//  Copyright © 2019 Ping. All rights reserved.
//
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface NSString (Category)


/**
 计算文字的宽度

 @param size 控件的 size
 @param font 文字的font
 @return 返回文字的 size
 */
- (CGSize)boundingSize:(CGSize)viewSize textFont:(UIFont *)font;

/**
 字符串不为空
 
 @param string 待检测字符串
 @return 检测结果
 */
+ (BOOL) isNotBlankString:(NSString *)string;

/**
 *  字符串为空
 *
 *  @param string 要判断的字符串
 *
 *  @return 返回值：真或假
 */
+ (BOOL) isBlankString:(NSString *)string;

/**
 *  行间距设置 spacing：大小 textSpacing：字体间距
 */
+ (NSMutableAttributedString *)setLineSpacingString:(NSString *)textStr lineSpacing:(CGFloat)spacing textSpacing:(CGFloat)textSpacing;

/**
 *  从一个字符串截取到另一个字符串
 *
 *  @param str      要截取的字符串
 *  @param startStr 开始截取的字符串
 *  @param endStr   结束截取字符串之后的字符串
 *
 *  @return 截取好的字符串
 */
+ (NSString *)cutString:(NSString *)str StartString:(NSString *)startStr toEndString:(NSString *)endStr;

/**
 *  从某个字符串截取到最后
 *  @param str   要截取的字符串
 *  @param startStr  开始截取的字符串
 *
 *  @return  截取好的字符串
 */
+ (NSString *)cutString:(NSString *)str startString:(NSString *)startStr;

/**
 获取时间戳(精准)
 
 @param datetime 要转成时间戳的 NSDate
 @return <#return value description#>
 */
+ (NSString *)getTiemstampForDateTime:(NSDate *)datetime;

/**
 *  格式化时间
 *
 *  @param format 格式化样式
 *
 *  @return 返回格式化后的时间
 */
+ (NSString *)formatterTime:(NSString *)format;


/**
 *  时间戳转时间
 *
 *  @param format 格式化样式
 *
 *  @return 返回格式化后的时间
 */
+ (NSString *)formatter:(NSString *)format stampString:(NSString *)stamp;

/**
 *  将阿拉伯数字转换为中文数字
 */
+ (NSString *)translationArabicNum:(NSInteger)arabicNum;


/// 将字符串中的空格替换掉
+ (NSString *)noneSpaseString:(NSString *)string;

// MARK: 将银行卡号的前4位和后4位是明文，中间隐藏
/**
 * 将银行卡号的前4位和后4位是明文，中间隐藏
 */
+ (NSString *)returnBankCard:(NSString *)bankCardString;

@end

NS_ASSUME_NONNULL_END
