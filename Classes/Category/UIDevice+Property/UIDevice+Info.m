//
//  UIDevice+Info.m
//  BaseFramework
//
//  Created by PingXuhui on 2018/9/12.
//  Copyright © 2018年 Pxh. All rights reserved.
//

#import "UIDevice+Info.h"

@implementation UIDevice (Info)

/// 获取设备信息
+(NSString *)getDeviceDesciption{
    UIDevice *device = [UIDevice currentDevice];
    NSString *name = device.name;
    NSString *model = device.model;
    NSString *localizeModel = device.localizedModel;
    NSString *systemName = device.systemName;
    NSString *systemVersion = device.systemVersion;
    return [NSString stringWithFormat:@"name:%@, device:%@%@, system:%@%@", name, model, localizeModel, systemName, systemVersion];
}

@end
