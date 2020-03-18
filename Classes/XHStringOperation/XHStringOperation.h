//
//  XHStringOperation.h
//  YioksQRCode
//
//  Created by PingXuhui on 16/1/19.
//  Copyright © 2016年 Yioks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface XHStringOperation : NSObject

/**
 非空检测,字符串不为空，返回 YES,否则返回 NO
 
 @param string 待检测字符串
 @return 检测结果
 */
+ (BOOL) isNotBlankString:(NSString *)string;

/**
 *  字符串操作,字符串为空，返回 YES,否则返回 NO
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
 *  时间戳,不太精准
 */
+ (NSString *)getTimestamp;

/**
 获取时间戳(精准)
 
 @param datetime 要转成时间戳的 NSDate
 @return <#return value description#>
 */
+ (NSString *)getDateTimeTOMilliSeconds:(NSDate *)datetime;

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
+ (NSString *)formatterTime:(NSString *)format stampString:(NSString *)stamp;

/**
 *  将阿拉伯数字转换为中文数字
 */
+(NSString *)translationArabicNum:(NSInteger)arabicNum;


/// 将字符串中的空格替换掉
+ (NSString *)noneSpaseString:(NSString *)string;

// MARK: 将银行卡号的前4位和后4位是明文，中间隐藏
/**
 * 将银行卡号的前4位和后4位是明文，中间隐藏
 */
+ (NSString *)returnBankCard:(NSString *)bankCardString;


@end
