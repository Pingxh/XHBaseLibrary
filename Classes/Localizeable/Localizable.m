//
//  Localizable.m
//  BaseFramework
//
//  Created by PingXuhui on 2018/9/12.
//  Copyright © 2018年 Pxh. All rights reserved.
//

#import "Localizable.h"
#import "NSBundle+Language.h"

static Localizable *currentLanguage;

@implementation Localizable

+ (void)initUserLanguage {
    NSString *language = [Localizable userLanguage];
    if ([[Localizable chineseHans] containsObject:language]) {
        language = [[Localizable chineseHans] firstObject];
    } else if ([[Localizable chineseHant] containsObject:language]) {
        language = [Localizable chineseHant].firstObject;
    } else if ([[Localizable english] containsObject:language]) {
        language = [Localizable english].firstObject;
    }
    
    [[NSUserDefaults standardUserDefaults] setObject:language forKey:LanguageKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
    [NSBundle setLanguage:language];
    [[NSNotificationCenter defaultCenter] postNotificationName:NotificationLanguageChanged object:currentLanguage];
}

+ (NSArray *)english {
    return @[@"en", @"en-CN"];
}

+ (NSArray *)chineseHans {
    return @[@"zh-Hans", @"zh-Hans-CN"];
}

+ (NSArray *)chineseHant {
    return @[@"zh-Hant", @"zh-Hant-CN"];
}

// 设置当前语言
+ (void)setUserlanguage:(NSString *)language {
    if ([[Localizable userLanguage] isEqualToString:language]) return;
    [[NSUserDefaults standardUserDefaults] setObject:language forKey:LanguageKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
    [NSBundle setLanguage:language];
    [[NSNotificationCenter defaultCenter] postNotificationName:NotificationLanguageChanged object:currentLanguage];
}

// 获取应用当前语言
+ (NSString *)userLanguage {
    NSString *language = [[NSUserDefaults standardUserDefaults] objectForKey:LanguageKey];
    if (language.length <= 0) {
        NSArray *languages = [[NSUserDefaults standardUserDefaults] objectForKey:@"AppleLanguages"];
        return languages.firstObject;
    }
    return language;
}

@end
