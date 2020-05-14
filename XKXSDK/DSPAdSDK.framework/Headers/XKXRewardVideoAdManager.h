//
//  XKXRewardVideoAdManager.h
//  DSPAdSDK
//
//  Created by 赵国成 on 2019/6/6.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class XKXRewardVideoAdManager;
@class ConfigModel;
@class XKXRewardVideoAdModel;
/**
 * 激励视频代理方法
 *
 * @protocol XKXRewardVideoAdManagerDelegate
 * @abstract 创建激励视频的代理方法，用于客户端使用此代理，获取我们提供的代理方法，从而处理他们自己的逻辑
 */
@protocol XKXRewardVideoAdManagerDelegate <NSObject>

//========================↓↓↓↓ 激励视频代理方法 ↓↓↓↓========================

/**
 * 激励视频被点击时调用此方法
 */
- (void)xkxRewardVideoAdDidClicked;

/**
 * 激励视频预加载成功时调用的方法
 *
 * @param manager 这是当前对象，加载成功后这个对象可以实行前端页面的查看方法
 */
- (void)xkxRewardVideoAdLoaded:(XKXRewardVideoAdManager *)manager model:(XKXRewardVideoAdModel*)rewardModel;


/**
 * 激励视频被关闭时调用的方法
 *
 * @param manager 这是当前对象，激励视频关闭后这个对象可以执行一些操作，方便前端使用
 */
- (void)xkxRewardVideoAdDidClose:(XKXRewardVideoAdManager *)manager;


/**
 * 激励视频播放完成时调用
 */
- (void)xkxRewardVideoAdDidPlayFinish;

/**
 * 激励视频曝光成功时调用
 */
- (void)xkxRewardVideoAdDidExposure;

/**
 * 激励视频展示成功时候调用
 */
- (void)xkxRewardVideoAdDidShowSuccess;


/**
 * 激励视频广告请求广告条数据失败后调用
 *
 * @param error 激励视频错误信息
 * @param typeCode 联盟第三方标识（1：百度  2：腾讯  3：穿山甲  0：未知错误  99：侠客行自渲染）
 *                 用于客户端判断是哪家联盟使用
 */
- (void)xkxRewardVideoAdFailWithError:(NSError *)error andType:(NSInteger)typeCode;

//========================↑↑↑↑ 激励视频代理方法结束 ↑↑↑↑========================
@end


/**
 * 激励视频广告类
 *
 * @class XKXRewardVideoAdManager
 * @abstract 用户初始化该类，可以创建激励视频广告。
 */
@interface XKXRewardVideoAdManager : NSObject

/**
 * 创建代理，用于使用代理调用代理方法通知客户端使用
 */
@property (nonatomic, weak) id<XKXRewardVideoAdManagerDelegate> xkxRewardVideoAdDelegate;

//========================↓↓↓↓ 激励视频主动方法开始 ↓↓↓↓========================

/**
 * 根据平台类型初始化激励视频广告
 *
 * @param model 激励视频的需要的参数配置
 *
 */
- (instancetype)initRewardVideoWithConfigModel:(ConfigModel *)model;


/**
 * 展示方法，提供给客户端主动调用，当激励视频加载成功之后，调用此方法，才能展示出来广告
 *
 * @param nav 用户传进来的导航栏，用于自渲染激励视频跳转页面使用
 */
- (void)xkxShowRewardVideo:(UINavigationController *)nav;

//========================↑↑↑↑ 激励视频主动方法结束 ↑↑↑↑========================
@end

NS_ASSUME_NONNULL_END
