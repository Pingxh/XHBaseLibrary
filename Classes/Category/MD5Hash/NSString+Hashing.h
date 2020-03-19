

#import <Foundation/Foundation.h>


@interface NSString (NSString_Hashing)

- (NSString *)MD5Hash;

/**
 解密MD5

 @param signString <#signString description#>
 @return <#return value description#>
 */
- (NSMutableString *)encryptMd5:(NSString *)origingString;

+(NSString*)fileMD5:(NSString*)path;

+(NSString*)dataMD5:(NSData*)data;

+ (NSString *)md5:(NSString *)input;

//sha1加密方式
+ (NSString *) sha1:(NSString *)input;

/**
 *  加密方式,MAC算法: HmacSHA256
 *
 *  @param plaintext 要加密的文本
 *  @param key       秘钥
 *
 *  @return 加密后的字符串
 */
+ (NSString *)hmac:(NSString *)plaintext withKey:(NSString *)key;

/// 散列函数--HMAC sha256加密
+ (NSString *)sha256String:(NSString *)text key:(NSString *)key;

//sha256加密方式
+ (NSString *)getSha256String:(NSString *)srcString;

@end
