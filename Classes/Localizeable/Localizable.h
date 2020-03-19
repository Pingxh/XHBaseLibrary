//
//  Localizable.h
//  BaseFramework
//
//  Created by PingXuhui on 2018/9/12.
//  Copyright © 2018年 Pxh. All rights reserved.
//

#import <Foundation/Foundation.h>

// 简体中文
#define Chinese_Hans @"zh-Hans"
// 繁体中文
#define Chinese_Hant @"zh-Hant"
// 英文
#define English      @"en"

#define NotificationLanguageChanged  @"languageChanged"

#define LanguageKey                  @"language"

#define CurrentLanguageIsChinese        ([[InternationalControl chineseHans] containsObject:[Localizable userLanguage]])

@interface Localizable : NSObject

/**
 * 初始化
 */
+ (void)initUserLanguage;

/**
 * 设置当前语言
 *
 * @param language 当前语言字符串形式
 */
+ (void)setUserlanguage:(NSString *)language;

/**
 * 获取当前语言
 *
 * @return 当前语言
 */
+ (NSString *)userLanguage;

@end
