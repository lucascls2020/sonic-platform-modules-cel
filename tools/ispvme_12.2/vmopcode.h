/***************************************************************
*
* This is the include file for Lattice Semiconductor's ispVM
* Embedded software application.
*
***************************************************************/

/***************************************************************
*
* VME version.
*
* History:
* 
***************************************************************/
#define VME_VERSION_NUMBER "12.2"

/***************************************************************
*
* Maximum declarations.
*
***************************************************************/

#define VMEHEXMAX   60000L  /* The hex file is split 60K per file. */
#define SCANMAX     64000L  /* The maximum SDR/SIR burst. */

/***************************************************************
*
* Supported JTAG state transitions.
*
***************************************************************/

#define RESET      0x00
#define IDLE       0x01
#define IRPAUSE    0x02
#define DRPAUSE    0x03
#define SHIFTIR    0x04
#define SHIFTDR    0x05
#define DRCAPTURE  0x06

/***************************************************************
*
* Flow control register bit definitions.  A set bit indicates 
* that the register currently exhibits the corresponding mode.
*
***************************************************************/

#define INTEL_PRGM 0x0001    /* Intelligent programming is in effect. */
#define CASCADE    0x0002    /* Currently splitting large SDR. */
#define REPEATLOOP 0x0008    /* Currently executing a repeat loop. */
#define SHIFTRIGHT 0x0080    /* The next data stream needs a right shift. */
#define SHIFTLEFT  0x0100    /* The next data stream needs a left shift. */
#define VERIFYUES  0x0200    /* Continue if fail is in effect. */

/***************************************************************
*
* DataType register bit definitions.  A set bit indicates
* that the register currently holds the corresponding type of data.
*
***************************************************************/

#define EXPRESS    0x0001    /* Simultaneous program and verify. */
#define SIR_DATA   0x0002    /* SIR is the active SVF command. */
#define SDR_DATA   0x0004    /* SDR is the active SVF command. */
#define COMPRESS   0x0008    /* Data is compressed. */
#define TDI_DATA   0x0010    /* TDI data is present. */
#define TDO_DATA   0x0020    /* TDO data is present. */
#define MASK_DATA  0x0040    /* MASK data is present. */
#define HEAP_IN    0x0080    /* Data is from the heap. */
#define LHEAP_IN   0x0200    /* Data is from intel data buffer. */
#define VARIABLE   0x0400    /* Data is from a declared variable. */
#define CRC_DATA   0x0800	 /* CRC data is pressent. */
#define CMASK_DATA 0x1000    /* CMASK data is pressent. */
#define RMASK_DATA 0x2000	 /* RMASK data is pressent. */
#define READ_DATA  0x4000    /* READ data is pressent. */
#define DMASK_DATA 0x8000	 /* DMASK data is pressent. */

/***************************************************************
*
* Pin opcodes.
*
***************************************************************/

#define signalENABLE  0x1C    /* ispENABLE pin. */
#define signalTMS     0x1D    /* TMS pin. */
#define signalTCK     0x1E    /* TCK pin. */
#define signalTDI     0x1F    /* TDI pin. */
#define signalTRST    0x20    /* TRST pin. */

/***************************************************************
*
* Supported vendors.
*
***************************************************************/

#define VENDOR		0x56
#define LATTICE		0x01
#define ALTERA		0x02
#define XILINX		0x03

/***************************************************************
*
* Opcode definitions.
*
* Note: opcodes must be unique.
*
***************************************************************/

#define ENDDATA    0x00    /* The end of the current SDR data stream. */
#define RUNTEST    0x01    /* The duration to stay at the stable state. */
#define ENDDR      0x02    /* The stable state after SDR. */
#define ENDIR      0x03    /* The stable state after SIR. */
#define ENDSTATE   0x04    /* The stable state after RUNTEST. */
#define TRST       0x05    /* Assert the TRST pin. */
#define HIR        0x06    /* The sum of the IR bits of the leading devices. */
#define TIR        0x07    /* The sum of the IR bits of the trailing devices. */
#define HDR        0x08    /* The number of leading devices. */
#define TDR        0x09    /* The number of trailing devices. */
#define ispEN      0x0A    /* Assert the ispEN pin. */
#define FREQUENCY  0x0B    /* The maximum clock rate to run the JTAG state machine. */
#define STATE      0x10    /* Move to the next stable state. */
#define SIR        0x11    /* The instruction stream follows. */
#define SDR        0x12    /* The data stream follows. */
#define TDI        0x13    /* The following data stream feeds into the device. */
#define TDO        0x14    /* The following data stream is compared against the device. */
#define MASK       0x15    /* The following data stream is used as mask. */
#define XSDR       0x16    /* The following data stream is for simultaneous program and verify. */
#define XTDI       0x17    /* The following data stream is for shift in only. It must be stored for the next XSDR. */
#define XTDO       0x18    /* There is not data stream.  The data stream was stored from the previous XTDI. */
#define MEM        0x19    /* The maximum memory needed to allocate in order hold one row of data. */
#define WAIT       0x1A    /* The duration of delay to observe. */
#define TCK        0x1B    /* The number of TCK pulses. */
#define SHR        0x23    /* Set the flow control register for right shift. */
#define SHL        0x24    /* Set the flow control register for left shift. */
#define HEAP       0x32    /* The memory size needed to hold one loop. */
#define REPEAT     0x33    /* The beginning of the loop. */
#define LEFTPAREN  0x35    /* The beginning of data following the loop. */
#define VAR		     0x55	   /* Plac holder for loop data. */
#define SEC        0x1C    /* The delay time in seconds that must be observed. */
#define SMASK      0x1D    /* The mask for TDI data. */
#define MAX        0x1E    /* The absolute maximum wait time. */
#define ON         0x1F    /* Assert the targeted pin. */
#define OFF        0x20    /* Dis-assert the targeted pin. */
#define SETFLOW    0x30    /* Change the flow control register. */
#define RESETFLOW  0x31    /* Clear the flow control register. */
#define CRC		     0x47    /* The following data stream is used for CRC calculation. */
#define CMASK	     0x48	   /* The following data stream is used as mask for CRC calculation. */
#define RMASK      0x49    /* The following data stream is used as mask for read and save. */
#define READ	     0x50    /* The following data stream is used for read and save. */
#define ENDLOOP    0x59    /* The end of the repeat loop. */
#define SECUREHEAP 0x60    /* Used to secure the HEAP opcode. */
#define VUES       0x61	   /* Support continue if fail. */
#define DMASK      0x62    /* The following data stream is used for dynamic I/O. */
#define COMMENT	   0x63    /* Support SVF comments in the VME file. */
#define HEADER     0x64    /* Support header in VME file. */
#define FILE_CRC   0x65    /* Support crc-protected VME file. */
#define LCOUNT     0x66    /* Support intelligent programming. */
#define LDELAY     0x67    /* Support intelligent programming. */
#define LSDR       0x68    /* Support intelligent programming. */
#define LHEAP      0x69    /* Memory needed to hold intelligent data buffer */
#define CONTINUE   0x70    /* Allow continuation. */
#define LVDS	     0x71	   /* Support LVDS. */
#define ENDVME     0x7F    /* End of the VME file. */
#define HIGH       0x80    /* Assert the targeted pin. */
#define LOW        0x81    /* Dis-assert the targeted pin. */
#define ENDFILE    0xFF    /* End of file. */

/* Denverton GPIO MAPPING */
#define MAP_MASK (sysconf(_SC_PAGE_SIZE)-1)
#define MAP_SIZE(addr) ( (addr & MAP_MASK) + 8 )
#define OFFSET_ADDR(addr) (addr & MAP_MASK)
#define GET_PORT(addr) ( (addr >> 16) & 0xFF )
#define DNV_BAR 0xFD000000
#define DNV_GPIO_TCK_CONFIG 0xFDC20510
#define DNV_GPIO_TMS_CONFIG 0xFDC20508
#define DNV_GPIO_TDI_CONFIG 0xFDC204D8
#define DNV_GPIO_TDO_CONFIG 0xFDC50570
#define DNV_GPIO_DIR_INPUT  1
#define DNV_GPIO_DIR_OUTPUT 0
#define DNV_GPIO_LVL_HIGH   1
#define DNV_GPIO_LVL_LOW    0

// FIXME: This only works on Fishbone/Phalanx
#define CPU_FREQ_MH_CONFIG 2200 /* in MHz */
#define GPIO_USE_SEL	0x500
#define GP_IO_SEL		0x504
#define GP_LVL 			0x50C
#define GPIO_USE_SEL2	0x530
#define GP_IO_SEL2		0x534
#define GP_LVL2 		0x538
#define GPIO_USE_SEL3	0x540
#define GP_IO_SEL3		0x544
#define GP_LVL3 		0x548

#define GPIO_TCK_CONFIG 18
#define GPIO_TMS_CONFIG 9
#define GPIO_TDI_CONFIG 8
#define GPIO_TDO_CONFIG 10
#define GPIO_ENABLE_CONFIG 13	/* GPIO 13 is unused */
#define GPIO_TRST_CONFIG 13     /* GPIO 13 is unused */

/***************************************************************
*
* ispVM Embedded Return Codes.
*
***************************************************************/

#define VME_VERIFICATION_FAILURE		-1
#define VME_FILE_READ_FAILURE			-2
#define VME_VERSION_FAILURE				-3
#define VME_INVALID_FILE				-4
#define VME_ARGUMENT_FAILURE			-5
#define VME_CRC_FAILURE					-6


/***************************************************************
*
* Type definitions.
*
***************************************************************/

/* Support LVDS */
typedef struct {
	unsigned short usPositiveIndex;
	unsigned short usNegativeIndex;
	unsigned char  ucUpdate;
} LVDSPair;

void isp_dnv_gpio_config( unsigned int gpio, unsigned int dir );
void isp_dnv_gpio_write( unsigned int gpio, unsigned int value);
int  isp_dnv_gpio_read( unsigned int gpio);

void isp_dnv_gpio_init(void);
void isp_dnv_gpio_deinit(void);