// GameProcCharacterCreate.h: interface for the CGameProcCharacterCreate class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "GameProcedure.h"
#include "N3Base/N3TableBase.h"

enum e_ChrValue {
    CVAL_STR = 0,
    CVAL_STA = 1,
    CVAL_DEX = 2,
    CVAL_INT = 3,
    CVAL_CHA = 4,
    CVAL_BONUS = 5,
    CVAL_NUM = 6
};
enum e_ErrorCharacterCreate {
    ERROR_CHARACTER_CREATE_SUCCESS = 0,
    ERROR_CHARACTER_CREATE_NO_MORE_CHARACTER = 1,
    ERROR_CHARACTER_CREATE_INVALID_NATION_AND_INVALID_RACE = 2,
    ERROR_CHARACTER_CREATE_OVERLAPPED_ID = 3,
    ERROR_CHARACTER_CREATE_DB_CREATE = 4,
    ERROR_CHARACTER_CREATE_INVALID_NAME_HAS_SPECIAL_LETTER = 5,
    ERROR_CHARACTER_CREATE_INVALID_NAME,
    ERROR_CHARACTER_CREATE_INVALID_RACE,
    ERROR_CHARACTER_CREATE_NOT_SUPPORTED_RACE,
    ERROR_CHARACTER_CREATE_INVALID_CLASS,
    ERROR_CHARACTER_CREATE_REMAIN_BONUS_POINT,
    ERROR_CHARACTER_CREATE_INVALID_STAT_POINT
};

typedef struct __TABLE_NEW_CHR {
    DWORD       dwID;   // NPC 고유 ID
    std::string szName; // 종족이름..
    int         iStr;
    int         iSta;
    int         iDex;
    int         iInt;
    int         iMAP; // 마법 공격력 Magic Attack Point
    int         iBonus;
} TABLE_NEW_CHR;

const int TRIBE_NUM = 8;

class CGameProcCharacterCreate : public CGameProcedure {
  public:
    class CUICharacterCreate *    m_pUICharacterCreate;
    RECT                          m_rcChr;
    CN3TableBase<__TABLE_NEW_CHR> m_Tbl_InitValue; // 사운드 소스 정보 테이블..

    //    int                        m_InitValue[TRIBE_NUM][CVAL_NUM];

  protected:
    bool ProcessPacket(DataPack * pDataPack, int & iOffset);

  public:
    void ReportErrorCharacterCreate(e_ErrorCharacterCreate eErr);
    bool MsgSendCharacterCreate();
    void RenderChr();
    void SetChr();

    void Release();
    void Init();
    void Tick();
    void Render();

    CGameProcCharacterCreate();
    virtual ~CGameProcCharacterCreate();
};
