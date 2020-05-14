//
//  MobBannerAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/3/7.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^MobBannerViewBlock) (UIView * bannerView);

/**
 * Banner广告的相关代理方法
 */
@protocol MobBannerAdManagerDelegate <NSObject>

//========================↓↓↓↓ banner代理方法开始 ↓↓↓↓========================
/**
 * banner广告请求广告条数据失败后调用
 *
 * @param error 信息流错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：未知错误 99：侠客行自渲染）
 */
- (void)bannerViewFailToReceived:(NSError *)error andType:(NSInteger)typeCode;

/**
 * banner广告栏被点击后调用
 */
- (void)bannerViewToClicked;

/**
 * banner广告栏展示成功时调用
 *
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 99：侠客行自渲染）
 */
- (void)bannerViewShowSuccessAndType:(NSInteger)typeCode;

/**
 *  banner广告栏曝光时调用
 */
- (void)bannerViewToExposure;

/**
 *  banner广告栏被关闭时调用
 */
- (void)bannerViewClosed;

/**
 *  banner广告详情页广告被关闭时调用
 */
-(void)bannerDetailsViewDidDismiss;
//========================↑↑↑↑ banner代理方法结束 ↑↑↑↑========================
@end

/**
 * 抽象的Banner广告的初始化方法
 * 支持Banner
 */
@interface MobBannerAdManager : NSObject


/**
 * 声明banner的代理
 */
@property (nonatomic, weak)id<MobBannerAdManagerDelegate> delegate;

//========================↓↓↓↓ banner主动方法开始 ↓↓↓↓========================
/**
 * 展示banner广告视图成功返回的banner视图
 */
@property (nonatomic, copy)MobBannerViewBlock bannerViewBlock;


/**
 * 根据宽高和广告位ID 初始化banner对象
 *
 * @param tagId 广告位id
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 */
- (instancetype)initWithTagId:(NSString *)tagId adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView;



/**
 * 根据宽高和广告位ID 超时时长和UUID 初始化banner对象
 *
 * @param tagId 广告位id
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 * @param timeOut 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于等于0——默认为3秒
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initWithTagId:(NSString *)tagId adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeOut andUUIDStr:(NSString*)UUIDStr;



/**
 * 根据宽高和广告位ID和超时时长 初始化banner对象
 *
 * @param tagId 广告位id
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 * @param timeOut 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于等于0——默认为3秒
 */
- (instancetype)initWithTagId:(NSString *)tagId adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeOut;


/**
 * 根据宽高和广告位ID和uuid 初始化banner对象
 *
 * @param tagId 广告位id
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 * @param UUIDStr 用户传的UUID字符串标识
 */
- (instancetype)initWithTagId:(NSString *)tagId adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView andUUIDStr:(NSString*)UUIDStr;



/**
 * 根据宽高和参数模型 初始化banner对象
 *
 * @param model 初始化时所需的参数模型
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 */
- (instancetype)initWithConfig:(ConfigModel *)model adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView;

/**
 * 根据宽高超时时长和参数模型 初始化banner对象
 *
 * @param model 初始化时所需的参数模型
 * @param width banner广告的固定宽度
 * @param height banner广告的固定高度
 * @param subView banner广告图父视图
 * @param timeOut 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒，小于等于0——默认为3秒
 */
- (instancetype)initWithConfig:(ConfigModel *)model adWidth:(CGFloat)width adHeight:(CGFloat)height addSubView:(nonnull UIView *)subView timeOutTime:(NSTimeInterval)timeOut;


/**
 * 移除banner广告视图
 */
- (void)clickRemoveBannerAd;
//========================↑↑↑↑ banner主动方法结束 ↑↑↑↑========================
@end

NS_ASSUME_NONNULL_END
