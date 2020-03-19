//
//  NSBundle+Language.h
//  BaseFramework
//
//  Created by PingXuhui on 2018/9/12.
//  Copyright © 2018年 Pxh. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (Language)

/**
 * 设置当前语言
 *
 * @param language 当前语言字符串形式
 */
+ (void)setLanguage:(NSString *)language;

@end
