//
//  XHStringOperation.m
//  YioksQRCode
//
//  Created by PingXuhui on 16/1/19.
//  Copyright © 2016年 Yioks. All rights reserved.
//

#import "XHStringOperation.h"


@implementation XHStringOperation

/**
 非空检测
 
 @param string 待检测字符串
 @return 检测结果
 */
+ (BOOL) isNotBlankString:(NSString *)string{
    return ![XHStringOperation isBlankString:string];
}

+ (BOOL) isBlankString:(NSString *)string {
    if (string == nil || string == NULL) {
        return YES;
    }
    if ([string isEqualToString:@"<null>"] || [string isEqualToString:@"(null)"]) {
        return YES;
    }
    if ([string isEqual:[NSNull null]]) {
        return YES;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return YES;
    }
    return NO;
}

+ (NSMutableAttributedString *)setLineSpacingString:(NSString *)textStr lineSpacing:(CGFloat)spacing textSpacing:(CGFloat)textSpacing
{
    NSMutableAttributedString * attributedString = [[NSMutableAttributedString alloc] initWithString:textStr attributes:@{NSKernAttributeName:@(textSpacing)}];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle setLineSpacing:spacing];
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [textStr length])];
    return attributedString;
}


+ (NSString *)cutString:(NSString *)str StartString:(NSString *)startStr toEndString:(NSString *)endStr
{
    NSString *pageStart = startStr;
    NSString *pageEnd = endStr;
    NSUInteger startOffset = [str rangeOfString:pageStart].location;
    NSUInteger endOffset = [str rangeOfString:pageEnd].location;
    NSString *result = [str substringWithRange:NSMakeRange(startOffset, endOffset-startOffset)];
    return result;
}

+ (NSString *)cutString:(NSString *)str startString:(NSString *)startStr
{
    NSString *pageStart = startStr;
    NSUInteger startOffset = [str rangeOfString:pageStart].location + startStr.length;
    NSString *result = [str substringFromIndex:startOffset];
    return result;
}


+ (NSString *)getTimestamp
{
    // 把时间转为时间戳
    NSDate *localDate = [NSDate date]; //当前时间
    NSString *timeSp = [NSString stringWithFormat:@"%ld",(long)[localDate timeIntervalSince1970]];  // 转为 UNIX 时间戳
    return timeSp;
}

// MARK: 将NSDate类型的时间转换为时间戳,从1970/1/1开始
+ (NSString *)getDateTimeTOMilliSeconds:(NSDate *)datetime{
    NSTimeInterval interval = [datetime timeIntervalSince1970];
    NSLog(@"转换的时间戳=%f",interval);
    long long totalMilliseconds = interval * 1000 ;
    
    NSLog(@"totalMilliseconds=%llu",totalMilliseconds);
    //    NSString * timeSp = []
    return [NSString stringWithFormat:@"%lld", totalMilliseconds];
}

+ (NSString *)formatterTime:(NSString *)format
{
    // 在网络开发中，上传文件时，是文件不允许被覆盖，文件重名
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    // 设置时间格式
    formatter.dateFormat = format;
    NSString *timeStr = [formatter stringFromDate:[NSDate date]];
    return timeStr;
}

/**
 时间戳转时间
 
 @param format 格式化样式
 @param stamp 时间戳
 @return 返回格式化后的时间
 */
+ (NSString *)formatterTime:(NSString *)format stampString:(NSString *)stamp {
    NSTimeInterval interval;
    if (stamp.length == 13) {
        interval = [stamp doubleValue] / 1000.0;
    } else {
        interval = [stamp doubleValue];
    }
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:interval];
    // 在网络开发中，上传文件时，是文件不允许被覆盖，文件重名
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    // 设置时间格式
    formatter.dateFormat = format;
    NSString *timeStr = [formatter stringFromDate:date];
    return timeStr;
}


/**
 *  将阿拉伯数字转换为中文数字
 */
+(NSString *)translationArabicNum:(NSInteger)arabicNum
{
    NSString *arabicNumStr = [NSString stringWithFormat:@"%ld",(long)arabicNum];
    NSArray *arabicNumeralsArray = @[@"1",@"2",@"3",@"4",@"5",@"6",@"7",@"8",@"9",@"0"];
    NSArray *chineseNumeralsArray = @[@"一",@"二",@"三",@"四",@"五",@"六",@"七",@"八",@"九",@"零"];
    NSArray *digits = @[@"个",@"十",@"百",@"千",@"万",@"十",@"百",@"千",@"亿",@"十",@"百",@"千",@"兆"];
    NSDictionary *dictionary = [NSDictionary dictionaryWithObjects:chineseNumeralsArray forKeys:arabicNumeralsArray];
    
    if (arabicNum < 20 && arabicNum > 9) {
        if (arabicNum == 10) {
            return @"十";
        }else{
            NSString *subStr1 = [arabicNumStr substringWithRange:NSMakeRange(1, 1)];
            NSString *a1 = [dictionary objectForKey:subStr1];
            NSString *chinese1 = [NSString stringWithFormat:@"十%@",a1];
            return chinese1;
        }
    }else{
        NSMutableArray *sums = [NSMutableArray array];
        for (int i = 0; i < arabicNumStr.length; i ++)
        {
            NSString *substr = [arabicNumStr substringWithRange:NSMakeRange(i, 1)];
            NSString *a = [dictionary objectForKey:substr];
            NSString *b = digits[arabicNumStr.length -i-1];
            NSString *sum = [a stringByAppendingString:b];
            if ([a isEqualToString:chineseNumeralsArray[9]])
            {
                if([b isEqualToString:digits[4]] || [b isEqualToString:digits[8]])
                {
                    sum = b;
                    if ([[sums lastObject] isEqualToString:chineseNumeralsArray[9]])
                    {
                        [sums removeLastObject];
                    }
                }else
                {
                    sum = chineseNumeralsArray[9];
                }
                
                if ([[sums lastObject] isEqualToString:sum])
                {
                    continue;
                }
            }
            
            [sums addObject:sum];
        }
        NSString *sumStr = [sums  componentsJoinedByString:@""];
        NSString *chinese = [sumStr substringToIndex:sumStr.length-1];
        return chinese;
    }
}

/// 将字符串中的空格替换掉
+ (NSString *)noneSpaseString:(NSString *)string {
    return [string stringByReplacingOccurrencesOfString:@" " withString:@""];
}

// MARK: 将银行卡号的前4位和后4位是明文，中间隐藏
/**
 * 将银行卡号的前4位和后4位是明文，中间隐藏
 */
+ (NSString *)returnBankCard:(NSString *)bankCardString {
    NSString *fromStr = [bankCardString substringToIndex:6];
    NSString *str1 = [bankCardString stringByReplacingOccurrencesOfString:fromStr withString:@""];
    NSString *endStr = [bankCardString substringFromIndex:bankCardString.length - 4];
    NSString *str2 = [str1 stringByReplacingOccurrencesOfString:endStr withString:@""];
    NSString *middleStr = [str2 stringByReplacingOccurrencesOfString:str2 withString:@"****"];
    NSString *cardNumberStr = [fromStr stringByAppendingFormat:@"%@%@", middleStr, endStr];
    return cardNumberStr;
}


@end
