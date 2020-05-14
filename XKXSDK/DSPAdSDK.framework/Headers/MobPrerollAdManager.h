//
//  MobPrerollAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/3/13.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConfigModel.h"

@class MobPrerollAdManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * 前贴片广告的代理方法
 *
 * @protocol MobPrerollAdManagerDelegate
 * @abstract 创建前贴片广告的代理方法，用于客户端使用此代理，获取我们提供的代理方法，从而处理他们自己的逻辑
 */
@protocol MobPrerollAdManagerDelegate <NSObject>

//========================↓↓↓↓ 前贴片代理方法 ↓↓↓↓========================
/**
 * 前贴片广告数据加载成功时调用
 *
 * @param videoDuration 视频播放时长（前贴片广告如果是视频类型的时候会返回，其他情况为0，以s为单位）
 * @param adType 广告类型 (0一般图文或图片广告, 1视频广告，需开发者增加播放器支持 2html模版广告, 3GIF广告 )
 * @param prerollManager 贴片广告管理类对象
 */
- (void)prerollPrestrainSuccessWithVideoDuration:(NSNumber *)videoDuration prerollAdType:(NSInteger)adType prerollManager:(MobPrerollAdManager *)prerollManager;

/**
 * 前贴片广告加载失败时调用
 *
 * @param error 失败错误信息（包含数据请求失败，素材预加载失败的错误信息）
 * @param prerollManager 前贴片广告对象
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：未知错误 99：侠客行自渲染）
 */
- (void)prerollViewFailToReceived:(NSError *)error prerollManager:(MobPrerollAdManager *)prerollManager andTypeCode:(NSInteger)typeCode;

/**
 * 前贴片广告播放完成时调用的代理方法
 *
 * @param prerollManager 前贴片广告对象
 */
- (void)prerollDidFinishedWithManager:(MobPrerollAdManager *)prerollManager;

/**
 * 前贴片广告被点击后调用的代理方法
 *
 * @param prerollManager 前贴片广告对象
 */
- (void)prerollViewToClickedWithManager:(MobPrerollAdManager *)prerollManager;

/**
 * 前贴片广告栏详情页被关闭后调用
 *
 * @param prerollManager 前贴片广告对象
 */
- (void)prerollViewDidDismissLandingPageWithManager:(MobPrerollAdManager *)prerollManager;

/**
 * 前贴片广告素材预加载成功
 *
 * @param prerollManager 前贴片广告对象
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：未知错误，99：侠客行自渲染）
 */
- (void)prerollAdResourceCompleteWithManager:(MobPrerollAdManager *)prerollManager andTypeCode:(NSInteger)typeCode;

//========================↑↑↑↑ 前贴片代理方法结束 ↑↑↑↑========================
@end

/**
 * 抽象的前贴片广告的初始化方法
 * 支持前贴片广告
 */
@interface MobPrerollAdManager : NSObject

@property (nonatomic, weak)id<MobPrerollAdManagerDelegate> delegate;

//========================↓↓↓↓ 前贴片主动方法 ↓↓↓↓========================
/**
 * 根据广告位id 坐标大小，和边距 初始化前贴片广告 带超时时长
 *
 * @param tagId 广告位id
 * @param frame 前贴片广告的frame
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView 前贴片广告父视图
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于0秒——返回错误信息 等于0秒——不启动定时器
 */
- (instancetype)initPrerollWithTagId:(NSString *)tagId frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeout;


/**
 * 前贴片初始化不带超时时长的
 *
 * @param tagId      广告位id
 * @param frame      前贴片广告的坐标大小
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView    渲染前贴片广告的示图
 */
- (instancetype)initPrerollWithTagId:(NSString *)tagId frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView;


/**
 * 根据广告位id 坐标大小，和边距 初始化前贴片广告 不带超时时长
 *
 * @param tagId 广告位id
 * @param frame 前贴片广告的frame
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView 前贴片广告父视图
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initPrerollWithTagId:(NSString *)tagId frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView andUUIDStr:(NSString*)UUIDStr;


/**
 * 根据广告位id 坐标大小，和边距 初始化前贴片广告 带超时时长
 *
 * @param tagId 广告位id
 * @param frame 前贴片广告的frame
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView 前贴片广告父视图
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于0秒——返回错误信息 等于0秒——不启动定时器
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initPrerollWithTagId:(NSString *)tagId frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeout andUUIDStr:(NSString*)UUIDStr;

/**
 * 根据参数模型，坐标大小，和边距 初始化前贴片广告 不带超时时长
 *
 * @param model 初始化时所需的参数模型
 * @param frame 前贴片广告的frame
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView 前贴片广告父视图
 */
- (instancetype)initPrerollWithConfig:(ConfigModel *)model frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView;

/**
 * 根据参数模型，坐标大小，和边距 初始化前贴片广告 带超时时长
 *
 * @param model 初始化时所需的参数模型
 * @param frame 前贴片广告的frame
 * @param edgeInsets 前贴片广告上下左右间距
 * @param subView 前贴片广告父视图
 * @param timeout 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于0秒——返回错误信息 等于0秒——不启动定时器
 */
- (instancetype)initPrerollWithConfig:(ConfigModel *)model frame:(CGRect)frame edgeInsets:(UIEdgeInsets)edgeInsets subView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeout;

/**
 * 预加载前贴片广告视图
 */
- (void)preloadPrerollAd;

/**
 * 前贴片广告(曝光计费及播放)
 */
- (void)prerollAdReadyAndPlay;

/**
 * 前贴片广告(视频广告开始播放)
 */
- (void)prerollAdPlay;

/**
 * 前贴片广告(视频广告暂停)
 */
- (void)prerollAdPause;

/**
 * 前贴片广告(视频广告重新播放)
 */
- (void)prerollAdReplay;

/**
 * 关闭前贴片广告
 */
- (void)closePrerollAd;

/**
 * 点击前贴片广告
 */
- (void)clickPrerollAd;

/**
 * 设置前贴片广告是否静音
 *
 * @param mute 是否是静音播
 */
- (void)setPrerollAdMute:(BOOL)mute;

/**
 * 获取视频贴片广告的当前播放时间
 */
- (NSTimeInterval)getPrerollCurrentTime;

/**
 * 获取视频贴片广告的总时长
 */
- (NSTimeInterval)getPrerollTotalTime;

//========================↑↑↑↑ 前贴片主动方法结束 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
