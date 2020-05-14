//
//  MobInterstitialAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/4/8.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 暂停贴片广告的相关代理方法
 */
@protocol MobInterstitialAdManagerDelegate <NSObject>

//========================↓↓↓↓ 暂停贴片代理方法 ↓↓↓↓========================
/**
 * 暂停贴片广告栏被点击后调用
 */
- (void)interstitialViewToClicked;

/**
 * 暂停贴片详情页关闭时调用
 */
- (void)interstitialViewToClosed;

/**
 * 暂停贴片广告栏加载成功的调用
 *
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：未知错误 99：侠客行自渲染）
 */
- (void)interstitialAdViewLoadAndTypeCode:(NSInteger)typeCode;

/**
 * 暂停贴片广告加载失败调用
 *
 * @param error 失败错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：未知错位 99：侠客行自渲染）
 */
- (void)interstitialFailToReceived:(NSError *)error andTypeCode:(NSInteger)typeCode;

//========================↑↑↑↑ 暂停贴片代理结束 ↑↑↑↑========================
@end

/**
 * 抽象的暂停贴片广告的初始化方法
 * 支持暂停贴片广告
 */
@interface MobInterstitialAdManager : NSObject

@property (nonatomic, weak)id<MobInterstitialAdManagerDelegate> delegate;

//========================↓↓↓↓ 暂停贴片主动方法 ↓↓↓↓========================
/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param tagId 广告位id
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 */
- (instancetype)initInterstitialWithTagId:(NSString *)tagId edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(nonnull UIView *)subView;

/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param tagId 广告位id
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 * @param timeout 暂停贴片超时时长
 */
- (instancetype)initInterstitialWithTagId:(NSString *)tagId edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(UIView *)subView timeOutTime:(NSTimeInterval)timeout;

/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param tagId 广告位id
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initInterstitialWithTagId:(NSString *)tagId edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(nonnull UIView *)subView andUUIDStr:(NSString*)UUIDStr;

/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param tagId 广告位id
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 * @param timeout 暂停贴片超时时长
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initInterstitialWithTagId:(NSString *)tagId edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(UIView *)subView timeOutTime:(NSTimeInterval)timeout andUUIDStr:(NSString*)UUIDStr;

/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param model 初始化时所需的参数模型
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 */
- (instancetype)initInterstitialWithConfig:(ConfigModel *)model edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(UIView *)subView;

/**
 * 根据平台类型加载暂停贴片广告
 *
 * @param model 初始化时所需的参数模型
 * @param edgeInsets 暂停贴片广告的上下左右边距 (广告宽度及高度尺寸必须大于150并且以1:1的宽高比)
 * @param subView 暂停贴片广告父视图
 * @param timeout 暂停贴片超时时长
 */
- (instancetype)initInterstitialWithConfig:(ConfigModel *)model edgeInsets:(UIEdgeInsets)edgeInsets addSubView:(UIView *)subView timeOutTime:(NSTimeInterval)timeout;

/**
 * 展示暂停贴片广告视图
 *
 * @param clickableViews 穿山甲注册点击的示图
 */
- (void)showInterstitialAdWithClickableViews:(NSArray<__kindof UIView *> *)clickableViews;

/**
 * 点击暂停贴片广告视图
 */
- (void)clickInterstitialAd;

/**
 * 关闭暂停贴片广告视图
 */
- (void)closeInterstitialAd;

//========================↑↑↑↑ 暂停贴片主动方法结束 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
