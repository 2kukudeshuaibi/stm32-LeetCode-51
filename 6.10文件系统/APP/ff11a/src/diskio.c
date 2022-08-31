/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "spi_flash.h"



/* Definitions of physical drive number for each drive */
#define SD_CARD		0	/* Example: Map ATA harddisk to physical drive 0 */
#define SPI_FLASH   1	/* Example: Map MMC/SD card to physical drive 1 */

#define FLASH_ID 0xc84018
/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	u32 ID=0;
	int result;

	switch (pdrv) {
	case SD_CARD :
		
		return stat;
	case SPI_FLASH :
		
	    ID=SPI_Read_ID();
	    if(ID==FLASH_ID)
		{
			stat=RES_OK;
		}
		else
		{
			stat=STA_NOINIT;
		}
		return stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;

	switch (pdrv) {
	case SD_CARD :
		
		

		return stat;

	case SPI_FLASH :
		
		
		SPI2_FLASH_Init();
	    
		return disk_status(SPI_FLASH);
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;

	switch (pdrv) {
	case SD_CARD :

		

		return res;

	case SPI_FLASH :
		
		SPI_FLASH_Read_data(sector*4096,buff,count*4096);
		res=RES_OK;
		return res;
	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;
	

	switch (pdrv) {
	case SD_CARD :

		

		return res;

	case SPI_FLASH :
		

		SPI_FLASH_Write(sector*4096,(u8*)buff,count*4096);
		res=RES_OK;
		return res;
	}

	return RES_PARERR;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case SD_CARD :

		
		return res;

	case SPI_FLASH :

		
		switch(cmd)
		{
			case GET_SECTOR_COUNT:*(DWORD*)buff=2048;break;
			case GET_SECTOR_SIZE:*(WORD*)buff=4096;break;
			case GET_BLOCK_SIZE:*(DWORD*)buff=1;break;
		}
		
		res=RES_OK;
		
		return res;

	}

	return RES_PARERR;
}
#endif

DWORD get_fattime()
{
	return 0;
}

