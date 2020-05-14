//
//  SDKInfo.h
//  DSPAdSDK
//
//  Created by 赵国成 on 2019/5/24.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SDKInfo : NSObject

+ (instancetype)shared;

// 获取当前sdk版本信息
- (NSString*)sdkInfo;

// 获取当前手机网络环境
- (NSString *)wifiInfo;

@end

NS_ASSUME_NONNULL_END
