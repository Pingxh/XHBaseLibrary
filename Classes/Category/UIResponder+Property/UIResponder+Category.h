//
//  UIResponder+Category.h
//  EastAsiaOilCard
//
//  Created by PingXuhui on 2018/2/1.
//  Copyright © 2018年 PingXuhui. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIResponder (Category)

// MARK: 获取当前正在输入的控件
/// 获取当前正在输入的控件
/**
  获取当前正在输入的控件

 @return <#return value description#>
 */
+(id)currentFirstResponder;

@end
