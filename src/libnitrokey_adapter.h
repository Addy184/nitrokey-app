//
// Created by sz on 09.01.17.
//

#ifndef NITROKEYAPP_LIBNITROKEY_ADAPTER_H
#define NITROKEYAPP_LIBNITROKEY_ADAPTER_H

#include <memory>
#include <string>

#define HOTP_SLOT_COUNT_MAX 3
#define TOTP_SLOT_COUNT_MAX 15
#define HOTP_SLOT_COUNT 3
#define TOTP_SLOT_COUNT 15

#define STICK10_PASSWORD_LEN 20
#define STICK20_PASSOWRD_LEN 20
#define CS20_MAX_UPDATE_PASSWORD_LEN 20

#define PWS_SLOT_COUNT 16
#define PWS_SLOTNAME_LENGTH 11
#define PWS_PASSWORD_LENGTH 20
#define PWS_LOGINNAME_LENGTH 32

#define DEBUG_STATUS_NO_DEBUGGING 0
#define DEBUG_STATUS_LOCAL_DEBUG 1
#define DEBUG_STATUS_DEBUG_ALL 2

#define MAX_HIDDEN_VOLUME_PASSOWORD_SIZE 20

class libnitrokey_adapter {
  private:
    libnitrokey_adapter();
    static std::shared_ptr <libnitrokey_adapter> _instance;

public:
    ~libnitrokey_adapter();
    static std::shared_ptr<libnitrokey_adapter> instance();

    int getMajorFirmwareVersion();
    int getMinorFirmwareVersion();
    int getPasswordRetryCount();
    int getUserPasswordRetryCount();
    std::string getCardSerial();
    std::string getTOTPSlotName(const int i);
    std::string getHOTPSlotName(const int i);

    int getStorageInfoData();
    int getStorageSDCardSize();

    int setUserPIN();
    int setAdminPIN();
    int setStorageUpdatePassword();

    bool isDeviceConnected();
    bool isDeviceInitialized();
    bool isStorageDeviceConnected();
};


#endif //NITROKEYAPP_LIBNITROKEY_ADAPTER_H
