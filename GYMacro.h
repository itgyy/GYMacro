//
//  GYMacro.h
//  GYMacro
//
//  Created by gyy on 2019/8/30.
//

#ifndef GYMacro_h
#define GYMacro_h

#ifdef __OBJC__

#pragma mark ================== GYLog =====================

#define GYLog(FORMAT, ...) fprintf(stderr,"%s [line: %d] %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

#pragma mark =================== SCREEN ====================

#define GYKSCREEN_WIDTH           [UIScreen mainScreen].bounds.size.width
#define GYKSCREEN_HEIGHT          [UIScreen mainScreen].bounds.size.height
#define GYKSCREEN_BOUNDS          [UIScreen mainScreen].bounds
#define GYKStatusBarHeight        [[UIApplication sharedApplication] statusBarFrame].size.height
#define GYKScreenMaxLength        (MAX(GYKSCREEN_WIDTH, GYKSCREEN_HEIGHT))
#define GYKScreenMinLength        (MIN(GYKSCREEN_WIDTH, GYKSCREEN_HEIGHT))
#define GYKNavBarHeight           (GYKStatusBarHeight + 44)

#define GYKWeakSelf(type)         __weak typeof(type) weak##type = type;
#define GYKStrongSelf(type)       __strong typeof(type) type = weak##type

#define GYKScale_W_375(w)         ((GYKSCREEN_WIDTH)/375) * (w)
#define GYKScale_H_667(h)         (GYKSCREEN_HEIGHT/667) * (h)


#pragma mark =================== App ====================

#define GYKeyWindow              [UIApplication sharedApplication].keyWindow
#define GYKApplication           [UIApplication sharedApplication]
#define GYKUserDefaults          [NSUserDefaults standardUserDefaults]
#define GYKNotificationCenter    [NSNotificationCenter defaultCenter]
#define GYKAppVersion            [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]
#define GYKPostNotification(name,obj,info) [[NSNotificationCenter defaultCenter]postNotificationName:name object:obj userInfo:info]
#define GYKCurrentLanguage       ([[NSLocale preferredLanguages] objectAtIndex:0])
#define GYKIOS_SYSTEM_VERSION    [[UIDevice currentDevice] systemVersion]




#pragma mark =================== Resource ====================
#define GYKImage(imageName)      [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define GYKLoadNib(nibName)      [UINib nibWithNibName:nibName bundle:[NSBundle mainBundle]]
#define GYKStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]



#pragma mark =================== 颜色 ====================
#define GYKRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
#define GYKRGBA(a,b,c,d) [UIColor colorWithRed:a/255. green:b/255. blue:c/255. alpha:d]
#define GYKColorHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]




#pragma mark =================== 属性 ====================
#define GYKPropertyString(name)                  @property(nonatomic,copy)NSString *name
#define GYKPropertyStrong(type,name)             @property(nonatomic,strong)type *name
#define GYKPropertyAssign(name)                  @property(nonatomic,assign)NSInteger name
#define GYKPropertyNSArray(name)                 @property(nonatomic, copy) NSArray * name
#define GYKPropertyNSMutableArray(name)          @property(nonatomic, strong) NSMutableArray * name
#define GYKPropertyNSDictionary(name)            @property(nonatomic, copy) NSDictionary * name
#define GYKPropertyNSMutableDictionary(name)     @property(nonatomic, copy) NSMutableDictionary * name



#pragma mark =================== 文件 ====================
#define GYKPathTemp NSTemporaryDirectory()
#define GYKPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define GYKPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
//Library/Caches 文件路径
#define GYKFilePath ([[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:YES error:nil])


#pragma mark =================== GCD ====================
//默认block
//GCD - 在Main线程上运行
#define GYKMainThread(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
//GCD - 开启异步线程
#define GYKGlobalThread(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);
//GCD - 一次性执行
#define GYKDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);


#pragma mark =================== Date ====================
//获得年
#define  GYKCurrentYear(date) [[NSCalendar currentCalendar] component:NSCalendarUnitYear fromDate:date]
//获得月
#define  GYKCurrentMonth(date) [[NSCalendar currentCalendar] component:NSCalendarUnitMonth fromDate:date]
//获得日
#define  GYKCurrentDay(date)  [[NSCalendar currentCalendar] component:NSCalendarUnitDay fromDate:date]
//获得时
#define  GYKCurrentHour(date) [[NSCalendar currentCalendar] component:NSCalendarUnitHour fromDate:date]
//获得分
#define  GYKCurrentMin(date) [[NSCalendar currentCalendar] component:NSCalendarUnitMinute fromDate:date]
//获得秒
#define  GYKCurrentSec(date) [[NSCalendar currentCalendar] component:NSCalendarUnitSecond fromDate:date]


#pragma mark =================== 控制判断 ====================
//字符串是否为空
#define GYKISNullString(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//数组是否为空
#define GYKISNullArray(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 ||[array isEqual:[NSNull null]])
//字典是否为空
#define GYKISNullDict(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0 || [dic isEqual:[NSNull null]])
//是否是空对象
#define GYKISNullObject(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
//判断对象是否为空,为空则返回默认值
#define GYKGetNullDefaultObj(_value,_default) ([_value isKindOfClass:[NSNull class]] || !_value || _value == nil || [_value isEqualToString:@"(null)"] || [_value isEqualToString:@"<null>"] || [_value isEqualToString:@""] || [_value length] == 0)?_default:_value





#endif


#endif /* GYMacro_h */
