#ifndef ssd_H_
#define ssd_H_

#define DISP1                   1
#define DISP2                   2

extern u8 Nums[10];


void SSD_init(void);
void SSD_send(u8 N);
void SSD_enable(u8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(u16 N);



#endif
