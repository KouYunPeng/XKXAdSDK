//
//  MobSplashAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/3/11.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ConfigModel;

NS_ASSUME_NONNULL_BEGIN

// 开屏广告加载成功后返回开屏广告视图的block回调
typedef void (^MobSplashViewBlock)(UIView *splashView);

/**
 * 开屏广告代理
 *
 * @protocol MobSplashAdManagerDelegate
 * @abstract 用户遵循开屏广告代理，可以监听广告展示成功，失败，被曝光，被点击，开屏广告展示结束，详情页被关闭的方法
 */
@protocol MobSplashAdManagerDelegate <NSObject>

//========================↓↓↓↓ 代理方法开始 ↓↓↓↓========================

/**
 * 开屏广告加载成功时调用
 *
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 -1侠客行自渲染 0：不存在）
 */
- (void)splashViewShowSuccessAndType:(NSInteger)typeCode;

/**
 * 开屏广告加载失败后调用
 *
 * @param error 开屏广告错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 -1侠客行自渲染 0：不存在）
 */
- (void)splashViewFailToReceived:(NSError *)error andType:(NSInteger)typeCode;

/**
 *  开屏广告被点击后调用
 */
- (void)splashViewToClicked;

/**
 *  开屏广告展示结束时调用
 */
- (void)splashViewDismissScreen;

/**
 *  开屏广告详情页消失时调用
 */
- (void)splashViewDidDismissLp;

/**
 *  开屏广告曝光成功时调用
 */
- (void)splashViewToExposure;

//========================↑↑↑↑ 代理方法结束 ↑↑↑↑========================

@end

/**
 * 开屏广告类
 *
 * @class MobSplashAdManager
 * @abstract 用户初始化该类，可以创建开屏广告
 */
@interface MobSplashAdManager : NSObject

/** 开屏广告block,广告加载成功返回开屏广告视图 */
@property (nonatomic, copy) MobSplashViewBlock splashViewBlock;
/** 开屏广告代理 */
@property (nonatomic, weak) id<MobSplashAdManagerDelegate> delegate;

//========================↓↓↓↓ 主动方法 ↓↓↓↓========================

/**
 * 根据广告位id,自定义底部视图以及开屏底部logo视图的frame初始化开屏广告
 *
 * @param tagId 广告位id
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithTagId:(NSString *)tagId bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame;

/**
 * 根据广告位id，自定义底部视图，开屏底部logo视图的frame以及超时时长初始化开屏广告
 *
 * @param tagId 广告位id
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithTagId:(NSString *)tagId bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame timeOutTime:(NSTimeInterval)timeout;

/**
 * 根据广告位id，自定义底部视图，开屏底部logo视图的frame以及流程id初始化开屏广告
 *
 * @param tagId 广告位id
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @param UUIDStr 用户传的UUID字符串标识（流程id）
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithTagId:(NSString *)tagId bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame andUUIDStr:(NSString *)UUIDStr;

/**
 * 根据广告位id，自定义底部视图，开屏底部logo视图的frame，超时时长以及流程id初始化开屏广告
 *
 * @param tagId 广告位id
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒
 * @param UUIDStr 用户传的UUID字符串标识（流程id）
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithTagId:(NSString *)tagId bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame timeOutTime:(NSTimeInterval)timeout andUUIDStr:(NSString *)UUIDStr;

/**
 * 根据参数配置模型，自定义底部视图，开屏底部logo视图的frame初始化开屏广告
 *
 * @param model 初始化时所需的参数配置模型
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithConfig:(ConfigModel *)model bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame;

/**
 * 根据参数配置模型，自定义底部视图，开屏底部logo视图的frame以及超时时长初始化开屏广告
 *
 * @param model 初始化时所需的参数配置模型
 * @param bottemView 自定义底部View，可以在此View中设置应用Logo（可以为空）
 * @param frame 开屏底部logo视图的frame，必填
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒
 * @abstract 将获取的广告以半屏形式展示在Window的上半部，剩余部分展示传入的bottomView
 *           请注意bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
 *           如果全屏显示开屏广告请填写CGRectZero
 */
- (instancetype)initSplashWithConfig:(ConfigModel *)model bottemView:(UIView *)bottemView bottemViewFrame:(CGRect)frame timeOutTime:(NSTimeInterval)timeout;

/**
 * 开屏广告展示方法（展示腾讯及自渲染开屏时，需要获取到广告所在的window，所以需要主动执行开屏展示方法，传递广告所在的window）
 *
 * @param window 展示开屏广告的窗口
 */
- (void)loadAndDisplaySplashViewWithWindow:(UIWindow *)window;

//========================↑↑↑↑ 主动方法 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
