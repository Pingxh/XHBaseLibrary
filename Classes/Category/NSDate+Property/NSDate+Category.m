//
//  NSDate+Category.m
//  BaseFramework
//
//  Created by PingXuhui on 2019/1/24.
//  Copyright © 2019 Pxh. All rights reserved.
//

#import "NSDate+Category.h"

@implementation NSDate (Category)


/**
 时间转换为时间戳
 
 @param datetime 要转换的时间
 @return 返回转换后的时间戳 long long 类型
 */
+ (long long)getDateTimeTOMilliSeconds:(NSDate *)datetime {
    NSTimeInterval interval = [datetime timeIntervalSince1970];
//    NSLog(@"转换的时间戳=%f",interval);
    long long totalMilliseconds = interval*1000 ;
//    NSLog(@"totalMilliseconds=%llu",totalMilliseconds);
    return totalMilliseconds;
}


/**
 时间戳转时间
 
 @param format 格式化样式
 @param stamp 时间戳
 @return 返回格式化后的时间
 */
+ (NSString *)formatterTime:(NSString *)format stampString:(NSString *)stamp {
    
    NSTimeInterval interval = [stamp doubleValue] / 1000.0;
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:interval];
    // 在网络开发中，上传文件时，是文件不允许被覆盖，文件重名
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    // 设置时间格式
    formatter.dateFormat = format;
    NSString *timeStr = [formatter stringFromDate:date];
    return timeStr;
}




@end
