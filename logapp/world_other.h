#ifndef __WORLD_LOG_HEAD__
#define __WORLD_LOG_HEAD__

#include "world.h"
#include "dboper.h"
#include "db_task.h"
#include "balance.h"

namespace mogo
{

    struct SEntityLookup
    {
        TENTITYID eid;      //entity id
        uint16_t sid;       //baseapp id
    };

    class CWorldOther : public world
    {
        public:
            CWorldOther();
            ~CWorldOther();


        public:
            virtual int init(const char* pszEtcFile);

            int FromRpcCall(CPluto& u, CDbOper& db);

            bool InitMutex();

			int Response2Browser(int nFd,const string& response);

			// 重载 world 中的方法
			int ShutdownServer(T_VECTOR_OBJECT* p);
			int OpenMogoLib(lua_State* L) { return 0; }
			CEntityParent* GetEntity(TENTITYID id) { return NULL; }
			int FromRpcCall(CPluto& u) { return 0; }

        private:
            int InsertDB(T_VECTOR_OBJECT* p, CDbOper& db);
            int ReqUrl(T_VECTOR_OBJECT* p);
            int RegisterGlobally(T_VECTOR_OBJECT* p);
            int SupportApi(T_VECTOR_OBJECT* p, CMailBox* pmb, CDbOper& db);
            int Response2Browser(T_VECTOR_OBJECT* p);


            int BaseCall(const char* mgrName, const char* pszFunc,int nFd, string &method, string& param);

			int InitLib();
			int RunApi(int nFd,  string & method_str, string& params_str,  CDbOper& db);

            //int TableSelect(T_VECTOR_OBJECT* p, CDbOper& db);
            //int TableInsert(T_VECTOR_OBJECT* p, CDbOper& db);

            //int TableUpdateBatch(T_VECTOR_OBJECT* p, CDbOper& db);
			int SdkServerVerify(T_VECTOR_OBJECT* p, CPluto& u);
			int PlatApi(T_VECTOR_OBJECT* p, CMailBox* pmb, CDbOper& db);


        private:
            CBalance m_baseBalance;
            pthread_mutex_t m_entityMutex; 
            pthread_mutex_t m_rpcMutex;
            map<string, CEntityMailbox*> m_globalBases;

            CWorldOther(const CWorldOther&);
            CWorldOther& operator=(const CWorldOther&);

	};
}




#endif

