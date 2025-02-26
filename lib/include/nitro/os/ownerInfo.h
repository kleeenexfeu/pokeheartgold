#ifndef NITRO_OS_OWNERINFO_H_
#define NITRO_OS_OWNERINFO_H_

typedef struct OSBirthday {
    u8 month;
    u8 day;
} OSBirthday;

typedef struct OSOwnerInfo {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

#endif //NITRO_OS_OWNERINFO_H_
