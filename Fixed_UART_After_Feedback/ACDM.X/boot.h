
#ifdef BOOT_GLOBAL
#define BOOT_GLOBAL
#else 
#define BOOT_GLOBAL extern
#endif

BOOT_GLOBAL void iap_load_app(unsigned int appxaddr);
	

