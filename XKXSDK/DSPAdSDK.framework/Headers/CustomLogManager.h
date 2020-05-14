//
//  CustomLogManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/9/20.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//
// 打印日志的方法 方便用户前端查看日志
#define SetUpLog(format,...)\
({\
    NSString *formatStr = @"";\
    NSString *appendStr = @"";\
    appendStr = [CustomLogManager getLogInfo];\
    formatStr = [CustomLogManager customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]];\
    appendStr = [appendStr stringByAppendingString:[NSString stringWithFormat:@"\n%@", formatStr]];\
    [CustomLogManager setLogInfo:appendStr];\
    (appendStr);\
})\

//#if defined(DEBUG)||defined(_DEBUG)
//NSLog(@"banner广告初始化");
//#endif
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CustomLogManager : NSObject

+ (void)setLogInfo:(NSString *)logInfo;

+ (NSString *)getLogInfo;

// 设置日志输出状态
+ (void)setLogEnable:(BOOL)enable;

// 获取日志输出状态
+ (BOOL)getLogEnable;

// 清除日志输出
+ (void)clearLogInfo;

// 日志输出方法
+ (NSString *)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;

@end

NS_ASSUME_NONNULL_END
