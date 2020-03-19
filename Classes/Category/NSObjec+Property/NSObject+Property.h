//
//  NSObject+Property.h
//  EastAsiaOilCard
//
//  Created by PingXuhui on 2018/1/23.
//  Copyright © 2018年 PingXuhui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSObject (Property)

// MARK: 加载 nib 视图
- (id)loadNibNamed:(NSString *)nibName view:(UIView *)view;

// MARK: 通过子视图获取父视图
- (UIViewController *)controller:(UIView *)view;

/**
 归档信息
 
 @param obj <#userInfo description#>
 @param key key
 */
- (BOOL)keyedArchiver:(id)obj key:(NSString *)key;
/**
 解档信息
 
 @return <#return value description#>
 */
- (id)keyedUnarchiverWithKey:(NSString *)key;

/**
 删除指定归档的文件
 */
- (void)deleteKeyedArchiverFile:(NSString *)fileName;

/**
 删除所有归档的文件
 */
- (void)deleteKeyedArchiverFile;

/*!
 * @brief 把格式化的JSON格式的字符串转换成字典
 * @param jsonString JSON格式的字符串
 * @return 返回字典
 */
- (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

// MARK: 汉字转拼音
/**
 汉字转拼音
 
 @param chinese <#chinese description#>
 @return <#return value description#>
 */
- (NSString *)transformPinYin:(NSString *)chinese;


/**
 判断图片url是否包含http / https

 @param urlStr 图片的URL
 @param server 图片的域名 如果url不包含域名，则使用此域名
 @return <#return value description#>
 */
- (NSString *)imageUrlHandler:(NSString *)urlStr server:(NSString *)server;

/// 手机号 固话验证
- (BOOL)validateContactNumber:(NSString *)mobileNum;

///  只验证手机号
- (BOOL)validateCellPhoneNumber:(NSString *)cellNum;

/// 验证身份证
- (BOOL)checkIDCard:(NSString *)identityCard;

/**
 验证网址
 
 @param http 要验证的字符串
 @return <#return value description#>
 */
- (BOOL)validateHttp:(NSString *)http;

/// 验证嗨兔卡
- (BOOL)validateHiToCardHttp:(NSString *)http;


@end
