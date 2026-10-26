/* odeboot "Bootstrap v1.1" (FZ-1 ODE bootloader, first 64 KB of flash) - Ghidra 11.1.2 decompilation of all functions.
   Machine-generated pseudo-C. RAM code 0x200000c0.. is the copy_to_ram image; lma_* = the same code at its flash load address. */

/* ===== FUN_10000000 @ 10000000 (170 bytes) ===== */

void FUN_10000000(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_lr;
  
  iVar3 = DAT_100000cc;
  *(undefined4 *)(DAT_100000cc + 4) = 0x21;
  uVar2 = *(uint *)(iVar3 + 8) & 0xfffffffd;
  *(uint *)(iVar3 + 8) = uVar2;
  *(uint *)(iVar3 + 0xc) = uVar2;
  *(uint *)(iVar3 + 0x10) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2;
  puVar5 = DAT_100000d0;
  DAT_100000d0[2] = 0;
  puVar5[5] = 2;
  puVar5[0x3c] = 1;
  *puVar5 = DAT_100000d4;
  puVar5[2] = 1;
  iVar3 = read_flash_sreg(0x35);
  uVar4 = 2;
  if (iVar3 != 2) {
    puVar5[0x18] = 6;
    FUN_100000aa();
    puVar5[0x18] = 1;
    puVar5[0x18] = 0;
    puVar5[0x18] = uVar4;
    FUN_100000aa();
    uVar4 = puVar5[0x18];
    do {
      uVar2 = read_flash_sreg(5,uVar4);
      uVar4 = 1;
    } while ((uVar2 & 1) != 0);
  }
  puVar5[2] = 0;
  *puVar5 = DAT_100000d8;
  puVar5[1] = 0;
  *DAT_100000e0 = DAT_100000dc;
  puVar5[2] = 1;
  puVar5[0x18] = 0xeb;
  puVar5[0x18] = 0xa0;
  FUN_100000aa();
  puVar5[2] = 0;
  *DAT_100000e0 = DAT_100000e4;
  puVar5[2] = 1;
  puVar5 = DAT_100000e8;
  if (in_lr != 0) {
    return;
  }
  *DAT_100000ec = (int)DAT_100000e8;
  uVar4 = *puVar5;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(uVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x100000a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)puVar5[1])(uVar4);
  return;
}


/* ===== FUN_100000aa @ 100000aa (18 bytes) ===== */

undefined8 FUN_100000aa(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  do {
    do {
    } while ((*(uint *)(param_4 + 0x28) & 4) == 0);
  } while ((*(uint *)(param_4 + 0x28) & 1) != 0);
  return CONCAT44(param_2,param_1);
}


/* ===== read_flash_sreg @ 100000bc (16 bytes) ===== */

undefined8 read_flash_sreg(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_4 + 0x60) = param_1;
  *(undefined4 *)(param_4 + 0x60) = param_1;
  FUN_100000aa();
  return CONCAT44(param_2,*(undefined4 *)(param_4 + 0x60));
}


/* ===== FUN_100001f6 @ 100001f6 (60 bytes) ===== */

void FUN_100001f6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  
  if (*DAT_10000284 != 0) {
    UNRECOVERED_JUMPTABLE = (code *)FUN_100002a0(DAT_1000029c);
                    /* WARNING: Could not recover jumptable at 0x10000274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  piVar5 = &DAT_10000238;
  uVar2 = 0;
  while( true ) {
    puVar1 = DAT_1000028c;
    iVar3 = *piVar5;
    piVar6 = piVar5 + 1;
    piVar5 = piVar5 + 3;
    puVar4 = DAT_10000288;
    if (iVar3 == 0) break;
    uVar2 = FUN_10000230(uVar2,iVar3,*piVar6);
  }
  for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {
    *puVar4 = 0;
  }
  (*DAT_10000290)();
  (*DAT_10000294)();
  (*DAT_10000298)();
  do {
    software_bkpt(0);
  } while( true );
}


/* ===== FUN_10000230 @ 10000230 (10 bytes) ===== */

void FUN_10000230(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_3 = uVar1;
  }
  return;
}


/* ===== FUN_100002a0 @ 100002a0 (10 bytes) ===== */

void FUN_100002a0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x100002a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_100002ac)(param_1);
  return;
}


/* ===== lma_try_boot_app @ 100003cc (80 bytes) ===== */

void lma_try_boot_app(void)

{
  bool bVar1;
  uint *puVar2;
  
  puVar2 = DAT_1000041c;
  lma___wrap_printf(DAT_10000420,*DAT_1000041c,DAT_1000041c[1]);
  if ((((0x1fffffff < *puVar2) && (DAT_10000424 < puVar2[1])) && (*puVar2 <= DAT_10000428)) &&
     (puVar2[1] < 0x11000000)) {
    lma___wrap_printf(DAT_1000042c);
    *DAT_10000430 = puVar2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setMainStackPointer(*puVar2);
    }
                    /* WARNING: Could not recover jumptable at 0x1000041a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar2[1])(*puVar2,(code *)puVar2[1],puVar2 + 2);
    return;
  }
  return;
}


/* ===== lma_main @ 10000434 (804 bytes) ===== */

void lma_main(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar6;
  undefined4 extraout_r1_01;
  uint uVar7;
  uint uVar8;
  
  iVar2 = DAT_10000758;
  lma_stdio_uart_init_full(DAT_10000760,DAT_1000075c,0x10,0x11);
  iVar3 = lma_watchdog_caused_reboot();
  if (iVar3 == 0) {
LAB_10000516:
    lma___wrap_puts(DAT_10000788);
    lma_watchdog_enable(500);
    iVar3 = DAT_10000764;
    *(int *)(DAT_10000764 + 0xc) = DAT_1000076c;
    *(int *)(iVar3 + 0x10) = DAT_10000770;
    *(uint *)(iVar3 + 0x14) = DAT_10000768;
    lma_try_boot_app();
    lma___wrap_puts(DAT_1000078c);
    iVar3 = 4;
  }
  else if (*(uint *)(DAT_10000764 + 0xc) == DAT_10000768) {
    if (*(int *)(DAT_10000764 + 0x10) == DAT_1000076c) {
      if (*(int *)(DAT_10000764 + 0x14) == DAT_10000770) goto LAB_10000516;
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar4 = DAT_10000764;
  if (((*(int *)(DAT_10000764 + 0xc) == DAT_1000076c) &&
      (*(int *)(DAT_10000764 + 0x10) == DAT_10000770)) &&
     (*(uint *)(DAT_10000764 + 0x14) == DAT_10000768)) {
    iVar3 = 1;
  }
  if (((*(int *)(DAT_10000764 + 0xc) == DAT_10000770) &&
      (*(int *)(DAT_10000764 + 0x10) == DAT_1000076c)) &&
     ((*(uint *)(DAT_10000764 + 0x14) & 0xffff0000) == DAT_10000768)) {
    iVar3 = 2;
  }
  else if (iVar3 == 1) {
    uVar7 = 1;
    goto LAB_10000480;
  }
  uVar7 = *(uint *)(DAT_10000764 + 0x14) & 0xffff;
LAB_10000480:
  *(undefined4 *)(DAT_10000764 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  *(undefined4 *)(iVar4 + 0x14) = 0;
  lma_board_init();
  lma___wrap_printf(DAT_10000774,iVar3,uVar7);
  lma_usb_disk_set_nodisk();
  lma_memcpy(DAT_10000778,0,0x200);
  DAT_d0000014 = 0x2000000;
  if (uVar7 == 2) {
    lma_multicore_launch_core1(DAT_10000790);
    do {
      while (iVar3 = lma_usb_disk_status(), iVar3 << 0x1e < 0) {
        lma_sleep_ms(100);
      }
      lma_sleep_ms(100);
      iVar3 = lma_f_mount(DAT_10000798,DAT_10000794,1);
      if (iVar3 == 0) {
        lma___wrap_puts(DAT_1000079c);
        iVar3 = lma_f_opendir(&stack0xffffffec + iVar2,DAT_100007a0);
        if (iVar3 == 0) {
          lma___wrap_puts(DAT_100007a4);
          uVar6 = DAT_10000794;
          iVar3 = lma_f_chdrive(DAT_10000794);
          lma_f_chdir(uVar6);
          if (iVar3 == 0) {
            lma___wrap_puts(DAT_100007a8);
            iVar3 = lma_f_open(&stack0x00000044 + iVar2,DAT_100007ac,1);
            if (iVar3 == 0) {
              lma___wrap_puts(DAT_100007b0);
              lma_f_close(&stack0x00000044 + iVar2);
            }
          }
        }
      }
    } while (iVar3 != 0);
  }
  else {
    iVar3 = lma_f_mount(DAT_10000780,DAT_1000077c,1);
  }
  if (iVar3 != 0) {
    lma___wrap_printf(DAT_100007b4,iVar3);
  }
  lma_connect_internal_flash();
  lma_flash_exit_xip();
  if (iVar3 == 0) {
    iVar3 = lma_f_open(&stack0x00000044 + iVar2,DAT_100007ac,1);
    if (iVar3 == 0) {
      uVar7 = *(uint *)(&stack0x00000054 + iVar2);
      lma___wrap_printf(DAT_100007b8,uVar7);
      bVar1 = true;
      uVar6 = extraout_r1;
      iVar4 = iVar3;
      for (uVar8 = 0; uVar8 < uVar7; uVar8 = uVar8 + 0x1000) {
        iVar4 = lma_f_read(&stack0x00000044 + iVar2,DAT_10000778,0x1000,&stack0xffffffe8 + iVar2);
        if (iVar4 != 0) {
          lma___wrap_printf(DAT_100007c0,iVar4);
          uVar6 = extraout_r1_00;
          break;
        }
        lma_flash_sector_erase(uVar8 + 0x10000);
        lma_flash_range_program(uVar8 + 0x10000,DAT_10000778,0x1000);
        lma___wrap_printf(DAT_100007c4,uVar8);
        lma_watchdog_update();
        bVar1 = (bool)(bVar1 ^ 1);
        if (bVar1) {
          DAT_d0000014 = 0x2000000;
        }
        else {
          DAT_d0000018 = 0x2000000;
        }
        uVar6 = extraout_r1_01;
      }
      lma_f_lseek(&stack0x00000044 + iVar2,uVar6,0,0);
      for (uVar8 = 0; uVar8 < uVar7; uVar8 = uVar8 + 0x1000) {
        lma_flash_read_data(uVar8 + 0x10000,DAT_100007cc,0x1000);
        iVar4 = lma_f_read(&stack0x00000044 + iVar2,DAT_10000778,0x1000,&stack0xffffffe8 + iVar2);
        if (iVar4 != 0) {
          lma___wrap_printf(DAT_100007c0,iVar4);
          break;
        }
        lma___wrap_printf(DAT_100007d0,uVar8,*(undefined4 *)(&stack0xffffffe8 + iVar2));
        iVar5 = lma_memcmp(DAT_10000778,DAT_100007cc,*(undefined4 *)(&stack0xffffffe8 + iVar2));
        if (iVar5 != 0) {
          lma___wrap_puts(DAT_100007c8);
          iVar4 = 0xff;
          break;
        }
        lma_watchdog_update();
        bVar1 = (bool)(bVar1 ^ 1);
        if (bVar1) {
          DAT_d0000014 = 0x2000000;
        }
        else {
          DAT_d0000018 = 0x2000000;
        }
      }
      if (uVar8 < uVar7) {
        iVar3 = iVar4;
      }
      lma_f_close(&stack0x00000044 + iVar2);
    }
    else {
      lma___wrap_printf(DAT_100007bc,iVar3);
    }
  }
  iVar2 = DAT_10000764;
  if (iVar3 == 0) {
    *(uint *)(DAT_10000764 + 0xc) = DAT_10000768;
    *(int *)(iVar2 + 0x10) = DAT_1000076c;
    *(int *)(iVar2 + 0x14) = DAT_10000770;
    lma___wrap_puts(DAT_100007d4);
  }
  else {
    *(undefined4 *)(DAT_10000764 + 0xc) = 0;
    *(int *)(iVar2 + 0x10) = DAT_1000076c;
    *(int *)(iVar2 + 0x14) = DAT_10000770;
    lma___wrap_puts(DAT_10000784);
  }
  lma_watchdog_enable(100,1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ===== FUN_100007d8 @ 100007d8 (100 bytes) ===== */

void FUN_100007d8(void)

{
  uint *puVar1;
  
  *DAT_1000083c = *DAT_1000083c + 10;
  if (*DAT_10000840 < 0xb) {
    *DAT_10000840 = 0;
    DAT_d0000018 = 0x2000000;
  }
  else {
    *DAT_10000840 = *DAT_10000840 - 10;
  }
  puVar1 = DAT_10000844;
  *DAT_10000844 = *DAT_10000844 << 1;
  *puVar1 = (uint)((DAT_d0000004 >> 0x1c & 1) == 0) | *puVar1;
  puVar1 = DAT_10000848;
  *DAT_10000848 = *DAT_10000848 << 1;
  *puVar1 = (uint)((DAT_d0000004 >> 0x13 & 1) == 0) | *puVar1;
  return;
}


/* ===== lma_board_init @ 1000084c (418 bytes) ===== */

void lma_board_init(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  lma_gpio_init(0x19);
  puVar2 = DAT_100009f4;
  uVar1 = DAT_100009f0;
  lma_spi_init(DAT_100009f4,DAT_100009f0);
  puVar3 = DAT_100009f8;
  lma_spi_init(DAT_100009f8,DAT_100009fc);
  lma_gpio_set_function(4,1);
  lma_gpio_set_function(3,1);
  lma_gpio_set_function(2,1);
  lma_gpio_init(0x13);
  lma_gpio_set_function(10,1);
  lma_gpio_set_function(8,1);
  lma_gpio_set_function(0xb,1);
  lma_gpio_init(0x19);
  lma_gpio_init(9);
  lma_gpio_init(0xe);
  lma_gpio_init(0xd);
  lma_gpio_init(0x14);
  lma_gpio_init(0x15);
  lma_gpio_init(0x16);
  lma_gpio_init(0x1c);
  DAT_d0000028 = 0x80000;
  DAT_d0000024 = 0x2000000;
  DAT_d0000014 = 0x2000000;
  lma_gpio_set_drive_strength(0x19,3);
  lma_gpio_set_pulls(0x13,1,0);
  DAT_d0000024 = 0x4000;
  lma_gpio_set_drive_strength(9,3);
  lma_gpio_set_drive_strength(10,3);
  lma_gpio_set_drive_strength(0xb,3);
  lma_gpio_set_drive_strength(0x16,3);
  DAT_d0000018 = 0x400000;
  DAT_d0000014 = 0x4000;
  lma_gpio_set_pulls(0xd,1,0);
  *DAT_10000a00 = 0;
  lma_gpio_init(5);
  DAT_d0000024 = 0x20;
  DAT_d0000014 = 0x20;
  lma_gpio_set_pulls(4,1,0);
  *(uint *)((uint)puVar2 | 0x1000) = (*puVar2 ^ 7) & 0xcf;
  *(uint *)((uint)puVar3 | 0x1000) = (*puVar3 ^ 7) & 0xcf;
  lma_gpio_set_function(0x1b,3);
  lma_gpio_set_function(0x1a,3);
  lma_gpio_set_pulls(0x1b,1,0);
  lma_gpio_set_pulls(0x1a,1,0);
  lma_i2c_init(DAT_10000a04,uVar1);
  *DAT_10000a08 = 0;
  uVar4 = lma_alarm_pool_get_default();
  lma_alarm_pool_add_repeating_timer_us
            ((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_10000a14,0xffffffff,DAT_10000a10,0,
             DAT_10000a0c);
  return;
}


/* ===== lma_sd_spi_set_speed @ 10000a18 (20 bytes) ===== */

void lma_sd_spi_set_speed(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10000a34;
  if (param_1 != 0) {
    uVar1 = DAT_10000a2c;
  }
  lma_spi_set_baudrate(DAT_10000a30,uVar1);
  return;
}


/* ===== lma_ld_word @ 10000a38 (10 bytes) ===== */

undefined2 lma_ld_word(undefined2 *param_1)

{
  return *param_1;
}


/* ===== lma_ld_dword @ 10000a42 (24 bytes) ===== */

undefined4 lma_ld_dword(undefined4 *param_1)

{
  return *param_1;
}


/* ===== lma_ld_qword @ 10000a5a (66 bytes) ===== */

undefined8 lma_ld_qword(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ((uint)param_1[3] | *(int *)(param_1 + 4) << 8) << 8;
  uVar2 = (param_1[2] | uVar1) << 8;
  return CONCAT44((((((uint)*(uint3 *)(param_1 + 5) << 8) >> 0x18) << 8 |
                   (uint)(*(int *)(param_1 + 4) << 8) >> 0x18) << 8 | uVar1 >> 0x18) << 8 |
                  uVar2 >> 0x18,(uint)*param_1 | (param_1[1] | uVar2) << 8);
}


/* ===== lma_st_word @ 10000a9c (8 bytes) ===== */

void lma_st_word(undefined *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  return;
}


/* ===== lma_st_dword @ 10000aa4 (16 bytes) ===== */

void lma_st_dword(undefined *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


/* ===== lma_st_qword @ 10000ab4 (30 bytes) ===== */

void lma_st_qword(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = (char)param_3;
  param_1[1] = (char)((uint)param_3 >> 8);
  param_1[2] = (char)((uint)param_3 >> 0x10);
  param_1[3] = (char)((uint)param_3 >> 0x18);
  param_1[4] = (char)param_4;
  param_1[5] = (char)((uint)param_4 >> 8);
  param_1[6] = (char)((uint)param_4 >> 0x10);
  param_1[7] = (char)((uint)param_4 >> 0x18);
  return;
}


/* ===== lma_dbc_1st__or__dbc_2nd @ 10000ad2 (4 bytes) ===== */

undefined4 lma_dbc_1st__or__dbc_2nd(void)

{
  return 0;
}


/* ===== lma_tchar2uni @ 10000ad8 (192 bytes) ===== */

uint lma_tchar2uni(byte **param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = *param_1 + 1;
  bVar1 = **param_1;
  uVar5 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    if ((uVar5 & 0xffffffe0) == 0xc0) {
      uVar5 = uVar5 & 0x1f;
      iVar4 = 1;
    }
    else if ((uVar5 & 0xfffffff0) == 0xe0) {
      uVar5 = uVar5 & 0xf;
      iVar4 = 2;
    }
    else {
      if ((uVar5 & 0xfffffff8) != 0xf0) {
        return 0xffffffff;
      }
      uVar5 = uVar5 & 7;
      iVar4 = 3;
    }
    do {
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      if ((bVar1 & 0xffffffc0) != 0x80) {
        return 0xffffffff;
      }
      uVar3 = uVar5 << 6;
      uVar2 = bVar1 & 0x3f;
      uVar5 = uVar2 | uVar3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (uVar5 < 0x80) {
      return 0xffffffff;
    }
    if (uVar5 + DAT_10000b98 < 0x800) {
      return 0xffffffff;
    }
    if (0x10ffff < uVar5) {
      return 0xffffffff;
    }
    if (0xffff < uVar5) {
      uVar5 = DAT_10000ba4 | (uVar5 + DAT_10000b9c) * 0x40 & DAT_10000ba0 | uVar2 | uVar3 & 0x3ff;
    }
  }
  *param_1 = pbVar6;
  return uVar5;
}


/* ===== lma_clst2sect @ 10000ba8 (40 bytes) ===== */

longlong lma_clst2sect(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 - 2U < *(int *)(param_1 + 0x2c) - 2U) {
    lVar1 = *(longlong *)(param_1 + 0x50);
    lVar2 = lma___wrap___aeabi_lmul(param_2 - 2U,0,*(undefined2 *)(param_1 + 10),0);
    lVar2 = lVar2 + lVar1;
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}


/* ===== lma_ld_clust @ 10000bd0 (38 bytes) ===== */

uint lma_ld_clust(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = lma_ld_word(param_2 + 0x1a);
  if (*param_1 == '\x03') {
    iVar2 = lma_ld_word(param_2 + 0x14);
    uVar1 = iVar2 << 0x10 | uVar1;
  }
  return uVar1;
}


/* ===== lma_st_clust @ 10000bf6 (38 bytes) ===== */

void lma_st_clust(char *param_1,int param_2,uint param_3)

{
  lma_st_word(param_2 + 0x1a,param_3 & 0xffff);
  if (*param_1 == '\x03') {
    lma_st_word(param_2 + 0x14,param_3 >> 0x10);
  }
  return;
}


/* ===== lma_pick_lfn @ 10000c1c (140 bytes) ===== */

undefined4 lma_pick_lfn(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = lma_ld_word(param_2 + 0x1a);
  if (iVar1 == 0) {
    uVar5 = ((*param_2 & 0xffffffbf) - 1) * 0xd;
    iVar1 = 1;
    for (uVar4 = 0; uVar4 < 0xd; uVar4 = uVar4 + 1) {
      iVar2 = lma_ld_word(param_2 + *(byte *)(DAT_10000cac + uVar4));
      if (iVar1 == 0) {
        if (iVar2 != DAT_10000ca8) {
          return 0;
        }
      }
      else {
        if (0xff < uVar5) {
          return 0;
        }
        *(short *)(param_1 + uVar5 * 2) = (short)iVar2;
        uVar5 = uVar5 + 1;
        iVar1 = iVar2;
      }
    }
    if ((int)((uint)*param_2 << 0x19) < 0) {
      if (iVar1 == 0) {
        uVar3 = 1;
      }
      else if (uVar5 < 0x100) {
        *(undefined2 *)(uVar5 * 2 + param_1) = 0;
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== lma_put_lfn @ 10000cb0 (130 bytes) ===== */

void lma_put_lfn(int param_1,undefined *param_2,uint param_3,undefined param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  param_2[0xd] = param_4;
  param_2[0xb] = 0xf;
  param_2[0xc] = 0;
  lma_st_word(param_2 + 0x1a,0);
  iVar3 = (param_3 - 1) * 0xd;
  uVar1 = 0;
  uVar2 = 0;
  do {
    if (uVar1 != DAT_10000d34) {
      uVar1 = (uint)*(ushort *)(param_1 + iVar3 * 2);
      iVar3 = iVar3 + 1;
    }
    lma_st_word(param_2 + *(byte *)(DAT_10000d38 + uVar2),uVar1);
    if (uVar1 == 0) {
      uVar1 = DAT_10000d34;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xd);
  if ((uVar1 == DAT_10000d34) || (*(short *)(iVar3 * 2 + param_1) == 0)) {
    param_3 = param_3 & 0xff | 0x40;
  }
  *param_2 = (char)param_3;
  return;
}


/* ===== lma_sum_sfn @ 10000d3c (32 bytes) ===== */

uint lma_sum_sfn(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0xb;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (uVar2 >> 1 | (uVar2 & 1) << 7) + (uint)bVar1 & 0xff;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar2;
}


/* ===== lma_xdir_sum @ 10000d5c (46 bytes) ===== */

uint lma_xdir_sum(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < (*(byte *)(param_1 + 1) + 1) * 0x20; uVar2 = uVar2 + 1) {
    if (uVar2 == 2) {
      uVar2 = 3;
    }
    else {
      uVar1 = ((uVar1 >> 1) + uVar1 * 0x8000 & 0xffff) + (uint)*(byte *)(param_1 + uVar2) & 0xffff;
    }
  }
  return uVar1;
}


/* ===== lma_init_alloc_info @ 10000d8a (46 bytes) ===== */

void lma_init_alloc_info(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = lma_ld_dword(*(int *)(param_1 + 0x10) + 0x34);
  *(undefined4 *)(param_2 + 8) = uVar1;
  uVar2 = lma_ld_qword(*(int *)(param_1 + 0x10) + 0x38);
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  *(byte *)(param_2 + 7) = *(byte *)(*(int *)(param_1 + 0x10) + 0x21) & 2;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}


/* ===== lma_get_ldnumber @ 10000db8 (192 bytes) ===== */

uint lma_get_ldnumber(byte **param_1)

{
  uint uVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  pbVar5 = *param_1;
  pbVar3 = pbVar5;
  if (pbVar5 == (byte *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    do {
      bVar4 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      if (bVar4 < 0x20) break;
    } while (bVar4 != 0x3a);
    if (bVar4 == 0x3a) {
      if ((*pbVar5 - 0x30 & 0xff) < 10) {
        if (pbVar5 + 2 == pbVar3) {
          uVar1 = *pbVar5 - 0x30;
          if ((int)uVar1 < 2) {
            *param_1 = pbVar3;
          }
          else {
            uVar1 = 0xffffffff;
          }
        }
        else {
          uVar1 = 0xffffffff;
        }
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else if (*pbVar5 == 0x2f) {
      for (; pbVar5[1] == 0x2f; pbVar5 = pbVar5 + 1) {
      }
      uVar1 = 0;
      do {
        pbVar6 = *(byte **)(uVar1 * 4 + DAT_10000e7c);
        pbVar3 = pbVar5;
        do {
          bVar4 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          pbVar3 = pbVar3 + 1;
          bVar2 = *pbVar3;
          if ((byte)(bVar4 + 0x9f) < 0x1a) {
            bVar4 = bVar4 - 0x20;
          }
          if ((byte)(bVar2 + 0x9f) < 0x1a) {
            bVar2 = bVar2 - 0x20;
          }
        } while ((bVar4 != 0) && (bVar2 == bVar4));
      } while (((bVar4 != 0) || ((bVar2 != 0x2f && (0x1f < bVar2)))) &&
              (uVar1 = uVar1 + 1, (int)uVar1 < 2));
      if ((int)uVar1 < 2) {
        *param_1 = pbVar3;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = (uint)*DAT_10000e78;
    }
  }
  return uVar1;
}


/* ===== lma_crc32 @ 10000e80 (40 bytes) ===== */

void lma_crc32(uint param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 1; uVar1 != 0; uVar1 = (uVar1 & 0x7f) << 1) {
    if ((int)((param_1 ^ (param_2 & uVar1) != 0) << 0x1f) < 0) {
      param_1 = DAT_10000ea8 ^ param_1 >> 1;
    }
    else {
      param_1 = param_1 >> 1;
    }
  }
  return;
}


/* ===== lma_validate @ 10000eac (82 bytes) ===== */

uint lma_validate(char **param_1,char **param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1 == (char **)0x0) {
    uVar1 = 9;
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *param_1;
    if (pcVar3 == (char *)0x0) {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
    else if (*pcVar3 == '\0') {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
    else if (*(short *)(param_1 + 1) == *(short *)(pcVar3 + 6)) {
      uVar2 = lma_disk_status(pcVar3[1]);
      uVar1 = uVar2 & 1;
      if ((uVar2 & 1) == 0) {
        pcVar3 = *param_1;
      }
      else {
        uVar1 = 9;
        pcVar3 = (char *)0x0;
      }
    }
    else {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
  }
  *param_2 = pcVar3;
  return uVar1;
}


/* ===== lma_test_gpt_header @ 10000f00 (96 bytes) ===== */

undefined4 lma_test_gpt_header(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = lma_memcmp(param_1,DAT_10000f60,0x10);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    for (uVar4 = 0; uVar4 < 0x5c; uVar4 = uVar4 + 1) {
      if (uVar4 - 0x10 < 4) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined *)(param_1 + uVar4);
      }
      uVar2 = lma_crc32(uVar2,uVar3);
    }
    uVar4 = lma_ld_dword(param_1 + 0x10);
    uVar5 = 0;
    if (((~uVar2 == uVar4) && (iVar1 = lma_ld_dword(param_1 + 0x54), iVar1 == 0x80)) &&
       (uVar2 = lma_ld_dword(param_1 + 0x50), uVar2 < 0x81)) {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== lma_sync_window @ 10000f64 (112 bytes) ===== */

char lma_sync_window(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = *(char *)(param_1 + 3);
  if (cVar3 != '\0') {
    iVar1 = lma_disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,
                           *(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100),1);
    if (iVar1 == 0) {
      *(undefined *)(param_1 + 3) = 0;
      uVar4 = *(uint *)(param_1 + 0x60);
      uVar2 = *(uint *)(param_1 + 0x30);
      cVar3 = '\0';
      if (((*(int *)(param_1 + 100) - *(int *)(param_1 + 0x44) ==
            (uint)(uVar4 < *(uint *)(param_1 + 0x40))) &&
          (uVar4 - *(uint *)(param_1 + 0x40) < uVar2)) && (*(char *)(param_1 + 2) == '\x02')) {
        lma_disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,uVar2 + uVar4,
                       *(int *)(param_1 + 100) + (uint)CARRY4(uVar2,uVar4),1);
      }
    }
    else {
      cVar3 = '\x01';
    }
  }
  return cVar3;
}


/* ===== lma_move_window @ 10000fd4 (76 bytes) ===== */

int lma_move_window(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x60) == param_3) && (*(int *)(param_1 + 100) == param_4)) {
    iVar2 = 0;
  }
  else {
    iVar2 = lma_sync_window(param_1);
    if (iVar2 == 0) {
      iVar1 = lma_disk_read(*(undefined *)(param_1 + 1),param_1 + 0x68,param_3,param_4,1);
      if (iVar1 != 0) {
        iVar2 = 1;
        param_3 = -1;
        param_4 = -1;
      }
      *(int *)(param_1 + 0x60) = param_3;
      *(int *)(param_1 + 100) = param_4;
    }
  }
  return iVar2;
}


/* ===== lma_check_fs @ 10001020 (240 bytes) ===== */

undefined4 lma_check_fs(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  *(undefined *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  iVar3 = lma_move_window(param_1);
  if (iVar3 == 0) {
    iVar3 = lma_ld_word(param_1 + DAT_10001110);
    if ((iVar3 == DAT_10001114) && (iVar6 = lma_memcmp(param_1 + 0x68,DAT_10001118,0xb), iVar6 == 0)
       ) {
      uVar4 = 1;
    }
    else {
      cVar1 = *(char *)(param_1 + 0x68);
      if ((cVar1 == -0x15) || ((cVar1 == -0x17 || (cVar1 == -0x18)))) {
        if ((iVar3 == DAT_10001114) &&
           (iVar6 = lma_memcmp(param_1 + 0xba,DAT_1000111c,8), iVar6 == 0)) {
          return 0;
        }
        uVar5 = lma_ld_word(param_1 + 0x73);
        bVar2 = *(byte *)(param_1 + 0x75);
        if ((((((((uVar5 - 1 & uVar5) == 0) && (0x1ff < uVar5)) && (uVar5 < 0x201)) &&
              ((bVar2 != 0 && ((bVar2 - 1 & bVar2) == 0)))) &&
             ((iVar6 = lma_ld_word(param_1 + 0x76), iVar6 != 0 &&
              ((*(byte *)(param_1 + 0x78) - 1 < 2 &&
               (iVar6 = lma_ld_word(param_1 + 0x79), iVar6 != 0)))))) &&
            ((uVar5 = lma_ld_word(param_1 + 0x7b), 0x7f < uVar5 ||
             (uVar5 = lma_ld_dword(param_1 + 0x88), 0xffff < uVar5)))) &&
           (iVar6 = lma_ld_word(param_1 + 0x7e), iVar6 != 0)) {
          return 0;
        }
      }
      if (iVar3 == DAT_10001114) {
        uVar4 = 2;
      }
      else {
        uVar4 = 3;
      }
    }
  }
  else {
    uVar4 = 4;
  }
  return uVar4;
}


/* ===== lma_find_volume @ 10001120 (322 bytes) ===== */

uint lma_find_volume(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  int local_3c;
  int local_38 [5];
  
  uVar8 = lma_check_fs(param_1,param_2,0,0);
  uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
  uVar5 = (uint)uVar8;
  if ((uVar5 == 2) || ((uVar5 < 3 && (param_2 != 0)))) {
    if (*(char *)(param_1 + DAT_10001264) == -0x12) {
      iVar2 = lma_move_window(param_1,uVar3,1,0);
      if (iVar2 == 0) {
        iVar7 = param_1 + 0x68;
        iVar2 = lma_test_gpt_header(iVar7);
        if (iVar2 == 0) {
          uVar5 = 3;
        }
        else {
          uVar5 = lma_ld_dword(param_1 + 0xb8);
          lVar9 = lma_ld_qword(param_1 + 0xb0);
          uVar3 = (undefined4)((ulonglong)lVar9 >> 0x20);
          local_3c = 0;
          for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
            lVar1 = lVar9 + (ulonglong)((uVar6 << 7) >> 9);
            iVar2 = lma_move_window(param_1,uVar3,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
            if (iVar2 != 0) {
              return 4;
            }
            uVar4 = uVar6 << 7 & 0x180;
            uVar8 = lma_memcmp(iVar7 + uVar4,DAT_10001268,0x10);
            uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
            if ((int)uVar8 == 0) {
              local_3c = local_3c + 1;
              uVar8 = lma_ld_qword(uVar4 + 0x20 + iVar7);
              uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
              uVar8 = lma_check_fs(param_1,uVar3,(int)uVar8,uVar3);
              uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
              uVar4 = (uint)uVar8;
              if ((param_2 == 0) && (uVar4 < 2)) {
                return uVar4;
              }
              if ((param_2 != 0) && (param_2 == local_3c)) {
                return uVar4;
              }
            }
          }
          uVar5 = 3;
        }
      }
      else {
        uVar5 = 4;
      }
    }
    else {
      for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {
        uVar8 = lma_ld_dword(param_1 + uVar5 * 0x10 + 0x22e);
        uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
        local_38[uVar5] = (int)uVar8;
      }
      if (param_2 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = param_2 - 1;
      }
      do {
        if (local_38[uVar6] == 0) {
          uVar8 = CONCAT44(uVar3,3);
        }
        else {
          uVar8 = lma_check_fs(param_1,uVar3,local_38[uVar6],0);
        }
        uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
        uVar5 = (uint)uVar8;
      } while (((param_2 == 0) && (1 < uVar5)) && (uVar6 = uVar6 + 1, uVar6 < 4));
    }
  }
  return uVar5;
}


/* ===== lma_mount_volume @ 1000126c (1302 bytes) ===== */

uint lma_mount_volume(undefined4 param_1,char **param_2,uint param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  longlong lVar18;
  longlong lVar19;
  undefined8 uVar20;
  
  *param_2 = (char *)0x0;
  iVar3 = lma_get_ldnumber();
  if (iVar3 < 0) {
    uVar16 = 0xb;
  }
  else {
    pcVar15 = *(char **)(iVar3 * 4 + DAT_100015b8);
    if (pcVar15 == (char *)0x0) {
      uVar16 = 0xc;
    }
    else {
      *param_2 = pcVar15;
      if (*pcVar15 != '\0') {
        uVar4 = lma_disk_status(pcVar15[1]);
        if ((uVar4 & 1) == 0) {
          if ((param_3 & 0xfffffffe) == 0) {
            return uVar4 & 1;
          }
          if (-1 < (int)(uVar4 << 0x1d)) {
            return uVar4 & 1;
          }
          return 10;
        }
      }
      *pcVar15 = '\0';
      pcVar15[1] = (char)iVar3;
      uVar4 = lma_disk_initialize();
      uVar16 = uVar4 & 1;
      if ((uVar4 & 1) == 0) {
        if (((param_3 & 0xfffffffe) == 0) || (-1 < (int)(uVar4 << 0x1d))) {
          uVar4 = lma_find_volume(pcVar15,0);
          if (uVar4 == 4) {
            uVar16 = 1;
          }
          else if (uVar4 < 2) {
            uVar12 = *(uint *)(pcVar15 + 0x60);
            iVar3 = *(int *)(pcVar15 + 100);
            lVar19 = *(longlong *)(pcVar15 + 0x60);
            if (uVar4 == 1) {
              for (uVar4 = 0xb; (uVar4 < 0x40 && (pcVar15[uVar4 + 0x68] == '\0')); uVar4 = uVar4 + 1
                  ) {
              }
              if (uVar4 < 0x40) {
                uVar16 = 0xd;
              }
              else {
                iVar7 = lma_ld_word(pcVar15 + 0xd0);
                if (iVar7 == 0x100) {
                  if (pcVar15[0xd4] == '\t') {
                    lVar18 = lma_ld_qword(pcVar15 + 0xb0);
                    lVar18 = lVar18 + lVar19;
                    uVar4 = (uint)((ulonglong)lVar18 >> 0x20);
                    uVar8 = lma_ld_dword(pcVar15 + 0xbc);
                    *(undefined4 *)(pcVar15 + 0x30) = uVar8;
                    pcVar15[2] = pcVar15[0xd6];
                    if (pcVar15[0xd6] == '\x01') {
                      uVar14 = 1 << (uint)(byte)pcVar15[0xd5] & 0xffff;
                      *(short *)(pcVar15 + 10) = (short)(1 << (uint)(byte)pcVar15[0xd5]);
                      if (uVar14 == 0) {
                        uVar16 = 0xd;
                      }
                      else {
                        uVar9 = lma_ld_dword(pcVar15 + 0xc4);
                        if (DAT_100015c8 < uVar9) {
                          uVar16 = 0xd;
                        }
                        else {
                          *(uint *)(pcVar15 + 0x2c) = uVar9 + 2;
                          *(uint *)(pcVar15 + 0x38) = uVar12;
                          *(int *)(pcVar15 + 0x3c) = iVar3;
                          uVar10 = lma_ld_dword(pcVar15 + 0xc0);
                          uVar11 = uVar12 + uVar10;
                          iVar7 = iVar3 + (uint)CARRY4(uVar12,uVar10);
                          *(uint *)(pcVar15 + 0x50) = uVar11;
                          *(int *)(pcVar15 + 0x54) = iVar7;
                          uVar10 = lma_ld_dword(pcVar15 + 0xb8);
                          *(uint *)(pcVar15 + 0x40) = uVar10 + uVar12;
                          *(uint *)(pcVar15 + 0x44) = iVar3 + (uint)CARRY4(uVar10,uVar12);
                          uVar9 = uVar9 * uVar14;
                          uVar12 = iVar7 + (uint)CARRY4(uVar9,uVar11);
                          if ((uVar4 <= uVar12 && uVar12 != uVar4) ||
                             ((uVar12 == uVar4 && ((uint)lVar18 < uVar9 + uVar11)))) {
                            uVar16 = 0xd;
                          }
                          else {
                            uVar8 = lma_ld_dword(pcVar15 + 200);
                            *(undefined4 *)(pcVar15 + 0x48) = uVar8;
                            *(undefined4 *)(pcVar15 + 0x4c) = 0;
                            uVar4 = 0;
                            uVar12 = 0;
                            while( true ) {
                              if (uVar4 == 0) {
                                if (*(ushort *)(pcVar15 + 10) <= uVar12) {
                                  return 0xd;
                                }
                                lVar19 = lma_clst2sect(pcVar15,*(undefined4 *)(pcVar15 + 0x48));
                                iVar3 = lma_move_window(pcVar15,(int)((ulonglong)lVar19 >> 0x20),
                                                        (int)(lVar19 + (ulonglong)uVar12),
                                                        (int)(lVar19 + (ulonglong)uVar12 >> 0x20));
                                if (iVar3 != 0) {
                                  return 1;
                                }
                                uVar12 = uVar12 + 1;
                              }
                              if (pcVar15[uVar4 + 0x68] == -0x7f) break;
                              uVar4 = uVar4 + 0x20 & 0x1ff;
                            }
                            uVar4 = lma_ld_dword(pcVar15 + uVar4 + 0x7c);
                            if (uVar4 < 2) {
                              uVar16 = 0xd;
                            }
                            else if (uVar4 < *(uint *)(pcVar15 + 0x2c)) {
                              uVar12 = (uint)*(ushort *)(pcVar15 + 10) * (uVar4 - 2);
                              iVar3 = *(int *)(pcVar15 + 0x54);
                              *(uint *)(pcVar15 + 0x58) = uVar12 + *(uint *)(pcVar15 + 0x50);
                              *(uint *)(pcVar15 + 0x5c) =
                                   iVar3 + (uint)CARRY4(uVar12,*(uint *)(pcVar15 + 0x50));
                              do {
                                iVar3 = lma_move_window(pcVar15,iVar3,
                                                        *(uint *)(pcVar15 + 0x40) + (uVar4 >> 7),
                                                        *(int *)(pcVar15 + 0x44) +
                                                        (uint)CARRY4(*(uint *)(pcVar15 + 0x40),
                                                                     uVar4 >> 7));
                                if (iVar3 != 0) {
                                  return 1;
                                }
                                uVar20 = lma_ld_dword(pcVar15 + (uVar4 & 0x7f) * 4 + 0x68);
                                iVar3 = (int)((ulonglong)uVar20 >> 0x20);
                                if ((uint)uVar20 == 0xffffffff) {
                                  *(undefined4 *)(pcVar15 + 0x18) = 0xffffffff;
                                  *(undefined4 *)(pcVar15 + 0x14) = 0xffffffff;
                                  cVar13 = '\x04';
                                  goto LAB_10001656;
                                }
                                uVar4 = uVar4 + 1;
                              } while ((uint)uVar20 == uVar4);
                              uVar16 = 0xd;
                            }
                            else {
                              uVar16 = 0xd;
                            }
                          }
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                    }
                  }
                  else {
                    uVar16 = 0xd;
                  }
                }
                else {
                  uVar16 = 0xd;
                }
              }
            }
            else {
              iVar7 = lma_ld_word(pcVar15 + 0x73);
              if (iVar7 == 0x200) {
                uVar4 = lma_ld_word(pcVar15 + 0x7e);
                if (uVar4 == 0) {
                  uVar4 = lma_ld_dword(pcVar15 + 0x8c);
                }
                *(uint *)(pcVar15 + 0x30) = uVar4;
                bVar1 = pcVar15[0x78];
                pcVar15[2] = bVar1;
                if ((bVar1 - 1 & 0xff) < 2) {
                  uVar14 = uVar4 * bVar1;
                  uVar9 = (uint)(byte)pcVar15[0x75];
                  *(ushort *)(pcVar15 + 10) = (ushort)(byte)pcVar15[0x75];
                  if (uVar9 == 0) {
                    uVar16 = 0xd;
                  }
                  else if ((uVar9 - 1 & uVar9) == 0) {
                    uVar10 = lma_ld_word(pcVar15 + 0x79);
                    *(short *)(pcVar15 + 8) = (short)uVar10;
                    if ((uVar10 & 0xf) == 0) {
                      uVar11 = lma_ld_word(pcVar15 + 0x7b);
                      if (uVar11 == 0) {
                        uVar11 = lma_ld_dword(pcVar15 + 0x88);
                      }
                      uVar5 = lma_ld_word(pcVar15 + 0x76);
                      if (uVar5 == 0) {
                        uVar16 = 0xd;
                      }
                      else {
                        uVar17 = uVar14 + uVar5 + (uVar10 >> 4 & 0xffff);
                        if (uVar11 < uVar17) {
                          uVar16 = 0xd;
                        }
                        else {
                          uVar6 = lma___aeabi_uidiv(uVar11 - uVar17,uVar9);
                          if (uVar11 - uVar17 < uVar9) {
                            uVar16 = 0xd;
                          }
                          else {
                            if (DAT_100015bc < uVar6) {
                              cVar13 = '\0';
                            }
                            else {
                              cVar13 = '\x03';
                            }
                            if (uVar6 <= DAT_100015c0) {
                              cVar13 = '\x02';
                            }
                            if (DAT_100015c4 < uVar6) {
                              if (cVar13 == '\0') {
                                return 0xd;
                              }
                            }
                            else {
                              cVar13 = '\x01';
                            }
                            uVar6 = uVar6 + 2;
                            *(uint *)(pcVar15 + 0x2c) = uVar6;
                            *(uint *)(pcVar15 + 0x38) = uVar12;
                            *(int *)(pcVar15 + 0x3c) = iVar3;
                            uVar9 = uVar5 + uVar12;
                            iVar7 = iVar3 + (uint)CARRY4(uVar5,uVar12);
                            *(uint *)(pcVar15 + 0x40) = uVar9;
                            *(int *)(pcVar15 + 0x44) = iVar7;
                            *(uint *)(pcVar15 + 0x50) = uVar17 + uVar12;
                            *(uint *)(pcVar15 + 0x54) = iVar3 + (uint)CARRY4(uVar17,uVar12);
                            if (cVar13 == '\x03') {
                              iVar7 = lma_ld_word(pcVar15 + 0x92);
                              if (iVar7 != 0) {
                                return 0xd;
                              }
                              if (uVar10 != 0) {
                                return 0xd;
                              }
                              uVar8 = lma_ld_dword(pcVar15 + 0x94);
                              *(undefined4 *)(pcVar15 + 0x48) = uVar8;
                              *(undefined4 *)(pcVar15 + 0x4c) = 0;
                              iVar7 = uVar6 * 4;
                            }
                            else {
                              if (uVar10 == 0) {
                                return 0xd;
                              }
                              *(uint *)(pcVar15 + 0x48) = uVar14 + uVar9;
                              *(uint *)(pcVar15 + 0x4c) = iVar7 + (uint)CARRY4(uVar14,uVar9);
                              if (cVar13 == '\x02') {
                                iVar7 = uVar6 * 2;
                              }
                              else {
                                iVar7 = (uVar6 * 3 >> 1) + (uVar6 & 1);
                              }
                            }
                            if (uVar4 < (uint)(iVar7 + DAT_10001798) >> 9) {
                              uVar16 = 0xd;
                            }
                            else {
                              *(undefined4 *)(pcVar15 + 0x18) = 0xffffffff;
                              *(undefined4 *)(pcVar15 + 0x14) = 0xffffffff;
                              pcVar15[4] = -0x80;
                              if (((cVar13 == '\x03') &&
                                  (iVar7 = lma_ld_word(pcVar15 + 0x98), iVar7 == 1)) &&
                                 (iVar3 = iVar3 + (uint)(0xfffffffe < uVar12),
                                 iVar3 = lma_move_window(pcVar15,iVar3,uVar12 + 1,iVar3), iVar3 == 0
                                 )) {
                                pcVar15[4] = '\0';
                                iVar3 = lma_ld_word(pcVar15 + DAT_100017a8);
                                if (((iVar3 == DAT_100017ac) &&
                                    (iVar3 = lma_ld_dword(pcVar15 + 0x68), iVar3 == DAT_100017b0))
                                   && (iVar3 = lma_ld_dword(pcVar15 + 0x24c), iVar3 == DAT_100017b4)
                                   ) {
                                  uVar8 = lma_ld_dword(pcVar15 + 0x250);
                                  *(undefined4 *)(pcVar15 + 0x18) = uVar8;
                                  uVar8 = lma_ld_dword(pcVar15 + 0x254);
                                  *(undefined4 *)(pcVar15 + 0x14) = uVar8;
                                }
                              }
LAB_10001656:
                              *pcVar15 = cVar13;
                              sVar2 = *DAT_1000179c;
                              *DAT_1000179c = sVar2 + 1;
                              *(short *)(pcVar15 + 6) = sVar2 + 1;
                              *(undefined4 *)(pcVar15 + 0xc) = DAT_100017a0;
                              *(undefined4 *)(pcVar15 + 0x10) = DAT_100017a4;
                              *(undefined4 *)(pcVar15 + 0x1c) = 0;
                            }
                          }
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                    }
                  }
                  else {
                    uVar16 = 0xd;
                  }
                }
                else {
                  uVar16 = 0xd;
                }
              }
              else {
                uVar16 = 0xd;
              }
            }
          }
          else {
            uVar16 = 0xd;
          }
        }
        else {
          uVar16 = 10;
        }
      }
      else {
        uVar16 = 3;
      }
    }
  }
  return uVar16;
}


/* ===== lma_find_bitmap @ 100017b8 (166 bytes) ===== */

int lma_find_bitmap(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_28;
  
  uVar7 = param_2 - 2;
  if (*(int *)(param_1 + 0x2c) - 2U <= uVar7) {
    uVar7 = 0;
  }
  iVar6 = 0;
  uVar5 = uVar7;
  local_28 = uVar7;
  do {
    iVar1 = lma_move_window(param_1,0,*(uint *)(param_1 + 0x58) + (uVar5 >> 0xc),
                            *(int *)(param_1 + 0x5c) +
                            (uint)CARRY4(*(uint *)(param_1 + 0x58),uVar5 >> 0xc));
    if (iVar1 != 0) {
      return -1;
    }
    uVar2 = uVar5 >> 3 & 0x1ff;
    uVar4 = 1 << (uVar5 & 7) & 0xff;
    while( true ) {
      do {
        uVar3 = *(byte *)(param_1 + uVar2 + 0x68) & uVar4;
        uVar4 = (uVar4 & 0x7f) << 1;
        uVar5 = uVar5 + 1;
        if (*(int *)(param_1 + 0x2c) - 2U <= uVar5) {
          uVar5 = 0;
          uVar2 = 0x200;
          uVar4 = 0;
        }
        if (uVar3 == 0) {
          iVar6 = iVar6 + 1;
          if (iVar6 == param_3) {
            return local_28 + 2;
          }
        }
        else {
          iVar6 = 0;
          local_28 = uVar5;
        }
        if (uVar7 == uVar5) {
          return 0;
        }
      } while (uVar4 != 0);
      uVar2 = uVar2 + 1;
      if (0x1ff < uVar2) break;
      uVar4 = 1;
    }
  } while( true );
}


/* ===== lma_change_bitmap @ 1000185e (150 bytes) ===== */

undefined4 lma_change_bitmap(int param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = param_2 - 2;
  uVar3 = (uVar6 >> 0xc) + *(uint *)(param_1 + 0x58);
  iVar5 = *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar6 >> 0xc,*(uint *)(param_1 + 0x58));
  uVar8 = uVar6 >> 3 & 0x1ff;
  uVar6 = 1 << (uVar6 & 7) & 0xff;
  do {
    iVar7 = iVar5 + (uint)(0xfffffffe < uVar3);
    uVar2 = uVar3 + 1;
    iVar4 = lma_move_window(param_1,iVar5,uVar3,iVar5,uVar3 + 1,iVar7);
    iVar5 = iVar7;
    uVar3 = uVar2;
    if (iVar4 != 0) {
      return 1;
    }
    while( true ) {
      do {
        bVar1 = *(byte *)(param_1 + uVar8 + 0x68);
        if (((uVar6 & bVar1) != 0) == param_4) {
          return 2;
        }
        *(byte *)(param_1 + uVar8 + 0x68) = bVar1 ^ (byte)uVar6;
        *(undefined *)(param_1 + 3) = 1;
        param_3 = param_3 + -1;
        if (param_3 == 0) {
          return 0;
        }
        uVar2 = uVar6 & 0x7f;
        uVar6 = uVar2 * 2;
      } while (uVar2 != 0);
      uVar8 = uVar8 + 1;
      uVar6 = 1;
      if (0x1ff < uVar8) break;
      uVar6 = 1;
    }
    uVar8 = 0;
  } while( true );
}


/* ===== lma_put_fat @ 100018f4 (374 bytes) ===== */

int lma_put_fat(byte *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 < 2) {
    iVar3 = 2;
  }
  else if (param_2 < *(uint *)(param_1 + 0x2c)) {
    bVar1 = *param_1;
    if (bVar1 == 2) {
      iVar3 = lma_move_window(param_1,*(int *)(param_1 + 0x44),
                              (param_2 >> 8) + *(uint *)(param_1 + 0x40),
                              *(int *)(param_1 + 0x44) +
                              (uint)CARRY4(param_2 >> 8,*(uint *)(param_1 + 0x40)));
      if (iVar3 == 0) {
        lma_st_word(param_1 + (param_2 & 0xff) * 2 + 0x68,param_3 & 0xffff);
        param_1[3] = 1;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 1) {
        uVar4 = (param_2 >> 1) + param_2;
        iVar3 = lma_move_window(param_1,*(int *)(param_1 + 0x44),
                                (uVar4 >> 9) + *(uint *)(param_1 + 0x40),
                                *(int *)(param_1 + 0x44) +
                                (uint)CARRY4(uVar4 >> 9,*(uint *)(param_1 + 0x40)));
        if (iVar3 == 0) {
          if ((param_2 & 1) == 0) {
            bVar1 = (byte)param_3;
          }
          else {
            bVar1 = param_1[(uVar4 & 0x1ff) + 0x68] & 0xf | (byte)(param_3 << 4);
          }
          param_1[(uVar4 & 0x1ff) + 0x68] = bVar1;
          param_1[3] = 1;
          uVar2 = uVar4 + 1 >> 9;
          iVar3 = lma_move_window(param_1,*(int *)(param_1 + 0x44),uVar2 + *(uint *)(param_1 + 0x40)
                                  ,*(int *)(param_1 + 0x44) +
                                   (uint)CARRY4(uVar2,*(uint *)(param_1 + 0x40)));
          if (iVar3 == 0) {
            if ((param_2 & 1) == 0) {
              bVar1 = (byte)(param_3 >> 8) & 0xf | param_1[(uVar4 + 1 & 0x1ff) + 0x68] & 0xf0;
            }
            else {
              bVar1 = (byte)(param_3 >> 4);
            }
            param_1[(uVar4 + 1 & 0x1ff) + 0x68] = bVar1;
            param_1[3] = 1;
          }
        }
      }
      else {
        iVar3 = 2;
      }
    }
    else if ((byte)(bVar1 - 3) < 2) {
      iVar3 = lma_move_window(param_1,*(int *)(param_1 + 0x44),
                              (param_2 >> 7) + *(uint *)(param_1 + 0x40),
                              *(int *)(param_1 + 0x44) +
                              (uint)CARRY4(param_2 >> 7,*(uint *)(param_1 + 0x40)));
      if (iVar3 == 0) {
        if (*param_1 != 4) {
          uVar4 = lma_ld_dword(param_1 + (param_2 & 0x7f) * 4 + 0x68);
          param_3 = param_3 & 0xfffffff | uVar4 & 0xf0000000;
        }
        lma_st_dword(param_1 + (param_2 & 0x7f) * 4 + 0x68,param_3);
        param_1[3] = 1;
      }
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 2;
  }
  return iVar3;
}


/* ===== lma_fill_last_frag @ 10001a6a (50 bytes) ===== */

int lma_fill_last_frag(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    uVar2 = param_1[7];
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = param_3;
    if (1 < uVar2) {
      iVar1 = (param_2 - uVar2) + 2;
    }
    iVar1 = lma_put_fat(*param_1,(param_2 - uVar2) + 1,iVar1);
    if (iVar1 != 0) break;
    param_1[7] = param_1[7] + -1;
  }
  return iVar1;
}


/* ===== lma_fill_first_frag @ 10001a9c (50 bytes) ===== */

int lma_fill_first_frag(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)((int)param_1 + 7) == '\x03') {
    iVar2 = param_1[2];
    for (iVar3 = param_1[6]; iVar3 != 0; iVar3 = iVar3 + -1) {
      iVar1 = lma_put_fat(*param_1,iVar2,iVar2 + 1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    }
    *(undefined *)((int)param_1 + 7) = 0;
  }
  return 0;
}


/* ===== lma_get_fat @ 10001ad0 (422 bytes) ===== */

uint lma_get_fat(byte **param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  pbVar8 = *param_1;
  if (param_2 < 2) {
    uVar4 = 1;
  }
  else if (param_2 < *(uint *)(pbVar8 + 0x2c)) {
    bVar1 = *pbVar8;
    if (bVar1 == 3) {
      iVar3 = lma_move_window(pbVar8,*(int *)(pbVar8 + 0x44),
                              (param_2 >> 7) + *(uint *)(pbVar8 + 0x40),
                              *(int *)(pbVar8 + 0x44) +
                              (uint)CARRY4(param_2 >> 7,*(uint *)(pbVar8 + 0x40)),param_4);
      if (iVar3 == 0) {
        uVar4 = lma_ld_dword(pbVar8 + (param_2 & 0x7f) * 4 + 0x68);
        uVar4 = uVar4 & 0xfffffff;
      }
      else {
        uVar4 = 0xffffffff;
      }
    }
    else if (bVar1 < 4) {
      if (bVar1 == 1) {
        uVar4 = (param_2 >> 1) + param_2;
        iVar3 = lma_move_window(pbVar8,*(int *)(pbVar8 + 0x44),
                                (uVar4 >> 9) + *(uint *)(pbVar8 + 0x40),
                                *(int *)(pbVar8 + 0x44) +
                                (uint)CARRY4(uVar4 >> 9,*(uint *)(pbVar8 + 0x40)),param_4);
        if (iVar3 == 0) {
          bVar1 = pbVar8[(uVar4 & 0x1ff) + 0x68];
          uVar6 = uVar4 + 1 >> 9;
          iVar3 = lma_move_window(pbVar8,*(int *)(pbVar8 + 0x44),uVar6 + *(uint *)(pbVar8 + 0x40),
                                  *(int *)(pbVar8 + 0x44) +
                                  (uint)CARRY4(uVar6,*(uint *)(pbVar8 + 0x40)),param_4);
          if (iVar3 == 0) {
            if ((int)(param_2 << 0x1f) < 0) {
              uVar4 = (uint)(ushort)(CONCAT11(pbVar8[(uVar4 + 1 & 0x1ff) + 0x68],bVar1) >> 4);
            }
            else {
              uVar4 = CONCAT11(pbVar8[(uVar4 + 1 & 0x1ff) + 0x68],bVar1) & 0xfff;
            }
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      else if (bVar1 == 2) {
        iVar3 = lma_move_window(pbVar8,*(int *)(pbVar8 + 0x44),
                                (param_2 >> 8) + *(uint *)(pbVar8 + 0x40),
                                *(int *)(pbVar8 + 0x44) +
                                (uint)CARRY4(param_2 >> 8,*(uint *)(pbVar8 + 0x40)),param_4);
        if (iVar3 == 0) {
          uVar4 = lma_ld_word(pbVar8 + (param_2 & 0xff) * 2 + 0x68);
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      else {
        uVar4 = 1;
      }
    }
    else if (bVar1 == 4) {
      pbVar5 = param_1[4];
      if (((((uint)pbVar5 | (uint)param_1[5]) == 0) || (param_1[2] == (byte *)0x0)) &&
         (*(char *)((int)param_1 + 7) != '\0')) {
        uVar4 = 1;
      }
      else {
        pbVar9 = (byte *)(param_2 - (int)param_1[2]);
        pbVar7 = param_1[5] + ((pbVar5 != (byte *)0x0) - 1);
        pbVar5 = (byte *)lma___aeabi_uldivmod
                                   ((uint)(pbVar5 + -1) >> 9 | (int)pbVar7 * 0x800000,
                                    (uint)pbVar7 >> 9,*(undefined2 *)(pbVar8 + 10),0);
        cVar2 = *(char *)((int)param_1 + 7);
        uVar4 = DAT_10001c78;
        if ((cVar2 == '\x02') && (pbVar9 <= pbVar5)) {
          if (pbVar9 != pbVar5) {
            uVar4 = param_2 + 1;
          }
        }
        else if ((cVar2 == '\x03') && (pbVar9 < param_1[6])) {
          uVar4 = param_2 + 1;
        }
        else if (cVar2 == '\x02') {
          uVar4 = 1;
        }
        else if (param_1[7] == (byte *)0x0) {
          iVar3 = lma_move_window(pbVar8,*(int *)(pbVar8 + 0x44),
                                  (param_2 >> 7) + *(uint *)(pbVar8 + 0x40),
                                  *(int *)(pbVar8 + 0x44) +
                                  (uint)CARRY4(param_2 >> 7,*(uint *)(pbVar8 + 0x40)),param_4);
          if (iVar3 == 0) {
            uVar4 = lma_ld_dword(pbVar8 + (param_2 & 0x7f) * 4 + 0x68);
            uVar4 = uVar4 & 0x7fffffff;
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
      }
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


/* ===== lma_create_chain @ 10001c7c (454 bytes) ===== */

uint lma_create_chain(char **param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  pcVar4 = *param_1;
  if (param_2 == 0) {
    uVar2 = *(uint *)(pcVar4 + 0x14);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    else if (*(uint *)(pcVar4 + 0x2c) <= uVar2) {
      uVar2 = 1;
    }
  }
  else {
    uVar5 = lma_get_fat();
    if (uVar5 < 2) {
      return 1;
    }
    if (uVar5 == 0xffffffff) {
      return 0xffffffff;
    }
    uVar2 = param_2;
    if (uVar5 < *(uint *)(pcVar4 + 0x2c)) {
      return uVar5;
    }
  }
  if (*(int *)(pcVar4 + 0x18) == 0) {
    return 0;
  }
  if (*pcVar4 == '\x04') {
    uVar5 = lma_find_bitmap(pcVar4,uVar2,1);
    if (0xfffffffd < uVar5 - 1) {
      return uVar5;
    }
    iVar1 = lma_change_bitmap(pcVar4,uVar5,1,1);
    if (iVar1 == 2) {
      return 1;
    }
    if (iVar1 == 1) {
      return 0xffffffff;
    }
    if (param_2 == 0) {
      *(undefined *)((int)param_1 + 7) = 2;
    }
    else if ((*(char *)((int)param_1 + 7) == '\x02') && (uVar2 + 1 != uVar5)) {
      param_1[6] = (char *)(uVar2 - (int)param_1[2]);
      *(undefined *)((int)param_1 + 7) = 3;
    }
    if (*(char *)((int)param_1 + 7) != '\x02') {
      if (param_2 + 1 == uVar5) {
        if (param_1[7] == (char *)0x0) {
          pcVar3 = (char *)0x2;
        }
        else {
          pcVar3 = param_1[7] + 1;
        }
        param_1[7] = pcVar3;
      }
      else {
        if (param_1[7] == (char *)0x0) {
          param_1[7] = (char *)0x1;
        }
        iVar1 = lma_fill_last_frag(param_1,param_2,uVar5);
        if (iVar1 == 0) {
          param_1[7] = (char *)0x1;
        }
      }
    }
LAB_10001db8:
    if (iVar1 == 0) {
      *(uint *)(pcVar4 + 0x14) = uVar5;
      if (*(uint *)(pcVar4 + 0x18) <= *(int *)(pcVar4 + 0x2c) - 2U) {
        *(uint *)(pcVar4 + 0x18) = *(uint *)(pcVar4 + 0x18) - 1;
      }
      pcVar4[4] = pcVar4[4] | 1;
    }
    else if (iVar1 == 1) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 1;
    }
  }
  else {
    uVar6 = uVar2;
    if (uVar2 == param_2) {
      uVar5 = uVar2 + 1;
      if (*(uint *)(pcVar4 + 0x2c) <= uVar5) {
        uVar5 = 2;
      }
      iVar1 = lma_get_fat(param_1,uVar5);
      if (iVar1 == 1) {
        return 1;
      }
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (iVar1 == 0) {
        if (uVar5 != 0) {
LAB_10001da2:
          iVar1 = lma_put_fat(pcVar4,uVar5,0xffffffff);
          if ((iVar1 == 0) && (param_2 != 0)) {
            iVar1 = lma_put_fat(pcVar4,param_2,uVar5);
          }
          goto LAB_10001db8;
        }
      }
      else {
        uVar5 = *(uint *)(pcVar4 + 0x14);
        if ((1 < uVar5) && (uVar5 < *(uint *)(pcVar4 + 0x2c))) {
          uVar2 = uVar5;
          uVar6 = uVar5;
        }
      }
    }
    do {
      uVar5 = uVar2 + 1;
      if (*(uint *)(pcVar4 + 0x2c) <= uVar5) {
        if (uVar6 < 2) {
          return 0;
        }
        uVar5 = 2;
      }
      iVar1 = lma_get_fat(param_1,uVar5);
      if (iVar1 == 0) goto LAB_10001da2;
      if (iVar1 == 1) {
        return 1;
      }
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      uVar2 = uVar5;
    } while (uVar5 != uVar6);
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== lma_dir_sdi @ 10001e42 (212 bytes) ===== */

undefined4 lma_dir_sdi(byte **param_1,code *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  code *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined8 uVar7;
  
  pbVar3 = *param_1;
  if (*pbVar3 == 4) {
    pcVar4 = FUN_10000000;
  }
  else {
    pcVar4 = (code *)0x200000;
  }
  if (param_2 < pcVar4) {
    if (((uint)param_2 & 0x1f) == 0) {
      param_1[0xc] = (byte *)param_2;
      pbVar6 = param_1[2];
      if ((pbVar6 == (byte *)0x0) && (2 < *pbVar3)) {
        pbVar6 = *(byte **)(pbVar3 + 0x48);
        *(undefined *)((int)param_1 + 7) = 0;
      }
      if (pbVar6 == (byte *)0x0) {
        if ((uint)*(ushort *)(pbVar3 + 8) <= (uint)param_2 >> 5) {
          return 2;
        }
        pbVar5 = *(byte **)(pbVar3 + 0x4c);
        param_1[0xe] = *(byte **)(pbVar3 + 0x48);
        param_1[0xf] = pbVar5;
      }
      else {
        uVar1 = *(ushort *)(pbVar3 + 10);
        for (; (code *)((uint)uVar1 * 0x200) <= param_2; param_2 = param_2 + (uint)uVar1 * -0x200) {
          pbVar6 = (byte *)lma_get_fat(param_1,pbVar6);
          if (pbVar6 == (byte *)0xffffffff) {
            return 1;
          }
          if (pbVar6 < (byte *)0x2) {
            return 2;
          }
          if (*(byte **)(pbVar3 + 0x2c) <= pbVar6) {
            return 2;
          }
        }
        uVar7 = lma_clst2sect(pbVar3,pbVar6);
        *(undefined8 *)(param_1 + 0xe) = uVar7;
      }
      param_1[0xd] = pbVar6;
      pbVar6 = param_1[0xe];
      if (((uint)pbVar6 | (uint)param_1[0xf]) == 0) {
        uVar2 = 2;
      }
      else {
        param_1[0xe] = pbVar6 + ((uint)param_2 >> 9);
        param_1[0xf] = param_1[0xf] + CARRY4((uint)pbVar6,(uint)param_2 >> 9);
        param_1[0x10] = pbVar3 + ((uint)param_2 & 0x1ff) + 0x68;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


/* ===== lma_dir_clear @ 10001f16 (138 bytes) ===== */

bool lma_dir_clear(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  longlong lVar4;
  
  iVar1 = lma_sync_window();
  if (iVar1 == 0) {
    lVar4 = lma_clst2sect(param_1,param_2);
    *(longlong *)(param_1 + 0x60) = lVar4;
    lma_memset(param_1 + 0x68,0,0x200);
    for (uVar2 = 0; uVar2 < *(ushort *)(param_1 + 10); uVar2 = uVar2 + 1) {
      iVar1 = lma_disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,
                             (int)(lVar4 + (ulonglong)uVar2),(int)(lVar4 + (ulonglong)uVar2 >> 0x20)
                             ,1);
      if (iVar1 != 0) break;
    }
    bVar3 = *(ushort *)(param_1 + 10) != uVar2;
  }
  else {
    bVar3 = true;
  }
  return bVar3;
}


/* ===== lma_dir_next @ 10001fa0 (260 bytes) ===== */

undefined4 lma_dir_next(char **param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  char *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  pcVar4 = *param_1;
  pcVar5 = (code *)(param_1[0xc] + 0x20);
  if (*pcVar4 == '\x04') {
    pcVar3 = FUN_10000000;
  }
  else {
    pcVar3 = (code *)0x200000;
  }
  if (pcVar3 <= pcVar5) {
    param_1[0xe] = (char *)0x0;
    param_1[0xf] = (char *)0x0;
  }
  pcVar2 = param_1[0xe];
  if (((uint)pcVar2 | (uint)param_1[0xf]) == 0) {
    return 4;
  }
  if (((uint)pcVar5 & 0x1ff) == 0) {
    param_1[0xe] = pcVar2 + 1;
    param_1[0xf] = param_1[0xf] + ((char *)0xfffffffe < pcVar2);
    if (param_1[0xd] == (char *)0x0) {
      if ((uint)*(ushort *)(pcVar4 + 8) <= (uint)pcVar5 >> 5) {
        param_1[0xe] = (char *)0x0;
        param_1[0xf] = (char *)0x0;
        return 4;
      }
    }
    else if ((*(ushort *)(pcVar4 + 10) - 1 & (uint)pcVar5 >> 9) == 0) {
      pcVar2 = (char *)lma_get_fat(param_1);
      if (pcVar2 < (char *)0x2) {
        return 2;
      }
      if (pcVar2 == (char *)0xffffffff) {
        return 1;
      }
      if (*(char **)(pcVar4 + 0x2c) <= pcVar2) {
        if (param_2 == 0) {
          param_1[0xe] = (char *)0x0;
          param_1[0xf] = (char *)0x0;
          return 4;
        }
        pcVar2 = (char *)lma_create_chain(param_1,param_1[0xd]);
        if (pcVar2 == (char *)0x0) {
          return 7;
        }
        if (pcVar2 == (char *)0x1) {
          return 2;
        }
        if (pcVar2 == (char *)0xffffffff) {
          return 1;
        }
        iVar1 = lma_dir_clear(pcVar4,pcVar2);
        if (iVar1 != 0) {
          return 1;
        }
        *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) | 4;
      }
      param_1[0xd] = pcVar2;
      uVar6 = lma_clst2sect(pcVar4,pcVar2);
      *(undefined8 *)(param_1 + 0xe) = uVar6;
    }
  }
  param_1[0xc] = (char *)pcVar5;
  param_1[0x10] = pcVar4 + ((uint)pcVar5 & 0x1ff) + 0x68;
  return 0;
}


/* ===== lma_dir_alloc @ 100020a4 (112 bytes) ===== */

int lma_dir_alloc(char **param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  pcVar4 = *param_1;
  uVar6 = lma_dir_sdi(param_1,0,param_3,param_4,param_4);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  iVar1 = (int)uVar6;
  if (iVar1 == 0) {
    iVar5 = 0;
    do {
      iVar1 = lma_move_window(pcVar4,uVar2,param_1[0xe],param_1[0xf]);
      if (iVar1 != 0) break;
      if (*pcVar4 == '\x04') {
        uVar3 = (uint)~(int)*param_1[0x10] >> 0x1f;
      }
      else if (*param_1[0x10] == -0x1b) {
        uVar3 = 1;
      }
      else if (*param_1[0x10] == '\0') {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      if (uVar3 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar5 + 1;
        if (iVar5 == param_2) break;
      }
      uVar6 = lma_dir_next(param_1,1);
      uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
      iVar1 = (int)uVar6;
    } while (iVar1 == 0);
  }
  if (iVar1 == 4) {
    iVar1 = 7;
  }
  return iVar1;
}


/* ===== lma_load_xdir @ 10002114 (268 bytes) ===== */

int lma_load_xdir(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  iVar3 = *(int *)(*param_1 + 0x10);
  iVar1 = lma_move_window(*param_1,param_2,param_1[0xe],param_1[0xf]);
  if (iVar1 == 0) {
    if (*(char *)param_1[0x10] == -0x7b) {
      lma_memcpy(iVar3,(char *)param_1[0x10],0x20);
      iVar2 = *(byte *)(iVar3 + 1) + 1;
      uVar4 = iVar2 * 0x20;
      if (uVar4 - 0x60 < 0x201) {
        uVar6 = lma_dir_next(param_1,0);
        iVar1 = (int)uVar6;
        if (iVar1 == 4) {
          iVar1 = 2;
        }
        else if ((iVar1 == 0) &&
                (iVar1 = lma_move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],
                                         param_1[0xf]), iVar1 == 0)) {
          if (*(char *)param_1[0x10] == -0x40) {
            lma_memcpy(iVar3 + 0x20,(char *)param_1[0x10],0x20);
            iVar1 = lma___aeabi_uidiv(*(byte *)(iVar3 + 0x23) + 0x2c,0xf);
            if ((uint)(iVar1 * 0x20) < uVar4 || iVar1 * 0x20 + iVar2 * -0x20 == 0) {
              uVar5 = 0x40;
              do {
                uVar6 = lma_dir_next(param_1,0);
                iVar1 = (int)uVar6;
                if (iVar1 == 4) {
                  return 2;
                }
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = lma_move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],
                                        param_1[0xf]);
                if (iVar1 != 0) {
                  return iVar1;
                }
                if (*(char *)param_1[0x10] != -0x3f) {
                  return 2;
                }
                if (uVar5 < 0x260) {
                  lma_memcpy(iVar3 + uVar5,(char *)param_1[0x10],0x20);
                }
                uVar5 = uVar5 + 0x20;
              } while (uVar5 <= uVar4 && uVar4 - uVar5 != 0);
              iVar1 = 0;
              if (uVar5 < 0x261) {
                iVar2 = lma_xdir_sum(iVar3);
                iVar3 = lma_ld_word(iVar3 + 2);
                if (iVar2 != iVar3) {
                  iVar1 = 2;
                }
              }
            }
            else {
              iVar1 = 2;
            }
          }
          else {
            iVar1 = 2;
          }
        }
      }
      else {
        iVar1 = 2;
      }
    }
    else {
      iVar1 = 2;
    }
  }
  return iVar1;
}


/* ===== lma_load_obj_xdir @ 10002220 (54 bytes) ===== */

void lma_load_obj_xdir(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_1 = *param_2;
  param_1[2] = param_2[8];
  *(char *)((int)param_1 + 7) = (char)param_2[9];
  param_1[4] = param_2[9] & 0xffffff00;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[0x14] = param_2[10];
  iVar1 = lma_dir_sdi();
  if (iVar1 == 0) {
    lma_load_xdir(param_1);
  }
  return;
}


/* ===== lma_dir_read @ 10002256 (276 bytes) ===== */

int lma_dir_read(char **param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  pcVar6 = *param_1;
  uVar7 = 0xff;
  uVar8 = 0xff;
  iVar5 = 4;
  do {
    if ((((uint)param_1[0xe] | (uint)param_1[0xf]) == 0) ||
       (iVar5 = lma_move_window(pcVar6), iVar5 != 0)) break;
    pbVar2 = (byte *)param_1[0x10];
    uVar4 = (uint)*pbVar2;
    if (uVar4 == 0) {
      iVar5 = 4;
      break;
    }
    if (*pcVar6 == '\x04') {
      if (uVar4 == 0x85) {
        param_1[0x14] = param_1[0xc];
        iVar5 = lma_load_xdir(param_1);
        if (iVar5 == 0) {
          *(byte *)((int)param_1 + 6) = *(byte *)(*(int *)(pcVar6 + 0x10) + 4) & 0x3f;
        }
        break;
      }
    }
    else {
      bVar1 = pbVar2[0xb];
      bVar3 = bVar1 & 0x3f;
      *(byte *)((int)param_1 + 6) = bVar3;
      if (uVar4 == 0xe5) {
        uVar8 = 0xff;
      }
      else if (uVar4 == 0x2e) {
        uVar8 = 0xff;
      }
      else if (((bVar1 & 0x1f) == 8) == param_2) {
        if (bVar3 != 0xf) {
          if ((uVar8 != 0) || (uVar8 = lma_sum_sfn(pbVar2), uVar8 != uVar7)) {
            param_1[0x14] = (char *)0xffffffff;
          }
          break;
        }
        if ((int)(uVar4 << 0x19) < 0) {
          uVar7 = (uint)pbVar2[0xd];
          uVar4 = uVar4 & 0xffffffbf;
          param_1[0x14] = param_1[0xc];
          uVar8 = uVar4;
        }
        if (uVar4 == uVar8) {
          if (pbVar2[0xd] == uVar7) {
            iVar5 = lma_pick_lfn(*(undefined4 *)(pcVar6 + 0xc));
            if (iVar5 == 0) {
              uVar8 = 0xff;
            }
            else {
              uVar8 = uVar8 - 1 & 0xff;
            }
          }
          else {
            uVar8 = 0xff;
          }
        }
        else {
          uVar8 = 0xff;
        }
      }
      else {
        uVar8 = 0xff;
      }
    }
    iVar5 = lma_dir_next(param_1,0);
  } while (iVar5 == 0);
  if (iVar5 != 0) {
    param_1[0xe] = (char *)0x0;
    param_1[0xf] = (char *)0x0;
  }
  return iVar5;
}


/* ===== lma_gen_numname @ 1000236c (168 bytes) ===== */

void lma_gen_numname(int param_1,undefined4 param_2,ushort *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  char acStack_21 [13];
  
  lma_memcpy(param_1,param_2,0xb);
  if (5 < param_4) {
    while (uVar3 = (uint)*param_3, uVar3 != 0) {
      param_3 = param_3 + 1;
      for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1) {
        uVar6 = param_4 * 2 + (uVar3 & 1);
        uVar3 = uVar3 >> 1;
        if ((int)(param_4 << 0x10) < 0) {
          uVar6 = uVar6 ^ DAT_10002414;
        }
        param_4 = uVar6;
      }
    }
  }
  uVar3 = 7;
  do {
    uVar5 = uVar3;
    uVar3 = (param_4 & 0xf) + 0x30;
    cVar4 = (char)uVar3;
    if (0x39 < uVar3) {
      cVar4 = (char)(param_4 & 0xf) + '7';
    }
    uVar3 = uVar5 - 1;
    acStack_21[uVar5 + 1] = cVar4;
  } while ((uVar5 != 1) && (bVar1 = 0xf < param_4, param_4 = param_4 >> 4, bVar1));
  acStack_21[uVar5] = '~';
  uVar6 = 0;
  do {
    if ((uVar3 <= uVar6) || (*(char *)(param_1 + uVar6) == ' ')) goto LAB_10002404;
    iVar2 = lma_dbc_1st__or__dbc_2nd();
    if (iVar2 != 0) {
      if (uVar5 - 2 == uVar6) {
LAB_10002404:
        do {
          if (uVar3 < 8) {
            cVar4 = acStack_21[uVar3 + 1];
            uVar3 = uVar3 + 1;
          }
          else {
            cVar4 = ' ';
          }
          uVar5 = uVar6 + 1;
          *(char *)(param_1 + uVar6) = cVar4;
          uVar6 = uVar5;
        } while (uVar5 < 8);
        return;
      }
      uVar6 = uVar6 + 1;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}


/* ===== lma_store_xdir @ 10002418 (102 bytes) ===== */

undefined lma_store_xdir(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar4 = *(int *)(*param_1 + 0x10);
  uVar2 = lma_xdir_sum(iVar4);
  lma_st_word(iVar4 + 2,uVar2);
  iVar5 = *(byte *)(iVar4 + 1) + 1;
  uVar6 = lma_dir_sdi(param_1,param_1[0x14]);
  while ((uVar3 = (uint)uVar6, uVar3 == 0 &&
         (uVar3 = lma_move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],param_1[0xf]
                                  ,param_4), uVar3 == 0))) {
    lma_memcpy(param_1[0x10],iVar4,0x20);
    *(undefined *)(*param_1 + 3) = 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) break;
    iVar4 = iVar4 + 0x20;
    uVar6 = lma_dir_next(param_1,0);
  }
  uVar1 = (undefined)uVar3;
  if (2 < uVar3) {
    uVar1 = 2;
  }
  return uVar1;
}


/* ===== lma_create_name @ 10002480 (784 bytes) ===== */

undefined4 lma_create_name(int *param_1,byte **param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_34;
  byte *local_2c [2];
  
  local_2c[0] = *param_2;
  iVar9 = *(int *)(*param_1 + 0xc);
  uVar8 = 0;
  while( true ) {
    uVar2 = lma_tchar2uni(local_2c);
    if (uVar2 == 0xffffffff) {
      return 6;
    }
    if (0xffff < uVar2) {
      *(short *)(iVar9 + uVar8 * 2) = (short)(uVar2 >> 0x10);
      uVar8 = uVar8 + 1;
    }
    uVar10 = uVar2 & 0xffff;
    if (((uVar10 < 0x20) || (uVar10 == 0x2f)) || (uVar10 == 0x5c)) break;
    if ((uVar10 < 0x80) && (iVar3 = lma_strchr(DAT_10002790,uVar2 & 0xffff), iVar3 != 0)) {
      return 6;
    }
    if (0xfe < uVar8) {
      return 6;
    }
    *(short *)(iVar9 + uVar8 * 2) = (short)uVar2;
    uVar8 = uVar8 + 1;
  }
  if (uVar10 < 0x20) {
    uVar2 = 4;
  }
  else {
    for (; (bVar6 = *local_2c[0], bVar6 == 0x2f || (bVar6 == 0x5c)); local_2c[0] = local_2c[0] + 1)
    {
    }
    if (bVar6 < 0x20) {
      uVar2 = 4;
    }
    else {
      uVar2 = 0;
    }
  }
  *param_2 = local_2c[0];
  if (((uVar8 == 1) && (*(short *)((DAT_10002794 + 1) * 2 + iVar9) == 0x2e)) ||
     ((uVar8 == 2 &&
      ((*(short *)((DAT_10002794 + 2) * 2 + iVar9) == 0x2e &&
       (*(short *)((DAT_10002798 + 2) * 2 + iVar9) == 0x2e)))))) {
    *(undefined2 *)(iVar9 + uVar8 * 2) = 0;
    for (uVar10 = 0; uVar10 < 0xb; uVar10 = uVar10 + 1) {
      if (uVar10 < uVar8) {
        uVar5 = 0x2e;
      }
      else {
        uVar5 = 0x20;
      }
      *(undefined *)((int)param_1 + uVar10 + 0x44) = uVar5;
    }
    *(byte *)((int)param_1 + uVar10 + 0x44) = (byte)uVar2 | 0x20;
    uVar4 = 0;
  }
  else {
    while ((uVar8 != 0 &&
           ((sVar1 = *(short *)(iVar9 + (uVar8 + DAT_10002794) * 2), sVar1 == 0x20 ||
            (sVar1 == 0x2e))))) {
      uVar8 = uVar8 - 1;
    }
    *(undefined2 *)(iVar9 + uVar8 * 2) = 0;
    if (uVar8 != 0) {
      for (uVar10 = 0; sVar1 = *(short *)(uVar10 * 2 + iVar9), sVar1 == 0x20; uVar10 = uVar10 + 1) {
      }
      if ((uVar10 != 0) || (sVar1 == 0x2e)) {
        uVar2 = uVar2 | 3;
      }
      while ((uVar8 != 0 && (*(short *)((uVar8 + DAT_10002794) * 2 + iVar9) != 0x2e))) {
        uVar8 = uVar8 - 1;
      }
      lma_memset(param_1 + 0x11,0x20,0xb);
      uVar13 = 8;
      local_34 = 0;
      uVar12 = 0;
LAB_100025e4:
      do {
        uVar7 = uVar10 + 1;
        uVar11 = (uint)*(ushort *)(iVar9 + uVar10 * 2);
        if (uVar11 == 0) {
LAB_10002650:
          if (*(char *)(param_1 + 0x11) == -0x1b) {
            *(undefined *)(param_1 + 0x11) = 5;
          }
          if (uVar13 == 8) {
            uVar12 = (uVar12 & 0x3f) << 2;
          }
          if (((uVar12 & 0xc) == 0xc) || ((uVar12 & 3) == 3)) {
            uVar2 = uVar2 | 2;
          }
          bVar6 = (byte)uVar2;
          if (-1 < (int)(uVar2 << 0x1e)) {
            if ((int)(uVar12 << 0x1f) < 0) {
              bVar6 = bVar6 | 0x10;
            }
            if ((int)(uVar12 << 0x1d) < 0) {
              bVar6 = bVar6 | 8;
            }
          }
          *(byte *)((int)param_1 + 0x4f) = bVar6;
          return 0;
        }
        uVar10 = uVar7;
        if ((uVar11 == 0x20) || ((uVar11 == 0x2e && (uVar8 != uVar7)))) {
          uVar2 = uVar2 | 3;
          goto LAB_100025e4;
        }
        if ((local_34 < uVar13) && (uVar8 != uVar7)) {
          if (0x7f < uVar11) {
            uVar2 = uVar2 | 2;
            uVar11 = lma_ff_uni2oem(uVar11,0x1b5);
            if ((int)(uVar11 << 0x18) < 0) {
              uVar11 = (uint)*(byte *)(DAT_1000279c + (uVar11 & 0x7f));
            }
          }
          if (uVar11 < 0x100) {
            if ((uVar11 == 0) || (iVar3 = lma_strchr(DAT_100027a0,uVar11), iVar3 != 0)) {
              uVar2 = uVar2 | 3;
              uVar11 = 0x5f;
            }
            else {
              if ((uVar11 - 0x41 & 0xffff) < 0x1a) {
                uVar12 = uVar12 | 2;
              }
              if ((uVar11 - 0x61 & 0xffff) < 0x1a) {
                uVar12 = uVar12 | 1;
                uVar11 = uVar11 - 0x20 & 0xffff;
              }
            }
          }
          else {
            if (uVar13 - 1 <= local_34) {
              uVar2 = uVar2 | 3;
              local_34 = uVar13;
              goto LAB_100025e4;
            }
            *(char *)((int)param_1 + local_34 + 0x44) = (char)(uVar11 >> 8);
            local_34 = local_34 + 1;
          }
          *(char *)((int)param_1 + local_34 + 0x44) = (char)uVar11;
          local_34 = local_34 + 1;
          goto LAB_100025e4;
        }
        if (uVar13 == 0xb) {
          uVar2 = uVar2 | 3;
          goto LAB_10002650;
        }
        if (uVar8 != uVar7) {
          uVar2 = uVar2 | 3;
        }
        if (uVar8 < uVar7) goto LAB_10002650;
        uVar12 = (uVar12 & 0x3f) << 2;
        uVar13 = 0xb;
        local_34 = 8;
        uVar10 = uVar8;
      } while( true );
    }
    uVar4 = 6;
  }
  return uVar4;
}


/* ===== lma_xname_sum @ 100027a4 (56 bytes) ===== */

uint lma_xname_sum(short *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (*param_1 == 0) break;
    uVar1 = lma_ff_wtoupper();
    uVar2 = ((uVar2 >> 1) + uVar2 * 0x8000 & 0xffff) + (uVar1 & 0xff) & 0xffff;
    uVar2 = ((uVar2 >> 1) + uVar2 * 0x8000 & 0xffff) + ((uVar1 & 0xffff) >> 8) & 0xffff;
    param_1 = param_1 + 1;
  }
  return uVar2;
}


/* ===== lma_create_xdir @ 100027dc (144 bytes) ===== */

void lma_create_xdir(undefined *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  char cVar7;
  
  lma_memset(param_1,0,0x40);
  *param_1 = 0x85;
  param_1[0x20] = 0xc0;
  sVar5 = 1;
  uVar6 = 0;
  uVar4 = 0x40;
  cVar1 = '\0';
  do {
    cVar7 = cVar1;
    iVar3 = uVar4 + 1;
    param_1[uVar4] = 0xc1;
    uVar4 = uVar4 + 2;
    param_1[iVar3] = 0;
    do {
      if ((sVar5 != 0) && (sVar5 = *(short *)(param_2 + uVar6 * 2), sVar5 != 0)) {
        uVar6 = uVar6 + 1 & 0xff;
      }
      lma_st_word(param_1 + uVar4,sVar5);
      uVar4 = uVar4 + 2;
    } while ((uVar4 & 0x1f) != 0);
    cVar1 = cVar7 + '\x01';
  } while (*(short *)(uVar6 * 2 + param_2) != 0);
  param_1[0x23] = (char)uVar6;
  param_1[1] = cVar7 + '\x02';
  uVar2 = lma_xname_sum(param_2);
  lma_st_word(param_1 + 0x24,uVar2);
  return;
}


/* ===== lma_cmp_lfn @ 1000286c (166 bytes) ===== */

undefined4 lma_cmp_lfn(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  iVar1 = lma_ld_word(param_2 + 0x1a);
  if (iVar1 == 0) {
    iVar1 = 1;
    uVar7 = ((*param_2 & 0x3f) - 1) * 0xd;
    for (uVar6 = 0; uVar6 < 0xd; uVar6 = uVar6 + 1) {
      iVar2 = lma_ld_word(param_2 + *(byte *)(DAT_10002918 + uVar6));
      if (iVar1 == 0) {
        bVar8 = iVar2 != DAT_10002914;
        iVar2 = iVar1;
        uVar5 = uVar7;
        if (bVar8) {
          return 0;
        }
      }
      else {
        if (0xff < uVar7) {
          return 0;
        }
        iVar1 = lma_ff_wtoupper();
        uVar5 = uVar7 + 1;
        iVar3 = lma_ff_wtoupper(*(undefined2 *)(uVar7 * 2 + param_1));
        if (iVar1 != iVar3) {
          return 0;
        }
      }
      iVar1 = iVar2;
      uVar7 = uVar5;
    }
    if ((int)((uint)*param_2 << 0x19) < 0) {
      if (iVar1 == 0) {
        uVar4 = 1;
      }
      else if (*(short *)(uVar7 * 2 + param_1) == 0) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* ===== lma_dir_find @ 1000291c (396 bytes) ===== */

int lma_dir_find(char **param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  undefined8 uVar14;
  
  pcVar13 = *param_1;
  uVar14 = lma_dir_sdi(param_1,0);
  uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
  iVar3 = (int)uVar14;
  if (iVar3 == 0) {
    if (*pcVar13 == '\x04') {
      iVar2 = lma_xname_sum(*(undefined4 *)(pcVar13 + 0xc));
      do {
        do {
          iVar3 = lma_dir_read(param_1,0);
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar11 = *(int *)(pcVar13 + 0x10);
          iVar3 = lma_ld_word(iVar11 + 0x24);
        } while (iVar3 != iVar2);
        iVar7 = 0;
        uVar6 = 0x40;
        for (cVar10 = *(char *)(iVar11 + 0x23); cVar10 != '\0'; cVar10 = cVar10 + -1) {
          if ((uVar6 & 0x1f) == 0) {
            uVar6 = uVar6 + 2;
          }
          lma_ld_word(*(int *)(pcVar13 + 0x10) + uVar6);
          iVar3 = lma_ff_wtoupper();
          iVar11 = lma_ff_wtoupper(*(undefined2 *)(iVar7 * 2 + *(int *)(pcVar13 + 0xc)));
          if (iVar3 != iVar11) break;
          uVar6 = uVar6 + 2;
          iVar7 = iVar7 + 1;
        }
      } while ((cVar10 != '\0') || (iVar3 = 0, *(short *)(iVar7 * 2 + *(int *)(pcVar13 + 0xc)) != 0)
              );
    }
    else {
      param_1[0x14] = (char *)0xffffffff;
      uVar6 = 0xff;
      uVar9 = uVar6;
      while (iVar3 = lma_move_window(pcVar13,uVar4,param_1[0xe],param_1[0xf]), iVar3 == 0) {
        pbVar12 = (byte *)param_1[0x10];
        uVar5 = (uint)*pbVar12;
        if (uVar5 == 0) {
          return 4;
        }
        bVar1 = pbVar12[0xb];
        uVar8 = bVar1 & 0x3f;
        *(char *)((int)param_1 + 6) = (char)uVar8;
        if ((uVar5 == 0xe5) || (((int)((uint)bVar1 << 0x1c) < 0 && (uVar8 != 0xf)))) {
          param_1[0x14] = (char *)0xffffffff;
          uVar6 = 0xff;
        }
        else if (uVar8 == 0xf) {
          if (-1 < (int)((uint)*(byte *)((int)param_1 + 0x4f) << 0x19)) {
            if ((int)(uVar5 << 0x19) < 0) {
              uVar9 = (uint)pbVar12[0xd];
              uVar5 = uVar5 & 0xffffffbf;
              param_1[0x14] = param_1[0xc];
              uVar6 = uVar5;
            }
            if (uVar5 == uVar6) {
              if (pbVar12[0xd] == uVar9) {
                iVar3 = lma_cmp_lfn(*(undefined4 *)(pcVar13 + 0xc),pbVar12);
                if (iVar3 == 0) {
                  uVar6 = 0xff;
                }
                else {
                  uVar6 = uVar6 - 1 & 0xff;
                }
              }
              else {
                uVar6 = 0xff;
              }
            }
            else {
              uVar6 = 0xff;
            }
          }
        }
        else {
          if ((uVar6 == 0) && (uVar6 = lma_sum_sfn(pbVar12), uVar6 == uVar9)) {
            return 0;
          }
          if ((-1 < (int)((uint)*(byte *)((int)param_1 + 0x4f) << 0x1f)) &&
             (iVar3 = lma_memcmp(pbVar12,param_1 + 0x11,0xb), iVar3 == 0)) {
            return 0;
          }
          param_1[0x14] = (char *)0xffffffff;
          uVar6 = 0xff;
        }
        uVar14 = lma_dir_next(param_1,0);
        uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
        if ((int)uVar14 != 0) {
          return (int)uVar14;
        }
      }
    }
  }
  return iVar3;
}


/* ===== lma_follow_path @ 10002aa8 (286 bytes) ===== */

int lma_follow_path(char **param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  byte *local_6c;
  undefined auStack_68 [88];
  
  pcVar5 = *param_1;
  bVar1 = *param_2;
  local_6c = param_2;
  if (((bVar1 == 0x2f) || (bVar1 == 0x5c)) || (bVar1 < 0x20)) {
    for (; (*local_6c == 0x2f || (*local_6c == 0x5c)); local_6c = local_6c + 1) {
    }
    param_1[2] = (char *)0x0;
  }
  else {
    param_1[2] = *(char **)(pcVar5 + 0x1c);
  }
  param_1[7] = (char *)0x0;
  if ((*pcVar5 == '\x04') && (param_1[2] != (char *)0x0)) {
    param_1[8] = *(char **)(pcVar5 + 0x20);
    param_1[9] = *(char **)(pcVar5 + 0x24);
    param_1[10] = *(char **)(pcVar5 + 0x28);
    iVar2 = lma_load_obj_xdir(auStack_68,param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    pcVar3 = (char *)lma_ld_dword(*(int *)(pcVar5 + 0x10) + 0x38);
    param_1[4] = pcVar3;
    param_1[5] = (char *)0x0;
    *(byte *)((int)param_1 + 7) = *(byte *)(*(int *)(pcVar5 + 0x10) + 0x21) & 2;
  }
  if (*local_6c < 0x20) {
    *(undefined *)((int)param_1 + 0x4f) = 0x80;
    iVar2 = lma_dir_sdi(param_1,0);
  }
  else {
    do {
      while( true ) {
        iVar2 = lma_create_name(param_1,&local_6c);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = lma_dir_find(param_1);
        uVar4 = (uint)*(byte *)((int)param_1 + 0x4f);
        if (iVar2 != 0) break;
        if ((int)(uVar4 << 0x1d) < 0) {
          return 0;
        }
        if (-1 < (int)((uint)*(byte *)((int)param_1 + 6) << 0x1b)) {
          return 5;
        }
        if (*pcVar5 == '\x04') {
          param_1[8] = param_1[2];
          param_1[9] = (char *)((uint)param_1[4] & 0xffffff00 | (uint)*(byte *)((int)param_1 + 7));
          param_1[10] = param_1[0x14];
          lma_init_alloc_info(pcVar5,param_1);
        }
        else {
          pcVar3 = (char *)lma_ld_clust(pcVar5,pcVar5 + ((uint)param_1[0xc] & 0x1ff) + 0x68);
          param_1[2] = pcVar3;
        }
      }
      if (iVar2 != 4) {
        return iVar2;
      }
      if (-1 < (int)(uVar4 << 0x1a)) {
        if ((int)(uVar4 << 0x1d) < 0) {
          return 4;
        }
        return 5;
      }
    } while (-1 < (int)(uVar4 << 0x1d));
    *(undefined *)((int)param_1 + 0x4f) = 0x80;
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== lma_dir_register @ 10002bc6 (514 bytes) ===== */

int lma_dir_register(char **param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int unaff_r8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined auStack_80 [92];
  undefined auStack_24 [11];
  byte local_19;
  
  pcVar6 = *param_1;
  bVar1 = *(byte *)((int)param_1 + 0x4f);
  if ((bVar1 & 0xa0) != 0) {
    return 6;
  }
  for (iVar7 = 0; *(short *)(iVar7 * 2 + *(int *)(pcVar6 + 0xc)) != 0; iVar7 = iVar7 + 1) {
  }
  if (*pcVar6 == '\x04') {
    iVar7 = lma___aeabi_uidiv(iVar7 + 0xe,0xf);
    iVar3 = lma_dir_alloc(param_1,iVar7 + 2);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1[0x14] = param_1[0xc] + (iVar7 + 1) * -0x20;
    if ((int)((uint)*(byte *)((int)param_1 + 7) << 0x1d) < 0) {
      *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) & 0xfb;
      iVar7 = lma_fill_first_frag(param_1);
      if (iVar7 != 0) {
        return iVar7;
      }
      iVar7 = lma_fill_last_frag(param_1,param_1[0xd],0xffffffff);
      if (iVar7 != 0) {
        return iVar7;
      }
      if (param_1[2] != (char *)0x0) {
        iVar7 = lma_load_obj_xdir(auStack_80,param_1);
        if (iVar7 != 0) {
          return iVar7;
        }
        uVar2 = *(ushort *)(pcVar6 + 10);
        pcVar4 = param_1[4];
        param_1[4] = pcVar4 + (uint)uVar2 * 0x200;
        param_1[5] = param_1[5] + CARRY4((uint)uVar2 * 0x200,(uint)pcVar4);
        lma_st_qword(*(int *)(pcVar6 + 0x10) + 0x38);
        lma_st_qword(*(int *)(pcVar6 + 0x10) + 0x28,extraout_r1,param_1[4],param_1[5]);
        *(byte *)(*(int *)(pcVar6 + 0x10) + 0x21) = *(byte *)((int)param_1 + 7) | 1;
        iVar7 = lma_store_xdir(auStack_80);
        if (iVar7 != 0) {
          return iVar7;
        }
      }
    }
    lma_create_xdir(*(undefined4 *)(pcVar6 + 0x10),*(undefined4 *)(pcVar6 + 0xc));
    return 0;
  }
  lma_memcpy(auStack_24,param_1 + 0x11,0xc);
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    *(undefined *)((int)param_1 + 0x4f) = 0x40;
    for (uVar8 = 1; uVar8 < 100; uVar8 = uVar8 + 1) {
      lma_gen_numname(param_1 + 0x11,auStack_24,*(undefined4 *)(pcVar6 + 0xc),uVar8);
      unaff_r8 = lma_dir_find(param_1);
      if (unaff_r8 != 0) break;
    }
    if (uVar8 == 100) {
      return 7;
    }
    if (unaff_r8 != 4) {
      return unaff_r8;
    }
    *(byte *)((int)param_1 + 0x4f) = local_19;
  }
  if ((int)((uint)local_19 << 0x1e) < 0) {
    iVar7 = lma___aeabi_uidiv(iVar7 + 0xc,0xd);
    iVar7 = iVar7 + 1;
  }
  else {
    iVar7 = 1;
  }
  uVar9 = lma_dir_alloc(param_1,iVar7);
  if ((((int)uVar9 == 0) && (uVar8 = iVar7 - 1, iVar7 != 1)) &&
     (uVar9 = lma_dir_sdi(param_1,param_1[0xc] + uVar8 * -0x20), (int)uVar9 == 0)) {
    uVar10 = lma_sum_sfn(param_1 + 0x11);
    uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
    while (uVar9 = lma_move_window(pcVar6,uVar5,param_1[0xe],param_1[0xf]), (int)uVar9 == 0) {
      lma_put_lfn(*(undefined4 *)(pcVar6 + 0xc),param_1[0x10],uVar8 & 0xff,(int)uVar10);
      pcVar6[3] = '\x01';
      uVar9 = lma_dir_next(param_1,0);
      uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
      if (((int)uVar9 != 0) || (uVar8 = uVar8 - 1, uVar8 == 0)) break;
    }
  }
  iVar7 = (int)uVar9;
  if ((iVar7 == 0) &&
     (iVar7 = lma_move_window(pcVar6,(int)((ulonglong)uVar9 >> 0x20),param_1[0xe],param_1[0xf]),
     iVar7 == 0)) {
    lma_memset(param_1[0x10],0,0x20);
    lma_memcpy(param_1[0x10],param_1 + 0x11,0xb);
    param_1[0x10][0xc] = *(byte *)((int)param_1 + 0x4f) & 0x18;
    pcVar6[3] = '\x01';
  }
  return iVar7;
}


/* ===== lma_remove_chain @ 10002dc8 (396 bytes) ===== */

int lma_remove_chain(char **param_1,uint param_2,char *param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 local_30;
  int local_28;
  int local_24;
  
  pcVar3 = *param_1;
  if (param_2 < 2) {
    iVar5 = 2;
  }
  else if (param_2 < *(uint *)(pcVar3 + 0x2c)) {
    uVar6 = param_2;
    local_30 = CONCAT44(local_30._4_4_,(undefined4)local_30);
    if ((param_3 != (char *)0x0) &&
       ((*pcVar3 != '\x04' ||
        (local_30 = CONCAT44(local_30._4_4_,(undefined4)local_30),
        *(char *)((int)param_1 + 7) != '\x02')))) {
      iVar5 = lma_put_fat(pcVar3,param_3,0xffffffff);
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    do {
      uVar1 = lma_get_fat(param_1,param_2);
      if (uVar1 == 0) break;
      if (uVar1 == 1) {
        return 2;
      }
      if (uVar1 == 0xffffffff) {
        return 1;
      }
      if (*pcVar3 != '\x04') {
        iVar5 = lma_put_fat(pcVar3,param_2,0);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      if (*(uint *)(pcVar3 + 0x18) < *(int *)(pcVar3 + 0x2c) - 2U) {
        *(uint *)(pcVar3 + 0x18) = *(uint *)(pcVar3 + 0x18) + 1;
        pcVar3[4] = pcVar3[4] | 1;
      }
      if (param_2 + 1 != uVar1) {
        if (*pcVar3 == '\x04') {
          iVar5 = lma_change_bitmap(pcVar3,uVar6,(param_2 - uVar6) + 1,0);
          if (iVar5 != 0) {
            return iVar5;
          }
        }
        uVar7 = lma_clst2sect(pcVar3,uVar6);
        local_30 = uVar7;
        uVar7 = lma_clst2sect(pcVar3,param_2);
        iVar5 = (uint)*(ushort *)(pcVar3 + 10) + (uint)uVar7;
        local_28 = iVar5 + -1;
        local_24 = (int)((ulonglong)uVar7 >> 0x20) +
                   (uint)CARRY4((uint)*(ushort *)(pcVar3 + 10),(uint)uVar7) + -1 +
                   (uint)(iVar5 != 0);
        lma_disk_ioctl(pcVar3[1],4,&local_30);
        uVar6 = uVar1;
      }
      param_2 = uVar1;
    } while (uVar1 < *(uint *)(pcVar3 + 0x2c));
    if (*pcVar3 == '\x04') {
      if (param_3 == (char *)0x0) {
        *(undefined *)((int)param_1 + 7) = 0;
        iVar5 = 0;
      }
      else if (*(char *)((int)param_1 + 7) == '\0') {
        pcVar3 = param_1[2];
        do {
          pcVar4 = pcVar3;
          if (pcVar4 == param_3) break;
          pcVar2 = (char *)lma_get_fat(param_1,pcVar4);
          if (pcVar2 < (char *)0x2) {
            return 2;
          }
          if (pcVar2 == (char *)0xffffffff) {
            return 1;
          }
          pcVar3 = pcVar4 + 1;
        } while (pcVar4 + 1 == pcVar2);
        iVar5 = 0;
        if (pcVar4 == param_3) {
          *(undefined *)((int)param_1 + 7) = 2;
        }
      }
      else if (*(char *)((int)param_1 + 7) == '\x03') {
        if (param_3 < param_1[2]) {
          iVar5 = 0;
        }
        else if (param_1[2] + (int)param_1[6] < param_3) {
          iVar5 = 0;
        }
        else {
          *(undefined *)((int)param_1 + 7) = 2;
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 2;
  }
  return iVar5;
}


/* ===== lma_sync_fs @ 10002f54 (152 bytes) ===== */

int lma_sync_fs(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar1 = lma_sync_window();
  if (iVar1 == 0) {
    if ((*param_1 == '\x03') && (param_1[4] == '\x01')) {
      pcVar4 = param_1 + 0x68;
      lma_memset(pcVar4,0,0x200);
      lma_st_word(param_1 + DAT_10002ff0,DAT_10002fec);
      lma_st_dword(pcVar4,DAT_10002ff4);
      lma_st_dword(param_1 + 0x24c,DAT_10002ff8);
      lma_st_dword(param_1 + 0x250,*(undefined4 *)(param_1 + 0x18));
      lma_st_dword(param_1 + 0x254,*(undefined4 *)(param_1 + 0x14));
      iVar2 = *(uint *)(param_1 + 0x38) + 1;
      iVar3 = *(int *)(param_1 + 0x3c) + (uint)(0xfffffffe < *(uint *)(param_1 + 0x38));
      *(int *)(param_1 + 0x60) = iVar2;
      *(int *)(param_1 + 100) = iVar3;
      lma_disk_write(param_1[1],pcVar4,iVar2,iVar3,1);
      param_1[4] = '\0';
    }
    iVar2 = lma_disk_ioctl(param_1[1],0,0);
    if (iVar2 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}


/* ===== lma_f_mount @ 10002ffc (80 bytes) ===== */

undefined4 lma_f_mount(undefined *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_18;
  undefined *local_14 [2];
  undefined4 local_c;
  
  local_18 = param_2;
  local_14[0] = param_1;
  local_c = param_2;
  iVar1 = lma_get_ldnumber(&local_c);
  if (iVar1 < 0) {
    uVar2 = 0xb;
  }
  else {
    puVar3 = *(undefined **)(iVar1 * 4 + DAT_1000304c);
    if (puVar3 != (undefined *)0x0) {
      *puVar3 = 0;
    }
    if (local_14[0] != (undefined *)0x0) {
      *local_14[0] = 0;
    }
    *(undefined **)(iVar1 * 4 + DAT_1000304c) = local_14[0];
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = lma_mount_volume(&local_18,local_14,0);
    }
  }
  return uVar2;
}


/* ===== lma_f_open @ 10003050 (754 bytes) ===== */

int lma_f_open(char **param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined4 local_84 [2];
  char *local_7c;
  char *local_78;
  byte local_72;
  byte local_71;
  char *local_70;
  uint local_68;
  char *local_38;
  char cStack_29;
  char *local_28;
  
  if (param_1 == (char **)0x0) {
    return 9;
  }
  uVar8 = param_3 & 0x3f;
  local_84[0] = param_2;
  iVar2 = lma_mount_volume(local_84,&local_7c,uVar8);
  if (iVar2 == 0) {
    local_78 = local_7c;
    iVar2 = lma_follow_path(&local_78,local_84[0]);
    if ((iVar2 == 0) && (cStack_29 < '\0')) {
      iVar2 = 6;
    }
    if ((param_3 & 0x1c) == 0) {
      if (iVar2 != 0) goto LAB_100031f0;
      if ((int)((uint)local_72 << 0x1b) < 0) {
        iVar2 = 4;
      }
      else {
        if ((-1 < (int)(param_3 << 0x1e)) || (-1 < (int)((uint)local_72 << 0x1f)))
        goto LAB_100031f0;
        iVar2 = 7;
      }
    }
    else {
      if (iVar2 == 0) {
        if ((local_72 & 0x11) == 0) {
          if (-1 < (int)(param_3 << 0x1d)) goto LAB_100030bc;
          iVar2 = 8;
        }
        else {
          iVar2 = 7;
        }
      }
      else {
        if (iVar2 == 4) {
          iVar2 = lma_dir_register(&local_78);
        }
        uVar8 = uVar8 | 8;
LAB_100030bc:
        uVar5 = DAT_10003344;
        if ((iVar2 == 0) && ((int)(uVar8 << 0x1c) < 0)) {
          if (*local_7c == '\x04') {
            *param_1 = local_7c;
            lma_init_alloc_info(local_7c,param_1);
            lma_memset(*(int *)(local_7c + 0x10) + 2,0,0x1e);
            pcVar3 = local_7c;
            lma_memset(*(int *)(local_7c + 0x10) + 0x26,0,0x1a);
            *(undefined *)(*(int *)(pcVar3 + 0x10) + 4) = 0x20;
            lma_st_dword(*(int *)(pcVar3 + 0x10) + 8,DAT_10003344);
            *(undefined *)(*(int *)(local_7c + 0x10) + 0x21) = 1;
            iVar2 = lma_store_xdir(&local_78);
            if ((iVar2 == 0) && (param_1[2] != (char *)0x0)) {
              iVar2 = lma_remove_chain(param_1,param_1[2],0);
              *(char **)(local_7c + 0x14) = param_1[2] + -1;
            }
          }
          else {
            lma_st_dword(local_38 + 0xe,DAT_10003344);
            lma_st_dword(local_38 + 0x16,uVar5);
            pcVar9 = local_38;
            pcVar3 = local_7c;
            iVar4 = lma_ld_clust(local_7c,local_38);
            pcVar9[0xb] = ' ';
            lma_st_clust(pcVar3,local_38,0);
            lma_st_dword(local_38 + 0x1c,0);
            local_7c[3] = '\x01';
            if (iVar4 != 0) {
              uVar5 = *(undefined4 *)(local_7c + 0x60);
              uVar6 = *(undefined4 *)(local_7c + 100);
              uVar11 = lma_remove_chain(&local_78,iVar4,0);
              iVar2 = (int)uVar11;
              if (iVar2 == 0) {
                iVar2 = lma_move_window(local_7c,(int)((ulonglong)uVar11 >> 0x20),uVar5,uVar6);
                *(int *)(local_7c + 0x14) = iVar4 + -1;
              }
            }
          }
        }
      }
LAB_100031f0:
      if (iVar2 == 0) {
        if ((int)(uVar8 << 0x1c) < 0) {
          uVar8 = uVar8 | 0x40;
        }
        pcVar3 = *(char **)(local_7c + 100);
        param_1[0x14] = *(char **)(local_7c + 0x60);
        param_1[0x15] = pcVar3;
        param_1[0x16] = local_38;
      }
    }
    if (iVar2 == 0) {
      if (*local_7c == '\x04') {
        param_1[8] = local_70;
        param_1[9] = (char *)(local_68 & 0xffffff00 | (uint)local_71);
        param_1[10] = local_28;
        lma_init_alloc_info(local_7c,param_1);
      }
      else {
        pcVar3 = (char *)lma_ld_clust(local_7c,local_38);
        param_1[2] = pcVar3;
        pcVar3 = (char *)lma_ld_dword(local_38 + 0x1c);
        param_1[4] = pcVar3;
        param_1[5] = (char *)0x0;
      }
      pcVar3 = local_7c;
      *param_1 = local_7c;
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_7c + 6);
      *(char *)(param_1 + 0xc) = (char)uVar8;
      *(undefined *)((int)param_1 + 0x31) = 0;
      param_1[0x12] = (char *)0x0;
      param_1[0x13] = (char *)0x0;
      param_1[0xe] = (char *)0x0;
      param_1[0xf] = (char *)0x0;
      lma_memset(param_1 + 0x17,0,0x200);
      if ((int)(uVar8 << 0x1a) < 0) {
        pcVar9 = param_1[4];
        pcVar10 = param_1[5];
        if (((uint)pcVar9 | (uint)pcVar10) != 0) {
          param_1[0xe] = pcVar9;
          param_1[0xf] = pcVar10;
          uVar1 = *(ushort *)(pcVar3 + 10);
          pcVar7 = (char *)((uint)uVar1 * 0x200);
          pcVar3 = param_1[2];
          for (; (iVar2 == 0 && ((pcVar10 != (char *)0x0 || (pcVar7 < pcVar9))));
              pcVar9 = pcVar9 + (uint)uVar1 * -0x200) {
            pcVar3 = (char *)lma_get_fat(param_1);
            if (pcVar3 < (char *)0x2) {
              iVar2 = 2;
            }
            if (pcVar3 == (char *)0xffffffff) {
              iVar2 = 1;
            }
            pcVar10 = pcVar10 + -(uint)(pcVar9 < pcVar7);
          }
          param_1[0x10] = pcVar3;
          if ((iVar2 == 0) && (((uint)pcVar9 & 0x1ff) != 0)) {
            lVar12 = lma_clst2sect(local_7c);
            if (lVar12 == 0) {
              iVar2 = 2;
              goto LAB_1000307c;
            }
            lVar12 = lVar12 + (ulonglong)((int)pcVar10 << 0x17 | (uint)pcVar9 >> 9);
            *(longlong *)(param_1 + 0x12) = lVar12;
            iVar4 = lma_disk_read(local_7c[1],param_1 + 0x17,(int)lVar12,
                                  (int)((ulonglong)lVar12 >> 0x20),1);
            if (iVar4 != 0) {
              iVar2 = 1;
              goto LAB_1000307c;
            }
          }
        }
      }
    }
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_1000307c:
  *param_1 = (char *)0x0;
  return iVar2;
}


/* ===== lma_f_read @ 10003348 (574 bytes) ===== */

uint lma_f_read(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  uint local_44;
  int local_2c [2];
  
  *param_4 = 0;
  local_44 = lma_validate(param_1,local_2c);
  if ((local_44 == 0) && (local_44 = (uint)*(byte *)(param_1 + 0x31), local_44 == 0)) {
    if ((int)((uint)*(byte *)(param_1 + 0x30) << 0x1f) < 0) {
      uVar4 = *(uint *)(param_1 + 0x10) - *(uint *)(param_1 + 0x38);
      uVar7 = param_3;
      if ((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x3c) ==
           (uint)(*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 0x38))) &&
         (uVar7 = uVar4, param_3 <= uVar4)) {
        uVar7 = param_3;
      }
      for (; uVar7 != 0; uVar7 = uVar7 - uVar4) {
        uVar4 = *(uint *)(param_1 + 0x38);
        if ((uVar4 & 0x1ff) == 0) {
          uVar5 = uVar4 >> 9 | *(uint *)(param_1 + 0x3c) << 0x17;
          uVar2 = *(ushort *)(local_2c[0] + 10) - 1;
          uVar6 = uVar2 & uVar5;
          if ((uVar2 & uVar5) == 0) {
            if ((uVar4 | *(uint *)(param_1 + 0x3c)) == 0) {
              uVar4 = *(uint *)(param_1 + 8);
            }
            else {
              uVar4 = lma_get_fat(param_1,*(undefined4 *)(param_1 + 0x40));
            }
            if (uVar4 < 2) {
              *(undefined *)(param_1 + 0x31) = 2;
              return 2;
            }
            if (uVar4 == 0xffffffff) {
              *(undefined *)(param_1 + 0x31) = 1;
              return 1;
            }
            *(uint *)(param_1 + 0x40) = uVar4;
          }
          iVar1 = local_2c[0];
          lVar8 = lma_clst2sect(local_2c[0],*(undefined4 *)(param_1 + 0x40));
          if (lVar8 == 0) {
            *(undefined *)(param_1 + 0x31) = 2;
            return 2;
          }
          lVar8 = lVar8 + (ulonglong)uVar6;
          uVar2 = (uint)lVar8;
          iVar3 = (int)((ulonglong)lVar8 >> 0x20);
          uVar4 = uVar7 >> 9;
          if (uVar7 < 0x200) {
            if (lVar8 != *(longlong *)(param_1 + 0x48)) {
              if (*(char *)(param_1 + 0x30) < '\0') {
                iVar1 = lma_disk_write(*(undefined *)(iVar1 + 1),param_1 + 0x5c,
                                       *(undefined4 *)(longlong *)(param_1 + 0x48),
                                       *(undefined4 *)(param_1 + 0x4c),1);
                if (iVar1 != 0) {
                  *(undefined *)(param_1 + 0x31) = 1;
                  return 1;
                }
                *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) & 0x7f;
              }
              iVar1 = lma_disk_read(*(undefined *)(local_2c[0] + 1),param_1 + 0x5c,uVar2,iVar3,1);
              if (iVar1 != 0) {
                *(undefined *)(param_1 + 0x31) = 1;
                return 1;
              }
            }
            *(longlong *)(param_1 + 0x48) = lVar8;
            goto LAB_10003440;
          }
          if ((uint)*(ushort *)(iVar1 + 10) < uVar6 + uVar4) {
            uVar4 = *(ushort *)(iVar1 + 10) - uVar6;
          }
          iVar1 = lma_disk_read(*(undefined *)(iVar1 + 1),param_2,uVar2,iVar3,uVar4);
          if (iVar1 != 0) {
            *(undefined *)(param_1 + 0x31) = 1;
            return 1;
          }
          if (((*(char *)(param_1 + 0x30) < '\0') &&
              (uVar5 = *(uint *)(param_1 + 0x48) - uVar2,
              *(int *)(param_1 + 0x4c) - iVar3 == (uint)(*(uint *)(param_1 + 0x48) < uVar2))) &&
             (uVar5 < uVar4)) {
            lma_memcpy(param_2 + uVar5 * 0x200,param_1 + 0x5c,0x200);
          }
          uVar4 = uVar4 << 9;
        }
        else {
LAB_10003440:
          uVar2 = *(uint *)(param_1 + 0x38) & 0x1ff;
          uVar4 = 0x200 - uVar2;
          if (uVar7 < uVar4) {
            uVar4 = uVar7;
          }
          lma_memcpy(param_2,param_1 + 0x5c + uVar2,uVar4);
        }
        *param_4 = *param_4 + uVar4;
        param_2 = param_2 + uVar4;
        uVar2 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x38) = uVar2 + uVar4;
        *(uint *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + (uint)CARRY4(uVar2,uVar4);
      }
    }
    else {
      local_44 = 7;
    }
  }
  return local_44;
}


/* ===== lma_f_sync @ 10003588 (328 bytes) ===== */

int lma_f_sync(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined8 uVar3;
  undefined auStack_70 [92];
  char *local_14 [2];
  
  uVar3 = lma_validate(param_1,local_14);
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  iVar1 = (int)uVar3;
  if ((iVar1 == 0) && ((int)((uint)*(byte *)(param_1 + 0xc) << 0x19) < 0)) {
    if ((char)*(byte *)(param_1 + 0xc) < '\0') {
      iVar1 = lma_disk_write(local_14[0][1],param_1 + 0x17,param_1[0x12],param_1[0x13],1);
      if (iVar1 != 0) {
        return 1;
      }
      uVar2 = (uint)*(byte *)(param_1 + 0xc);
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0x7f;
    }
    if (*local_14[0] == '\x04') {
      iVar1 = lma_fill_first_frag(param_1);
      if (iVar1 == 0) {
        iVar1 = lma_fill_last_frag(param_1,param_1[0x10],0xffffffff);
      }
      if ((iVar1 == 0) && (iVar1 = lma_load_obj_xdir(auStack_70,param_1), iVar1 == 0)) {
        *(byte *)(*(int *)(local_14[0] + 0x10) + 4) =
             *(byte *)(*(int *)(local_14[0] + 0x10) + 4) | 0x20;
        *(byte *)(*(int *)(local_14[0] + 0x10) + 0x21) = *(byte *)((int)param_1 + 7) | 1;
        lma_st_dword(*(int *)(local_14[0] + 0x10) + 0x34,param_1[2]);
        lma_st_qword(*(int *)(local_14[0] + 0x10) + 0x38,extraout_r1,param_1[4],param_1[5]);
        lma_st_qword(*(int *)(local_14[0] + 0x10) + 0x28,extraout_r1_00,param_1[4],param_1[5]);
        lma_st_dword(*(int *)(local_14[0] + 0x10) + 0xc,DAT_100036d0);
        *(undefined *)(*(int *)(local_14[0] + 0x10) + 0x15) = 0;
        lma_st_dword(*(int *)(local_14[0] + 0x10) + 0x10,0);
        iVar1 = lma_store_xdir(auStack_70);
        if (iVar1 == 0) {
          iVar1 = lma_sync_fs(local_14[0]);
          *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xbf;
        }
      }
    }
    else {
      iVar1 = lma_move_window(local_14[0],uVar2,param_1[0x14],param_1[0x15]);
      if (iVar1 == 0) {
        iVar1 = param_1[0x16];
        *(byte *)(iVar1 + 0xb) = *(byte *)(iVar1 + 0xb) | 0x20;
        lma_st_clust(*param_1,iVar1,param_1[2]);
        lma_st_dword(iVar1 + 0x1c,param_1[4]);
        lma_st_dword(iVar1 + 0x16,DAT_100036d0);
        lma_st_word(iVar1 + 0x12,0);
        local_14[0][3] = '\x01';
        iVar1 = lma_sync_fs(local_14[0]);
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xbf;
      }
    }
  }
  return iVar1;
}


/* ===== lma_f_close @ 100036d4 (36 bytes) ===== */

void lma_f_close(undefined4 *param_1)

{
  int iVar1;
  undefined auStack_c [4];
  
  iVar1 = lma_f_sync();
  if ((iVar1 == 0) && (iVar1 = lma_validate(param_1,auStack_c), iVar1 == 0)) {
    *param_1 = 0;
  }
  return;
}


/* ===== lma_f_chdrive @ 100036f8 (30 bytes) ===== */

undefined4 lma_f_chdrive(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c [3];
  
  local_c[0] = param_1;
  iVar1 = lma_get_ldnumber(local_c);
  if (iVar1 < 0) {
    uVar2 = 0xb;
  }
  else {
    *DAT_10003718 = (char)iVar1;
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== lma_f_chdir @ 1000371c (190 bytes) ===== */

int lma_f_chdir(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_74 [2];
  char *local_6c;
  char *local_68;
  byte local_62;
  byte local_61;
  undefined4 local_60;
  uint local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_28;
  char cStack_19;
  undefined4 local_18;
  
  local_74[0] = param_1;
  iVar2 = lma_mount_volume(local_74,&local_6c,0);
  if (iVar2 != 0) {
    return iVar2;
  }
  local_68 = local_6c;
  iVar2 = lma_follow_path(&local_68,local_74[0]);
  pcVar1 = local_6c;
  if (iVar2 == 0) {
    if (cStack_19 < '\0') {
      *(undefined4 *)(local_6c + 0x1c) = local_60;
      if (*local_6c == '\x04') {
        *(undefined4 *)(local_6c + 0x20) = local_48;
        *(undefined4 *)(local_6c + 0x24) = local_44;
        *(undefined4 *)(local_6c + 0x28) = local_40;
      }
    }
    else {
      if (-1 < (int)((uint)local_62 << 0x1b)) {
        iVar2 = 5;
        goto LAB_1000377c;
      }
      if (*local_6c == '\x04') {
        uVar3 = lma_ld_dword(*(int *)(local_6c + 0x10) + 0x34);
        *(undefined4 *)(pcVar1 + 0x1c) = uVar3;
        *(undefined4 *)(pcVar1 + 0x20) = local_60;
        *(uint *)(pcVar1 + 0x24) = local_58 & 0xffffff00 | (uint)local_61;
        *(undefined4 *)(pcVar1 + 0x28) = local_18;
      }
      else {
        uVar3 = lma_ld_clust(local_6c,local_28);
        *(undefined4 *)(pcVar1 + 0x1c) = uVar3;
      }
    }
  }
  if (iVar2 == 4) {
    return 5;
  }
LAB_1000377c:
  if (iVar2 == 0) {
    for (iVar4 = 1; (iVar4 != 0 && (*(char **)(iVar4 * 4 + DAT_100037dc) != local_6c));
        iVar4 = iVar4 + -1) {
    }
    *DAT_100037e0 = (char)iVar4;
  }
  return iVar2;
}


/* ===== lma_f_lseek @ 100037e4 (780 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x10003a96) */
/* WARNING: Removing unreachable block (ram,0x100038bc) */

uint lma_f_lseek(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint local_48;
  uint local_44;
  char *local_24;
  
  uVar1 = lma_validate(param_1,&local_24);
  if (uVar1 == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x31);
  }
  if ((uVar1 == 0) && (*local_24 == '\x04')) {
    uVar1 = lma_fill_last_frag(param_1,*(undefined4 *)(param_1 + 0x40),0xffffffff);
  }
  if (uVar1 != 0) {
    return uVar1;
  }
  local_48 = param_3;
  local_44 = param_4;
  if ((*local_24 != '\x04') && (param_4 != 0)) {
    local_48 = 0xffffffff;
    local_44 = 0;
  }
  uVar1 = *(uint *)(param_1 + 0x14);
  if (((uVar1 < local_44) || ((local_44 == uVar1 && (*(uint *)(param_1 + 0x10) < local_48)))) &&
     (-1 < (int)((uint)*(byte *)(param_1 + 0x30) << 0x1e))) {
    local_48 = *(uint *)(param_1 + 0x10);
    local_44 = uVar1;
  }
  uVar7 = CONCAT44(local_44,local_48);
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar2 = *(uint *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if ((local_48 | local_44) == 0) goto LAB_1000390a;
  uVar5 = (uint)*(ushort *)(local_24 + 10);
  uVar4 = uVar5 * 0x200;
  if ((uVar1 | uVar2) == 0) {
LAB_100038f4:
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 0) {
      iVar3 = lma_create_chain(param_1);
      if (iVar3 == 1) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      if (iVar3 == -1) {
        *(undefined *)(param_1 + 0x31) = 1;
        return 1;
      }
      *(int *)(param_1 + 8) = iVar3;
    }
    *(int *)(param_1 + 0x40) = iVar3;
  }
  else {
    uVar7 = lma___aeabi_uldivmod(local_48 - 1,(local_44 - 1) + (uint)(local_48 != 0),uVar4,0);
    iVar3 = (uVar2 - 1) + (uint)(uVar1 != 0);
    uVar8 = lma___aeabi_uldivmod(uVar1 - 1,iVar3,uVar4,0);
    if (uVar7 < uVar8) goto LAB_100038f4;
    uVar1 = uVar1 - 1 & uVar5 * -0x200;
    *(uint *)(param_1 + 0x38) = uVar1;
    *(int *)(param_1 + 0x3c) = iVar3;
    bVar6 = local_48 < uVar1;
    local_48 = local_48 - uVar1;
    local_44 = (local_44 - iVar3) - (uint)bVar6;
    iVar3 = *(int *)(param_1 + 0x40);
  }
  if (iVar3 == 0) {
    uVar7 = 0;
  }
  else {
    while ((local_44 != 0 || (uVar4 < local_48))) {
      bVar6 = local_48 < uVar4;
      local_48 = local_48 + uVar5 * -0x200;
      local_44 = local_44 - bVar6;
      uVar1 = *(uint *)(param_1 + 0x38) + uVar4;
      uVar2 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),uVar4);
      *(uint *)(param_1 + 0x38) = uVar1;
      *(uint *)(param_1 + 0x3c) = uVar2;
      if ((int)((uint)*(byte *)(param_1 + 0x30) << 0x1e) < 0) {
        if ((*(uint *)(param_1 + 0x14) < uVar2) ||
           ((uVar2 == *(uint *)(param_1 + 0x14) && (*(uint *)(param_1 + 0x10) < uVar1)))) {
          *(uint *)(param_1 + 0x10) = uVar1;
          *(uint *)(param_1 + 0x14) = uVar2;
          *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 0x40;
        }
        uVar1 = lma_create_chain(param_1);
        if (uVar1 == 0) {
          local_48 = 0;
          local_44 = 0;
          break;
        }
      }
      else {
        uVar1 = lma_get_fat(param_1);
      }
      if (uVar1 == 0xffffffff) {
        *(undefined *)(param_1 + 0x31) = 1;
        return 1;
      }
      if ((uVar1 < 2) || (*(uint *)(local_24 + 0x2c) <= uVar1)) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      *(uint *)(param_1 + 0x40) = uVar1;
    }
    uVar1 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x38) = uVar1 + local_48;
    *(uint *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + local_44 + (uint)CARRY4(uVar1,local_48);
    if ((local_48 & 0x1ff) == 0) {
      uVar7 = (ulonglong)(local_48 & 0x1ff);
    }
    else {
      lVar9 = lma_clst2sect(local_24);
      if (lVar9 == 0) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      uVar7 = lVar9 + (ulonglong)(local_44 << 0x17 | local_48 >> 9);
    }
  }
LAB_1000390a:
  local_44 = (uint)(uVar7 >> 0x20);
  local_48 = (uint)uVar7;
  uVar2 = *(uint *)(param_1 + 0x38);
  uVar1 = *(uint *)(param_1 + 0x3c);
  if ((*(uint *)(param_1 + 0x14) < uVar1) ||
     ((uVar1 == *(uint *)(param_1 + 0x14) && (*(uint *)(param_1 + 0x10) < uVar2)))) {
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint *)(param_1 + 0x14) = uVar1;
    *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 0x40;
  }
  uVar1 = 0;
  if ((uVar2 & 0x1ff) != 0) {
    if (uVar7 != *(ulonglong *)(param_1 + 0x48)) {
      if (*(char *)(param_1 + 0x30) < '\0') {
        iVar3 = lma_disk_write(local_24[1],param_1 + 0x5c,
                               *(undefined4 *)(ulonglong *)(param_1 + 0x48),
                               *(undefined4 *)(param_1 + 0x4c),1);
        if (iVar3 != 0) {
          *(undefined *)(param_1 + 0x31) = 1;
          return 1;
        }
        *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) & 0x7f;
      }
      iVar3 = lma_disk_read(local_24[1],param_1 + 0x5c,local_48,local_44,1);
      if (iVar3 == 0) {
        *(ulonglong *)(param_1 + 0x48) = uVar7;
      }
      else {
        *(undefined *)(param_1 + 0x31) = 1;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* ===== lma_f_opendir @ 10003af0 (142 bytes) ===== */

int lma_f_opendir(char **param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_14 [2];
  char *local_c;
  
  if (param_1 == (char **)0x0) {
    return 9;
  }
  local_14[0] = param_2;
  iVar1 = lma_mount_volume(local_14,&local_c,0);
  if (iVar1 == 0) {
    *param_1 = local_c;
    iVar1 = lma_follow_path(param_1,local_14[0]);
    if (iVar1 == 0) {
      if (-1 < *(char *)((int)param_1 + 0x4f)) {
        if (-1 < (int)((uint)*(byte *)((int)param_1 + 6) << 0x1b)) {
          iVar1 = 5;
          goto LAB_10003b50;
        }
        if (*local_c == '\x04') {
          param_1[8] = param_1[2];
          param_1[9] = (char *)((uint)param_1[4] & 0xffffff00 | (uint)*(byte *)((int)param_1 + 7));
          param_1[10] = param_1[0x14];
          lma_init_alloc_info(local_c,param_1);
        }
        else {
          pcVar2 = (char *)lma_ld_clust(local_c,param_1[0x10]);
          param_1[2] = pcVar2;
        }
      }
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_c + 6);
      iVar1 = lma_dir_sdi(param_1,0);
    }
LAB_10003b50:
    if (iVar1 == 4) {
      iVar1 = 5;
      goto LAB_10003b0c;
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_10003b0c:
  *param_1 = (char *)0x0;
  return iVar1;
}


/* ===== lma_ff_uni2oem @ 10003b80 (64 bytes) ===== */

uint lma_ff_uni2oem(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 < 0x80) {
    param_1 = param_1 & 0xffff;
  }
  else if (param_1 < 0x10000) {
    if (param_2 == 0x1b5) {
      uVar1 = 0;
      while ((uVar1 < 0x80 && (*(ushort *)(DAT_10003bc0 + uVar1 * 2) != param_1))) {
        uVar1 = uVar1 + 1 & 0xffff;
      }
      param_1 = uVar1 + 0x80 & 0xff;
    }
    else {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}


/* ===== lma_ff_wtoupper @ 10003bc4 (86 bytes) ===== */

uint lma_ff_wtoupper(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  uVar6 = param_1;
  if (param_1 < 0x10000) {
    uVar6 = param_1 & 0xffff;
    puVar2 = DAT_10003c60;
    if (uVar6 < 0x1000) {
      puVar2 = DAT_10003c5c;
    }
    while( true ) {
      uVar1 = (uint)*puVar2;
      if (uVar1 == 0) {
        return uVar6;
      }
      if (uVar6 < uVar1) {
        return uVar6;
      }
      puVar5 = puVar2 + 2;
      uVar4 = (uint)(puVar2[1] >> 8);
      uVar3 = puVar2[1] & 0xff;
      if ((param_1 & 0xffff) < uVar3 + uVar1) break;
      puVar2 = puVar5;
      if (uVar4 == 0) {
        puVar2 = puVar5 + uVar3;
      }
    }
    if (uVar4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x10003c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (**(code **)(DAT_10003c64 + uVar4 * 4))();
      return uVar6;
    }
  }
  return uVar6;
}


/* ===== lma_disk_initialize @ 10003c6c (26 bytes) ===== */

undefined4 lma_disk_initialize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = lma_mmc_disk_initialize();
  }
  else if (param_1 == 1) {
    uVar1 = lma_usb_disk_initialize();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ===== lma_disk_status @ 10003c86 (26 bytes) ===== */

undefined4 lma_disk_status(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = lma_mmc_disk_status();
  }
  else if (param_1 == 1) {
    uVar1 = lma_usb_disk_status();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ===== lma_disk_read @ 10003ca0 (42 bytes) ===== */

undefined4 lma_disk_read(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = lma_mmc_disk_read(param_2);
  }
  else if (param_1 == 1) {
    uVar1 = lma_usb_disk_read();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== lma_disk_write @ 10003cca (42 bytes) ===== */

undefined4 lma_disk_write(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = lma_mmc_disk_write(param_2);
  }
  else if (param_1 == 1) {
    uVar1 = lma_usb_disk_write();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== lma_disk_ioctl @ 10003cf4 (32 bytes) ===== */

undefined4 lma_disk_ioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = lma_mmc_disk_ioctl(param_2,param_3);
  }
  else if (param_1 == 1) {
    uVar1 = lma_usb_disk_ioctl();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== lma_mmc_power_on @ 10003d4c (72 bytes) ===== */

void lma_mmc_power_on(void)

{
  undefined8 uVar1;
  
  DAT_d0000024 = 0x1000000;
  DAT_d0000014 = 0x20;
  lma_sd_spi_set_speed(0);
  if (*DAT_10003d94 == 0) {
    uVar1 = lma_alarm_pool_get_default();
    lma_alarm_pool_add_repeating_timer_us
              ((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_10003da0,0xffffffff,DAT_10003d9c,0,
               DAT_10003d98);
  }
  *DAT_10003d94 = 1;
  return;
}


/* ===== lma_xchg_spi @ 10003da4 (26 bytes) ===== */

undefined lma_xchg_spi(undefined param_1)

{
  undefined local_10 [4];
  undefined local_c [12];
  
  local_c[0] = param_1;
  lma_spi_write_read_blocking(DAT_10003dc0,local_c,local_10,1);
  return local_10[0];
}


/* ===== lma_wait_ready @ 10003dc4 (36 bytes) ===== */

bool lma_wait_ready(uint param_1)

{
  int iVar1;
  
  *DAT_10003de8 = param_1;
  do {
    iVar1 = lma_xchg_spi(0xff);
  } while ((*DAT_10003de8 & (uint)(iVar1 != 0xff)) != 0);
  return iVar1 == 0xff;
}


/* ===== lma_deselect @ 10003dec (42 bytes) ===== */

void lma_deselect(void)

{
  lma_busy_wait_us_32(10);
  lma_xchg_spi(0xff);
  lma_busy_wait_us_32(10);
  DAT_d0000014 = 0x20;
  lma_xchg_spi(0xff);
  lma_busy_wait_us_32(10);
  return;
}


/* ===== lma_select @ 10003e16 (40 bytes) ===== */

bool lma_select(void)

{
  int iVar1;
  
  lma_xchg_spi(0xff);
  DAT_d0000018 = 0x20;
  iVar1 = lma_wait_ready(500);
  if (iVar1 == 0) {
    lma_deselect();
  }
  return iVar1 != 0;
}


/* ===== lma_send_cmd @ 10003e3e (160 bytes) ===== */

int lma_send_cmd(uint param_1,uint param_2)

{
  undefined uVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  
  if ((char)param_1 < '\0') {
    param_1 = param_1 & 0x7f;
    iVar3 = lma_send_cmd(0x37,0);
    if (1 < iVar3) {
      return iVar3;
    }
  }
  if (param_1 != 0xc) {
    lma_deselect();
    iVar3 = lma_select();
    if (iVar3 == 0) {
      return -1;
    }
  }
  lma_xchg_spi(param_1 & 0xff | 0x40);
  lma_xchg_spi(param_2 >> 0x18);
  lma_xchg_spi(param_2 >> 0x10 & 0xff);
  lma_xchg_spi(param_2 >> 8 & 0xff);
  lma_xchg_spi(param_2 & 0xff);
  if (param_1 == 0) {
    uVar1 = 0x95;
  }
  else if (param_1 == 8) {
    uVar1 = 0x87;
  }
  else {
    uVar1 = 0xff;
  }
  lma_xchg_spi(uVar1);
  if (param_1 == 0xc) {
    lma_xchg_spi(0xff);
  }
  cVar4 = '\n';
  do {
    bVar2 = lma_xchg_spi(0xff);
    if (-1 < (int)((uint)bVar2 << 0x18)) {
      return (int)(char)bVar2;
    }
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return (int)(char)bVar2;
}


/* ===== lma_rcvr_spi_multi @ 10003ee0 (26 bytes) ===== */

void lma_rcvr_spi_multi(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    lma_spi_read_blocking(DAT_10003efc,0xff,param_1,param_2);
  }
  return;
}


/* ===== lma_rcvr_datablock @ 10003f00 (78 bytes) ===== */

bool lma_rcvr_datablock(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *DAT_10003f50 = 200;
  do {
    iVar1 = lma_xchg_spi(0xff);
    if (iVar1 != 0xff) break;
  } while (*DAT_10003f50 != 0);
  if (iVar1 == 0xfe) {
    lma_rcvr_spi_multi(param_1,param_2);
    lma_xchg_spi(0xff);
    lma_xchg_spi(0xff);
    lma_busy_wait_us_32(10);
  }
  else {
    lma___wrap_printf(DAT_10003f54,iVar1);
  }
  return iVar1 == 0xfe;
}


/* ===== lma_xmit_spi_multi @ 10003f58 (24 bytes) ===== */

void lma_xmit_spi_multi(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    lma_spi_write_blocking(DAT_10003f70,param_1,param_2);
  }
  return;
}


/* ===== lma_xmit_datablock @ 10003f74 (86 bytes) ===== */

int lma_xmit_datablock(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = lma_wait_ready(500);
  if (iVar1 != 0) {
    lma_xchg_spi(param_2);
    if (param_2 == 0xfd) {
      iVar1 = 1;
    }
    else {
      lma_xmit_spi_multi(param_1,0x200);
      lma_xchg_spi(0);
      lma_xchg_spi(0);
      uVar2 = lma_xchg_spi(0xff);
      if ((uVar2 & 0x1f) == 5) {
        iVar1 = 1;
      }
      else {
        lma___wrap_printf(DAT_10003fcc,uVar2);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


/* ===== lma_mmc_disk_initialize @ 10003fd0 (332 bytes) ===== */

uint lma_mmc_disk_initialize(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte local_14 [4];
  
  lma_mmc_power_on();
  uVar5 = *DAT_1000411c & 2;
  if ((*DAT_1000411c & 2) == 0) {
    lma_sd_spi_set_speed(0);
    for (uVar2 = uVar5; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
      lma_xchg_spi(0xff);
    }
    uVar2 = lma_send_cmd(0,0);
    if (uVar2 == 1) {
      *DAT_10004120 = 1000;
      iVar3 = lma_send_cmd(8,0x1aa);
      if (iVar3 == 1) {
        lma___wrap_puts(DAT_10004128);
        for (uVar2 = uVar5; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
          bVar1 = lma_xchg_spi(0xff);
          local_14[uVar2] = bVar1;
        }
        if ((local_14[2] == '\x01') && (local_14[3] == -0x56)) {
          do {
            if (*DAT_10004120 == 0) break;
            iVar3 = lma_send_cmd(0xa9,0x40000000);
          } while (iVar3 != 0);
          if ((*DAT_10004120 != 0) && (iVar3 = lma_send_cmd(0x3a,0), iVar3 == 0)) {
            for (; uVar5 < 4; uVar5 = uVar5 + 1 & 0xff) {
              bVar1 = lma_xchg_spi(0xff);
              local_14[uVar5] = bVar1;
            }
            if ((int)((uint)local_14[0] << 0x19) < 0) {
              uVar5 = 0x18;
            }
            else {
              uVar5 = 8;
            }
          }
        }
      }
      else {
        iVar3 = lma_send_cmd(0xa9,0);
        if (iVar3 < 2) {
          uVar2 = 4;
          uVar4 = 0xa9;
        }
        else {
          uVar2 = 1;
          uVar4 = 1;
        }
        do {
          if (*DAT_10004120 == 0) break;
          iVar3 = lma_send_cmd(uVar4,0);
        } while (iVar3 != 0);
        if ((*DAT_10004120 != 0) && (iVar3 = lma_send_cmd(0x10,0x200), iVar3 == 0)) {
          uVar5 = uVar2;
        }
      }
      *DAT_10004124 = uVar5;
      lma_deselect();
      if (uVar5 == 0) {
        *DAT_1000411c = 1;
      }
      else {
        lma_sd_spi_set_speed(1);
        lma_send_cmd(0x3b,0);
        *DAT_1000411c = *DAT_1000411c & 0xfe;
      }
      uVar2 = (uint)*DAT_1000411c;
    }
  }
  else {
    uVar2 = (uint)*DAT_1000411c;
  }
  return uVar2;
}


/* ===== lma_mmc_disk_status @ 1000412c (8 bytes) ===== */

undefined lma_mmc_disk_status(void)

{
  return *DAT_10004134;
}


/* ===== lma_mmc_disk_read @ 10004138 (144 bytes) ===== */

undefined lma_mmc_disk_read(int param_1,undefined4 param_2,int param_3,undefined4 param_4,
                           int param_5)

{
  char cVar1;
  int iVar2;
  undefined uVar3;
  
  if (param_5 == 0) {
    uVar3 = 4;
  }
  else if ((int)((uint)*DAT_100041c8 << 0x1f) < 0) {
    uVar3 = 3;
  }
  else {
    if (-1 < *DAT_100041cc << 0x1b) {
      param_3 = param_3 << 9;
    }
    if (param_5 == 1) {
      cVar1 = lma_send_cmd(0x11,param_3);
      if (cVar1 == '\0') {
        iVar2 = lma_rcvr_datablock(param_1,0x200);
        if (iVar2 != 0) {
          param_5 = 0;
        }
      }
      else {
        lma___wrap_printf(DAT_100041d0,cVar1);
      }
    }
    else {
      iVar2 = lma_send_cmd(0x12,param_3);
      if (iVar2 == 0) {
        do {
          iVar2 = lma_rcvr_datablock(param_1,0x200);
          if (iVar2 == 0) break;
          param_1 = param_1 + 0x200;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
        lma_send_cmd(0xc,0);
      }
    }
    lma_deselect();
    uVar3 = param_5 != 0;
  }
  return uVar3;
}


/* ===== lma_mmc_disk_write @ 100041d4 (152 bytes) ===== */

undefined lma_mmc_disk_write(int param_1,undefined4 param_2,int param_3,undefined4 param_4,
                            int param_5)

{
  int iVar1;
  undefined uVar2;
  
  if (param_5 == 0) {
    uVar2 = 4;
  }
  else if ((int)((uint)*DAT_1000426c << 0x1f) < 0) {
    uVar2 = 3;
  }
  else {
    if (-1 < (int)(*DAT_10004270 << 0x1b)) {
      param_3 = param_3 << 9;
    }
    if (param_5 == 1) {
      iVar1 = lma_send_cmd(0x18,param_3);
      if ((iVar1 == 0) && (iVar1 = lma_xmit_datablock(param_1,0xfe), iVar1 != 0)) {
        param_5 = 0;
      }
    }
    else {
      if ((*DAT_10004270 & 0xc) != 0) {
        lma_send_cmd(0x97,param_5);
      }
      iVar1 = lma_send_cmd(0x19,param_3);
      if (iVar1 == 0) {
        do {
          iVar1 = lma_xmit_datablock(param_1,0xfc);
          if (iVar1 == 0) break;
          param_1 = param_1 + 0x200;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
        iVar1 = lma_xmit_datablock(0,0xfd);
        if (iVar1 == 0) {
          param_5 = 1;
        }
      }
    }
    lma_deselect();
    uVar2 = param_5 != 0;
  }
  return uVar2;
}


/* ===== lma_mmc_disk_ioctl @ 10004274 (54 bytes) ===== */

undefined4 lma_mmc_disk_ioctl(uint param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_10004524 & 1) == 0) {
    if (param_1 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x10004298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(PTR_PTR_LAB_10004528 + param_1 * 4))();
      return uVar1;
    }
    uVar1 = 4;
    lma_deselect();
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


/* ===== lma_tuh_msc_mount_cb @ 100045f8 (24 bytes) ===== */

void lma_tuh_msc_mount_cb(undefined4 param_1)

{
  lma___wrap_puts(PTR_s_A_MassStorage_device_is_mounted_10004610);
  lma_tuh_msc_inquiry(param_1,0,PTR_DAT_10004618,PTR_msc_inquiry_complete_cb_1_10004614);
  return;
}


/* ===== lma_tuh_msc_umount_cb @ 1000461c (16 bytes) ===== */

void lma_tuh_msc_umount_cb(void)

{
  lma___wrap_puts(DAT_1000462c);
  *DAT_10004630 = 2;
  return;
}


/* ===== lma_usb_msc_service_request @ 10004634 (198 bytes) ===== */

void lma_usb_msc_service_request(uint param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  
  if (param_1 == 3) {
    if (*DAT_100046fc == '\0') {
      iVar2 = lma_tuh_msc_write10(*DAT_10004700,0,param_2 + 0x14,*(undefined4 *)(param_2 + 8),1,
                                  DAT_10004708);
      if (iVar2 == 0) {
        lma_multicore_fifo_push_blocking(1);
      }
    }
    else {
      lma_multicore_fifo_push_blocking(1);
    }
  }
  else if (param_1 < 4) {
    if (param_1 == 1) {
      lma_multicore_fifo_push_blocking(*DAT_100046fc);
    }
    else if (param_1 == 2) {
      if (*DAT_100046fc == '\0') {
        iVar2 = lma_tuh_msc_read10(*DAT_10004700,0,param_2 + 0x14,*(undefined4 *)(param_2 + 8),1,
                                   DAT_10004704);
        if (iVar2 == 0) {
          lma_multicore_fifo_push_blocking(1);
        }
      }
      else {
        lma_multicore_fifo_push_blocking(1);
      }
    }
  }
  else if (param_1 == 4) {
    if (*DAT_100046fc == '\0') {
      if (*(int *)(param_2 + 8) == 1) {
        *(undefined4 *)(param_2 + 0xc) = *DAT_1000470c;
        uVar1 = 0;
      }
      else {
        uVar1 = 4;
        if (*(int *)(param_2 + 8) == 3) {
          *(undefined4 *)(param_2 + 0xc) = *DAT_10004710;
          uVar1 = 0;
        }
      }
      lma_multicore_fifo_push_blocking(uVar1);
    }
    else {
      lma_multicore_fifo_push_blocking(4);
    }
  }
  return;
}


/* ===== lma_usb_disk_set_nodisk @ 10004714 (8 bytes) ===== */

void lma_usb_disk_set_nodisk(void)

{
  *DAT_1000471c = 2;
  return;
}


/* ===== lma_usb_disk_initialize @ 10004720 (24 bytes) ===== */

undefined lma_usb_disk_initialize(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_10004738;
  *DAT_10004738 = 0;
  puVar1[1] = 0;
  lma_multicore_fifo_push_blocking(1);
  uVar2 = lma_multicore_fifo_pop_blocking();
  return uVar2;
}


/* ===== lma_usb_disk_status @ 1000473c (24 bytes) ===== */

undefined lma_usb_disk_status(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_10004754;
  *DAT_10004754 = 0;
  puVar1[1] = 0;
  lma_multicore_fifo_push_blocking(1);
  uVar2 = lma_multicore_fifo_pop_blocking();
  return uVar2;
}


/* ===== lma_usb_disk_read @ 10004758 (98 bytes) ===== */

char lma_usb_disk_read(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    puVar1 = DAT_100047bc;
    if (param_5 <= uVar3) {
      return '\0';
    }
    *DAT_100047bc = 0;
    puVar1[1] = 0;
    puVar1[2] = param_3;
    puVar1[3] = 0x200;
    lma_multicore_fifo_push_blocking(2);
    cVar2 = lma_multicore_fifo_pop_blocking();
    if (cVar2 != '\0') break;
    lma_memcpy(param_1,DAT_100047bc + 5,0x200);
    param_1 = param_1 + 0x200;
    param_3 = param_3 + 1;
    uVar3 = uVar3 + 1;
  }
  return cVar2;
}


/* ===== lma_usb_disk_write @ 100047c0 (92 bytes) ===== */

char lma_usb_disk_write(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    puVar1 = DAT_1000481c;
    if (param_5 <= uVar3) {
      return '\0';
    }
    *DAT_1000481c = 0;
    puVar1[1] = 0;
    puVar1[2] = param_3;
    puVar1[3] = 0x200;
    lma_memcpy(puVar1 + 5,param_1);
    lma_multicore_fifo_push_blocking(3);
    cVar2 = lma_multicore_fifo_pop_blocking();
    if (cVar2 != '\0') break;
    param_1 = param_1 + 0x200;
    param_3 = param_3 + 1;
    uVar3 = uVar3 + 1;
  }
  return cVar2;
}


/* ===== lma_usb_disk_ioctl @ 10004820 (104 bytes) ===== */

uint lma_usb_disk_ioctl(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  uint uVar3;
  
  puVar1 = DAT_10004888;
  *DAT_10004888 = 0;
  puVar1[1] = 0;
  if (param_1 == 1) {
    DAT_10004888[2] = 1;
    lma_multicore_fifo_push_blocking(4);
    bVar2 = lma_multicore_fifo_pop_blocking();
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      *param_2 = DAT_10004888[3];
      param_2[1] = 0;
    }
  }
  else if (param_1 == 3) {
    DAT_10004888[2] = 3;
    lma_multicore_fifo_push_blocking(4);
    bVar2 = lma_multicore_fifo_pop_blocking();
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      *param_2 = DAT_10004888[3];
    }
  }
  else if (param_1 == 0) {
    uVar3 = lma_usb_disk_status();
    if (uVar3 != 0) {
      uVar3 = 4;
    }
  }
  else {
    uVar3 = 4;
  }
  return uVar3;
}


/* ===== lma_flash_cs_force @ 1000488c (18 bytes) ===== */

void lma_flash_cs_force(int param_1)

{
  *DAT_100048a0 = *DAT_100048a0 & DAT_100048a4 | param_1 << 8;
  return;
}


/* ===== lma_connect_internal_flash @ 100048a8 (34 bytes) ===== */

void lma_connect_internal_flash(void)

{
  int iVar1;
  
  lma_reset_unreset_block_wait_noinline(0x240);
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    *(undefined4 *)(iVar1 * 8 + DAT_100048cc) = 0;
  }
  return;
}


/* ===== lma_flash_init_spi @ 100048d0 (30 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_init_spi(void)

{
  _DAT_18000014 = 6;
  _DAT_18000000 = 0x70000;
  _DAT_18000010 = 1;
  _DAT_18000008 = 1;
  return;
}


/* ===== lma_flash_was_aborted @ 100048f0 (12 bytes) ===== */

uint lma_flash_was_aborted(void)

{
  return *DAT_100048fc & 0x30000;
}


/* ===== lma_flash_put_get @ 10004900 (148 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_put_get(byte *param_1,undefined *param_2,uint param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = param_3;
  do {
    if ((param_4 | param_3 | uVar3) == 0) break;
    if (param_3 == 0) {
      bVar2 = false;
    }
    else if ((uint)(_DAT_18000020 + _DAT_18000024) < 0xe) {
      if (param_1 == (byte *)0x0) {
        _DAT_18000060 = 0;
      }
      else {
        _DAT_18000060 = (uint)*param_1;
        param_1 = param_1 + 1;
      }
      param_3 = param_3 - 1;
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (_DAT_18000024 != 0) {
      if (param_4 == 0) {
        if (param_2 != (undefined *)0x0) {
          *param_2 = (char)_DAT_18000060;
          param_2 = param_2 + 1;
        }
        uVar3 = uVar3 - 1;
        bVar2 = true;
      }
      else {
        param_4 = param_4 - 1;
        bVar2 = true;
      }
    }
  } while ((bVar2) || (iVar1 = lma_flash_was_aborted(), iVar1 == 0));
  lma_flash_cs_force(3);
  return;
}


/* ===== lma_flash_do_cmd @ 10004994 (36 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_do_cmd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = param_4;
  lma_flash_cs_force(2);
  _DAT_18000060 = param_1;
  lma_flash_put_get(param_2,param_3,param_4,1,uVar1);
  return;
}


/* ===== lma_flash_enable_write @ 100049b8 (16 bytes) ===== */

void lma_flash_enable_write(void)

{
  lma_flash_do_cmd(6,0,0,0);
  return;
}


/* ===== lma_flash_exit_xip @ 100049c8 (136 bytes) ===== */

void lma_flash_exit_xip(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined local_14;
  undefined local_13;
  
  local_14 = 0xff;
  local_13 = 0xff;
  lma_flash_init_spi();
  uVar4 = *DAT_10004a50;
  uVar3 = uVar4 & 0xffffff73 | 0x84;
  lma_flash_cs_force(3);
  for (iVar5 = 0; puVar1 = DAT_10004a50, iVar5 < 2; iVar5 = iVar5 + 1) {
    *DAT_10004a50 = uVar3;
    puVar1[1] = uVar3;
    puVar1[2] = uVar3;
    puVar1[3] = uVar3;
    iVar2 = 0x800;
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    lma_flash_put_get(0,0,4,0);
    uVar3 = uVar3 & 0xfffffff3 | 8;
    lma_flash_cs_force(2);
  }
  *DAT_10004a50 = uVar4;
  puVar1[1] = uVar4;
  uVar3 = uVar4 & 0xfffffff3 | 8;
  puVar1[2] = uVar3;
  puVar1[3] = uVar3;
  lma_flash_cs_force(2);
  lma_flash_put_get(&local_14,0,2,0);
  *DAT_10004a54 = 0;
  return;
}


/* ===== lma_flash_page_program @ 10004a58 (134 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_page_program(uint param_1,undefined4 param_2)

{
  int iVar1;
  byte local_11;
  
  if (0xffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10004ae8,0x10d,DAT_10004ae4,DAT_10004ae0);
  }
  if ((param_1 & 0xff) == 0) {
    lma_flash_enable_write();
    lma_flash_cs_force(2);
    param_1 = param_1 | 0x2000000;
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      _DAT_18000060 = param_1 >> 0x18;
      param_1 = param_1 << 8;
    }
    lma_flash_put_get(param_2,0,0x100,4);
    do {
      lma_flash_do_cmd(5,0,&local_11,1);
      if (-1 < (int)((uint)local_11 << 0x1f)) {
        return;
      }
      iVar1 = lma_flash_was_aborted();
    } while (iVar1 == 0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10004ae8,0x10e,DAT_10004ae4,DAT_10004aec);
}


/* ===== lma_flash_range_program @ 10004af0 (60 bytes) ===== */

void lma_flash_range_program(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 & 0xff) == 0) {
    uVar2 = param_1 + param_3;
    while ((param_1 < uVar2 && (iVar1 = lma_flash_was_aborted(), iVar1 == 0))) {
      lma_flash_page_program(param_1,param_2);
      param_1 = param_1 + 0x100;
      param_2 = param_2 + 0x100;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10004b34,0x118,DAT_10004b30,DAT_10004b2c);
}


/* ===== lma_flash_user_erase @ 10004b38 (110 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_user_erase(uint param_1,int param_2)

{
  int iVar1;
  byte local_11 [5];
  
  if (0xffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10004bb0,0x13c,DAT_10004bac,DAT_10004ba8);
  }
  lma_flash_enable_write();
  lma_flash_cs_force(2);
  param_1 = param_2 << 0x18 | param_1;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    _DAT_18000060 = param_1 >> 0x18;
    param_1 = param_1 << 8;
  }
  lma_flash_put_get(0,0,0,4);
  do {
    lma_flash_do_cmd(5,0,local_11,1);
    if (-1 < (int)((uint)local_11[0] << 0x1f)) {
      return;
    }
    iVar1 = lma_flash_was_aborted();
  } while (iVar1 == 0);
  return;
}


/* ===== lma_flash_sector_erase @ 10004bb4 (10 bytes) ===== */

void lma_flash_sector_erase(undefined4 param_1)

{
  lma_flash_user_erase(param_1,0x20);
  return;
}


/* ===== lma_flash_read_data @ 10004bc0 (76 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_flash_read_data(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 < 0x1000000) {
    lma_flash_cs_force(2);
    param_1 = param_1 | 0x3000000;
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      _DAT_18000060 = param_1 >> 0x18;
      param_1 = param_1 << 8;
    }
    lma_flash_put_get(0,param_2,param_3,4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10004c14,0x15f,DAT_10004c10,DAT_10004c0c,param_4);
}


/* ===== lma_reset_unreset_block_wait_noinline @ 10004c1e (18 bytes) ===== */

void lma_reset_unreset_block_wait_noinline(uint param_1)

{
  int iVar1;
  
  *DAT_10004c30 = param_1;
  iVar1 = DAT_10004c34;
  *DAT_10004c38 = param_1;
  do {
    param_1 = param_1 & ~*(uint *)(iVar1 + 8);
  } while (param_1 != 0);
  return;
}


/* ===== lma_gpio_set_function @ 10004c3c (40 bytes) ===== */

void lma_gpio_set_function(int param_1,undefined4 param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_10004c64);
  *(uint *)((uint)puVar1 | 0x1000) = (*puVar1 ^ 0x40) & 0xc0;
  *(undefined4 *)(param_1 * 8 + DAT_10004c68 + 4) = param_2;
  return;
}


/* ===== lma_gpio_set_pulls @ 10004c6c (48 bytes) ===== */

void lma_gpio_set_pulls(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_10004c9c);
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 8;
  }
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  *(uint *)((uint)puVar1 | 0x1000) = ((uVar3 | uVar2) ^ *puVar1) & 0xc;
  return;
}


/* ===== lma_gpio_set_drive_strength @ 10004ca0 (28 bytes) ===== */

void lma_gpio_set_drive_strength(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_10004cbc);
  *(uint *)((uint)puVar1 | 0x1000) = (param_2 << 4 ^ *puVar1) & 0x30;
  return;
}


/* ===== lma_gpio_init @ 10004cc0 (22 bytes) ===== */

void lma_gpio_init(uint param_1)

{
  DAT_d0000018 = 1 << (param_1 & 0xff);
  DAT_d0000028 = DAT_d0000018;
  lma_gpio_set_function(param_1,5);
  return;
}


/* ===== lma_hw_claim_lock @ 10004cd8 (20 bytes) ===== */

undefined4 lma_hw_claim_lock(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_10004cec == 0);
  DataMemoryBarrier(0x1f);
  return uVar2;
}


/* ===== lma_hw_claim_unlock @ 10004cf0 (16 bytes) ===== */

void lma_hw_claim_unlock(uint param_1)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1f);
  *DAT_10004d00 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_1 & 1) == 1);
  }
  return;
}


/* ===== lma_hw_claim_or_assert @ 10004d04 (50 bytes) ===== */

void lma_hw_claim_or_assert(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  
  lma_hw_claim_lock();
  bVar1 = *(byte *)(param_1 + (param_2 >> 3));
  uVar2 = 1 << (param_2 & 7);
  if ((uVar2 & bVar1) == 0) {
    *(byte *)(param_1 + (param_2 >> 3)) = (byte)uVar2 | bVar1;
    lma_hw_claim_unlock();
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma_panic(param_3,param_2,param_2 & 7,uVar2,param_4);
}


/* ===== lma_hw_claim_unused_from_range @ 10004d36 (80 bytes) ===== */

uint lma_hw_claim_unused_from_range
               (int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5)

{
  byte bVar1;
  uint uVar2;
  
  lma_hw_claim_lock();
  do {
    if (param_4 < param_3) {
      param_3 = 0xffffffff;
LAB_10004d6c:
      lma_hw_claim_unlock();
      if (((int)param_3 < 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
        lma_panic(param_5);
      }
      return param_3;
    }
    bVar1 = *(byte *)(param_1 + (param_3 >> 3));
    uVar2 = 1 << (param_3 & 7);
    if ((uVar2 & bVar1) == 0) {
      *(byte *)(param_1 + (param_3 >> 3)) = (byte)uVar2 | bVar1;
      goto LAB_10004d6c;
    }
    param_3 = param_3 + 1;
  } while( true );
}


/* ===== lma_running_on_fpga @ 10004d88 (16 bytes) ===== */

bool lma_running_on_fpga(void)

{
  return (*DAT_10004d98 & 2) != 0;
}


/* ===== lma_spin_locks_reset @ 10004d9c (26 bytes) ===== */

void lma_spin_locks_reset(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0x20; uVar1 = uVar1 + 1) {
    DataMemoryBarrier(0x1f);
    *(undefined4 *)((uVar1 + DAT_10004db8) * 4) = 0;
  }
  return;
}


/* ===== lma_next_striped_spin_lock_num @ 10004dbc (22 bytes) ===== */

void lma_next_striped_spin_lock_num(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_10004dd4;
  bVar1 = *DAT_10004dd4;
  *DAT_10004dd4 = bVar1 + 1;
  if (0x17 < (byte)(bVar1 + 1)) {
    *pbVar2 = 0x10;
  }
  return;
}


/* ===== lma_spin_lock_claim_unused @ 10004dd8 (24 bytes) ===== */

void lma_spin_lock_claim_unused(undefined4 param_1)

{
  lma_hw_claim_unused_from_range(DAT_10004df4,param_1,0x18,0x1f,DAT_10004df0);
  return;
}


/* ===== lma_uart_set_baudrate @ 10004df8 (84 bytes) ===== */

void lma_uart_set_baudrate(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = lma_clock_get_hz(6);
  uVar2 = lma___aeabi_uidiv(iVar1 << 3,param_2);
  uVar3 = uVar2 >> 7;
  if (uVar3 == 0) {
    uVar3 = 1;
    uVar2 = 0;
  }
  else if (DAT_10004e4c < uVar3) {
    uVar2 = 0;
    uVar3 = DAT_10004e50;
  }
  else {
    uVar2 = (uVar2 & 0x7f) + 1 >> 1;
  }
  *(uint *)(param_1 + 0x24) = uVar3;
  *(uint *)(param_1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x2cU | 0x2000) = 0;
  iVar1 = lma_clock_get_hz(6);
  lma___aeabi_uidiv(iVar1 << 2,uVar3 * 0x40 + uVar2);
  return;
}


/* ===== lma_uart_set_translate_crlf @ 10004e54 (30 bytes) ===== */

void lma_uart_set_translate_crlf(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = 10;
  }
  *(undefined2 *)((uint)(param_1 + DAT_10004e74 == 0) * 2 + DAT_10004e78) = uVar1;
  return;
}


/* ===== lma_uart_init @ 10004e7c (108 bytes) ===== */

void lma_uart_init(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = lma_clock_get_hz(6);
  if (iVar1 != 0) {
    if (param_1 == DAT_10004ee8) {
      uVar2 = 0x800000;
    }
    else {
      uVar2 = 0x400000;
    }
    *DAT_10004eec = uVar2;
    *DAT_10004ef0 = uVar2;
    do {
    } while ((uVar2 & ~*(uint *)(DAT_10004ef4 + 8)) != 0);
    lma_uart_set_translate_crlf(param_1,0);
    lma_uart_set_baudrate(param_1,param_2);
    *(uint *)(param_1 + 0x2cU | 0x1000) = (*(uint *)(param_1 + 0x2c) ^ 0x60) & 0x6e;
    *(undefined4 *)(param_1 + 0x30) = DAT_10004ef8;
    *(undefined4 *)(param_1 + 0x2cU | 0x2000) = 0x10;
    *(undefined4 *)(param_1 + 0x48) = 3;
  }
  return;
}


/* ===== lma_alarm_pool_post_alloc_init @ 10004f3c (50 bytes) ===== */

void lma_alarm_pool_post_alloc_init(int param_1,int param_2)

{
  int iVar1;
  
  lma_hardware_alarm_claim(param_2);
  lma_hardware_alarm_cancel(param_2);
  lma_hardware_alarm_set_callback(param_2,DAT_10004f70);
  iVar1 = lma_next_striped_spin_lock_num();
  *(int *)(param_1 + 4) = (iVar1 + DAT_10004f74) * 4;
  *(char *)(param_1 + 0x14) = (char)param_2;
  *(int *)(param_2 * 4 + DAT_10004f78) = param_1;
  return;
}


/* ===== lma_ph_add_child_node @ 10005028 (134 bytes) ===== */

void lma_ph_add_child_node(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100050b8,0x69,DAT_100050b4,DAT_100050b0);
  }
  pcVar2 = (char *)(param_2 * 3 + -3 + *param_1);
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100050b8,0x70,DAT_100050c0,DAT_100050bc);
  }
  if (param_3 != 0) {
    if (param_2 == param_3) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_100050b8,0x72,DAT_100050c0,DAT_100050c8);
    }
    if ((param_3 != 0) && (param_3 <= *(byte *)(param_1 + 3))) {
      iVar1 = *param_1 + param_3 * 3 + -3;
      *(char *)(iVar1 + 2) = (char)param_2;
      if (*pcVar2 == '\0') {
        *pcVar2 = (char)param_3;
      }
      else {
        *(char *)(iVar1 + 1) = *pcVar2;
        *pcVar2 = (char)param_3;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100050b8,0x69,DAT_100050b4,DAT_100050b0);
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100050b8,0x71,DAT_100050c0,DAT_100050c4);
}


/* ===== lma_ph_merge_nodes @ 100050cc (62 bytes) ===== */

int lma_ph_merge_nodes(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3;
  if ((param_2 != 0) && (iVar2 = param_2, param_3 != 0)) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      lma_ph_add_child_node(param_1,param_3,param_2);
      iVar2 = param_3;
    }
    else {
      lma_ph_add_child_node(param_1,param_2,param_3);
    }
  }
  return iVar2;
}


/* ===== lma_add_alarm_under_lock @ 1000510c (328 bytes) ===== */

uint lma_add_alarm_under_lock
               (int **param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
               byte param_7,char param_8,undefined *param_9)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar5 = (uint)param_7;
  if (uVar5 == 0) {
    piVar3 = *param_1;
    uVar5 = (uint)*(byte *)((int)piVar3 + 0xe);
    if (uVar5 != 0) {
      if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000525c,0x69,DAT_10005258,DAT_10005254);
      }
      puVar4 = (undefined *)(uVar5 * 3 + -3 + *piVar3);
      cVar2 = puVar4[1];
      *(char *)((int)piVar3 + 0xe) = cVar2;
      if (cVar2 == '\0') {
        *(undefined *)((int)piVar3 + 0xf) = 0;
      }
      puVar4[2] = 0;
      puVar4[1] = 0;
      *puVar4 = 0;
    }
  }
  else {
    piVar3 = *param_1;
    if (uVar5 == *(byte *)((int)piVar3 + 0xd)) {
      cVar2 = '\x01';
    }
    else {
      if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000525c,0x69,DAT_10005258,DAT_10005254);
      }
      cVar2 = *(char *)(*piVar3 + uVar5 * 3 + -1);
      if (cVar2 != '\0') {
        cVar2 = '\x01';
      }
    }
    if (cVar2 != '\0') {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10005268,0x65,DAT_10005264,DAT_10005260);
    }
  }
  if (uVar5 != 0) {
    if ((uVar5 == 0) || (*(byte *)(*param_1 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10005268,0x3b,DAT_10005274,DAT_10005270);
    }
    piVar3 = param_1[2] + (uVar5 + DAT_1000526c) * 4;
    *piVar3 = param_3;
    piVar3[1] = param_4;
    piVar3[2] = param_5;
    piVar3[3] = param_6;
    piVar3 = *param_1;
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_1000525c,0xa6,DAT_1000527c,DAT_10005278);
    }
    if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_1000525c,0x69,DAT_10005258,DAT_10005254);
    }
    puVar4 = (undefined *)(uVar5 * 3 + -3 + *piVar3);
    puVar4[2] = 0;
    puVar4[1] = 0;
    *puVar4 = 0;
    uVar6 = lma_ph_merge_nodes(piVar3,*(undefined *)((int)piVar3 + 0xd),uVar5);
    *(char *)((int)piVar3 + 0xd) = (char)uVar6;
    if (uVar5 == (uint)uVar6) {
      iVar1 = lma_hardware_alarm_set_target
                        (*(undefined *)(param_1 + 5),(int)((ulonglong)uVar6 >> 0x20),param_3,param_4
                        );
      if ((iVar1 != 0) && (param_8 == '\0')) {
        lma_ph_remove_and_free_node(*param_1,uVar5);
      }
      if (param_9 != (undefined *)0x0) {
        *param_9 = (char)iVar1;
      }
    }
  }
  return uVar5;
}


/* ===== lma_alarm_pool_alarm_callback @ 10005280 (736 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x1000547e) */
/* WARNING: Removing unreachable block (ram,0x100053f6) */

void lma_alarm_pool_alarm_callback(int param_1)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int **ppiVar9;
  uint uVar10;
  bool bVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_30 = 0;
  ppiVar9 = *(int ***)(param_1 * 4 + DAT_10005560);
  do {
    while( true ) {
      lVar12 = lma_time_us_64();
      if (lVar12 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000556c,0x3f,DAT_10005568,DAT_10005564);
      }
      local_38 = 0;
      local_34 = 0;
      uVar10 = 0;
      bVar11 = (bool)isCurrentModePrivileged();
      if (bVar11) {
        uVar10 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      do {
      } while (*ppiVar9[1] == 0);
      DataMemoryBarrier(0x1f);
      piVar3 = *ppiVar9;
      bVar1 = *(byte *)((int)piVar3 + 0xd);
      uVar7 = (uint)bVar1;
      if (uVar7 == 0) {
        uVar6 = 0;
        pcVar5 = (code *)0x0;
        iVar4 = 0;
      }
      else {
        if ((uVar7 == 0) || (*(byte *)(piVar3 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
          lma___assert_func(DAT_10005578,0x3b,DAT_10005574,DAT_10005570);
        }
        puVar8 = (uint *)(ppiVar9[2] + (uVar7 + DAT_1000558c) * 4);
        iVar4 = (puVar8[1] - (int)((ulonglong)lVar12 >> 0x20)) - (uint)(*puVar8 < (uint)lVar12);
        if ((iVar4 < 1) && ((iVar4 != 0 || (*puVar8 == (uint)lVar12)))) {
          uVar2 = lma_ph_remove_head(piVar3,0);
          if (uVar2 != uVar7) {
                    /* WARNING: Subroutine does not return */
            lma___assert_func(DAT_10005578,0x8c,DAT_10005580,DAT_1000557c);
          }
          local_38 = *puVar8;
          local_34 = puVar8[1];
          pcVar5 = (code *)puVar8[2];
          uVar6 = puVar8[3];
          if (pcVar5 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
            lma___assert_func(DAT_10005578,0x90,DAT_10005580,DAT_10005584);
          }
          if ((uVar7 == 0) || (*(byte *)(*ppiVar9 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
            lma___assert_func(DAT_10005578,0x40,DAT_10005588,DAT_10005570);
          }
          local_30 = (uint)*(byte *)((int)ppiVar9[3] + (uVar7 - 1));
          ppiVar9[4] = (int *)(uVar2 | local_30 << 8);
          iVar4 = 0;
        }
        else {
          iVar4 = lma_hardware_alarm_set_target(param_1,iVar4,*puVar8,puVar8[1]);
          uVar6 = 0;
          pcVar5 = (code *)0x0;
        }
      }
      DataMemoryBarrier(0x1f);
      *ppiVar9[1] = 0;
      bVar11 = (bool)isCurrentModePrivileged();
      if (bVar11) {
        enableIRQinterrupts((uVar10 & 1) == 1);
      }
      if (pcVar5 != (code *)0x0) break;
      if (iVar4 == 0) {
        return;
      }
    }
    piVar3 = (int *)(local_30 << 8 | uVar7);
    lVar12 = (*pcVar5)(piVar3,uVar6);
    uVar10 = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      uVar10 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
      bVar11 = *ppiVar9[1] == 0;
    } while (bVar11);
    DataMemoryBarrier(0x1f);
    if ((lVar12 < 0) && (ppiVar9[4] != (int *)0x0)) {
      if (ppiVar9[4] != piVar3) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005578,0x9f,DAT_10005580,DAT_10005590);
      }
      uVar7 = (local_34 - (int)((ulonglong)lVar12 >> 0x20)) - (uint)(local_38 < (uint)lVar12);
      if ((uVar7 < local_34) || ((local_34 == uVar7 && (local_38 - (uint)lVar12 < local_38)))) {
        uVar7 = 0xffffffff;
      }
      if ((int)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000556c,0x3f,DAT_10005568,DAT_10005564);
      }
      lma_add_alarm_under_lock(ppiVar9);
    }
    else if ((lVar12 < 1) || (ppiVar9[4] == (int *)0x0)) {
      piVar3 = *ppiVar9;
      if (uVar7 == 0) {
LAB_10005514:
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000559c,0xf7,DAT_100055a4,DAT_100055a0);
      }
      if (uVar7 == *(byte *)((int)piVar3 + 0xd)) {
        bVar11 = true;
      }
      else {
        if ((uVar7 == 0) || (*(byte *)(piVar3 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
          lma___assert_func(DAT_1000559c,0x69,DAT_10005598,DAT_10005594);
        }
        if (*(char *)(uVar7 * 3 + *piVar3 + -1) != '\0') {
          bVar11 = true;
        }
      }
      if (bVar11) goto LAB_10005514;
      uVar6 = (uint)*(byte *)((int)piVar3 + 0xf);
      if (uVar6 != 0) {
        if ((uVar6 == 0) || (*(byte *)(piVar3 + 3) < uVar6)) {
                    /* WARNING: Subroutine does not return */
          lma___assert_func(DAT_1000559c,0x69,DAT_10005598,DAT_10005594);
        }
        *(byte *)(uVar6 * 3 + *piVar3 + -2) = bVar1;
      }
      *(byte *)((int)piVar3 + 0xf) = bVar1;
      if ((uVar7 == 0) || (*(byte *)(*ppiVar9 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005578,0x40,DAT_10005588,DAT_10005570);
      }
      *(char *)((int)ppiVar9[3] + (uVar7 - 1)) = *(char *)((int)ppiVar9[3] + (uVar7 - 1)) + '\x01';
    }
    else {
      if (ppiVar9[4] != piVar3) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005578,0xa2,DAT_10005580,DAT_10005590);
      }
      uVar13 = lma_time_us_64();
      if ((longlong)uVar13 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000556c,0x3f,DAT_10005568,DAT_10005564);
      }
      iVar4 = (int)(lVar12 + uVar13 >> 0x20);
      if (lVar12 + uVar13 < uVar13) {
        iVar4 = -1;
      }
      if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000556c,0x3f,DAT_10005568,DAT_10005564);
      }
      lma_add_alarm_under_lock(ppiVar9);
    }
    ppiVar9[4] = (int *)0x0;
    DataMemoryBarrier(0x1f);
    *ppiVar9[1] = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      enableIRQinterrupts((uVar10 & 1) == 1);
    }
  } while( true );
}


/* ===== lma_alarm_pool_init_default @ 100055a8 (44 bytes) ===== */

void lma_alarm_pool_init_default(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_100055d4;
  if (DAT_100055d4[1] == 0) {
    lma_ph_post_alloc_init(*DAT_100055d4,0x10,DAT_100055dc,DAT_100055d4);
    lma_alarm_pool_post_alloc_init(puVar1,3);
  }
  lma_lock_init(DAT_100055d8,10);
  return;
}


/* ===== lma_alarm_pool_get_default @ 100055e0 (26 bytes) ===== */

int lma_alarm_pool_get_default(void)

{
  if (*(int *)(DAT_100055fc + 4) != 0) {
    return DAT_100055fc;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005608,0x5c,DAT_10005604,DAT_10005600);
}


/* ===== lma_alarm_pool_add_alarm_at @ 1000560c (344 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x1000571c) */
/* WARNING: Removing unreachable block (ram,0x10005694) */

uint lma_alarm_pool_add_alarm_at
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,code *param_5,
               undefined4 param_6,char param_7)

{
  bool bVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  char local_29 [5];
  
  uVar2 = CONCAT44(param_4,param_3);
  local_29[0] = '\0';
  while( true ) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (*(int *)param_1[1] == 0);
    DataMemoryBarrier(0x1f);
    uVar3 = lma_add_alarm_under_lock
                      (param_1,0,(int)uVar2,(int)(uVar2 >> 0x20),param_5,param_6,0,0,local_29);
    if (uVar3 == 0) {
      uVar4 = 0;
    }
    else {
      if ((uVar3 == 0) || (*(byte *)(*param_1 + 0xc) < uVar3)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000576c,0x40,DAT_10005768,DAT_10005764);
      }
      uVar4 = (uint)*(byte *)(param_1[3] + (uVar3 - 1));
    }
    DataMemoryBarrier(0x1f);
    *(undefined4 *)param_1[1] = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    if (uVar3 == 0) break;
    if (local_29[0] == '\0') {
      return uVar3 | uVar4 << 8;
    }
    if (param_7 == '\0') {
      return 0;
    }
    lVar6 = (*param_5)(0,param_6);
    if (lVar6 == 0) {
      return 0;
    }
    if (lVar6 < 0) {
      bVar1 = uVar2 - lVar6 < uVar2;
      uVar2 = uVar2 - lVar6;
      if (bVar1) {
        uVar2 = 0xffffffffffffffff;
      }
      if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005778,0x3f,DAT_10005774,DAT_10005770);
      }
    }
    else {
      uVar7 = lma_time_us_64();
      if ((longlong)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005778,0x3f,DAT_10005774,DAT_10005770);
      }
      uVar2 = lVar6 + uVar7;
      if (uVar2 < uVar7) {
        uVar2 = 0xffffffffffffffff;
      }
      if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005778,0x3f,DAT_10005774,DAT_10005770);
      }
    }
  }
  return 0xffffffff;
}


/* ===== lma_alarm_pool_cancel_alarm @ 1000577c (202 bytes) ===== */

int lma_alarm_pool_cancel_alarm(int **param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*param_1[1] == 0);
  DataMemoryBarrier(0x1f);
  uVar4 = (uint)param_2 & 0xff;
  piVar3 = *param_1;
  if (uVar4 == *(byte *)((int)piVar3 + 0xd)) {
    bVar1 = true;
  }
  else {
    if ((uVar4 == 0) || (*(byte *)(piVar3 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10005850,0x69,DAT_1000584c,DAT_10005848,param_4);
    }
    bVar1 = false;
    if (*(char *)(uVar4 * 3 + *piVar3 + -1) != '\0') {
      bVar1 = true;
    }
  }
  if (bVar1) {
    if (param_1[4] == param_2) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_1000585c,0x10a,DAT_10005858,DAT_10005854,param_4);
    }
    if ((uVar4 == 0) || (*(byte *)(*param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_1000585c,0x40,DAT_10005864,DAT_10005860,param_4);
    }
    if ((uint)*(byte *)((int)param_1[3] + (uVar4 - 1)) == ((uint)param_2 >> 8 & 0xff)) {
      iVar2 = lma_ph_remove_and_free_node(piVar3,uVar4);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000585c,0x111,DAT_10005858,DAT_10005868,param_4);
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
    if (param_1[4] == param_2) {
      param_1[4] = (int *)0x0;
    }
  }
  DataMemoryBarrier(0x1f);
  *param_1[1] = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return iVar2;
}


/* ===== lma_alarm_pool_add_repeating_timer_us @ 1000586c (140 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x100058b8) */

uint lma_alarm_pool_add_repeating_timer_us
               (uint param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               uint *param_7)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  
  if ((param_3 | param_4) == 0) {
    param_3 = 1;
    param_4 = 0;
  }
  param_7[2] = param_1;
  param_7[4] = param_5;
  *param_7 = param_3;
  param_7[1] = param_4;
  param_7[5] = param_6;
  uVar2 = (int)param_4 >> 0x1f;
  uVar4 = lma_time_us_64();
  if ((longlong)uVar4 < 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10005904,0x3f,DAT_10005900,DAT_100058fc);
  }
  uVar1 = uVar4 + CONCAT44(((param_4 ^ uVar2) - uVar2) - (uint)((param_3 ^ uVar2) < uVar2),
                           (param_3 ^ uVar2) - uVar2);
  iVar3 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar4) {
    iVar3 = -1;
  }
  if (-1 < iVar3) {
    uVar2 = lma_alarm_pool_add_alarm_at(param_1);
    param_7[3] = uVar2;
    return ~uVar2 >> 0x1f;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005904,0x3f,DAT_10005900,DAT_100058fc);
}


/* ===== lma_sleep_until @ 10005908 (222 bytes) ===== */

void lma_sleep_until(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  
  iVar3 = lma_____get_current_exception_veneer();
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    lma_panic(DAT_100059e8);
  }
  uVar5 = param_1 - 6;
  uVar6 = (param_2 - 1) + (uint)(5 < param_1);
  if ((param_2 < uVar6) || ((uVar6 == param_2 && (param_1 < uVar5)))) {
    uVar5 = 0;
    uVar6 = 0;
  }
  if ((int)uVar6 < 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100059f4,0x3f,DAT_100059f0,DAT_100059ec);
  }
  lVar7 = lma_time_us_64();
  if (lVar7 < 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100059f4,0x3f,DAT_100059f0,DAT_100059ec);
  }
  uVar4 = uVar6 - (int)((ulonglong)lVar7 >> 0x20);
  uVar2 = (uint)(uVar5 < (uint)lVar7);
  if ((0 < (int)(uVar4 - uVar2)) || ((uVar4 == uVar2 && (uVar5 != (uint)lVar7)))) {
    uVar8 = lma_alarm_pool_get_default();
    iVar3 = lma_alarm_pool_add_alarm_at
                      ((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar5,uVar6,DAT_100059f8,0,0);
    if (-1 < iVar3) {
      while( true ) {
        if (*(uint *)(DAT_10005a00 + 0x24) < uVar6) {
          bVar1 = false;
        }
        else if (*(uint *)(DAT_10005a00 + 0x28) < uVar5) {
          if (uVar6 == *(uint *)(DAT_10005a00 + 0x24)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
        }
        else {
          bVar1 = true;
        }
        if (bVar1) break;
        uVar4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar4 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        do {
        } while (**DAT_100059fc == 0);
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        **DAT_100059fc = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar4 & 1) == 1);
        }
        WaitForEvent();
      }
    }
  }
  lma_busy_wait_until(param_1,param_2);
  return;
}


/* ===== lma_sleep_us @ 10005a04 (74 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x10005a22) */

void lma_sleep_us(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = lma_time_us_64();
  if ((longlong)uVar3 < 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10005a58,0x3f,DAT_10005a54,DAT_10005a50,param_4);
  }
  uVar1 = uVar3 + CONCAT44(param_2,param_1);
  iVar2 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar3) {
    iVar2 = -1;
  }
  if (-1 < iVar2) {
    lma_sleep_until();
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005a58,0x3f,DAT_10005a54,DAT_10005a50,param_4);
}


/* ===== lma_sleep_ms @ 10005a5c (20 bytes) ===== */

void lma_sleep_ms(undefined4 param_1)

{
  lma___wrap___aeabi_lmul(param_1,0,1000,0);
  lma_sleep_us();
  return;
}


/* ===== lma_best_effort_wfe_or_timeout @ 10005a70 (120 bytes) ===== */

undefined4 lma_best_effort_wfe_or_timeout(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = lma_alarm_pool_get_default();
  iVar1 = lma_alarm_pool_add_alarm_at
                    ((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1,param_2,DAT_10005ae8,0,0);
  if (iVar1 < 1) {
    if (*(uint *)(DAT_10005aec + 0x24) < param_2) {
      uVar2 = 0;
    }
    else if (*(uint *)(DAT_10005aec + 0x28) < param_1) {
      if (param_2 == *(uint *)(DAT_10005aec + 0x24)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    WaitForEvent();
    uVar2 = lma_alarm_pool_get_default();
    lma_alarm_pool_cancel_alarm(uVar2,iVar1);
    if (*(uint *)(DAT_10005aec + 0x24) < param_2) {
      uVar2 = 0;
    }
    else if (*(uint *)(DAT_10005aec + 0x28) < param_1) {
      if (param_2 == *(uint *)(DAT_10005aec + 0x24)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* ===== lma_hardware_alarm_claim @ 10005b7c (14 bytes) ===== */

void lma_hardware_alarm_claim(undefined4 param_1)

{
  lma_hw_claim_or_assert(DAT_10005b90,param_1,DAT_10005b8c);
  return;
}


/* ===== lma_time_us_64 @ 10005b94 (18 bytes) ===== */

undefined4 lma_time_us_64(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(DAT_10005ba8 + 0x24);
  do {
    bVar2 = iVar1 != *(int *)(DAT_10005ba8 + 0x24);
    iVar1 = *(int *)(DAT_10005ba8 + 0x24);
  } while (bVar2);
  return *(undefined4 *)(DAT_10005ba8 + 0x28);
}


/* ===== lma_busy_wait_until @ 10005bac (34 bytes) ===== */

void lma_busy_wait_until(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_10005bd0 + 0x24);
  while (uVar1 < param_2) {
    uVar1 = *(uint *)(DAT_10005bd0 + 0x24);
  }
  while ((uVar1 == param_2 && (*(uint *)(DAT_10005bd0 + 0x28) < param_1))) {
    uVar1 = *(uint *)(DAT_10005bd0 + 0x24);
  }
  return;
}


/* ===== lma_busy_wait_us @ 10005bd4 (60 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x10005bf0) */

void lma_busy_wait_us(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = lma_time_us_64();
  uVar1 = uVar3 + CONCAT44(param_2,param_1);
  iVar2 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar3) {
    iVar2 = -1;
  }
  if (-1 < iVar2) {
    lma_busy_wait_until();
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005c18,0x3f,DAT_10005c14,DAT_10005c10);
}


/* ===== lma_busy_wait_us_32 @ 10005c1c (30 bytes) ===== */

void lma_busy_wait_us_32(uint param_1)

{
  if ((int)param_1 < 0) {
    lma_busy_wait_us(param_1,0);
  }
  else {
    do {
    } while ((uint)(*(int *)(DAT_10005c3c + 0x28) - *(int *)(DAT_10005c3c + 0x28)) < param_1);
  }
  return;
}


/* ===== lma_hardware_alarm_set_callback @ 10005c40 (124 bytes) ===== */

void lma_hardware_alarm_set_callback(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_10005cbc == 0);
  DataMemoryBarrier(0x1f);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 * 4 + DAT_10005cc8) = 0;
    *DAT_10005ccc = *DAT_10005ccc & ~(byte)(1 << (param_1 & 0xff));
    lma_irq_remove_handler(param_1,DAT_10005cc0);
    lma_irq_set_enabled(param_1,0);
  }
  else {
    iVar2 = lma_irq_get_vtable_handler(param_1);
    if (DAT_10005cc0 != iVar2) {
      lma_irq_set_exclusive_handler(param_1,DAT_10005cc0);
      lma_irq_set_enabled(param_1,1);
      *DAT_10005cc4 = 1 << (param_1 & 0xff);
    }
    *(int *)(param_1 * 4 + DAT_10005cc8) = param_2;
  }
  DataMemoryBarrier(0x1f);
  *DAT_10005cbc = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== lma_hardware_alarm_set_target @ 10005cd0 (198 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x10005cee) */
/* WARNING: Removing unreachable block (ram,0x10005d5c) */

undefined4
lma_hardware_alarm_set_target(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar7 = lma_time_us_64();
  if (uVar7 < CONCAT44(param_4,param_3)) {
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (*DAT_10005d98 == 0);
    DataMemoryBarrier(0x1f);
    bVar1 = *DAT_10005d9c;
    uVar5 = 1 << (param_1 & 0xff);
    *DAT_10005d9c = (byte)uVar5 | bVar1;
    iVar3 = DAT_10005da0;
    *(uint *)(DAT_10005da0 + 0x34) = uVar5;
    *(undefined4 *)((param_1 + 4) * 4 + iVar3) = param_3;
    *(undefined4 *)(param_1 * 4 + DAT_10005da4) = param_4;
    if ((*(uint *)(iVar3 + 0x20) & uVar5) == 0) {
      if ((*(uint *)(DAT_10005da0 + 0x40) & uVar5) == 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005db0,0xc1,DAT_10005dac,DAT_10005da8);
      }
      uVar4 = 0;
    }
    else {
      uVar7 = lma_time_us_64();
      iVar3 = DAT_10005da0;
      if (uVar7 < CONCAT44(param_4,param_3)) {
        uVar4 = 0;
      }
      else if (*DAT_10005d9c == bVar1) {
        uVar4 = 1;
      }
      else {
        *(uint *)(DAT_10005da0 + 0x20) = uVar5;
        *(uint *)(iVar3 + 0x34) = uVar5;
        *DAT_10005db4 = 1 << (param_1 & 0x1f);
        *DAT_10005d9c = bVar1;
        uVar4 = 1;
      }
    }
    DataMemoryBarrier(0x1f);
    *DAT_10005d98 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


/* ===== lma_hardware_alarm_cancel @ 10005db8 (50 bytes) ===== */

void lma_hardware_alarm_cancel(uint param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_10005dec == 0);
  DataMemoryBarrier(0x1f);
  iVar2 = 1 << (param_1 & 0xff);
  *(int *)(DAT_10005df0 + 0x20) = iVar2;
  *DAT_10005df4 = *DAT_10005df4 & ~(byte)iVar2;
  DataMemoryBarrier(0x1f);
  *DAT_10005dec = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== lma_lock_init @ 10005df8 (12 bytes) ===== */

void lma_lock_init(int *param_1,int param_2)

{
  *param_1 = (param_2 + DAT_10005e04) * 4;
  return;
}


/* ===== lma_mutex_init @ 10005e08 (26 bytes) ===== */

void lma_mutex_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = lma_next_striped_spin_lock_num();
  lma_lock_init(param_1,uVar1);
  *(undefined *)(param_1 + 4) = 0xff;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== lma_recursive_mutex_init @ 10005e22 (30 bytes) ===== */

void lma_recursive_mutex_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = lma_next_striped_spin_lock_num();
  lma_lock_init(param_1,uVar1);
  *(undefined *)(param_1 + 4) = 0xff;
  *(undefined *)(param_1 + 5) = 0;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== lma_critical_section_init_with_lock_num @ 10005e40 (16 bytes) ===== */

void lma_critical_section_init_with_lock_num(int *param_1,int param_2)

{
  *param_1 = (param_2 + DAT_10005e50) * 4;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== lma_critical_section_init @ 10005e54 (20 bytes) ===== */

void lma_critical_section_init(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = lma_spin_lock_claim_unused(1);
  lma_critical_section_init_with_lock_num(param_1,uVar1);
  return;
}


/* ===== lma_ph_add_child_node @ 10005e68 (134 bytes) ===== */

void lma_ph_add_child_node(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10005ef8,0x69,DAT_10005ef4,DAT_10005ef0);
  }
  pcVar2 = (char *)(param_2 * 3 + -3 + *param_1);
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10005ef8,0x70,DAT_10005f00,DAT_10005efc);
  }
  if (param_3 != 0) {
    if (param_2 == param_3) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10005ef8,0x72,DAT_10005f00,DAT_10005f08);
    }
    if ((param_3 != 0) && (param_3 <= *(byte *)(param_1 + 3))) {
      iVar1 = *param_1 + param_3 * 3 + -3;
      *(char *)(iVar1 + 2) = (char)param_2;
      if (*pcVar2 == '\0') {
        *pcVar2 = (char)param_3;
      }
      else {
        *(char *)(iVar1 + 1) = *pcVar2;
        *pcVar2 = (char)param_3;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10005ef8,0x69,DAT_10005ef4,DAT_10005ef0);
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005ef8,0x71,DAT_10005f00,DAT_10005f04);
}


/* ===== lma_ph_merge_nodes @ 10005f0c (62 bytes) ===== */

int lma_ph_merge_nodes(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3;
  if ((param_2 != 0) && (iVar2 = param_2, param_3 != 0)) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      lma_ph_add_child_node(param_1,param_3,param_2);
      iVar2 = param_3;
    }
    else {
      lma_ph_add_child_node(param_1,param_2,param_3);
    }
  }
  return iVar2;
}


/* ===== lma_ph_clear @ 10005f4c (100 bytes) ===== */

void lma_ph_clear(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined *)((int)param_1 + 0xd) = 0;
  *(undefined *)((int)param_1 + 0xe) = 1;
  *(undefined *)((int)param_1 + 0xf) = *(undefined *)(param_1 + 3);
  uVar3 = 1;
  while( true ) {
    uVar2 = (uint)*(byte *)(param_1 + 3);
    if (uVar2 <= uVar3) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10005fb8,0x69,DAT_10005fb4,DAT_10005fb0);
      }
      *(undefined *)(*param_1 + uVar2 * 3 + -2) = 0;
      return;
    }
    if ((uVar3 == 0) || (*(byte *)(param_1 + 3) < uVar3)) break;
    iVar1 = uVar3 * 3;
    uVar2 = uVar3 + 1;
    uVar3 = uVar2 & 0xff;
    *(char *)(iVar1 + *param_1 + -2) = (char)uVar2;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10005fb8,0x69,DAT_10005fb4,DAT_10005fb0);
}


/* ===== lma_ph_post_alloc_init @ 10005fbc (14 bytes) ===== */

void lma_ph_post_alloc_init(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  lma_ph_clear();
  return;
}


/* ===== lma_ph_merge_two_pass @ 10005fcc (156 bytes) ===== */

void lma_ph_merge_two_pass(int *param_1,uint param_2)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 != 0) {
    if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10006070,0x69,DAT_1000606c,DAT_10006068);
    }
    uVar4 = (uint)*(byte *)(param_2 * 3 + *param_1 + -2);
    if (uVar4 != 0) {
      if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10006070,0x69,DAT_1000606c,DAT_10006068);
      }
      iVar5 = uVar4 * 3 + -3 + *param_1;
      uVar1 = *(undefined *)(iVar5 + 1);
      *(undefined *)(iVar5 + 1) = 0;
      if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10006070,0x69,DAT_1000606c,DAT_10006068);
      }
      *(undefined *)(param_2 * 3 + *param_1 + -2) = 0;
      uVar2 = lma_ph_merge_nodes(param_1,param_2);
      uVar3 = lma_ph_merge_two_pass(param_1,uVar1);
      lma_ph_merge_nodes(param_1,uVar2,uVar3);
    }
  }
  return;
}


/* ===== lma_ph_remove_any_head @ 10006074 (232 bytes) ===== */

void lma_ph_remove_any_head(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006164,0x38,DAT_10006160,DAT_1000615c);
  }
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006170,0x69,DAT_1000616c,DAT_10006168);
  }
  puVar3 = (undefined *)(param_2 * 3 + -3 + *param_1);
  if (puVar3[1] != '\0') {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006164,0x3a,DAT_10006160,DAT_10006174);
  }
  if (puVar3[2] == '\0') {
    uVar1 = lma_ph_merge_two_pass(param_1,*puVar3);
    if (param_3 != 0) {
      uVar2 = (uint)*(byte *)((int)param_1 + 0xf);
      if (uVar2 != 0) {
        if ((uVar2 == 0) || (*(byte *)(param_1 + 3) < uVar2)) {
                    /* WARNING: Subroutine does not return */
          lma___assert_func(DAT_10006170,0x69,DAT_1000616c,DAT_10006168);
        }
        *(char *)(uVar2 * 3 + *param_1 + -2) = (char)param_2;
      }
      *(char *)((int)param_1 + 0xf) = (char)param_2;
    }
    if (uVar1 != 0) {
      if ((uVar1 == 0) || (*(byte *)(param_1 + 3) < uVar1)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10006170,0x69,DAT_1000616c,DAT_10006168);
      }
      *(undefined *)(uVar1 * 3 + *param_1 + -1) = 0;
    }
    if ((param_2 != 0) && (param_2 <= *(byte *)(param_1 + 3))) {
      *(undefined *)(*param_1 + param_2 * 3 + -2) = 0;
      return;
    }
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006170,0x69,DAT_1000616c,DAT_10006168);
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10006164,0x3b,DAT_10006160,DAT_10006178);
}


/* ===== lma_ph_remove_head @ 1000617c (20 bytes) ===== */

undefined lma_ph_remove_head(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined uVar2;
  
  uVar1 = *(undefined *)(param_1 + 0xd);
  uVar2 = lma_ph_remove_any_head(param_1,uVar1,param_2);
  *(undefined *)(param_1 + 0xd) = uVar2;
  return uVar1;
}


/* ===== lma_ph_remove_and_free_node @ 10006190 (220 bytes) ===== */

undefined4 lma_ph_remove_and_free_node(int *param_1,uint param_2)

{
  undefined uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else if (*(byte *)((int)param_1 + 0xd) == param_2) {
    lma_ph_remove_head(param_1,1);
    uVar3 = 1;
  }
  else {
    if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10006274,0x69,DAT_10006270,DAT_1000626c);
    }
    iVar2 = *param_1 + param_2 * 3 + -3;
    uVar4 = (uint)*(byte *)(iVar2 + 2);
    if (uVar4 == 0) {
      uVar3 = 0;
    }
    else {
      if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10006274,0x69,DAT_10006270,DAT_1000626c);
      }
      iVar5 = uVar4 * 3 + -3;
      uVar4 = (uint)*(byte *)(*param_1 + iVar5);
      if (uVar4 == param_2) {
        *(undefined *)(*param_1 + iVar5) = *(undefined *)(iVar2 + 1);
      }
      else {
        while( true ) {
          if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
            lma___assert_func(DAT_10006274,0x69,DAT_10006270,DAT_1000626c);
          }
          iVar5 = *param_1 + uVar4 * 3 + -3;
          uVar4 = (uint)*(byte *)(iVar5 + 1);
          if (uVar4 == param_2) break;
          if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            lma___assert_func(DAT_10006280,0x67,DAT_1000627c,DAT_10006278);
          }
        }
        *(undefined *)(iVar5 + 1) = *(undefined *)(iVar2 + 1);
      }
      *(undefined *)(iVar2 + 2) = 0;
      *(undefined *)(iVar2 + 1) = 0;
      uVar4 = lma_ph_remove_any_head(param_1,param_2,1);
      if (*(byte *)((int)param_1 + 0xd) == uVar4) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_10006280,0x6d,DAT_1000627c,DAT_10006284);
      }
      uVar1 = lma_ph_merge_nodes(param_1,(uint)*(byte *)((int)param_1 + 0xd),uVar4);
      *(undefined *)((int)param_1 + 0xd) = uVar1;
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* ===== lma__exit @ 10006288 (4 bytes) ===== */

void lma__exit(void)

{
  do {
    software_bkpt(0);
  } while( true );
}


/* ===== lma___assert_func @ 10006294 (46 bytes) ===== */

void lma___assert_func(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = CONCAT44(param_4,param_1);
  iVar1 = param_3;
  iVar2 = DAT_100062c4;
  if (param_3 == 0) goto LAB_100062ba;
  do {
    param_3 = (int)uVar3;
    if (iVar1 == 0) {
      iVar1 = DAT_100062cc;
    }
    lma___wrap_printf(DAT_100062c8,(int)((ulonglong)uVar3 >> 0x20),param_3,param_2,iVar2,iVar1);
    uVar3 = lma__exit(1);
LAB_100062ba:
    iVar1 = param_3;
    iVar2 = DAT_100062cc;
  } while( true );
}


/* ===== lma_runtime_init @ 100062d0 (174 bytes) ===== */

void lma_runtime_init(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code **ppcVar4;
  
  *DAT_10006380 = DAT_10006384;
  *DAT_10006388 = DAT_1000638c;
  do {
    ppcVar4 = DAT_10006394;
  } while ((DAT_1000638c & ~*(uint *)(DAT_10006390 + 8)) != 0);
  for (; ppcVar4 < DAT_10006398; ppcVar4 = ppcVar4 + 1) {
    (**ppcVar4)();
  }
  lma_clocks_init();
  *DAT_10006388 = DAT_1000639c;
  iVar2 = DAT_100063a0;
  do {
  } while ((~*(uint *)(DAT_10006390 + 8) & 0x1ffffff) != 0);
  *(undefined4 *)(DAT_100063a0 + 0x78) = 0x40;
  *(undefined4 *)(iVar2 + 0x74) = 0x40;
  *(undefined4 *)(iVar2 + 0x70) = 0x40;
  *(undefined4 *)(iVar2 + 0x6c) = 0x40;
  piVar3 = DAT_100063a4;
  while( true ) {
    while( true ) {
      uVar1 = DAT_100063bc;
      iVar2 = DAT_100063b8;
      if (DAT_100063b4 <= piVar3) {
        lma_memcpy(DAT_100063bc,*(undefined4 *)(DAT_100063b8 + 8),0xc0);
        *(undefined4 *)(iVar2 + 8) = uVar1;
        iVar2 = lma_____get_current_exception_veneer();
        if (iVar2 != 0) {
          software_bkpt(0);
        }
        lma_spin_locks_reset();
        lma_irq_init_priorities();
        lma_alarm_pool_init_default();
        for (ppcVar4 = DAT_100063c0; ppcVar4 < DAT_100063c4; ppcVar4 = ppcVar4 + 1) {
          (**ppcVar4)();
        }
        return;
      }
      if (*piVar3 != 0) break;
      lma_mutex_init(piVar3);
      piVar3 = piVar3 + 2;
    }
    if (*piVar3 != 1) break;
    lma_recursive_mutex_init(piVar3);
    piVar3 = piVar3 + 2;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100063b0,0x83,DAT_100063ac,DAT_100063a8);
}


/* ===== lma_panic @ 100063c8 (48 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x100064ba) */
/* WARNING: Removing unreachable block (ram,0x100064be) */
/* WARNING: Removing unreachable block (ram,0x100064c8) */
/* WARNING: Removing unreachable block (ram,0x100064ce) */
/* WARNING: Removing unreachable block (ram,0x100064d0) */
/* WARNING: Removing unreachable block (ram,0x100064da) */
/* WARNING: Removing unreachable block (ram,0x100064e4) */

void lma_panic(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *unaff_r6;
  code *UNRECOVERED_JUMPTABLE;
  uint uStack_20;
  
  lma___wrap_puts(s_____PANIC_____2000ce38);
  if (param_1 != 0) {
    lma___wrap_vprintf(param_1);
    lma___wrap_puts(s___8s___16s_rev___4s_2000c5fc + 0x14);
  }
  UNRECOVERED_JUMPTABLE = (code *)0x100063f1;
  lma__exit(1);
  uVar4 = *unaff_r6;
  unaff_r6[3] = unaff_r6[1];
  if (uVar4 < uStack_20) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100064f8,0x2d,DAT_100064f4,DAT_100064f0);
  }
  uVar2 = lma___aeabi_uldivmod(uVar4 << 8,uVar4 >> 0x18,uStack_20,0);
  puVar1 = DAT_100064e8;
  if (DAT_100064e8[1] < uVar2) {
    DAT_100064e8[1] = uVar2;
  }
  *(undefined4 *)((uint)puVar1 | 0x3000) = 0x800;
  if (*DAT_100064ec != 0) {
    iVar3 = lma___aeabi_uidiv(DAT_100064ec[5]);
    iVar3 = iVar3 + 1;
    do {
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(uint *)((uint)puVar1 | 0x1000) = (param_3 << 5 ^ *puVar1) & 0xe0;
  *(undefined4 *)((uint)puVar1 | 0x2000) = 0x800;
  puVar1[1] = uVar2;
  iVar3 = lma___aeabi_uldivmod(uVar4 << 8,uVar4 >> 0x18,uVar2,0);
  *DAT_100064ec = iVar3;
                    /* WARNING: Could not recover jumptable at 0x100064ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(1);
  return;
}


/* ===== lma_clock_configure @ 100063f8 (238 bytes) ===== */

void lma_clock_configure(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_4 < param_5) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100064f8,0x2d,DAT_100064f4,DAT_100064f0);
  }
  uVar1 = lma___aeabi_uldivmod(param_4 << 8,param_4 >> 0x18,param_5,0);
  puVar5 = (uint *)(param_1 * 0xc + DAT_100064e8);
  if (puVar5[1] < uVar1) {
    puVar5[1] = uVar1;
  }
  uVar4 = param_1 - 4U & 0xff;
  if ((uVar4 < 2) && (param_2 == 1)) {
    *(undefined4 *)((uint)puVar5 | 0x3000) = 3;
    do {
    } while (-1 < (int)(puVar5[2] << 0x1f));
  }
  else {
    *(undefined4 *)((uint)puVar5 | 0x3000) = 0x800;
    if (*(int *)(param_1 * 4 + DAT_100064ec) != 0) {
      iVar2 = lma___aeabi_uidiv(*(undefined4 *)(DAT_100064ec + 0x14));
      iVar2 = iVar2 + 1;
      do {
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  *(uint *)((uint)puVar5 | 0x1000) = (param_3 << 5 ^ *puVar5) & 0xe0;
  if (uVar4 < 2) {
    *(uint *)((uint)puVar5 | 0x1000) = (*puVar5 ^ param_2) & 3;
    do {
    } while ((1 << (param_2 & 0xff) & puVar5[2]) == 0);
  }
  *(undefined4 *)((uint)puVar5 | 0x2000) = 0x800;
  puVar5[1] = uVar1;
  uVar3 = lma___aeabi_uldivmod(param_4 << 8,param_4 >> 0x18,uVar1,0);
  *(undefined4 *)(DAT_100064ec + param_1 * 4) = uVar3;
                    /* WARNING: Could not recover jumptable at 0x100064ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(1);
  return;
}


/* ===== lma_clocks_init @ 100064fc (206 bytes) ===== */

void lma_clocks_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  lma_watchdog_start_tick(0xc);
  iVar3 = lma_running_on_fpga();
  if (iVar3 == 0) {
    *(undefined4 *)(DAT_100065d8 + 0x78) = 0;
    lma_xosc_init();
    *DAT_100065dc = 1;
    do {
    } while (*(int *)(DAT_100065d8 + 0x44) != 1);
    *DAT_100065e0 = 3;
    do {
    } while (*(int *)(DAT_100065d8 + 0x38) != 1);
    lma_pll_init(DAT_100065e8,1,DAT_100065e4,6,2);
    lma_pll_init(DAT_100065f0,1,DAT_100065ec,5,2);
    lma_clock_configure(4,2,0,DAT_100065f4,DAT_100065f4);
    uVar2 = DAT_100065f8;
    lma_clock_configure(5,1,0,DAT_100065f8,DAT_100065f8);
    uVar1 = DAT_100065d0;
    lma_clock_configure(7,0,0,DAT_100065d0,DAT_100065d0);
    lma_clock_configure(8,0,0,uVar1,uVar1);
    lma_clock_configure(9,0,0,uVar1,DAT_100065d4);
    lma_clock_configure(6,0,0,uVar2,uVar2);
  }
  else {
    for (uVar4 = 0; uVar4 < 10; uVar4 = uVar4 + 1) {
      *(undefined4 *)(uVar4 * 4 + DAT_100065cc) = DAT_100065d0;
    }
    *(undefined4 *)(DAT_100065cc + 0x24) = DAT_100065d4;
  }
  return;
}


/* ===== lma_clock_get_hz @ 100065fc (8 bytes) ===== */

undefined4 lma_clock_get_hz(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + DAT_10006604);
}


/* ===== lma_set_raw_irq_handler_and_unlock @ 10006608 (30 bytes) ===== */

void lma_set_raw_irq_handler_and_unlock(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  
  *(undefined4 *)(*(int *)(DAT_10006628 + 8) + (param_1 + 0x10) * 4) = param_2;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_1000662c = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_3 & 1) == 1);
  }
  return;
}


/* ===== lma_make_branch @ 10006630 (36 bytes) ===== */

uint lma_make_branch(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 - param_1) - 4;
  if (uVar1 >> 0xc == 0) {
    return uVar1 >> 1 & 0x7ff | DAT_10006654 & 0xffff;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10006660,0x8b,DAT_1000665c,DAT_10006658);
}


/* ===== lma_insert_branch_and_link @ 10006664 (42 bytes) ===== */

void lma_insert_branch_and_link(undefined2 *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 - (int)param_1) - 4;
  if (uVar1 >> 0xc == 0) {
    *param_1 = (short)DAT_10006690;
    param_1[1] = (ushort)DAT_10006694 | (ushort)(uVar1 >> 1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100066a0,0x93,DAT_1000669c,DAT_10006698);
}


/* ===== lma_irq_is_enabled @ 100066a4 (18 bytes) ===== */

bool lma_irq_is_enabled(uint param_1)

{
  return (*DAT_100066b8 & 1 << (param_1 & 0xff)) != 0;
}


/* ===== lma_irq_set_mask_enabled @ 100066bc (20 bytes) ===== */

void lma_irq_set_mask_enabled(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    *DAT_100066d8 = param_1;
  }
  else {
    *DAT_100066d0 = param_1;
    *DAT_100066d4 = param_1;
  }
  return;
}


/* ===== lma_irq_set_enabled @ 100066dc (14 bytes) ===== */

void lma_irq_set_enabled(uint param_1)

{
  lma_irq_set_mask_enabled(1 << (param_1 & 0xff));
  return;
}


/* ===== lma_irq_get_vtable_handler @ 100066ec (12 bytes) ===== */

undefined4 lma_irq_get_vtable_handler(int param_1)

{
  return *(undefined4 *)((param_1 + 0x10) * 4 + *(int *)(DAT_100066f8 + 8));
}


/* ===== lma_irq_set_exclusive_handler @ 100066fc (64 bytes) ===== */

void lma_irq_set_exclusive_handler(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_1000673c == 0);
  DataMemoryBarrier(0x1f);
  iVar2 = lma_irq_get_vtable_handler(param_1);
  if ((iVar2 != DAT_10006740) && (iVar2 != param_2)) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000674c,0x6e,DAT_10006748,DAT_10006744);
  }
  lma_set_raw_irq_handler_and_unlock(param_1,param_2,uVar3);
  return;
}


/* ===== lma_irq_remove_handler @ 10006750 (372 bytes) ===== */

void lma_irq_remove_handler(int param_1,uint param_2)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  
  uVar14 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar14 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_100068c4 == 0);
  DataMemoryBarrier(0x1f);
  uVar12 = *(uint *)(*(int *)(DAT_100068c8 + 8) + (param_1 + 0x10) * 4);
  uVar9 = uVar12;
  if (((uVar12 != DAT_100068cc) && (uVar9 = DAT_100068cc, uVar12 != param_2)) &&
     (uVar9 = uVar12, uVar12 - DAT_100068d0 < 0x30)) {
    uVar6 = lma_irq_is_enabled(param_1);
    lma_irq_set_enabled(param_1,0);
    DataMemoryBarrier(0x1f);
    iVar7 = lma_____get_current_exception_veneer();
    if ((iVar7 != 0) && (param_1 + 0x10 != iVar7)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_100068e0,0x11d,DAT_100068dc,DAT_100068d8);
    }
    uVar8 = ((uVar10 - DAT_100068d0) * 2 + (uint)(DAT_100068d0 <= uVar10)) * DAT_100068d4;
    uVar9 = 0;
    for (uVar10 = uVar12 & 0xfffffffe;
        (*(uint *)(uVar10 + 8) != param_2 && (uVar9 = uVar10, -1 < *(char *)(uVar10 + 6)));
        uVar10 = DAT_100068d0 + *(char *)(uVar10 + 6) * 0xc) {
    }
    if (*(uint *)(uVar10 + 8) != param_2) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_100068e0,0x152,DAT_100068dc,DAT_100068f8);
    }
    cVar2 = *(char *)(uVar10 + 6);
    iVar11 = (int)cVar2;
    if (iVar11 < 0) {
      if (iVar7 == 0) {
        uVar13 = DAT_100068cc;
        if (uVar9 != 0) {
          *(undefined *)(uVar9 + 6) = 0xff;
          *(short *)(uVar9 + 4) = (short)DAT_100068f0;
          uVar13 = uVar12;
        }
        pcVar4 = DAT_100068e4;
        *(char *)(uVar10 + 6) = *DAT_100068e4;
        *pcVar4 = (char)(uVar8 >> 0x14);
        uVar12 = uVar13;
      }
      else {
        lma_insert_branch_and_link(uVar10 + 4,DAT_100068f4);
      }
    }
    else {
      iVar7 = DAT_100068d0 + iVar11 * 0xc;
      *(undefined4 *)(uVar10 + 8) = *(undefined4 *)(iVar7 + 8);
      *(undefined *)(uVar10 + 7) = *(undefined *)(iVar7 + 7);
      *(undefined *)(uVar10 + 6) = *(undefined *)(iVar7 + 6);
      if (*(char *)(iVar7 + 6) < '\0') {
        uVar5 = 0xbd00;
      }
      else {
        iVar7 = iVar11 * 0xc + DAT_100068d0;
        uVar1 = *(ushort *)(iVar7 + 4);
        if (uVar1 >> 0xb != 0x1c) {
                    /* WARNING: Subroutine does not return */
          lma___assert_func(DAT_100068e0,0x99,DAT_100068ec,DAT_100068e8);
        }
        uVar5 = lma_make_branch(uVar10 + 4,
                                iVar7 + 4 + (((int)((uint)uVar1 << 0x15) >> 0x15) + 2) * 2);
      }
      *(undefined2 *)(uVar10 + 4) = uVar5;
      pcVar4 = DAT_100068e4;
      *(char *)(DAT_100068d0 + iVar11 * 0xc + 6) = *DAT_100068e4;
      *pcVar4 = cVar2;
    }
    lma_irq_set_enabled(param_1,uVar6);
    uVar9 = uVar12;
  }
  lma_set_raw_irq_handler_and_unlock(param_1,uVar9,uVar14);
  return;
}


/* ===== lma_irq_init_priorities @ 100069ec (18 bytes) ===== */

void lma_irq_init_priorities(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_10006a00;
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    *puVar2 = DAT_10006a04;
    puVar2 = puVar2 + 1;
  }
  return;
}


/* ===== lma_pll_init @ 10006a08 (240 bytes) ===== */

void lma_pll_init(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = lma___aeabi_uidiv(0xc);
  uVar2 = lma___aeabi_uidiv(param_3,uVar1 * 1000000);
  if (0x130 < uVar2 - 0x10) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006b10,0x16,DAT_10006b0c,DAT_10006b08);
  }
  if ((6 < param_4 - 1) || (6 < param_5 - 1)) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006b10,0x19,DAT_10006b0c,DAT_10006b14);
  }
  if (param_4 < param_5) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006b10,0x1f,DAT_10006b0c,DAT_10006b18);
  }
  if (param_3 >> 4 < uVar1) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10006b10,0x22,DAT_10006b0c,DAT_10006b1c);
  }
  uVar1 = param_4 << 0x10 | param_5 << 0xc;
  if ((((-1 < (int)*param_1) || ((*param_1 & 0x3f) != param_2)) || ((param_1[2] & 0xfff) != uVar2))
     || (uVar1 != 0)) {
    if (param_1 == DAT_10006af8) {
      uVar3 = 0x2000;
    }
    else {
      uVar3 = 0x1000;
    }
    *DAT_10006afc = uVar3;
    *DAT_10006b00 = uVar3;
    do {
    } while ((uVar3 & ~*(uint *)(DAT_10006b04 + 8)) != 0);
    *param_1 = param_2;
    param_1[2] = uVar2;
    *(undefined4 *)((uint)(param_1 + 1) | 0x3000) = 0x21;
    do {
    } while (-1 < (int)*param_1);
    param_1[3] = uVar1;
    *(undefined4 *)((uint)(param_1 + 1) | 0x3000) = 8;
  }
  return;
}


/* ===== lma_watchdog_start_tick @ 10006b20 (12 bytes) ===== */

void lma_watchdog_start_tick(uint param_1)

{
  *(uint *)(DAT_10006b2c + 0x2c) = param_1 | 0x200;
  return;
}


/* ===== lma_watchdog_update @ 10006b30 (10 bytes) ===== */

void lma_watchdog_update(void)

{
  *(undefined4 *)(DAT_10006b40 + 4) = *DAT_10006b3c;
  return;
}


/* ===== lma__watchdog_enable @ 10006b44 (96 bytes) ===== */

void lma__watchdog_enable(int param_1,int param_2)

{
  *DAT_10006ba4 = 0x40000000;
  *DAT_10006ba8 = DAT_10006bac;
  if (param_2 == 0) {
    *DAT_10006ba4 = 0x7000000;
  }
  else {
    *DAT_10006bb0 = 0x7000000;
  }
  if (param_1 == 0) {
    *DAT_10006bb0 = 0x80000000;
  }
  else {
    *DAT_10006bb4 = param_1 * 2000;
    if (0xffffff < (uint)(param_1 * 2000)) {
      *DAT_10006bb4 = DAT_10006bb8;
    }
    lma_watchdog_update();
    *DAT_10006bb0 = 0x40000000;
  }
  return;
}


/* ===== lma_watchdog_enable @ 10006bbc (14 bytes) ===== */

void lma_watchdog_enable(void)

{
  *(undefined4 *)(DAT_10006bcc + 0x1c) = DAT_10006bd0;
  lma__watchdog_enable();
  return;
}


/* ===== lma_watchdog_caused_reboot @ 10006bd4 (12 bytes) ===== */

bool lma_watchdog_caused_reboot(void)

{
  return *(int *)(DAT_10006be0 + 8) != 0;
}


/* ===== lma_xosc_init @ 10006be4 (28 bytes) ===== */

void lma_xosc_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_10006c00;
  *DAT_10006c00 = 0xaa0;
  puVar1[3] = 0x2f;
  *DAT_10006c04 = DAT_10006c08;
  do {
  } while (-1 < (int)DAT_10006c00[1]);
  return;
}


/* ===== lma__atoi @ 10006c1c (36 bytes) ===== */

int lma__atoi(byte **param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  while (pbVar2 = *param_1, (byte)(*pbVar2 - 0x30) < 10) {
    *param_1 = pbVar2 + 1;
    iVar1 = (uint)*pbVar2 + iVar1 * 10 + -0x30;
  }
  return iVar1;
}


/* ===== lma__out_rev @ 10006c40 (174 bytes) ===== */

int lma__out_rev(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                uint param_6,uint param_7,uint param_8)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_3;
  uVar1 = param_6;
  if ((param_8 & 3) == 0) {
    for (; uVar1 < param_7; uVar1 = uVar1 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
    }
  }
  while (param_6 != 0) {
    param_6 = param_6 - 1;
    (*param_1)(*(undefined *)(param_5 + param_6),param_2,iVar2,param_4);
    iVar2 = iVar2 + 1;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    for (; (uint)(iVar2 - param_3) < param_7; iVar2 = iVar2 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4);
    }
  }
  return iVar2;
}


/* ===== lma__ntoa_format @ 10006cee (274 bytes) ===== */

void lma__ntoa_format(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     int param_5,uint param_6,char param_7,int param_8,uint param_9,uint param_10,
                     uint param_11)

{
  uint uVar1;
  
  if (-1 < (int)(param_11 << 0x1e)) {
    if (((param_10 != 0) && ((int)(param_11 << 0x1f) < 0)) &&
       ((param_7 != '\0' || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 < 0x20)); param_6 = param_6 + 1) {
      *(undefined *)(param_5 + param_6) = 0x30;
    }
    for (; (((int)(param_11 << 0x1f) < 0 && (param_6 < param_10)) && (param_6 < 0x20));
        param_6 = param_6 + 1) {
      *(undefined *)(param_5 + param_6) = 0x30;
    }
  }
  uVar1 = param_6;
  if ((int)(param_11 << 0x1b) < 0) {
    if ((((-1 < (int)(param_11 << 0x15)) && (param_6 != 0)) &&
        ((param_6 == param_9 || (param_6 == param_10)))) &&
       ((uVar1 = param_6 - 1, param_6 != 1 && (param_8 == 0x10)))) {
      uVar1 = param_6 - 2;
    }
    if (((param_8 == 0x10) && (-1 < (int)(param_11 << 0x1a))) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x78;
      uVar1 = uVar1 + 1;
    }
    else if (((param_8 == 0x10) && ((int)(param_11 << 0x1a) < 0)) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x58;
      uVar1 = uVar1 + 1;
    }
    else if ((param_8 == 2) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x62;
      uVar1 = uVar1 + 1;
    }
    if (uVar1 < 0x20) {
      *(undefined *)(param_5 + uVar1) = 0x30;
      uVar1 = uVar1 + 1;
    }
  }
  if (uVar1 < 0x20) {
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        *(undefined *)(param_5 + uVar1) = 0x2b;
        uVar1 = uVar1 + 1;
      }
      else if ((int)(param_11 << 0x1c) < 0) {
        *(undefined *)(param_5 + uVar1) = 0x20;
        uVar1 = uVar1 + 1;
      }
    }
    else {
      *(undefined *)(param_5 + uVar1) = 0x2d;
      uVar1 = uVar1 + 1;
    }
  }
  lma__out_rev(param_1,param_2,param_3,param_4,param_5,uVar1,param_10,param_11);
  return;
}


/* ===== lma__ntoa_long @ 10006e00 (188 bytes) ===== */

void lma__ntoa_long(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   uint param_5,undefined param_6,uint param_7,undefined4 param_8,undefined4 param_9
                   ,uint param_10)

{
  uint uVar1;
  byte extraout_r1;
  char cVar2;
  uint uVar3;
  char local_48 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  uVar1 = param_10 & 0x400;
  if ((param_10 & 0x400) != 0) {
    if (param_5 == 0) {
      uVar3 = 0;
      goto LAB_10006e8a;
    }
    uVar1 = 0;
  }
  do {
    lma___aeabi_uidiv(param_5,param_7);
    if (extraout_r1 < 10) {
      cVar2 = extraout_r1 + 0x30;
    }
    else {
      if ((int)(param_10 << 0x1a) < 0) {
        cVar2 = 'A';
      }
      else {
        cVar2 = 'a';
      }
      cVar2 = cVar2 + extraout_r1 + -10;
    }
    uVar3 = uVar1 + 1;
    local_48[uVar1] = cVar2;
    uVar1 = lma___aeabi_uidiv(param_5,param_7);
  } while ((param_7 <= param_5) && (param_5 = uVar1, uVar1 = uVar3, uVar3 < 0x20));
LAB_10006e8a:
  lma__ntoa_format(param_1,param_2,param_3,param_4,local_48,uVar3,param_6,param_7,param_8,param_9,
                   param_10);
  return;
}


/* ===== lma__ntoa_long_long @ 10006ebc (226 bytes) ===== */

void lma__ntoa_long_long(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,uint param_5,uint param_6,undefined param_7,undefined4 param_8,uint param_9
                        ,uint param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  char local_48 [36];
  
  if ((param_5 | param_6) == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  uVar5 = param_13 & 0x400;
  uVar6 = CONCAT44(param_6,param_5);
  if ((param_13 & 0x400) != 0) {
    if ((param_5 | param_6) == 0) {
      uVar2 = 0;
      goto LAB_10006f68;
    }
    uVar5 = 0;
    uVar6 = CONCAT44(param_6,param_5);
  }
  do {
    uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar4 = (uint)uVar6;
    uVar2 = param_9;
    lma___aeabi_uldivmod(uVar4,uVar3,param_9,param_10);
    if ((uVar2 & 0xff) < 10) {
      cVar1 = (char)uVar2 + '0';
    }
    else {
      if ((int)(param_13 << 0x1a) < 0) {
        cVar1 = 'A';
      }
      else {
        cVar1 = 'a';
      }
      cVar1 = cVar1 + (char)uVar2 + -10;
    }
    uVar2 = uVar5 + 1;
    local_48[uVar5] = cVar1;
    uVar6 = lma___aeabi_uldivmod(uVar4,uVar3,param_9,param_10);
  } while ((param_10 < uVar3 || param_10 == uVar3) &&
          (((param_10 != uVar3 || (param_9 <= uVar4)) && (uVar5 = uVar2, uVar2 < 0x20))));
LAB_10006f68:
  lma__ntoa_format(param_1,param_2,param_3,param_4,local_48,uVar2,param_7,param_9,param_11,param_12,
                   param_13);
  return;
}


/* ===== lma__etoa @ 10006fa0 (936 bytes) ===== */

int lma__etoa(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
             uint param_6,int param_7,uint param_8,uint param_9)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 local_50;
  uint local_4c;
  
  iVar1 = lma___wrap___aeabi_dcmpun(param_5,param_6,param_5,param_6);
  if (((iVar1 == 0) &&
      (iVar1 = lma___wrap___aeabi_dcmpgt(param_5,param_6,0xffffffff,DAT_10007334), iVar1 == 0)) &&
     (iVar1 = lma___wrap___aeabi_dcmplt(param_5,param_6,0xffffffff,DAT_10007338), iVar1 == 0)) {
    iVar1 = lma___wrap___aeabi_dcmplt(param_5,param_6,0,0);
    if (iVar1 == 0) {
      local_4c = param_6;
    }
    else {
      local_4c = param_6 + 0x80000000;
    }
    uVar14 = CONCAT44(local_4c,param_5);
    if ((param_9 & 0x400) == 0) {
      param_7 = 6;
    }
    if ((local_4c | param_5) == 0) {
      uVar10 = 0;
      uVar6 = param_5;
      uVar7 = local_4c;
    }
    else {
      uVar6 = DAT_10007340 | local_4c & 0xfffff;
      uVar11 = lma___wrap___aeabi_i2d((local_4c >> 0x14 & 0x7ff) + DAT_1000733c);
      uVar11 = lma___wrap___aeabi_dmul
                         ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_10007344,DAT_10007348);
      uVar11 = lma___wrap___aeabi_dadd
                         ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_1000734c,DAT_10007350);
      uVar12 = lma___wrap___aeabi_dsub(param_5,uVar6,0,DAT_10007354);
      uVar12 = lma___wrap___aeabi_dmul
                         ((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_10007358,DAT_1000735c);
      lma___wrap___aeabi_dadd
                ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                 (int)((ulonglong)uVar12 >> 0x20));
      uVar10 = lma___wrap___aeabi_d2iz__or__double2int_z();
      uVar11 = lma___wrap___aeabi_i2d();
      uVar8 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar12 = lma___wrap___aeabi_dmul((int)uVar11,uVar8,DAT_10007360,DAT_10007364);
      lma___wrap___aeabi_dadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_10007368);
      iVar1 = lma___wrap___aeabi_d2iz__or__double2int_z();
      uVar11 = lma___wrap___aeabi_dmul((int)uVar11,uVar8,DAT_1000736c,DAT_10007370);
      uVar12 = lma___wrap___aeabi_i2d(iVar1);
      uVar12 = lma___wrap___aeabi_dmul
                         ((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_10007374,DAT_10007378);
      uVar11 = lma___wrap___aeabi_dsub
                         ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
      uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar8 = (undefined4)uVar11;
      uVar11 = lma___wrap___aeabi_dmul(uVar8,uVar4,uVar8,uVar4);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar2 = (undefined4)uVar11;
      iVar1 = iVar1 + DAT_1000737c;
      uVar11 = lma___wrap___aeabi_dadd(uVar8,uVar4,uVar8,uVar4);
      uVar12 = lma___wrap___aeabi_dsub(0,0x40000000,uVar8,uVar4);
      uVar13 = lma___aeabi_ddiv(uVar2,uVar5,0,DAT_10007380);
      uVar13 = lma___wrap___aeabi_dadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,DAT_10007384);
      uVar13 = lma___aeabi_ddiv(uVar2,uVar5,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      uVar13 = lma___wrap___aeabi_dadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,DAT_10007388);
      uVar13 = lma___aeabi_ddiv(uVar2,uVar5,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      uVar12 = lma___wrap___aeabi_dadd
                         ((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar13,
                          (int)((ulonglong)uVar13 >> 0x20));
      uVar11 = lma___aeabi_ddiv((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                                (int)((ulonglong)uVar12 >> 0x20));
      uVar11 = lma___wrap___aeabi_dadd((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_10007340);
      uVar11 = lma___wrap___aeabi_dmul
                         ((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,iVar1 * 0x100000);
      uVar7 = (uint)((ulonglong)uVar11 >> 0x20);
      uVar6 = (uint)uVar11;
      iVar1 = lma___wrap___aeabi_dcmpgt(uVar6,uVar7,param_5,local_4c);
      if (iVar1 != 0) {
        uVar10 = uVar10 - 1;
        uVar11 = lma___aeabi_ddiv(uVar6,uVar7,0,DAT_10007384);
        uVar7 = (uint)((ulonglong)uVar11 >> 0x20);
        uVar6 = (uint)uVar11;
      }
    }
    if (uVar10 + 99 < 199) {
      uVar9 = 4;
    }
    else {
      uVar9 = 5;
    }
    if ((int)(param_9 << 0x14) < 0) {
      if (((uVar7 | uVar6) == 0) ||
         ((iVar1 = lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                             (param_5,local_4c,DAT_1000738c,DAT_10007390), iVar1 != 0 &&
          (iVar1 = lma___wrap___aeabi_dcmplt(param_5,local_4c,0,DAT_10007394), iVar1 != 0)))) {
        if ((int)uVar10 < param_7) {
          param_7 = (param_7 - uVar10) + -1;
        }
        else {
          param_7 = 0;
        }
        param_9 = param_9 | 0x400;
        uVar9 = 0;
        uVar10 = 0;
      }
      else if ((param_7 != 0) && ((param_9 & 0x400) != 0)) {
        param_7 = param_7 + -1;
      }
    }
    if (uVar9 < param_8) {
      iVar1 = param_8 - uVar9;
    }
    else {
      iVar1 = 0;
    }
    if (((param_9 & 2) != 0) && (uVar9 != 0)) {
      iVar1 = 0;
    }
    if (uVar10 != 0) {
      uVar14 = lma___aeabi_ddiv(param_5,local_4c,uVar6,uVar7);
    }
    local_4c = (uint)((ulonglong)uVar14 >> 0x20);
    local_50 = (undefined4)uVar14;
    iVar3 = lma___wrap___aeabi_dcmplt(param_5,param_6,0,0);
    if (iVar3 != 0) {
      local_4c = local_4c + -0x80000000;
    }
    iVar1 = lma__ftoa(param_1,param_2,param_3,param_4,local_50,local_4c,param_7,iVar1,
                      DAT_10007398 & param_9);
    if (uVar9 != 0) {
      if ((int)(param_9 << 0x1a) < 0) {
        uVar8 = 0x45;
      }
      else {
        uVar8 = 0x65;
      }
      (*param_1)(uVar8,param_2,iVar1,param_4);
      iVar1 = lma__ntoa_long(param_1,param_2,iVar1 + 1,param_4,
                             uVar10 + ((int)uVar10 >> 0x1f) ^ (int)uVar10 >> 0x1f,uVar10 >> 0x1f,10,
                             0,uVar9 - 1,5);
      if ((param_9 & 2) != 0) {
        for (; (uint)(iVar1 - param_3) < param_8; iVar1 = iVar1 + 1) {
          (*param_1)(0x20,param_2,iVar1,param_4);
        }
      }
    }
  }
  else {
    iVar1 = lma__ftoa(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return iVar1;
}


/* ===== lma__ftoa @ 100073b4 (812 bytes) ===== */

void lma__ftoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,uint param_7,uint param_8,uint param_9)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  char local_48 [36];
  
  uVar13 = CONCAT44(param_6,param_5);
  iVar2 = lma___wrap___aeabi_dcmpun(param_5,param_6);
  if (iVar2 == 0) {
    iVar2 = lma___wrap___aeabi_dcmplt(param_5,param_6,0xffffffff,DAT_100076e0);
    if (iVar2 == 0) {
      iVar2 = lma___wrap___aeabi_dcmpgt(param_5,param_6,0xffffffff,DAT_100076e4);
      if (iVar2 == 0) {
        iVar2 = lma___wrap___aeabi_dcmpgt(param_5,param_6,0,DAT_100076e8);
        if ((iVar2 == 0) &&
           (iVar2 = lma___wrap___aeabi_dcmplt(param_5,param_6,0,DAT_100076ec), iVar2 == 0)) {
          iVar2 = lma___wrap___aeabi_dcmplt(param_5,param_6,0,0);
          bVar12 = iVar2 != 0;
          if (bVar12) {
            uVar13 = lma___wrap___aeabi_dsub(0,0,param_5,param_6);
          }
          param_6 = (undefined4)((ulonglong)uVar13 >> 0x20);
          param_5 = (undefined4)uVar13;
          if (-1 < (int)(param_9 << 0x15)) {
            param_7 = 6;
          }
          uVar10 = 0;
          for (; (uVar10 < 0x20 && (9 < param_7)); param_7 = param_7 - 1) {
            local_48[uVar10] = '0';
            uVar10 = uVar10 + 1;
          }
          iVar3 = lma___wrap___aeabi_d2iz__or__double2int_z(param_5,param_6);
          uVar13 = lma___wrap___aeabi_i2d();
          lma___wrap___aeabi_dsub(param_5,param_6,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
          puVar8 = (undefined4 *)(DAT_10007700 + param_7 * 8);
          uVar6 = *puVar8;
          uVar9 = puVar8[1];
          uVar13 = lma___wrap___aeabi_dmul();
          uVar4 = lma___wrap___aeabi_d2uiz__or__double2uint();
          uVar14 = lma___wrap___aeabi_ui2d();
          uVar13 = lma___wrap___aeabi_dsub
                             ((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                              (int)((ulonglong)uVar14 >> 0x20));
          uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
          iVar2 = lma___wrap___aeabi_dcmpgt((int)uVar13,uVar7,0,DAT_10007704);
          if (iVar2 == 0) {
            iVar2 = lma___wrap___aeabi_dcmplt((int)uVar13,uVar7,0,DAT_10007704);
            if ((iVar2 == 0) && ((uVar4 == 0 || ((int)(uVar4 << 0x1f) < 0)))) {
              uVar4 = uVar4 + 1;
            }
          }
          else {
            uVar4 = uVar4 + 1;
            uVar13 = lma___wrap___aeabi_ui2d(uVar4);
            iVar2 = lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                              (uVar6,uVar9,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
            if (iVar2 != 0) {
              iVar3 = iVar3 + 1;
              uVar4 = 0;
            }
          }
          if (param_7 == 0) {
            uVar13 = lma___wrap___aeabi_i2d(iVar3);
            uVar13 = lma___wrap___aeabi_dsub
                               (param_5,param_6,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
            uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
            iVar2 = lma___wrap___aeabi_dcmplt((int)uVar13,uVar7,0,DAT_10007704);
            if (((iVar2 == 0) &&
                (iVar2 = lma___wrap___aeabi_dcmpgt((int)uVar13,uVar7,0,DAT_10007704), iVar2 == 0))
               && (iVar3 << 0x1f < 0)) {
              iVar3 = iVar3 + 1;
            }
          }
          else {
            do {
              if (0x1f < uVar10) break;
              param_7 = param_7 - 1;
              lma___aeabi_uidiv(uVar4,10);
              uVar11 = uVar10 + 1;
              local_48[uVar10] = extraout_r1 + '0';
              uVar5 = lma___aeabi_uidiv(uVar4,10);
              bVar1 = 9 < uVar4;
              uVar10 = uVar11;
              uVar4 = uVar5;
            } while (bVar1);
            while ((uVar10 < 0x20 && (param_7 != 0))) {
              local_48[uVar10] = '0';
              uVar10 = uVar10 + 1;
              param_7 = param_7 - 1;
            }
            if (uVar10 < 0x20) {
              local_48[uVar10] = '.';
              uVar10 = uVar10 + 1;
            }
          }
          do {
            uVar4 = uVar10;
            if (0x1f < uVar10) break;
            lma___aeabi_idivmod(iVar3,10);
            uVar4 = uVar10 + 1;
            local_48[uVar10] = extraout_r1_00 + '0';
            iVar3 = lma___aeabi_idivmod(iVar3,10);
            uVar10 = uVar4;
          } while (iVar3 != 0);
          if ((param_9 & 3) == 1) {
            uVar10 = param_8;
            if ((param_8 != 0) && ((bVar12 || ((param_9 & 0xc) != 0)))) {
              param_8 = param_8 - 1;
              uVar10 = param_8;
            }
            for (; (uVar4 < uVar10 && (uVar4 < 0x20)); uVar4 = uVar4 + 1) {
              local_48[uVar4] = '0';
            }
          }
          if (uVar4 < 0x20) {
            if (bVar12) {
              local_48[uVar4] = '-';
              uVar4 = uVar4 + 1;
            }
            else if ((int)(param_9 << 0x1d) < 0) {
              local_48[uVar4] = '+';
              uVar4 = uVar4 + 1;
            }
            else if ((int)(param_9 << 0x1c) < 0) {
              local_48[uVar4] = ' ';
              uVar4 = uVar4 + 1;
            }
          }
          lma__out_rev(param_1,param_2,param_3,param_4,local_48,uVar4,param_8,param_9);
        }
        else {
          lma__etoa(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
        }
      }
      else {
        uVar7 = DAT_100076fc;
        if ((param_9 & 4) != 0) {
          uVar7 = DAT_100076f8;
        }
        if ((param_9 & 4) == 0) {
          uVar6 = 3;
        }
        else {
          uVar6 = 4;
        }
        lma__out_rev(param_1,param_2,param_3,param_4,uVar7,uVar6,param_8,param_9);
      }
    }
    else {
      lma__out_rev(param_1,param_2,param_3,param_4,DAT_100076f4,4,param_8,param_9);
    }
  }
  else {
    lma__out_rev(param_1,param_2,param_3,param_4,DAT_100076f0,3,param_8,param_9);
  }
  return;
}


/* ===== lma__vsnprintf @ 10007708 (342 bytes) ===== */

uint lma__vsnprintf(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *local_2c [2];
  
  if (param_2 == 0) {
    param_1 = DAT_10007d28;
  }
  uVar3 = 0;
  local_2c[0] = param_4;
  while( true ) {
    while( true ) {
      bVar1 = *local_2c[0];
      if (bVar1 == 0) {
        uVar2 = uVar3;
        if (param_3 <= uVar3) {
          uVar2 = param_3 - 1;
        }
        (*param_1)(0,param_2,uVar2,param_3);
        return uVar3;
      }
      if (bVar1 == 0x25) break;
      (*param_1)(bVar1,param_2,uVar3,param_3);
      local_2c[0] = local_2c[0] + 1;
      uVar3 = uVar3 + 1;
    }
    pbVar5 = local_2c[0] + 1;
    bVar1 = *pbVar5;
    uVar2 = (uint)(byte)(bVar1 - 0x20);
    if (uVar2 < 0x11) break;
    if ((byte)(bVar1 - 0x30) < 10) {
      local_2c[0] = pbVar5;
      uVar2 = lma__atoi(local_2c);
      pbVar5 = local_2c[0];
    }
    else if (bVar1 == 0x2a) {
      uVar2 = *param_5;
      param_5 = param_5 + 1;
      pbVar5 = local_2c[0] + 2;
    }
    local_2c[0] = pbVar5;
    pbVar5 = local_2c[0];
    if (*local_2c[0] == 0x2e) {
      if ((byte)(local_2c[0][1] - 0x30) < 10) {
        local_2c[0] = local_2c[0] + 1;
        uVar2 = lma__atoi(local_2c);
        pbVar5 = local_2c[0];
      }
      else {
        pbVar5 = local_2c[0] + 1;
        if (local_2c[0][1] == 0x2a) {
          uVar2 = *param_5;
          if ((int)uVar2 < 0) {
            uVar2 = 0;
          }
          param_5 = param_5 + 1;
          pbVar5 = local_2c[0] + 2;
        }
      }
    }
    local_2c[0] = pbVar5;
    uVar4 = *local_2c[0] - 0x68 & 0xff;
    if (uVar4 < 0x13) {
                    /* WARNING: Could not recover jumptable at 0x10007796. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(DAT_10007aa8 + uVar4 * 4))(uVar2);
      return uVar3;
    }
    uVar2 = (uint)(byte)(*local_2c[0] - 0x25);
    if (uVar2 < 0x54) {
                    /* WARNING: Could not recover jumptable at 0x10007894. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(DAT_10007aac + uVar2 * 4))();
      return uVar3;
    }
    (*param_1)(*local_2c[0],param_2,uVar3,param_3);
    local_2c[0] = local_2c[0] + 1;
    uVar3 = uVar3 + 1;
  }
  local_2c[0] = pbVar5;
                    /* WARNING: Could not recover jumptable at 0x10007764. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(DAT_10007aa4 + uVar2 * 4))();
  return uVar3;
}


/* ===== lma_vfctprintf @ 10007d2c (28 bytes) ===== */

void lma_vfctprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_1;
  local_c = param_2;
  lma__vsnprintf(DAT_10007d48,&local_10,0xffffffff,param_3,param_4);
  return;
}


/* ===== lma___aeabi_idivmod @ 10007db4 (32 bytes) ===== */

ulonglong lma___aeabi_idivmod(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  
  iVar2 = DAT_10007e00;
  if ((*(uint *)(DAT_10007e00 + 0x78) >> 1 & 1) != 0) {
    uVar3 = *(undefined4 *)(DAT_10007e00 + 0x60);
    uVar4 = *(undefined4 *)(DAT_10007e00 + 100);
    uVar6 = *(undefined4 *)(DAT_10007e00 + 0x74);
    uVar5 = *(undefined4 *)(DAT_10007e00 + 0x70);
    uVar7 = lma_divmod_s32s32_unsafe();
    *(undefined4 *)(iVar2 + 0x60) = uVar3;
    *(undefined4 *)(iVar2 + 100) = uVar4;
    *(undefined4 *)(iVar2 + 0x74) = uVar6;
    *(undefined4 *)(iVar2 + 0x70) = uVar5;
    return uVar7;
  }
  *(uint *)(DAT_10007e00 + 0x68) = param_1;
  *(int *)(iVar2 + 0x6c) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(iVar2 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = ~((int)param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar1 = lma___aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== lma_divmod_s32s32_unsafe @ 10007dbc (44 bytes) ===== */

ulonglong lma_divmod_s32s32_unsafe(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  
  *(uint *)(param_3 + 0x68) = param_1;
  *(int *)(param_3 + 0x6c) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = ~((int)param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar1 = lma___aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== lma___aeabi_uidiv @ 10007e04 (32 bytes) ===== */

ulonglong lma___aeabi_uidiv(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  
  iVar2 = DAT_10007e4c;
  if ((*(uint *)(DAT_10007e4c + 0x78) >> 1 & 1) != 0) {
    uVar3 = *(undefined4 *)(DAT_10007e4c + 0x60);
    uVar4 = *(undefined4 *)(DAT_10007e4c + 100);
    uVar6 = *(undefined4 *)(DAT_10007e4c + 0x74);
    uVar5 = *(undefined4 *)(DAT_10007e4c + 0x70);
    uVar7 = lma_divmod_u32u32_unsafe();
    *(undefined4 *)(iVar2 + 0x60) = uVar3;
    *(undefined4 *)(iVar2 + 100) = uVar4;
    *(undefined4 *)(iVar2 + 0x74) = uVar6;
    *(undefined4 *)(iVar2 + 0x70) = uVar5;
    return uVar7;
  }
  *(int *)(DAT_10007e4c + 0x60) = param_1;
  *(int *)(iVar2 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(iVar2 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  uVar1 = lma___aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== lma_divmod_u32u32_unsafe @ 10007e0c (38 bytes) ===== */

ulonglong lma_divmod_u32u32_unsafe(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  *(int *)(param_3 + 0x60) = param_1;
  *(int *)(param_3 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  uVar1 = lma___aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== lma___aeabi_uldivmod @ 10007e88 (52 bytes) ===== */

void lma___aeabi_uldivmod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(uint *)(DAT_10007f8c + 0x78) >> 1 & 1) != 0) {
    do {
    } while ((*(uint *)(DAT_10007f8c + 0x78) & 1) == 0);
    uVar2 = *(undefined4 *)(DAT_10007f8c + 0x60);
    uVar3 = *(undefined4 *)(DAT_10007f8c + 100);
    uVar5 = *(undefined4 *)(DAT_10007f8c + 0x74);
    uVar4 = *(undefined4 *)(DAT_10007f8c + 0x70);
    lma_divmod_u64u64_unsafe(param_1,param_2,param_3);
    iVar1 = DAT_10007f8c;
    *(undefined4 *)(DAT_10007f8c + 0x60) = uVar2;
    *(undefined4 *)(iVar1 + 100) = uVar3;
    *(undefined4 *)(iVar1 + 0x74) = uVar5;
    *(undefined4 *)(iVar1 + 0x70) = uVar4;
    return;
  }
  lma_divmod_u64u64_unsafe(param_1,param_2,param_3);
  return;
}


/* ===== lma_divmod_u64u64_unsafe @ 10007f48 (796 bytes) ===== */

ulonglong lma_divmod_u64u64_unsafe(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  ulonglong uVar16;
  
  iVar2 = DAT_1000827c;
  iVar1 = DAT_100080b0;
  iVar6 = DAT_10007fec;
  iVar7 = DAT_10007f8c;
  if (param_2 == 0) {
    if (param_4 != 0) {
      return 0;
    }
    if (param_3 != 0) {
      *(uint *)(DAT_10007f8c + 0x60) = param_1;
      *(uint *)(iVar7 + 100) = param_3;
      return (ulonglong)*(uint *)(iVar7 + 0x70);
    }
    uVar8 = 0;
    if (param_1 == 0) goto LAB_10007f76;
  }
  else {
    if (param_4 != 0) {
      if (param_4 >> 0x10 != 0) {
        uVar8 = 0;
        if (param_4 + 1 != 0) {
          *(uint *)(DAT_1000827c + 100) = param_4 + 1;
          *(uint *)(iVar2 + 0x60) = param_2;
          uVar8 = *(uint *)(iVar2 + 0x70);
        }
        uVar9 = uVar8 * (param_3 & 0xffff);
        uVar5 = param_1 - uVar9;
        uVar10 = uVar8 * (param_3 >> 0x10);
        uVar9 = (((param_2 - uVar8 * (param_4 & 0xffff)) - (uint)(param_1 < uVar9)) -
                (uVar8 * (param_4 >> 0x10) * 0x10000 | uVar10 >> 0x10)) -
                (uint)(uVar5 < uVar10 * 0x10000);
        for (uVar5 = uVar5 + uVar10 * -0x10000;
            (param_4 <= uVar9 && ((uVar9 != param_4 || (param_3 <= uVar5))));
            uVar5 = uVar5 - param_3) {
          uVar9 = (uVar9 - param_4) - (uint)(uVar5 < param_3);
          uVar8 = uVar8 + 1;
        }
        return (ulonglong)uVar8;
      }
      uVar9 = 0;
      uVar8 = param_3;
      uVar5 = param_4;
      if (param_4 >> 8 == 0) {
        uVar5 = param_4 << 8 | param_3 >> 0x18;
        uVar8 = param_3 << 8;
        uVar9 = 8;
      }
      if (uVar5 >> 0xc == 0) {
        uVar5 = uVar5 << 4 | uVar8 >> 0x1c;
        uVar8 = uVar8 << 4;
        uVar9 = uVar9 + 4;
      }
      if (uVar5 >> 0xe == 0) {
        uVar5 = uVar5 << 2 | uVar8 >> 0x1e;
        uVar8 = uVar8 << 2;
        uVar9 = uVar9 + 2;
      }
      if (uVar5 >> 0xf == 0) {
        bVar14 = CARRY4(uVar8,uVar8);
        uVar8 = uVar8 * 2;
        uVar5 = uVar5 * 2 + (uint)bVar14;
        uVar9 = uVar9 + 1;
      }
      *(uint *)(DAT_1000827c + 100) = uVar5 * 2 + (uint)CARRY4(uVar8,uVar8) + 1;
      *(undefined4 *)(iVar2 + 0x60) = DAT_10008280;
      iVar7 = *(int *)(iVar2 + 0x70);
      uVar10 = iVar7 * (param_2 >> 0x10) >> 0x10;
      uVar11 = uVar10 * (uVar8 & 0xffff);
      if (param_1 < uVar11) {
        param_2 = param_2 - 1;
      }
      uVar3 = (param_1 - uVar11) - uVar11;
      if (param_1 - uVar11 < uVar11) {
        param_2 = param_2 - 1;
      }
      uVar12 = uVar10 * (uVar8 >> 0x10);
      uVar11 = uVar3 + uVar12 * -0x20000;
      uVar3 = ((param_2 + uVar10 * (uVar5 & 0xffff) * -2) - (uVar12 >> 0xf)) -
              (uint)(uVar3 < uVar12 * 0x20000);
      uVar12 = iVar7 * (uVar3 >> 3) >> 0x10;
      if (uVar9 < 0xc) {
        uVar8 = uVar12 >> (0xc - uVar9 & 0xff);
        iVar7 = (uVar10 << uVar9) * 2;
      }
      else {
        uVar13 = uVar12 * (uVar8 >> 0xc & 0xffff);
        uVar4 = uVar11 - uVar13;
        if (uVar11 < uVar13) {
          uVar3 = uVar3 - 1;
        }
        uVar8 = uVar12 * ((uVar8 >> 0xc | uVar5 << 0x14) >> 0x10);
        uVar11 = uVar4 + uVar8 * -0x10000;
        uVar3 = ((uVar3 - uVar12 * (uVar5 >> 0xc & 0xffff)) - (uVar8 >> 0x10)) -
                (uint)(uVar4 < uVar8 * 0x10000);
        uVar8 = iVar7 * (uVar11 >> 0x16 | uVar3 * 0x400) >> (0x29 - uVar9 & 0xff);
        iVar7 = uVar10 * 0x2000 + uVar12 << (uVar9 - 0xc & 0xff);
      }
      uVar10 = uVar8 * (param_3 & 0xffff);
      uVar5 = uVar11 - uVar10;
      uVar12 = uVar8 * (param_3 >> 0x10);
      uVar9 = uVar5 + uVar12 * -0x10000;
      uVar5 = (((uVar3 - uVar8 * (param_4 & 0xffff)) - (uint)(uVar11 < uVar10)) - (uVar12 >> 0x10))
              - (uint)(uVar5 < uVar12 * 0x10000);
      uVar8 = iVar7 + uVar8;
      do {
        uVar11 = uVar8;
        bVar15 = param_3 <= uVar9;
        uVar9 = uVar9 - param_3;
        uVar10 = uVar5 - param_4;
        bVar14 = param_4 < uVar5;
        uVar5 = (uVar5 - param_4) - (uint)!bVar15;
        uVar8 = uVar11 + 1;
      } while (bVar14 || uVar10 < bVar15);
      return (ulonglong)uVar11;
    }
    if (param_3 >> 0x10 != 0) {
      uVar5 = 0;
      uVar8 = param_3;
      if (param_3 >> 0x18 == 0) {
        uVar8 = param_3 << 8;
        uVar5 = 8;
      }
      if (uVar8 >> 0x1c == 0) {
        uVar8 = uVar8 << 4;
        uVar5 = uVar5 + 4;
      }
      if (uVar8 >> 0x1e == 0) {
        uVar8 = uVar8 << 2;
        uVar5 = uVar5 + 2;
      }
      if (-1 < (int)uVar8) {
        uVar8 = uVar8 << 1;
        uVar5 = uVar5 + 1;
      }
      *(uint *)(DAT_100080b0 + 100) = (uVar8 >> 0xf) + 1;
      *(undefined4 *)(iVar1 + 0x60) = DAT_100080b4;
      iVar6 = *(int *)(iVar1 + 0x70);
      uVar11 = iVar6 * (param_2 >> 0x10) >> 0x10;
      uVar10 = uVar11 * (uVar8 & 0xffff);
      uVar9 = param_1 + uVar10 * -0x20000;
      uVar12 = ((param_2 - (uVar10 >> 0xf)) - (uint)(param_1 < uVar10 * 0x20000)) +
               uVar11 * (uVar8 >> 0x10) * -2;
      uVar13 = iVar6 * (uVar12 >> 3) >> 0x10;
      uVar3 = uVar11 * 0x2000 + uVar13;
      uVar4 = uVar13 * (uVar8 & 0xffff);
      uVar10 = uVar9 + uVar4 * -0x10;
      uVar13 = uVar13 * (uVar8 >> 0x10);
      uVar11 = uVar10 + uVar13 * -0x100000;
      iVar7 = (((uVar12 - (uVar4 >> 0x1c)) - (uint)(uVar9 < uVar4 * 0x10)) - (uVar13 >> 0xc)) -
              (uint)(uVar10 < uVar13 * 0x100000);
      uVar9 = iVar6 * (uVar11 >> 0x16 | iVar7 * 0x400) >> 0x10;
      if (8 < uVar5) {
        uVar11 = uVar11 - uVar9 * (uVar8 >> 9);
        uVar8 = -uVar5 + 0x16;
        uVar10 = (iVar6 * (uVar11 >> 9) >> 0x10) >> (uVar8 & 0xff);
        uVar9 = ((uVar9 << 0xd) >> (uVar8 & 0xff)) + uVar10;
        uVar11 = uVar11 - param_3 * uVar10;
        uVar8 = uVar3 >> (-uVar5 + 0x1c & 0xff);
        uVar3 = uVar3 << uVar5 + 4;
        iVar7 = uVar3 + uVar9;
        if (CARRY4(uVar3,uVar9) == false) goto LAB_100080a6;
        do {
          uVar8 = uVar8 + 1;
LAB_100080a6:
          do {
            if (uVar11 < param_3) {
              return CONCAT44(uVar8,iVar7);
            }
            uVar11 = uVar11 - param_3;
            bVar14 = iVar7 != -1;
            iVar7 = iVar7 + 1;
          } while (bVar14);
        } while( true );
      }
      uVar9 = uVar9 >> (-uVar5 + 9 & 0xff);
      uVar10 = uVar9 * (param_3 & 0xffff);
      uVar8 = uVar11 - uVar10;
      if (uVar11 < uVar10) {
        iVar7 = iVar7 + -1;
      }
      uVar10 = uVar9 * (param_3 >> 0x10);
      uVar11 = uVar8 + uVar10 * -0x10000;
      iVar6 = (iVar7 - (uVar10 >> 0x10)) - (uint)(uVar8 < uVar10 * 0x10000);
      uVar8 = uVar3 >> (-uVar5 + 0x1c & 0xff);
      uVar3 = uVar3 << uVar5 + 4;
      iVar7 = uVar3 + uVar9;
      if (CARRY4(uVar3,uVar9) != false) {
        uVar8 = uVar8 + 1;
      }
      if (iVar6 == 0) {
        if (uVar11 < param_3) {
          return CONCAT44(uVar8,iVar7);
        }
        do {
          bVar14 = iVar7 == -1;
          iVar7 = iVar7 + 1;
          if (bVar14) {
            uVar8 = uVar8 + 1;
          }
          uVar11 = uVar11 - param_3;
LAB_1000810a:
        } while (param_3 <= uVar11);
        return CONCAT44(uVar8,iVar7);
      }
      do {
        bVar14 = iVar7 == -1;
        iVar7 = iVar7 + 1;
        if (bVar14) {
          uVar8 = uVar8 + 1;
        }
        bVar14 = uVar11 < param_3;
        uVar11 = uVar11 - param_3;
        if ((bVar14) && (iVar6 = iVar6 + -1, iVar6 == 0)) goto LAB_1000810a;
      } while( true );
    }
    if (param_3 != 0) {
      *(uint *)(DAT_10007fec + 0x60) = param_2;
      *(uint *)(iVar6 + 100) = param_3;
      *(uint *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x74) << 0x10 | param_1 >> 0x10;
      *(uint *)(iVar6 + 100) = param_3;
      *(uint *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x74) << 0x10 | param_1 & 0xffff;
      *(uint *)(iVar6 + 100) = param_3;
      uVar8 = *(uint *)(iVar6 + 0x70) * 0x10000;
      return CONCAT44(*(int *)(iVar6 + 0x70) + (*(uint *)(iVar6 + 0x70) >> 0x10) +
                      (uint)CARRY4(*(uint *)(iVar6 + 0x70),uVar8),*(uint *)(iVar6 + 0x70) + uVar8);
    }
  }
  param_1 = DAT_10007f90;
  uVar8 = DAT_10007f90;
LAB_10007f76:
  uVar16 = lma___aeabi_idiv0(param_1,uVar8);
  return uVar16;
}


/* ===== lma___wrap___aeabi_dsub @ 1000828a (12 bytes) ===== */

void lma___wrap___aeabi_dsub(void)

{
  return;
}


/* ===== lma___wrap___aeabi_dadd @ 1000829c (12 bytes) ===== */

void lma___wrap___aeabi_dadd(void)

{
  return;
}


/* ===== lma___aeabi_ddiv @ 100082ae (42 bytes) ===== */

void lma___aeabi_ddiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(uint *)(DAT_10008300 + 0x78) >> 1 & 1) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(DAT_10008300 + 0x60);
  uVar3 = *(undefined4 *)(DAT_10008300 + 100);
  uVar5 = *(undefined4 *)(DAT_10008300 + 0x74);
  uVar4 = *(undefined4 *)(DAT_10008300 + 0x70);
  lma_double_shim_helper(param_1,param_2,param_3);
  iVar1 = DAT_10008300;
  *(undefined4 *)(DAT_10008300 + 0x60) = uVar2;
  *(undefined4 *)(iVar1 + 100) = uVar3;
  *(undefined4 *)(iVar1 + 0x74) = uVar5;
  *(undefined4 *)(iVar1 + 0x70) = uVar4;
  return;
}


/* ===== lma_double_shim_helper @ 100082ba (12 bytes) ===== */

void lma_double_shim_helper(void)

{
  return;
}


/* ===== lma___wrap___aeabi_dmul @ 100082ea (12 bytes) ===== */

void lma___wrap___aeabi_dmul(void)

{
  return;
}


/* ===== lma___wrap___aeabi_cdrcmple @ 10008304 (16 bytes) ===== */

undefined8 lma___wrap___aeabi_cdrcmple(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_4 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_10008326:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == DAT_1000836c) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_10008350;
    goto LAB_10008326;
  }
  uVar3 = (param_2 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_1000833a:
    uVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    uVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == DAT_1000836c) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_10008350;
      goto LAB_1000833a;
    }
  }
  if ((int)(uVar2 ^ param_4) < 0) {
    if (((uVar2 ^ param_4 | param_4) * 2 | param_3 | uVar1) != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)uVar2) && (param_4 == uVar2)) {
    return CONCAT44(param_2,param_1);
  }
LAB_10008350:
  return CONCAT44(param_2,param_1);
}


/* ===== lma___wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple @ 10008314 (86 bytes) ===== */

undefined8
lma___wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple
          (uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_10008326:
    uVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    uVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == DAT_1000836c) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_10008350;
      goto LAB_10008326;
    }
  }
  uVar3 = (param_4 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_1000833a:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == DAT_1000836c) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_10008350;
    goto LAB_1000833a;
  }
  if ((int)(param_4 ^ uVar2) < 0) {
    if (((param_4 ^ uVar2 | uVar2) * 2 | uVar1 | param_3) != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)param_4) && (uVar2 == param_4)) {
    return CONCAT44(param_2,param_1);
  }
LAB_10008350:
  return CONCAT44(param_2,param_1);
}


/* ===== lma___wrap___aeabi_dcmplt @ 10008370 (10 bytes) ===== */

int lma___wrap___aeabi_dcmplt(void)

{
  undefined in_CY;
  
  lma___wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple();
  return -(uint)!(bool)in_CY;
}


/* ===== lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple @ 1000837c (16 bytes) ===== */

undefined4 lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  lma___wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple();
  if ((bool)in_CY && !(bool)in_ZR) {
    return 0;
  }
  return 1;
}


/* ===== lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple @ 1000838c (16 bytes) ===== */

undefined4 lma___wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  lma___wrap___aeabi_cdrcmple();
  if ((bool)in_CY && !(bool)in_ZR) {
    return 0;
  }
  return 1;
}


/* ===== lma___wrap___aeabi_dcmpgt @ 1000839c (10 bytes) ===== */

int lma___wrap___aeabi_dcmpgt(void)

{
  undefined in_CY;
  
  lma___wrap___aeabi_cdrcmple();
  return -(uint)!(bool)in_CY;
}


/* ===== lma___wrap___aeabi_dcmpun @ 100083a6 (24 bytes) ===== */

undefined4 lma___wrap___aeabi_dcmpun(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if (((uint)(param_2 * 2) < 0xffe00001) && ((uint)(param_4 * 2) < 0xffe00001)) {
    return 0;
  }
  return 1;
}


/* ===== lma___wrap___aeabi_ui2d @ 100083c4 (8 bytes) ===== */

undefined8 lma___wrap___aeabi_ui2d(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (**DAT_100083f4)();
  uVar2 = param_1 << (iVar1 + 1U & 0xff);
  return CONCAT44((DAT_100083f8 - (iVar1 + 1U)) * 0x100000 | uVar2 >> 0xc,uVar2 << 0x14);
}


/* ===== lma___wrap___aeabi_i2d @ 100083cc (40 bytes) ===== */

longlong lma___wrap___aeabi_i2d(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = (param_1 ^ uVar3) - uVar3;
  if (iVar1 != 0) {
    iVar2 = (**DAT_100083f4)();
    uVar4 = iVar1 << (iVar2 + 1U & 0xff);
    return CONCAT44((DAT_100083f8 - (iVar2 + 1U)) * 0x100000 | uVar3 << 0x1f | uVar4 >> 0xc,
                    uVar4 << 0x14);
  }
  return (ulonglong)uVar3 << 0x20;
}


/* ===== lma___wrap___aeabi_d2iz__or__double2int_z @ 100083fc (72 bytes) ===== */

int lma___wrap___aeabi_d2iz__or__double2int_z(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)(param_2 << 1) >> 0x15;
  iVar3 = uVar2 - 0x380;
  if (iVar3 < 0x7f) {
    return 0;
  }
  if (iVar3 < 0x9e) {
    uVar2 = -(uVar2 - 0x41e);
    uVar1 = ((uint)(param_2 << 0xc) >> 1 | 0x80000000) >> (uVar2 & 0xff);
    iVar3 = (param_2 >> 0x1f) * 2 + 1;
    uVar2 = uVar2 + 0x15;
    if ((int)uVar2 < 0x20) {
      return iVar3 * (param_1 >> (uVar2 & 0xff) | uVar1);
    }
    return iVar3 * uVar1;
  }
  return 0x7fffffff - (param_2 >> 0x1f);
}


/* ===== lma___wrap___aeabi_d2uiz__or__double2uint @ 10008444 (12 bytes) ===== */

void lma___wrap___aeabi_d2uiz__or__double2uint(void)

{
  return;
}


/* ===== lma___wrap___aeabi_lmul @ 10008a8c (50 bytes) ===== */

undefined8 lma___wrap___aeabi_lmul(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (param_3 >> 0x10) * (param_1 & 0xffff);
  uVar1 = (param_3 & 0xffff) * (param_1 & 0xffff);
  uVar3 = (param_1 >> 0x10) * (param_3 & 0xffff);
  uVar6 = uVar4 * 0x10000;
  uVar2 = uVar1 + uVar6;
  uVar5 = uVar3 * 0x10000;
  return CONCAT44((param_1 >> 0x10) * (param_3 >> 0x10) + (uVar4 >> 0x10) +
                  (uint)CARRY4(uVar1,uVar6) + (uVar3 >> 0x10) + (uint)CARRY4(uVar2,uVar5) +
                  param_3 * param_2 + param_1 * param_4,uVar2 + uVar5);
}


/* ===== lma_memset @ 10008c00 (6 bytes) ===== */

void lma_memset(void)

{
                    /* WARNING: Could not recover jumptable at 0x10008c04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**DAT_10008c08)();
  return;
}


/* ===== lma_memcpy @ 10008c0c (6 bytes) ===== */

void lma_memcpy(void)

{
                    /* WARNING: Could not recover jumptable at 0x10008c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_10008c14 + 4))();
  return;
}


/* ===== lma_stdio_out_chars_crlf @ 10008c28 (124 bytes) ===== */

void lma_stdio_out_chars_crlf(code **param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    (**param_1)(param_2,param_3,param_3,*param_1,param_4);
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; iVar2 < param_3; iVar2 = iVar2 + 1) {
      if (iVar2 < 1) {
        cVar3 = *(char *)(param_1 + 4);
      }
      else {
        cVar3 = *(char *)(param_2 + iVar2 + -1) == '\r';
      }
      if ((*(char *)(param_2 + iVar2) == '\n') && (cVar3 == '\0')) {
        if (iVar1 < iVar2) {
          (**param_1)(param_2 + iVar1,iVar2 - iVar1);
        }
        (**param_1)(DAT_10008ca4,2);
        iVar1 = iVar2 + 1;
      }
    }
    if (iVar1 < param_3) {
      (**param_1)(param_2 + iVar1,param_3 - iVar1);
    }
    if (0 < param_3) {
      *(bool *)(param_1 + 4) = *(char *)(param_2 + param_3 + -1) == '\r';
    }
  }
  return;
}


/* ===== lma_stdio_stack_buffer_flush @ 10008ca8 (58 bytes) ===== */

void lma_stdio_stack_buffer_flush(int *param_1)

{
  int *piVar1;
  
  if (*param_1 != 0) {
    for (piVar1 = *DAT_10008ce4; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[3]) {
      if ((*piVar1 != 0) && ((*DAT_10008ce8 == (int *)0x0 || (*DAT_10008ce8 == piVar1)))) {
        lma_stdio_out_chars_crlf(piVar1,param_1 + 1,*param_1);
      }
    }
    *param_1 = 0;
  }
  return;
}


/* ===== lma_stdout_serialize_begin @ 10008d0c (42 bytes) ===== */

int lma_stdout_serialize_begin(void)

{
  int iVar1;
  int iVar2;
  int local_c;
  
  iVar2 = (int)(char)DAT_d0000000;
  iVar1 = lma_mutex_try_enter(DAT_10008d38,&local_c);
  if ((iVar1 == 0) && (iVar2 != local_c)) {
    lma_mutex_enter_blocking(DAT_10008d38);
    iVar1 = 1;
  }
  return iVar1;
}


/* ===== lma_stdout_serialize_end @ 10008d3c (10 bytes) ===== */

void lma_stdout_serialize_end(void)

{
  lma_mutex_exit(DAT_10008d48);
  return;
}


/* ===== lma_stdio_put_string @ 10008d4c (136 bytes) ===== */

bool lma_stdio_put_string(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  undefined local_21 [5];
  
  iVar1 = lma_stdout_serialize_begin();
  if (param_2 == -1) {
    param_2 = lma_strlen(param_1);
  }
  pcVar3 = DAT_10008ddc;
  if (param_4 != 0) {
    pcVar3 = DAT_10008dd4;
  }
  for (piVar2 = *DAT_10008dd8; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    if ((*piVar2 != 0) &&
       (((*DAT_10008de0 == (int *)0x0 || (*DAT_10008de0 == piVar2)) &&
        ((*pcVar3)(piVar2,param_1,param_2), param_3 != 0)))) {
      local_21[0] = 10;
      (*pcVar3)(piVar2,local_21,1);
    }
  }
  if (iVar1 != 0) {
    lma_stdout_serialize_end();
  }
  return param_2 != 0;
}


/* ===== lma_stdio_set_driver_enabled @ 10008de4 (52 bytes) ===== */

void lma_stdio_set_driver_enabled(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_10008e18;
  iVar2 = *DAT_10008e18;
  while( true ) {
    if (iVar2 == 0) {
      if (param_2 != 0) {
        if (iVar1 == 0) {
          *DAT_10008e18 = param_1;
        }
        else {
          *(int *)(iVar1 + 0xc) = param_1;
        }
      }
      return;
    }
    if (iVar2 == param_1) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  if (param_2 != 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


/* ===== lma_stdio_flush @ 10008e1c (26 bytes) ===== */

void lma_stdio_flush(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_10008e38; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))();
    }
  }
  return;
}


/* ===== lma___wrap_puts @ 10008e3c (30 bytes) ===== */

undefined4 lma___wrap_puts(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = lma_strlen();
  lma_stdio_put_string(param_1,uVar1,1,0);
  lma_stdio_flush();
  return uVar1;
}


/* ===== lma___wrap_vprintf @ 10008e5c (64 bytes) ===== */

undefined4 lma___wrap_vprintf(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_94 [132];
  
  iVar1 = lma_stdout_serialize_begin();
  lma_memset(auStack_94,0,0x84);
  uVar2 = lma_vfctprintf(DAT_10008e9c,auStack_94,param_1,param_2);
  lma_stdio_stack_buffer_flush(auStack_94);
  lma_stdio_flush();
  if (iVar1 != 0) {
    lma_stdout_serialize_end();
  }
  return uVar2;
}


/* ===== lma___wrap_printf @ 10008ea0 (24 bytes) ===== */

void lma___wrap_printf(undefined4 param_1)

{
  lma___wrap_vprintf(param_1);
  return;
}


/* ===== lma_stdio_uart_out_chars @ 10008eb8 (104 bytes) ===== */

void lma_stdio_uart_out_chars(int param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  byte local_19 [5];
  
  for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
    puVar4 = *DAT_10008f20;
    bVar1 = *(byte *)(param_1 + iVar5);
    if (*(ushort *)((uint)((int)puVar4 + DAT_10008f24 == 0) * 2 + DAT_10008f28) == (ushort)bVar1) {
      pbVar3 = local_19;
      local_19[0] = 0xd;
      bVar2 = false;
      while (!bVar2) {
        do {
        } while ((int)(puVar4[6] << 0x1a) < 0);
        *puVar4 = (uint)*pbVar3;
        pbVar3 = pbVar3 + 1;
        bVar2 = true;
      }
    }
    pbVar3 = local_19;
    local_19[0] = bVar1;
    bVar2 = false;
    while (!bVar2) {
      do {
      } while ((int)(puVar4[6] << 0x1a) < 0);
      *puVar4 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
      bVar2 = true;
    }
  }
  return;
}


/* ===== lma_stdio_uart_in_chars @ 10008f2c (82 bytes) ===== */

int lma_stdio_uart_in_chars(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined local_19 [5];
  
  iVar2 = 0;
  while (iVar2 < param_2) {
    puVar4 = (undefined4 *)*DAT_10008f80;
    uVar3 = puVar4[6] & 0x10;
    if ((puVar4[6] & 0x10) != 0) break;
    puVar1 = local_19;
    while (uVar3 == 0) {
      do {
      } while ((int)(puVar4[6] << 0x1b) < 0);
      *puVar1 = (char)*puVar4;
      puVar1 = puVar1 + 1;
      uVar3 = 1;
    }
    *(undefined *)(param_1 + iVar2) = local_19[0];
    iVar2 = iVar2 + 1;
  }
  if (iVar2 == 0) {
    iVar2 = -3;
  }
  return iVar2;
}


/* ===== lma_stdio_uart_init_full @ 10008f84 (52 bytes) ===== */

void lma_stdio_uart_init_full(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  *DAT_10008fb8 = param_1;
  lma_uart_init();
  if (-1 < param_3) {
    lma_gpio_set_function(param_3,2);
  }
  if (-1 < param_4) {
    lma_gpio_set_function(param_4,2);
  }
  lma_stdio_set_driver_enabled(DAT_10008fbc,1);
  return;
}


/* ===== lma_spi_set_baudrate @ 10008fc0 (146 bytes) ===== */

void lma_spi_set_baudrate(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar2 = lma_clock_get_hz(6);
  uVar1 = 2;
  do {
    uVar4 = uVar1;
    if (0xfe < uVar4) {
      uVar1 = 0x100;
      goto LAB_10009002;
    }
    uVar6 = lma___wrap___aeabi_lmul((uVar4 + 2) * 0x100,0,param_2,0);
  } while (((int)((ulonglong)uVar6 >> 0x20) == 0) && (uVar1 = uVar4 + 2, (uint)uVar6 <= uVar2));
  uVar1 = 0x100;
LAB_10009002:
  do {
    uVar5 = uVar1;
    if (uVar5 < 2) break;
    uVar3 = lma___aeabi_uidiv(uVar2,(uVar5 - 1) * uVar4);
    uVar1 = uVar5 - 1;
  } while (uVar3 <= param_2);
  param_1[4] = uVar4;
  *(uint *)((uint)param_1 | 0x1000) = ((uVar5 - 1) * 0x100 ^ *param_1) & 0xff00;
  lma___aeabi_uidiv(uVar2,uVar4 * uVar5);
  return;
}


/* ===== lma_spi_init @ 10009054 (86 bytes) ===== */

void lma_spi_init(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == DAT_100090ac) {
    uVar1 = 0x10000;
  }
  else {
    uVar1 = 0x20000;
  }
  *DAT_100090b0 = uVar1;
  *DAT_100090b4 = uVar1;
  do {
  } while ((uVar1 & ~*(uint *)(DAT_100090b8 + 8)) != 0);
  lma_spi_set_baudrate(param_1);
  *(uint *)((uint)param_1 | 0x1000) = (*param_1 ^ 7) & 0xcf;
  *(undefined4 *)((uint)(param_1 + 9) | 0x2000) = 3;
  *(undefined4 *)((uint)(param_1 + 1) | 0x2000) = 2;
  return;
}


/* ===== lma_i2c_set_baudrate @ 100090bc (214 bytes) ===== */

void lma_i2c_set_baudrate(uint **param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = lma_clock_get_hz(5);
  iVar2 = lma___aeabi_uidiv((param_2 >> 1) + iVar1,param_2);
  uVar5 = iVar2 * 3;
  uVar3 = lma___aeabi_uidiv(uVar5,5);
  if (DAT_10009194 < param_2) {
    iVar4 = lma___aeabi_uidiv(iVar1 * 3,DAT_1000919c);
  }
  else {
    iVar4 = lma___aeabi_uidiv(iVar1 * 3,DAT_10009198);
  }
  if (iVar4 + 1U <= uVar3 - 2) {
    (*param_1)[0x1b] = 0;
    *(uint *)((uint)*param_1 | 0x1000) = (**param_1 ^ 4) & 6;
    (*param_1)[7] = iVar2 - uVar3;
    (*param_1)[8] = uVar3;
    if (uVar5 < 0x50) {
      uVar5 = 1;
    }
    else {
      uVar5 = lma___aeabi_uidiv(uVar5,0x50);
    }
    (*param_1)[0x28] = uVar5;
    *(uint *)((uint)(*param_1 + 0x1f) | 0x1000) = (iVar4 + 1U ^ (*param_1)[0x1f]) & 0xffff;
    (*param_1)[0x1b] = 1;
    lma___aeabi_uidiv(iVar1,iVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100091a8,0x5f,DAT_100091a4,DAT_100091a0);
}


/* ===== lma_i2c_init @ 100091ac (70 bytes) ===== */

void lma_i2c_init(int *param_1)

{
  uint uVar1;
  
  if (param_1 == DAT_100091f4) {
    uVar1 = 8;
  }
  else {
    uVar1 = 0x10;
  }
  *DAT_100091f8 = uVar1;
  *DAT_100091fc = uVar1;
  do {
  } while ((uVar1 & ~*(uint *)(DAT_10009200 + 8)) != 0);
  *(undefined *)(param_1 + 1) = 0;
  *(undefined4 *)(*param_1 + 0x6c) = 0;
  *(undefined4 *)*param_1 = 0x165;
  *(undefined4 *)(*param_1 + 0x3c) = 0;
  *(undefined4 *)(*param_1 + 0x38) = 0;
  *(undefined4 *)(*param_1 + 0x88) = 3;
  lma_i2c_set_baudrate();
  return;
}


/* ===== lma_multicore_fifo_push_blocking @ 10009212 (20 bytes) ===== */

void lma_multicore_fifo_push_blocking(undefined4 param_1)

{
  do {
  } while (-1 < DAT_d0000050 << 0x1e);
  DAT_d0000054 = param_1;
  return;
}


/* ===== lma_multicore_fifo_pop_blocking @ 10009226 (2 bytes) ===== */

undefined4 lma_multicore_fifo_pop_blocking(void)

{
  while (-1 < DAT_d0000050 << 0x1f) {
    WaitForEvent();
  }
  return DAT_d0000058;
}


/* ===== FUN_1000922a @ 1000922a (20 bytes) ===== */

undefined4 FUN_1000922a(void)

{
  while (-1 < DAT_d0000050 << 0x1f) {
    WaitForEvent();
  }
  return DAT_d0000058;
}


/* ===== lma_multicore_launch_core1_raw @ 1000923c (110 bytes) ===== */

void lma_multicore_launch_core1_raw(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_30 [7];
  
  uVar1 = lma_irq_is_enabled(0xf);
  lma_irq_set_enabled(0xf,0);
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 1;
  local_30[3] = param_3;
  local_30[4] = param_2;
  local_30[5] = param_1;
  uVar4 = 0;
  do {
    while( true ) {
      iVar3 = local_30[uVar4];
      if (iVar3 == 0) {
        do {
        } while (DAT_d0000050 << 0x1f < 0);
      }
      lma_multicore_fifo_push_blocking(iVar3);
      iVar2 = lma_multicore_fifo_pop_blocking();
      if (iVar3 == iVar2) break;
      uVar4 = 0;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 6);
  lma_irq_set_enabled(0xf,uVar1);
  return;
}


/* ===== lma_multicore_launch_core1_with_stack @ 100092ac (56 bytes) ===== */

void lma_multicore_launch_core1_with_stack(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 & 3) == 0) {
    iVar1 = param_2 + (param_3 & 0xfffffffc);
    *(undefined4 *)(iVar1 + -0xc) = param_1;
    *(int *)(iVar1 + -8) = param_2;
    *(undefined4 *)(iVar1 + -4) = DAT_100092e4;
    lma_multicore_launch_core1_raw
              (DAT_100092ec,(undefined4 *)(iVar1 + -0xc),*(undefined4 *)(DAT_100092e8 + 8));
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100092f8,0x6e,DAT_100092f4,DAT_100092f0);
}


/* ===== lma_multicore_launch_core1 @ 100092fc (28 bytes) ===== */

void lma_multicore_launch_core1(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = DAT_10009318;
  if (DAT_10009318 < DAT_1000931c) {
    uVar1 = 0xffffffff;
  }
  lma_multicore_launch_core1_with_stack(param_1,uVar1,0x800);
  return;
}


/* ===== lma_get_dev_ep @ 10009320 (60 bytes) ===== */

int lma_get_dev_ep(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_1000935c;
  if ((param_2 & 0x7f) != 0) {
    for (uVar2 = 1; uVar2 < 0x10; uVar2 = uVar2 + 1) {
      iVar1 = uVar2 * 0x24 + DAT_1000935c;
      if (((*(char *)(uVar2 * 0x24 + DAT_1000935c) != '\0') && (*(byte *)(iVar1 + 0x1f) == param_1))
         && (*(byte *)(iVar1 + 2) == param_2)) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== lma__next_free_interrupt_ep @ 10009360 (44 bytes) ===== */

int lma__next_free_interrupt_ep(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  iVar1 = 0;
  while( true ) {
    if (0xf < uVar2) {
      return iVar1;
    }
    iVar1 = uVar2 * 0x24 + DAT_1000938c;
    if (*(char *)(uVar2 * 0x24 + DAT_1000938c) == '\0') break;
    uVar2 = uVar2 + 1;
  }
  *(char *)(iVar1 + 0x20) = (char)uVar2 + -1;
  return iVar1;
}


/* ===== lma_next_free_interrupt_ep @ 10009390 (36 bytes) ===== */

int lma_next_free_interrupt_ep(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = 0xf;
      (iVar2 != 0 &&
      (iVar1 = iVar2 * 0x24 + DAT_100093b4, *(char *)(iVar2 * 0x24 + DAT_100093b4) != '\0'));
      iVar2 = iVar2 + -1) {
  }
  return iVar1;
}


/* ===== lma__hw_endpoint_allocate @ 100093b8 (122 bytes) ===== */

void lma__hw_endpoint_allocate(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_10009434;
  if (param_1 == 3) {
    iVar1 = lma__next_free_interrupt_ep();
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10009454,299,DAT_10009450,DAT_1000944c);
    }
    iVar2 = (uint)*(byte *)(iVar1 + 0x20) * 8;
    *(int *)(iVar1 + 8) = iVar2 + DAT_10009444;
    *(int *)(iVar1 + 4) = iVar2 + DAT_10009448;
    *(uint *)(iVar1 + 0xc) = (*(byte *)(iVar1 + 0x20) + 2) * 0x40 + DAT_10009440;
  }
  else if ((param_1 - 1U & 0xff) < 2) {
    iVar1 = lma_next_free_interrupt_ep();
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10009454,0x138,DAT_10009450,DAT_1000944c);
    }
    *(undefined4 *)(iVar1 + 8) = DAT_10009438;
    *(undefined4 *)(iVar1 + 4) = DAT_1000943c;
    *(int *)(iVar1 + 0xc) = DAT_10009440;
  }
  else {
    *(undefined4 *)(DAT_10009434 + 8) = DAT_10009438;
    *(undefined4 *)(iVar1 + 4) = DAT_1000943c;
    *(int *)(iVar1 + 0xc) = DAT_10009440;
  }
  return;
}


/* ===== lma__hw_endpoint_reinit_epx @ 10009458 (144 bytes) ===== */

void lma__hw_endpoint_reinit_epx(char *param_1)

{
  uint uVar1;
  
  if (*(uint **)(param_1 + 4) == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009500,DAT_100094fc,DAT_100094f8,DAT_100094f4);
  }
  if (*(int *)(param_1 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009500,DAT_10009508,DAT_100094f8,DAT_10009504);
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009500,0x214,DAT_100094f8,DAT_1000950c);
  }
  if (*param_1 != '\0') {
    if ((uVar1 & 0x3f) == 0) {
      **(uint **)(param_1 + 4) =
           (uint)(byte)param_1[0x1e] << 0x1a | DAT_100094e8 ^ uVar1 | 0xa0000000;
      if (*(int *)(DAT_100094ec + 0x50) << 3 < 0) {
        *(undefined4 *)(DAT_100094f0 + 0x50) = 0x10000000;
      }
      if (param_1[2] < '\0') {
        *(undefined4 *)(DAT_100094ec + 0x6c) = DAT_10009520;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009500,DAT_1000951c,DAT_100094f8,DAT_10009518);
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_10009500,DAT_10009514,DAT_100094f8,DAT_10009510);
}


/* ===== lma_hw_xfer_complete @ 10009524 (36 bytes) ===== */

void lma_hw_xfer_complete(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined2 uVar3;
  
  uVar1 = *(undefined *)(param_1 + 0x1f);
  uVar2 = *(undefined *)(param_1 + 2);
  uVar3 = *(undefined2 *)(param_1 + 0x14);
  lma_hw_endpoint_reset_transfer();
  lma_hcd_event_xfer_complete(uVar1,uVar2,uVar3,param_2,1);
  return;
}


/* ===== lma__handle_buff_status_bit @ 10009548 (30 bytes) ===== */

void lma__handle_buff_status_bit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(DAT_10009568 + 0x58) = param_1;
  iVar1 = lma_hw_endpoint_xfer_continue(param_2);
  if (iVar1 != 0) {
    lma_hw_xfer_complete(param_2,0);
  }
  return;
}


/* ===== lma_hw_handle_buff_status @ 1000956c (86 bytes) ===== */

void lma_hw_handle_buff_status(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_100095c4 + 0x58);
  if ((int)(uVar3 << 0x1f) < 0) {
    uVar3 = uVar3 & 0xfffffffe;
    lma__handle_buff_status_bit(1,*DAT_100095c8,param_3,**(undefined4 **)(*DAT_100095c8 + 4));
  }
  uVar2 = 1;
  while ((uVar2 < 0x10 && (uVar3 != 0))) {
    uVar1 = 1 << ((uVar2 & 0x7f) << 1);
    if ((uVar1 & uVar3) != 0) {
      uVar3 = uVar3 & ~uVar1;
      lma__handle_buff_status_bit(uVar1,uVar2 * 0x24 + DAT_100095cc);
    }
    uVar2 = uVar2 + 1;
  }
  if (uVar3 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma_panic(DAT_100095d0,uVar3);
}


/* ===== lma_hw_trans_complete @ 100095d4 (40 bytes) ===== */

void lma_hw_trans_complete(void)

{
  if (*(int *)(DAT_100095fc + 0x4c) << 0x1e < 0) {
    if (*(char *)(DAT_10009600 + 0x10) == '\0') {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_1000960c,0xb9,DAT_10009608,DAT_10009604);
    }
    lma_hw_xfer_complete(DAT_10009600,0);
  }
  return;
}


/* ===== lma_hcd_rp2040_irq @ 10009610 (168 bytes) ===== */

void lma_hcd_rp2040_irq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(DAT_100096b8 + 0x98);
  uVar2 = uVar1 & 1;
  if ((uVar1 & 1) != 0) {
    if ((*(uint *)(DAT_100096b8 + 0x50) >> 8 & 3) == 0) {
      lma_hcd_event_device_remove(0,1);
    }
    else {
      lma_hcd_event_device_attach(0,1);
    }
    *(undefined4 *)(DAT_100096bc + 0x50) = 0x300;
    uVar2 = 1;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    uVar2 = uVar2 | 0x10;
    lma_hw_handle_buff_status();
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    uVar2 = uVar2 | 8;
    *(undefined4 *)(DAT_100096bc + 0x50) = 0x40000;
    lma_hw_trans_complete();
  }
  if ((int)(uVar1 << 0x15) < 0) {
    uVar2 = uVar2 | 0x400;
    *(undefined4 *)(DAT_100096bc + 0x50) = 0x20000000;
    lma_hw_xfer_complete(DAT_100096c0,2);
  }
  if ((int)(uVar1 << 0x19) < 0) {
    uVar2 = uVar2 | 0x40;
    *(undefined4 *)(DAT_100096bc + 0x50) = 0x8000000;
  }
  if (-1 < (int)(uVar1 << 0x1a)) {
    if (uVar2 == uVar1) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    lma_panic(DAT_100096c8,uVar2 ^ uVar1);
  }
  *(undefined4 *)(DAT_100096bc + 0x50) = 0x80000000;
                    /* WARNING: Subroutine does not return */
  lma_panic(DAT_100096c4);
}


/* ===== lma_hcd_init @ 100096cc (68 bytes) ===== */

undefined4 lma_hcd_init(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    lma_rp2040_usb_init();
    iVar1 = DAT_10009710;
    *(undefined4 *)(DAT_10009710 + 0x78) = 0xc;
    lma_irq_set_exclusive_handler(5,PTR_hcd_rp2040_irq_1_10009714);
    lma_memset(PTR_DAT_10009718,0,0x240);
    *(undefined4 *)(iVar1 + 0x40) = 3;
    *(undefined **)(iVar1 + 0x4c) = PTR_DAT_1000971c;
    *(undefined4 *)(iVar1 + 0x90) = DAT_10009720;
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(PTR_s__Users_felix_mysrc_pico_sdk_lib__1000972c,0x18d,PTR_s_hcd_init_10009728,
                    PTR_s_rhport____0_10009724);
}


/* ===== lma_hcd_port_connect_status @ 10009754 (38 bytes) ===== */

bool lma_hcd_port_connect_status(int param_1)

{
  if (param_1 == 0) {
    return (*(uint *)(DAT_1000977c + 0x50) & 0x300) != 0;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(PTR_s__Users_felix_mysrc_pico_sdk_lib__10009788,0x1b2,
                    PTR_s_hcd_port_connect_status_10009784,PTR_s_rhport____0_10009780);
}


/* ===== lma_hcd_port_speed_get @ 1000978c (56 bytes) ===== */

uint lma_hcd_port_speed_get(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_100097d4,0x1b8,DAT_100097d0,DAT_100097cc);
  }
  uVar1 = *(uint *)(DAT_100097c4 + 0x50) >> 8 & 3;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      uVar1 = 0;
    }
    else {
      if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        lma_panic(DAT_100097c8);
      }
      uVar1 = 0xff;
    }
  }
  return uVar1;
}


/* ===== lma_need_pre @ 100097d8 (28 bytes) ===== */

bool lma_need_pre(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = lma_hcd_port_speed_get(0);
  iVar2 = lma_tuh_speed_get(param_1);
  return iVar1 != iVar2;
}


/* ===== lma__hw_endpoint_init @ 100097f4 (268 bytes) ===== */

void lma__hw_endpoint_init
               (undefined *param_1,uint param_2,uint param_3,undefined2 param_4,byte param_5,
               byte param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)param_6;
  if (*(uint **)(param_1 + 4) == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000990c,0x14b,DAT_10009908,DAT_10009904);
  }
  if (*(int *)(param_1 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000990c,0x14c,DAT_10009908,DAT_10009910);
  }
  if (*(uint *)(param_1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000990c,0x14d,DAT_10009908,DAT_10009914);
  }
  param_1[2] = (char)param_3;
  param_1[0x1f] = (char)param_2;
  param_1[1] = (char)(param_3 >> 7);
  param_1[3] = (param_3 & 0x7f) == 0;
  *(undefined2 *)(param_1 + 0x1c) = param_4;
  param_1[0x1e] = param_5;
  uVar4 = DAT_10009900 ^ *(uint *)(param_1 + 0xc);
  uVar3 = uVar4 & 0x3f;
  if ((uVar4 & 0x3f) == 0) {
    if (uVar1 != 0) {
      uVar3 = (uVar1 - 1) * 0x10000;
    }
    **(uint **)(param_1 + 4) = uVar3 | (uint)param_5 << 0x1a | uVar4 | 0xa0000000;
    *param_1 = 1;
    if ((uVar1 != 0) && (param_1[0x1e] == '\x03')) {
      uVar1 = (param_3 & 0x7f) << 0x10 | param_2;
      if (param_3 >> 7 != 1) {
                    /* WARNING: Subroutine does not return */
        lma___assert_func(DAT_1000990c,0x177,DAT_10009908,DAT_10009924);
      }
      iVar2 = lma_need_pre(param_2);
      if (iVar2 != 0) {
        uVar1 = uVar1 | 0x4000000;
      }
      *(uint *)((uint)(byte)param_1[0x20] * 4 + DAT_1000991c + 4) = uVar1;
      *(int *)(DAT_10009920 + 0x54) = 1 << ((byte)param_1[0x20] + 1 & 0xff);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_1000990c,0x161,DAT_10009908,DAT_10009918);
}


/* ===== lma_hcd_device_close @ 10009928 (114 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lma_hcd_device_close(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    *DAT_1000999c = 0x14;
    for (uVar3 = 1; iVar1 = _LAB_100099a0, uVar3 < 0x10; uVar3 = uVar3 + 1) {
      iVar2 = uVar3 * 0x24 + _LAB_100099a0;
      if ((*(byte *)(iVar2 + 0x1f) == param_2) && (*(char *)(uVar3 * 0x24 + _LAB_100099a0) != '\0'))
      {
        *(int *)(_LAB_100099a4 + 0x54) = 1 << (*(byte *)(iVar2 + 0x20) + 1 & 0xff);
        *(undefined4 *)((uint)*(byte *)(iVar2 + 0x20) * 4 + _LAB_100099a8 + 4) = 0;
        *(undefined *)(uVar3 * 0x24 + iVar1) = 0;
        **(undefined4 **)(iVar2 + 4) = 0;
        **(undefined4 **)(iVar2 + 8) = 0;
        lma_hw_endpoint_reset_transfer();
      }
    }
  }
  return;
}


/* ===== lma_hcd_int_enable @ 100099ac (30 bytes) ===== */

void lma_hcd_int_enable(int param_1)

{
  if (param_1 == 0) {
    lma_irq_set_enabled(5,1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_100099d4,0x1ec,DAT_100099d0,DAT_100099cc);
}


/* ===== lma_hcd_edpt_open @ 100099d8 (56 bytes) ===== */

undefined4 lma_hcd_edpt_open(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = lma__hw_endpoint_allocate(*(byte *)(param_3 + 3) & 3);
  lma__hw_endpoint_init
            (uVar1,param_2,*(undefined *)(param_3 + 2),
             (*(byte *)(param_3 + 5) & 7) << 8 | (uint)*(byte *)(param_3 + 4),
             *(byte *)(param_3 + 3) & 3,*(undefined *)(param_3 + 6));
  return 1;
}


/* ===== lma_hcd_edpt_xfer @ 10009a10 (298 bytes) ===== */

undefined4
lma_hcd_edpt_xfer(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5
                 )

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_3 & 0x7f;
  iVar3 = lma_get_dev_ep(param_2,param_3);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009b54,0x238,DAT_10009b50,DAT_10009b4c);
  }
  if (uVar5 == 0) {
    if ((*DAT_10009b3c != DAT_10009b40) || (*(byte *)(iVar3 + 2) != param_3)) {
      lma__hw_endpoint_init
                (iVar3,param_2,param_3,*(undefined2 *)(iVar3 + 0x1c),*(undefined *)(iVar3 + 0x1e),0)
      ;
    }
    *DAT_10009b3c = DAT_10009b40;
  }
  if (iVar3 == DAT_10009b40) {
    bVar1 = false;
  }
  else if ((byte)(*(char *)(iVar3 + 0x1e) - 1U) < 2) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (*DAT_10009b3c != iVar3) {
      lma__hw_endpoint_reinit_epx(iVar3);
    }
    *DAT_10009b3c = iVar3;
    lma_hw_endpoint_xfer_start(iVar3,param_4,param_5);
    *DAT_10009b44 = uVar5 << 0x10 | param_2;
    uVar5 = DAT_10009b58;
    if (param_3 >> 7 != 0) {
      uVar5 = DAT_10009b48;
    }
    iVar3 = lma_need_pre(param_2);
    puVar2 = DAT_10009b44;
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x40;
    }
    DAT_10009b44[0x13] = uVar4 | uVar5;
    puVar2[0x13] = uVar4 | uVar5 | 1;
  }
  else if (iVar3 == DAT_10009b40) {
    lma_hw_endpoint_xfer_start(iVar3,param_4,param_5);
    *DAT_10009b44 = uVar5 << 0x10 | param_2;
    uVar5 = DAT_10009b60;
    if (param_3 >> 7 != 0) {
      uVar5 = DAT_10009b5c;
    }
    iVar3 = lma_need_pre(param_2);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x40;
    }
    DAT_10009b44[0x13] = uVar5 | uVar4;
  }
  else {
    lma_hw_endpoint_xfer_start(iVar3,param_4,param_5);
  }
  return 1;
}


/* ===== lma_hcd_setup_send @ 10009b64 (96 bytes) ===== */

undefined4 lma_hcd_setup_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  lma_memcpy(DAT_10009bc4,param_3,8);
  pcVar1 = (char *)lma__hw_endpoint_allocate(0);
  lma__hw_endpoint_init(pcVar1,param_2,0,*(undefined2 *)(pcVar1 + 0x1c),0,0);
  if (*pcVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_10009bd8,0x284,DAT_10009bd4,DAT_10009bd0);
  }
  *(undefined2 *)(pcVar1 + 0x12) = 8;
  pcVar1[0x10] = '\x01';
  *DAT_10009bc8 = param_2;
  iVar2 = lma_need_pre(param_2);
  uVar3 = DAT_10009bdc;
  if (iVar2 != 0) {
    uVar3 = DAT_10009bcc;
  }
  DAT_10009bc8[0x13] = uVar3;
  return 1;
}


/* ===== lma_prepare_ep_buffer @ 10009be0 (120 bytes) ===== */

uint lma_prepare_ep_buffer(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x12);
  uVar3 = uVar1;
  if (*(ushort *)(param_1 + 0x1c) < uVar1) {
    uVar3 = *(ushort *)(param_1 + 0x1c);
  }
  uVar4 = (uint)uVar3;
  *(ushort *)(param_1 + 0x12) = uVar1 - uVar3;
  if (*(byte *)(param_1 + 3) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x2000;
  }
  uVar2 = uVar4 | 0x400 | uVar2;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ 1;
  if (*(char *)(param_1 + 1) == '\0') {
    lma_memcpy(param_2 * 0x40 + *(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18),uVar4,
               *(int *)(param_1 + 0xc),param_4);
    *(uint *)(param_1 + 0x18) = uVar4 + *(int *)(param_1 + 0x18);
    uVar2 = uVar2 | 0x8000;
  }
  if ((*(short *)(param_1 + 0x12) == 0) || (*(char *)(param_1 + 0x21) != '\0')) {
    uVar2 = uVar2 | 0x4000;
  }
  if (param_2 != 0) {
    uVar2 = uVar2 << 0x10;
  }
  return uVar2;
}


/* ===== lma_sync_ep_buffer @ 10009c58 (106 bytes) ===== */

uint lma_sync_ep_buffer(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = **(uint **)(param_1 + 8);
  if (param_2 != 0) {
    uVar1 = uVar1 >> 0x10;
  }
  uVar2 = uVar1 & 0x3ff;
  if (*(char *)(param_1 + 1) == '\0') {
    if ((int)(uVar1 << 0x10) < 0) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10009ccc,0xdb,DAT_10009cc8,DAT_10009cc4);
    }
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + (short)uVar2;
  }
  else {
    if (-1 < (int)(uVar1 << 0x10)) {
                    /* WARNING: Subroutine does not return */
      lma___assert_func(DAT_10009ccc,0xe2,DAT_10009cc8,DAT_10009cd0);
    }
    lma_memcpy(*(undefined4 *)(param_1 + 0x18),param_2 * 0x40 + *(int *)(param_1 + 0xc),uVar2);
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + (short)uVar2;
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar2;
  }
  if (uVar2 < *(ushort *)(param_1 + 0x1c)) {
    *(undefined2 *)(param_1 + 0x12) = 0;
  }
  return uVar2;
}


/* ===== lma__hw_endpoint_xfer_sync @ 10009cd4 (40 bytes) ===== */

void lma__hw_endpoint_xfer_sync(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = lma_sync_ep_buffer(param_1,0,param_3,**(undefined4 **)(param_1 + 8));
  if ((**(int **)(param_1 + 4) << 1 < 0) && (*(ushort *)(param_1 + 0x1c) == uVar1)) {
    lma_sync_ep_buffer(param_1,1);
  }
  return;
}


/* ===== lma_rp2040_usb_init @ 10009cfc (56 bytes) ===== */

void lma_rp2040_usb_init(void)

{
  int iVar1;
  
  *(undefined4 *)PTR_DAT_10009d34 = 0x1000000;
  *(undefined4 *)PTR_DAT_10009d38 = 0x1000000;
  iVar1 = DAT_10009d40;
  do {
  } while ((~*(uint *)(PTR_DAT_10009d3c + 8) & 0x1000000) != 0);
  lma_memset(DAT_10009d40,0,0x9c);
  lma_memset(DAT_10009d44,0,0x1000);
  *(undefined4 *)(iVar1 + 0x74) = 9;
  return;
}


/* ===== lma_hw_endpoint_reset_transfer @ 10009d48 (12 bytes) ===== */

void lma_hw_endpoint_reset_transfer(int param_1)

{
  *(undefined *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


/* ===== lma__hw_endpoint_buffer_control_update32 @ 10009d54 (62 bytes) ===== */

void lma__hw_endpoint_buffer_control_update32(int param_1,uint param_2,uint param_3)

{
  if (param_2 != 0) {
    param_2 = param_2 & **(uint **)(param_1 + 8);
  }
  if ((param_3 != 0) && (param_2 = param_2 | param_3, (int)(param_3 << 0x15) < 0)) {
    if ((int)(**(uint **)(param_1 + 8) << 0x15) < 0) {
                    /* WARNING: Subroutine does not return */
      lma_panic(DAT_10009d9c,*(byte *)(param_1 + 2) & 0x7f,
                *(undefined4 *)((uint)(*(byte *)(param_1 + 2) >> 7) * 4 + DAT_10009d98));
    }
    **(uint **)(param_1 + 8) = DAT_10009d94 & param_2;
  }
  **(uint **)(param_1 + 8) = param_2;
  return;
}


/* ===== lma__hw_endpoint_start_next_buffer @ 10009da0 (102 bytes) ===== */

void lma__hw_endpoint_start_next_buffer(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = **(uint **)(param_1 + 4);
  uVar2 = lma_prepare_ep_buffer(param_1,0);
  uVar2 = uVar2 | 0x1000;
  if (*(int *)(DAT_10009e08 + 0x40) << 0x1e < 0) {
    bVar1 = false;
  }
  else if (*(char *)(param_1 + 2) < '\0') {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((*(short *)(param_1 + 0x12) == 0) || (bVar1)) {
    uVar4 = uVar4 & DAT_10009e0c | 0x20000000;
  }
  else {
    uVar3 = lma_prepare_ep_buffer(param_1,1);
    uVar2 = uVar2 | uVar3;
    uVar4 = uVar4 & DAT_10009e10 | 0x50000000;
  }
  **(uint **)(param_1 + 4) = uVar4;
  lma__hw_endpoint_buffer_control_update32(param_1,0,uVar2);
  return;
}


/* ===== lma_hw_endpoint_xfer_start @ 10009e14 (62 bytes) ===== */

void lma_hw_endpoint_xfer_start(int param_1,undefined4 param_2,undefined2 param_3)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    lma___wrap_printf(DAT_10009e58,*(byte *)(param_1 + 2) & 0x7f,
                      *(undefined4 *)((uint)(*(byte *)(param_1 + 2) >> 7) * 4 + DAT_10009e54));
    lma_hw_endpoint_reset_transfer(param_1);
  }
  *(undefined2 *)(param_1 + 0x12) = param_3;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  lma__hw_endpoint_start_next_buffer(param_1);
  return;
}


/* ===== lma_hw_endpoint_xfer_continue @ 10009e5c (48 bytes) ===== */

char lma_hw_endpoint_xfer_continue(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 != '\0') {
    lma__hw_endpoint_xfer_sync();
    if (*(short *)(param_1 + 0x12) != 0) {
      lma__hw_endpoint_start_next_buffer(param_1);
      cVar1 = '\0';
    }
    return cVar1;
  }
                    /* WARNING: Subroutine does not return */
  lma_panic(DAT_10009e90,*(byte *)(param_1 + 2) & 0x7f,DAT_10009e8c);
}


/* ===== lma_get_new_address @ 10009e94 (80 bytes) ===== */

uint lma_get_new_address(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined *puVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    cVar5 = '\x01';
    bVar4 = 4;
  }
  else {
    cVar5 = '\x05';
    bVar4 = 1;
  }
  bVar2 = 0;
  uVar6 = param_4;
  while( true ) {
    if (bVar4 <= bVar2) {
      return 0xff;
    }
    uVar3 = (uint)(byte)(bVar2 + cVar5);
    if (uVar3 == 0) {
      lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_10009ee8,PTR_s_get_device_10009ee4,0xdc,param_4,
                        uVar6);
      puVar1 = (undefined *)0x0;
    }
    else {
      puVar1 = PTR_DAT_10009eec + (uVar3 - 1) * 0x50;
    }
    param_4 = (uint)(byte)puVar1[0xd];
    if (param_4 == 0) break;
    bVar2 = bVar2 + 1;
  }
  return uVar3;
}


/* ===== lma_enum_hub_get_status0_complete @ 10009ef0 (94 bytes) ===== */

undefined4 lma_enum_hub_get_status0_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  byte bStack_b;
  
  iVar1 = DAT_10009f54;
  if (param_3 == 0) {
    uVar4 = *DAT_10009f50;
    if ((int)(uVar4 << 0x1f) < 0) {
      bStack_b = (byte)(uVar4 >> 8);
      if ((int)((uint)bStack_b << 0x1d) < 0) {
        bVar3 = 2;
      }
      else {
        bVar3 = bStack_b >> 1 & 1;
      }
      *(byte *)(DAT_10009f54 + 3) = bVar3;
      if ((int)((uVar4 >> 0x10) << 0x1b) < 0) {
        lma_hub_port_clear_feature
                  (*(undefined *)(iVar1 + 1),*(undefined *)(iVar1 + 2),0x14,DAT_10009f64);
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = lma_hub_status_pipe_queue();
    }
  }
  else {
    lma___wrap_printf(DAT_10009f60,DAT_10009f5c,DAT_10009f58);
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== lma_enum_hub_get_status1_complete @ 10009f68 (74 bytes) ===== */

int lma_enum_hub_get_status1_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    if ((int)((*DAT_10009fb4 >> 0x10) << 0x1b) < 0) {
      iVar1 = lma_hub_port_clear_feature
                        (*(undefined *)(DAT_10009fc4 + 1),*(undefined *)(DAT_10009fc4 + 2),0x14,
                         DAT_10009fc8);
      if (iVar1 == 0) {
        lma___wrap_printf(DAT_10009fc0,DAT_10009fbc,DAT_10009fcc);
      }
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    lma___wrap_printf(DAT_10009fc0,DAT_10009fbc,DAT_10009fb8);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== lma_enum_request_set_addr @ 10009fd0 (182 bytes) ===== */

int lma_enum_request_set_addr(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined local_10;
  undefined local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar2 = lma_get_new_address(*(char *)(DAT_1000a088 + 4) == '\t');
  if (iVar2 == 0xff) {
    lma___wrap_printf(DAT_1000a0a0,DAT_1000a09c,DAT_1000a098);
    iVar2 = 0;
  }
  else {
    if (iVar2 == 0) {
      lma___wrap_printf(DAT_1000a0a0,DAT_1000a0a4,0xdc);
      puVar3 = (undefined *)0x0;
    }
    else {
      puVar3 = (undefined *)((iVar2 + -1) * 0x50 + DAT_1000a08c);
    }
    puVar1 = DAT_1000a090;
    *puVar3 = *DAT_1000a090;
    puVar3[1] = puVar1[1];
    puVar3[2] = puVar1[2];
    puVar3[3] = puVar1[3];
    puVar3[0xc] = puVar3[0xc] | 1;
    puVar3[8] = *(undefined *)(DAT_1000a088 + 7);
    local_10 = 0;
    local_f = 5;
    local_e = (undefined2)iVar2;
    local_c = 0;
    local_a = 0;
    iVar2 = lma_tuh_control_xfer(0,&local_10,0,DAT_1000a094);
    if (iVar2 == 0) {
      lma___wrap_printf(DAT_1000a0a0,DAT_1000a09c,0x32c);
    }
  }
  return iVar2;
}


/* ===== lma_enum_get_device_desc_complete @ 1000a0dc (116 bytes) ===== */

int lma_enum_get_device_desc_complete(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (param_3 == 0) {
    if (param_1 == 0) {
      lma___wrap_printf(DAT_1000a168,DAT_1000a16c,0xdc);
      iVar2 = 0;
    }
    else {
      iVar2 = (param_1 + -1) * 0x50 + DAT_1000a150;
    }
    iVar1 = DAT_1000a154;
    *(undefined2 *)(iVar2 + 4) = *(undefined2 *)(DAT_1000a154 + 8);
    *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(iVar1 + 10);
    *(undefined *)(iVar2 + 9) = *(undefined *)(iVar1 + 0xe);
    *(undefined *)(iVar2 + 10) = *(undefined *)(iVar1 + 0xf);
    *(undefined *)(iVar2 + 0xb) = *(undefined *)(iVar1 + 0x10);
    local_18 = *DAT_1000a158;
    uStack_14 = DAT_1000a158[1];
    iVar2 = lma_tuh_control_xfer(param_1,&local_18,iVar1,DAT_1000a15c);
    if (iVar2 == 0) {
      lma___wrap_printf(DAT_1000a168,DAT_1000a164,DAT_1000a170);
    }
  }
  else {
    lma___wrap_printf(DAT_1000a168,DAT_1000a164,DAT_1000a160);
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== lma_enum_get_9byte_config_desc_complete @ 1000a174 (128 bytes) ===== */

int lma_enum_get_9byte_config_desc_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined local_10;
  undefined local_f;
  undefined2 local_e;
  undefined2 local_c;
  ushort local_a;
  
  if (param_3 == 0) {
    local_a = *(ushort *)(DAT_1000a1f4 + 2);
    if (local_a < 0x201) {
      local_10 = 0x80;
      local_f = 6;
      local_e = 0x200;
      local_c = 0;
      iVar1 = lma_tuh_control_xfer(param_1,&local_10,DAT_1000a1f4,DAT_1000a1f8);
      if (iVar1 == 0) {
        lma___wrap_printf(DAT_1000a204,DAT_1000a200,DAT_1000a20c);
      }
    }
    else {
      lma___wrap_printf(DAT_1000a204,DAT_1000a200,DAT_1000a208);
      iVar1 = 0;
    }
  }
  else {
    lma___wrap_printf(DAT_1000a204,DAT_1000a200,DAT_1000a1fc);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== lma_process_device_unplugged @ 1000a210 (222 bytes) ===== */

void lma_process_device_unplugged(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  while (uVar2 = uVar3, uVar2 < 5) {
    uVar3 = uVar2 + 1 & 0xff;
    if ((((*(byte *)(uVar2 * 0x50 + DAT_1000a2f0) == param_1) &&
         ((param_2 == 0 || (*(byte *)(DAT_1000a2f0 + uVar2 * 0x50 + 1) == param_2)))) &&
        ((param_3 == 0 || (*(byte *)(DAT_1000a2f0 + uVar2 * 0x50 + 2) == param_3)))) &&
       (*(char *)(DAT_1000a2f0 + uVar2 * 0x50 + 0xd) != '\0')) {
      for (uVar4 = 0; iVar1 = DAT_1000a2f0, uVar4 < 2; uVar4 = uVar4 + 1 & 0xff) {
        (**(code **)(DAT_1000a2f8 + uVar4 * 0x14 + 0x10))(uVar3);
      }
      lma_memset(uVar2 * 0x50 + DAT_1000a2f0 + 0xe,0xff,0x10);
      lma_memset(uVar2 * 0x50 + iVar1 + 0x1e,0xff,0x12);
      lma_hcd_device_close(param_1,uVar3);
      *(undefined *)(uVar2 * 0x50 + iVar1 + 0xd) = 0;
    }
  }
  return;
}


/* ===== lma_tuh_speed_get @ 1000a4a4 (26 bytes) ===== */

undefined lma_tuh_speed_get(int param_1)

{
  undefined uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(undefined *)(DAT_1000a4c4 + 3);
  }
  else {
    uVar1 = *(undefined *)((param_1 + -1) * 0x50 + DAT_1000a4c0 + 3);
  }
  return uVar1;
}


/* ===== lma_tuh_inited @ 1000a4c8 (6 bytes) ===== */

undefined lma_tuh_inited(void)

{
  return *DAT_1000a4d0;
}


/* ===== lma_tuh_init @ 1000a4d4 (234 bytes) ===== */

uint lma_tuh_init(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)*PTR_DAT_1000a5c0;
  if (uVar3 == 0) {
    lma_memset(PTR_DAT_1000a5c4,0,400);
    lma_memset(PTR_DAT_1000a5c8,0,5);
    puVar1 = PTR_DAT_1000a5cc;
    lma_critical_section_init(PTR_DAT_1000a5cc + 0x1c);
    lma_tu_fifo_clear(puVar1);
    *(undefined **)PTR_DAT_1000a5d0 = puVar1;
    for (uVar3 = 0; puVar1 = PTR_DAT_1000a5c4, uVar3 < 5; uVar3 = uVar3 + 1 & 0xff) {
      puVar2 = PTR_DAT_1000a5c4 + uVar3 * 0x50 + 0x44;
      lma_mutex_init(puVar2);
      *(undefined **)(puVar1 + uVar3 * 0x50 + 0x4c) = puVar2;
      puVar1 = PTR_DAT_1000a5c4;
      if (puVar2 == (undefined *)0x0) {
        lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_1000a5d8,PTR_s_tuh_init_1000a5d4,0x12a);
        return 0;
      }
      lma_memset(PTR_DAT_1000a5c4 + uVar3 * 0x50 + 0xe,0xff,0x10);
      lma_memset(puVar1 + uVar3 * 0x50 + 0x1e,0xff,0x12);
    }
    for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1 & 0xff) {
      (**(code **)(PTR_DAT_1000a5dc + uVar3 * 0x14))();
    }
    uVar3 = lma_hcd_init(param_1);
    if (uVar3 == 0) {
      lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_1000a5d8,PTR_s_tuh_init_1000a5d4,0x138);
    }
    else {
      lma_hcd_int_enable(param_1);
      *PTR_DAT_1000a5c0 = 1;
    }
  }
  return uVar3;
}


/* ===== lma_usbh_get_rhport @ 1000a5e0 (24 bytes) ===== */

undefined lma_usbh_get_rhport(int param_1)

{
  undefined uVar1;
  
  if (param_1 == 0) {
    uVar1 = *DAT_1000a5f8;
  }
  else {
    uVar1 = *(undefined *)(DAT_1000a5fc + (param_1 + -1) * 0x50);
  }
  return uVar1;
}


/* ===== lma_usbh_edpt_control_open @ 1000a600 (56 bytes) ===== */

void lma_usbh_edpt_control_open(undefined4 param_1,ushort param_2)

{
  undefined4 uVar1;
  undefined local_18;
  undefined local_17;
  ushort local_14;
  
  lma_memset(&local_18,0,7);
  local_18 = 7;
  local_17 = 5;
  local_14 = local_14 & 0xf800 | param_2;
  uVar1 = lma_usbh_get_rhport(param_1);
  lma_hcd_edpt_open(uVar1,param_1,&local_18);
  return;
}


/* ===== lma_enum_request_addr0_device_desc @ 1000a638 (72 bytes) ===== */

int lma_enum_request_addr0_device_desc(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar1 = lma_usbh_edpt_control_open(0,8);
  if (iVar1 == 0) {
    lma___wrap_printf(DAT_1000a694,DAT_1000a690,DAT_1000a68c);
    iVar1 = 0;
  }
  else {
    local_10 = *(undefined4 *)(DAT_1000a680 + 0x10);
    uStack_c = *(undefined4 *)(DAT_1000a680 + 0x14);
    iVar1 = lma_tuh_control_xfer(0,&local_10,DAT_1000a688,DAT_1000a684);
    if (iVar1 == 0) {
      lma___wrap_printf(DAT_1000a694,DAT_1000a690,DAT_1000a698);
    }
  }
  return iVar1;
}


/* ===== lma_enum_new_device @ 1000a69c (102 bytes) ===== */

int lma_enum_new_device(undefined *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined uVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_1000a704;
  *PTR_DAT_1000a704 = *param_1;
  cVar1 = param_1[4];
  puVar2[1] = cVar1;
  puVar2[2] = param_1[5];
  if (cVar1 == '\0') {
    lma_sleep_ms(500);
    iVar4 = lma_hcd_port_connect_status(*PTR_DAT_1000a704);
    puVar2 = PTR_DAT_1000a704;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    else {
      uVar3 = lma_hcd_port_speed_get(*PTR_DAT_1000a704);
      puVar2[3] = uVar3;
      lma_enum_request_addr0_device_desc();
    }
  }
  else {
    lma_sleep_ms(500);
    iVar4 = lma_hub_port_get_status
                      (PTR_DAT_1000a704[1],PTR_DAT_1000a704[2],PTR_DAT_1000a70c,
                       PTR_enum_hub_get_status0_complete_1_1000a708);
    if (iVar4 == 0) {
      lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_1000a718,PTR_s_enum_new_device_1000a714,
                        DAT_1000a710);
    }
  }
  return iVar4;
}


/* ===== lma_tuh_task @ 1000a71c (282 bytes) ===== */

void lma_tuh_task(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined local_1c;
  byte local_1b;
  byte local_1a;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = lma_tusb_inited();
  if (iVar2 != 0) {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            iVar2 = *DAT_1000a838;
            uVar4 = 0;
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              uVar4 = isIRQinterruptsEnabled();
            }
            disableIRQinterrupts();
            do {
            } while (**(int **)(iVar2 + 0x1c) == 0);
            DataMemoryBarrier(0x1f);
            *(undefined4 *)(iVar2 + 0x20) = uVar4;
            iVar3 = lma_tu_fifo_read(iVar2,&local_1c);
            uVar6 = *(uint *)(iVar2 + 0x20);
            DataMemoryBarrier(0x1f);
            **(undefined4 **)(iVar2 + 0x1c) = 0;
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              enableIRQinterrupts((uVar6 & 1) == 1);
            }
            if (iVar3 == 0) {
              return;
            }
            if (local_1b == 2) break;
            if (local_1b < 3) {
              if (local_1b == 0) {
                lma_enum_new_device(&local_1c);
              }
              else if ((local_1b == 1) &&
                      (lma_process_device_unplugged(local_1c,(uint)local_18 & 0xff,local_18._1_1_),
                      ((uint)local_18 & 0xff) != 0)) {
                lma_hub_status_pipe_queue();
              }
            }
            else if ((local_1b == 3) && (local_18 != (code *)0x0)) {
              (*local_18)(local_14);
            }
          }
          uVar6 = (uint)local_18 & 0xff;
          uVar7 = (uint)local_18 >> 7 & 1;
          if (local_1a != 0) break;
          if (((uint)local_18 & 0x7f) != 0) {
            lma___wrap_printf(DAT_1000a840,DAT_1000a83c,0x17e);
            return;
          }
          lma_usbh_control_xfer_cb(0,uVar6,local_18._1_1_,local_14);
        }
        iVar2 = (local_1a - 1) * 0x50 + DAT_1000a844;
        pbVar5 = (byte *)(iVar2 + ((uint)local_18 & 0x7f) * 2 + uVar7 + 0x30);
        *pbVar5 = *pbVar5 & 0xfe;
        *pbVar5 = *pbVar5 & 0xfb;
        if (((uint)local_18 & 0x7f) != 0) break;
        lma_usbh_control_xfer_cb(local_1a,uVar6,local_18._1_1_,local_14);
      }
      uVar7 = (uint)*(byte *)(iVar2 + ((uint)local_18 & 0x7f) * 2 + uVar7 + 0x1e);
      if (1 < uVar7) break;
      (**(code **)(DAT_1000a848 + uVar7 * 0x14 + 0xc))(local_1a,uVar6,local_18._1_1_,local_14);
    }
    lma___wrap_printf(DAT_1000a840,DAT_1000a83c,0x18d);
  }
  return;
}


/* ===== lma_enum_set_address_complete @ 1000a93c (162 bytes) ===== */

int lma_enum_set_address_complete(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    if (param_3 == 0) {
      uVar2 = (uint)*(byte *)(param_2 + 2);
      if (uVar2 == 0) {
        lma___wrap_printf(DAT_1000a9f8,DAT_1000aa00,0xdc);
        iVar1 = 0;
      }
      else {
        iVar1 = (uVar2 - 1) * 0x50 + DAT_1000a9e0;
      }
      *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 2;
      lma_hcd_device_close(*DAT_1000a9e4,0);
      iVar1 = lma_usbh_edpt_control_open(uVar2,*(undefined *)(iVar1 + 8));
      if (iVar1 == 0) {
        lma___wrap_printf(DAT_1000a9f8,DAT_1000a9f4,0x340);
        iVar1 = 0;
      }
      else {
        local_18 = *(undefined4 *)(DAT_1000a9e8 + 0x18);
        uStack_14 = *(undefined4 *)(DAT_1000a9e8 + 0x1c);
        iVar1 = lma_tuh_control_xfer(uVar2,&local_18,DAT_1000a9f0,DAT_1000a9ec);
        if (iVar1 == 0) {
          lma___wrap_printf(DAT_1000a9f8,DAT_1000a9f4,DAT_1000aa04);
        }
      }
    }
    else {
      lma___wrap_printf(DAT_1000a9f8,DAT_1000a9f4,DAT_1000a9fc);
      iVar1 = 0;
    }
  }
  else {
    lma___wrap_printf(DAT_1000a9f8,DAT_1000a9f4,0x334);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== lma_hcd_event_handler @ 1000aa08 (68 bytes) ===== */

void lma_hcd_event_handler(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *DAT_1000aa4c;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**(int **)(iVar5 + 0x1c) == 0);
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(iVar5 + 0x20) = uVar2;
  iVar3 = lma_tu_fifo_write(iVar5,param_1);
  uVar4 = *(uint *)(iVar5 + 0x20);
  DataMemoryBarrier(0x1f);
  **(undefined4 **)(iVar5 + 0x1c) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  if (iVar3 == 0) {
    lma___wrap_printf(DAT_1000aa54,DAT_1000aa50,0xa8,uVar4);
  }
  return;
}


/* ===== lma_hcd_event_xfer_complete @ 1000aa58 (38 bytes) ===== */

void lma_hcd_event_xfer_complete
               (undefined param_1,undefined param_2,undefined4 param_3,undefined param_4,
               undefined param_5)

{
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_18;
  undefined local_17;
  undefined4 local_14;
  
  local_1c = 0;
  local_1b = 2;
  local_1a = param_1;
  local_18 = param_2;
  local_17 = param_4;
  local_14 = param_3;
  lma_hcd_event_handler(&local_1c,param_5);
  return;
}


/* ===== lma_hcd_event_device_attach @ 1000aa7e (34 bytes) ===== */

void lma_hcd_event_device_attach(undefined param_1,undefined4 param_2)

{
  undefined local_1c [12];
  
  lma_memset(local_1c,0,0xc);
  local_1c[0] = param_1;
  lma_hcd_event_handler(local_1c,param_2);
  return;
}


/* ===== lma_hcd_event_device_remove @ 1000aaa0 (40 bytes) ===== */

void lma_hcd_event_device_remove(undefined param_1,undefined4 param_2)

{
  undefined local_1c;
  undefined local_1b;
  
  lma_memset(&local_1c,0,0xc);
  local_1b = 1;
  local_1c = param_1;
  lma_hcd_event_handler(&local_1c,param_2);
  return;
}


/* ===== lma_usbh_driver_set_config_complete @ 1000aac8 (94 bytes) ===== */

int lma_usbh_driver_set_config_complete(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    iVar1 = lma___wrap_printf(DAT_1000ab30,DAT_1000ab2c,0xdc);
    iVar2 = 0;
  }
  else {
    iVar2 = (param_1 + -1) * 0x50 + DAT_1000ab28;
    iVar1 = param_1;
  }
  uVar4 = (uint)(byte)(param_2 + 1);
  do {
    if (0xf < uVar4) {
LAB_1000ab14:
      if ((uVar4 == 0x10) && (DAT_1000ab38 != 0)) {
        iVar1 = param_1;
      }
      return iVar1;
    }
    uVar3 = (uint)*(byte *)(iVar2 + uVar4 + 0xe);
    if (uVar3 != 0xff) {
      iVar1 = (**(code **)(DAT_1000ab34 + uVar3 * 0x14 + 8))(param_1,uVar4);
      goto LAB_1000ab14;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while( true );
}


/* ===== lma_usbh_edpt_xfer @ 1000ab9c (152 bytes) ===== */

int lma_usbh_edpt_xfer(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 & 0x7f;
  uVar4 = param_2 >> 7;
  if (param_1 == 0) {
    lma___wrap_printf(DAT_1000ac3c,DAT_1000ac38,0xdc);
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = (undefined *)((param_1 + -1) * 0x50 + DAT_1000ac34);
  }
  if ((int)((uint)(byte)puVar2[uVar4 + uVar5 * 2 + 0x30] << 0x1f) < 0) {
    lma___wrap_printf(DAT_1000ac3c,DAT_1000ac44,DAT_1000ac40);
    iVar1 = 0;
  }
  else {
    puVar2[uVar4 + uVar5 * 2 + 0x30] = puVar2[uVar4 + uVar5 * 2 + 0x30] | 1;
    iVar1 = lma_hcd_edpt_xfer(*puVar2,param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      pbVar3 = puVar2 + uVar4 + uVar5 * 2 + 0x30;
      *pbVar3 = *pbVar3 & 0xfe;
      *pbVar3 = *pbVar3 & 0xfb;
    }
  }
  return iVar1;
}


/* ===== lma_usbh_edpt_open @ 1000ac48 (78 bytes) ===== */

undefined4 lma_usbh_edpt_open(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (param_2 == 0) {
    lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_1000aca0,PTR_s_get_device_1000ac9c,0xdc,param_4,
                      param_4);
    puVar3 = (undefined *)0x0;
  }
  else {
    puVar3 = PTR_DAT_1000ac98 + (param_2 + -1) * 0x50;
  }
  iVar1 = lma_tu_edpt_validate(param_3,puVar3[3]);
  if (iVar1 == 0) {
    lma___wrap_printf(PTR_s__s__d__ASSERT_FAILED_1000aca0,DAT_1000aca8,DAT_1000aca4);
    uVar2 = 0;
  }
  else {
    uVar2 = lma_hcd_edpt_open(param_1,param_2,param_3);
  }
  return uVar2;
}


/* ===== lma__xfer_complete @ 1000acac (18 bytes) ===== */

void lma__xfer_complete(undefined4 param_1,undefined4 param_2)

{
  if (*(code **)(DAT_1000acc0 + 0x10) != (code *)0x0) {
    (**(code **)(DAT_1000acc0 + 0x10))(param_1,DAT_1000acc0,param_2);
  }
  return;
}


/* ===== lma_tuh_control_xfer @ 1000acc4 (78 bytes) ===== */

int lma_tuh_control_xfer
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = lma_usbh_get_rhport();
  iVar2 = DAT_1000ad14;
  lma_memcpy(DAT_1000ad14,param_2,8);
  *(undefined4 *)(iVar2 + 0xc) = param_3;
  *(undefined *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0x10) = param_4;
  iVar2 = lma_hcd_setup_send(uVar1,param_1,iVar2);
  if (iVar2 == 0) {
    lma___wrap_printf(DAT_1000ad1c,DAT_1000ad18,0x4a);
  }
  return iVar2;
}


/* ===== lma_usbh_control_xfer_cb @ 1000ad20 (138 bytes) ===== */

undefined4 lma_usbh_control_xfer_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined uVar5;
  
  uVar4 = lma_usbh_get_rhport();
  pcVar3 = DAT_1000adac;
  if (param_3 != 0) {
    lma__xfer_complete(param_1,param_3);
    return 1;
  }
  cVar1 = DAT_1000adac[8];
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      lma__xfer_complete(param_1,0);
      return 1;
    }
    if (cVar1 != '\0') {
      return 0;
    }
    DAT_1000adac[8] = '\x01';
    sVar2 = *(short *)(pcVar3 + 6);
    if (sVar2 != 0) {
      if (*pcVar3 < '\0') {
        uVar5 = 0x80;
      }
      else {
        uVar5 = 0;
      }
      lma_hcd_edpt_xfer(uVar4,param_1,uVar5,*(undefined4 *)(DAT_1000adac + 0xc),sVar2);
      return 1;
    }
  }
  pcVar3 = DAT_1000adac;
  DAT_1000adac[8] = '\x02';
  if (*pcVar3 < '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x80;
  }
  lma_hcd_edpt_xfer(uVar4,param_1,uVar5,0,0);
  return 1;
}


/* ===== lma_connection_port_reset_complete @ 1000adb0 (66 bytes) ===== */

bool lma_connection_port_reset_complete(undefined4 param_1,int param_2,int param_3)

{
  undefined uVar1;
  undefined local_1c [4];
  undefined local_18;
  undefined local_17;
  
  if (param_3 != 0) {
    lma___wrap_printf(DAT_1000adf8,DAT_1000adf4,0x16e);
  }
  else {
    uVar1 = *(undefined *)(param_2 + 4);
    lma_memset(local_1c,0,0xc);
    local_1c[0] = lma_usbh_get_rhport(param_1);
    local_18 = (undefined)param_1;
    local_17 = uVar1;
    lma_hcd_event_handler(local_1c,0);
  }
  return param_3 == 0;
}


/* ===== lma_hub_port_clear_feature @ 1000adfc (84 bytes) ===== */

int lma_hub_port_clear_feature(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0x23;
  local_17 = 1;
  local_12 = 0;
  local_16 = param_3;
  local_14 = param_2;
  iVar1 = lma_tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    lma___wrap_printf(DAT_1000ae54,DAT_1000ae50,0x61);
  }
  return iVar1;
}


/* ===== lma_hub_port_set_feature @ 1000ae58 (84 bytes) ===== */

int lma_hub_port_set_feature(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0x23;
  local_17 = 3;
  local_12 = 0;
  local_16 = param_3;
  local_14 = param_2;
  iVar1 = lma_tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    lma___wrap_printf(DAT_1000aeb0,DAT_1000aeac,0x76);
  }
  return iVar1;
}


/* ===== lma_hub_port_get_status @ 1000aff4 (86 bytes) ===== */

int lma_hub_port_get_status(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0xa3;
  local_17 = 0;
  local_16 = 0;
  local_12 = 4;
  local_14 = param_2;
  iVar1 = lma_tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    lma___wrap_printf(DAT_1000b050,DAT_1000b04c,0x90);
  }
  return iVar1;
}


/* ===== lma_hub_status_pipe_queue @ 1000b11c (22 bytes) ===== */

void lma_hub_status_pipe_queue(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_1000b134 + (param_1 + -5) * 8;
  lma_usbh_edpt_xfer(param_1,*(undefined *)(iVar1 + 1),iVar1 + 3,1);
  return;
}


/* ===== lma_hub_set_config @ 1000b184 (68 bytes) ===== */

int lma_hub_set_config(int param_1,uint param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (*(byte *)((param_1 + -5) * 8 + DAT_1000b1c8) == param_2) {
    local_18 = *DAT_1000b1d4;
    uStack_14 = DAT_1000b1d4[1];
    iVar1 = lma_tuh_control_xfer(param_1,&local_18,DAT_1000b1dc,DAT_1000b1d8);
    if (iVar1 == 0) {
      lma___wrap_printf(DAT_1000b1d0,DAT_1000b1cc,0xe2);
    }
  }
  else {
    lma___wrap_printf(DAT_1000b1d0,DAT_1000b1cc,0xd1);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== lma_config_read_capacity_complete @ 1000b240 (130 bytes) ===== */

undefined4 lma_config_read_capacity_complete(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = DAT_1000b2c8;
  puVar1 = DAT_1000b2c4;
  if (*(char *)(param_3 + 0xc) == '\0') {
    iVar5 = param_1 + -1;
    uVar4 = *DAT_1000b2c4;
    *(uint *)(DAT_1000b2c8 + (iVar5 * 0xc + (uint)*(byte *)(param_2 + 0xd) + 1) * 8 + 4) =
         (uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18)
         + 1;
    uVar4 = puVar1[1];
    *(uint *)((iVar5 * 0xc + (uint)*(byte *)(param_2 + 0xd) + 1) * 8 + iVar2) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    *(undefined *)(iVar2 + iVar5 * 0x60 + 5) = 1;
    if (DAT_1000b2cc != 0) {
      lma_tuh_msc_mount_cb(param_1);
    }
    lma_usbh_driver_set_config_complete(param_1,*(undefined *)(iVar5 * 0x60 + DAT_1000b2c8));
    uVar3 = 1;
  }
  else {
    lma___wrap_printf(DAT_1000b2d4,DAT_1000b2d0,0x1d8);
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== lma_tuh_msc_scsi_command @ 1000b30c (120 bytes) ===== */

uint lma_tuh_msc_scsi_command(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_1000b384;
  iVar4 = param_1 + -1;
  bVar1 = *(byte *)(DAT_1000b384 + iVar4 * 0x60 + 4);
  uVar3 = (uint)bVar1;
  if (bVar1 != 0) {
    iVar5 = iVar4 * 0x60 + DAT_1000b384;
    lma_memcpy(iVar5 + 0x34,param_2,0x1f);
    *(undefined *)(iVar5 + 0x28) = 1;
    *(undefined4 *)(iVar5 + 0x2c) = param_3;
    *(undefined4 *)(iVar5 + 0x30) = param_4;
    uVar3 = lma_usbh_edpt_xfer(param_1,*(undefined *)(iVar5 + 2),iVar4 * 0x60 + iVar2 + 0x34,0x1f);
    if (uVar3 == 0) {
      lma___wrap_printf(DAT_1000b38c,DAT_1000b388,0x8d);
    }
  }
  return uVar3;
}


/* ===== lma_tuh_msc_read_capacity @ 1000b390 (88 bytes) ===== */

uint lma_tuh_msc_read_capacity(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  
  bVar1 = *(byte *)(DAT_1000b3e8 + (param_1 + -1) * 0x60 + 4);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    lma_memset(&local_38,0,0x1f);
    local_38 = DAT_1000b3ec;
    local_34 = DAT_1000b3f0;
    local_30 = 8;
    local_2c = 0x80;
    local_2a = 10;
    local_29 = 0x25;
    local_2b = param_2;
    uVar2 = lma_tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  }
  return uVar2;
}


/* ===== lma_tuh_msc_inquiry @ 1000b3f4 (114 bytes) ===== */

uint lma_tuh_msc_inquiry(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined local_40 [4];
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [21];
  
  bVar1 = *(byte *)(DAT_1000b468 + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    lma_memset(&local_38,0,0x1f);
    local_38 = DAT_1000b46c;
    local_34 = DAT_1000b470;
    local_30 = 0x24;
    local_2c = 0x80;
    local_2a = 6;
    local_2b = param_2;
    lma_memset(local_40,0,6);
    local_40[0] = 0x12;
    local_3c = 0x24;
    lma_memcpy(auStack_29,local_40,6);
    uVar2 = lma_tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  }
  return uVar2;
}


/* ===== lma_tuh_msc_test_unit_ready @ 1000b474 (78 bytes) ===== */

uint lma_tuh_msc_test_unit_ready(int param_1,undefined param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_2b;
  undefined local_2a;
  undefined local_28;
  
  bVar1 = *(byte *)(DAT_1000b4c4 + (param_1 + -1) * 0x60 + 4);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    lma_memset(&local_38,0,0x1f);
    local_38 = DAT_1000b4c8;
    local_34 = DAT_1000b4cc;
    local_2a = 6;
    local_2b = param_2;
    local_28 = param_2;
    uVar2 = lma_tuh_msc_scsi_command(param_1,&local_38,0,param_3);
  }
  return uVar2;
}


/* ===== lma_tuh_msc_request_sense @ 1000b54c (100 bytes) ===== */

void lma_tuh_msc_request_sense
               (undefined4 param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  undefined local_40 [4];
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  lma_memset(&local_38,0,0x1f);
  local_38 = DAT_1000b5b0;
  local_34 = DAT_1000b5b4;
  local_30 = 0x12;
  local_2c = 0x80;
  local_2a = 6;
  local_2b = param_2;
  lma_memset(local_40,0,6);
  local_40[0] = 3;
  local_3c = 0x12;
  lma_memcpy(auStack_29,local_40,6);
  lma_tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  return;
}


/* ===== lma_tuh_msc_read10 @ 1000b600 (186 bytes) ===== */

uint lma_tuh_msc_read10(int param_1,int param_2,undefined4 param_3,uint param_4,ushort param_5,
                       undefined4 param_6)

{
  byte bVar1;
  uint uVar2;
  undefined local_44 [2];
  ushort local_42;
  ushort local_40;
  undefined local_3d;
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  bVar1 = *(byte *)(DAT_1000b6bc + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    lma_memset(&local_38,0,0x1f,bVar1,param_3,param_4);
    local_38 = DAT_1000b6c0;
    local_34 = DAT_1000b6c4;
    local_2b = (undefined)param_2;
    local_30 = (uint)param_5 * *(int *)(((param_1 + -1) * 0xc + param_2 + 1) * 8 + DAT_1000b6bc);
    local_2c = 0x80;
    local_2a = 10;
    lma_memset(local_44,0,10);
    local_44[0] = 0x28;
    local_40 = (ushort)((param_4 << 0x18) >> 0x10) | (ushort)(param_4 >> 8) & 0xff;
    local_42 = (ushort)((param_4 >> 0x10 & 0xff) << 8) | (ushort)(byte)(param_4 >> 0x18);
    local_3d = (undefined)(param_5 >> 8);
    local_3c = (undefined)param_5;
    lma_memcpy(auStack_29,local_44,10);
    uVar2 = lma_tuh_msc_scsi_command(param_1,&local_38,param_3,param_6);
  }
  return uVar2;
}


/* ===== lma_tuh_msc_write10 @ 1000b6c8 (180 bytes) ===== */

uint lma_tuh_msc_write10(int param_1,int param_2,undefined4 param_3,uint param_4,ushort param_5,
                        undefined4 param_6)

{
  byte bVar1;
  uint uVar2;
  undefined local_44 [2];
  ushort local_42;
  ushort local_40;
  undefined local_3d;
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  bVar1 = *(byte *)(DAT_1000b77c + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    lma_memset(&local_38,0,0x1f,bVar1,param_3,param_4);
    local_38 = DAT_1000b780;
    local_34 = DAT_1000b784;
    local_2b = (undefined)param_2;
    local_30 = (uint)param_5 * *(int *)(((param_1 + -1) * 0xc + param_2 + 1) * 8 + DAT_1000b77c);
    local_2a = 10;
    lma_memset(local_44,0,10);
    local_44[0] = 0x2a;
    local_40 = (ushort)((param_4 << 0x18) >> 0x10) | (ushort)(param_4 >> 8) & 0xff;
    local_42 = (ushort)((param_4 >> 0x10 & 0xff) << 8) | (ushort)(byte)(param_4 >> 0x18);
    local_3d = (undefined)(param_5 >> 8);
    local_3c = (undefined)param_5;
    lma_memcpy(auStack_29,local_44,10);
    uVar2 = lma_tuh_msc_scsi_command(param_1,&local_38,param_3,param_6);
  }
  return uVar2;
}


/* ===== lma_msch_xfer_cb @ 1000b7d4 (338 bytes) ===== */

int lma_msch_xfer_cb(int param_1,uint param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = DAT_1000b928;
  iVar8 = param_1 + -1;
  iVar2 = iVar8 * 0x60 + DAT_1000b928;
  iVar4 = iVar8 * 0x60 + DAT_1000b928 + 0x53;
  cVar1 = *(char *)(DAT_1000b928 + iVar8 * 0x60 + 0x28);
  if (cVar1 == '\x02') {
    *(undefined *)(DAT_1000b928 + iVar8 * 0x60 + 0x28) = 3;
    iVar7 = lma_usbh_edpt_xfer(param_1,*(undefined *)(iVar7 + iVar8 * 0x60 + 1),iVar4,0xd);
    if (iVar7 == 0) {
      lma___wrap_printf(DAT_1000b930,DAT_1000b92c,0x154);
    }
  }
  else if (cVar1 == '\x03') {
    *(undefined *)(DAT_1000b928 + iVar8 * 0x60 + 0x28) = 0;
    pcVar6 = *(code **)(iVar7 + iVar8 * 0x60 + 0x30);
    if (pcVar6 == (code *)0x0) {
      iVar7 = 1;
    }
    else {
      (*pcVar6)(param_1,iVar2 + 0x34);
      iVar7 = 1;
    }
  }
  else if (cVar1 == '\x01') {
    uVar3 = (uint)*(byte *)(DAT_1000b928 + iVar8 * 0x60 + 2);
    if (((uVar3 == param_2) && (param_3 == 0)) && (param_4 == 0x1f)) {
      uVar5 = *(uint *)(DAT_1000b928 + iVar8 * 0x60 + 0x3c);
      if ((uVar5 == 0) || (iVar2 = *(int *)(DAT_1000b928 + iVar8 * 0x60 + 0x2c), iVar2 == 0)) {
        *(undefined *)(DAT_1000b928 + iVar8 * 0x60 + 0x28) = 3;
        iVar7 = lma_usbh_edpt_xfer(param_1,*(undefined *)(iVar7 + iVar8 * 0x60 + 1),iVar4,0xd);
        if (iVar7 == 0) {
          lma___wrap_printf(DAT_1000b930,DAT_1000b92c,0x14d);
        }
      }
      else {
        iVar7 = DAT_1000b928 + iVar8 * 0x60;
        *(undefined *)(iVar7 + 0x28) = 2;
        if (*(char *)(iVar7 + 0x40) < '\0') {
          uVar3 = (uint)*(byte *)(DAT_1000b928 + iVar8 * 0x60 + 1);
        }
        iVar7 = lma_usbh_edpt_xfer(param_1,uVar3,iVar2,uVar5 & 0xffff);
        if (iVar7 == 0) {
          lma___wrap_printf(DAT_1000b930,DAT_1000b92c,0x148);
        }
      }
    }
    else {
      lma___wrap_printf(DAT_1000b930,DAT_1000b92c,0x140);
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 1;
  }
  return iVar7;
}


/* ===== lma_msch_open @ 1000b934 (216 bytes) ===== */

undefined4 lma_msch_open(undefined4 param_1,int param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  
  if (param_3[6] == 6) {
    if (param_3[7] == 0x50) {
      if (param_4 < (uint)param_3[4] * 7 + 9) {
        lma___wrap_printf(DAT_1000ba10,DAT_1000ba0c,0x175);
        uVar5 = 0;
      }
      else {
        iVar4 = param_2 + -1;
        pbVar6 = param_3 + *param_3;
        for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1) {
          if ((pbVar6[1] != 5) || ((pbVar6[3] & 3) != 2)) {
            lma___wrap_printf(DAT_1000ba10,DAT_1000ba0c,0x17c);
            return 0;
          }
          iVar2 = lma_usbh_edpt_open(param_1,param_2,pbVar6);
          if (iVar2 == 0) {
            lma___wrap_printf(DAT_1000ba10,DAT_1000ba0c,0x17d);
            return 0;
          }
          bVar1 = pbVar6[2];
          if ((char)bVar1 < '\0') {
            *(byte *)(DAT_1000ba14 + iVar4 * 0x60 + 1) = bVar1;
          }
          else {
            *(byte *)(DAT_1000ba14 + iVar4 * 0x60 + 2) = bVar1;
          }
          pbVar6 = pbVar6 + *pbVar6;
        }
        *(byte *)(iVar4 * 0x60 + DAT_1000ba14) = param_3[2];
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== lma_msch_set_config @ 1000ba18 (142 bytes) ===== */

int lma_msch_set_config(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined local_20;
  undefined local_1f;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar2 = DAT_1000baa8;
  iVar1 = param_1 + -1;
  if (*(byte *)(iVar1 * 0x60 + DAT_1000baa8) == param_2) {
    *(undefined *)(DAT_1000baa8 + iVar1 * 0x60 + 4) = 1;
    local_20 = 0xa1;
    local_1f = 0xfe;
    local_1e = 0;
    local_1c = (undefined2)param_2;
    local_1a = 1;
    iVar2 = lma_tuh_control_xfer(param_1,&local_20,iVar1 * 0x60 + iVar2 + 3,DAT_1000bab4);
    if (iVar2 == 0) {
      lma___wrap_printf(DAT_1000bab0,DAT_1000baac,0x1a5);
    }
  }
  else {
    lma___wrap_printf(DAT_1000bab0,DAT_1000baac,0x192);
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== lma_tusb_inited @ 1000badc (14 bytes) ===== */

int lma_tusb_inited(void)

{
  int iVar1;
  
  iVar1 = lma_tuh_inited();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


/* ===== lma_tu_edpt_validate @ 1000baec (156 bytes) ===== */

undefined4 lma_tu_edpt_validate(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar2 = (uint)*(byte *)(param_1 + 4) | (*(byte *)(param_1 + 5) & 7) << 8;
  bVar3 = *(byte *)(param_1 + 3) & 3;
  if (bVar3 == 2) {
    if (param_2 == 2) {
      if (uVar2 == 0x200) {
        uVar1 = 1;
      }
      else {
        lma___wrap_printf(DAT_1000bb90,DAT_1000bb8c,0x58);
        uVar1 = 0;
      }
    }
    else if (uVar2 < 0x41) {
      uVar1 = 1;
    }
    else {
      lma___wrap_printf(DAT_1000bb90,DAT_1000bb8c,0x5c);
      uVar1 = 0;
    }
  }
  else if (bVar3 == 3) {
    if (param_2 == 2) {
      uVar4 = 0x400;
    }
    else {
      uVar4 = 0x40;
    }
    if (uVar4 < uVar2) {
      lma___wrap_printf(DAT_1000bb90,DAT_1000bb8c,99);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (bVar3 == 1) {
    uVar4 = DAT_1000bb88;
    if (param_2 == 2) {
      uVar4 = 0x400;
    }
    if (uVar4 < uVar2) {
      lma___wrap_printf(DAT_1000bb90,DAT_1000bb8c,0x50);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== lma_advance_pointer @ 1000bbfc (24 bytes) ===== */

uint lma_advance_pointer(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3 & 0xffff;
  if ((uVar1 < param_2) || (*(ushort *)(param_1 + 0xc) < uVar1)) {
    uVar1 = uVar1 + *(ushort *)(param_1 + 10) & 0xffff;
  }
  return uVar1;
}


/* ===== lma_backward_pointer @ 1000bc14 (30 bytes) ===== */

uint lma_backward_pointer(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_2 < param_3) ||
     (uVar1 = param_2 - param_3 & 0xffff, *(ushort *)(param_1 + 0xc) < uVar1)) {
    uVar1 = (param_2 - param_3 & 0xffff) - (uint)*(ushort *)(param_1 + 10) & 0xffff;
  }
  return uVar1;
}


/* ===== lma_get_relative_pointer @ 1000bc32 (16 bytes) ===== */

uint lma_get_relative_pointer(int param_1,uint param_2)

{
  for (; *(ushort *)(param_1 + 4) <= param_2; param_2 = param_2 - *(ushort *)(param_1 + 4) & 0xffff)
  {
  }
  return param_2;
}


/* ===== lma__tu_fifo_peek @ 1000bc42 (80 bytes) ===== */

bool lma__tu_fifo_peek(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_3 - param_4 & 0xffff;
  if (param_3 < param_4) {
    uVar3 = uVar3 - *(ushort *)((int)param_1 + 10) & 0xffff;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 1);
  if (uVar4 < uVar3) {
    uVar1 = lma_backward_pointer(param_1,param_3,uVar4);
    *(undefined2 *)(param_1 + 4) = uVar1;
    uVar3 = uVar4;
  }
  if (uVar3 != 0) {
    iVar2 = lma_get_relative_pointer(param_1,param_4);
    lma_memcpy(param_2,*param_1 + (uint)*(ushort *)((int)param_1 + 6) * iVar2);
  }
  return uVar3 != 0;
}


/* ===== lma_tu_fifo_read @ 1000bc92 (66 bytes) ===== */

uint lma_tu_fifo_read(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x18),0xffffffff);
  }
  uVar2 = lma__tu_fifo_peek(param_1,param_2,*(undefined2 *)(param_1 + 0xe),
                            *(undefined2 *)(param_1 + 0x10));
  uVar1 = lma_advance_pointer(param_1,*(undefined2 *)(param_1 + 0x10),uVar2 & 0xffff);
  *(undefined2 *)(param_1 + 0x10) = uVar1;
  if (*(int *)(param_1 + 0x18) != 0) {
    lma_mutex_exit();
  }
  return uVar2;
}


/* ===== lma_tu_fifo_write @ 1000bcd4 (108 bytes) ===== */

char lma_tu_fifo_write(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  short sVar5;
  
  if (param_1[5] != 0) {
    lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms(param_1[5],0xffffffff);
  }
  uVar1 = *(ushort *)((int)param_1 + 0xe);
  sVar5 = uVar1 - *(ushort *)(param_1 + 4);
  if (uVar1 < *(ushort *)(param_1 + 4)) {
    sVar5 = sVar5 - *(short *)((int)param_1 + 10);
  }
  if ((*(short *)(param_1 + 1) != sVar5) || (cVar2 = *(char *)(param_1 + 2), cVar2 != '\0')) {
    iVar4 = lma_get_relative_pointer(param_1,uVar1);
    lma_memcpy((uint)*(ushort *)((int)param_1 + 6) * iVar4 + *param_1,param_2);
    uVar3 = lma_advance_pointer(param_1,uVar1,1);
    *(undefined2 *)((int)param_1 + 0xe) = uVar3;
    if (param_1[5] == 0) {
      cVar2 = '\x01';
    }
    else {
      lma_mutex_exit();
      cVar2 = '\x01';
    }
  }
  return cVar2;
}


/* ===== lma_tu_fifo_clear @ 1000bd40 (76 bytes) ===== */

undefined4 lma_tu_fifo_clear(int param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x14),0xffffffff);
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x18),0xffffffff);
  }
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  uVar1 = *(short *)(param_1 + 4) * 2 - 1;
  *(ushort *)(param_1 + 0xc) = uVar1;
  *(ushort *)(param_1 + 10) = ~uVar1;
  if (*(int *)(param_1 + 0x14) != 0) {
    lma_mutex_exit();
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    lma_mutex_exit();
  }
  return 1;
}


/* ===== lma___aeabi_idiv0 @ 1000bd8c (2 bytes) ===== */

void lma___aeabi_idiv0(void)

{
  return;
}


/* ===== lma_memcmp @ 1000bd90 (70 bytes) ===== */

int lma_memcmp(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (3 < param_3) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_1000bdb6;
    do {
      if (*param_1 != *param_2) goto LAB_1000bdb6;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_1000bdb6:
  iVar1 = 0;
  do {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    bVar2 = param_3 - 1 != iVar1;
    iVar1 = iVar1 + 1;
  } while (bVar2);
  return 0;
}


/* ===== lma_strchr @ 1000bdd8 (182 bytes) ===== */

uint * lma_strchr(uint *param_1,char param_2)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == '\0') {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if (*(char *)param_1 == '\0') {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar4 = *param_1 + DAT_1000be90 & ~*param_1;
    while ((uVar4 & DAT_1000be94) == 0) {
      puVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      uVar4 = *puVar1 + DAT_1000be90 & ~*puVar1;
    }
    cVar3 = *(char *)param_1;
    while (cVar3 != '\0') {
      pcVar2 = (char *)((int)param_1 + 1);
      param_1 = (uint *)((int)param_1 + 1);
      cVar3 = *pcVar2;
    }
  }
  else {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if (*(char *)param_1 == '\0') {
        return (uint *)0x0;
      }
      if (*(char *)param_1 == param_2) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar6 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    uVar5 = *param_1;
    uVar4 = uVar6 ^ uVar5;
    if (((uVar4 + DAT_1000be90 & ~uVar4 | uVar5 + DAT_1000be90 & ~uVar5) & DAT_1000be94) != 0)
    goto LAB_1000be2e;
    do {
      uVar4 = param_1[1];
      uVar5 = uVar4 ^ uVar6;
      param_1 = param_1 + 1;
    } while (((uVar4 + DAT_1000be90 & ~uVar4 | uVar5 + DAT_1000be90 & ~uVar5) & DAT_1000be94) == 0);
    cVar3 = *(char *)param_1;
    while (cVar3 != '\0') {
      if (param_2 == cVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
LAB_1000be2e:
      cVar3 = *(char *)param_1;
    }
    param_1 = (uint *)0x0;
  }
  return param_1;
}


/* ===== lma_strlen @ 1000be98 (84 bytes) ===== */

int lma_strlen(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = (uint)param_1 & 3;
  puVar2 = param_1;
  while (uVar1 != 0) {
    if (*(char *)puVar2 == '\0') goto LAB_1000beb0;
    puVar2 = (uint *)((int)puVar2 + 1);
    uVar1 = (uint)puVar2 & 3;
  }
  uVar1 = *puVar2 + DAT_1000beec & ~*puVar2;
  puVar3 = puVar2;
  while ((puVar2 = puVar3, (uVar1 & DAT_1000bef0) == 0 &&
         (puVar2 = puVar3 + 1, (puVar3[1] + DAT_1000beec & ~puVar3[1] & DAT_1000bef0) == 0))) {
    puVar2 = puVar3 + 2;
    puVar3 = puVar3 + 2;
    uVar1 = *puVar2 + DAT_1000beec & ~*puVar2;
  }
  for (; *(char *)puVar2 != '\0'; puVar2 = (uint *)((int)puVar2 + 1)) {
  }
LAB_1000beb0:
  return (int)puVar2 - (int)param_1;
}


/* ===== lma_____get_current_exception_veneer @ 1000bef8 (10 bytes) ===== */

void lma_____get_current_exception_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1000bf00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1000bf04)(param_1);
  return;
}


/* ===== lma_mutex_enter_blocking @ 1000bf08 (72 bytes) ===== */

void lma_mutex_enter_blocking(int **param_1)

{
  bool bVar1;
  undefined uVar2;
  uint uVar3;
  
  uVar2 = (undefined)DAT_d0000000;
  while( true ) {
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**param_1 == 0);
    DataMemoryBarrier(0x1f);
    if (*(char *)(param_1 + 1) < '\0') break;
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    WaitForEvent();
  }
  *(undefined *)(param_1 + 1) = uVar2;
  DataMemoryBarrier(0x1f);
  **param_1 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== lma_mutex_try_enter @ 1000bf50 (70 bytes) ===== */

undefined4 lma_mutex_try_enter(int **param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**param_1 == 0);
  DataMemoryBarrier(0x1f);
  if (*(char *)(param_1 + 1) < 0) {
    *(undefined *)(param_1 + 1) = (undefined)DAT_d0000000;
    uVar2 = 1;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    *param_2 = (int)*(char *)(param_1 + 1);
    uVar2 = 0;
  }
  DataMemoryBarrier(0x1f);
  **param_1 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return uVar2;
}


/* ===== lma_mutex_enter_block_until @ 1000bf98 (126 bytes) ===== */

undefined4
lma_mutex_enter_block_until(int **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (undefined)DAT_d0000000;
  if (*param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000c020,0x7a,DAT_1000c01c,DAT_1000c018);
  }
  do {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**param_1 == 0);
    DataMemoryBarrier(0x1f);
    if (*(char *)(param_1 + 1) < '\0') {
      *(undefined *)(param_1 + 1) = uVar2;
      DataMemoryBarrier(0x1f);
      **param_1 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar4 & 1) == 1);
      }
      return 1;
    }
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    iVar3 = lma_best_effort_wfe_or_timeout(param_3,param_4);
  } while (iVar3 == 0);
                    /* WARNING: Read-only address (ram,0xd0000000) is written */
  return 0;
}


/* ===== lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms @ 1000c024 (104 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x1000c058) */

void lma_mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = lma_time_us_64();
  if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    lma___assert_func(DAT_1000c094,0x3f,DAT_1000c090,DAT_1000c08c);
  }
  lVar3 = lma___wrap___aeabi_lmul(param_2,0,1000,0);
  iVar1 = (int)(lVar3 + uVar2 >> 0x20);
  if (lVar3 + uVar2 < uVar2) {
    iVar1 = -1;
  }
  if (-1 < iVar1) {
    lma_mutex_enter_block_until(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_1000c094,0x3f,DAT_1000c090,DAT_1000c08c);
}


/* ===== lma_mutex_exit @ 1000c098 (62 bytes) ===== */

void lma_mutex_exit(int **param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**param_1 == 0);
  DataMemoryBarrier(0x1f);
  if (-1 < *(char *)(param_1 + 1)) {
    *(undefined *)(param_1 + 1) = 0xff;
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  lma___assert_func(DAT_1000c0e0,0xa9,DAT_1000c0dc,DAT_1000c0d8);
}


/* ===== lma_spi_write_read_blocking @ 1000c0e4 (66 bytes) ===== */

uint lma_spi_write_read_blocking(int param_1,byte *param_2,undefined *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_4;
  uVar2 = param_4;
  while ((param_4 | uVar2) != 0) {
    if (((uVar2 != 0) && (*(int *)(param_1 + 0xc) << 0x1e < 0)) && (param_4 < uVar2 + 8)) {
      *(uint *)(param_1 + 8) = (uint)*param_2;
      uVar2 = uVar2 - 1;
      param_2 = param_2 + 1;
    }
    if ((param_4 != 0) && (*(int *)(param_1 + 0xc) << 0x1d < 0)) {
      *param_3 = (char)*(undefined4 *)(param_1 + 8);
      param_4 = param_4 - 1;
      param_3 = param_3 + 1;
    }
  }
  return uVar1;
}


/* ===== lma_spi_write_blocking @ 1000c126 (58 bytes) ===== */

void lma_spi_write_blocking(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(param_1 + 0xc) << 0x1e);
    *(uint *)(param_1 + 8) = (uint)*(byte *)(param_2 + uVar1);
  }
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1d < 0);
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1b < 0);
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1d < 0);
  *(undefined4 *)(param_1 + 0x20) = 1;
  return;
}


/* ===== lma_spi_read_blocking @ 1000c160 (62 bytes) ===== */

uint lma_spi_read_blocking(int param_1,undefined4 param_2,undefined *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_4;
  uVar2 = param_4;
  while ((param_4 | uVar2) != 0) {
    if (((uVar2 != 0) && (*(int *)(param_1 + 0xc) << 0x1e < 0)) && (param_4 < uVar2 + 8)) {
      *(undefined4 *)(param_1 + 8) = param_2;
      uVar2 = uVar2 - 1;
    }
    if ((param_4 != 0) && (*(int *)(param_1 + 0xc) << 0x1d < 0)) {
      *param_3 = (char)*(undefined4 *)(param_1 + 8);
      param_4 = param_4 - 1;
      param_3 = param_3 + 1;
    }
  }
  return uVar1;
}


/* ===== FUN_200000ec @ 200000ec (16 bytes) ===== */

undefined8 FUN_200000ec(undefined4 param_1,undefined4 param_2)

{
  if (DAT_20000100 != 0) {
    param_1 = DAT_20000108;
    param_2 = DAT_20000104;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== core1_sio_irq_handler @ 2000010c (34 bytes) ===== */

void core1_sio_irq_handler(void)

{
  undefined uVar1;
  
  if (DAT_d0000050 << 0x1f < 0) {
    uVar1 = multicore_fifo_pop_blocking();
    *DAT_20000130 = uVar1;
  }
  DAT_d0000050 = 0xff;
  return;
}


/* ===== core1_usb_task @ 20000134 (66 bytes) ===== */

void core1_usb_task(void)

{
  char *pcVar1;
  
  tusb_init();
  *DAT_20000178 = '\0';
  DAT_d0000050 = 0xff;
  irq_set_exclusive_handler(0x10,DAT_2000017c);
  irq_set_enabled(0x10,1);
  do {
    do {
      tuh_task();
      pcVar1 = DAT_20000178;
    } while (*DAT_20000178 == '\0');
    usb_msc_service_request(*DAT_20000178,DAT_20000180);
    *pcVar1 = '\0';
  } while( true );
}


/* ===== try_boot_app @ 20000184 (80 bytes) ===== */

void try_boot_app(void)

{
  bool bVar1;
  uint *puVar2;
  
  puVar2 = DAT_200001d4;
  __wrap_printf(DAT_200001d8,*DAT_200001d4,DAT_200001d4[1]);
  if ((((0x1fffffff < *puVar2) && (DAT_200001dc < puVar2[1])) && (*puVar2 <= DAT_200001e0)) &&
     (puVar2[1] < 0x11000000)) {
    __wrap_printf(DAT_200001e4);
    *DAT_200001e8 = puVar2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setMainStackPointer(*puVar2);
    }
                    /* WARNING: Could not recover jumptable at 0x200001d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar2[1])(*puVar2,(code *)puVar2[1],puVar2 + 2);
    return;
  }
  return;
}


/* ===== main @ 200001ec (804 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar6;
  undefined4 extraout_r1_01;
  uint uVar7;
  uint uVar8;
  
  iVar2 = DAT_20000510;
  stdio_uart_init_full(DAT_20000518,DAT_20000514,0x10,0x11);
  iVar3 = watchdog_caused_reboot();
  if (iVar3 == 0) {
LAB_200002ce:
    __wrap_puts(DAT_20000540);
    watchdog_enable(500);
    iVar3 = DAT_2000051c;
    *(int *)(DAT_2000051c + 0xc) = DAT_20000524;
    *(int *)(iVar3 + 0x10) = DAT_20000528;
    *(uint *)(iVar3 + 0x14) = DAT_20000520;
    try_boot_app();
    __wrap_puts(DAT_20000544);
    iVar3 = 4;
  }
  else if (*(uint *)(DAT_2000051c + 0xc) == DAT_20000520) {
    if (*(int *)(DAT_2000051c + 0x10) == DAT_20000524) {
      if (*(int *)(DAT_2000051c + 0x14) == DAT_20000528) goto LAB_200002ce;
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar4 = DAT_2000051c;
  if (((*(int *)(DAT_2000051c + 0xc) == DAT_20000524) &&
      (*(int *)(DAT_2000051c + 0x10) == DAT_20000528)) &&
     (*(uint *)(DAT_2000051c + 0x14) == DAT_20000520)) {
    iVar3 = 1;
  }
  if (((*(int *)(DAT_2000051c + 0xc) == DAT_20000528) &&
      (*(int *)(DAT_2000051c + 0x10) == DAT_20000524)) &&
     ((*(uint *)(DAT_2000051c + 0x14) & 0xffff0000) == DAT_20000520)) {
    iVar3 = 2;
  }
  else if (iVar3 == 1) {
    uVar7 = 1;
    goto LAB_20000238;
  }
  uVar7 = *(uint *)(DAT_2000051c + 0x14) & 0xffff;
LAB_20000238:
  *(undefined4 *)(DAT_2000051c + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  *(undefined4 *)(iVar4 + 0x14) = 0;
  board_init();
  __wrap_printf(DAT_2000052c,iVar3,uVar7);
  usb_disk_set_nodisk();
  memcpy(_FUN_20000530,0,0x200);
  DAT_d0000014 = 0x2000000;
  if (uVar7 == 2) {
    multicore_launch_core1(DAT_20000548);
    do {
      while (iVar3 = usb_disk_status(), iVar3 << 0x1e < 0) {
        sleep_ms(100);
      }
      sleep_ms(100);
      iVar3 = f_mount(DAT_20000550,DAT_2000054c,1);
      if (iVar3 == 0) {
        __wrap_puts(DAT_20000554);
        iVar3 = f_opendir(&stack0xffffffec + iVar2,DAT_20000558);
        if (iVar3 == 0) {
          __wrap_puts(DAT_2000055c);
          uVar6 = DAT_2000054c;
          iVar3 = f_chdrive(DAT_2000054c);
          f_chdir(uVar6);
          if (iVar3 == 0) {
            __wrap_puts(DAT_20000560);
            iVar3 = f_open(&stack0x00000044 + iVar2,DAT_20000564,1);
            if (iVar3 == 0) {
              __wrap_puts(DAT_20000568);
              f_close(&stack0x00000044 + iVar2);
            }
          }
        }
      }
    } while (iVar3 != 0);
  }
  else {
    iVar3 = f_mount(&DAT_2000e0e8,uRam20000534,1);
  }
  if (iVar3 != 0) {
    __wrap_printf(DAT_2000056c,iVar3);
  }
  connect_internal_flash();
  flash_exit_xip();
  if (iVar3 == 0) {
    iVar3 = f_open(&stack0x00000044 + iVar2,DAT_20000564,1);
    if (iVar3 == 0) {
      uVar7 = *(uint *)(&stack0x00000054 + iVar2);
      __wrap_printf(DAT_20000570,uVar7);
      bVar1 = true;
      uVar6 = extraout_r1;
      iVar4 = iVar3;
      for (uVar8 = 0; uVar8 < uVar7; uVar8 = uVar8 + 0x1000) {
        iVar4 = f_read(&stack0x00000044 + iVar2,&DAT_2000f084,0x1000,&stack0xffffffe8 + iVar2);
        if (iVar4 != 0) {
          __wrap_printf(DAT_20000578,iVar4);
          uVar6 = extraout_r1_00;
          break;
        }
        flash_sector_erase(uVar8 + 0x10000);
        flash_range_program(uVar8 + 0x10000,&DAT_2000f084,0x1000);
        __wrap_printf(DAT_2000057c,uVar8);
        watchdog_update();
        bVar1 = (bool)(bVar1 ^ 1);
        if (bVar1) {
          DAT_d0000014 = 0x2000000;
        }
        else {
          DAT_d0000018 = 0x2000000;
        }
        uVar6 = extraout_r1_01;
      }
      f_lseek(&stack0x00000044 + iVar2,uVar6,0,0);
      for (uVar8 = 0; uVar8 < uVar7; uVar8 = uVar8 + 0x1000) {
        flash_read_data(uVar8 + 0x10000,DAT_20000584,0x1000);
        iVar4 = f_read(&stack0x00000044 + iVar2,&DAT_2000f084,0x1000,&stack0xffffffe8 + iVar2);
        if (iVar4 != 0) {
          __wrap_printf(DAT_20000578,iVar4);
          break;
        }
        __wrap_printf(DAT_20000588,uVar8,*(undefined4 *)(&stack0xffffffe8 + iVar2));
        iVar5 = memcmp(&DAT_2000f084,DAT_20000584,*(undefined4 *)(&stack0xffffffe8 + iVar2));
        if (iVar5 != 0) {
          __wrap_puts(DAT_20000580);
          iVar4 = 0xff;
          break;
        }
        watchdog_update();
        bVar1 = (bool)(bVar1 ^ 1);
        if (bVar1) {
          DAT_d0000014 = 0x2000000;
        }
        else {
          DAT_d0000018 = 0x2000000;
        }
      }
      if (uVar8 < uVar7) {
        iVar3 = iVar4;
      }
      f_close(&stack0x00000044 + iVar2);
    }
    else {
      __wrap_printf(DAT_20000574,iVar3);
    }
  }
  iVar2 = DAT_2000051c;
  if (iVar3 == 0) {
    *(uint *)(DAT_2000051c + 0xc) = DAT_20000520;
    *(int *)(iVar2 + 0x10) = DAT_20000524;
    *(int *)(iVar2 + 0x14) = DAT_20000528;
    __wrap_puts(DAT_2000058c);
  }
  else {
    *(undefined4 *)(DAT_2000051c + 0xc) = 0;
    *(int *)(iVar2 + 0x10) = DAT_20000524;
    *(int *)(iVar2 + 0x14) = DAT_20000528;
    __wrap_puts(DAT_2000053c);
  }
  watchdog_enable(100,1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ===== FUN_20000530 @ 20000530 (10 bytes) ===== */

void FUN_20000530(void)

{
  undefined4 in_r3;
  undefined4 *unaff_r4;
  uint *unaff_r5;
  undefined4 unaff_r6;
  uint *unaff_r7;
  undefined8 uVar1;
  
  *unaff_r4 = in_r3;
  unaff_r4[1] = unaff_r4;
  unaff_r4[5] = in_r3;
  unaff_r4[5] = unaff_r6;
  gpio_set_pulls(0xd,1,0);
  *DAT_200007b8 = 0;
  gpio_init(5);
  unaff_r4[9] = 0x20;
  unaff_r4[5] = 0x20;
  gpio_set_pulls(4,1,0);
  *(uint *)((uint)unaff_r5 | 0x1000) = (*unaff_r5 ^ 7) & 0xcf;
  *(uint *)((uint)unaff_r7 | 0x1000) = (*unaff_r7 ^ 7) & 0xcf;
  gpio_set_function(0x1b,3);
  gpio_set_function(0x1a,3);
  gpio_set_pulls(0x1b,1,0);
  gpio_set_pulls(0x1a,1,0);
  i2c_init(DAT_200007bc);
  *DAT_200007c0 = 0;
  uVar1 = alarm_pool_get_default();
  alarm_pool_add_repeating_timer_us
            ((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_200007cc,0xffffffff);
  return;
}


/* ===== FUN_20000590 @ 20000590 (100 bytes) ===== */

void FUN_20000590(void)

{
  uint *puVar1;
  
  *DAT_200005f4 = *DAT_200005f4 + 10;
  if (*DAT_200005f8 < 0xb) {
    *DAT_200005f8 = 0;
    DAT_d0000018 = 0x2000000;
  }
  else {
    *DAT_200005f8 = *DAT_200005f8 - 10;
  }
  puVar1 = DAT_200005fc;
  *DAT_200005fc = *DAT_200005fc << 1;
  *puVar1 = (uint)((DAT_d0000004 >> 0x1c & 1) == 0) | *puVar1;
  puVar1 = DAT_20000600;
  *DAT_20000600 = *DAT_20000600 << 1;
  *puVar1 = (uint)((DAT_d0000004 >> 0x13 & 1) == 0) | *puVar1;
  return;
}


/* ===== board_init @ 20000604 (418 bytes) ===== */

void board_init(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  gpio_init(0x19);
  puVar2 = DAT_200007ac;
  uVar1 = DAT_200007a8;
  spi_init(DAT_200007ac,DAT_200007a8);
  puVar3 = DAT_200007b0;
  spi_init(DAT_200007b0,DAT_200007b4);
  gpio_set_function(4,1);
  gpio_set_function(3,1);
  gpio_set_function(2,1);
  gpio_init(0x13);
  gpio_set_function(10,1);
  gpio_set_function(8,1);
  gpio_set_function(0xb,1);
  gpio_init(0x19);
  gpio_init(9);
  gpio_init(0xe);
  gpio_init(0xd);
  gpio_init(0x14);
  gpio_init(0x15);
  gpio_init(0x16);
  gpio_init(0x1c);
  DAT_d0000028 = 0x80000;
  DAT_d0000024 = 0x2000000;
  DAT_d0000014 = 0x2000000;
  gpio_set_drive_strength(0x19,3);
  gpio_set_pulls(0x13,1,0);
  DAT_d0000024 = 0x4000;
  gpio_set_drive_strength(9,3);
  gpio_set_drive_strength(10,3);
  gpio_set_drive_strength(0xb,3);
  gpio_set_drive_strength(0x16,3);
  DAT_d0000018 = 0x400000;
  DAT_d0000014 = 0x4000;
  gpio_set_pulls(0xd,1,0);
  *DAT_200007b8 = 0;
  gpio_init(5);
  DAT_d0000024 = 0x20;
  DAT_d0000014 = 0x20;
  gpio_set_pulls(4,1,0);
  *(uint *)((uint)puVar2 | 0x1000) = (*puVar2 ^ 7) & 0xcf;
  *(uint *)((uint)puVar3 | 0x1000) = (*puVar3 ^ 7) & 0xcf;
  gpio_set_function(0x1b,3);
  gpio_set_function(0x1a,3);
  gpio_set_pulls(0x1b,1,0);
  gpio_set_pulls(0x1a,1,0);
  i2c_init(DAT_200007bc,uVar1);
  *DAT_200007c0 = 0;
  uVar4 = alarm_pool_get_default();
  alarm_pool_add_repeating_timer_us
            ((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_200007cc,0xffffffff,DAT_200007c8,0,
             DAT_200007c4);
  return;
}


/* ===== sd_spi_set_speed @ 200007d0 (16 bytes) ===== */

void sd_spi_set_speed(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_200007ec;
  if (param_1 != 0) {
    uVar1 = DAT_200007e4;
  }
  spi_set_baudrate(DAT_200007e8,uVar1);
  return;
}


/* ===== sd_spi_set_slow @ 200007e0 (4 bytes) ===== */

void sd_spi_set_slow(void)

{
  spi_set_baudrate(DAT_200007e8,DAT_200007ec);
  return;
}


/* ===== ld_word @ 200007f0 (10 bytes) ===== */

undefined2 ld_word(undefined2 *param_1)

{
  return *param_1;
}


/* ===== ld_dword @ 200007fa (24 bytes) ===== */

undefined4 ld_dword(undefined4 *param_1)

{
  return *param_1;
}


/* ===== ld_qword @ 20000812 (66 bytes) ===== */

undefined8 ld_qword(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ((uint)param_1[3] | *(int *)(param_1 + 4) << 8) << 8;
  uVar2 = (param_1[2] | uVar1) << 8;
  return CONCAT44((((((uint)*(uint3 *)(param_1 + 5) << 8) >> 0x18) << 8 |
                   (uint)(*(int *)(param_1 + 4) << 8) >> 0x18) << 8 | uVar1 >> 0x18) << 8 |
                  uVar2 >> 0x18,(uint)*param_1 | (param_1[1] | uVar2) << 8);
}


/* ===== st_word @ 20000854 (8 bytes) ===== */

void st_word(undefined *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  return;
}


/* ===== st_dword @ 2000085c (16 bytes) ===== */

void st_dword(undefined *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


/* ===== st_qword @ 2000086c (30 bytes) ===== */

void st_qword(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = (char)param_3;
  param_1[1] = (char)((uint)param_3 >> 8);
  param_1[2] = (char)((uint)param_3 >> 0x10);
  param_1[3] = (char)((uint)param_3 >> 0x18);
  param_1[4] = (char)param_4;
  param_1[5] = (char)((uint)param_4 >> 8);
  param_1[6] = (char)((uint)param_4 >> 0x10);
  param_1[7] = (char)((uint)param_4 >> 0x18);
  return;
}


/* ===== dbc_1st__or__dbc_2nd @ 2000088a (4 bytes) ===== */

undefined4 dbc_1st__or__dbc_2nd(void)

{
  return 0;
}


/* ===== tchar2uni @ 20000890 (192 bytes) ===== */

uint tchar2uni(byte **param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = *param_1 + 1;
  bVar1 = **param_1;
  uVar5 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    if ((uVar5 & 0xffffffe0) == 0xc0) {
      uVar5 = uVar5 & 0x1f;
      iVar4 = 1;
    }
    else if ((uVar5 & 0xfffffff0) == 0xe0) {
      uVar5 = uVar5 & 0xf;
      iVar4 = 2;
    }
    else {
      if ((uVar5 & 0xfffffff8) != 0xf0) {
        return 0xffffffff;
      }
      uVar5 = uVar5 & 7;
      iVar4 = 3;
    }
    do {
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      if ((bVar1 & 0xffffffc0) != 0x80) {
        return 0xffffffff;
      }
      uVar3 = uVar5 << 6;
      uVar2 = bVar1 & 0x3f;
      uVar5 = uVar2 | uVar3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (uVar5 < 0x80) {
      return 0xffffffff;
    }
    if (uVar5 + DAT_20000950 < 0x800) {
      return 0xffffffff;
    }
    if (0x10ffff < uVar5) {
      return 0xffffffff;
    }
    if (0xffff < uVar5) {
      uVar5 = DAT_2000095c | (uVar5 + DAT_20000954) * 0x40 & DAT_20000958 | uVar2 | uVar3 & 0x3ff;
    }
  }
  *param_1 = pbVar6;
  return uVar5;
}


/* ===== clst2sect @ 20000960 (40 bytes) ===== */

longlong clst2sect(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 - 2U < *(int *)(param_1 + 0x2c) - 2U) {
    lVar1 = *(longlong *)(param_1 + 0x50);
    lVar2 = __wrap___aeabi_lmul(param_2 - 2U,0,*(undefined2 *)(param_1 + 10),0);
    lVar2 = lVar2 + lVar1;
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}


/* ===== ld_clust @ 20000988 (38 bytes) ===== */

uint ld_clust(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = ld_word(param_2 + 0x1a);
  if (*param_1 == '\x03') {
    iVar2 = ld_word(param_2 + 0x14);
    uVar1 = iVar2 << 0x10 | uVar1;
  }
  return uVar1;
}


/* ===== st_clust @ 200009ae (38 bytes) ===== */

void st_clust(char *param_1,int param_2,uint param_3)

{
  st_word(param_2 + 0x1a,param_3 & 0xffff);
  if (*param_1 == '\x03') {
    st_word(param_2 + 0x14,param_3 >> 0x10);
  }
  return;
}


/* ===== pick_lfn @ 200009d4 (140 bytes) ===== */

undefined4 pick_lfn(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = ld_word(param_2 + 0x1a);
  if (iVar1 == 0) {
    uVar5 = ((*param_2 & 0xffffffbf) - 1) * 0xd;
    iVar1 = 1;
    for (uVar4 = 0; uVar4 < 0xd; uVar4 = uVar4 + 1) {
      iVar2 = ld_word(param_2 + *(byte *)(DAT_20000a64 + uVar4));
      if (iVar1 == 0) {
        if (iVar2 != DAT_20000a60) {
          return 0;
        }
      }
      else {
        if (0xff < uVar5) {
          return 0;
        }
        *(short *)(param_1 + uVar5 * 2) = (short)iVar2;
        uVar5 = uVar5 + 1;
        iVar1 = iVar2;
      }
    }
    if ((int)((uint)*param_2 << 0x19) < 0) {
      if (iVar1 == 0) {
        uVar3 = 1;
      }
      else if (uVar5 < 0x100) {
        *(undefined2 *)(uVar5 * 2 + param_1) = 0;
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== put_lfn @ 20000a68 (130 bytes) ===== */

void put_lfn(int param_1,undefined *param_2,uint param_3,undefined param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  param_2[0xd] = param_4;
  param_2[0xb] = 0xf;
  param_2[0xc] = 0;
  st_word(param_2 + 0x1a,0);
  iVar3 = (param_3 - 1) * 0xd;
  uVar1 = 0;
  uVar2 = 0;
  do {
    if (uVar1 != DAT_20000aec) {
      uVar1 = (uint)*(ushort *)(param_1 + iVar3 * 2);
      iVar3 = iVar3 + 1;
    }
    st_word(param_2 + *(byte *)(DAT_20000af0 + uVar2),uVar1);
    if (uVar1 == 0) {
      uVar1 = DAT_20000aec;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xd);
  if ((uVar1 == DAT_20000aec) || (*(short *)(iVar3 * 2 + param_1) == 0)) {
    param_3 = param_3 & 0xff | 0x40;
  }
  *param_2 = (char)param_3;
  return;
}


/* ===== sum_sfn @ 20000af4 (32 bytes) ===== */

uint sum_sfn(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0xb;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (uVar2 >> 1 | (uVar2 & 1) << 7) + (uint)bVar1 & 0xff;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar2;
}


/* ===== xdir_sum @ 20000b14 (46 bytes) ===== */

uint xdir_sum(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < (*(byte *)(param_1 + 1) + 1) * 0x20; uVar2 = uVar2 + 1) {
    if (uVar2 == 2) {
      uVar2 = 3;
    }
    else {
      uVar1 = ((uVar1 >> 1) + uVar1 * 0x8000 & 0xffff) + (uint)*(byte *)(param_1 + uVar2) & 0xffff;
    }
  }
  return uVar1;
}


/* ===== init_alloc_info @ 20000b42 (46 bytes) ===== */

void init_alloc_info(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = ld_dword(*(int *)(param_1 + 0x10) + 0x34);
  *(undefined4 *)(param_2 + 8) = uVar1;
  uVar2 = ld_qword(*(int *)(param_1 + 0x10) + 0x38);
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  *(byte *)(param_2 + 7) = *(byte *)(*(int *)(param_1 + 0x10) + 0x21) & 2;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}


/* ===== get_ldnumber @ 20000b70 (192 bytes) ===== */

uint get_ldnumber(byte **param_1)

{
  uint uVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  pbVar5 = *param_1;
  pbVar3 = pbVar5;
  if (pbVar5 == (byte *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    do {
      bVar4 = *pbVar3;
      pbVar3 = pbVar3 + 1;
      if (bVar4 < 0x20) break;
    } while (bVar4 != 0x3a);
    if (bVar4 == 0x3a) {
      if ((*pbVar5 - 0x30 & 0xff) < 10) {
        if (pbVar5 + 2 == pbVar3) {
          uVar1 = *pbVar5 - 0x30;
          if ((int)uVar1 < 2) {
            *param_1 = pbVar3;
          }
          else {
            uVar1 = 0xffffffff;
          }
        }
        else {
          uVar1 = 0xffffffff;
        }
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else if (*pbVar5 == 0x2f) {
      for (; pbVar5[1] == 0x2f; pbVar5 = pbVar5 + 1) {
      }
      uVar1 = 0;
      do {
        pbVar6 = *(byte **)(uVar1 * 4 + DAT_20000c34);
        pbVar3 = pbVar5;
        do {
          bVar4 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          pbVar3 = pbVar3 + 1;
          bVar2 = *pbVar3;
          if ((byte)(bVar4 + 0x9f) < 0x1a) {
            bVar4 = bVar4 - 0x20;
          }
          if ((byte)(bVar2 + 0x9f) < 0x1a) {
            bVar2 = bVar2 - 0x20;
          }
        } while ((bVar4 != 0) && (bVar2 == bVar4));
      } while (((bVar4 != 0) || ((bVar2 != 0x2f && (0x1f < bVar2)))) &&
              (uVar1 = uVar1 + 1, (int)uVar1 < 2));
      if ((int)uVar1 < 2) {
        *param_1 = pbVar3;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = (uint)*DAT_20000c30;
    }
  }
  return uVar1;
}


/* ===== crc32 @ 20000c38 (40 bytes) ===== */

void crc32(uint param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 1; uVar1 != 0; uVar1 = (uVar1 & 0x7f) << 1) {
    if ((int)((param_1 ^ (param_2 & uVar1) != 0) << 0x1f) < 0) {
      param_1 = DAT_20000c60 ^ param_1 >> 1;
    }
    else {
      param_1 = param_1 >> 1;
    }
  }
  return;
}


/* ===== validate @ 20000c64 (82 bytes) ===== */

uint validate(char **param_1,char **param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1 == (char **)0x0) {
    uVar1 = 9;
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = *param_1;
    if (pcVar3 == (char *)0x0) {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
    else if (*pcVar3 == '\0') {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
    else if (*(short *)(param_1 + 1) == *(short *)(pcVar3 + 6)) {
      uVar2 = disk_status(pcVar3[1]);
      uVar1 = uVar2 & 1;
      if ((uVar2 & 1) == 0) {
        pcVar3 = *param_1;
      }
      else {
        uVar1 = 9;
        pcVar3 = (char *)0x0;
      }
    }
    else {
      uVar1 = 9;
      pcVar3 = (char *)0x0;
    }
  }
  *param_2 = pcVar3;
  return uVar1;
}


/* ===== test_gpt_header @ 20000cb8 (96 bytes) ===== */

undefined4 test_gpt_header(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = memcmp(param_1,DAT_20000d18,0x10);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    for (uVar4 = 0; uVar4 < 0x5c; uVar4 = uVar4 + 1) {
      if (uVar4 - 0x10 < 4) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined *)(param_1 + uVar4);
      }
      uVar2 = crc32(uVar2,uVar3);
    }
    uVar4 = ld_dword(param_1 + 0x10);
    uVar5 = 0;
    if (((~uVar2 == uVar4) && (iVar1 = ld_dword(param_1 + 0x54), iVar1 == 0x80)) &&
       (uVar2 = ld_dword(param_1 + 0x50), uVar2 < 0x81)) {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== sync_window @ 20000d1c (112 bytes) ===== */

char sync_window(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = *(char *)(param_1 + 3);
  if (cVar3 != '\0') {
    iVar1 = disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,*(undefined4 *)(param_1 + 0x60),
                       *(undefined4 *)(param_1 + 100),1);
    if (iVar1 == 0) {
      *(undefined *)(param_1 + 3) = 0;
      uVar4 = *(uint *)(param_1 + 0x60);
      uVar2 = *(uint *)(param_1 + 0x30);
      cVar3 = '\0';
      if (((*(int *)(param_1 + 100) - *(int *)(param_1 + 0x44) ==
            (uint)(uVar4 < *(uint *)(param_1 + 0x40))) &&
          (uVar4 - *(uint *)(param_1 + 0x40) < uVar2)) && (*(char *)(param_1 + 2) == '\x02')) {
        disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,uVar2 + uVar4,
                   *(int *)(param_1 + 100) + (uint)CARRY4(uVar2,uVar4),1);
      }
    }
    else {
      cVar3 = '\x01';
    }
  }
  return cVar3;
}


/* ===== move_window @ 20000d8c (76 bytes) ===== */

int move_window(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x60) == param_3) && (*(int *)(param_1 + 100) == param_4)) {
    iVar2 = 0;
  }
  else {
    iVar2 = sync_window(param_1);
    if (iVar2 == 0) {
      iVar1 = disk_read(*(undefined *)(param_1 + 1),param_1 + 0x68,param_3,param_4,1);
      if (iVar1 != 0) {
        iVar2 = 1;
        param_3 = -1;
        param_4 = -1;
      }
      *(int *)(param_1 + 0x60) = param_3;
      *(int *)(param_1 + 100) = param_4;
    }
  }
  return iVar2;
}


/* ===== check_fs @ 20000dd8 (240 bytes) ===== */

undefined4 check_fs(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  *(undefined *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  iVar3 = move_window(param_1);
  if (iVar3 == 0) {
    iVar3 = ld_word(param_1 + DAT_20000ec8);
    if ((iVar3 == DAT_20000ecc) && (iVar6 = memcmp(param_1 + 0x68,DAT_20000ed0,0xb), iVar6 == 0)) {
      uVar4 = 1;
    }
    else {
      cVar1 = *(char *)(param_1 + 0x68);
      if ((cVar1 == -0x15) || ((cVar1 == -0x17 || (cVar1 == -0x18)))) {
        if ((iVar3 == DAT_20000ecc) && (iVar6 = memcmp(param_1 + 0xba,DAT_20000ed4,8), iVar6 == 0))
        {
          return 0;
        }
        uVar5 = ld_word(param_1 + 0x73);
        bVar2 = *(byte *)(param_1 + 0x75);
        if ((((((((uVar5 - 1 & uVar5) == 0) && (0x1ff < uVar5)) && (uVar5 < 0x201)) &&
              ((bVar2 != 0 && ((bVar2 - 1 & bVar2) == 0)))) &&
             ((iVar6 = ld_word(param_1 + 0x76), iVar6 != 0 &&
              ((*(byte *)(param_1 + 0x78) - 1 < 2 && (iVar6 = ld_word(param_1 + 0x79), iVar6 != 0)))
              ))) && ((uVar5 = ld_word(param_1 + 0x7b), 0x7f < uVar5 ||
                      (uVar5 = ld_dword(param_1 + 0x88), 0xffff < uVar5)))) &&
           (iVar6 = ld_word(param_1 + 0x7e), iVar6 != 0)) {
          return 0;
        }
      }
      if (iVar3 == DAT_20000ecc) {
        uVar4 = 2;
      }
      else {
        uVar4 = 3;
      }
    }
  }
  else {
    uVar4 = 4;
  }
  return uVar4;
}


/* ===== find_volume @ 20000ed8 (322 bytes) ===== */

uint find_volume(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  int local_3c;
  int local_38 [5];
  
  uVar8 = check_fs(param_1,param_2,0,0);
  uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
  uVar5 = (uint)uVar8;
  if ((uVar5 == 2) || ((uVar5 < 3 && (param_2 != 0)))) {
    if (*(char *)(param_1 + DAT_2000101c) == -0x12) {
      iVar2 = move_window(param_1,uVar3,1,0);
      if (iVar2 == 0) {
        iVar7 = param_1 + 0x68;
        iVar2 = test_gpt_header(iVar7);
        if (iVar2 == 0) {
          uVar5 = 3;
        }
        else {
          uVar5 = ld_dword(param_1 + 0xb8);
          lVar9 = ld_qword(param_1 + 0xb0);
          uVar3 = (undefined4)((ulonglong)lVar9 >> 0x20);
          local_3c = 0;
          for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
            lVar1 = lVar9 + (ulonglong)((uVar6 << 7) >> 9);
            iVar2 = move_window(param_1,uVar3,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
            if (iVar2 != 0) {
              return 4;
            }
            uVar4 = uVar6 << 7 & 0x180;
            uVar8 = memcmp(iVar7 + uVar4,DAT_20001020,0x10);
            uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
            if ((int)uVar8 == 0) {
              local_3c = local_3c + 1;
              uVar8 = ld_qword(uVar4 + 0x20 + iVar7);
              uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
              uVar8 = check_fs(param_1,uVar3,(int)uVar8,uVar3);
              uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
              uVar4 = (uint)uVar8;
              if ((param_2 == 0) && (uVar4 < 2)) {
                return uVar4;
              }
              if ((param_2 != 0) && (param_2 == local_3c)) {
                return uVar4;
              }
            }
          }
          uVar5 = 3;
        }
      }
      else {
        uVar5 = 4;
      }
    }
    else {
      for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {
        uVar8 = ld_dword(param_1 + uVar5 * 0x10 + 0x22e);
        uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
        local_38[uVar5] = (int)uVar8;
      }
      if (param_2 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = param_2 - 1;
      }
      do {
        if (local_38[uVar6] == 0) {
          uVar8 = CONCAT44(uVar3,3);
        }
        else {
          uVar8 = check_fs(param_1,uVar3,local_38[uVar6],0);
        }
        uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
        uVar5 = (uint)uVar8;
      } while (((param_2 == 0) && (1 < uVar5)) && (uVar6 = uVar6 + 1, uVar6 < 4));
    }
  }
  return uVar5;
}


/* ===== mount_volume @ 20001024 (1302 bytes) ===== */

uint mount_volume(undefined4 param_1,char **param_2,uint param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  longlong lVar18;
  longlong lVar19;
  undefined8 uVar20;
  
  *param_2 = (char *)0x0;
  iVar3 = get_ldnumber();
  if (iVar3 < 0) {
    uVar16 = 0xb;
  }
  else {
    pcVar15 = *(char **)(iVar3 * 4 + DAT_20001370);
    if (pcVar15 == (char *)0x0) {
      uVar16 = 0xc;
    }
    else {
      *param_2 = pcVar15;
      if (*pcVar15 != '\0') {
        uVar4 = disk_status(pcVar15[1]);
        if ((uVar4 & 1) == 0) {
          if ((param_3 & 0xfffffffe) == 0) {
            return uVar4 & 1;
          }
          if (-1 < (int)(uVar4 << 0x1d)) {
            return uVar4 & 1;
          }
          return 10;
        }
      }
      *pcVar15 = '\0';
      pcVar15[1] = (char)iVar3;
      uVar4 = disk_initialize();
      uVar16 = uVar4 & 1;
      if ((uVar4 & 1) == 0) {
        if (((param_3 & 0xfffffffe) == 0) || (-1 < (int)(uVar4 << 0x1d))) {
          uVar4 = find_volume(pcVar15,0);
          if (uVar4 == 4) {
            uVar16 = 1;
          }
          else if (uVar4 < 2) {
            uVar12 = *(uint *)(pcVar15 + 0x60);
            iVar3 = *(int *)(pcVar15 + 100);
            lVar19 = *(longlong *)(pcVar15 + 0x60);
            if (uVar4 == 1) {
              for (uVar4 = 0xb; (uVar4 < 0x40 && (pcVar15[uVar4 + 0x68] == '\0')); uVar4 = uVar4 + 1
                  ) {
              }
              if (uVar4 < 0x40) {
                uVar16 = 0xd;
              }
              else {
                iVar7 = ld_word(pcVar15 + 0xd0);
                if (iVar7 == 0x100) {
                  if (pcVar15[0xd4] == '\t') {
                    lVar18 = ld_qword(pcVar15 + 0xb0);
                    lVar18 = lVar18 + lVar19;
                    uVar4 = (uint)((ulonglong)lVar18 >> 0x20);
                    uVar8 = ld_dword(pcVar15 + 0xbc);
                    *(undefined4 *)(pcVar15 + 0x30) = uVar8;
                    pcVar15[2] = pcVar15[0xd6];
                    if (pcVar15[0xd6] == '\x01') {
                      uVar14 = 1 << (uint)(byte)pcVar15[0xd5] & 0xffff;
                      *(short *)(pcVar15 + 10) = (short)(1 << (uint)(byte)pcVar15[0xd5]);
                      if (uVar14 == 0) {
                        uVar16 = 0xd;
                      }
                      else {
                        uVar9 = ld_dword(pcVar15 + 0xc4);
                        if (DAT_20001380 < uVar9) {
                          uVar16 = 0xd;
                        }
                        else {
                          *(uint *)(pcVar15 + 0x2c) = uVar9 + 2;
                          *(uint *)(pcVar15 + 0x38) = uVar12;
                          *(int *)(pcVar15 + 0x3c) = iVar3;
                          uVar10 = ld_dword(pcVar15 + 0xc0);
                          uVar11 = uVar12 + uVar10;
                          iVar7 = iVar3 + (uint)CARRY4(uVar12,uVar10);
                          *(uint *)(pcVar15 + 0x50) = uVar11;
                          *(int *)(pcVar15 + 0x54) = iVar7;
                          uVar10 = ld_dword(pcVar15 + 0xb8);
                          *(uint *)(pcVar15 + 0x40) = uVar10 + uVar12;
                          *(uint *)(pcVar15 + 0x44) = iVar3 + (uint)CARRY4(uVar10,uVar12);
                          uVar9 = uVar9 * uVar14;
                          uVar12 = iVar7 + (uint)CARRY4(uVar9,uVar11);
                          if ((uVar4 <= uVar12 && uVar12 != uVar4) ||
                             ((uVar12 == uVar4 && ((uint)lVar18 < uVar9 + uVar11)))) {
                            uVar16 = 0xd;
                          }
                          else {
                            uVar8 = ld_dword(pcVar15 + 200);
                            *(undefined4 *)(pcVar15 + 0x48) = uVar8;
                            *(undefined4 *)(pcVar15 + 0x4c) = 0;
                            uVar4 = 0;
                            uVar12 = 0;
                            while( true ) {
                              if (uVar4 == 0) {
                                if (*(ushort *)(pcVar15 + 10) <= uVar12) {
                                  return 0xd;
                                }
                                lVar19 = clst2sect(pcVar15,*(undefined4 *)(pcVar15 + 0x48));
                                iVar3 = move_window(pcVar15,(int)((ulonglong)lVar19 >> 0x20),
                                                    (int)(lVar19 + (ulonglong)uVar12),
                                                    (int)(lVar19 + (ulonglong)uVar12 >> 0x20));
                                if (iVar3 != 0) {
                                  return 1;
                                }
                                uVar12 = uVar12 + 1;
                              }
                              if (pcVar15[uVar4 + 0x68] == -0x7f) break;
                              uVar4 = uVar4 + 0x20 & 0x1ff;
                            }
                            uVar4 = ld_dword(pcVar15 + uVar4 + 0x7c);
                            if (uVar4 < 2) {
                              uVar16 = 0xd;
                            }
                            else if (uVar4 < *(uint *)(pcVar15 + 0x2c)) {
                              uVar12 = (uint)*(ushort *)(pcVar15 + 10) * (uVar4 - 2);
                              iVar3 = *(int *)(pcVar15 + 0x54);
                              *(uint *)(pcVar15 + 0x58) = uVar12 + *(uint *)(pcVar15 + 0x50);
                              *(uint *)(pcVar15 + 0x5c) =
                                   iVar3 + (uint)CARRY4(uVar12,*(uint *)(pcVar15 + 0x50));
                              do {
                                iVar3 = move_window(pcVar15,iVar3,
                                                    *(uint *)(pcVar15 + 0x40) + (uVar4 >> 7),
                                                    *(int *)(pcVar15 + 0x44) +
                                                    (uint)CARRY4(*(uint *)(pcVar15 + 0x40),
                                                                 uVar4 >> 7));
                                if (iVar3 != 0) {
                                  return 1;
                                }
                                uVar20 = ld_dword(pcVar15 + (uVar4 & 0x7f) * 4 + 0x68);
                                iVar3 = (int)((ulonglong)uVar20 >> 0x20);
                                if ((uint)uVar20 == 0xffffffff) {
                                  *(undefined4 *)(pcVar15 + 0x18) = 0xffffffff;
                                  *(undefined4 *)(pcVar15 + 0x14) = 0xffffffff;
                                  cVar13 = '\x04';
                                  goto LAB_2000140e;
                                }
                                uVar4 = uVar4 + 1;
                              } while ((uint)uVar20 == uVar4);
                              uVar16 = 0xd;
                            }
                            else {
                              uVar16 = 0xd;
                            }
                          }
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                    }
                  }
                  else {
                    uVar16 = 0xd;
                  }
                }
                else {
                  uVar16 = 0xd;
                }
              }
            }
            else {
              iVar7 = ld_word(pcVar15 + 0x73);
              if (iVar7 == 0x200) {
                uVar4 = ld_word(pcVar15 + 0x7e);
                if (uVar4 == 0) {
                  uVar4 = ld_dword(pcVar15 + 0x8c);
                }
                *(uint *)(pcVar15 + 0x30) = uVar4;
                bVar1 = pcVar15[0x78];
                pcVar15[2] = bVar1;
                if ((bVar1 - 1 & 0xff) < 2) {
                  uVar14 = uVar4 * bVar1;
                  uVar9 = (uint)(byte)pcVar15[0x75];
                  *(ushort *)(pcVar15 + 10) = (ushort)(byte)pcVar15[0x75];
                  if (uVar9 == 0) {
                    uVar16 = 0xd;
                  }
                  else if ((uVar9 - 1 & uVar9) == 0) {
                    uVar10 = ld_word(pcVar15 + 0x79);
                    *(short *)(pcVar15 + 8) = (short)uVar10;
                    if ((uVar10 & 0xf) == 0) {
                      uVar11 = ld_word(pcVar15 + 0x7b);
                      if (uVar11 == 0) {
                        uVar11 = ld_dword(pcVar15 + 0x88);
                      }
                      uVar5 = ld_word(pcVar15 + 0x76);
                      if (uVar5 == 0) {
                        uVar16 = 0xd;
                      }
                      else {
                        uVar17 = uVar14 + uVar5 + (uVar10 >> 4 & 0xffff);
                        if (uVar11 < uVar17) {
                          uVar16 = 0xd;
                        }
                        else {
                          uVar6 = __aeabi_uidiv(uVar11 - uVar17,uVar9);
                          if (uVar11 - uVar17 < uVar9) {
                            uVar16 = 0xd;
                          }
                          else {
                            if (DAT_20001374 < uVar6) {
                              cVar13 = '\0';
                            }
                            else {
                              cVar13 = '\x03';
                            }
                            if (uVar6 <= DAT_20001378) {
                              cVar13 = '\x02';
                            }
                            if (DAT_2000137c < uVar6) {
                              if (cVar13 == '\0') {
                                return 0xd;
                              }
                            }
                            else {
                              cVar13 = '\x01';
                            }
                            uVar6 = uVar6 + 2;
                            *(uint *)(pcVar15 + 0x2c) = uVar6;
                            *(uint *)(pcVar15 + 0x38) = uVar12;
                            *(int *)(pcVar15 + 0x3c) = iVar3;
                            uVar9 = uVar5 + uVar12;
                            iVar7 = iVar3 + (uint)CARRY4(uVar5,uVar12);
                            *(uint *)(pcVar15 + 0x40) = uVar9;
                            *(int *)(pcVar15 + 0x44) = iVar7;
                            *(uint *)(pcVar15 + 0x50) = uVar17 + uVar12;
                            *(uint *)(pcVar15 + 0x54) = iVar3 + (uint)CARRY4(uVar17,uVar12);
                            if (cVar13 == '\x03') {
                              iVar7 = ld_word(pcVar15 + 0x92);
                              if (iVar7 != 0) {
                                return 0xd;
                              }
                              if (uVar10 != 0) {
                                return 0xd;
                              }
                              uVar8 = ld_dword(pcVar15 + 0x94);
                              *(undefined4 *)(pcVar15 + 0x48) = uVar8;
                              *(undefined4 *)(pcVar15 + 0x4c) = 0;
                              iVar7 = uVar6 * 4;
                            }
                            else {
                              if (uVar10 == 0) {
                                return 0xd;
                              }
                              *(uint *)(pcVar15 + 0x48) = uVar14 + uVar9;
                              *(uint *)(pcVar15 + 0x4c) = iVar7 + (uint)CARRY4(uVar14,uVar9);
                              if (cVar13 == '\x02') {
                                iVar7 = uVar6 * 2;
                              }
                              else {
                                iVar7 = (uVar6 * 3 >> 1) + (uVar6 & 1);
                              }
                            }
                            if (uVar4 < (uint)(iVar7 + DAT_20001550) >> 9) {
                              uVar16 = 0xd;
                            }
                            else {
                              *(undefined4 *)(pcVar15 + 0x18) = 0xffffffff;
                              *(undefined4 *)(pcVar15 + 0x14) = 0xffffffff;
                              pcVar15[4] = -0x80;
                              if (((cVar13 == '\x03') &&
                                  (iVar7 = ld_word(pcVar15 + 0x98), iVar7 == 1)) &&
                                 (iVar3 = iVar3 + (uint)(0xfffffffe < uVar12),
                                 iVar3 = move_window(pcVar15,iVar3,uVar12 + 1,iVar3), iVar3 == 0)) {
                                pcVar15[4] = '\0';
                                iVar3 = ld_word(pcVar15 + DAT_20001560);
                                if (((iVar3 == DAT_20001564) &&
                                    (iVar3 = ld_dword(pcVar15 + 0x68), iVar3 == DAT_20001568)) &&
                                   (iVar3 = ld_dword(pcVar15 + 0x24c), iVar3 == DAT_2000156c)) {
                                  uVar8 = ld_dword(pcVar15 + 0x250);
                                  *(undefined4 *)(pcVar15 + 0x18) = uVar8;
                                  uVar8 = ld_dword(pcVar15 + 0x254);
                                  *(undefined4 *)(pcVar15 + 0x14) = uVar8;
                                }
                              }
LAB_2000140e:
                              *pcVar15 = cVar13;
                              sVar2 = *DAT_20001554;
                              *DAT_20001554 = sVar2 + 1;
                              *(short *)(pcVar15 + 6) = sVar2 + 1;
                              *(undefined4 *)(pcVar15 + 0xc) = DAT_20001558;
                              *(undefined4 *)(pcVar15 + 0x10) = DAT_2000155c;
                              *(undefined4 *)(pcVar15 + 0x1c) = 0;
                            }
                          }
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                    }
                  }
                  else {
                    uVar16 = 0xd;
                  }
                }
                else {
                  uVar16 = 0xd;
                }
              }
              else {
                uVar16 = 0xd;
              }
            }
          }
          else {
            uVar16 = 0xd;
          }
        }
        else {
          uVar16 = 10;
        }
      }
      else {
        uVar16 = 3;
      }
    }
  }
  return uVar16;
}


/* ===== find_bitmap @ 20001570 (166 bytes) ===== */

int find_bitmap(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_28;
  
  uVar7 = param_2 - 2;
  if (*(int *)(param_1 + 0x2c) - 2U <= uVar7) {
    uVar7 = 0;
  }
  iVar6 = 0;
  uVar5 = uVar7;
  local_28 = uVar7;
  do {
    iVar1 = move_window(param_1,0,*(uint *)(param_1 + 0x58) + (uVar5 >> 0xc),
                        *(int *)(param_1 + 0x5c) +
                        (uint)CARRY4(*(uint *)(param_1 + 0x58),uVar5 >> 0xc));
    if (iVar1 != 0) {
      return -1;
    }
    uVar2 = uVar5 >> 3 & 0x1ff;
    uVar4 = 1 << (uVar5 & 7) & 0xff;
    while( true ) {
      do {
        uVar3 = *(byte *)(param_1 + uVar2 + 0x68) & uVar4;
        uVar4 = (uVar4 & 0x7f) << 1;
        uVar5 = uVar5 + 1;
        if (*(int *)(param_1 + 0x2c) - 2U <= uVar5) {
          uVar5 = 0;
          uVar2 = 0x200;
          uVar4 = 0;
        }
        if (uVar3 == 0) {
          iVar6 = iVar6 + 1;
          if (iVar6 == param_3) {
            return local_28 + 2;
          }
        }
        else {
          iVar6 = 0;
          local_28 = uVar5;
        }
        if (uVar7 == uVar5) {
          return 0;
        }
      } while (uVar4 != 0);
      uVar2 = uVar2 + 1;
      if (0x1ff < uVar2) break;
      uVar4 = 1;
    }
  } while( true );
}


/* ===== change_bitmap @ 20001616 (150 bytes) ===== */

undefined4 change_bitmap(int param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = param_2 - 2;
  uVar3 = (uVar6 >> 0xc) + *(uint *)(param_1 + 0x58);
  iVar5 = *(int *)(param_1 + 0x5c) + (uint)CARRY4(uVar6 >> 0xc,*(uint *)(param_1 + 0x58));
  uVar8 = uVar6 >> 3 & 0x1ff;
  uVar6 = 1 << (uVar6 & 7) & 0xff;
  do {
    iVar7 = iVar5 + (uint)(0xfffffffe < uVar3);
    uVar2 = uVar3 + 1;
    iVar4 = move_window(param_1,iVar5,uVar3,iVar5,uVar3 + 1,iVar7);
    iVar5 = iVar7;
    uVar3 = uVar2;
    if (iVar4 != 0) {
      return 1;
    }
    while( true ) {
      do {
        bVar1 = *(byte *)(param_1 + uVar8 + 0x68);
        if (((uVar6 & bVar1) != 0) == param_4) {
          return 2;
        }
        *(byte *)(param_1 + uVar8 + 0x68) = bVar1 ^ (byte)uVar6;
        *(undefined *)(param_1 + 3) = 1;
        param_3 = param_3 + -1;
        if (param_3 == 0) {
          return 0;
        }
        uVar2 = uVar6 & 0x7f;
        uVar6 = uVar2 * 2;
      } while (uVar2 != 0);
      uVar8 = uVar8 + 1;
      uVar6 = 1;
      if (0x1ff < uVar8) break;
      uVar6 = 1;
    }
    uVar8 = 0;
  } while( true );
}


/* ===== put_fat @ 200016ac (374 bytes) ===== */

int put_fat(byte *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 < 2) {
    iVar3 = 2;
  }
  else if (param_2 < *(uint *)(param_1 + 0x2c)) {
    bVar1 = *param_1;
    if (bVar1 == 2) {
      iVar3 = move_window(param_1,*(int *)(param_1 + 0x44),
                          (param_2 >> 8) + *(uint *)(param_1 + 0x40),
                          *(int *)(param_1 + 0x44) +
                          (uint)CARRY4(param_2 >> 8,*(uint *)(param_1 + 0x40)));
      if (iVar3 == 0) {
        st_word(param_1 + (param_2 & 0xff) * 2 + 0x68,param_3 & 0xffff);
        param_1[3] = 1;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 1) {
        uVar4 = (param_2 >> 1) + param_2;
        iVar3 = move_window(param_1,*(int *)(param_1 + 0x44),
                            (uVar4 >> 9) + *(uint *)(param_1 + 0x40),
                            *(int *)(param_1 + 0x44) +
                            (uint)CARRY4(uVar4 >> 9,*(uint *)(param_1 + 0x40)));
        if (iVar3 == 0) {
          if ((param_2 & 1) == 0) {
            bVar1 = (byte)param_3;
          }
          else {
            bVar1 = param_1[(uVar4 & 0x1ff) + 0x68] & 0xf | (byte)(param_3 << 4);
          }
          param_1[(uVar4 & 0x1ff) + 0x68] = bVar1;
          param_1[3] = 1;
          uVar2 = uVar4 + 1 >> 9;
          iVar3 = move_window(param_1,*(int *)(param_1 + 0x44),uVar2 + *(uint *)(param_1 + 0x40),
                              *(int *)(param_1 + 0x44) +
                              (uint)CARRY4(uVar2,*(uint *)(param_1 + 0x40)));
          if (iVar3 == 0) {
            if ((param_2 & 1) == 0) {
              bVar1 = (byte)(param_3 >> 8) & 0xf | param_1[(uVar4 + 1 & 0x1ff) + 0x68] & 0xf0;
            }
            else {
              bVar1 = (byte)(param_3 >> 4);
            }
            param_1[(uVar4 + 1 & 0x1ff) + 0x68] = bVar1;
            param_1[3] = 1;
          }
        }
      }
      else {
        iVar3 = 2;
      }
    }
    else if ((byte)(bVar1 - 3) < 2) {
      iVar3 = move_window(param_1,*(int *)(param_1 + 0x44),
                          (param_2 >> 7) + *(uint *)(param_1 + 0x40),
                          *(int *)(param_1 + 0x44) +
                          (uint)CARRY4(param_2 >> 7,*(uint *)(param_1 + 0x40)));
      if (iVar3 == 0) {
        if (*param_1 != 4) {
          uVar4 = ld_dword(param_1 + (param_2 & 0x7f) * 4 + 0x68);
          param_3 = param_3 & 0xfffffff | uVar4 & 0xf0000000;
        }
        st_dword(param_1 + (param_2 & 0x7f) * 4 + 0x68,param_3);
        param_1[3] = 1;
      }
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 2;
  }
  return iVar3;
}


/* ===== fill_last_frag @ 20001822 (50 bytes) ===== */

int fill_last_frag(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    uVar2 = param_1[7];
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = param_3;
    if (1 < uVar2) {
      iVar1 = (param_2 - uVar2) + 2;
    }
    iVar1 = put_fat(*param_1,(param_2 - uVar2) + 1,iVar1);
    if (iVar1 != 0) break;
    param_1[7] = param_1[7] + -1;
  }
  return iVar1;
}


/* ===== fill_first_frag @ 20001854 (50 bytes) ===== */

int fill_first_frag(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)((int)param_1 + 7) == '\x03') {
    iVar2 = param_1[2];
    for (iVar3 = param_1[6]; iVar3 != 0; iVar3 = iVar3 + -1) {
      iVar1 = put_fat(*param_1,iVar2,iVar2 + 1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    }
    *(undefined *)((int)param_1 + 7) = 0;
  }
  return 0;
}


/* ===== get_fat @ 20001888 (422 bytes) ===== */

uint get_fat(byte **param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  pbVar8 = *param_1;
  if (param_2 < 2) {
    uVar4 = 1;
  }
  else if (param_2 < *(uint *)(pbVar8 + 0x2c)) {
    bVar1 = *pbVar8;
    if (bVar1 == 3) {
      iVar3 = move_window(pbVar8,*(int *)(pbVar8 + 0x44),(param_2 >> 7) + *(uint *)(pbVar8 + 0x40),
                          *(int *)(pbVar8 + 0x44) +
                          (uint)CARRY4(param_2 >> 7,*(uint *)(pbVar8 + 0x40)),param_4);
      if (iVar3 == 0) {
        uVar4 = ld_dword(pbVar8 + (param_2 & 0x7f) * 4 + 0x68);
        uVar4 = uVar4 & 0xfffffff;
      }
      else {
        uVar4 = 0xffffffff;
      }
    }
    else if (bVar1 < 4) {
      if (bVar1 == 1) {
        uVar4 = (param_2 >> 1) + param_2;
        iVar3 = move_window(pbVar8,*(int *)(pbVar8 + 0x44),(uVar4 >> 9) + *(uint *)(pbVar8 + 0x40),
                            *(int *)(pbVar8 + 0x44) +
                            (uint)CARRY4(uVar4 >> 9,*(uint *)(pbVar8 + 0x40)),param_4);
        if (iVar3 == 0) {
          bVar1 = pbVar8[(uVar4 & 0x1ff) + 0x68];
          uVar6 = uVar4 + 1 >> 9;
          iVar3 = move_window(pbVar8,*(int *)(pbVar8 + 0x44),uVar6 + *(uint *)(pbVar8 + 0x40),
                              *(int *)(pbVar8 + 0x44) + (uint)CARRY4(uVar6,*(uint *)(pbVar8 + 0x40))
                              ,param_4);
          if (iVar3 == 0) {
            if ((int)(param_2 << 0x1f) < 0) {
              uVar4 = (uint)(ushort)(CONCAT11(pbVar8[(uVar4 + 1 & 0x1ff) + 0x68],bVar1) >> 4);
            }
            else {
              uVar4 = CONCAT11(pbVar8[(uVar4 + 1 & 0x1ff) + 0x68],bVar1) & 0xfff;
            }
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      else if (bVar1 == 2) {
        iVar3 = move_window(pbVar8,*(int *)(pbVar8 + 0x44),(param_2 >> 8) + *(uint *)(pbVar8 + 0x40)
                            ,*(int *)(pbVar8 + 0x44) +
                             (uint)CARRY4(param_2 >> 8,*(uint *)(pbVar8 + 0x40)),param_4);
        if (iVar3 == 0) {
          uVar4 = ld_word(pbVar8 + (param_2 & 0xff) * 2 + 0x68);
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      else {
        uVar4 = 1;
      }
    }
    else if (bVar1 == 4) {
      pbVar5 = param_1[4];
      if (((((uint)pbVar5 | (uint)param_1[5]) == 0) || (param_1[2] == (byte *)0x0)) &&
         (*(char *)((int)param_1 + 7) != '\0')) {
        uVar4 = 1;
      }
      else {
        pbVar9 = (byte *)(param_2 - (int)param_1[2]);
        pbVar7 = param_1[5] + ((pbVar5 != (byte *)0x0) - 1);
        pbVar5 = (byte *)__aeabi_uldivmod((uint)(pbVar5 + -1) >> 9 | (int)pbVar7 * 0x800000,
                                          (uint)pbVar7 >> 9,*(undefined2 *)(pbVar8 + 10),0);
        cVar2 = *(char *)((int)param_1 + 7);
        uVar4 = DAT_20001a30;
        if ((cVar2 == '\x02') && (pbVar9 <= pbVar5)) {
          if (pbVar9 != pbVar5) {
            uVar4 = param_2 + 1;
          }
        }
        else if ((cVar2 == '\x03') && (pbVar9 < param_1[6])) {
          uVar4 = param_2 + 1;
        }
        else if (cVar2 == '\x02') {
          uVar4 = 1;
        }
        else if (param_1[7] == (byte *)0x0) {
          iVar3 = move_window(pbVar8,*(int *)(pbVar8 + 0x44),
                              (param_2 >> 7) + *(uint *)(pbVar8 + 0x40),
                              *(int *)(pbVar8 + 0x44) +
                              (uint)CARRY4(param_2 >> 7,*(uint *)(pbVar8 + 0x40)),param_4);
          if (iVar3 == 0) {
            uVar4 = ld_dword(pbVar8 + (param_2 & 0x7f) * 4 + 0x68);
            uVar4 = uVar4 & 0x7fffffff;
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
      }
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


/* ===== create_chain @ 20001a34 (454 bytes) ===== */

uint create_chain(char **param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  pcVar4 = *param_1;
  if (param_2 == 0) {
    uVar2 = *(uint *)(pcVar4 + 0x14);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    else if (*(uint *)(pcVar4 + 0x2c) <= uVar2) {
      uVar2 = 1;
    }
  }
  else {
    uVar5 = get_fat();
    if (uVar5 < 2) {
      return 1;
    }
    if (uVar5 == 0xffffffff) {
      return 0xffffffff;
    }
    uVar2 = param_2;
    if (uVar5 < *(uint *)(pcVar4 + 0x2c)) {
      return uVar5;
    }
  }
  if (*(int *)(pcVar4 + 0x18) == 0) {
    return 0;
  }
  if (*pcVar4 == '\x04') {
    uVar5 = find_bitmap(pcVar4,uVar2,1);
    if (0xfffffffd < uVar5 - 1) {
      return uVar5;
    }
    iVar1 = change_bitmap(pcVar4,uVar5,1,1);
    if (iVar1 == 2) {
      return 1;
    }
    if (iVar1 == 1) {
      return 0xffffffff;
    }
    if (param_2 == 0) {
      *(undefined *)((int)param_1 + 7) = 2;
    }
    else if ((*(char *)((int)param_1 + 7) == '\x02') && (uVar2 + 1 != uVar5)) {
      param_1[6] = (char *)(uVar2 - (int)param_1[2]);
      *(undefined *)((int)param_1 + 7) = 3;
    }
    if (*(char *)((int)param_1 + 7) != '\x02') {
      if (param_2 + 1 == uVar5) {
        if (param_1[7] == (char *)0x0) {
          pcVar3 = (char *)0x2;
        }
        else {
          pcVar3 = param_1[7] + 1;
        }
        param_1[7] = pcVar3;
      }
      else {
        if (param_1[7] == (char *)0x0) {
          param_1[7] = (char *)0x1;
        }
        iVar1 = fill_last_frag(param_1,param_2,uVar5);
        if (iVar1 == 0) {
          param_1[7] = (char *)0x1;
        }
      }
    }
LAB_20001b70:
    if (iVar1 == 0) {
      *(uint *)(pcVar4 + 0x14) = uVar5;
      if (*(uint *)(pcVar4 + 0x18) <= *(int *)(pcVar4 + 0x2c) - 2U) {
        *(uint *)(pcVar4 + 0x18) = *(uint *)(pcVar4 + 0x18) - 1;
      }
      pcVar4[4] = pcVar4[4] | 1;
    }
    else if (iVar1 == 1) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = 1;
    }
  }
  else {
    uVar6 = uVar2;
    if (uVar2 == param_2) {
      uVar5 = uVar2 + 1;
      if (*(uint *)(pcVar4 + 0x2c) <= uVar5) {
        uVar5 = 2;
      }
      iVar1 = get_fat(param_1,uVar5);
      if (iVar1 == 1) {
        return 1;
      }
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      if (iVar1 == 0) {
        if (uVar5 != 0) {
LAB_20001b5a:
          iVar1 = put_fat(pcVar4,uVar5,0xffffffff);
          if ((iVar1 == 0) && (param_2 != 0)) {
            iVar1 = put_fat(pcVar4,param_2,uVar5);
          }
          goto LAB_20001b70;
        }
      }
      else {
        uVar5 = *(uint *)(pcVar4 + 0x14);
        if ((1 < uVar5) && (uVar5 < *(uint *)(pcVar4 + 0x2c))) {
          uVar2 = uVar5;
          uVar6 = uVar5;
        }
      }
    }
    do {
      uVar5 = uVar2 + 1;
      if (*(uint *)(pcVar4 + 0x2c) <= uVar5) {
        if (uVar6 < 2) {
          return 0;
        }
        uVar5 = 2;
      }
      iVar1 = get_fat(param_1,uVar5);
      if (iVar1 == 0) goto LAB_20001b5a;
      if (iVar1 == 1) {
        return 1;
      }
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      uVar2 = uVar5;
    } while (uVar5 != uVar6);
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== dir_sdi @ 20001bfa (212 bytes) ===== */

undefined4 dir_sdi(byte **param_1,code *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  code *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined8 uVar7;
  
  pbVar3 = *param_1;
  if (*pbVar3 == 4) {
    pcVar4 = FUN_10000000;
  }
  else {
    pcVar4 = (code *)0x200000;
  }
  if (param_2 < pcVar4) {
    if (((uint)param_2 & 0x1f) == 0) {
      param_1[0xc] = (byte *)param_2;
      pbVar6 = param_1[2];
      if ((pbVar6 == (byte *)0x0) && (2 < *pbVar3)) {
        pbVar6 = *(byte **)(pbVar3 + 0x48);
        *(undefined *)((int)param_1 + 7) = 0;
      }
      if (pbVar6 == (byte *)0x0) {
        if ((uint)*(ushort *)(pbVar3 + 8) <= (uint)param_2 >> 5) {
          return 2;
        }
        pbVar5 = *(byte **)(pbVar3 + 0x4c);
        param_1[0xe] = *(byte **)(pbVar3 + 0x48);
        param_1[0xf] = pbVar5;
      }
      else {
        uVar1 = *(ushort *)(pbVar3 + 10);
        for (; (code *)((uint)uVar1 * 0x200) <= param_2; param_2 = param_2 + (uint)uVar1 * -0x200) {
          pbVar6 = (byte *)get_fat(param_1,pbVar6);
          if (pbVar6 == (byte *)0xffffffff) {
            return 1;
          }
          if (pbVar6 < (byte *)0x2) {
            return 2;
          }
          if (*(byte **)(pbVar3 + 0x2c) <= pbVar6) {
            return 2;
          }
        }
        uVar7 = clst2sect(pbVar3,pbVar6);
        *(undefined8 *)(param_1 + 0xe) = uVar7;
      }
      param_1[0xd] = pbVar6;
      pbVar6 = param_1[0xe];
      if (((uint)pbVar6 | (uint)param_1[0xf]) == 0) {
        uVar2 = 2;
      }
      else {
        param_1[0xe] = pbVar6 + ((uint)param_2 >> 9);
        param_1[0xf] = param_1[0xf] + CARRY4((uint)pbVar6,(uint)param_2 >> 9);
        param_1[0x10] = pbVar3 + ((uint)param_2 & 0x1ff) + 0x68;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


/* ===== dir_clear @ 20001cce (138 bytes) ===== */

bool dir_clear(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  longlong lVar4;
  
  iVar1 = sync_window();
  if (iVar1 == 0) {
    lVar4 = clst2sect(param_1,param_2);
    *(longlong *)(param_1 + 0x60) = lVar4;
    memset(param_1 + 0x68,0,0x200);
    for (uVar2 = 0; uVar2 < *(ushort *)(param_1 + 10); uVar2 = uVar2 + 1) {
      iVar1 = disk_write(*(undefined *)(param_1 + 1),param_1 + 0x68,(int)(lVar4 + (ulonglong)uVar2),
                         (int)(lVar4 + (ulonglong)uVar2 >> 0x20),1);
      if (iVar1 != 0) break;
    }
    bVar3 = *(ushort *)(param_1 + 10) != uVar2;
  }
  else {
    bVar3 = true;
  }
  return bVar3;
}


/* ===== dir_next @ 20001d58 (260 bytes) ===== */

undefined4 dir_next(char **param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  char *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  pcVar4 = *param_1;
  pcVar5 = (code *)(param_1[0xc] + 0x20);
  if (*pcVar4 == '\x04') {
    pcVar3 = FUN_10000000;
  }
  else {
    pcVar3 = (code *)0x200000;
  }
  if (pcVar3 <= pcVar5) {
    param_1[0xe] = (char *)0x0;
    param_1[0xf] = (char *)0x0;
  }
  pcVar2 = param_1[0xe];
  if (((uint)pcVar2 | (uint)param_1[0xf]) == 0) {
    return 4;
  }
  if (((uint)pcVar5 & 0x1ff) == 0) {
    param_1[0xe] = pcVar2 + 1;
    param_1[0xf] = param_1[0xf] + ((char *)0xfffffffe < pcVar2);
    if (param_1[0xd] == (char *)0x0) {
      if ((uint)*(ushort *)(pcVar4 + 8) <= (uint)pcVar5 >> 5) {
        param_1[0xe] = (char *)0x0;
        param_1[0xf] = (char *)0x0;
        return 4;
      }
    }
    else if ((*(ushort *)(pcVar4 + 10) - 1 & (uint)pcVar5 >> 9) == 0) {
      pcVar2 = (char *)get_fat(param_1);
      if (pcVar2 < (char *)0x2) {
        return 2;
      }
      if (pcVar2 == (char *)0xffffffff) {
        return 1;
      }
      if (*(char **)(pcVar4 + 0x2c) <= pcVar2) {
        if (param_2 == 0) {
          param_1[0xe] = (char *)0x0;
          param_1[0xf] = (char *)0x0;
          return 4;
        }
        pcVar2 = (char *)create_chain(param_1,param_1[0xd]);
        if (pcVar2 == (char *)0x0) {
          return 7;
        }
        if (pcVar2 == (char *)0x1) {
          return 2;
        }
        if (pcVar2 == (char *)0xffffffff) {
          return 1;
        }
        iVar1 = dir_clear(pcVar4,pcVar2);
        if (iVar1 != 0) {
          return 1;
        }
        *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) | 4;
      }
      param_1[0xd] = pcVar2;
      uVar6 = clst2sect(pcVar4,pcVar2);
      *(undefined8 *)(param_1 + 0xe) = uVar6;
    }
  }
  param_1[0xc] = (char *)pcVar5;
  param_1[0x10] = pcVar4 + ((uint)pcVar5 & 0x1ff) + 0x68;
  return 0;
}


/* ===== dir_alloc @ 20001e5c (112 bytes) ===== */

int dir_alloc(char **param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  pcVar4 = *param_1;
  uVar6 = dir_sdi(param_1,0,param_3,param_4,param_4);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  iVar1 = (int)uVar6;
  if (iVar1 == 0) {
    iVar5 = 0;
    do {
      iVar1 = move_window(pcVar4,uVar2,param_1[0xe],param_1[0xf]);
      if (iVar1 != 0) break;
      if (*pcVar4 == '\x04') {
        uVar3 = (uint)~(int)*param_1[0x10] >> 0x1f;
      }
      else if (*param_1[0x10] == -0x1b) {
        uVar3 = 1;
      }
      else if (*param_1[0x10] == '\0') {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      if (uVar3 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar5 + 1;
        if (iVar5 == param_2) break;
      }
      uVar6 = dir_next(param_1,1);
      uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
      iVar1 = (int)uVar6;
    } while (iVar1 == 0);
  }
  if (iVar1 == 4) {
    iVar1 = 7;
  }
  return iVar1;
}


/* ===== load_xdir @ 20001ecc (268 bytes) ===== */

int load_xdir(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  iVar3 = *(int *)(*param_1 + 0x10);
  iVar1 = move_window(*param_1,param_2,param_1[0xe],param_1[0xf]);
  if (iVar1 == 0) {
    if (*(char *)param_1[0x10] == -0x7b) {
      memcpy(iVar3,(char *)param_1[0x10],0x20);
      iVar2 = *(byte *)(iVar3 + 1) + 1;
      uVar4 = iVar2 * 0x20;
      if (uVar4 - 0x60 < 0x201) {
        uVar6 = dir_next(param_1,0);
        iVar1 = (int)uVar6;
        if (iVar1 == 4) {
          iVar1 = 2;
        }
        else if ((iVar1 == 0) &&
                (iVar1 = move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],
                                     param_1[0xf]), iVar1 == 0)) {
          if (*(char *)param_1[0x10] == -0x40) {
            memcpy(iVar3 + 0x20,(char *)param_1[0x10],0x20);
            iVar1 = __aeabi_uidiv(*(byte *)(iVar3 + 0x23) + 0x2c,0xf);
            if ((uint)(iVar1 * 0x20) < uVar4 || iVar1 * 0x20 + iVar2 * -0x20 == 0) {
              uVar5 = 0x40;
              do {
                uVar6 = dir_next(param_1,0);
                iVar1 = (int)uVar6;
                if (iVar1 == 4) {
                  return 2;
                }
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],
                                    param_1[0xf]);
                if (iVar1 != 0) {
                  return iVar1;
                }
                if (*(char *)param_1[0x10] != -0x3f) {
                  return 2;
                }
                if (uVar5 < 0x260) {
                  memcpy(iVar3 + uVar5,(char *)param_1[0x10],0x20);
                }
                uVar5 = uVar5 + 0x20;
              } while (uVar5 <= uVar4 && uVar4 - uVar5 != 0);
              iVar1 = 0;
              if (uVar5 < 0x261) {
                iVar2 = xdir_sum(iVar3);
                iVar3 = ld_word(iVar3 + 2);
                if (iVar2 != iVar3) {
                  iVar1 = 2;
                }
              }
            }
            else {
              iVar1 = 2;
            }
          }
          else {
            iVar1 = 2;
          }
        }
      }
      else {
        iVar1 = 2;
      }
    }
    else {
      iVar1 = 2;
    }
  }
  return iVar1;
}


/* ===== load_obj_xdir @ 20001fd8 (54 bytes) ===== */

void load_obj_xdir(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  *param_1 = *param_2;
  param_1[2] = param_2[8];
  *(char *)((int)param_1 + 7) = (char)param_2[9];
  param_1[4] = param_2[9] & 0xffffff00;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[0x14] = param_2[10];
  iVar1 = dir_sdi();
  if (iVar1 == 0) {
    load_xdir(param_1);
  }
  return;
}


/* ===== dir_read @ 2000200e (276 bytes) ===== */

int dir_read(char **param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  pcVar6 = *param_1;
  uVar7 = 0xff;
  uVar8 = 0xff;
  iVar5 = 4;
  do {
    if ((((uint)param_1[0xe] | (uint)param_1[0xf]) == 0) ||
       (iVar5 = move_window(pcVar6), iVar5 != 0)) break;
    pbVar2 = (byte *)param_1[0x10];
    uVar4 = (uint)*pbVar2;
    if (uVar4 == 0) {
      iVar5 = 4;
      break;
    }
    if (*pcVar6 == '\x04') {
      if (uVar4 == 0x85) {
        param_1[0x14] = param_1[0xc];
        iVar5 = load_xdir(param_1);
        if (iVar5 == 0) {
          *(byte *)((int)param_1 + 6) = *(byte *)(*(int *)(pcVar6 + 0x10) + 4) & 0x3f;
        }
        break;
      }
    }
    else {
      bVar1 = pbVar2[0xb];
      bVar3 = bVar1 & 0x3f;
      *(byte *)((int)param_1 + 6) = bVar3;
      if (uVar4 == 0xe5) {
        uVar8 = 0xff;
      }
      else if (uVar4 == 0x2e) {
        uVar8 = 0xff;
      }
      else if (((bVar1 & 0x1f) == 8) == param_2) {
        if (bVar3 != 0xf) {
          if ((uVar8 != 0) || (uVar8 = sum_sfn(pbVar2), uVar8 != uVar7)) {
            param_1[0x14] = (char *)0xffffffff;
          }
          break;
        }
        if ((int)(uVar4 << 0x19) < 0) {
          uVar7 = (uint)pbVar2[0xd];
          uVar4 = uVar4 & 0xffffffbf;
          param_1[0x14] = param_1[0xc];
          uVar8 = uVar4;
        }
        if (uVar4 == uVar8) {
          if (pbVar2[0xd] == uVar7) {
            iVar5 = pick_lfn(*(undefined4 *)(pcVar6 + 0xc));
            if (iVar5 == 0) {
              uVar8 = 0xff;
            }
            else {
              uVar8 = uVar8 - 1 & 0xff;
            }
          }
          else {
            uVar8 = 0xff;
          }
        }
        else {
          uVar8 = 0xff;
        }
      }
      else {
        uVar8 = 0xff;
      }
    }
    iVar5 = dir_next(param_1,0);
  } while (iVar5 == 0);
  if (iVar5 != 0) {
    param_1[0xe] = (char *)0x0;
    param_1[0xf] = (char *)0x0;
  }
  return iVar5;
}


/* ===== gen_numname @ 20002124 (168 bytes) ===== */

void gen_numname(int param_1,undefined4 param_2,ushort *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  char acStack_21 [13];
  
  memcpy(param_1,param_2,0xb);
  if (5 < param_4) {
    while (uVar3 = (uint)*param_3, uVar3 != 0) {
      param_3 = param_3 + 1;
      for (uVar5 = 0; uVar5 < 0x10; uVar5 = uVar5 + 1) {
        uVar6 = param_4 * 2 + (uVar3 & 1);
        uVar3 = uVar3 >> 1;
        if ((int)(param_4 << 0x10) < 0) {
          uVar6 = uVar6 ^ DAT_200021cc;
        }
        param_4 = uVar6;
      }
    }
  }
  uVar3 = 7;
  do {
    uVar5 = uVar3;
    uVar3 = (param_4 & 0xf) + 0x30;
    cVar4 = (char)uVar3;
    if (0x39 < uVar3) {
      cVar4 = (char)(param_4 & 0xf) + '7';
    }
    uVar3 = uVar5 - 1;
    acStack_21[uVar5 + 1] = cVar4;
  } while ((uVar5 != 1) && (bVar1 = 0xf < param_4, param_4 = param_4 >> 4, bVar1));
  acStack_21[uVar5] = '~';
  uVar6 = 0;
  do {
    if ((uVar3 <= uVar6) || (*(char *)(param_1 + uVar6) == ' ')) goto LAB_200021bc;
    iVar2 = dbc_1st__or__dbc_2nd();
    if (iVar2 != 0) {
      if (uVar5 - 2 == uVar6) {
LAB_200021bc:
        do {
          if (uVar3 < 8) {
            cVar4 = acStack_21[uVar3 + 1];
            uVar3 = uVar3 + 1;
          }
          else {
            cVar4 = ' ';
          }
          uVar5 = uVar6 + 1;
          *(char *)(param_1 + uVar6) = cVar4;
          uVar6 = uVar5;
        } while (uVar5 < 8);
        return;
      }
      uVar6 = uVar6 + 1;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}


/* ===== store_xdir @ 200021d0 (102 bytes) ===== */

undefined store_xdir(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar4 = *(int *)(*param_1 + 0x10);
  uVar2 = xdir_sum(iVar4);
  st_word(iVar4 + 2,uVar2);
  iVar5 = *(byte *)(iVar4 + 1) + 1;
  uVar6 = dir_sdi(param_1,param_1[0x14]);
  while ((uVar3 = (uint)uVar6, uVar3 == 0 &&
         (uVar3 = move_window(*param_1,(int)((ulonglong)uVar6 >> 0x20),param_1[0xe],param_1[0xf],
                              param_4), uVar3 == 0))) {
    memcpy(param_1[0x10],iVar4,0x20);
    *(undefined *)(*param_1 + 3) = 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) break;
    iVar4 = iVar4 + 0x20;
    uVar6 = dir_next(param_1,0);
  }
  uVar1 = (undefined)uVar3;
  if (2 < uVar3) {
    uVar1 = 2;
  }
  return uVar1;
}


/* ===== create_name @ 20002238 (662 bytes) ===== */

undefined4 create_name(int *param_1,byte **param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_34;
  byte *local_2c [2];
  
  local_2c[0] = *param_2;
  iVar9 = *(int *)(*param_1 + 0xc);
  uVar8 = 0;
  while( true ) {
    uVar2 = tchar2uni(local_2c);
    if (uVar2 == 0xffffffff) {
      return 6;
    }
    if (0xffff < uVar2) {
      *(short *)(iVar9 + uVar8 * 2) = (short)(uVar2 >> 0x10);
      uVar8 = uVar8 + 1;
    }
    uVar10 = uVar2 & 0xffff;
    if (((uVar10 < 0x20) || (uVar10 == 0x2f)) || (uVar10 == 0x5c)) break;
    if ((uVar10 < 0x80) && (iVar3 = strchr(DAT_20002548,uVar2 & 0xffff), iVar3 != 0)) {
      return 6;
    }
    if (0xfe < uVar8) {
      return 6;
    }
    *(short *)(iVar9 + uVar8 * 2) = (short)uVar2;
    uVar8 = uVar8 + 1;
  }
  if (uVar10 < 0x20) {
    uVar2 = 4;
  }
  else {
    for (; (bVar6 = *local_2c[0], bVar6 == 0x2f || (bVar6 == 0x5c)); local_2c[0] = local_2c[0] + 1)
    {
    }
    if (bVar6 < 0x20) {
      uVar2 = 4;
    }
    else {
      uVar2 = 0;
    }
  }
  *param_2 = local_2c[0];
  if (((uVar8 == 1) && (*(short *)((DAT_2000254c + 1) * 2 + iVar9) == 0x2e)) ||
     ((uVar8 == 2 &&
      ((*(short *)((DAT_2000254c + 2) * 2 + iVar9) == 0x2e &&
       (*(short *)((DAT_20002550 + 2) * 2 + iVar9) == 0x2e)))))) {
    *(undefined2 *)(iVar9 + uVar8 * 2) = 0;
    for (uVar10 = 0; uVar10 < 0xb; uVar10 = uVar10 + 1) {
      if (uVar10 < uVar8) {
        uVar5 = 0x2e;
      }
      else {
        uVar5 = 0x20;
      }
      *(undefined *)((int)param_1 + uVar10 + 0x44) = uVar5;
    }
    *(byte *)((int)param_1 + uVar10 + 0x44) = (byte)uVar2 | 0x20;
    uVar4 = 0;
  }
  else {
    while ((uVar8 != 0 &&
           ((sVar1 = *(short *)(iVar9 + (uVar8 + DAT_2000254c) * 2), sVar1 == 0x20 ||
            (sVar1 == 0x2e))))) {
      uVar8 = uVar8 - 1;
    }
    *(undefined2 *)(iVar9 + uVar8 * 2) = 0;
    if (uVar8 != 0) {
      for (uVar10 = 0; sVar1 = *(short *)(uVar10 * 2 + iVar9), sVar1 == 0x20; uVar10 = uVar10 + 1) {
      }
      if ((uVar10 != 0) || (sVar1 == 0x2e)) {
        uVar2 = uVar2 | 3;
      }
      while ((uVar8 != 0 && (*(short *)((uVar8 + DAT_2000254c) * 2 + iVar9) != 0x2e))) {
        uVar8 = uVar8 - 1;
      }
      memset(param_1 + 0x11,0x20,0xb);
      uVar13 = 8;
      local_34 = 0;
      uVar12 = 0;
LAB_2000239c:
      do {
        uVar7 = uVar10 + 1;
        uVar11 = (uint)*(ushort *)(iVar9 + uVar10 * 2);
        if (uVar11 == 0) {
LAB_20002408:
          if (*(char *)(param_1 + 0x11) == -0x1b) {
            *(undefined *)(param_1 + 0x11) = 5;
          }
          if (uVar13 == 8) {
            uVar12 = (uVar12 & 0x3f) << 2;
          }
          if (((uVar12 & 0xc) == 0xc) || ((uVar12 & 3) == 3)) {
            uVar2 = uVar2 | 2;
          }
          bVar6 = (byte)uVar2;
          if (-1 < (int)(uVar2 << 0x1e)) {
            if ((int)(uVar12 << 0x1f) < 0) {
              bVar6 = bVar6 | 0x10;
            }
            if ((int)(uVar12 << 0x1d) < 0) {
              bVar6 = bVar6 | 8;
            }
          }
          *(byte *)((int)param_1 + 0x4f) = bVar6;
          return 0;
        }
        uVar10 = uVar7;
        if ((uVar11 == 0x20) || ((uVar11 == 0x2e && (uVar8 != uVar7)))) {
          uVar2 = uVar2 | 3;
          goto LAB_2000239c;
        }
        if ((local_34 < uVar13) && (uVar8 != uVar7)) {
          if (0x7f < uVar11) {
            uVar2 = uVar2 | 2;
            uVar11 = ff_uni2oem(uVar11,0x1b5);
            if ((int)(uVar11 << 0x18) < 0) {
              uVar11 = (uint)*(byte *)(DAT_20002554 + (uVar11 & 0x7f));
            }
          }
          if (uVar11 < 0x100) {
            if ((uVar11 == 0) || (iVar3 = strchr(DAT_20002558,uVar11), iVar3 != 0)) {
              uVar2 = uVar2 | 3;
              uVar11 = 0x5f;
            }
            else {
              if ((uVar11 - 0x41 & 0xffff) < 0x1a) {
                uVar12 = uVar12 | 2;
              }
              if ((uVar11 - 0x61 & 0xffff) < 0x1a) {
                uVar12 = uVar12 | 1;
                uVar11 = uVar11 - 0x20 & 0xffff;
              }
            }
          }
          else {
            if (uVar13 - 1 <= local_34) {
              uVar2 = uVar2 | 3;
              local_34 = uVar13;
              goto LAB_2000239c;
            }
            *(char *)((int)param_1 + local_34 + 0x44) = (char)(uVar11 >> 8);
            local_34 = local_34 + 1;
          }
          *(char *)((int)param_1 + local_34 + 0x44) = (char)uVar11;
          local_34 = local_34 + 1;
          goto LAB_2000239c;
        }
        if (uVar13 == 0xb) {
          uVar2 = uVar2 | 3;
          goto LAB_20002408;
        }
        if (uVar8 != uVar7) {
          uVar2 = uVar2 | 3;
        }
        if (uVar8 < uVar7) goto LAB_20002408;
        uVar12 = (uVar12 & 0x3f) << 2;
        uVar13 = 0xb;
        local_34 = 8;
        uVar10 = uVar8;
      } while( true );
    }
    uVar4 = 6;
  }
  return uVar4;
}


/* ===== FUN_2000240a @ 2000240a (122 bytes) ===== */

undefined4 FUN_2000240a(void)

{
  byte bVar1;
  int in_r3;
  int unaff_r7;
  uint unaff_r8;
  uint unaff_r10;
  int unaff_r11;
  
  if (*(char *)(unaff_r7 + in_r3) == -0x1b) {
    *(undefined *)(unaff_r7 + 0x44) = 5;
  }
  if (unaff_r11 == 8) {
    unaff_r10 = (unaff_r10 & 0x3f) << 2;
  }
  if (((unaff_r10 & 0xc) == 0xc) || ((unaff_r10 & 3) == 3)) {
    unaff_r8 = unaff_r8 & 0xff | 2;
  }
  bVar1 = (byte)unaff_r8;
  if (-1 < (int)(unaff_r8 << 0x1e)) {
    if ((int)(unaff_r10 << 0x1f) < 0) {
      bVar1 = bVar1 | 0x10;
    }
    if ((int)(unaff_r10 << 0x1d) < 0) {
      bVar1 = bVar1 | 8;
    }
  }
  *(byte *)(unaff_r7 + 0x4f) = bVar1;
  return 0;
}


/* ===== xname_sum @ 2000255c (56 bytes) ===== */

uint xname_sum(short *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (*param_1 == 0) break;
    uVar1 = ff_wtoupper();
    uVar2 = ((uVar2 >> 1) + uVar2 * 0x8000 & 0xffff) + (uVar1 & 0xff) & 0xffff;
    uVar2 = ((uVar2 >> 1) + uVar2 * 0x8000 & 0xffff) + ((uVar1 & 0xffff) >> 8) & 0xffff;
    param_1 = param_1 + 1;
  }
  return uVar2;
}


/* ===== create_xdir @ 20002594 (144 bytes) ===== */

void create_xdir(undefined *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  char cVar7;
  
  memset(param_1,0,0x40);
  *param_1 = 0x85;
  param_1[0x20] = 0xc0;
  sVar5 = 1;
  uVar6 = 0;
  uVar4 = 0x40;
  cVar1 = '\0';
  do {
    cVar7 = cVar1;
    iVar3 = uVar4 + 1;
    param_1[uVar4] = 0xc1;
    uVar4 = uVar4 + 2;
    param_1[iVar3] = 0;
    do {
      if ((sVar5 != 0) && (sVar5 = *(short *)(param_2 + uVar6 * 2), sVar5 != 0)) {
        uVar6 = uVar6 + 1 & 0xff;
      }
      st_word(param_1 + uVar4,sVar5);
      uVar4 = uVar4 + 2;
    } while ((uVar4 & 0x1f) != 0);
    cVar1 = cVar7 + '\x01';
  } while (*(short *)(uVar6 * 2 + param_2) != 0);
  param_1[0x23] = (char)uVar6;
  param_1[1] = cVar7 + '\x02';
  uVar2 = xname_sum(param_2);
  st_word(param_1 + 0x24,uVar2);
  return;
}


/* ===== cmp_lfn @ 20002624 (166 bytes) ===== */

undefined4 cmp_lfn(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  iVar1 = ld_word(param_2 + 0x1a);
  if (iVar1 == 0) {
    iVar1 = 1;
    uVar7 = ((*param_2 & 0x3f) - 1) * 0xd;
    for (uVar6 = 0; uVar6 < 0xd; uVar6 = uVar6 + 1) {
      iVar2 = ld_word(param_2 + *(byte *)(DAT_200026d0 + uVar6));
      if (iVar1 == 0) {
        bVar8 = iVar2 != DAT_200026cc;
        iVar2 = iVar1;
        uVar5 = uVar7;
        if (bVar8) {
          return 0;
        }
      }
      else {
        if (0xff < uVar7) {
          return 0;
        }
        iVar1 = ff_wtoupper();
        uVar5 = uVar7 + 1;
        iVar3 = ff_wtoupper(*(undefined2 *)(uVar7 * 2 + param_1));
        if (iVar1 != iVar3) {
          return 0;
        }
      }
      iVar1 = iVar2;
      uVar7 = uVar5;
    }
    if ((int)((uint)*param_2 << 0x19) < 0) {
      if (iVar1 == 0) {
        uVar4 = 1;
      }
      else if (*(short *)(uVar7 * 2 + param_1) == 0) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* ===== dir_find @ 200026d4 (396 bytes) ===== */

int dir_find(char **param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  byte *pbVar12;
  char *pcVar13;
  undefined8 uVar14;
  
  pcVar13 = *param_1;
  uVar14 = dir_sdi(param_1,0);
  uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
  iVar3 = (int)uVar14;
  if (iVar3 == 0) {
    if (*pcVar13 == '\x04') {
      iVar2 = xname_sum(*(undefined4 *)(pcVar13 + 0xc));
      do {
        do {
          iVar3 = dir_read(param_1,0);
          if (iVar3 != 0) {
            return iVar3;
          }
          iVar11 = *(int *)(pcVar13 + 0x10);
          iVar3 = ld_word(iVar11 + 0x24);
        } while (iVar3 != iVar2);
        iVar7 = 0;
        uVar6 = 0x40;
        for (cVar10 = *(char *)(iVar11 + 0x23); cVar10 != '\0'; cVar10 = cVar10 + -1) {
          if ((uVar6 & 0x1f) == 0) {
            uVar6 = uVar6 + 2;
          }
          ld_word(*(int *)(pcVar13 + 0x10) + uVar6);
          iVar3 = ff_wtoupper();
          iVar11 = ff_wtoupper(*(undefined2 *)(iVar7 * 2 + *(int *)(pcVar13 + 0xc)));
          if (iVar3 != iVar11) break;
          uVar6 = uVar6 + 2;
          iVar7 = iVar7 + 1;
        }
      } while ((cVar10 != '\0') || (iVar3 = 0, *(short *)(iVar7 * 2 + *(int *)(pcVar13 + 0xc)) != 0)
              );
    }
    else {
      param_1[0x14] = (char *)0xffffffff;
      uVar6 = 0xff;
      uVar9 = uVar6;
      while (iVar3 = move_window(pcVar13,uVar4,param_1[0xe],param_1[0xf]), iVar3 == 0) {
        pbVar12 = (byte *)param_1[0x10];
        uVar5 = (uint)*pbVar12;
        if (uVar5 == 0) {
          return 4;
        }
        bVar1 = pbVar12[0xb];
        uVar8 = bVar1 & 0x3f;
        *(char *)((int)param_1 + 6) = (char)uVar8;
        if ((uVar5 == 0xe5) || (((int)((uint)bVar1 << 0x1c) < 0 && (uVar8 != 0xf)))) {
          param_1[0x14] = (char *)0xffffffff;
          uVar6 = 0xff;
        }
        else if (uVar8 == 0xf) {
          if (-1 < (int)((uint)*(byte *)((int)param_1 + 0x4f) << 0x19)) {
            if ((int)(uVar5 << 0x19) < 0) {
              uVar9 = (uint)pbVar12[0xd];
              uVar5 = uVar5 & 0xffffffbf;
              param_1[0x14] = param_1[0xc];
              uVar6 = uVar5;
            }
            if (uVar5 == uVar6) {
              if (pbVar12[0xd] == uVar9) {
                iVar3 = cmp_lfn(*(undefined4 *)(pcVar13 + 0xc),pbVar12);
                if (iVar3 == 0) {
                  uVar6 = 0xff;
                }
                else {
                  uVar6 = uVar6 - 1 & 0xff;
                }
              }
              else {
                uVar6 = 0xff;
              }
            }
            else {
              uVar6 = 0xff;
            }
          }
        }
        else {
          if ((uVar6 == 0) && (uVar6 = sum_sfn(pbVar12), uVar6 == uVar9)) {
            return 0;
          }
          if ((-1 < (int)((uint)*(byte *)((int)param_1 + 0x4f) << 0x1f)) &&
             (iVar3 = memcmp(pbVar12,param_1 + 0x11,0xb), iVar3 == 0)) {
            return 0;
          }
          param_1[0x14] = (char *)0xffffffff;
          uVar6 = 0xff;
        }
        uVar14 = dir_next(param_1,0);
        uVar4 = (undefined4)((ulonglong)uVar14 >> 0x20);
        if ((int)uVar14 != 0) {
          return (int)uVar14;
        }
      }
    }
  }
  return iVar3;
}


/* ===== follow_path @ 20002860 (286 bytes) ===== */

int follow_path(char **param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  byte *local_6c;
  undefined auStack_68 [88];
  
  pcVar5 = *param_1;
  bVar1 = *param_2;
  local_6c = param_2;
  if (((bVar1 == 0x2f) || (bVar1 == 0x5c)) || (bVar1 < 0x20)) {
    for (; (*local_6c == 0x2f || (*local_6c == 0x5c)); local_6c = local_6c + 1) {
    }
    param_1[2] = (char *)0x0;
  }
  else {
    param_1[2] = *(char **)(pcVar5 + 0x1c);
  }
  param_1[7] = (char *)0x0;
  if ((*pcVar5 == '\x04') && (param_1[2] != (char *)0x0)) {
    param_1[8] = *(char **)(pcVar5 + 0x20);
    param_1[9] = *(char **)(pcVar5 + 0x24);
    param_1[10] = *(char **)(pcVar5 + 0x28);
    iVar2 = load_obj_xdir(auStack_68,param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    pcVar3 = (char *)ld_dword(*(int *)(pcVar5 + 0x10) + 0x38);
    param_1[4] = pcVar3;
    param_1[5] = (char *)0x0;
    *(byte *)((int)param_1 + 7) = *(byte *)(*(int *)(pcVar5 + 0x10) + 0x21) & 2;
  }
  if (*local_6c < 0x20) {
    *(undefined *)((int)param_1 + 0x4f) = 0x80;
    iVar2 = dir_sdi(param_1,0);
  }
  else {
    do {
      while( true ) {
        iVar2 = create_name(param_1,&local_6c);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = dir_find(param_1);
        uVar4 = (uint)*(byte *)((int)param_1 + 0x4f);
        if (iVar2 != 0) break;
        if ((int)(uVar4 << 0x1d) < 0) {
          return 0;
        }
        if (-1 < (int)((uint)*(byte *)((int)param_1 + 6) << 0x1b)) {
          return 5;
        }
        if (*pcVar5 == '\x04') {
          param_1[8] = param_1[2];
          param_1[9] = (char *)((uint)param_1[4] & 0xffffff00 | (uint)*(byte *)((int)param_1 + 7));
          param_1[10] = param_1[0x14];
          init_alloc_info(pcVar5,param_1);
        }
        else {
          pcVar3 = (char *)ld_clust(pcVar5,pcVar5 + ((uint)param_1[0xc] & 0x1ff) + 0x68);
          param_1[2] = pcVar3;
        }
      }
      if (iVar2 != 4) {
        return iVar2;
      }
      if (-1 < (int)(uVar4 << 0x1a)) {
        if ((int)(uVar4 << 0x1d) < 0) {
          return 4;
        }
        return 5;
      }
    } while (-1 < (int)(uVar4 << 0x1d));
    *(undefined *)((int)param_1 + 0x4f) = 0x80;
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== dir_register @ 2000297e (514 bytes) ===== */

int dir_register(char **param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int unaff_r8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined auStack_80 [92];
  undefined auStack_24 [11];
  byte local_19;
  
  pcVar6 = *param_1;
  bVar1 = *(byte *)((int)param_1 + 0x4f);
  if ((bVar1 & 0xa0) != 0) {
    return 6;
  }
  for (iVar7 = 0; *(short *)(iVar7 * 2 + *(int *)(pcVar6 + 0xc)) != 0; iVar7 = iVar7 + 1) {
  }
  if (*pcVar6 == '\x04') {
    iVar7 = __aeabi_uidiv(iVar7 + 0xe,0xf);
    iVar3 = dir_alloc(param_1,iVar7 + 2);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1[0x14] = param_1[0xc] + (iVar7 + 1) * -0x20;
    if ((int)((uint)*(byte *)((int)param_1 + 7) << 0x1d) < 0) {
      *(byte *)((int)param_1 + 7) = *(byte *)((int)param_1 + 7) & 0xfb;
      iVar7 = fill_first_frag(param_1);
      if (iVar7 != 0) {
        return iVar7;
      }
      iVar7 = fill_last_frag(param_1,param_1[0xd],0xffffffff);
      if (iVar7 != 0) {
        return iVar7;
      }
      if (param_1[2] != (char *)0x0) {
        iVar7 = load_obj_xdir(auStack_80,param_1);
        if (iVar7 != 0) {
          return iVar7;
        }
        uVar2 = *(ushort *)(pcVar6 + 10);
        pcVar4 = param_1[4];
        param_1[4] = pcVar4 + (uint)uVar2 * 0x200;
        param_1[5] = param_1[5] + CARRY4((uint)uVar2 * 0x200,(uint)pcVar4);
        st_qword(*(int *)(pcVar6 + 0x10) + 0x38);
        st_qword(*(int *)(pcVar6 + 0x10) + 0x28,extraout_r1,param_1[4],param_1[5]);
        *(byte *)(*(int *)(pcVar6 + 0x10) + 0x21) = *(byte *)((int)param_1 + 7) | 1;
        iVar7 = store_xdir(auStack_80);
        if (iVar7 != 0) {
          return iVar7;
        }
      }
    }
    create_xdir(*(undefined4 *)(pcVar6 + 0x10),*(undefined4 *)(pcVar6 + 0xc));
    return 0;
  }
  memcpy(auStack_24,param_1 + 0x11,0xc);
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    *(undefined *)((int)param_1 + 0x4f) = 0x40;
    for (uVar8 = 1; uVar8 < 100; uVar8 = uVar8 + 1) {
      gen_numname(param_1 + 0x11,auStack_24,*(undefined4 *)(pcVar6 + 0xc),uVar8);
      unaff_r8 = dir_find(param_1);
      if (unaff_r8 != 0) break;
    }
    if (uVar8 == 100) {
      return 7;
    }
    if (unaff_r8 != 4) {
      return unaff_r8;
    }
    *(byte *)((int)param_1 + 0x4f) = local_19;
  }
  if ((int)((uint)local_19 << 0x1e) < 0) {
    iVar7 = __aeabi_uidiv(iVar7 + 0xc,0xd);
    iVar7 = iVar7 + 1;
  }
  else {
    iVar7 = 1;
  }
  uVar9 = dir_alloc(param_1,iVar7);
  if ((((int)uVar9 == 0) && (uVar8 = iVar7 - 1, iVar7 != 1)) &&
     (uVar9 = dir_sdi(param_1,param_1[0xc] + uVar8 * -0x20), (int)uVar9 == 0)) {
    uVar10 = sum_sfn(param_1 + 0x11);
    uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
    while (uVar9 = move_window(pcVar6,uVar5,param_1[0xe],param_1[0xf]), (int)uVar9 == 0) {
      put_lfn(*(undefined4 *)(pcVar6 + 0xc),param_1[0x10],uVar8 & 0xff,(int)uVar10);
      pcVar6[3] = '\x01';
      uVar9 = dir_next(param_1,0);
      uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
      if (((int)uVar9 != 0) || (uVar8 = uVar8 - 1, uVar8 == 0)) break;
    }
  }
  iVar7 = (int)uVar9;
  if ((iVar7 == 0) &&
     (iVar7 = move_window(pcVar6,(int)((ulonglong)uVar9 >> 0x20),param_1[0xe],param_1[0xf]),
     iVar7 == 0)) {
    memset(param_1[0x10],0,0x20);
    memcpy(param_1[0x10],param_1 + 0x11,0xb);
    param_1[0x10][0xc] = *(byte *)((int)param_1 + 0x4f) & 0x18;
    pcVar6[3] = '\x01';
  }
  return iVar7;
}


/* ===== remove_chain @ 20002b80 (396 bytes) ===== */

int remove_chain(char **param_1,uint param_2,char *param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 local_30;
  int local_28;
  int local_24;
  
  pcVar3 = *param_1;
  if (param_2 < 2) {
    iVar5 = 2;
  }
  else if (param_2 < *(uint *)(pcVar3 + 0x2c)) {
    uVar6 = param_2;
    local_30 = CONCAT44(local_30._4_4_,(undefined4)local_30);
    if ((param_3 != (char *)0x0) &&
       ((*pcVar3 != '\x04' ||
        (local_30 = CONCAT44(local_30._4_4_,(undefined4)local_30),
        *(char *)((int)param_1 + 7) != '\x02')))) {
      iVar5 = put_fat(pcVar3,param_3,0xffffffff);
      if (iVar5 != 0) {
        return iVar5;
      }
    }
    do {
      uVar1 = get_fat(param_1,param_2);
      if (uVar1 == 0) break;
      if (uVar1 == 1) {
        return 2;
      }
      if (uVar1 == 0xffffffff) {
        return 1;
      }
      if (*pcVar3 != '\x04') {
        iVar5 = put_fat(pcVar3,param_2,0);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      if (*(uint *)(pcVar3 + 0x18) < *(int *)(pcVar3 + 0x2c) - 2U) {
        *(uint *)(pcVar3 + 0x18) = *(uint *)(pcVar3 + 0x18) + 1;
        pcVar3[4] = pcVar3[4] | 1;
      }
      if (param_2 + 1 != uVar1) {
        if (*pcVar3 == '\x04') {
          iVar5 = change_bitmap(pcVar3,uVar6,(param_2 - uVar6) + 1,0);
          if (iVar5 != 0) {
            return iVar5;
          }
        }
        uVar7 = clst2sect(pcVar3,uVar6);
        local_30 = uVar7;
        uVar7 = clst2sect(pcVar3,param_2);
        iVar5 = (uint)*(ushort *)(pcVar3 + 10) + (uint)uVar7;
        local_28 = iVar5 + -1;
        local_24 = (int)((ulonglong)uVar7 >> 0x20) +
                   (uint)CARRY4((uint)*(ushort *)(pcVar3 + 10),(uint)uVar7) + -1 +
                   (uint)(iVar5 != 0);
        disk_ioctl(pcVar3[1],4,&local_30);
        uVar6 = uVar1;
      }
      param_2 = uVar1;
    } while (uVar1 < *(uint *)(pcVar3 + 0x2c));
    if (*pcVar3 == '\x04') {
      if (param_3 == (char *)0x0) {
        *(undefined *)((int)param_1 + 7) = 0;
        iVar5 = 0;
      }
      else if (*(char *)((int)param_1 + 7) == '\0') {
        pcVar3 = param_1[2];
        do {
          pcVar4 = pcVar3;
          if (pcVar4 == param_3) break;
          pcVar2 = (char *)get_fat(param_1,pcVar4);
          if (pcVar2 < (char *)0x2) {
            return 2;
          }
          if (pcVar2 == (char *)0xffffffff) {
            return 1;
          }
          pcVar3 = pcVar4 + 1;
        } while (pcVar4 + 1 == pcVar2);
        iVar5 = 0;
        if (pcVar4 == param_3) {
          *(undefined *)((int)param_1 + 7) = 2;
        }
      }
      else if (*(char *)((int)param_1 + 7) == '\x03') {
        if (param_3 < param_1[2]) {
          iVar5 = 0;
        }
        else if (param_1[2] + (int)param_1[6] < param_3) {
          iVar5 = 0;
        }
        else {
          *(undefined *)((int)param_1 + 7) = 2;
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 2;
  }
  return iVar5;
}


/* ===== sync_fs @ 20002d0c (152 bytes) ===== */

int sync_fs(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar1 = sync_window();
  if (iVar1 == 0) {
    if ((*param_1 == '\x03') && (param_1[4] == '\x01')) {
      pcVar4 = param_1 + 0x68;
      memset(pcVar4,0,0x200);
      st_word(param_1 + DAT_20002da8,DAT_20002da4);
      st_dword(pcVar4,DAT_20002dac);
      st_dword(param_1 + 0x24c,DAT_20002db0);
      st_dword(param_1 + 0x250,*(undefined4 *)(param_1 + 0x18));
      st_dword(param_1 + 0x254,*(undefined4 *)(param_1 + 0x14));
      iVar2 = *(uint *)(param_1 + 0x38) + 1;
      iVar3 = *(int *)(param_1 + 0x3c) + (uint)(0xfffffffe < *(uint *)(param_1 + 0x38));
      *(int *)(param_1 + 0x60) = iVar2;
      *(int *)(param_1 + 100) = iVar3;
      disk_write(param_1[1],pcVar4,iVar2,iVar3,1);
      param_1[4] = '\0';
    }
    iVar2 = disk_ioctl(param_1[1],0,0);
    if (iVar2 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}


/* ===== f_mount @ 20002db4 (80 bytes) ===== */

undefined4 f_mount(undefined *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_18;
  undefined *local_14 [2];
  undefined4 local_c;
  
  local_18 = param_2;
  local_14[0] = param_1;
  local_c = param_2;
  iVar1 = get_ldnumber(&local_c);
  if (iVar1 < 0) {
    uVar2 = 0xb;
  }
  else {
    puVar3 = *(undefined **)(iVar1 * 4 + DAT_20002e04);
    if (puVar3 != (undefined *)0x0) {
      *puVar3 = 0;
    }
    if (local_14[0] != (undefined *)0x0) {
      *local_14[0] = 0;
    }
    *(undefined **)(iVar1 * 4 + DAT_20002e04) = local_14[0];
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = mount_volume(&local_18,local_14,0);
    }
  }
  return uVar2;
}


/* ===== f_open @ 20002e08 (754 bytes) ===== */

int f_open(char **param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined4 local_84 [2];
  char *local_7c;
  char *local_78;
  byte local_72;
  byte local_71;
  char *local_70;
  uint local_68;
  char *local_38;
  char cStack_29;
  char *local_28;
  
  if (param_1 == (char **)0x0) {
    return 9;
  }
  uVar8 = param_3 & 0x3f;
  local_84[0] = param_2;
  iVar2 = mount_volume(local_84,&local_7c,uVar8);
  if (iVar2 == 0) {
    local_78 = local_7c;
    iVar2 = follow_path(&local_78,local_84[0]);
    if ((iVar2 == 0) && (cStack_29 < '\0')) {
      iVar2 = 6;
    }
    if ((param_3 & 0x1c) == 0) {
      if (iVar2 != 0) goto LAB_20002fa8;
      if ((int)((uint)local_72 << 0x1b) < 0) {
        iVar2 = 4;
      }
      else {
        if ((-1 < (int)(param_3 << 0x1e)) || (-1 < (int)((uint)local_72 << 0x1f)))
        goto LAB_20002fa8;
        iVar2 = 7;
      }
    }
    else {
      if (iVar2 == 0) {
        if ((local_72 & 0x11) == 0) {
          if (-1 < (int)(param_3 << 0x1d)) goto LAB_20002e74;
          iVar2 = 8;
        }
        else {
          iVar2 = 7;
        }
      }
      else {
        if (iVar2 == 4) {
          iVar2 = dir_register(&local_78);
        }
        uVar8 = uVar8 | 8;
LAB_20002e74:
        uVar5 = DAT_200030fc;
        if ((iVar2 == 0) && ((int)(uVar8 << 0x1c) < 0)) {
          if (*local_7c == '\x04') {
            *param_1 = local_7c;
            init_alloc_info(local_7c,param_1);
            memset(*(int *)(local_7c + 0x10) + 2,0,0x1e);
            pcVar3 = local_7c;
            memset(*(int *)(local_7c + 0x10) + 0x26,0,0x1a);
            *(undefined *)(*(int *)(pcVar3 + 0x10) + 4) = 0x20;
            st_dword(*(int *)(pcVar3 + 0x10) + 8,DAT_200030fc);
            *(undefined *)(*(int *)(local_7c + 0x10) + 0x21) = 1;
            iVar2 = store_xdir(&local_78);
            if ((iVar2 == 0) && (param_1[2] != (char *)0x0)) {
              iVar2 = remove_chain(param_1,param_1[2],0);
              *(char **)(local_7c + 0x14) = param_1[2] + -1;
            }
          }
          else {
            st_dword(local_38 + 0xe,DAT_200030fc);
            st_dword(local_38 + 0x16,uVar5);
            pcVar9 = local_38;
            pcVar3 = local_7c;
            iVar4 = ld_clust(local_7c,local_38);
            pcVar9[0xb] = ' ';
            st_clust(pcVar3,local_38,0);
            st_dword(local_38 + 0x1c,0);
            local_7c[3] = '\x01';
            if (iVar4 != 0) {
              uVar5 = *(undefined4 *)(local_7c + 0x60);
              uVar6 = *(undefined4 *)(local_7c + 100);
              uVar11 = remove_chain(&local_78,iVar4,0);
              iVar2 = (int)uVar11;
              if (iVar2 == 0) {
                iVar2 = move_window(local_7c,(int)((ulonglong)uVar11 >> 0x20),uVar5,uVar6);
                *(int *)(local_7c + 0x14) = iVar4 + -1;
              }
            }
          }
        }
      }
LAB_20002fa8:
      if (iVar2 == 0) {
        if ((int)(uVar8 << 0x1c) < 0) {
          uVar8 = uVar8 | 0x40;
        }
        pcVar3 = *(char **)(local_7c + 100);
        param_1[0x14] = *(char **)(local_7c + 0x60);
        param_1[0x15] = pcVar3;
        param_1[0x16] = local_38;
      }
    }
    if (iVar2 == 0) {
      if (*local_7c == '\x04') {
        param_1[8] = local_70;
        param_1[9] = (char *)(local_68 & 0xffffff00 | (uint)local_71);
        param_1[10] = local_28;
        init_alloc_info(local_7c,param_1);
      }
      else {
        pcVar3 = (char *)ld_clust(local_7c,local_38);
        param_1[2] = pcVar3;
        pcVar3 = (char *)ld_dword(local_38 + 0x1c);
        param_1[4] = pcVar3;
        param_1[5] = (char *)0x0;
      }
      pcVar3 = local_7c;
      *param_1 = local_7c;
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_7c + 6);
      *(char *)(param_1 + 0xc) = (char)uVar8;
      *(undefined *)((int)param_1 + 0x31) = 0;
      param_1[0x12] = (char *)0x0;
      param_1[0x13] = (char *)0x0;
      param_1[0xe] = (char *)0x0;
      param_1[0xf] = (char *)0x0;
      memset(param_1 + 0x17,0,0x200);
      if ((int)(uVar8 << 0x1a) < 0) {
        pcVar9 = param_1[4];
        pcVar10 = param_1[5];
        if (((uint)pcVar9 | (uint)pcVar10) != 0) {
          param_1[0xe] = pcVar9;
          param_1[0xf] = pcVar10;
          uVar1 = *(ushort *)(pcVar3 + 10);
          pcVar7 = (char *)((uint)uVar1 * 0x200);
          pcVar3 = param_1[2];
          for (; (iVar2 == 0 && ((pcVar10 != (char *)0x0 || (pcVar7 < pcVar9))));
              pcVar9 = pcVar9 + (uint)uVar1 * -0x200) {
            pcVar3 = (char *)get_fat(param_1);
            if (pcVar3 < (char *)0x2) {
              iVar2 = 2;
            }
            if (pcVar3 == (char *)0xffffffff) {
              iVar2 = 1;
            }
            pcVar10 = pcVar10 + -(uint)(pcVar9 < pcVar7);
          }
          param_1[0x10] = pcVar3;
          if ((iVar2 == 0) && (((uint)pcVar9 & 0x1ff) != 0)) {
            lVar12 = clst2sect(local_7c);
            if (lVar12 == 0) {
              iVar2 = 2;
              goto LAB_20002e34;
            }
            lVar12 = lVar12 + (ulonglong)((int)pcVar10 << 0x17 | (uint)pcVar9 >> 9);
            *(longlong *)(param_1 + 0x12) = lVar12;
            iVar4 = disk_read(local_7c[1],param_1 + 0x17,(int)lVar12,
                              (int)((ulonglong)lVar12 >> 0x20),1);
            if (iVar4 != 0) {
              iVar2 = 1;
              goto LAB_20002e34;
            }
          }
        }
      }
    }
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_20002e34:
  *param_1 = (char *)0x0;
  return iVar2;
}


/* ===== f_read @ 20003100 (574 bytes) ===== */

uint f_read(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  uint local_44;
  int local_2c [2];
  
  *param_4 = 0;
  local_44 = validate(param_1,local_2c);
  if ((local_44 == 0) && (local_44 = (uint)*(byte *)(param_1 + 0x31), local_44 == 0)) {
    if ((int)((uint)*(byte *)(param_1 + 0x30) << 0x1f) < 0) {
      uVar4 = *(uint *)(param_1 + 0x10) - *(uint *)(param_1 + 0x38);
      uVar7 = param_3;
      if ((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x3c) ==
           (uint)(*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 0x38))) &&
         (uVar7 = uVar4, param_3 <= uVar4)) {
        uVar7 = param_3;
      }
      for (; uVar7 != 0; uVar7 = uVar7 - uVar4) {
        uVar4 = *(uint *)(param_1 + 0x38);
        if ((uVar4 & 0x1ff) == 0) {
          uVar5 = uVar4 >> 9 | *(uint *)(param_1 + 0x3c) << 0x17;
          uVar2 = *(ushort *)(local_2c[0] + 10) - 1;
          uVar6 = uVar2 & uVar5;
          if ((uVar2 & uVar5) == 0) {
            if ((uVar4 | *(uint *)(param_1 + 0x3c)) == 0) {
              uVar4 = *(uint *)(param_1 + 8);
            }
            else {
              uVar4 = get_fat(param_1,*(undefined4 *)(param_1 + 0x40));
            }
            if (uVar4 < 2) {
              *(undefined *)(param_1 + 0x31) = 2;
              return 2;
            }
            if (uVar4 == 0xffffffff) {
              *(undefined *)(param_1 + 0x31) = 1;
              return 1;
            }
            *(uint *)(param_1 + 0x40) = uVar4;
          }
          iVar1 = local_2c[0];
          lVar8 = clst2sect(local_2c[0],*(undefined4 *)(param_1 + 0x40));
          if (lVar8 == 0) {
            *(undefined *)(param_1 + 0x31) = 2;
            return 2;
          }
          lVar8 = lVar8 + (ulonglong)uVar6;
          uVar2 = (uint)lVar8;
          iVar3 = (int)((ulonglong)lVar8 >> 0x20);
          uVar4 = uVar7 >> 9;
          if (uVar7 < 0x200) {
            if (lVar8 != *(longlong *)(param_1 + 0x48)) {
              if (*(char *)(param_1 + 0x30) < '\0') {
                iVar1 = disk_write(*(undefined *)(iVar1 + 1),param_1 + 0x5c,
                                   *(undefined4 *)(longlong *)(param_1 + 0x48),
                                   *(undefined4 *)(param_1 + 0x4c),1);
                if (iVar1 != 0) {
                  *(undefined *)(param_1 + 0x31) = 1;
                  return 1;
                }
                *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) & 0x7f;
              }
              iVar1 = disk_read(*(undefined *)(local_2c[0] + 1),param_1 + 0x5c,uVar2,iVar3,1);
              if (iVar1 != 0) {
                *(undefined *)(param_1 + 0x31) = 1;
                return 1;
              }
            }
            *(longlong *)(param_1 + 0x48) = lVar8;
            goto LAB_200031f8;
          }
          if ((uint)*(ushort *)(iVar1 + 10) < uVar6 + uVar4) {
            uVar4 = *(ushort *)(iVar1 + 10) - uVar6;
          }
          iVar1 = disk_read(*(undefined *)(iVar1 + 1),param_2,uVar2,iVar3,uVar4);
          if (iVar1 != 0) {
            *(undefined *)(param_1 + 0x31) = 1;
            return 1;
          }
          if (((*(char *)(param_1 + 0x30) < '\0') &&
              (uVar5 = *(uint *)(param_1 + 0x48) - uVar2,
              *(int *)(param_1 + 0x4c) - iVar3 == (uint)(*(uint *)(param_1 + 0x48) < uVar2))) &&
             (uVar5 < uVar4)) {
            memcpy(param_2 + uVar5 * 0x200,param_1 + 0x5c,0x200);
          }
          uVar4 = uVar4 << 9;
        }
        else {
LAB_200031f8:
          uVar2 = *(uint *)(param_1 + 0x38) & 0x1ff;
          uVar4 = 0x200 - uVar2;
          if (uVar7 < uVar4) {
            uVar4 = uVar7;
          }
          memcpy(param_2,param_1 + 0x5c + uVar2,uVar4);
        }
        *param_4 = *param_4 + uVar4;
        param_2 = param_2 + uVar4;
        uVar2 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x38) = uVar2 + uVar4;
        *(uint *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + (uint)CARRY4(uVar2,uVar4);
      }
    }
    else {
      local_44 = 7;
    }
  }
  return local_44;
}


/* ===== f_sync @ 20003340 (328 bytes) ===== */

int f_sync(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined8 uVar3;
  undefined auStack_70 [92];
  char *local_14 [2];
  
  uVar3 = validate(param_1,local_14);
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  iVar1 = (int)uVar3;
  if ((iVar1 == 0) && ((int)((uint)*(byte *)(param_1 + 0xc) << 0x19) < 0)) {
    if ((char)*(byte *)(param_1 + 0xc) < '\0') {
      iVar1 = disk_write(local_14[0][1],param_1 + 0x17,param_1[0x12],param_1[0x13],1);
      if (iVar1 != 0) {
        return 1;
      }
      uVar2 = (uint)*(byte *)(param_1 + 0xc);
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0x7f;
    }
    if (*local_14[0] == '\x04') {
      iVar1 = fill_first_frag(param_1);
      if (iVar1 == 0) {
        iVar1 = fill_last_frag(param_1,param_1[0x10],0xffffffff);
      }
      if ((iVar1 == 0) && (iVar1 = load_obj_xdir(auStack_70,param_1), iVar1 == 0)) {
        *(byte *)(*(int *)(local_14[0] + 0x10) + 4) =
             *(byte *)(*(int *)(local_14[0] + 0x10) + 4) | 0x20;
        *(byte *)(*(int *)(local_14[0] + 0x10) + 0x21) = *(byte *)((int)param_1 + 7) | 1;
        st_dword(*(int *)(local_14[0] + 0x10) + 0x34,param_1[2]);
        st_qword(*(int *)(local_14[0] + 0x10) + 0x38,extraout_r1,param_1[4],param_1[5]);
        st_qword(*(int *)(local_14[0] + 0x10) + 0x28,extraout_r1_00,param_1[4],param_1[5]);
        st_dword(*(int *)(local_14[0] + 0x10) + 0xc,DAT_20003488);
        *(undefined *)(*(int *)(local_14[0] + 0x10) + 0x15) = 0;
        st_dword(*(int *)(local_14[0] + 0x10) + 0x10,0);
        iVar1 = store_xdir(auStack_70);
        if (iVar1 == 0) {
          iVar1 = sync_fs(local_14[0]);
          *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xbf;
        }
      }
    }
    else {
      iVar1 = move_window(local_14[0],uVar2,param_1[0x14],param_1[0x15]);
      if (iVar1 == 0) {
        iVar1 = param_1[0x16];
        *(byte *)(iVar1 + 0xb) = *(byte *)(iVar1 + 0xb) | 0x20;
        st_clust(*param_1,iVar1,param_1[2]);
        st_dword(iVar1 + 0x1c,param_1[4]);
        st_dword(iVar1 + 0x16,DAT_20003488);
        st_word(iVar1 + 0x12,0);
        local_14[0][3] = '\x01';
        iVar1 = sync_fs(local_14[0]);
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xbf;
      }
    }
  }
  return iVar1;
}


/* ===== f_close @ 2000348c (36 bytes) ===== */

void f_close(undefined4 *param_1)

{
  int iVar1;
  undefined auStack_c [4];
  
  iVar1 = f_sync();
  if ((iVar1 == 0) && (iVar1 = validate(param_1,auStack_c), iVar1 == 0)) {
    *param_1 = 0;
  }
  return;
}


/* ===== f_chdrive @ 200034b0 (30 bytes) ===== */

undefined4 f_chdrive(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c [3];
  
  local_c[0] = param_1;
  iVar1 = get_ldnumber(local_c);
  if (iVar1 < 0) {
    uVar2 = 0xb;
  }
  else {
    *DAT_200034d0 = (char)iVar1;
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== f_chdir @ 200034d4 (190 bytes) ===== */

int f_chdir(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_74 [2];
  char *local_6c;
  char *local_68;
  byte local_62;
  byte local_61;
  undefined4 local_60;
  uint local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_28;
  char cStack_19;
  undefined4 local_18;
  
  local_74[0] = param_1;
  iVar2 = mount_volume(local_74,&local_6c,0);
  if (iVar2 != 0) {
    return iVar2;
  }
  local_68 = local_6c;
  iVar2 = follow_path(&local_68,local_74[0]);
  pcVar1 = local_6c;
  if (iVar2 == 0) {
    if (cStack_19 < '\0') {
      *(undefined4 *)(local_6c + 0x1c) = local_60;
      if (*local_6c == '\x04') {
        *(undefined4 *)(local_6c + 0x20) = local_48;
        *(undefined4 *)(local_6c + 0x24) = local_44;
        *(undefined4 *)(local_6c + 0x28) = local_40;
      }
    }
    else {
      if (-1 < (int)((uint)local_62 << 0x1b)) {
        iVar2 = 5;
        goto LAB_20003534;
      }
      if (*local_6c == '\x04') {
        uVar3 = ld_dword(*(int *)(local_6c + 0x10) + 0x34);
        *(undefined4 *)(pcVar1 + 0x1c) = uVar3;
        *(undefined4 *)(pcVar1 + 0x20) = local_60;
        *(uint *)(pcVar1 + 0x24) = local_58 & 0xffffff00 | (uint)local_61;
        *(undefined4 *)(pcVar1 + 0x28) = local_18;
      }
      else {
        uVar3 = ld_clust(local_6c,local_28);
        *(undefined4 *)(pcVar1 + 0x1c) = uVar3;
      }
    }
  }
  if (iVar2 == 4) {
    return 5;
  }
LAB_20003534:
  if (iVar2 == 0) {
    for (iVar4 = 1; (iVar4 != 0 && (*(char **)(iVar4 * 4 + DAT_20003594) != local_6c));
        iVar4 = iVar4 + -1) {
    }
    *DAT_20003598 = (char)iVar4;
  }
  return iVar2;
}


/* ===== f_lseek @ 2000359c (780 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x2000384e) */
/* WARNING: Removing unreachable block (ram,0x20003674) */

uint f_lseek(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint local_48;
  uint local_44;
  char *local_24;
  
  uVar1 = validate(param_1,&local_24);
  if (uVar1 == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x31);
  }
  if ((uVar1 == 0) && (*local_24 == '\x04')) {
    uVar1 = fill_last_frag(param_1,*(undefined4 *)(param_1 + 0x40),0xffffffff);
  }
  if (uVar1 != 0) {
    return uVar1;
  }
  local_48 = param_3;
  local_44 = param_4;
  if ((*local_24 != '\x04') && (param_4 != 0)) {
    local_48 = 0xffffffff;
    local_44 = 0;
  }
  uVar1 = *(uint *)(param_1 + 0x14);
  if (((uVar1 < local_44) || ((local_44 == uVar1 && (*(uint *)(param_1 + 0x10) < local_48)))) &&
     (-1 < (int)((uint)*(byte *)(param_1 + 0x30) << 0x1e))) {
    local_48 = *(uint *)(param_1 + 0x10);
    local_44 = uVar1;
  }
  uVar7 = CONCAT44(local_44,local_48);
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar2 = *(uint *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if ((local_48 | local_44) == 0) goto LAB_200036c2;
  uVar5 = (uint)*(ushort *)(local_24 + 10);
  uVar4 = uVar5 * 0x200;
  if ((uVar1 | uVar2) == 0) {
LAB_200036ac:
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == 0) {
      iVar3 = create_chain(param_1);
      if (iVar3 == 1) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      if (iVar3 == -1) {
        *(undefined *)(param_1 + 0x31) = 1;
        return 1;
      }
      *(int *)(param_1 + 8) = iVar3;
    }
    *(int *)(param_1 + 0x40) = iVar3;
  }
  else {
    uVar7 = __aeabi_uldivmod(local_48 - 1,(local_44 - 1) + (uint)(local_48 != 0),uVar4,0);
    iVar3 = (uVar2 - 1) + (uint)(uVar1 != 0);
    uVar8 = __aeabi_uldivmod(uVar1 - 1,iVar3,uVar4,0);
    if (uVar7 < uVar8) goto LAB_200036ac;
    uVar1 = uVar1 - 1 & uVar5 * -0x200;
    *(uint *)(param_1 + 0x38) = uVar1;
    *(int *)(param_1 + 0x3c) = iVar3;
    bVar6 = local_48 < uVar1;
    local_48 = local_48 - uVar1;
    local_44 = (local_44 - iVar3) - (uint)bVar6;
    iVar3 = *(int *)(param_1 + 0x40);
  }
  if (iVar3 == 0) {
    uVar7 = 0;
  }
  else {
    while ((local_44 != 0 || (uVar4 < local_48))) {
      bVar6 = local_48 < uVar4;
      local_48 = local_48 + uVar5 * -0x200;
      local_44 = local_44 - bVar6;
      uVar1 = *(uint *)(param_1 + 0x38) + uVar4;
      uVar2 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),uVar4);
      *(uint *)(param_1 + 0x38) = uVar1;
      *(uint *)(param_1 + 0x3c) = uVar2;
      if ((int)((uint)*(byte *)(param_1 + 0x30) << 0x1e) < 0) {
        if ((*(uint *)(param_1 + 0x14) < uVar2) ||
           ((uVar2 == *(uint *)(param_1 + 0x14) && (*(uint *)(param_1 + 0x10) < uVar1)))) {
          *(uint *)(param_1 + 0x10) = uVar1;
          *(uint *)(param_1 + 0x14) = uVar2;
          *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 0x40;
        }
        uVar1 = create_chain(param_1);
        if (uVar1 == 0) {
          local_48 = 0;
          local_44 = 0;
          break;
        }
      }
      else {
        uVar1 = get_fat(param_1);
      }
      if (uVar1 == 0xffffffff) {
        *(undefined *)(param_1 + 0x31) = 1;
        return 1;
      }
      if ((uVar1 < 2) || (*(uint *)(local_24 + 0x2c) <= uVar1)) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      *(uint *)(param_1 + 0x40) = uVar1;
    }
    uVar1 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x38) = uVar1 + local_48;
    *(uint *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + local_44 + (uint)CARRY4(uVar1,local_48);
    if ((local_48 & 0x1ff) == 0) {
      uVar7 = (ulonglong)(local_48 & 0x1ff);
    }
    else {
      lVar9 = clst2sect(local_24);
      if (lVar9 == 0) {
        *(undefined *)(param_1 + 0x31) = 2;
        return 2;
      }
      uVar7 = lVar9 + (ulonglong)(local_44 << 0x17 | local_48 >> 9);
    }
  }
LAB_200036c2:
  local_44 = (uint)(uVar7 >> 0x20);
  local_48 = (uint)uVar7;
  uVar2 = *(uint *)(param_1 + 0x38);
  uVar1 = *(uint *)(param_1 + 0x3c);
  if ((*(uint *)(param_1 + 0x14) < uVar1) ||
     ((uVar1 == *(uint *)(param_1 + 0x14) && (*(uint *)(param_1 + 0x10) < uVar2)))) {
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint *)(param_1 + 0x14) = uVar1;
    *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 0x40;
  }
  uVar1 = 0;
  if ((uVar2 & 0x1ff) != 0) {
    if (uVar7 != *(ulonglong *)(param_1 + 0x48)) {
      if (*(char *)(param_1 + 0x30) < '\0') {
        iVar3 = disk_write(local_24[1],param_1 + 0x5c,*(undefined4 *)(ulonglong *)(param_1 + 0x48),
                           *(undefined4 *)(param_1 + 0x4c),1);
        if (iVar3 != 0) {
          *(undefined *)(param_1 + 0x31) = 1;
          return 1;
        }
        *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) & 0x7f;
      }
      iVar3 = disk_read(local_24[1],param_1 + 0x5c,local_48,local_44,1);
      if (iVar3 == 0) {
        *(ulonglong *)(param_1 + 0x48) = uVar7;
      }
      else {
        *(undefined *)(param_1 + 0x31) = 1;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* ===== f_opendir @ 200038a8 (142 bytes) ===== */

int f_opendir(char **param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_14 [2];
  char *local_c;
  
  if (param_1 == (char **)0x0) {
    return 9;
  }
  local_14[0] = param_2;
  iVar1 = mount_volume(local_14,&local_c,0);
  if (iVar1 == 0) {
    *param_1 = local_c;
    iVar1 = follow_path(param_1,local_14[0]);
    if (iVar1 == 0) {
      if (-1 < *(char *)((int)param_1 + 0x4f)) {
        if (-1 < (int)((uint)*(byte *)((int)param_1 + 6) << 0x1b)) {
          iVar1 = 5;
          goto LAB_20003908;
        }
        if (*local_c == '\x04') {
          param_1[8] = param_1[2];
          param_1[9] = (char *)((uint)param_1[4] & 0xffffff00 | (uint)*(byte *)((int)param_1 + 7));
          param_1[10] = param_1[0x14];
          init_alloc_info(local_c,param_1);
        }
        else {
          pcVar2 = (char *)ld_clust(local_c,param_1[0x10]);
          param_1[2] = pcVar2;
        }
      }
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_c + 6);
      iVar1 = dir_sdi(param_1,0);
    }
LAB_20003908:
    if (iVar1 == 4) {
      iVar1 = 5;
      goto LAB_200038c4;
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_200038c4:
  *param_1 = (char *)0x0;
  return iVar1;
}


/* ===== ff_uni2oem @ 20003938 (64 bytes) ===== */

uint ff_uni2oem(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 < 0x80) {
    param_1 = param_1 & 0xffff;
  }
  else if (param_1 < 0x10000) {
    if (param_2 == 0x1b5) {
      uVar1 = 0;
      while ((uVar1 < 0x80 && (*(ushort *)(DAT_20003978 + uVar1 * 2) != param_1))) {
        uVar1 = uVar1 + 1 & 0xffff;
      }
      param_1 = uVar1 + 0x80 & 0xff;
    }
    else {
      param_1 = 0;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}


/* ===== ff_wtoupper @ 2000397c (86 bytes) ===== */

uint ff_wtoupper(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  uVar6 = param_1;
  if (param_1 < 0x10000) {
    uVar6 = param_1 & 0xffff;
    puVar2 = DAT_20003a18;
    if (uVar6 < 0x1000) {
      puVar2 = DAT_20003a14;
    }
    while( true ) {
      uVar1 = (uint)*puVar2;
      if (uVar1 == 0) {
        return uVar6;
      }
      if (uVar6 < uVar1) {
        return uVar6;
      }
      puVar5 = puVar2 + 2;
      uVar4 = (uint)(puVar2[1] >> 8);
      uVar3 = puVar2[1] & 0xff;
      if ((param_1 & 0xffff) < uVar3 + uVar1) break;
      puVar2 = puVar5;
      if (uVar4 == 0) {
        puVar2 = puVar5 + uVar3;
      }
    }
    if (uVar4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x200039cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (**(code **)(DAT_20003a1c + uVar4 * 4))();
      return uVar6;
    }
  }
  return uVar6;
}


/* ===== disk_initialize @ 20003a24 (26 bytes) ===== */

undefined4 disk_initialize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = mmc_disk_initialize();
  }
  else if (param_1 == 1) {
    uVar1 = usb_disk_initialize();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ===== disk_status @ 20003a3e (26 bytes) ===== */

undefined4 disk_status(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = mmc_disk_status();
  }
  else if (param_1 == 1) {
    uVar1 = usb_disk_status();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* ===== disk_read @ 20003a58 (42 bytes) ===== */

undefined4 disk_read(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = mmc_disk_read(param_2);
  }
  else if (param_1 == 1) {
    uVar1 = usb_disk_read();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== disk_write @ 20003a82 (42 bytes) ===== */

undefined4 disk_write(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = mmc_disk_write(param_2);
  }
  else if (param_1 == 1) {
    uVar1 = usb_disk_write();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== disk_ioctl @ 20003aac (32 bytes) ===== */

undefined4 disk_ioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = mmc_disk_ioctl(param_2,param_3);
  }
  else if (param_1 == 1) {
    uVar1 = usb_disk_ioctl();
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


/* ===== mmc_disk_timerproc @ 20003acc (46 bytes) ===== */

void mmc_disk_timerproc(void)

{
  if (*DAT_20003afc < 10) {
    *DAT_20003afc = 0;
  }
  else {
    *DAT_20003afc = *DAT_20003afc - 10;
  }
  if (*DAT_20003b00 < 10) {
    *DAT_20003b00 = 0;
  }
  else {
    *DAT_20003b00 = *DAT_20003b00 - 10;
  }
  return;
}


/* ===== mmc_power_on @ 20003b04 (72 bytes) ===== */

void mmc_power_on(void)

{
  undefined8 uVar1;
  
  DAT_d0000024 = 0x1000000;
  DAT_d0000014 = 0x20;
  sd_spi_set_speed(0);
  if (*DAT_20003b4c == 0) {
    uVar1 = alarm_pool_get_default();
    alarm_pool_add_repeating_timer_us
              ((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_20003b58,0xffffffff,DAT_20003b54,0,
               DAT_20003b50);
  }
  *DAT_20003b4c = 1;
  return;
}


/* ===== xchg_spi @ 20003b5c (26 bytes) ===== */

undefined xchg_spi(undefined param_1)

{
  undefined local_10 [4];
  undefined local_c [12];
  
  local_c[0] = param_1;
  spi_write_read_blocking(DAT_20003b78,local_c,local_10,1);
  return local_10[0];
}


/* ===== wait_ready @ 20003b7c (36 bytes) ===== */

bool wait_ready(uint param_1)

{
  int iVar1;
  
  *DAT_20003ba0 = param_1;
  do {
    iVar1 = xchg_spi(0xff);
  } while ((*DAT_20003ba0 & (uint)(iVar1 != 0xff)) != 0);
  return iVar1 == 0xff;
}


/* ===== deselect @ 20003ba4 (42 bytes) ===== */

void deselect(void)

{
  busy_wait_us_32(10);
  xchg_spi(0xff);
  busy_wait_us_32(10);
  DAT_d0000014 = 0x20;
  xchg_spi(0xff);
  busy_wait_us_32(10);
  return;
}


/* ===== select @ 20003bce (40 bytes) ===== */

bool select(void)

{
  int iVar1;
  
  xchg_spi(0xff);
  DAT_d0000018 = 0x20;
  iVar1 = wait_ready(500);
  if (iVar1 == 0) {
    deselect();
  }
  return iVar1 != 0;
}


/* ===== send_cmd @ 20003bf6 (160 bytes) ===== */

int send_cmd(uint param_1,uint param_2)

{
  undefined uVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  
  if ((char)param_1 < '\0') {
    param_1 = param_1 & 0x7f;
    iVar3 = send_cmd(0x37,0);
    if (1 < iVar3) {
      return iVar3;
    }
  }
  if (param_1 != 0xc) {
    deselect();
    iVar3 = select();
    if (iVar3 == 0) {
      return -1;
    }
  }
  xchg_spi(param_1 & 0xff | 0x40);
  xchg_spi(param_2 >> 0x18);
  xchg_spi(param_2 >> 0x10 & 0xff);
  xchg_spi(param_2 >> 8 & 0xff);
  xchg_spi(param_2 & 0xff);
  if (param_1 == 0) {
    uVar1 = 0x95;
  }
  else if (param_1 == 8) {
    uVar1 = 0x87;
  }
  else {
    uVar1 = 0xff;
  }
  xchg_spi(uVar1);
  if (param_1 == 0xc) {
    xchg_spi(0xff);
  }
  cVar4 = '\n';
  do {
    bVar2 = xchg_spi(0xff);
    if (-1 < (int)((uint)bVar2 << 0x18)) {
      return (int)(char)bVar2;
    }
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return (int)(char)bVar2;
}


/* ===== rcvr_spi_multi @ 20003c98 (26 bytes) ===== */

void rcvr_spi_multi(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    spi_read_blocking(DAT_20003cb4,0xff,param_1,param_2);
  }
  return;
}


/* ===== rcvr_datablock @ 20003cb8 (78 bytes) ===== */

bool rcvr_datablock(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *DAT_20003d08 = 200;
  do {
    iVar1 = xchg_spi(0xff);
    if (iVar1 != 0xff) break;
  } while (*DAT_20003d08 != 0);
  if (iVar1 == 0xfe) {
    rcvr_spi_multi(param_1,param_2);
    xchg_spi(0xff);
    xchg_spi(0xff);
    busy_wait_us_32(10);
  }
  else {
    __wrap_printf(DAT_20003d0c,iVar1);
  }
  return iVar1 == 0xfe;
}


/* ===== xmit_spi_multi @ 20003d10 (24 bytes) ===== */

void xmit_spi_multi(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    spi_write_blocking(DAT_20003d28,param_1,param_2);
  }
  return;
}


/* ===== xmit_datablock @ 20003d2c (86 bytes) ===== */

int xmit_datablock(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = wait_ready(500);
  if (iVar1 != 0) {
    xchg_spi(param_2);
    if (param_2 == 0xfd) {
      iVar1 = 1;
    }
    else {
      xmit_spi_multi(param_1,0x200);
      xchg_spi(0);
      xchg_spi(0);
      uVar2 = xchg_spi(0xff);
      if ((uVar2 & 0x1f) == 5) {
        iVar1 = 1;
      }
      else {
        __wrap_printf(DAT_20003d84,uVar2);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


/* ===== mmc_disk_initialize @ 20003d88 (332 bytes) ===== */

uint mmc_disk_initialize(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte local_14 [4];
  
  mmc_power_on();
  uVar5 = *DAT_20003ed4 & 2;
  if ((*DAT_20003ed4 & 2) == 0) {
    sd_spi_set_speed(0);
    for (uVar2 = uVar5; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
      xchg_spi(0xff);
    }
    uVar2 = send_cmd(0,0);
    if (uVar2 == 1) {
      *DAT_20003ed8 = 1000;
      iVar3 = send_cmd(8,0x1aa);
      if (iVar3 == 1) {
        __wrap_puts(DAT_20003ee0);
        for (uVar2 = uVar5; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
          bVar1 = xchg_spi(0xff);
          local_14[uVar2] = bVar1;
        }
        if ((local_14[2] == '\x01') && (local_14[3] == -0x56)) {
          do {
            if (*DAT_20003ed8 == 0) break;
            iVar3 = send_cmd(0xa9,0x40000000);
          } while (iVar3 != 0);
          if ((*DAT_20003ed8 != 0) && (iVar3 = send_cmd(0x3a,0), iVar3 == 0)) {
            for (; uVar5 < 4; uVar5 = uVar5 + 1 & 0xff) {
              bVar1 = xchg_spi(0xff);
              local_14[uVar5] = bVar1;
            }
            if ((int)((uint)local_14[0] << 0x19) < 0) {
              uVar5 = 0x18;
            }
            else {
              uVar5 = 8;
            }
          }
        }
      }
      else {
        iVar3 = send_cmd(0xa9,0);
        if (iVar3 < 2) {
          uVar2 = 4;
          uVar4 = 0xa9;
        }
        else {
          uVar2 = 1;
          uVar4 = 1;
        }
        do {
          if (*DAT_20003ed8 == 0) break;
          iVar3 = send_cmd(uVar4,0);
        } while (iVar3 != 0);
        if ((*DAT_20003ed8 != 0) && (iVar3 = send_cmd(0x10,0x200), iVar3 == 0)) {
          uVar5 = uVar2;
        }
      }
      *DAT_20003edc = uVar5;
      deselect();
      if (uVar5 == 0) {
        *DAT_20003ed4 = 1;
      }
      else {
        sd_spi_set_speed(1);
        send_cmd(0x3b,0);
        *DAT_20003ed4 = *DAT_20003ed4 & 0xfe;
      }
      uVar2 = (uint)*DAT_20003ed4;
    }
  }
  else {
    uVar2 = (uint)*DAT_20003ed4;
  }
  return uVar2;
}


/* ===== mmc_disk_status @ 20003ee4 (8 bytes) ===== */

undefined mmc_disk_status(void)

{
  return *DAT_20003eec;
}


/* ===== mmc_disk_read @ 20003ef0 (144 bytes) ===== */

undefined mmc_disk_read(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined uVar3;
  
  if (param_5 == 0) {
    uVar3 = 4;
  }
  else if ((int)((uint)*DAT_20003f80 << 0x1f) < 0) {
    uVar3 = 3;
  }
  else {
    if (-1 < *DAT_20003f84 << 0x1b) {
      param_3 = param_3 << 9;
    }
    if (param_5 == 1) {
      cVar1 = send_cmd(0x11,param_3);
      if (cVar1 == '\0') {
        iVar2 = rcvr_datablock(param_1,0x200);
        if (iVar2 != 0) {
          param_5 = 0;
        }
      }
      else {
        __wrap_printf(DAT_20003f88,cVar1);
      }
    }
    else {
      iVar2 = send_cmd(0x12,param_3);
      if (iVar2 == 0) {
        do {
          iVar2 = rcvr_datablock(param_1,0x200);
          if (iVar2 == 0) break;
          param_1 = param_1 + 0x200;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
        send_cmd(0xc,0);
      }
    }
    deselect();
    uVar3 = param_5 != 0;
  }
  return uVar3;
}


/* ===== mmc_disk_write @ 20003f8c (152 bytes) ===== */

undefined mmc_disk_write(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined uVar2;
  
  if (param_5 == 0) {
    uVar2 = 4;
  }
  else if ((int)((uint)*DAT_20004024 << 0x1f) < 0) {
    uVar2 = 3;
  }
  else {
    if (-1 < (int)(*DAT_20004028 << 0x1b)) {
      param_3 = param_3 << 9;
    }
    if (param_5 == 1) {
      iVar1 = send_cmd(0x18,param_3);
      if ((iVar1 == 0) && (iVar1 = xmit_datablock(param_1,0xfe), iVar1 != 0)) {
        param_5 = 0;
      }
    }
    else {
      if ((*DAT_20004028 & 0xc) != 0) {
        send_cmd(0x97,param_5);
      }
      iVar1 = send_cmd(0x19,param_3);
      if (iVar1 == 0) {
        do {
          iVar1 = xmit_datablock(param_1,0xfc);
          if (iVar1 == 0) break;
          param_1 = param_1 + 0x200;
          param_5 = param_5 + -1;
        } while (param_5 != 0);
        iVar1 = xmit_datablock(0,0xfd);
        if (iVar1 == 0) {
          param_5 = 1;
        }
      }
    }
    deselect();
    uVar2 = param_5 != 0;
  }
  return uVar2;
}


/* ===== mmc_disk_ioctl @ 2000402c (54 bytes) ===== */

undefined4 mmc_disk_ioctl(uint param_1)

{
  undefined4 uVar1;
  
  if ((*DAT_200042dc & 1) == 0) {
    if (param_1 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x20004050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(DAT_200042e0 + param_1 * 4))();
      return uVar1;
    }
    uVar1 = 4;
    deselect();
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


/* ===== msc_inquiry_complete_cb @ 200042f0 (134 bytes) ===== */

undefined4 msc_inquiry_complete_cb(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_3 + 0xc) == '\0') {
    if ((*DAT_20004378 & 0x1f) == 0) {
      __wrap_printf(DAT_20004380,DAT_20004378 + 8,DAT_20004378 + 0x10,DAT_20004378 + 0x20);
      uVar1 = tuh_msc_get_block_count(param_1,*(undefined *)(param_2 + 0xd));
      uVar2 = tuh_msc_get_block_size(param_1,*(undefined *)(param_2 + 0xd));
      *DAT_20004384 = uVar1;
      *DAT_20004388 = uVar2;
      *DAT_2000438c = (char)param_1;
      *DAT_20004390 = *DAT_20004390 & 0xfd;
      uVar3 = __aeabi_uidiv(0x100000,uVar2);
      uVar3 = __aeabi_uidiv(uVar1,uVar3);
      __wrap_printf(DAT_20004394,uVar3);
      __wrap_printf(DAT_20004398,uVar1,uVar2);
      uVar1 = 1;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    __wrap_puts(DAT_2000437c);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== msc_read_complete_cb @ 2000439c (10 bytes) ===== */

void msc_read_complete_cb(void)

{
  multicore_fifo_push_blocking(0);
  return;
}


/* ===== msc_write_complete_cb @ 200043a6 (10 bytes) ===== */

void msc_write_complete_cb(void)

{
  multicore_fifo_push_blocking(0);
  return;
}


/* ===== tuh_msc_mount_cb @ 200043b0 (24 bytes) ===== */

void tuh_msc_mount_cb(undefined4 param_1)

{
  __wrap_puts(DAT_200043c8);
  tuh_msc_inquiry(param_1,0,DAT_200043d0,DAT_200043cc);
  return;
}


/* ===== tuh_msc_umount_cb @ 200043d4 (16 bytes) ===== */

void tuh_msc_umount_cb(void)

{
  __wrap_puts(DAT_200043e4);
  *DAT_200043e8 = 2;
  return;
}


/* ===== usb_msc_service_request @ 200043ec (198 bytes) ===== */

void usb_msc_service_request(uint param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  
  if (param_1 == 3) {
    if (*DAT_200044b4 == '\0') {
      iVar2 = tuh_msc_write10(*DAT_200044b8,0,param_2 + 0x14,*(undefined4 *)(param_2 + 8),1,
                              DAT_200044c0);
      if (iVar2 == 0) {
        multicore_fifo_push_blocking(1);
      }
    }
    else {
      multicore_fifo_push_blocking(1);
    }
  }
  else if (param_1 < 4) {
    if (param_1 == 1) {
      multicore_fifo_push_blocking(*DAT_200044b4);
    }
    else if (param_1 == 2) {
      if (*DAT_200044b4 == '\0') {
        iVar2 = tuh_msc_read10(*DAT_200044b8,0,param_2 + 0x14,*(undefined4 *)(param_2 + 8),1,
                               DAT_200044bc);
        if (iVar2 == 0) {
          multicore_fifo_push_blocking(1);
        }
      }
      else {
        multicore_fifo_push_blocking(1);
      }
    }
  }
  else if (param_1 == 4) {
    if (*DAT_200044b4 == '\0') {
      if (*(int *)(param_2 + 8) == 1) {
        *(undefined4 *)(param_2 + 0xc) = *DAT_200044c4;
        uVar1 = 0;
      }
      else {
        uVar1 = 4;
        if (*(int *)(param_2 + 8) == 3) {
          *(undefined4 *)(param_2 + 0xc) = *DAT_200044c8;
          uVar1 = 0;
        }
      }
      multicore_fifo_push_blocking(uVar1);
    }
    else {
      multicore_fifo_push_blocking(4);
    }
  }
  return;
}


/* ===== usb_disk_set_nodisk @ 200044cc (8 bytes) ===== */

void usb_disk_set_nodisk(void)

{
  *DAT_200044d4 = 2;
  return;
}


/* ===== usb_disk_initialize @ 200044d8 (24 bytes) ===== */

undefined usb_disk_initialize(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_200044f0;
  *DAT_200044f0 = 0;
  puVar1[1] = 0;
  multicore_fifo_push_blocking(1);
  uVar2 = multicore_fifo_pop_blocking();
  return uVar2;
}


/* ===== usb_disk_status @ 200044f4 (24 bytes) ===== */

undefined usb_disk_status(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  
  puVar1 = DAT_2000450c;
  *DAT_2000450c = 0;
  puVar1[1] = 0;
  multicore_fifo_push_blocking(1);
  uVar2 = multicore_fifo_pop_blocking();
  return uVar2;
}


/* ===== usb_disk_read @ 20004510 (98 bytes) ===== */

char usb_disk_read(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    puVar1 = DAT_20004574;
    if (param_5 <= uVar3) {
      return '\0';
    }
    *DAT_20004574 = 0;
    puVar1[1] = 0;
    puVar1[2] = param_3;
    puVar1[3] = 0x200;
    multicore_fifo_push_blocking(2);
    cVar2 = multicore_fifo_pop_blocking();
    if (cVar2 != '\0') break;
    memcpy(param_1,DAT_20004574 + 5,0x200);
    param_1 = param_1 + 0x200;
    param_3 = param_3 + 1;
    uVar3 = uVar3 + 1;
  }
  return cVar2;
}


/* ===== usb_disk_write @ 20004578 (92 bytes) ===== */

char usb_disk_write(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    puVar1 = DAT_200045d4;
    if (param_5 <= uVar3) {
      return '\0';
    }
    *DAT_200045d4 = 0;
    puVar1[1] = 0;
    puVar1[2] = param_3;
    puVar1[3] = 0x200;
    memcpy(puVar1 + 5,param_1);
    multicore_fifo_push_blocking(3);
    cVar2 = multicore_fifo_pop_blocking();
    if (cVar2 != '\0') break;
    param_1 = param_1 + 0x200;
    param_3 = param_3 + 1;
    uVar3 = uVar3 + 1;
  }
  return cVar2;
}


/* ===== usb_disk_ioctl @ 200045d8 (104 bytes) ===== */

uint usb_disk_ioctl(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  uint uVar3;
  
  puVar1 = DAT_20004640;
  *DAT_20004640 = 0;
  puVar1[1] = 0;
  if (param_1 == 1) {
    DAT_20004640[2] = 1;
    multicore_fifo_push_blocking(4);
    bVar2 = multicore_fifo_pop_blocking();
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      *param_2 = DAT_20004640[3];
      param_2[1] = 0;
    }
  }
  else if (param_1 == 3) {
    DAT_20004640[2] = 3;
    multicore_fifo_push_blocking(4);
    bVar2 = multicore_fifo_pop_blocking();
    uVar3 = (uint)bVar2;
    if (uVar3 == 0) {
      *param_2 = DAT_20004640[3];
    }
  }
  else if (param_1 == 0) {
    uVar3 = usb_disk_status();
    if (uVar3 != 0) {
      uVar3 = 4;
    }
  }
  else {
    uVar3 = 4;
  }
  return uVar3;
}


/* ===== flash_cs_force @ 20004644 (18 bytes) ===== */

void flash_cs_force(int param_1)

{
  *DAT_20004658 = *DAT_20004658 & DAT_2000465c | param_1 << 8;
  return;
}


/* ===== connect_internal_flash @ 20004660 (34 bytes) ===== */

void connect_internal_flash(void)

{
  int iVar1;
  
  reset_unreset_block_wait_noinline(0x240);
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    *(undefined4 *)(iVar1 * 8 + DAT_20004684) = 0;
  }
  return;
}


/* ===== flash_init_spi @ 20004688 (30 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_init_spi(void)

{
  _DAT_18000014 = 6;
  _DAT_18000000 = 0x70000;
  _DAT_18000010 = 1;
  _DAT_18000008 = 1;
  return;
}


/* ===== flash_was_aborted @ 200046a8 (12 bytes) ===== */

uint flash_was_aborted(void)

{
  return *DAT_200046b4 & 0x30000;
}


/* ===== flash_put_get @ 200046b8 (148 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_put_get(byte *param_1,undefined *param_2,uint param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = param_3;
  do {
    if ((param_4 | param_3 | uVar3) == 0) break;
    if (param_3 == 0) {
      bVar2 = false;
    }
    else if ((uint)(_DAT_18000020 + _DAT_18000024) < 0xe) {
      if (param_1 == (byte *)0x0) {
        _DAT_18000060 = 0;
      }
      else {
        _DAT_18000060 = (uint)*param_1;
        param_1 = param_1 + 1;
      }
      param_3 = param_3 - 1;
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (_DAT_18000024 != 0) {
      if (param_4 == 0) {
        if (param_2 != (undefined *)0x0) {
          *param_2 = (char)_DAT_18000060;
          param_2 = param_2 + 1;
        }
        uVar3 = uVar3 - 1;
        bVar2 = true;
      }
      else {
        param_4 = param_4 - 1;
        bVar2 = true;
      }
    }
  } while ((bVar2) || (iVar1 = flash_was_aborted(), iVar1 == 0));
  flash_cs_force(3);
  return;
}


/* ===== flash_do_cmd @ 2000474c (36 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_do_cmd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = param_4;
  flash_cs_force(2);
  _DAT_18000060 = param_1;
  flash_put_get(param_2,param_3,param_4,1,uVar1);
  return;
}


/* ===== flash_enable_write @ 20004770 (16 bytes) ===== */

void flash_enable_write(void)

{
  flash_do_cmd(6,0,0,0);
  return;
}


/* ===== flash_exit_xip @ 20004780 (136 bytes) ===== */

void flash_exit_xip(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined local_14;
  undefined local_13;
  
  local_14 = 0xff;
  local_13 = 0xff;
  flash_init_spi();
  uVar4 = *DAT_20004808;
  uVar3 = uVar4 & 0xffffff73 | 0x84;
  flash_cs_force(3);
  for (iVar5 = 0; puVar1 = DAT_20004808, iVar5 < 2; iVar5 = iVar5 + 1) {
    *DAT_20004808 = uVar3;
    puVar1[1] = uVar3;
    puVar1[2] = uVar3;
    puVar1[3] = uVar3;
    iVar2 = 0x800;
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    flash_put_get(0,0,4,0);
    uVar3 = uVar3 & 0xfffffff3 | 8;
    flash_cs_force(2);
  }
  *DAT_20004808 = uVar4;
  puVar1[1] = uVar4;
  uVar3 = uVar4 & 0xfffffff3 | 8;
  puVar1[2] = uVar3;
  puVar1[3] = uVar3;
  flash_cs_force(2);
  flash_put_get(&local_14,0,2,0);
  *DAT_2000480c = 0;
  return;
}


/* ===== flash_page_program @ 20004810 (134 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_page_program(uint param_1,undefined4 param_2)

{
  int iVar1;
  byte local_11;
  
  if (0xffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200048a0,0x10d,DAT_2000489c,DAT_20004898);
  }
  if ((param_1 & 0xff) == 0) {
    flash_enable_write();
    flash_cs_force(2);
    param_1 = param_1 | 0x2000000;
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      _DAT_18000060 = param_1 >> 0x18;
      param_1 = param_1 << 8;
    }
    flash_put_get(param_2,0,0x100,4);
    do {
      flash_do_cmd(5,0,&local_11,1);
      if (-1 < (int)((uint)local_11 << 0x1f)) {
        return;
      }
      iVar1 = flash_was_aborted();
    } while (iVar1 == 0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200048a0,0x10e,DAT_2000489c,DAT_200048a4);
}


/* ===== flash_range_program @ 200048a8 (60 bytes) ===== */

void flash_range_program(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 & 0xff) == 0) {
    uVar2 = param_1 + param_3;
    while ((param_1 < uVar2 && (iVar1 = flash_was_aborted(), iVar1 == 0))) {
      flash_page_program(param_1,param_2);
      param_1 = param_1 + 0x100;
      param_2 = param_2 + 0x100;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200048ec,0x118,DAT_200048e8,DAT_200048e4);
}


/* ===== flash_user_erase @ 200048f0 (110 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_user_erase(uint param_1,int param_2)

{
  int iVar1;
  byte local_11 [5];
  
  if (0xffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20004968,0x13c,DAT_20004964,DAT_20004960);
  }
  flash_enable_write();
  flash_cs_force(2);
  param_1 = param_2 << 0x18 | param_1;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    _DAT_18000060 = param_1 >> 0x18;
    param_1 = param_1 << 8;
  }
  flash_put_get(0,0,0,4);
  do {
    flash_do_cmd(5,0,local_11,1);
    if (-1 < (int)((uint)local_11[0] << 0x1f)) {
      return;
    }
    iVar1 = flash_was_aborted();
  } while (iVar1 == 0);
  return;
}


/* ===== flash_sector_erase @ 2000496c (10 bytes) ===== */

void flash_sector_erase(undefined4 param_1)

{
  flash_user_erase(param_1,0x20);
  return;
}


/* ===== flash_read_data @ 20004978 (76 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flash_read_data(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 < 0x1000000) {
    flash_cs_force(2);
    param_1 = param_1 | 0x3000000;
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      _DAT_18000060 = param_1 >> 0x18;
      param_1 = param_1 << 8;
    }
    flash_put_get(0,param_2,param_3,4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200049cc,0x15f,DAT_200049c8,DAT_200049c4,param_4);
}


/* ===== reset_unreset_block_wait_noinline @ 200049d6 (18 bytes) ===== */

void reset_unreset_block_wait_noinline(uint param_1)

{
  int iVar1;
  
  *DAT_200049e8 = param_1;
  iVar1 = DAT_200049ec;
  *DAT_200049f0 = param_1;
  do {
    param_1 = param_1 & ~*(uint *)(iVar1 + 8);
  } while (param_1 != 0);
  return;
}


/* ===== gpio_set_function @ 200049f4 (40 bytes) ===== */

void gpio_set_function(int param_1,undefined4 param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_20004a1c);
  *(uint *)((uint)puVar1 | 0x1000) = (*puVar1 ^ 0x40) & 0xc0;
  *(undefined4 *)(param_1 * 8 + DAT_20004a20 + 4) = param_2;
  return;
}


/* ===== gpio_set_pulls @ 20004a24 (48 bytes) ===== */

void gpio_set_pulls(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_20004a54);
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 8;
  }
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  *(uint *)((uint)puVar1 | 0x1000) = ((uVar3 | uVar2) ^ *puVar1) & 0xc;
  return;
}


/* ===== gpio_set_drive_strength @ 20004a58 (28 bytes) ===== */

void gpio_set_drive_strength(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 4 + DAT_20004a74);
  *(uint *)((uint)puVar1 | 0x1000) = (param_2 << 4 ^ *puVar1) & 0x30;
  return;
}


/* ===== gpio_init @ 20004a78 (22 bytes) ===== */

void gpio_init(uint param_1)

{
  DAT_d0000018 = 1 << (param_1 & 0xff);
  DAT_d0000028 = DAT_d0000018;
  gpio_set_function(param_1,5);
  return;
}


/* ===== hw_claim_lock @ 20004a90 (20 bytes) ===== */

undefined4 hw_claim_lock(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_20004aa4 == 0);
  DataMemoryBarrier(0x1f);
  return uVar2;
}


/* ===== hw_claim_unlock @ 20004aa8 (16 bytes) ===== */

void hw_claim_unlock(uint param_1)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1f);
  *DAT_20004ab8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_1 & 1) == 1);
  }
  return;
}


/* ===== hw_claim_or_assert @ 20004abc (50 bytes) ===== */

void hw_claim_or_assert(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  
  hw_claim_lock();
  bVar1 = *(byte *)(param_1 + (param_2 >> 3));
  uVar2 = 1 << (param_2 & 7);
  if ((uVar2 & bVar1) == 0) {
    *(byte *)(param_1 + (param_2 >> 3)) = (byte)uVar2 | bVar1;
    hw_claim_unlock();
    return;
  }
                    /* WARNING: Subroutine does not return */
  panic(param_3,param_2,param_2 & 7,uVar2,param_4);
}


/* ===== hw_claim_unused_from_range @ 20004aee (80 bytes) ===== */

uint hw_claim_unused_from_range
               (int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5)

{
  byte bVar1;
  uint uVar2;
  
  hw_claim_lock();
  do {
    if (param_4 < param_3) {
      param_3 = 0xffffffff;
LAB_20004b24:
      hw_claim_unlock();
      if (((int)param_3 < 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
        panic(param_5);
      }
      return param_3;
    }
    bVar1 = *(byte *)(param_1 + (param_3 >> 3));
    uVar2 = 1 << (param_3 & 7);
    if ((uVar2 & bVar1) == 0) {
      *(byte *)(param_1 + (param_3 >> 3)) = (byte)uVar2 | bVar1;
      goto LAB_20004b24;
    }
    param_3 = param_3 + 1;
  } while( true );
}


/* ===== running_on_fpga @ 20004b40 (16 bytes) ===== */

bool running_on_fpga(void)

{
  return (*DAT_20004b50 & 2) != 0;
}


/* ===== spin_locks_reset @ 20004b54 (26 bytes) ===== */

void spin_locks_reset(void)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 0x20; uVar1 = uVar1 + 1) {
    DataMemoryBarrier(0x1f);
    *(undefined4 *)((uVar1 + DAT_20004b70) * 4) = 0;
  }
  return;
}


/* ===== next_striped_spin_lock_num @ 20004b74 (22 bytes) ===== */

void next_striped_spin_lock_num(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_20004b8c;
  bVar1 = *DAT_20004b8c;
  *DAT_20004b8c = bVar1 + 1;
  if (0x17 < (byte)(bVar1 + 1)) {
    *pbVar2 = 0x10;
  }
  return;
}


/* ===== spin_lock_claim_unused @ 20004b90 (24 bytes) ===== */

void spin_lock_claim_unused(undefined4 param_1)

{
  hw_claim_unused_from_range(DAT_20004bac,param_1,0x18,0x1f,DAT_20004ba8);
  return;
}


/* ===== uart_set_baudrate @ 20004bb0 (84 bytes) ===== */

void uart_set_baudrate(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = clock_get_hz(6);
  uVar2 = __aeabi_uidiv(iVar1 << 3,param_2);
  uVar3 = uVar2 >> 7;
  if (uVar3 == 0) {
    uVar3 = 1;
    uVar2 = 0;
  }
  else if (DAT_20004c04 < uVar3) {
    uVar2 = 0;
    uVar3 = DAT_20004c08;
  }
  else {
    uVar2 = (uVar2 & 0x7f) + 1 >> 1;
  }
  *(uint *)(param_1 + 0x24) = uVar3;
  *(uint *)(param_1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x2cU | 0x2000) = 0;
  iVar1 = clock_get_hz(6);
  __aeabi_uidiv(iVar1 << 2,uVar3 * 0x40 + uVar2);
  return;
}


/* ===== uart_set_translate_crlf @ 20004c0c (30 bytes) ===== */

void uart_set_translate_crlf(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = 10;
  }
  *(undefined2 *)((uint)(param_1 + DAT_20004c2c == 0) * 2 + DAT_20004c30) = uVar1;
  return;
}


/* ===== uart_init @ 20004c34 (108 bytes) ===== */

void uart_init(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = clock_get_hz(6);
  if (iVar1 != 0) {
    if (param_1 == DAT_20004ca0) {
      uVar2 = 0x800000;
    }
    else {
      uVar2 = 0x400000;
    }
    *DAT_20004ca4 = uVar2;
    *DAT_20004ca8 = uVar2;
    do {
    } while ((uVar2 & ~*(uint *)(DAT_20004cac + 8)) != 0);
    uart_set_translate_crlf(param_1,0);
    uart_set_baudrate(param_1,param_2);
    *(uint *)(param_1 + 0x2cU | 0x1000) = (*(uint *)(param_1 + 0x2c) ^ 0x60) & 0x6e;
    *(undefined4 *)(param_1 + 0x30) = DAT_20004cb0;
    *(undefined4 *)(param_1 + 0x2cU | 0x2000) = 0x10;
    *(undefined4 *)(param_1 + 0x48) = 3;
  }
  return;
}


/* ===== repeating_timer_callback @ 20004cb4 (50 bytes) ===== */

undefined8 repeating_timer_callback(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2[3] == param_1) {
    iVar1 = (*(code *)param_2[4])(param_2);
    if (iVar1 == 0) {
      param_2[3] = 0;
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = *param_2;
      uVar3 = param_2[1];
    }
    return CONCAT44(uVar3,uVar2);
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20004cf0,300,DAT_20004cec,DAT_20004ce8);
}


/* ===== alarm_pool_post_alloc_init @ 20004cf4 (50 bytes) ===== */

void alarm_pool_post_alloc_init(int param_1,int param_2)

{
  int iVar1;
  
  hardware_alarm_claim(param_2);
  hardware_alarm_cancel(param_2);
  hardware_alarm_set_callback(param_2,DAT_20004d28);
  iVar1 = next_striped_spin_lock_num();
  *(int *)(param_1 + 4) = (iVar1 + DAT_20004d2c) * 4;
  *(char *)(param_1 + 0x14) = (char)param_2;
  *(int *)(param_2 * 4 + DAT_20004d30) = param_1;
  return;
}


/* ===== sleep_until_callback @ 20004d34 (44 bytes) ===== */

undefined8 sleep_until_callback(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**DAT_20004d60 == 0);
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  **DAT_20004d60 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return 0;
}


/* ===== timer_pool_entry_comparator @ 20004d64 (106 bytes) ===== */

undefined timer_pool_entry_comparator(int *param_1,uint param_2,uint param_3)

{
  undefined uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if ((param_2 == 0) || (*(byte *)(*param_1 + 0xc) < param_2)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20004ddc,0x3b,DAT_20004dd8,DAT_20004dd4);
  }
  puVar2 = (uint *)((param_2 + DAT_20004dd0) * 0x10 + param_1[2]);
  uVar3 = puVar2[1];
  if ((param_3 != 0) && (param_3 <= *(byte *)(*param_1 + 0xc))) {
    puVar4 = (uint *)(param_1[2] + (param_3 + DAT_20004dd0) * 0x10);
    uVar5 = puVar4[1];
    uVar1 = 1;
    if ((uVar5 <= uVar3) && ((uVar5 != uVar3 || (*puVar4 <= *puVar2)))) {
      uVar1 = 0;
    }
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20004ddc,0x3b,DAT_20004dd8,DAT_20004dd4);
}


/* ===== ph_add_child_node @ 20004de0 (134 bytes) ===== */

void ph_add_child_node(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20004e70,0x69,DAT_20004e6c,DAT_20004e68);
  }
  pcVar2 = (char *)(param_2 * 3 + -3 + *param_1);
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20004e70,0x70,DAT_20004e78,DAT_20004e74);
  }
  if (param_3 != 0) {
    if (param_2 == param_3) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20004e70,0x72,DAT_20004e78,DAT_20004e80);
    }
    if ((param_3 != 0) && (param_3 <= *(byte *)(param_1 + 3))) {
      iVar1 = *param_1 + param_3 * 3 + -3;
      *(char *)(iVar1 + 2) = (char)param_2;
      if (*pcVar2 == '\0') {
        *pcVar2 = (char)param_3;
      }
      else {
        *(char *)(iVar1 + 1) = *pcVar2;
        *pcVar2 = (char)param_3;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20004e70,0x69,DAT_20004e6c,DAT_20004e68);
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20004e70,0x71,DAT_20004e78,DAT_20004e7c);
}


/* ===== ph_merge_nodes @ 20004e84 (62 bytes) ===== */

int ph_merge_nodes(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3;
  if ((param_2 != 0) && (iVar2 = param_2, param_3 != 0)) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      ph_add_child_node(param_1,param_3,param_2);
      iVar2 = param_3;
    }
    else {
      ph_add_child_node(param_1,param_2,param_3);
    }
  }
  return iVar2;
}


/* ===== add_alarm_under_lock @ 20004ec4 (328 bytes) ===== */

uint add_alarm_under_lock
               (int **param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
               byte param_7,char param_8,undefined *param_9)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar5 = (uint)param_7;
  if (uVar5 == 0) {
    piVar3 = *param_1;
    uVar5 = (uint)*(byte *)((int)piVar3 + 0xe);
    if (uVar5 != 0) {
      if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005014,0x69,DAT_20005010,DAT_2000500c);
      }
      puVar4 = (undefined *)(uVar5 * 3 + -3 + *piVar3);
      cVar2 = puVar4[1];
      *(char *)((int)piVar3 + 0xe) = cVar2;
      if (cVar2 == '\0') {
        *(undefined *)((int)piVar3 + 0xf) = 0;
      }
      puVar4[2] = 0;
      puVar4[1] = 0;
      *puVar4 = 0;
    }
  }
  else {
    piVar3 = *param_1;
    if (uVar5 == *(byte *)((int)piVar3 + 0xd)) {
      cVar2 = '\x01';
    }
    else {
      if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005014,0x69,DAT_20005010,DAT_2000500c);
      }
      cVar2 = *(char *)(*piVar3 + uVar5 * 3 + -1);
      if (cVar2 != '\0') {
        cVar2 = '\x01';
      }
    }
    if (cVar2 != '\0') {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005020,0x65,DAT_2000501c,DAT_20005018);
    }
  }
  if (uVar5 != 0) {
    if ((uVar5 == 0) || (*(byte *)(*param_1 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005020,0x3b,DAT_2000502c,DAT_20005028);
    }
    piVar3 = param_1[2] + (uVar5 + DAT_20005024) * 4;
    *piVar3 = param_3;
    piVar3[1] = param_4;
    piVar3[2] = param_5;
    piVar3[3] = param_6;
    piVar3 = *param_1;
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005014,0xa6,DAT_20005034,DAT_20005030);
    }
    if ((uVar5 == 0) || (*(byte *)(piVar3 + 3) < uVar5)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005014,0x69,DAT_20005010,DAT_2000500c);
    }
    puVar4 = (undefined *)(uVar5 * 3 + -3 + *piVar3);
    puVar4[2] = 0;
    puVar4[1] = 0;
    *puVar4 = 0;
    uVar6 = ph_merge_nodes(piVar3,*(undefined *)((int)piVar3 + 0xd),uVar5);
    *(char *)((int)piVar3 + 0xd) = (char)uVar6;
    if (uVar5 == (uint)uVar6) {
      iVar1 = hardware_alarm_set_target
                        (*(undefined *)(param_1 + 5),(int)((ulonglong)uVar6 >> 0x20),param_3,param_4
                        );
      if ((iVar1 != 0) && (param_8 == '\0')) {
        ph_remove_and_free_node(*param_1,uVar5);
      }
      if (param_9 != (undefined *)0x0) {
        *param_9 = (char)iVar1;
      }
    }
  }
  return uVar5;
}


/* ===== alarm_pool_alarm_callback @ 20005038 (736 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x20005236) */
/* WARNING: Removing unreachable block (ram,0x200051ae) */

void alarm_pool_alarm_callback(int param_1)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int **ppiVar9;
  uint uVar10;
  bool bVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_30 = 0;
  ppiVar9 = *(int ***)(param_1 * 4 + DAT_20005318);
  do {
    while( true ) {
      lVar12 = time_us_64();
      if (lVar12 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005324,0x3f,DAT_20005320,DAT_2000531c);
      }
      local_38 = 0;
      local_34 = 0;
      uVar10 = 0;
      bVar11 = (bool)isCurrentModePrivileged();
      if (bVar11) {
        uVar10 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      do {
      } while (*ppiVar9[1] == 0);
      DataMemoryBarrier(0x1f);
      piVar3 = *ppiVar9;
      bVar1 = *(byte *)((int)piVar3 + 0xd);
      uVar7 = (uint)bVar1;
      if (uVar7 == 0) {
        uVar6 = 0;
        pcVar5 = (code *)0x0;
        iVar4 = 0;
      }
      else {
        if ((uVar7 == 0) || (*(byte *)(piVar3 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_20005330,0x3b,DAT_2000532c,DAT_20005328);
        }
        puVar8 = (uint *)(ppiVar9[2] + (uVar7 + DAT_20005344) * 4);
        iVar4 = (puVar8[1] - (int)((ulonglong)lVar12 >> 0x20)) - (uint)(*puVar8 < (uint)lVar12);
        if ((iVar4 < 1) && ((iVar4 != 0 || (*puVar8 == (uint)lVar12)))) {
          uVar2 = ph_remove_head(piVar3,0);
          if (uVar2 != uVar7) {
                    /* WARNING: Subroutine does not return */
            __assert_func(DAT_20005330,0x8c,DAT_20005338,DAT_20005334);
          }
          local_38 = *puVar8;
          local_34 = puVar8[1];
          pcVar5 = (code *)puVar8[2];
          uVar6 = puVar8[3];
          if (pcVar5 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
            __assert_func(DAT_20005330,0x90,DAT_20005338,DAT_2000533c);
          }
          if ((uVar7 == 0) || (*(byte *)(*ppiVar9 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
            __assert_func(DAT_20005330,0x40,DAT_20005340,DAT_20005328);
          }
          local_30 = (uint)*(byte *)((int)ppiVar9[3] + (uVar7 - 1));
          ppiVar9[4] = (int *)(uVar2 | local_30 << 8);
          iVar4 = 0;
        }
        else {
          iVar4 = hardware_alarm_set_target(param_1,iVar4,*puVar8,puVar8[1]);
          uVar6 = 0;
          pcVar5 = (code *)0x0;
        }
      }
      DataMemoryBarrier(0x1f);
      *ppiVar9[1] = 0;
      bVar11 = (bool)isCurrentModePrivileged();
      if (bVar11) {
        enableIRQinterrupts((uVar10 & 1) == 1);
      }
      if (pcVar5 != (code *)0x0) break;
      if (iVar4 == 0) {
        return;
      }
    }
    piVar3 = (int *)(local_30 << 8 | uVar7);
    lVar12 = (*pcVar5)(piVar3,uVar6);
    uVar10 = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      uVar10 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
      bVar11 = *ppiVar9[1] == 0;
    } while (bVar11);
    DataMemoryBarrier(0x1f);
    if ((lVar12 < 0) && (ppiVar9[4] != (int *)0x0)) {
      if (ppiVar9[4] != piVar3) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005330,0x9f,DAT_20005338,DAT_20005348);
      }
      uVar7 = (local_34 - (int)((ulonglong)lVar12 >> 0x20)) - (uint)(local_38 < (uint)lVar12);
      if ((uVar7 < local_34) || ((local_34 == uVar7 && (local_38 - (uint)lVar12 < local_38)))) {
        uVar7 = 0xffffffff;
      }
      if ((int)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005324,0x3f,DAT_20005320,DAT_2000531c);
      }
      add_alarm_under_lock(ppiVar9);
    }
    else if ((lVar12 < 1) || (ppiVar9[4] == (int *)0x0)) {
      piVar3 = *ppiVar9;
      if (uVar7 == 0) {
LAB_200052cc:
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005354,0xf7,DAT_2000535c,DAT_20005358);
      }
      if (uVar7 == *(byte *)((int)piVar3 + 0xd)) {
        bVar11 = true;
      }
      else {
        if ((uVar7 == 0) || (*(byte *)(piVar3 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_20005354,0x69,DAT_20005350,DAT_2000534c);
        }
        if (*(char *)(uVar7 * 3 + *piVar3 + -1) != '\0') {
          bVar11 = true;
        }
      }
      if (bVar11) goto LAB_200052cc;
      uVar6 = (uint)*(byte *)((int)piVar3 + 0xf);
      if (uVar6 != 0) {
        if ((uVar6 == 0) || (*(byte *)(piVar3 + 3) < uVar6)) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_20005354,0x69,DAT_20005350,DAT_2000534c);
        }
        *(byte *)(uVar6 * 3 + *piVar3 + -2) = bVar1;
      }
      *(byte *)((int)piVar3 + 0xf) = bVar1;
      if ((uVar7 == 0) || (*(byte *)(*ppiVar9 + 3) < uVar7)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005330,0x40,DAT_20005340,DAT_20005328);
      }
      *(char *)((int)ppiVar9[3] + (uVar7 - 1)) = *(char *)((int)ppiVar9[3] + (uVar7 - 1)) + '\x01';
    }
    else {
      if (ppiVar9[4] != piVar3) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005330,0xa2,DAT_20005338,DAT_20005348);
      }
      uVar13 = time_us_64();
      if ((longlong)uVar13 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005324,0x3f,DAT_20005320,DAT_2000531c);
      }
      iVar4 = (int)(lVar12 + uVar13 >> 0x20);
      if (lVar12 + uVar13 < uVar13) {
        iVar4 = -1;
      }
      if (iVar4 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005324,0x3f,DAT_20005320,DAT_2000531c);
      }
      add_alarm_under_lock(ppiVar9);
    }
    ppiVar9[4] = (int *)0x0;
    DataMemoryBarrier(0x1f);
    *ppiVar9[1] = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      enableIRQinterrupts((uVar10 & 1) == 1);
    }
  } while( true );
}


/* ===== alarm_pool_init_default @ 20005360 (44 bytes) ===== */

void alarm_pool_init_default(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_2000538c;
  if (DAT_2000538c[1] == 0) {
    ph_post_alloc_init(*DAT_2000538c,0x10,DAT_20005394,DAT_2000538c);
    alarm_pool_post_alloc_init(puVar1,3);
  }
  lock_init(DAT_20005390,10);
  return;
}


/* ===== alarm_pool_get_default @ 20005398 (26 bytes) ===== */

int alarm_pool_get_default(void)

{
  if (*(int *)(DAT_200053b4 + 4) != 0) {
    return DAT_200053b4;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200053c0,0x5c,DAT_200053bc,DAT_200053b8);
}


/* ===== alarm_pool_add_alarm_at @ 200053c4 (344 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x200054d4) */
/* WARNING: Removing unreachable block (ram,0x2000544c) */

uint alarm_pool_add_alarm_at
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,code *param_5,
               undefined4 param_6,char param_7)

{
  bool bVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  char local_29 [5];
  
  uVar2 = CONCAT44(param_4,param_3);
  local_29[0] = '\0';
  while( true ) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (*(int *)param_1[1] == 0);
    DataMemoryBarrier(0x1f);
    uVar3 = add_alarm_under_lock
                      (param_1,0,(int)uVar2,(int)(uVar2 >> 0x20),param_5,param_6,0,0,local_29);
    if (uVar3 == 0) {
      uVar4 = 0;
    }
    else {
      if ((uVar3 == 0) || (*(byte *)(*param_1 + 0xc) < uVar3)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005524,0x40,DAT_20005520,DAT_2000551c);
      }
      uVar4 = (uint)*(byte *)(param_1[3] + (uVar3 - 1));
    }
    DataMemoryBarrier(0x1f);
    *(undefined4 *)param_1[1] = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    if (uVar3 == 0) break;
    if (local_29[0] == '\0') {
      return uVar3 | uVar4 << 8;
    }
    if (param_7 == '\0') {
      return 0;
    }
    lVar6 = (*param_5)(0,param_6);
    if (lVar6 == 0) {
      return 0;
    }
    if (lVar6 < 0) {
      bVar1 = uVar2 - lVar6 < uVar2;
      uVar2 = uVar2 - lVar6;
      if (bVar1) {
        uVar2 = 0xffffffffffffffff;
      }
      if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005530,0x3f,DAT_2000552c,DAT_20005528);
      }
    }
    else {
      uVar7 = time_us_64();
      if ((longlong)uVar7 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005530,0x3f,DAT_2000552c,DAT_20005528);
      }
      uVar2 = lVar6 + uVar7;
      if (uVar2 < uVar7) {
        uVar2 = 0xffffffffffffffff;
      }
      if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005530,0x3f,DAT_2000552c,DAT_20005528);
      }
    }
  }
  return 0xffffffff;
}


/* ===== alarm_pool_cancel_alarm @ 20005534 (202 bytes) ===== */

int alarm_pool_cancel_alarm(int **param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*param_1[1] == 0);
  DataMemoryBarrier(0x1f);
  uVar4 = (uint)param_2 & 0xff;
  piVar3 = *param_1;
  if (uVar4 == *(byte *)((int)piVar3 + 0xd)) {
    bVar1 = true;
  }
  else {
    if ((uVar4 == 0) || (*(byte *)(piVar3 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005608,0x69,DAT_20005604,DAT_20005600,param_4);
    }
    bVar1 = false;
    if (*(char *)(uVar4 * 3 + *piVar3 + -1) != '\0') {
      bVar1 = true;
    }
  }
  if (bVar1) {
    if (param_1[4] == param_2) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005614,0x10a,DAT_20005610,DAT_2000560c,param_4);
    }
    if ((uVar4 == 0) || (*(byte *)(*param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005614,0x40,DAT_2000561c,DAT_20005618,param_4);
    }
    if ((uint)*(byte *)((int)param_1[3] + (uVar4 - 1)) == ((uint)param_2 >> 8 & 0xff)) {
      iVar2 = ph_remove_and_free_node(piVar3,uVar4);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005614,0x111,DAT_20005610,DAT_20005620,param_4);
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
    if (param_1[4] == param_2) {
      param_1[4] = (int *)0x0;
    }
  }
  DataMemoryBarrier(0x1f);
  *param_1[1] = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return iVar2;
}


/* ===== alarm_pool_add_repeating_timer_us @ 20005624 (140 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x20005670) */

uint alarm_pool_add_repeating_timer_us
               (uint param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               uint *param_7)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  
  if ((param_3 | param_4) == 0) {
    param_3 = 1;
    param_4 = 0;
  }
  param_7[2] = param_1;
  param_7[4] = param_5;
  *param_7 = param_3;
  param_7[1] = param_4;
  param_7[5] = param_6;
  uVar2 = (int)param_4 >> 0x1f;
  uVar4 = time_us_64();
  if ((longlong)uVar4 < 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200056bc,0x3f,DAT_200056b8,DAT_200056b4);
  }
  uVar1 = uVar4 + CONCAT44(((param_4 ^ uVar2) - uVar2) - (uint)((param_3 ^ uVar2) < uVar2),
                           (param_3 ^ uVar2) - uVar2);
  iVar3 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar4) {
    iVar3 = -1;
  }
  if (-1 < iVar3) {
    uVar2 = alarm_pool_add_alarm_at(param_1);
    param_7[3] = uVar2;
    return ~uVar2 >> 0x1f;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200056bc,0x3f,DAT_200056b8,DAT_200056b4);
}


/* ===== sleep_until @ 200056c0 (222 bytes) ===== */

void sleep_until(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  
  iVar3 = ____get_current_exception_veneer();
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    panic(DAT_200057a0);
  }
  uVar5 = param_1 - 6;
  uVar6 = (param_2 - 1) + (uint)(5 < param_1);
  if ((param_2 < uVar6) || ((uVar6 == param_2 && (param_1 < uVar5)))) {
    uVar5 = 0;
    uVar6 = 0;
  }
  if ((int)uVar6 < 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200057ac,0x3f,DAT_200057a8,DAT_200057a4);
  }
  lVar7 = time_us_64();
  if (lVar7 < 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200057ac,0x3f,DAT_200057a8,DAT_200057a4);
  }
  uVar4 = uVar6 - (int)((ulonglong)lVar7 >> 0x20);
  uVar2 = (uint)(uVar5 < (uint)lVar7);
  if ((0 < (int)(uVar4 - uVar2)) || ((uVar4 == uVar2 && (uVar5 != (uint)lVar7)))) {
    uVar8 = alarm_pool_get_default();
    iVar3 = alarm_pool_add_alarm_at
                      ((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar5,uVar6,DAT_200057b0,0,0);
    if (-1 < iVar3) {
      while( true ) {
        if (*(uint *)(DAT_200057b8 + 0x24) < uVar6) {
          bVar1 = false;
        }
        else if (*(uint *)(DAT_200057b8 + 0x28) < uVar5) {
          if (uVar6 == *(uint *)(DAT_200057b8 + 0x24)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
        }
        else {
          bVar1 = true;
        }
        if (bVar1) break;
        uVar4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar4 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        do {
        } while (**DAT_200057b4 == 0);
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        **DAT_200057b4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar4 & 1) == 1);
        }
        WaitForEvent();
      }
    }
  }
  busy_wait_until(param_1,param_2);
  return;
}


/* ===== sleep_us @ 200057bc (74 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x200057da) */

void sleep_us(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = time_us_64();
  if ((longlong)uVar3 < 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005810,0x3f,DAT_2000580c,DAT_20005808,param_4);
  }
  uVar1 = uVar3 + CONCAT44(param_2,param_1);
  iVar2 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar3) {
    iVar2 = -1;
  }
  if (-1 < iVar2) {
    sleep_until();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20005810,0x3f,DAT_2000580c,DAT_20005808,param_4);
}


/* ===== sleep_ms @ 20005814 (20 bytes) ===== */

void sleep_ms(undefined4 param_1)

{
  __wrap___aeabi_lmul(param_1,0,1000,0);
  sleep_us();
  return;
}


/* ===== best_effort_wfe_or_timeout @ 20005828 (120 bytes) ===== */

undefined4 best_effort_wfe_or_timeout(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = alarm_pool_get_default();
  iVar1 = alarm_pool_add_alarm_at
                    ((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1,param_2,DAT_200058a0,0,0);
  if (iVar1 < 1) {
    if (*(uint *)(DAT_200058a4 + 0x24) < param_2) {
      uVar2 = 0;
    }
    else if (*(uint *)(DAT_200058a4 + 0x28) < param_1) {
      if (param_2 == *(uint *)(DAT_200058a4 + 0x24)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    WaitForEvent();
    uVar2 = alarm_pool_get_default();
    alarm_pool_cancel_alarm(uVar2,iVar1);
    if (*(uint *)(DAT_200058a4 + 0x24) < param_2) {
      uVar2 = 0;
    }
    else if (*(uint *)(DAT_200058a4 + 0x28) < param_1) {
      if (param_2 == *(uint *)(DAT_200058a4 + 0x24)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* ===== hardware_alarm_irq_handler @ 200058a8 (118 bytes) ===== */

void hardware_alarm_irq_handler(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  uVar2 = uVar4 - 0x10;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_20005920 == 0);
  DataMemoryBarrier(0x1f);
  iVar3 = 1 << (uVar2 & 0xff);
  *(int *)(DAT_20005924 + 0x34) = iVar3;
  if ((*DAT_20005928 >> (uVar2 & 0xff) & 1) == 0) {
    pcVar5 = (code *)0x0;
  }
  else if (*(uint *)(DAT_20005924 + 0x24) < *(uint *)(uVar2 * 4 + DAT_2000592c)) {
    iVar3 = (uVar4 - 0xc) * 4;
    *(undefined4 *)(iVar3 + DAT_20005924) = *(undefined4 *)(iVar3 + DAT_20005924);
    pcVar5 = (code *)0x0;
  }
  else {
    pcVar5 = *(code **)(uVar2 * 4 + DAT_20005930);
    *DAT_20005928 = *DAT_20005928 & ~(byte)iVar3;
  }
  DataMemoryBarrier(0x1f);
  *DAT_20005920 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)();
  }
  return;
}


/* ===== hardware_alarm_claim @ 20005934 (14 bytes) ===== */

void hardware_alarm_claim(undefined4 param_1)

{
  hw_claim_or_assert(DAT_20005948,param_1,DAT_20005944);
  return;
}


/* ===== time_us_64 @ 2000594c (18 bytes) ===== */

undefined4 time_us_64(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(DAT_20005960 + 0x24);
  do {
    bVar2 = iVar1 != *(int *)(DAT_20005960 + 0x24);
    iVar1 = *(int *)(DAT_20005960 + 0x24);
  } while (bVar2);
  return *(undefined4 *)(DAT_20005960 + 0x28);
}


/* ===== busy_wait_until @ 20005964 (34 bytes) ===== */

void busy_wait_until(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_20005988 + 0x24);
  while (uVar1 < param_2) {
    uVar1 = *(uint *)(DAT_20005988 + 0x24);
  }
  while ((uVar1 == param_2 && (*(uint *)(DAT_20005988 + 0x28) < param_1))) {
    uVar1 = *(uint *)(DAT_20005988 + 0x24);
  }
  return;
}


/* ===== busy_wait_us @ 2000598c (60 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x200059a8) */

void busy_wait_us(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = time_us_64();
  uVar1 = uVar3 + CONCAT44(param_2,param_1);
  iVar2 = (int)(uVar1 >> 0x20);
  if (uVar1 < uVar3) {
    iVar2 = -1;
  }
  if (-1 < iVar2) {
    busy_wait_until();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200059d0,0x3f,DAT_200059cc,DAT_200059c8);
}


/* ===== busy_wait_us_32 @ 200059d4 (30 bytes) ===== */

void busy_wait_us_32(uint param_1)

{
  if ((int)param_1 < 0) {
    busy_wait_us(param_1,0);
  }
  else {
    do {
    } while ((uint)(*(int *)(DAT_200059f4 + 0x28) - *(int *)(DAT_200059f4 + 0x28)) < param_1);
  }
  return;
}


/* ===== hardware_alarm_set_callback @ 200059f8 (124 bytes) ===== */

void hardware_alarm_set_callback(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_20005a74 == 0);
  DataMemoryBarrier(0x1f);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 * 4 + DAT_20005a80) = 0;
    *DAT_20005a84 = *DAT_20005a84 & ~(byte)(1 << (param_1 & 0xff));
    irq_remove_handler(param_1,DAT_20005a78);
    irq_set_enabled(param_1,0);
  }
  else {
    iVar2 = irq_get_vtable_handler(param_1);
    if (DAT_20005a78 != iVar2) {
      irq_set_exclusive_handler(param_1,DAT_20005a78);
      irq_set_enabled(param_1,1);
      *DAT_20005a7c = 1 << (param_1 & 0xff);
    }
    *(int *)(param_1 * 4 + DAT_20005a80) = param_2;
  }
  DataMemoryBarrier(0x1f);
  *DAT_20005a74 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== hardware_alarm_set_target @ 20005a88 (198 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x20005aa6) */
/* WARNING: Removing unreachable block (ram,0x20005b14) */

undefined4
hardware_alarm_set_target(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar7 = time_us_64();
  if (uVar7 < CONCAT44(param_4,param_3)) {
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (*DAT_20005b50 == 0);
    DataMemoryBarrier(0x1f);
    bVar1 = *DAT_20005b54;
    uVar5 = 1 << (param_1 & 0xff);
    *DAT_20005b54 = (byte)uVar5 | bVar1;
    iVar3 = DAT_20005b58;
    *(uint *)(DAT_20005b58 + 0x34) = uVar5;
    *(undefined4 *)((param_1 + 4) * 4 + iVar3) = param_3;
    *(undefined4 *)(param_1 * 4 + DAT_20005b5c) = param_4;
    if ((*(uint *)(iVar3 + 0x20) & uVar5) == 0) {
      if ((*(uint *)(DAT_20005b58 + 0x40) & uVar5) == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005b68,0xc1,DAT_20005b64,DAT_20005b60);
      }
      uVar4 = 0;
    }
    else {
      uVar7 = time_us_64();
      iVar3 = DAT_20005b58;
      if (uVar7 < CONCAT44(param_4,param_3)) {
        uVar4 = 0;
      }
      else if (*DAT_20005b54 == bVar1) {
        uVar4 = 1;
      }
      else {
        *(uint *)(DAT_20005b58 + 0x20) = uVar5;
        *(uint *)(iVar3 + 0x34) = uVar5;
        *DAT_20005b6c = 1 << (param_1 & 0x1f);
        *DAT_20005b54 = bVar1;
        uVar4 = 1;
      }
    }
    DataMemoryBarrier(0x1f);
    *DAT_20005b50 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


/* ===== hardware_alarm_cancel @ 20005b70 (50 bytes) ===== */

void hardware_alarm_cancel(uint param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_20005ba4 == 0);
  DataMemoryBarrier(0x1f);
  iVar2 = 1 << (param_1 & 0xff);
  *(int *)(DAT_20005ba8 + 0x20) = iVar2;
  *DAT_20005bac = *DAT_20005bac & ~(byte)iVar2;
  DataMemoryBarrier(0x1f);
  *DAT_20005ba4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== lock_init @ 20005bb0 (12 bytes) ===== */

void lock_init(int *param_1,int param_2)

{
  *param_1 = (param_2 + DAT_20005bbc) * 4;
  return;
}


/* ===== mutex_init @ 20005bc0 (26 bytes) ===== */

void mutex_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = next_striped_spin_lock_num();
  lock_init(param_1,uVar1);
  *(undefined *)(param_1 + 4) = 0xff;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== recursive_mutex_init @ 20005bda (30 bytes) ===== */

void recursive_mutex_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = next_striped_spin_lock_num();
  lock_init(param_1,uVar1);
  *(undefined *)(param_1 + 4) = 0xff;
  *(undefined *)(param_1 + 5) = 0;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== critical_section_init_with_lock_num @ 20005bf8 (16 bytes) ===== */

void critical_section_init_with_lock_num(int *param_1,int param_2)

{
  *param_1 = (param_2 + DAT_20005c08) * 4;
  DataMemoryBarrier(0x1f);
  return;
}


/* ===== critical_section_init @ 20005c0c (20 bytes) ===== */

void critical_section_init(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = spin_lock_claim_unused(1);
  critical_section_init_with_lock_num(param_1,uVar1);
  return;
}


/* ===== ph_add_child_node @ 20005c20 (134 bytes) ===== */

void ph_add_child_node(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005cb0,0x69,DAT_20005cac,DAT_20005ca8);
  }
  pcVar2 = (char *)(param_2 * 3 + -3 + *param_1);
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005cb0,0x70,DAT_20005cb8,DAT_20005cb4);
  }
  if (param_3 != 0) {
    if (param_2 == param_3) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005cb0,0x72,DAT_20005cb8,DAT_20005cc0);
    }
    if ((param_3 != 0) && (param_3 <= *(byte *)(param_1 + 3))) {
      iVar1 = *param_1 + param_3 * 3 + -3;
      *(char *)(iVar1 + 2) = (char)param_2;
      if (*pcVar2 == '\0') {
        *pcVar2 = (char)param_3;
      }
      else {
        *(char *)(iVar1 + 1) = *pcVar2;
        *pcVar2 = (char)param_3;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005cb0,0x69,DAT_20005cac,DAT_20005ca8);
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20005cb0,0x71,DAT_20005cb8,DAT_20005cbc);
}


/* ===== ph_merge_nodes @ 20005cc4 (62 bytes) ===== */

int ph_merge_nodes(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3;
  if ((param_2 != 0) && (iVar2 = param_2, param_3 != 0)) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      ph_add_child_node(param_1,param_3,param_2);
      iVar2 = param_3;
    }
    else {
      ph_add_child_node(param_1,param_2,param_3);
    }
  }
  return iVar2;
}


/* ===== ph_clear @ 20005d04 (100 bytes) ===== */

void ph_clear(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined *)((int)param_1 + 0xd) = 0;
  *(undefined *)((int)param_1 + 0xe) = 1;
  *(undefined *)((int)param_1 + 0xf) = *(undefined *)(param_1 + 3);
  uVar3 = 1;
  while( true ) {
    uVar2 = (uint)*(byte *)(param_1 + 3);
    if (uVar2 <= uVar3) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005d70,0x69,DAT_20005d6c,DAT_20005d68);
      }
      *(undefined *)(*param_1 + uVar2 * 3 + -2) = 0;
      return;
    }
    if ((uVar3 == 0) || (*(byte *)(param_1 + 3) < uVar3)) break;
    iVar1 = uVar3 * 3;
    uVar2 = uVar3 + 1;
    uVar3 = uVar2 & 0xff;
    *(char *)(iVar1 + *param_1 + -2) = (char)uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20005d70,0x69,DAT_20005d6c,DAT_20005d68);
}


/* ===== ph_post_alloc_init @ 20005d74 (14 bytes) ===== */

void ph_post_alloc_init(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_4;
  ph_clear();
  return;
}


/* ===== ph_merge_two_pass @ 20005d84 (156 bytes) ===== */

void ph_merge_two_pass(int *param_1,uint param_2)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 != 0) {
    if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20005e28,0x69,DAT_20005e24,DAT_20005e20);
    }
    uVar4 = (uint)*(byte *)(param_2 * 3 + *param_1 + -2);
    if (uVar4 != 0) {
      if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005e28,0x69,DAT_20005e24,DAT_20005e20);
      }
      iVar5 = uVar4 * 3 + -3 + *param_1;
      uVar1 = *(undefined *)(iVar5 + 1);
      *(undefined *)(iVar5 + 1) = 0;
      if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005e28,0x69,DAT_20005e24,DAT_20005e20);
      }
      *(undefined *)(param_2 * 3 + *param_1 + -2) = 0;
      uVar2 = ph_merge_nodes(param_1,param_2);
      uVar3 = ph_merge_two_pass(param_1,uVar1);
      ph_merge_nodes(param_1,uVar2,uVar3);
    }
  }
  return;
}


/* ===== ph_remove_any_head @ 20005e2c (232 bytes) ===== */

void ph_remove_any_head(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005f1c,0x38,DAT_20005f18,DAT_20005f14);
  }
  if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005f28,0x69,DAT_20005f24,DAT_20005f20);
  }
  puVar3 = (undefined *)(param_2 * 3 + -3 + *param_1);
  if (puVar3[1] != '\0') {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005f1c,0x3a,DAT_20005f18,DAT_20005f2c);
  }
  if (puVar3[2] == '\0') {
    uVar1 = ph_merge_two_pass(param_1,*puVar3);
    if (param_3 != 0) {
      uVar2 = (uint)*(byte *)((int)param_1 + 0xf);
      if (uVar2 != 0) {
        if ((uVar2 == 0) || (*(byte *)(param_1 + 3) < uVar2)) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_20005f28,0x69,DAT_20005f24,DAT_20005f20);
        }
        *(char *)(uVar2 * 3 + *param_1 + -2) = (char)param_2;
      }
      *(char *)((int)param_1 + 0xf) = (char)param_2;
    }
    if (uVar1 != 0) {
      if ((uVar1 == 0) || (*(byte *)(param_1 + 3) < uVar1)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20005f28,0x69,DAT_20005f24,DAT_20005f20);
      }
      *(undefined *)(uVar1 * 3 + *param_1 + -1) = 0;
    }
    if ((param_2 != 0) && (param_2 <= *(byte *)(param_1 + 3))) {
      *(undefined *)(*param_1 + param_2 * 3 + -2) = 0;
      return;
    }
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20005f28,0x69,DAT_20005f24,DAT_20005f20);
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20005f1c,0x3b,DAT_20005f18,DAT_20005f30);
}


/* ===== ph_remove_head @ 20005f34 (20 bytes) ===== */

undefined ph_remove_head(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined uVar2;
  
  uVar1 = *(undefined *)(param_1 + 0xd);
  uVar2 = ph_remove_any_head(param_1,uVar1,param_2);
  *(undefined *)(param_1 + 0xd) = uVar2;
  return uVar1;
}


/* ===== ph_remove_and_free_node @ 20005f48 (220 bytes) ===== */

undefined4 ph_remove_and_free_node(int *param_1,uint param_2)

{
  undefined uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else if (*(byte *)((int)param_1 + 0xd) == param_2) {
    ph_remove_head(param_1,1);
    uVar3 = 1;
  }
  else {
    if ((param_2 == 0) || (*(byte *)(param_1 + 3) < param_2)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_2000602c,0x69,DAT_20006028,DAT_20006024);
    }
    iVar2 = *param_1 + param_2 * 3 + -3;
    uVar4 = (uint)*(byte *)(iVar2 + 2);
    if (uVar4 == 0) {
      uVar3 = 0;
    }
    else {
      if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_2000602c,0x69,DAT_20006028,DAT_20006024);
      }
      iVar5 = uVar4 * 3 + -3;
      uVar4 = (uint)*(byte *)(*param_1 + iVar5);
      if (uVar4 == param_2) {
        *(undefined *)(*param_1 + iVar5) = *(undefined *)(iVar2 + 1);
      }
      else {
        while( true ) {
          if ((uVar4 == 0) || (*(byte *)(param_1 + 3) < uVar4)) {
                    /* WARNING: Subroutine does not return */
            __assert_func(DAT_2000602c,0x69,DAT_20006028,DAT_20006024);
          }
          iVar5 = *param_1 + uVar4 * 3 + -3;
          uVar4 = (uint)*(byte *)(iVar5 + 1);
          if (uVar4 == param_2) break;
          if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_func(DAT_20006038,0x67,DAT_20006034,DAT_20006030);
          }
        }
        *(undefined *)(iVar5 + 1) = *(undefined *)(iVar2 + 1);
      }
      *(undefined *)(iVar2 + 2) = 0;
      *(undefined *)(iVar2 + 1) = 0;
      uVar4 = ph_remove_any_head(param_1,param_2,1);
      if (*(byte *)((int)param_1 + 0xd) == uVar4) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20006038,0x6d,DAT_20006034,DAT_2000603c);
      }
      uVar1 = ph_merge_nodes(param_1,(uint)*(byte *)((int)param_1 + 0xd),uVar4);
      *(undefined *)((int)param_1 + 0xd) = uVar1;
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* ===== _exit @ 20006040 (4 bytes) ===== */

void _exit(void)

{
  do {
    software_bkpt(0);
  } while( true );
}


/* ===== FUN_20006044 @ 20006044 (8 bytes) ===== */

void FUN_20006044(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = _exit();
  uVar4 = CONCAT44(param_4,(int)uVar3);
  iVar1 = param_3;
  iVar2 = DAT_2000607c;
  if (param_3 == 0) goto LAB_20006072;
  do {
    param_3 = (int)uVar4;
    if (iVar1 == 0) {
      iVar1 = DAT_20006084;
    }
    __wrap_printf(DAT_20006080,(int)((ulonglong)uVar4 >> 0x20),param_3,
                  (int)((ulonglong)uVar3 >> 0x20),iVar2,iVar1);
    uVar4 = _exit(1);
LAB_20006072:
    iVar1 = param_3;
    iVar2 = DAT_20006084;
  } while( true );
}


/* ===== __assert_func @ 2000604c (46 bytes) ===== */

void __assert_func(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = CONCAT44(param_4,param_1);
  iVar1 = param_3;
  iVar2 = DAT_2000607c;
  if (param_3 == 0) goto LAB_20006072;
  do {
    param_3 = (int)uVar3;
    if (iVar1 == 0) {
      iVar1 = DAT_20006084;
    }
    __wrap_printf(DAT_20006080,(int)((ulonglong)uVar3 >> 0x20),param_3,param_2,iVar2,iVar1);
    uVar3 = _exit(1);
LAB_20006072:
    iVar1 = param_3;
    iVar2 = DAT_20006084;
  } while( true );
}


/* ===== runtime_init @ 20006088 (174 bytes) ===== */

void runtime_init(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code **ppcVar4;
  
  *DAT_20006138 = DAT_2000613c;
  *DAT_20006140 = DAT_20006144;
  do {
    ppcVar4 = DAT_2000614c;
  } while ((DAT_20006144 & ~*(uint *)(DAT_20006148 + 8)) != 0);
  for (; ppcVar4 < DAT_20006150; ppcVar4 = ppcVar4 + 1) {
    (**ppcVar4)();
  }
  clocks_init();
  *DAT_20006140 = DAT_20006154;
  iVar2 = DAT_20006158;
  do {
  } while ((~*(uint *)(DAT_20006148 + 8) & 0x1ffffff) != 0);
  *(undefined4 *)(DAT_20006158 + 0x78) = 0x40;
  *(undefined4 *)(iVar2 + 0x74) = 0x40;
  *(undefined4 *)(iVar2 + 0x70) = 0x40;
  *(undefined4 *)(iVar2 + 0x6c) = 0x40;
  piVar3 = DAT_2000615c;
  while( true ) {
    while( true ) {
      uVar1 = DAT_20006174;
      iVar2 = DAT_20006170;
      if (DAT_2000616c <= piVar3) {
        memcpy(DAT_20006174,*(undefined4 *)(DAT_20006170 + 8),0xc0);
        *(undefined4 *)(iVar2 + 8) = uVar1;
        iVar2 = ____get_current_exception_veneer();
        if (iVar2 != 0) {
          software_bkpt(0);
        }
        spin_locks_reset();
        irq_init_priorities();
        alarm_pool_init_default();
        for (ppcVar4 = DAT_20006178; ppcVar4 < DAT_2000617c; ppcVar4 = ppcVar4 + 1) {
          (**ppcVar4)();
        }
        return;
      }
      if (*piVar3 != 0) break;
      mutex_init(piVar3);
      piVar3 = piVar3 + 2;
    }
    if (*piVar3 != 1) break;
    recursive_mutex_init(piVar3);
    piVar3 = piVar3 + 2;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20006168,0x83,DAT_20006164,DAT_20006160);
}


/* ===== panic @ 20006180 (48 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x20006272) */
/* WARNING: Removing unreachable block (ram,0x20006276) */
/* WARNING: Removing unreachable block (ram,0x20006280) */
/* WARNING: Removing unreachable block (ram,0x20006286) */
/* WARNING: Removing unreachable block (ram,0x20006288) */
/* WARNING: Removing unreachable block (ram,0x20006292) */
/* WARNING: Removing unreachable block (ram,0x2000629c) */

undefined4 panic(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *unaff_r6;
  uint uStack_20;
  
  __wrap_puts(s_____PANIC_____2000ce38);
  if (param_1 != 0) {
    __wrap_vprintf(param_1);
    __wrap_puts(s___8s___16s_rev___4s_2000c5fc + 0x14);
  }
  _exit(1);
  uVar4 = *unaff_r6;
  unaff_r6[3] = unaff_r6[1];
  if (uVar4 < uStack_20) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200062b0,0x2d,DAT_200062ac,DAT_200062a8);
  }
  uVar2 = __aeabi_uldivmod(uVar4 << 8,uVar4 >> 0x18,uStack_20,0);
  puVar1 = DAT_200062a0;
  if (DAT_200062a0[1] < uVar2) {
    DAT_200062a0[1] = uVar2;
  }
  *(undefined4 *)((uint)puVar1 | 0x3000) = 0x800;
  if (*DAT_200062a4 != 0) {
    iVar3 = __aeabi_uidiv(DAT_200062a4[5]);
    iVar3 = iVar3 + 1;
    do {
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(uint *)((uint)puVar1 | 0x1000) = (param_3 << 5 ^ *puVar1) & 0xe0;
  *(undefined4 *)((uint)puVar1 | 0x2000) = 0x800;
  puVar1[1] = uVar2;
  iVar3 = __aeabi_uldivmod(uVar4 << 8,uVar4 >> 0x18,uVar2,0);
  *DAT_200062a4 = iVar3;
  return 1;
}


/* ===== clock_configure @ 200061b0 (238 bytes) ===== */

undefined4 clock_configure(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_4 < param_5) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200062b0,0x2d,DAT_200062ac,DAT_200062a8);
  }
  uVar1 = __aeabi_uldivmod(param_4 << 8,param_4 >> 0x18,param_5,0);
  puVar5 = (uint *)(param_1 * 0xc + DAT_200062a0);
  if (puVar5[1] < uVar1) {
    puVar5[1] = uVar1;
  }
  uVar4 = param_1 - 4U & 0xff;
  if ((uVar4 < 2) && (param_2 == 1)) {
    *(undefined4 *)((uint)puVar5 | 0x3000) = 3;
    do {
    } while (-1 < (int)(puVar5[2] << 0x1f));
  }
  else {
    *(undefined4 *)((uint)puVar5 | 0x3000) = 0x800;
    if (*(int *)(param_1 * 4 + DAT_200062a4) != 0) {
      iVar2 = __aeabi_uidiv(*(undefined4 *)(DAT_200062a4 + 0x14));
      iVar2 = iVar2 + 1;
      do {
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  *(uint *)((uint)puVar5 | 0x1000) = (param_3 << 5 ^ *puVar5) & 0xe0;
  if (uVar4 < 2) {
    *(uint *)((uint)puVar5 | 0x1000) = (*puVar5 ^ param_2) & 3;
    do {
    } while ((1 << (param_2 & 0xff) & puVar5[2]) == 0);
  }
  *(undefined4 *)((uint)puVar5 | 0x2000) = 0x800;
  puVar5[1] = uVar1;
  uVar3 = __aeabi_uldivmod(param_4 << 8,param_4 >> 0x18,uVar1,0);
  *(undefined4 *)(DAT_200062a4 + param_1 * 4) = uVar3;
  return 1;
}


/* ===== clocks_init @ 200062b4 (206 bytes) ===== */

void clocks_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  watchdog_start_tick(0xc);
  iVar3 = running_on_fpga();
  if (iVar3 == 0) {
    *(undefined4 *)(DAT_20006390 + 0x78) = 0;
    xosc_init();
    *DAT_20006394 = 1;
    do {
    } while (*(int *)(DAT_20006390 + 0x44) != 1);
    *DAT_20006398 = 3;
    do {
    } while (*(int *)(DAT_20006390 + 0x38) != 1);
    pll_init(DAT_200063a0,1,DAT_2000639c,6,2);
    pll_init(DAT_200063a8,1,DAT_200063a4,5,2);
    clock_configure(4,2,0,DAT_200063ac,DAT_200063ac);
    uVar2 = DAT_200063b0;
    clock_configure(5,1,0,DAT_200063b0,DAT_200063b0);
    uVar1 = DAT_20006388;
    clock_configure(7,0,0,DAT_20006388,DAT_20006388);
    clock_configure(8,0,0,uVar1,uVar1);
    clock_configure(9,0,0,uVar1,DAT_2000638c);
    clock_configure(6,0,0,uVar2,uVar2);
  }
  else {
    for (uVar4 = 0; uVar4 < 10; uVar4 = uVar4 + 1) {
      *(undefined4 *)(uVar4 * 4 + DAT_20006384) = DAT_20006388;
    }
    *(undefined4 *)(DAT_20006384 + 0x24) = DAT_2000638c;
  }
  return;
}


/* ===== clock_get_hz @ 200063b4 (8 bytes) ===== */

undefined4 clock_get_hz(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + DAT_200063bc);
}


/* ===== set_raw_irq_handler_and_unlock @ 200063c0 (30 bytes) ===== */

void set_raw_irq_handler_and_unlock(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  
  *(undefined4 *)(*(int *)(DAT_200063e0 + 8) + (param_1 + 0x10) * 4) = param_2;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_200063e4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_3 & 1) == 1);
  }
  return;
}


/* ===== make_branch @ 200063e8 (36 bytes) ===== */

uint make_branch(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 - param_1) - 4;
  if (uVar1 >> 0xc == 0) {
    return uVar1 >> 1 & 0x7ff | DAT_2000640c & 0xffff;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20006418,0x8b,DAT_20006414,DAT_20006410);
}


/* ===== insert_branch_and_link @ 2000641c (32 bytes) ===== */

void insert_branch_and_link(undefined2 *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 - (int)param_1) - 4;
  if (uVar1 >> 0xc == 0) {
    *param_1 = (short)DAT_20006448;
    param_1[1] = (ushort)DAT_2000644c | (ushort)(uVar1 >> 1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20006458,0x93,DAT_20006454,DAT_20006450);
}


/* ===== FUN_2000643c @ 2000643c (10 bytes) ===== */

void FUN_2000643c(void)

{
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20006458,0x93,DAT_20006454);
}


/* ===== irq_is_enabled @ 2000645c (18 bytes) ===== */

bool irq_is_enabled(uint param_1)

{
  return (*DAT_20006470 & 1 << (param_1 & 0xff)) != 0;
}


/* ===== irq_set_mask_enabled @ 20006474 (20 bytes) ===== */

void irq_set_mask_enabled(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    *DAT_20006490 = param_1;
  }
  else {
    *DAT_20006488 = param_1;
    *DAT_2000648c = param_1;
  }
  return;
}


/* ===== irq_set_enabled @ 20006494 (14 bytes) ===== */

void irq_set_enabled(uint param_1)

{
  irq_set_mask_enabled(1 << (param_1 & 0xff));
  return;
}


/* ===== irq_get_vtable_handler @ 200064a4 (12 bytes) ===== */

undefined4 irq_get_vtable_handler(int param_1)

{
  return *(undefined4 *)((param_1 + 0x10) * 4 + *(int *)(DAT_200064b0 + 8));
}


/* ===== irq_set_exclusive_handler @ 200064b4 (64 bytes) ===== */

void irq_set_exclusive_handler(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_200064f4 == 0);
  DataMemoryBarrier(0x1f);
  iVar2 = irq_get_vtable_handler(param_1);
  if ((iVar2 != DAT_200064f8) && (iVar2 != param_2)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20006504,0x6e,DAT_20006500,DAT_200064fc);
  }
  set_raw_irq_handler_and_unlock(param_1,param_2,uVar3);
  return;
}


/* ===== irq_remove_handler @ 20006508 (372 bytes) ===== */

void irq_remove_handler(int param_1,uint param_2)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  
  uVar14 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar14 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*DAT_2000667c == 0);
  DataMemoryBarrier(0x1f);
  uVar12 = *(uint *)(*(int *)(DAT_20006680 + 8) + (param_1 + 0x10) * 4);
  uVar9 = uVar12;
  if (((uVar12 != DAT_20006684) && (uVar9 = DAT_20006684, uVar12 != param_2)) &&
     (uVar9 = uVar12, uVar12 - DAT_20006688 < 0x30)) {
    uVar6 = irq_is_enabled(param_1);
    irq_set_enabled(param_1,0);
    DataMemoryBarrier(0x1f);
    iVar7 = ____get_current_exception_veneer();
    if ((iVar7 != 0) && (param_1 + 0x10 != iVar7)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20006698,0x11d,DAT_20006694,DAT_20006690);
    }
    uVar8 = ((uVar10 - DAT_20006688) * 2 + (uint)(DAT_20006688 <= uVar10)) * DAT_2000668c;
    uVar9 = 0;
    for (uVar10 = uVar12 & 0xfffffffe;
        (*(uint *)(uVar10 + 8) != param_2 && (uVar9 = uVar10, -1 < *(char *)(uVar10 + 6)));
        uVar10 = DAT_20006688 + *(char *)(uVar10 + 6) * 0xc) {
    }
    if (*(uint *)(uVar10 + 8) != param_2) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20006698,0x152,DAT_20006694,DAT_200066b0);
    }
    cVar2 = *(char *)(uVar10 + 6);
    iVar11 = (int)cVar2;
    if (iVar11 < 0) {
      if (iVar7 == 0) {
        uVar13 = DAT_20006684;
        if (uVar9 != 0) {
          *(undefined *)(uVar9 + 6) = 0xff;
          *(short *)(uVar9 + 4) = (short)DAT_200066a8;
          uVar13 = uVar12;
        }
        pcVar4 = DAT_2000669c;
        *(char *)(uVar10 + 6) = *DAT_2000669c;
        *pcVar4 = (char)(uVar8 >> 0x14);
        uVar12 = uVar13;
      }
      else {
        insert_branch_and_link(uVar10 + 4,DAT_200066ac);
      }
    }
    else {
      iVar7 = DAT_20006688 + iVar11 * 0xc;
      *(undefined4 *)(uVar10 + 8) = *(undefined4 *)(iVar7 + 8);
      *(undefined *)(uVar10 + 7) = *(undefined *)(iVar7 + 7);
      *(undefined *)(uVar10 + 6) = *(undefined *)(iVar7 + 6);
      if (*(char *)(iVar7 + 6) < '\0') {
        uVar5 = 0xbd00;
      }
      else {
        iVar7 = iVar11 * 0xc + DAT_20006688;
        uVar1 = *(ushort *)(iVar7 + 4);
        if (uVar1 >> 0xb != 0x1c) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_20006698,0x99,DAT_200066a4,DAT_200066a0);
        }
        uVar5 = make_branch(uVar10 + 4,iVar7 + 4 + (((int)((uint)uVar1 << 0x15) >> 0x15) + 2) * 2);
      }
      *(undefined2 *)(uVar10 + 4) = uVar5;
      pcVar4 = DAT_2000669c;
      *(char *)(DAT_20006688 + iVar11 * 0xc + 6) = *DAT_2000669c;
      *pcVar4 = cVar2;
    }
    irq_set_enabled(param_1,uVar6);
    uVar9 = uVar12;
  }
  set_raw_irq_handler_and_unlock(param_1,uVar9,uVar14);
  return;
}


/* ===== irq_add_tail_to_free_list @ 200066b4 (192 bytes) ===== */

void irq_add_tail_to_free_list(uint param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (0x2f < (param_1 | 1) - DAT_20006774) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_2000678c,0x177,DAT_20006788,DAT_20006784);
  }
  iVar4 = ____get_current_exception_veneer();
  if (iVar4 != 0) {
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (*DAT_20006778 == 0);
    DataMemoryBarrier(0x1f);
    cVar2 = (char)(((param_1 - DAT_20006774) * 2 + (uint)(DAT_20006774 <= param_1)) * DAT_2000677c
                  >> 0x14);
    if (*(uint *)(*(int *)(DAT_20006780 + 8) + iVar4 * 4) == (param_1 | 1)) {
      *(undefined4 *)(*(int *)(DAT_20006780 + 8) + iVar4 * 4) = DAT_20006794;
    }
    else {
      uVar5 = 0;
      while( true ) {
        if (3 < uVar5) {
                    /* WARNING: Subroutine does not return */
          __assert_func(DAT_2000678c,0x18b,DAT_20006788,DAT_200067a0);
        }
        if (*(char *)(DAT_20006774 + uVar5 * 0xc + 6) == cVar2) break;
        uVar5 = uVar5 + 1;
      }
      iVar4 = DAT_20006774 + uVar5 * 0xc;
      *(undefined *)(iVar4 + 6) = 0xff;
      *(short *)(iVar4 + 4) = (short)DAT_2000679c;
    }
    pcVar3 = DAT_20006798;
    *(char *)(param_1 + 6) = *DAT_20006798;
    *pcVar3 = cVar2;
    DataMemoryBarrier(0x1f);
    *DAT_20006778 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_2000678c,0x17a,DAT_20006788,DAT_20006790);
}


/* ===== irq_init_priorities @ 200067a4 (18 bytes) ===== */

void irq_init_priorities(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_200067b8;
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    *puVar2 = DAT_200067bc;
    puVar2 = puVar2 + 1;
  }
  return;
}


/* ===== pll_init @ 200067c0 (240 bytes) ===== */

void pll_init(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = __aeabi_uidiv(0xc);
  uVar2 = __aeabi_uidiv(param_3,uVar1 * 1000000);
  if (0x130 < uVar2 - 0x10) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200068c8,0x16,DAT_200068c4,DAT_200068c0);
  }
  if ((6 < param_4 - 1) || (6 < param_5 - 1)) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200068c8,0x19,DAT_200068c4,DAT_200068cc);
  }
  if (param_4 < param_5) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200068c8,0x1f,DAT_200068c4,DAT_200068d0);
  }
  if (param_3 >> 4 < uVar1) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200068c8,0x22,DAT_200068c4,DAT_200068d4);
  }
  uVar1 = param_4 << 0x10 | param_5 << 0xc;
  if ((((-1 < (int)*param_1) || ((*param_1 & 0x3f) != param_2)) || ((param_1[2] & 0xfff) != uVar2))
     || (uVar1 != 0)) {
    if (param_1 == DAT_200068b0) {
      uVar3 = 0x2000;
    }
    else {
      uVar3 = 0x1000;
    }
    *DAT_200068b4 = uVar3;
    *DAT_200068b8 = uVar3;
    do {
    } while ((uVar3 & ~*(uint *)(DAT_200068bc + 8)) != 0);
    *param_1 = param_2;
    param_1[2] = uVar2;
    *(undefined4 *)((uint)(param_1 + 1) | 0x3000) = 0x21;
    do {
    } while (-1 < (int)*param_1);
    param_1[3] = uVar1;
    *(undefined4 *)((uint)(param_1 + 1) | 0x3000) = 8;
  }
  return;
}


/* ===== watchdog_start_tick @ 200068d8 (12 bytes) ===== */

void watchdog_start_tick(uint param_1)

{
  *(uint *)(DAT_200068e4 + 0x2c) = param_1 | 0x200;
  return;
}


/* ===== watchdog_update @ 200068e8 (10 bytes) ===== */

void watchdog_update(void)

{
  *(undefined4 *)(DAT_200068f8 + 4) = *DAT_200068f4;
  return;
}


/* ===== _watchdog_enable @ 200068fc (96 bytes) ===== */

void _watchdog_enable(int param_1,int param_2)

{
  *DAT_2000695c = 0x40000000;
  *DAT_20006960 = DAT_20006964;
  if (param_2 == 0) {
    *DAT_2000695c = 0x7000000;
  }
  else {
    *DAT_20006968 = 0x7000000;
  }
  if (param_1 == 0) {
    *DAT_20006968 = 0x80000000;
  }
  else {
    *DAT_2000696c = param_1 * 2000;
    if (0xffffff < (uint)(param_1 * 2000)) {
      *DAT_2000696c = DAT_20006970;
    }
    watchdog_update();
    *DAT_20006968 = 0x40000000;
  }
  return;
}


/* ===== watchdog_enable @ 20006974 (14 bytes) ===== */

void watchdog_enable(void)

{
  *(undefined4 *)(DAT_20006984 + 0x1c) = DAT_20006988;
  _watchdog_enable();
  return;
}


/* ===== watchdog_caused_reboot @ 2000698c (12 bytes) ===== */

bool watchdog_caused_reboot(void)

{
  return *(int *)(DAT_20006998 + 8) != 0;
}


/* ===== xosc_init @ 2000699c (28 bytes) ===== */

void xosc_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_200069b8;
  *DAT_200069b8 = 0xaa0;
  puVar1[3] = 0x2f;
  *DAT_200069bc = DAT_200069c0;
  do {
  } while (-1 < (int)DAT_200069b8[1]);
  return;
}


/* ===== _out_null @ 200069c4 (2 bytes) ===== */

void _out_null(void)

{
  return;
}


/* ===== _out_fct @ 200069c6 (14 bytes) ===== */

void _out_fct(int param_1,code **param_2)

{
  if (param_1 != 0) {
    (**param_2)(param_1,param_2[1]);
  }
  return;
}


/* ===== _atoi @ 200069d4 (36 bytes) ===== */

int _atoi(byte **param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  while (pbVar2 = *param_1, (byte)(*pbVar2 - 0x30) < 10) {
    *param_1 = pbVar2 + 1;
    iVar1 = (uint)*pbVar2 + iVar1 * 10 + -0x30;
  }
  return iVar1;
}


/* ===== _out_rev @ 200069f8 (174 bytes) ===== */

int _out_rev(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            uint param_6,uint param_7,uint param_8)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_3;
  uVar1 = param_6;
  if ((param_8 & 3) == 0) {
    for (; uVar1 < param_7; uVar1 = uVar1 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
    }
  }
  while (param_6 != 0) {
    param_6 = param_6 - 1;
    (*param_1)(*(undefined *)(param_5 + param_6),param_2,iVar2,param_4);
    iVar2 = iVar2 + 1;
  }
  if ((int)(param_8 << 0x1e) < 0) {
    for (; (uint)(iVar2 - param_3) < param_7; iVar2 = iVar2 + 1) {
      (*param_1)(0x20,param_2,iVar2,param_4);
    }
  }
  return iVar2;
}


/* ===== _ntoa_format @ 20006aa6 (274 bytes) ===== */

void _ntoa_format(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,uint param_6,char param_7,int param_8,uint param_9,uint param_10,
                 uint param_11)

{
  uint uVar1;
  
  if (-1 < (int)(param_11 << 0x1e)) {
    if (((param_10 != 0) && ((int)(param_11 << 0x1f) < 0)) &&
       ((param_7 != '\0' || ((param_11 & 0xc) != 0)))) {
      param_10 = param_10 - 1;
    }
    for (; (param_6 < param_9 && (param_6 < 0x20)); param_6 = param_6 + 1) {
      *(undefined *)(param_5 + param_6) = 0x30;
    }
    for (; (((int)(param_11 << 0x1f) < 0 && (param_6 < param_10)) && (param_6 < 0x20));
        param_6 = param_6 + 1) {
      *(undefined *)(param_5 + param_6) = 0x30;
    }
  }
  uVar1 = param_6;
  if ((int)(param_11 << 0x1b) < 0) {
    if ((((-1 < (int)(param_11 << 0x15)) && (param_6 != 0)) &&
        ((param_6 == param_9 || (param_6 == param_10)))) &&
       ((uVar1 = param_6 - 1, param_6 != 1 && (param_8 == 0x10)))) {
      uVar1 = param_6 - 2;
    }
    if (((param_8 == 0x10) && (-1 < (int)(param_11 << 0x1a))) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x78;
      uVar1 = uVar1 + 1;
    }
    else if (((param_8 == 0x10) && ((int)(param_11 << 0x1a) < 0)) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x58;
      uVar1 = uVar1 + 1;
    }
    else if ((param_8 == 2) && (uVar1 < 0x20)) {
      *(undefined *)(param_5 + uVar1) = 0x62;
      uVar1 = uVar1 + 1;
    }
    if (uVar1 < 0x20) {
      *(undefined *)(param_5 + uVar1) = 0x30;
      uVar1 = uVar1 + 1;
    }
  }
  if (uVar1 < 0x20) {
    if (param_7 == '\0') {
      if ((int)(param_11 << 0x1d) < 0) {
        *(undefined *)(param_5 + uVar1) = 0x2b;
        uVar1 = uVar1 + 1;
      }
      else if ((int)(param_11 << 0x1c) < 0) {
        *(undefined *)(param_5 + uVar1) = 0x20;
        uVar1 = uVar1 + 1;
      }
    }
    else {
      *(undefined *)(param_5 + uVar1) = 0x2d;
      uVar1 = uVar1 + 1;
    }
  }
  _out_rev(param_1,param_2,param_3,param_4,param_5,uVar1,param_10,param_11);
  return;
}


/* ===== _ntoa_long @ 20006bb8 (188 bytes) ===== */

void _ntoa_long(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               uint param_5,undefined param_6,uint param_7,undefined4 param_8,undefined4 param_9,
               uint param_10)

{
  uint uVar1;
  byte extraout_r1;
  char cVar2;
  uint uVar3;
  char local_48 [36];
  
  if (param_5 == 0) {
    param_10 = param_10 & 0xffffffef;
  }
  uVar1 = param_10 & 0x400;
  if ((param_10 & 0x400) != 0) {
    if (param_5 == 0) {
      uVar3 = 0;
      goto LAB_20006c42;
    }
    uVar1 = 0;
  }
  do {
    __aeabi_uidiv(param_5,param_7);
    if (extraout_r1 < 10) {
      cVar2 = extraout_r1 + 0x30;
    }
    else {
      if ((int)(param_10 << 0x1a) < 0) {
        cVar2 = 'A';
      }
      else {
        cVar2 = 'a';
      }
      cVar2 = cVar2 + extraout_r1 + -10;
    }
    uVar3 = uVar1 + 1;
    local_48[uVar1] = cVar2;
    uVar1 = __aeabi_uidiv(param_5,param_7);
  } while ((param_7 <= param_5) && (param_5 = uVar1, uVar1 = uVar3, uVar3 < 0x20));
LAB_20006c42:
  _ntoa_format(param_1,param_2,param_3,param_4,local_48,uVar3,param_6,param_7,param_8,param_9,
               param_10);
  return;
}


/* ===== _ntoa_long_long @ 20006c74 (226 bytes) ===== */

void _ntoa_long_long(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    uint param_5,uint param_6,undefined param_7,undefined4 param_8,uint param_9,
                    uint param_10,undefined4 param_11,undefined4 param_12,uint param_13)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  char local_48 [36];
  
  if ((param_5 | param_6) == 0) {
    param_13 = param_13 & 0xffffffef;
  }
  uVar5 = param_13 & 0x400;
  uVar6 = CONCAT44(param_6,param_5);
  if ((param_13 & 0x400) != 0) {
    if ((param_5 | param_6) == 0) {
      uVar2 = 0;
      goto LAB_20006d20;
    }
    uVar5 = 0;
    uVar6 = CONCAT44(param_6,param_5);
  }
  do {
    uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
    uVar4 = (uint)uVar6;
    uVar2 = param_9;
    __aeabi_uldivmod(uVar4,uVar3,param_9,param_10);
    if ((uVar2 & 0xff) < 10) {
      cVar1 = (char)uVar2 + '0';
    }
    else {
      if ((int)(param_13 << 0x1a) < 0) {
        cVar1 = 'A';
      }
      else {
        cVar1 = 'a';
      }
      cVar1 = cVar1 + (char)uVar2 + -10;
    }
    uVar2 = uVar5 + 1;
    local_48[uVar5] = cVar1;
    uVar6 = __aeabi_uldivmod(uVar4,uVar3,param_9,param_10);
  } while ((param_10 < uVar3 || param_10 == uVar3) &&
          (((param_10 != uVar3 || (param_9 <= uVar4)) && (uVar5 = uVar2, uVar2 < 0x20))));
LAB_20006d20:
  _ntoa_format(param_1,param_2,param_3,param_4,local_48,uVar2,param_7,param_9,param_11,param_12,
               param_13);
  return;
}


/* ===== _etoa @ 20006d58 (728 bytes) ===== */

int _etoa(code *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,uint param_6,
         int param_7,uint param_8,uint param_9)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 local_50;
  uint local_4c;
  
  iVar1 = __wrap___aeabi_dcmpun(param_5,param_6,param_5,param_6);
  if (((iVar1 == 0) &&
      (iVar1 = __wrap___aeabi_dcmpgt(param_5,param_6,0xffffffff,DAT_200070ec), iVar1 == 0)) &&
     (iVar1 = __wrap___aeabi_dcmplt(param_5,param_6,0xffffffff,DAT_200070f0), iVar1 == 0)) {
    iVar1 = __wrap___aeabi_dcmplt(param_5,param_6,0,0);
    if (iVar1 == 0) {
      local_4c = param_6;
    }
    else {
      local_4c = param_6 + 0x80000000;
    }
    uVar14 = CONCAT44(local_4c,param_5);
    if ((param_9 & 0x400) == 0) {
      param_7 = 6;
    }
    if ((local_4c | param_5) == 0) {
      uVar10 = 0;
      uVar6 = param_5;
      uVar7 = local_4c;
    }
    else {
      uVar6 = DAT_200070f8 | local_4c & 0xfffff;
      uVar11 = __wrap___aeabi_i2d((local_4c >> 0x14 & 0x7ff) + DAT_200070f4);
      uVar11 = __wrap___aeabi_dmul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_200070fc,
                                   DAT_20007100);
      uVar11 = __wrap___aeabi_dadd((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_20007104,
                                   DAT_20007108);
      uVar12 = __wrap___aeabi_dsub(param_5,uVar6,0,DAT_2000710c);
      uVar12 = __wrap___aeabi_dmul((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_20007110,
                                   DAT_20007114);
      __wrap___aeabi_dadd((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
      uVar10 = __wrap___aeabi_d2iz__or__double2int_z();
      uVar11 = __wrap___aeabi_i2d();
      uVar8 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar12 = __wrap___aeabi_dmul((int)uVar11,uVar8,DAT_20007118,DAT_2000711c);
      __wrap___aeabi_dadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_20007120);
      iVar1 = __wrap___aeabi_d2iz__or__double2int_z();
      uVar11 = __wrap___aeabi_dmul((int)uVar11,uVar8,DAT_20007124,DAT_20007128);
      uVar12 = __wrap___aeabi_i2d(iVar1);
      uVar12 = __wrap___aeabi_dmul((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_2000712c,
                                   DAT_20007130);
      uVar11 = __wrap___aeabi_dsub((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                                   (int)((ulonglong)uVar12 >> 0x20));
      uVar4 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar8 = (undefined4)uVar11;
      uVar11 = __wrap___aeabi_dmul(uVar8,uVar4,uVar8,uVar4);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar2 = (undefined4)uVar11;
      iVar1 = iVar1 + DAT_20007134;
      uVar11 = __wrap___aeabi_dadd(uVar8,uVar4,uVar8,uVar4);
      uVar12 = __wrap___aeabi_dsub(0,0x40000000,uVar8,uVar4);
      uVar13 = __aeabi_ddiv(uVar2,uVar5,0,DAT_20007138);
      uVar13 = __wrap___aeabi_dadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,DAT_2000713c);
      uVar13 = __aeabi_ddiv(uVar2,uVar5,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      uVar13 = __wrap___aeabi_dadd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,DAT_20007140);
      uVar13 = __aeabi_ddiv(uVar2,uVar5,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      uVar12 = __wrap___aeabi_dadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar13,
                                   (int)((ulonglong)uVar13 >> 0x20));
      uVar11 = __aeabi_ddiv((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
                            (int)((ulonglong)uVar12 >> 0x20));
      uVar11 = __wrap___aeabi_dadd((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_200070f8);
      uVar11 = __wrap___aeabi_dmul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,iVar1 * 0x100000);
      uVar7 = (uint)((ulonglong)uVar11 >> 0x20);
      uVar6 = (uint)uVar11;
      iVar1 = __wrap___aeabi_dcmpgt(uVar6,uVar7,param_5,local_4c);
      if (iVar1 != 0) {
        uVar10 = uVar10 - 1;
        uVar11 = __aeabi_ddiv(uVar6,uVar7,0,DAT_2000713c);
        uVar7 = (uint)((ulonglong)uVar11 >> 0x20);
        uVar6 = (uint)uVar11;
      }
    }
    if (uVar10 + 99 < 199) {
      uVar9 = 4;
    }
    else {
      uVar9 = 5;
    }
    if ((int)(param_9 << 0x14) < 0) {
      if (((uVar7 | uVar6) == 0) ||
         ((iVar1 = __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                             (param_5,local_4c,DAT_20007144,DAT_20007148), iVar1 != 0 &&
          (iVar1 = __wrap___aeabi_dcmplt(param_5,local_4c,0,DAT_2000714c), iVar1 != 0)))) {
        if ((int)uVar10 < param_7) {
          param_7 = (param_7 - uVar10) + -1;
        }
        else {
          param_7 = 0;
        }
        param_9 = param_9 | 0x400;
        uVar9 = 0;
        uVar10 = 0;
      }
      else if ((param_7 != 0) && ((param_9 & 0x400) != 0)) {
        param_7 = param_7 + -1;
      }
    }
    if (uVar9 < param_8) {
      iVar1 = param_8 - uVar9;
    }
    else {
      iVar1 = 0;
    }
    if (((param_9 & 2) != 0) && (uVar9 != 0)) {
      iVar1 = 0;
    }
    if (uVar10 != 0) {
      uVar14 = __aeabi_ddiv(param_5,local_4c,uVar6,uVar7);
    }
    local_4c = (uint)((ulonglong)uVar14 >> 0x20);
    local_50 = (undefined4)uVar14;
    iVar3 = __wrap___aeabi_dcmplt(param_5,param_6,0,0);
    if (iVar3 != 0) {
      local_4c = local_4c + -0x80000000;
    }
    iVar1 = _ftoa(param_1,param_2,param_3,param_4,local_50,local_4c,param_7,iVar1,
                  DAT_20007150 & param_9);
    if (uVar9 != 0) {
      if ((int)(param_9 << 0x1a) < 0) {
        uVar8 = 0x45;
      }
      else {
        uVar8 = 0x65;
      }
      (*param_1)(uVar8,param_2,iVar1,param_4);
      iVar1 = _ntoa_long(param_1,param_2,iVar1 + 1,param_4,
                         uVar10 + ((int)uVar10 >> 0x1f) ^ (int)uVar10 >> 0x1f,uVar10 >> 0x1f,10,0,
                         uVar9 - 1,5);
      if ((param_9 & 2) != 0) {
        for (; (uint)(iVar1 - param_3) < param_8; iVar1 = iVar1 + 1) {
          (*param_1)(0x20,param_2,iVar1,param_4);
        }
      }
    }
  }
  else {
    iVar1 = _ftoa(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  return iVar1;
}


/* ===== _etoa @ 20007018 (208 bytes) ===== */

int _etoa(void)

{
  int iVar1;
  int in_r3;
  undefined4 uVar2;
  int unaff_r6;
  code *unaff_r11;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  int param_15;
  int param_16;
  uint param_18;
  int param_19;
  
  if (in_r3 != 0) {
    __aeabi_ddiv(param_11,param_12);
  }
  __wrap___aeabi_dcmplt(param_13,param_14,0,0);
  iVar1 = _ftoa();
  if (unaff_r6 != 0) {
    if (param_19 << 0x1a < 0) {
      uVar2 = 0x45;
    }
    else {
      uVar2 = 0x65;
    }
    (*unaff_r11)(uVar2);
    iVar1 = _ntoa_long();
    if (param_15 != 0) {
      for (; (uint)(iVar1 - param_16) < param_18; iVar1 = iVar1 + 1) {
        (*unaff_r11)(0x20);
      }
    }
  }
  return iVar1;
}


/* ===== _ftoa @ 2000716c (500 bytes) ===== */

void _ftoa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,uint param_7,uint param_8,uint param_9)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  char local_48 [36];
  
  uVar13 = CONCAT44(param_6,param_5);
  iVar2 = __wrap___aeabi_dcmpun(param_5,param_6);
  if (iVar2 == 0) {
    iVar2 = __wrap___aeabi_dcmplt(param_5,param_6,0xffffffff,DAT_20007498);
    if (iVar2 == 0) {
      iVar2 = __wrap___aeabi_dcmpgt(param_5,param_6,0xffffffff,DAT_2000749c);
      if (iVar2 == 0) {
        iVar2 = __wrap___aeabi_dcmpgt(param_5,param_6,0,DAT_200074a0);
        if ((iVar2 == 0) &&
           (iVar2 = __wrap___aeabi_dcmplt(param_5,param_6,0,DAT_200074a4), iVar2 == 0)) {
          iVar2 = __wrap___aeabi_dcmplt(param_5,param_6,0,0);
          bVar12 = iVar2 != 0;
          if (bVar12) {
            uVar13 = __wrap___aeabi_dsub(0,0,param_5,param_6);
          }
          param_6 = (undefined4)((ulonglong)uVar13 >> 0x20);
          param_5 = (undefined4)uVar13;
          if (-1 < (int)(param_9 << 0x15)) {
            param_7 = 6;
          }
          uVar10 = 0;
          for (; (uVar10 < 0x20 && (9 < param_7)); param_7 = param_7 - 1) {
            local_48[uVar10] = '0';
            uVar10 = uVar10 + 1;
          }
          iVar3 = __wrap___aeabi_d2iz__or__double2int_z(param_5,param_6);
          uVar13 = __wrap___aeabi_i2d();
          __wrap___aeabi_dsub(param_5,param_6,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
          puVar8 = (undefined4 *)(DAT_200074b8 + param_7 * 8);
          uVar6 = *puVar8;
          uVar9 = puVar8[1];
          uVar13 = __wrap___aeabi_dmul();
          uVar4 = __wrap___aeabi_d2uiz__or__double2uint();
          uVar14 = __wrap___aeabi_ui2d();
          uVar13 = __wrap___aeabi_dsub((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                                       (int)((ulonglong)uVar14 >> 0x20));
          uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
          iVar2 = __wrap___aeabi_dcmpgt((int)uVar13,uVar7,0,DAT_200074bc);
          if (iVar2 == 0) {
            iVar2 = __wrap___aeabi_dcmplt((int)uVar13,uVar7,0,DAT_200074bc);
            if ((iVar2 == 0) && ((uVar4 == 0 || ((int)(uVar4 << 0x1f) < 0)))) {
              uVar4 = uVar4 + 1;
            }
          }
          else {
            uVar4 = uVar4 + 1;
            uVar13 = __wrap___aeabi_ui2d(uVar4);
            iVar2 = __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                              (uVar6,uVar9,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
            if (iVar2 != 0) {
              iVar3 = iVar3 + 1;
              uVar4 = 0;
            }
          }
          if (param_7 == 0) {
            uVar13 = __wrap___aeabi_i2d(iVar3);
            uVar13 = __wrap___aeabi_dsub(param_5,param_6,(int)uVar13,
                                         (int)((ulonglong)uVar13 >> 0x20));
            uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
            iVar2 = __wrap___aeabi_dcmplt((int)uVar13,uVar7,0,DAT_200074bc);
            if (((iVar2 == 0) &&
                (iVar2 = __wrap___aeabi_dcmpgt((int)uVar13,uVar7,0,DAT_200074bc), iVar2 == 0)) &&
               (iVar3 << 0x1f < 0)) {
              iVar3 = iVar3 + 1;
            }
          }
          else {
            do {
              if (0x1f < uVar10) break;
              param_7 = param_7 - 1;
              __aeabi_uidiv(uVar4,10);
              uVar11 = uVar10 + 1;
              local_48[uVar10] = extraout_r1 + '0';
              uVar5 = __aeabi_uidiv(uVar4,10);
              bVar1 = 9 < uVar4;
              uVar10 = uVar11;
              uVar4 = uVar5;
            } while (bVar1);
            while ((uVar10 < 0x20 && (param_7 != 0))) {
              local_48[uVar10] = '0';
              uVar10 = uVar10 + 1;
              param_7 = param_7 - 1;
            }
            if (uVar10 < 0x20) {
              local_48[uVar10] = '.';
              uVar10 = uVar10 + 1;
            }
          }
          do {
            uVar4 = uVar10;
            if (0x1f < uVar10) break;
            __aeabi_idivmod(iVar3,10);
            uVar4 = uVar10 + 1;
            local_48[uVar10] = extraout_r1_00 + '0';
            iVar3 = __aeabi_idivmod(iVar3,10);
            uVar10 = uVar4;
          } while (iVar3 != 0);
          if ((param_9 & 3) == 1) {
            uVar10 = param_8;
            if ((param_8 != 0) && ((bVar12 || ((param_9 & 0xc) != 0)))) {
              param_8 = param_8 - 1;
              uVar10 = param_8;
            }
            for (; (uVar4 < uVar10 && (uVar4 < 0x20)); uVar4 = uVar4 + 1) {
              local_48[uVar4] = '0';
            }
          }
          if (uVar4 < 0x20) {
            if (bVar12) {
              local_48[uVar4] = '-';
              uVar4 = uVar4 + 1;
            }
            else if ((int)(param_9 << 0x1d) < 0) {
              local_48[uVar4] = '+';
              uVar4 = uVar4 + 1;
            }
            else if ((int)(param_9 << 0x1c) < 0) {
              local_48[uVar4] = ' ';
              uVar4 = uVar4 + 1;
            }
          }
          _out_rev(param_1,param_2,param_3,param_4,local_48,uVar4,param_8,param_9);
        }
        else {
          _etoa(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
        }
      }
      else {
        uVar7 = DAT_200074b4;
        if ((param_9 & 4) != 0) {
          uVar7 = DAT_200074b0;
        }
        if ((param_9 & 4) == 0) {
          uVar6 = 3;
        }
        else {
          uVar6 = 4;
        }
        _out_rev(param_1,param_2,param_3,param_4,uVar7,uVar6,param_8,param_9);
      }
    }
    else {
      _out_rev(param_1,param_2,param_3,param_4,DAT_200074ac,4,param_8,param_9);
    }
  }
  else {
    _out_rev(param_1,param_2,param_3,param_4,DAT_200074a8,3,param_8,param_9);
  }
  return;
}


/* ===== _vsnprintf @ 200071f2 (2 bytes) ===== */

void _vsnprintf(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int unaff_r8;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  uint in_stack_00000084;
  uint in_stack_00000088;
  
  uVar10 = 0;
  for (uVar12 = 6; (uVar10 < 0x20 && (9 < uVar12)); uVar12 = uVar12 - 1) {
    (&stack0x00000030)[uVar10] = 0x30;
    uVar10 = uVar10 + 1;
  }
  iVar2 = __wrap___aeabi_d2iz__or__double2int_z(in_stack_00000078,in_stack_0000007c);
  uVar13 = __wrap___aeabi_i2d();
  __wrap___aeabi_dsub(in_stack_00000078,in_stack_0000007c,(int)uVar13,
                      (int)((ulonglong)uVar13 >> 0x20));
  puVar8 = (undefined4 *)(DAT_200074b8 + uVar12 * 8);
  uVar7 = *puVar8;
  uVar9 = puVar8[1];
  uVar13 = __wrap___aeabi_dmul();
  uVar3 = __wrap___aeabi_d2uiz__or__double2uint();
  uVar14 = __wrap___aeabi_ui2d();
  uVar13 = __wrap___aeabi_dsub((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                               (int)((ulonglong)uVar14 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar13 >> 0x20);
  iVar4 = __wrap___aeabi_dcmpgt((int)uVar13,uVar6,0,DAT_200074bc);
  if (iVar4 == 0) {
    iVar4 = __wrap___aeabi_dcmplt((int)uVar13,uVar6,0,DAT_200074bc);
    if ((iVar4 == 0) && ((uVar3 == 0 || ((int)(uVar3 << 0x1f) < 0)))) {
      uVar3 = uVar3 + 1;
    }
  }
  else {
    uVar3 = uVar3 + 1;
    uVar13 = __wrap___aeabi_ui2d(uVar3);
    iVar4 = __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                      (uVar7,uVar9,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
    if (iVar4 != 0) {
      iVar2 = iVar2 + 1;
      uVar3 = 0;
    }
  }
  if (uVar12 == 0) {
    uVar13 = __wrap___aeabi_i2d(iVar2);
    uVar13 = __wrap___aeabi_dsub(in_stack_00000078,in_stack_0000007c,(int)uVar13,
                                 (int)((ulonglong)uVar13 >> 0x20));
    uVar6 = (undefined4)((ulonglong)uVar13 >> 0x20);
    iVar4 = __wrap___aeabi_dcmplt((int)uVar13,uVar6,0,DAT_200074bc);
    if (((iVar4 == 0) &&
        (iVar4 = __wrap___aeabi_dcmpgt((int)uVar13,uVar6,0,DAT_200074bc), iVar4 == 0)) &&
       (iVar2 << 0x1f < 0)) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    do {
      if (0x1f < uVar10) break;
      uVar12 = uVar12 - 1;
      __aeabi_uidiv(uVar3,10);
      uVar11 = uVar10 + 1;
      (&stack0x00000030)[uVar10] = extraout_r1 + '0';
      uVar5 = __aeabi_uidiv(uVar3,10);
      bVar1 = 9 < uVar3;
      uVar10 = uVar11;
      uVar3 = uVar5;
    } while (bVar1);
    while ((uVar10 < 0x20 && (uVar12 != 0))) {
      (&stack0x00000030)[uVar10] = 0x30;
      uVar10 = uVar10 + 1;
      uVar12 = uVar12 - 1;
    }
    if (uVar10 < 0x20) {
      (&stack0x00000030)[uVar10] = 0x2e;
      uVar10 = uVar10 + 1;
    }
  }
  do {
    uVar12 = uVar10;
    if (0x1f < uVar10) break;
    __aeabi_idivmod(iVar2,10);
    uVar12 = uVar10 + 1;
    (&stack0x00000030)[uVar10] = extraout_r1_00 + '0';
    iVar2 = __aeabi_idivmod(iVar2,10);
    uVar10 = uVar12;
  } while (iVar2 != 0);
  if ((in_stack_00000088 & 3) == 1) {
    uVar10 = in_stack_00000084;
    if ((in_stack_00000084 != 0) && ((unaff_r8 != 0 || ((in_stack_00000088 & 0xc) != 0)))) {
      in_stack_00000084 = in_stack_00000084 - 1;
      uVar10 = in_stack_00000084;
    }
    for (; (uVar12 < uVar10 && (uVar12 < 0x20)); uVar12 = uVar12 + 1) {
      (&stack0x00000030)[uVar12] = 0x30;
    }
  }
  if (uVar12 < 0x20) {
    if (unaff_r8 == 0) {
      if ((int)(in_stack_00000088 << 0x1d) < 0) {
        (&stack0x00000030)[uVar12] = 0x2b;
      }
      else if ((int)(in_stack_00000088 << 0x1c) < 0) {
        (&stack0x00000030)[uVar12] = 0x20;
      }
    }
    else {
      (&stack0x00000030)[uVar12] = 0x2d;
    }
  }
  _out_rev(in_stack_00000018,in_stack_0000001c);
  return;
}


/* ===== _vsnprintf @ 20007362 (310 bytes) ===== */

void _vsnprintf(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char extraout_r1;
  char extraout_r1_00;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int unaff_r8;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  uint in_stack_00000084;
  uint in_stack_00000088;
  
  uVar10 = 0;
  for (uVar12 = 6; (uVar10 < 0x20 && (9 < uVar12)); uVar12 = uVar12 - 1) {
    (&stack0x00000030)[uVar10] = 0x30;
    uVar10 = uVar10 + 1;
  }
  iVar2 = __wrap___aeabi_d2iz__or__double2int_z(in_stack_00000078,in_stack_0000007c);
  uVar13 = __wrap___aeabi_i2d();
  __wrap___aeabi_dsub(in_stack_00000078,in_stack_0000007c,(int)uVar13,
                      (int)((ulonglong)uVar13 >> 0x20));
  puVar8 = (undefined4 *)(DAT_200074b8 + uVar12 * 8);
  uVar7 = *puVar8;
  uVar9 = puVar8[1];
  uVar13 = __wrap___aeabi_dmul();
  uVar3 = __wrap___aeabi_d2uiz__or__double2uint();
  uVar14 = __wrap___aeabi_ui2d();
  uVar13 = __wrap___aeabi_dsub((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                               (int)((ulonglong)uVar14 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar13 >> 0x20);
  iVar4 = __wrap___aeabi_dcmpgt((int)uVar13,uVar6,0,DAT_200074bc);
  if (iVar4 == 0) {
    iVar4 = __wrap___aeabi_dcmplt((int)uVar13,uVar6,0,DAT_200074bc);
    if ((iVar4 == 0) && ((uVar3 == 0 || ((int)(uVar3 << 0x1f) < 0)))) {
      uVar3 = uVar3 + 1;
    }
  }
  else {
    uVar3 = uVar3 + 1;
    uVar13 = __wrap___aeabi_ui2d(uVar3);
    iVar4 = __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple
                      (uVar7,uVar9,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
    if (iVar4 != 0) {
      iVar2 = iVar2 + 1;
      uVar3 = 0;
    }
  }
  if (uVar12 == 0) {
    uVar13 = __wrap___aeabi_i2d(iVar2);
    uVar13 = __wrap___aeabi_dsub(in_stack_00000078,in_stack_0000007c,(int)uVar13,
                                 (int)((ulonglong)uVar13 >> 0x20));
    uVar6 = (undefined4)((ulonglong)uVar13 >> 0x20);
    iVar4 = __wrap___aeabi_dcmplt((int)uVar13,uVar6,0,DAT_200074bc);
    if (((iVar4 == 0) &&
        (iVar4 = __wrap___aeabi_dcmpgt((int)uVar13,uVar6,0,DAT_200074bc), iVar4 == 0)) &&
       (iVar2 << 0x1f < 0)) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    do {
      if (0x1f < uVar10) break;
      uVar12 = uVar12 - 1;
      __aeabi_uidiv(uVar3,10);
      uVar11 = uVar10 + 1;
      (&stack0x00000030)[uVar10] = extraout_r1 + '0';
      uVar5 = __aeabi_uidiv(uVar3,10);
      bVar1 = 9 < uVar3;
      uVar10 = uVar11;
      uVar3 = uVar5;
    } while (bVar1);
    while ((uVar10 < 0x20 && (uVar12 != 0))) {
      (&stack0x00000030)[uVar10] = 0x30;
      uVar10 = uVar10 + 1;
      uVar12 = uVar12 - 1;
    }
    if (uVar10 < 0x20) {
      (&stack0x00000030)[uVar10] = 0x2e;
      uVar10 = uVar10 + 1;
    }
  }
  do {
    uVar12 = uVar10;
    if (0x1f < uVar10) break;
    __aeabi_idivmod(iVar2,10);
    uVar12 = uVar10 + 1;
    (&stack0x00000030)[uVar10] = extraout_r1_00 + '0';
    iVar2 = __aeabi_idivmod(iVar2,10);
    uVar10 = uVar12;
  } while (iVar2 != 0);
  if ((in_stack_00000088 & 3) == 1) {
    uVar10 = in_stack_00000084;
    if ((in_stack_00000084 != 0) && ((unaff_r8 != 0 || ((in_stack_00000088 & 0xc) != 0)))) {
      in_stack_00000084 = in_stack_00000084 - 1;
      uVar10 = in_stack_00000084;
    }
    for (; (uVar12 < uVar10 && (uVar12 < 0x20)); uVar12 = uVar12 + 1) {
      (&stack0x00000030)[uVar12] = 0x30;
    }
  }
  if (uVar12 < 0x20) {
    if (unaff_r8 == 0) {
      if ((int)(in_stack_00000088 << 0x1d) < 0) {
        (&stack0x00000030)[uVar12] = 0x2b;
      }
      else if ((int)(in_stack_00000088 << 0x1c) < 0) {
        (&stack0x00000030)[uVar12] = 0x20;
      }
    }
    else {
      (&stack0x00000030)[uVar12] = 0x2d;
    }
  }
  _out_rev(in_stack_00000018,in_stack_0000001c);
  return;
}


/* ===== _vsnprintf @ 200074c0 (342 bytes) ===== */

uint _vsnprintf(code *param_1,int param_2,uint param_3,byte *param_4,uint *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *local_2c [2];
  
  if (param_2 == 0) {
    param_1 = DAT_20007ae0;
  }
  uVar3 = 0;
  local_2c[0] = param_4;
  while( true ) {
    while( true ) {
      bVar1 = *local_2c[0];
      if (bVar1 == 0) {
        uVar2 = uVar3;
        if (param_3 <= uVar3) {
          uVar2 = param_3 - 1;
        }
        (*param_1)(0,param_2,uVar2,param_3);
        return uVar3;
      }
      if (bVar1 == 0x25) break;
      (*param_1)(bVar1,param_2,uVar3,param_3);
      local_2c[0] = local_2c[0] + 1;
      uVar3 = uVar3 + 1;
    }
    pbVar5 = local_2c[0] + 1;
    bVar1 = *pbVar5;
    uVar2 = (uint)(byte)(bVar1 - 0x20);
    if (uVar2 < 0x11) break;
    if ((byte)(bVar1 - 0x30) < 10) {
      local_2c[0] = pbVar5;
      uVar2 = _atoi(local_2c);
      pbVar5 = local_2c[0];
    }
    else if (bVar1 == 0x2a) {
      uVar2 = *param_5;
      param_5 = param_5 + 1;
      pbVar5 = local_2c[0] + 2;
    }
    local_2c[0] = pbVar5;
    pbVar5 = local_2c[0];
    if (*local_2c[0] == 0x2e) {
      if ((byte)(local_2c[0][1] - 0x30) < 10) {
        local_2c[0] = local_2c[0] + 1;
        uVar2 = _atoi(local_2c);
        pbVar5 = local_2c[0];
      }
      else {
        pbVar5 = local_2c[0] + 1;
        if (local_2c[0][1] == 0x2a) {
          uVar2 = *param_5;
          if ((int)uVar2 < 0) {
            uVar2 = 0;
          }
          param_5 = param_5 + 1;
          pbVar5 = local_2c[0] + 2;
        }
      }
    }
    local_2c[0] = pbVar5;
    uVar4 = *local_2c[0] - 0x68 & 0xff;
    if (uVar4 < 0x13) {
                    /* WARNING: Could not recover jumptable at 0x2000754e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(DAT_20007860 + uVar4 * 4))(uVar2);
      return uVar3;
    }
    uVar2 = (uint)(byte)(*local_2c[0] - 0x25);
    if (uVar2 < 0x54) {
                    /* WARNING: Could not recover jumptable at 0x2000764c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(DAT_20007864 + uVar2 * 4))();
      return uVar3;
    }
    (*param_1)(*local_2c[0],param_2,uVar3,param_3);
    local_2c[0] = local_2c[0] + 1;
    uVar3 = uVar3 + 1;
  }
  local_2c[0] = pbVar5;
                    /* WARNING: Could not recover jumptable at 0x2000751c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(DAT_2000785c + uVar2 * 4))();
  return uVar3;
}


/* ===== vfctprintf @ 20007ae4 (28 bytes) ===== */

void vfctprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_1;
  local_c = param_2;
  _vsnprintf(DAT_20007b00,&local_10,0xffffffff,param_3,param_4);
  return;
}


/* ===== __aeabi_bits_init__or____aeabi_mem_init @ 20007b04 (8 bytes) ===== */

void __aeabi_bits_init__or____aeabi_mem_init(void)

{
                    /* WARNING: Could not recover jumptable at 0x20007b0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20007b10)(DAT_20007b0c,4);
  return;
}


/* ===== rom_func_lookup @ 20007b14 (16 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rom_func_lookup(undefined4 param_1)

{
  (*(code *)(uint)_UsageFault)(_BusFault,param_1);
  return;
}


/* ===== rom_data_lookup @ 20007b24 (16 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rom_data_lookup(undefined4 param_1)

{
  (*(code *)(uint)_UsageFault)(_DAT_00000016,param_1);
  return;
}


/* ===== rom_funcs_lookup @ 20007b34 (54 bytes) ===== */

undefined4 rom_funcs_lookup(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 1) {
    piVar2 = (int *)(param_1 + uVar3 * 4);
    iVar1 = rom_func_lookup(*piVar2);
    *piVar2 = iVar1;
    if (iVar1 == 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}


/* ===== __aeabi_idivmod @ 20007b6c (32 bytes) ===== */

ulonglong __aeabi_idivmod(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  
  iVar2 = DAT_20007bb8;
  if ((*(uint *)(DAT_20007bb8 + 0x78) >> 1 & 1) != 0) {
    uVar3 = *(undefined4 *)(DAT_20007bb8 + 0x60);
    uVar4 = *(undefined4 *)(DAT_20007bb8 + 100);
    uVar6 = *(undefined4 *)(DAT_20007bb8 + 0x74);
    uVar5 = *(undefined4 *)(DAT_20007bb8 + 0x70);
    uVar7 = divmod_s32s32_unsafe();
    *(undefined4 *)(iVar2 + 0x60) = uVar3;
    *(undefined4 *)(iVar2 + 100) = uVar4;
    *(undefined4 *)(iVar2 + 0x74) = uVar6;
    *(undefined4 *)(iVar2 + 0x70) = uVar5;
    return uVar7;
  }
  *(uint *)(DAT_20007bb8 + 0x68) = param_1;
  *(int *)(iVar2 + 0x6c) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(iVar2 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = ~((int)param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar1 = __aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== divmod_s32s32_unsafe @ 20007b74 (44 bytes) ===== */

ulonglong divmod_s32s32_unsafe(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  
  *(uint *)(param_3 + 0x68) = param_1;
  *(int *)(param_3 + 0x6c) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = ~((int)param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar1 = __aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== __aeabi_uidiv @ 20007bbc (32 bytes) ===== */

ulonglong __aeabi_uidiv(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  
  iVar2 = DAT_20007c04;
  if ((*(uint *)(DAT_20007c04 + 0x78) >> 1 & 1) != 0) {
    uVar3 = *(undefined4 *)(DAT_20007c04 + 0x60);
    uVar4 = *(undefined4 *)(DAT_20007c04 + 100);
    uVar6 = *(undefined4 *)(DAT_20007c04 + 0x74);
    uVar5 = *(undefined4 *)(DAT_20007c04 + 0x70);
    uVar7 = divmod_u32u32_unsafe();
    *(undefined4 *)(iVar2 + 0x60) = uVar3;
    *(undefined4 *)(iVar2 + 100) = uVar4;
    *(undefined4 *)(iVar2 + 0x74) = uVar6;
    *(undefined4 *)(iVar2 + 0x70) = uVar5;
    return uVar7;
  }
  *(int *)(DAT_20007c04 + 0x60) = param_1;
  *(int *)(iVar2 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(iVar2 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  uVar1 = __aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== divmod_u32u32_unsafe @ 20007bc4 (38 bytes) ===== */

ulonglong divmod_u32u32_unsafe(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  *(int *)(param_3 + 0x60) = param_1;
  *(int *)(param_3 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  uVar1 = __aeabi_idiv0(param_1);
  return (ulonglong)uVar1;
}


/* ===== __aeabi_uldivmod @ 20007c40 (52 bytes) ===== */

void __aeabi_uldivmod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(uint *)(DAT_20007d44 + 0x78) >> 1 & 1) != 0) {
    do {
    } while ((*(uint *)(DAT_20007d44 + 0x78) & 1) == 0);
    uVar2 = *(undefined4 *)(DAT_20007d44 + 0x60);
    uVar3 = *(undefined4 *)(DAT_20007d44 + 100);
    uVar5 = *(undefined4 *)(DAT_20007d44 + 0x74);
    uVar4 = *(undefined4 *)(DAT_20007d44 + 0x70);
    divmod_u64u64_unsafe(param_1,param_2,param_3);
    iVar1 = DAT_20007d44;
    *(undefined4 *)(DAT_20007d44 + 0x60) = uVar2;
    *(undefined4 *)(iVar1 + 100) = uVar3;
    *(undefined4 *)(iVar1 + 0x74) = uVar5;
    *(undefined4 *)(iVar1 + 0x70) = uVar4;
    return;
  }
  divmod_u64u64_unsafe(param_1,param_2,param_3);
  return;
}


/* ===== divmod_u64u64_unsafe @ 20007d00 (796 bytes) ===== */

ulonglong divmod_u64u64_unsafe(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  ulonglong uVar16;
  
  iVar2 = DAT_20008034;
  iVar1 = DAT_20007e68;
  iVar6 = DAT_20007da4;
  iVar7 = DAT_20007d44;
  if (param_2 == 0) {
    if (param_4 != 0) {
      return 0;
    }
    if (param_3 != 0) {
      *(uint *)(DAT_20007d44 + 0x60) = param_1;
      *(uint *)(iVar7 + 100) = param_3;
      return (ulonglong)*(uint *)(iVar7 + 0x70);
    }
    uVar8 = 0;
    if (param_1 == 0) goto LAB_20007d2e;
  }
  else {
    if (param_4 != 0) {
      if (param_4 >> 0x10 != 0) {
        uVar8 = 0;
        if (param_4 + 1 != 0) {
          *(uint *)(DAT_20008034 + 100) = param_4 + 1;
          *(uint *)(iVar2 + 0x60) = param_2;
          uVar8 = *(uint *)(iVar2 + 0x70);
        }
        uVar9 = uVar8 * (param_3 & 0xffff);
        uVar5 = param_1 - uVar9;
        uVar10 = uVar8 * (param_3 >> 0x10);
        uVar9 = (((param_2 - uVar8 * (param_4 & 0xffff)) - (uint)(param_1 < uVar9)) -
                (uVar8 * (param_4 >> 0x10) * 0x10000 | uVar10 >> 0x10)) -
                (uint)(uVar5 < uVar10 * 0x10000);
        for (uVar5 = uVar5 + uVar10 * -0x10000;
            (param_4 <= uVar9 && ((uVar9 != param_4 || (param_3 <= uVar5))));
            uVar5 = uVar5 - param_3) {
          uVar9 = (uVar9 - param_4) - (uint)(uVar5 < param_3);
          uVar8 = uVar8 + 1;
        }
        return (ulonglong)uVar8;
      }
      uVar9 = 0;
      uVar8 = param_3;
      uVar5 = param_4;
      if (param_4 >> 8 == 0) {
        uVar5 = param_4 << 8 | param_3 >> 0x18;
        uVar8 = param_3 << 8;
        uVar9 = 8;
      }
      if (uVar5 >> 0xc == 0) {
        uVar5 = uVar5 << 4 | uVar8 >> 0x1c;
        uVar8 = uVar8 << 4;
        uVar9 = uVar9 + 4;
      }
      if (uVar5 >> 0xe == 0) {
        uVar5 = uVar5 << 2 | uVar8 >> 0x1e;
        uVar8 = uVar8 << 2;
        uVar9 = uVar9 + 2;
      }
      if (uVar5 >> 0xf == 0) {
        bVar14 = CARRY4(uVar8,uVar8);
        uVar8 = uVar8 * 2;
        uVar5 = uVar5 * 2 + (uint)bVar14;
        uVar9 = uVar9 + 1;
      }
      *(uint *)(DAT_20008034 + 100) = uVar5 * 2 + (uint)CARRY4(uVar8,uVar8) + 1;
      *(undefined4 *)(iVar2 + 0x60) = DAT_20008038;
      iVar7 = *(int *)(iVar2 + 0x70);
      uVar10 = iVar7 * (param_2 >> 0x10) >> 0x10;
      uVar11 = uVar10 * (uVar8 & 0xffff);
      if (param_1 < uVar11) {
        param_2 = param_2 - 1;
      }
      uVar3 = (param_1 - uVar11) - uVar11;
      if (param_1 - uVar11 < uVar11) {
        param_2 = param_2 - 1;
      }
      uVar12 = uVar10 * (uVar8 >> 0x10);
      uVar11 = uVar3 + uVar12 * -0x20000;
      uVar3 = ((param_2 + uVar10 * (uVar5 & 0xffff) * -2) - (uVar12 >> 0xf)) -
              (uint)(uVar3 < uVar12 * 0x20000);
      uVar12 = iVar7 * (uVar3 >> 3) >> 0x10;
      if (uVar9 < 0xc) {
        uVar8 = uVar12 >> (0xc - uVar9 & 0xff);
        iVar7 = (uVar10 << uVar9) * 2;
      }
      else {
        uVar13 = uVar12 * (uVar8 >> 0xc & 0xffff);
        uVar4 = uVar11 - uVar13;
        if (uVar11 < uVar13) {
          uVar3 = uVar3 - 1;
        }
        uVar8 = uVar12 * ((uVar8 >> 0xc | uVar5 << 0x14) >> 0x10);
        uVar11 = uVar4 + uVar8 * -0x10000;
        uVar3 = ((uVar3 - uVar12 * (uVar5 >> 0xc & 0xffff)) - (uVar8 >> 0x10)) -
                (uint)(uVar4 < uVar8 * 0x10000);
        uVar8 = iVar7 * (uVar11 >> 0x16 | uVar3 * 0x400) >> (0x29 - uVar9 & 0xff);
        iVar7 = uVar10 * 0x2000 + uVar12 << (uVar9 - 0xc & 0xff);
      }
      uVar10 = uVar8 * (param_3 & 0xffff);
      uVar5 = uVar11 - uVar10;
      uVar12 = uVar8 * (param_3 >> 0x10);
      uVar9 = uVar5 + uVar12 * -0x10000;
      uVar5 = (((uVar3 - uVar8 * (param_4 & 0xffff)) - (uint)(uVar11 < uVar10)) - (uVar12 >> 0x10))
              - (uint)(uVar5 < uVar12 * 0x10000);
      uVar8 = iVar7 + uVar8;
      do {
        uVar11 = uVar8;
        bVar15 = param_3 <= uVar9;
        uVar9 = uVar9 - param_3;
        uVar10 = uVar5 - param_4;
        bVar14 = param_4 < uVar5;
        uVar5 = (uVar5 - param_4) - (uint)!bVar15;
        uVar8 = uVar11 + 1;
      } while (bVar14 || uVar10 < bVar15);
      return (ulonglong)uVar11;
    }
    if (param_3 >> 0x10 != 0) {
      uVar5 = 0;
      uVar8 = param_3;
      if (param_3 >> 0x18 == 0) {
        uVar8 = param_3 << 8;
        uVar5 = 8;
      }
      if (uVar8 >> 0x1c == 0) {
        uVar8 = uVar8 << 4;
        uVar5 = uVar5 + 4;
      }
      if (uVar8 >> 0x1e == 0) {
        uVar8 = uVar8 << 2;
        uVar5 = uVar5 + 2;
      }
      if (-1 < (int)uVar8) {
        uVar8 = uVar8 << 1;
        uVar5 = uVar5 + 1;
      }
      *(uint *)(DAT_20007e68 + 100) = (uVar8 >> 0xf) + 1;
      *(undefined4 *)(iVar1 + 0x60) = DAT_20007e6c;
      iVar6 = *(int *)(iVar1 + 0x70);
      uVar11 = iVar6 * (param_2 >> 0x10) >> 0x10;
      uVar10 = uVar11 * (uVar8 & 0xffff);
      uVar9 = param_1 + uVar10 * -0x20000;
      uVar12 = ((param_2 - (uVar10 >> 0xf)) - (uint)(param_1 < uVar10 * 0x20000)) +
               uVar11 * (uVar8 >> 0x10) * -2;
      uVar13 = iVar6 * (uVar12 >> 3) >> 0x10;
      uVar3 = uVar11 * 0x2000 + uVar13;
      uVar4 = uVar13 * (uVar8 & 0xffff);
      uVar10 = uVar9 + uVar4 * -0x10;
      uVar13 = uVar13 * (uVar8 >> 0x10);
      uVar11 = uVar10 + uVar13 * -0x100000;
      iVar7 = (((uVar12 - (uVar4 >> 0x1c)) - (uint)(uVar9 < uVar4 * 0x10)) - (uVar13 >> 0xc)) -
              (uint)(uVar10 < uVar13 * 0x100000);
      uVar9 = iVar6 * (uVar11 >> 0x16 | iVar7 * 0x400) >> 0x10;
      if (8 < uVar5) {
        uVar11 = uVar11 - uVar9 * (uVar8 >> 9);
        uVar8 = -uVar5 + 0x16;
        uVar10 = (iVar6 * (uVar11 >> 9) >> 0x10) >> (uVar8 & 0xff);
        uVar9 = ((uVar9 << 0xd) >> (uVar8 & 0xff)) + uVar10;
        uVar11 = uVar11 - param_3 * uVar10;
        uVar8 = uVar3 >> (-uVar5 + 0x1c & 0xff);
        uVar3 = uVar3 << uVar5 + 4;
        iVar7 = uVar3 + uVar9;
        if (CARRY4(uVar3,uVar9) == false) goto LAB_20007e5e;
        do {
          uVar8 = uVar8 + 1;
LAB_20007e5e:
          do {
            if (uVar11 < param_3) {
              return CONCAT44(uVar8,iVar7);
            }
            uVar11 = uVar11 - param_3;
            bVar14 = iVar7 != -1;
            iVar7 = iVar7 + 1;
          } while (bVar14);
        } while( true );
      }
      uVar9 = uVar9 >> (-uVar5 + 9 & 0xff);
      uVar10 = uVar9 * (param_3 & 0xffff);
      uVar8 = uVar11 - uVar10;
      if (uVar11 < uVar10) {
        iVar7 = iVar7 + -1;
      }
      uVar10 = uVar9 * (param_3 >> 0x10);
      uVar11 = uVar8 + uVar10 * -0x10000;
      iVar6 = (iVar7 - (uVar10 >> 0x10)) - (uint)(uVar8 < uVar10 * 0x10000);
      uVar8 = uVar3 >> (-uVar5 + 0x1c & 0xff);
      uVar3 = uVar3 << uVar5 + 4;
      iVar7 = uVar3 + uVar9;
      if (CARRY4(uVar3,uVar9) != false) {
        uVar8 = uVar8 + 1;
      }
      if (iVar6 == 0) {
        if (uVar11 < param_3) {
          return CONCAT44(uVar8,iVar7);
        }
        do {
          bVar14 = iVar7 == -1;
          iVar7 = iVar7 + 1;
          if (bVar14) {
            uVar8 = uVar8 + 1;
          }
          uVar11 = uVar11 - param_3;
LAB_20007ec2:
        } while (param_3 <= uVar11);
        return CONCAT44(uVar8,iVar7);
      }
      do {
        bVar14 = iVar7 == -1;
        iVar7 = iVar7 + 1;
        if (bVar14) {
          uVar8 = uVar8 + 1;
        }
        bVar14 = uVar11 < param_3;
        uVar11 = uVar11 - param_3;
        if ((bVar14) && (iVar6 = iVar6 + -1, iVar6 == 0)) goto LAB_20007ec2;
      } while( true );
    }
    if (param_3 != 0) {
      *(uint *)(DAT_20007da4 + 0x60) = param_2;
      *(uint *)(iVar6 + 100) = param_3;
      *(uint *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x74) << 0x10 | param_1 >> 0x10;
      *(uint *)(iVar6 + 100) = param_3;
      *(uint *)(iVar6 + 0x60) = *(int *)(iVar6 + 0x74) << 0x10 | param_1 & 0xffff;
      *(uint *)(iVar6 + 100) = param_3;
      uVar8 = *(uint *)(iVar6 + 0x70) * 0x10000;
      return CONCAT44(*(int *)(iVar6 + 0x70) + (*(uint *)(iVar6 + 0x70) >> 0x10) +
                      (uint)CARRY4(*(uint *)(iVar6 + 0x70),uVar8),*(uint *)(iVar6 + 0x70) + uVar8);
    }
  }
  param_1 = DAT_20007d48;
  uVar8 = DAT_20007d48;
LAB_20007d2e:
  uVar16 = __aeabi_idiv0(param_1,uVar8);
  return uVar16;
}


/* ===== __wrap___aeabi_dsub @ 20008042 (12 bytes) ===== */

void __wrap___aeabi_dsub(void)

{
  return;
}


/* ===== __wrap___aeabi_dadd @ 20008054 (12 bytes) ===== */

void __wrap___aeabi_dadd(void)

{
  return;
}


/* ===== __aeabi_ddiv @ 20008066 (42 bytes) ===== */

void __aeabi_ddiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(uint *)(DAT_200080b8 + 0x78) >> 1 & 1) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(DAT_200080b8 + 0x60);
  uVar3 = *(undefined4 *)(DAT_200080b8 + 100);
  uVar5 = *(undefined4 *)(DAT_200080b8 + 0x74);
  uVar4 = *(undefined4 *)(DAT_200080b8 + 0x70);
  double_shim_helper(param_1,param_2,param_3);
  iVar1 = DAT_200080b8;
  *(undefined4 *)(DAT_200080b8 + 0x60) = uVar2;
  *(undefined4 *)(iVar1 + 100) = uVar3;
  *(undefined4 *)(iVar1 + 0x74) = uVar5;
  *(undefined4 *)(iVar1 + 0x70) = uVar4;
  return;
}


/* ===== double_shim_helper @ 20008072 (12 bytes) ===== */

void double_shim_helper(void)

{
  return;
}


/* ===== __wrap___aeabi_dmul @ 200080a2 (12 bytes) ===== */

void __wrap___aeabi_dmul(void)

{
  return;
}


/* ===== __wrap___aeabi_cdrcmple @ 200080bc (16 bytes) ===== */

undefined8 __wrap___aeabi_cdrcmple(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_4 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_200080de:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == DAT_20008124) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_20008108;
    goto LAB_200080de;
  }
  uVar3 = (param_2 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_200080f2:
    uVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    uVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == DAT_20008124) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_20008108;
      goto LAB_200080f2;
    }
  }
  if ((int)(uVar2 ^ param_4) < 0) {
    if (((uVar2 ^ param_4 | param_4) * 2 | param_3 | uVar1) != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)uVar2) && (param_4 == uVar2)) {
    return CONCAT44(param_2,param_1);
  }
LAB_20008108:
  return CONCAT44(param_2,param_1);
}


/* ===== __wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple @ 200080cc (86 bytes) ===== */

undefined8
__wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple
          (uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_200080de:
    uVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    uVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == DAT_20008124) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_20008108;
      goto LAB_200080de;
    }
  }
  uVar3 = (param_4 << 1) >> 0x15;
  if (uVar3 == 0) {
LAB_200080f2:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == DAT_20008124) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_20008108;
    goto LAB_200080f2;
  }
  if ((int)(param_4 ^ uVar2) < 0) {
    if (((param_4 ^ uVar2 | uVar2) * 2 | uVar1 | param_3) != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)param_4) && (uVar2 == param_4)) {
    return CONCAT44(param_2,param_1);
  }
LAB_20008108:
  return CONCAT44(param_2,param_1);
}


/* ===== __wrap___aeabi_dcmplt @ 20008128 (10 bytes) ===== */

int __wrap___aeabi_dcmplt(void)

{
  undefined in_CY;
  
  __wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple();
  return -(uint)!(bool)in_CY;
}


/* ===== __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple @ 20008134 (16 bytes) ===== */

undefined4 __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  __wrap___aeabi_cdcmpeq__or____wrap___aeabi_cdcmple();
  if ((bool)in_CY && !(bool)in_ZR) {
    return 0;
  }
  return 1;
}


/* ===== __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple @ 20008144 (16 bytes) ===== */

undefined4 __wrap___aeabi_dcmpge__or____wrap___aeabi_dcmple(void)

{
  undefined in_ZR;
  undefined in_CY;
  
  __wrap___aeabi_cdrcmple();
  if ((bool)in_CY && !(bool)in_ZR) {
    return 0;
  }
  return 1;
}


/* ===== __wrap___aeabi_dcmpgt @ 20008154 (10 bytes) ===== */

int __wrap___aeabi_dcmpgt(void)

{
  undefined in_CY;
  
  __wrap___aeabi_cdrcmple();
  return -(uint)!(bool)in_CY;
}


/* ===== __wrap___aeabi_dcmpun @ 2000815e (24 bytes) ===== */

undefined4 __wrap___aeabi_dcmpun(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if (((uint)(param_2 * 2) < 0xffe00001) && ((uint)(param_4 * 2) < 0xffe00001)) {
    return 0;
  }
  return 1;
}


/* ===== __wrap___aeabi_ui2d @ 2000817c (8 bytes) ===== */

undefined8 __wrap___aeabi_ui2d(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (**DAT_200081ac)();
  uVar2 = param_1 << (iVar1 + 1U & 0xff);
  return CONCAT44((DAT_200081b0 - (iVar1 + 1U)) * 0x100000 | uVar2 >> 0xc,uVar2 << 0x14);
}


/* ===== __wrap___aeabi_i2d @ 20008184 (40 bytes) ===== */

longlong __wrap___aeabi_i2d(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = (param_1 ^ uVar3) - uVar3;
  if (iVar1 != 0) {
    iVar2 = (**DAT_200081ac)();
    uVar4 = iVar1 << (iVar2 + 1U & 0xff);
    return CONCAT44((DAT_200081b0 - (iVar2 + 1U)) * 0x100000 | uVar3 << 0x1f | uVar4 >> 0xc,
                    uVar4 << 0x14);
  }
  return (ulonglong)uVar3 << 0x20;
}


/* ===== __wrap___aeabi_d2iz__or__double2int_z @ 200081b4 (72 bytes) ===== */

int __wrap___aeabi_d2iz__or__double2int_z(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)(param_2 << 1) >> 0x15;
  iVar3 = uVar2 - 0x380;
  if (iVar3 < 0x7f) {
    return 0;
  }
  if (iVar3 < 0x9e) {
    uVar2 = -(uVar2 - 0x41e);
    uVar1 = ((uint)(param_2 << 0xc) >> 1 | 0x80000000) >> (uVar2 & 0xff);
    iVar3 = (param_2 >> 0x1f) * 2 + 1;
    uVar2 = uVar2 + 0x15;
    if ((int)uVar2 < 0x20) {
      return iVar3 * (param_1 >> (uVar2 & 0xff) | uVar1);
    }
    return iVar3 * uVar1;
  }
  return 0x7fffffff - (param_2 >> 0x1f);
}


/* ===== __wrap___aeabi_d2uiz__or__double2uint @ 200081fc (12 bytes) ===== */

void __wrap___aeabi_d2uiz__or__double2uint(void)

{
  return;
}


/* ===== __aeabi_double_init @ 20008214 (144 bytes) ===== */

void __aeabi_double_init(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = DAT_00000013;
  if (DAT_00000013 == 1) {
    for (uVar4 = 0; uVar4 < 0x20; uVar4 = uVar4 + 1) {
      *(undefined4 *)(uVar4 * 4 + DAT_200082a8) = DAT_200082a4;
    }
  }
  if (1 < bVar1) {
    uVar2 = rom_data_lookup(DAT_200082b4);
    iVar3 = rom_data_lookup(DAT_200082b8);
    if ((uint)*(byte *)(iVar3 + -2) * 4 < 0x80) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_200082d8,0x32,DAT_200082d4,DAT_200082d0);
    }
    memcpy(DAT_200082a8,uVar2,0x80);
    if ((bVar1 == 2) &&
       (((*DAT_200082bc != -0x4b00 || (*DAT_200082c0 != DAT_200082c4)) ||
        (*DAT_200082c8 != DAT_200082cc)))) {
                    /* WARNING: Subroutine does not return */
      panic(0);
    }
  }
  if (bVar1 < 3) {
    *(undefined4 *)(DAT_200082a8 + 0x48) = DAT_200082a4;
  }
  uVar2 = rom_func_lookup(DAT_200082ac);
  *DAT_200082b0 = uVar2;
  return;
}


/* ===== double_table_shim_on_use_helper @ 200082dc (46 bytes) ===== */

undefined8 double_table_shim_on_use_helper(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *in_r12;
  
  if (in_r12 == (undefined4 *)0x0) {
    software_bkpt(0);
  }
  do {
    uVar1 = *(ushort *)in_r12;
    in_r12 = (undefined4 *)((int)in_r12 + 2);
  } while (uVar1 >> 8 != 0xdf);
  if (((uint)in_r12 >> 1 & 1) == 0) {
    uVar2 = *in_r12;
  }
  else {
    uVar2 = *in_r12;
  }
  *(undefined4 *)(DAT_2000830c + (uint)(byte)uVar1) = uVar2;
  return CONCAT44(param_2,param_1);
}


/* ===== dsub_shim @ 20008316 (352 bytes) ===== */

longlong dsub_shim(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  param_4 = param_4 ^ 0x80000000;
  uVar5 = param_2 >> 0x14;
  uVar2 = param_2 + (uVar5 - 1) * -0x100000;
  if ((uVar5 & 0x800) != 0) {
    uVar2 = ~uVar2;
    bVar10 = param_1 == 0;
    param_1 = -param_1;
    if (bVar10) {
      uVar2 = uVar2 + 1;
    }
  }
  uVar5 = uVar5 & 0x7ff;
  if (uVar5 == 0) {
LAB_20008344:
    param_1 = 0;
    uVar2 = (((int)param_2 >> 0x1f) * -2 + 1) * 0x40000000 >> 10;
    uVar5 = (uVar5 - 0x80) * 0x1000;
  }
  else if (uVar5 + 1 >> 0xb != 0) {
    uVar5 = uVar5 + ((int)param_2 >> 0x1f);
    goto LAB_20008344;
  }
  uVar7 = param_4 >> 0x14;
  uVar4 = param_4 + (uVar7 - 1) * -0x100000;
  if ((uVar7 & 0x800) != 0) {
    uVar4 = ~uVar4;
    bVar10 = param_3 == 0;
    param_3 = -param_3;
    if (bVar10) {
      uVar4 = uVar4 + 1;
    }
  }
  uVar7 = uVar7 & 0x7ff;
  if (uVar7 == 0) {
LAB_20008374:
    param_3 = 0;
    uVar4 = (((int)param_4 >> 0x1f) * -2 + 1) * 0x40000000 >> 10;
    uVar7 = (uVar7 - 0x80) * 0x1000;
  }
  else if (uVar7 + 1 >> 0xb != 0) {
    uVar7 = uVar7 + ((int)param_4 >> 0x1f);
    goto LAB_20008374;
  }
  uVar9 = uVar7 - uVar5;
  uVar8 = uVar5 - uVar7;
  if ((int)uVar8 < 0) {
    if ((int)uVar9 < 0x20) {
      uVar8 = uVar8 + 0x20;
      uVar6 = param_1 << (uVar8 & 0xff);
      uVar5 = uVar2;
    }
    else {
      uVar5 = param_3;
      uVar3 = uVar4;
      if (0x3b < (int)uVar9) goto LAB_20008474;
      uVar9 = uVar9 - 0x20;
      uVar8 = uVar8 + 0x40;
      uVar5 = param_1 << (uVar8 & 0xff);
      if (uVar5 != 0) {
        uVar5 = 1;
      }
      uVar6 = uVar5 | param_1 >> (uVar9 & 0xff) | uVar2 << (uVar8 & 0xff);
      uVar5 = (int)uVar2 >> 0x1f;
      param_1 = uVar2;
    }
    uVar2 = (int)uVar5 >> (uVar9 & 0xff);
    param_1 = param_1 >> (uVar9 & 0xff) | uVar5 << (uVar8 & 0xff);
  }
  else {
    uVar7 = uVar5;
    if ((int)uVar8 < 0x20) {
      uVar9 = uVar9 + 0x20;
      uVar6 = param_3 << (uVar9 & 0xff);
      uVar5 = uVar4;
    }
    else {
      uVar5 = param_1;
      uVar3 = uVar2;
      if (0x3b < (int)uVar8) {
LAB_20008474:
        uVar6 = 0;
        goto LAB_200083a2;
      }
      uVar8 = uVar8 - 0x20;
      uVar9 = uVar9 + 0x40;
      uVar5 = param_3 << (uVar9 & 0xff);
      if (uVar5 != 0) {
        uVar5 = 1;
      }
      uVar6 = uVar5 | param_3 >> (uVar8 & 0xff) | uVar4 << (uVar9 & 0xff);
      uVar5 = (int)uVar4 >> 0x1f;
      param_3 = uVar4;
    }
    uVar4 = (int)uVar5 >> (uVar8 & 0xff);
    param_3 = param_3 >> (uVar8 & 0xff) | uVar5 << (uVar9 & 0xff);
  }
  uVar5 = param_1 + param_3;
  uVar3 = uVar2 + uVar4 + (uint)CARRY4(param_1,param_3);
LAB_200083a2:
  iVar1 = (int)uVar3 >> 0x1f;
  if ((int)uVar3 < 0) {
    uVar2 = ~uVar5;
    bVar10 = uVar6 == 0;
    uVar6 = -uVar6;
    uVar5 = uVar2 + bVar10;
    uVar3 = ~uVar3 + (uint)CARRY4(uVar2,(uint)bVar10);
  }
  if (uVar3 >> 0x15 == 0) {
    if (uVar3 >> 0x14 == 0) {
      if (((uVar5 == 0) && (uVar3 == 0)) && (uVar6 == 0)) {
        return 0;
      }
      do {
        bVar11 = CARRY4(uVar6,uVar6);
        uVar6 = uVar6 * 2;
        uVar2 = uVar5 * 2;
        bVar10 = CARRY4(uVar5,uVar5);
        uVar5 = uVar5 * 2 + (uint)bVar11;
        uVar3 = uVar3 * 2 + (uint)(bVar10 || CARRY4(uVar2,(uint)bVar11));
        uVar7 = uVar7 - 1;
      } while (uVar3 >> 0x14 == 0);
    }
    uVar2 = uVar6 & 0x80000000;
    uVar6 = uVar6 << 1;
  }
  else {
    uVar7 = uVar7 + 1;
    uVar2 = uVar5 & 1;
    uVar5 = uVar5 >> 1 | uVar3 << 0x1f;
    uVar3 = uVar3 >> 1;
  }
  if (uVar2 != 0) {
    bVar10 = uVar5 == 0xffffffff;
    uVar5 = uVar5 + 1;
    if (bVar10) {
      uVar3 = uVar3 + 1;
    }
    if (uVar6 == 0) {
      uVar5 = uVar5 & 0xfffffffe;
    }
  }
  if ((int)(uVar7 - 1) < 0) {
    uVar2 = iVar1 * -0x80000000;
  }
  else {
    if (uVar7 + 1 >> 0xb == 0) {
      return CONCAT44(uVar3 + (uVar7 - 1) * 0x100000 + iVar1 * -0x80000000,uVar5);
    }
    uVar2 = iVar1 * -0x80000000 | DAT_20008478;
  }
  return (ulonglong)uVar2 << 0x20;
}


/* ===== dmul_shim @ 2000847c (342 bytes) ===== */

longlong dmul_shim(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  
  uVar2 = param_2 + ((param_2 >> 0x14) - 1) * -0x100000;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  if ((uVar6 == 0) || (uVar6 + 1 >> 0xb != 0)) {
    param_1 = 0;
    uVar2 = 0x100000;
    uVar6 = (uVar6 - 0x80) * 0x1000;
  }
  uVar5 = param_4 + ((param_4 >> 0x14) - 1) * -0x100000;
  uVar7 = param_4 >> 0x14 & 0x7ff;
  if ((uVar7 == 0) || (uVar7 + 1 >> 0xb != 0)) {
    param_3 = 0;
    uVar5 = 0x100000;
    uVar7 = (uVar7 - 0x80) * 0x1000;
  }
  iVar1 = (int)(param_4 ^ param_2) >> 0x1f;
  iVar8 = uVar7 + uVar6;
  uVar7 = (param_3 & 0xffff) * (param_1 & 0xffff);
  uVar11 = (param_1 >> 0x10) * (param_3 & 0xffff);
  iVar17 = (param_3 >> 0x10) * (param_1 >> 0x10);
  uVar6 = (param_3 >> 0x10) * (param_1 & 0xffff);
  uVar12 = uVar11 + uVar6;
  if (CARRY4(uVar11,uVar6) != false) {
    iVar17 = iVar17 + 0x10000;
  }
  uVar6 = uVar12 * 0x10000;
  uVar10 = (uVar12 >> 0x10) + iVar17 + (uint)CARRY4(uVar6,uVar7);
  uVar11 = (uVar5 & 0xffff) * (uVar2 & 0xffff);
  uVar12 = (uVar2 >> 0x10) * (uVar5 & 0xffff);
  iVar17 = (uVar5 >> 0x10) * (uVar2 >> 0x10);
  uVar13 = (uVar5 >> 0x10) * (uVar2 & 0xffff);
  uVar3 = uVar12 + uVar13;
  if (CARRY4(uVar12,uVar13) != false) {
    iVar17 = iVar17 + 0x10000;
  }
  uVar14 = uVar3 * 0x10000;
  uVar15 = uVar14 + uVar11;
  uVar12 = (uVar5 & 0xffff) * (param_1 & 0xffff);
  uVar13 = (param_1 >> 0x10) * (uVar5 & 0xffff);
  iVar9 = (uVar5 >> 0x10) * (param_1 >> 0x10);
  uVar5 = (uVar5 >> 0x10) * (param_1 & 0xffff);
  uVar4 = uVar13 + uVar5;
  if (CARRY4(uVar13,uVar5) != false) {
    iVar9 = iVar9 + 0x10000;
  }
  uVar5 = uVar4 * 0x10000;
  uVar13 = uVar5 + uVar12;
  uVar12 = (uVar4 >> 0x10) + iVar9 + (uint)CARRY4(uVar5,uVar12);
  bVar18 = CARRY4(uVar10,uVar13);
  uVar10 = uVar10 + uVar13;
  uVar16 = uVar15 + uVar12 + (uint)bVar18;
  uVar5 = (param_3 & 0xffff) * (uVar2 & 0xffff);
  uVar13 = (uVar2 >> 0x10) * (param_3 & 0xffff);
  iVar9 = (param_3 >> 0x10) * (uVar2 >> 0x10);
  uVar2 = (param_3 >> 0x10) * (uVar2 & 0xffff);
  uVar4 = uVar13 + uVar2;
  if (CARRY4(uVar13,uVar2) != false) {
    iVar9 = iVar9 + 0x10000;
  }
  uVar2 = uVar4 * 0x10000;
  uVar13 = uVar2 + uVar5;
  uVar2 = (uVar4 >> 0x10) + iVar9 + (uint)CARRY4(uVar2,uVar5);
  bVar19 = CARRY4(uVar10,uVar13);
  uVar10 = uVar10 + uVar13;
  uVar5 = uVar16 + uVar2 + (uint)bVar19;
  uVar11 = ((uVar3 >> 0x10) + iVar17 + (uint)CARRY4(uVar14,uVar11) +
            (uint)(CARRY4(uVar15,uVar12) || CARRY4(uVar15 + uVar12,(uint)bVar18)) +
           (uint)(CARRY4(uVar16,uVar2) || CARRY4(uVar16 + uVar2,(uint)bVar19))) * 0x800;
  uVar12 = uVar11 | uVar5 >> 0x15;
  uVar5 = uVar5 * 0x800 | uVar10 >> 0x15;
  uVar2 = uVar10 * 0x800;
  if (uVar11 >> 0x14 == 0) {
    bVar19 = CARRY4(uVar2,uVar2);
    uVar2 = uVar10 * 0x1000;
    uVar11 = uVar5 * 2;
    bVar18 = CARRY4(uVar5,uVar5);
    uVar5 = uVar5 * 2 + (uint)bVar19;
    uVar12 = uVar12 * 2 + (uint)(bVar18 || CARRY4(uVar11,(uint)bVar19));
    iVar8 = iVar8 + -1;
  }
  uVar11 = iVar8 - DAT_200085d4;
  uVar3 = DAT_200085d4 * 2;
  if (uVar11 < uVar3) {
    if ((uVar2 & 0x80000000) != 0) {
      bVar18 = 0xfffffffe < uVar5;
      uVar5 = uVar5 + 1;
      uVar12 = uVar12 + bVar18;
      if ((uVar2 << 1 | uVar6 + uVar7) == 0) {
        uVar5 = uVar5 & 0xfffffffe;
      }
    }
    uVar12 = uVar12 + uVar11 * 0x100000;
  }
  else if ((int)(uVar11 + DAT_200085d4 * -2) < 0 == SBORROW4(uVar11,uVar3)) {
    uVar12 = (uVar3 + 1) * 0x100000;
    uVar5 = 0;
  }
  else {
    if (((uVar11 != 0xffffffff) || (uVar5 != 0xffffffff)) || (uVar12 + 1 >> 0x15 == 0)) {
      return (ulonglong)(uint)(iVar1 * -0x80000000) << 0x20;
    }
    uVar12 = uVar12 + 1 >> 1;
    uVar5 = 0;
  }
  return CONCAT44(uVar12 + iVar1 * -0x80000000,uVar5);
}


/* ===== FUN_20008642 @ 20008642 (318 bytes) ===== */

longlong FUN_20008642(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_r5;
  uint uVar6;
  int unaff_r6;
  uint uVar7;
  int iVar8;
  int in_r12;
  bool bVar9;
  
  uVar7 = unaff_r6 * 0x8000 - ((unaff_r5 >> 0xe) + 1 >> 1);
  uVar3 = param_2 << 0xb;
  uVar1 = (uVar7 & 0xffff) * (uVar3 & 0xffff | param_1 >> 0x15);
  uVar2 = (uVar3 >> 0x10) * (uVar7 & 0xffff);
  iVar8 = (uVar7 >> 0x10) * (uVar3 >> 0x10);
  uVar4 = (uVar7 >> 0x10) * (uVar3 & 0xffff | param_1 >> 0x15);
  uVar3 = uVar2 + uVar4;
  if (CARRY4(uVar2,uVar4) != false) {
    iVar8 = iVar8 + 0x10000;
  }
  uVar2 = uVar3 * 0x10000;
  uVar4 = uVar2 + uVar1;
  uVar6 = ((uVar3 >> 0x10) + iVar8 + (uint)CARRY4(uVar2,uVar1)) * 2 + (uint)CARRY4(uVar4,uVar4);
  uVar1 = (uVar6 & 0xffff) * (param_3 & 0xffff);
  uVar3 = (param_3 >> 0x10) * (uVar6 & 0xffff);
  iVar8 = (uVar6 >> 0x10) * (param_3 >> 0x10);
  uVar2 = (uVar6 >> 0x10) * (param_3 & 0xffff);
  uVar4 = uVar3 + uVar2;
  if (CARRY4(uVar3,uVar2) != false) {
    iVar8 = iVar8 + 0x10000;
  }
  uVar2 = uVar4 * 0x10000;
  iVar5 = param_1 * 0x20;
  uVar1 = iVar5 - (uVar2 + uVar1 >> 0x19 |
                  ((uVar4 >> 0x10) + iVar8 + (uint)CARRY4(uVar2,uVar1) + uVar6 * param_4) * 0x80);
  uVar2 = ((int)uVar1 >> 0x10) * (uVar7 & 0xffff);
  uVar4 = (uVar7 >> 0x10) * (uVar1 & 0xffff);
  uVar3 = uVar2 + uVar4;
  iVar8 = (uVar3 >> 0x10) +
          (uVar7 >> 0x10) * ((int)uVar1 >> 0x10) +
          (((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar2,uVar4)) * 0x10000 +
          (uint)CARRY4(uVar3 * 0x10000,(uVar7 & 0xffff) * (uVar1 & 0xffff));
  uVar1 = iVar8 * 0x80;
  uVar2 = uVar1 + 0x80;
  uVar3 = uVar6 + (iVar8 >> 0x19) + (uint)(0xffffff7f < uVar1);
  if (uVar3 >> 0x1e == 0) {
    iVar5 = param_1 << 6;
    uVar7 = uVar3 >> 9;
    uVar4 = uVar2 >> 8;
    uVar1 = uVar3 * 0x800000 | uVar2 >> 9;
  }
  else {
    in_r12 = in_r12 + 4;
    uVar3 = uVar3 + (0xffffff7f < uVar2);
    uVar7 = uVar3 >> 10;
    uVar4 = uVar1 + 0x100 >> 9;
    uVar1 = uVar3 * 0x400000 | uVar1 + 0x100 >> 10;
  }
  bVar9 = (uVar4 & 1) != 0;
  if (bVar9) {
    uVar2 = uVar1 * 2 + (uint)bVar9;
    uVar7 = uVar7 * 2 + (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)bVar9));
    uVar3 = (uVar2 & 0xffff) * (param_3 & 0xffff);
    uVar4 = (param_3 >> 0x10) * (uVar2 & 0xffff);
    iVar8 = (uVar2 >> 0x10) * (param_3 >> 0x10);
    uVar1 = (uVar2 >> 0x10) * (param_3 & 0xffff);
    uVar6 = uVar4 + uVar1;
    if (CARRY4(uVar4,uVar1) != false) {
      iVar8 = iVar8 + 0x10000;
    }
    uVar1 = uVar6 * 0x10000;
    if (-1 < (int)((((iVar5 * 0x10000 - param_3 * uVar7) - uVar2 * param_4) -
                   ((uVar6 >> 0x10) + iVar8 + (uint)CARRY4(uVar1,uVar3))) -
                  (uint)(uVar1 + uVar3 != 0))) {
      bVar9 = 0xfffffffe < uVar2;
      uVar2 = uVar2 + 1;
      uVar7 = uVar7 + bVar9;
    }
    uVar1 = uVar2 >> 1 | uVar7 << 0x1f;
    uVar7 = uVar7 >> 1;
  }
  uVar2 = (in_r12 >> 2) + DAT_20008780;
  if (uVar2 < DAT_20008784) {
    iVar8 = uVar7 + uVar2 * 0x100000;
  }
  else {
    uVar1 = 0;
    if ((int)uVar2 < 1) {
      return (ulonglong)(uint)(in_r12 * -0x80000000) << 0x20;
    }
    iVar8 = (DAT_20008784 + 1) * 0x100000;
  }
  return CONCAT44(iVar8 + in_r12 * -0x80000000,uVar1);
}


/* ===== d2fix_a @ 200087ba (74 bytes) ===== */

undefined8 d2fix_a(uint param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int in_r12;
  
  param_3 = param_3 + in_r12;
  uVar1 = param_3 - 0x34;
  if (-1 < (int)uVar1) {
    if ((int)uVar1 < 0xc) {
      return CONCAT44(param_2 << (uVar1 & 0xff) | param_1 >> (0x20 - uVar1 & 0xff),
                      param_1 << (uVar1 & 0xff));
    }
    return CONCAT44(~param_4,~param_4);
  }
  uVar1 = param_3 - 0x14;
  if (-1 < (int)uVar1) {
    return CONCAT44(param_2 >> (0x20 - uVar1 & 0xff),
                    param_1 >> (0x20 - uVar1 & 0xff) | param_2 << (uVar1 & 0xff));
  }
  if (-1 < param_3 + 0xc) {
    return CONCAT44(param_2 >> 0x1f,param_2 >> (0x20U - (param_3 + 0xc) & 0xff));
  }
  return CONCAT44(param_4,param_4);
}


/* ===== __wrap___aeabi_lmul @ 20008844 (50 bytes) ===== */

undefined8 __wrap___aeabi_lmul(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (param_3 >> 0x10) * (param_1 & 0xffff);
  uVar1 = (param_3 & 0xffff) * (param_1 & 0xffff);
  uVar3 = (param_1 >> 0x10) * (param_3 & 0xffff);
  uVar6 = uVar4 * 0x10000;
  uVar2 = uVar1 + uVar6;
  uVar5 = uVar3 * 0x10000;
  return CONCAT44((param_1 >> 0x10) * (param_3 >> 0x10) + (uVar4 >> 0x10) +
                  (uint)CARRY4(uVar1,uVar6) + (uVar3 >> 0x10) + (uint)CARRY4(uVar2,uVar5) +
                  param_3 * param_2 + param_1 * param_4,uVar2 + uVar5);
}


/* ===== __aeabi_float_init @ 20008878 (174 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __aeabi_float_init(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  bVar1 = DAT_00000013;
  iVar3 = rom_data_lookup(DAT_20008928);
  if (bVar1 != 1) {
LAB_2000888a:
    if (1 < bVar1) {
      if ((uint)*(byte *)(iVar3 + -2) * 4 < 0x80) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_20008970,0x42,DAT_2000896c,DAT_20008968);
      }
      memcpy(DAT_2000892c,iVar3,0x80);
    }
    uVar4 = rom_func_lookup(DAT_20008930);
    *DAT_20008934 = uVar4;
    return;
  }
  memcpy(DAT_2000892c,iVar3,0x54);
  if (*DAT_20008938 == DAT_2000893c) {
    if (_DAT_000029c0 == DAT_20008940) {
      if (*DAT_20008944 == DAT_20008948) {
        if (*DAT_2000894c == 0x2500) {
          if (*DAT_20008950 == DAT_20008954) {
            if (*DAT_20008958 == DAT_2000895c) {
              for (uVar5 = 0x15; uVar4 = DAT_20008964, iVar2 = DAT_2000892c, uVar5 < 0x20;
                  uVar5 = uVar5 + 1) {
                *(undefined4 *)(uVar5 * 4 + DAT_2000892c) = DAT_20008964;
              }
              *(undefined4 *)(DAT_2000892c + 0x20) = DAT_20008964;
              *(undefined4 *)(iVar2 + 0x1c) = uVar4;
              goto LAB_2000888a;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  panic(DAT_20008960);
}


/* ===== double_table_shim_on_use_helper__or__float_table_shim_on_use_helper @ 20008974 (46 bytes) ===== */

undefined8
double_table_shim_on_use_helper__or__float_table_shim_on_use_helper
          (undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *in_r12;
  
  if (in_r12 == (undefined4 *)0x0) {
    software_bkpt(0);
  }
  do {
    uVar1 = *(ushort *)in_r12;
    in_r12 = (undefined4 *)((int)in_r12 + 2);
  } while (uVar1 >> 8 != 0xdf);
  if (((uint)in_r12 >> 1 & 1) == 0) {
    uVar2 = *in_r12;
  }
  else {
    uVar2 = *in_r12;
  }
  *(undefined4 *)(DAT_200089a4 + (uint)(byte)uVar1) = uVar2;
  return CONCAT44(param_2,param_1);
}


/* ===== __aeabi_bits_init__or____aeabi_mem_init @ 200089a8 (8 bytes) ===== */

void __aeabi_bits_init__or____aeabi_mem_init(void)

{
                    /* WARNING: Could not recover jumptable at 0x200089ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_200089b4)(DAT_200089b0,4);
  return;
}


/* ===== memset @ 200089b8 (6 bytes) ===== */

void memset(void)

{
                    /* WARNING: Could not recover jumptable at 0x200089bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**DAT_200089c0)();
  return;
}


/* ===== memcpy @ 200089c4 (6 bytes) ===== */

void memcpy(void)

{
                    /* WARNING: Could not recover jumptable at 0x200089c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_200089cc + 4))();
  return;
}


/* ===== stdio_out_chars_no_crlf @ 200089d0 (14 bytes) ===== */

void stdio_out_chars_no_crlf(code **param_1,undefined4 param_2,undefined4 param_3)

{
  (**param_1)(param_2,param_3);
  return;
}


/* ===== stdio_out_chars_crlf @ 200089e0 (124 bytes) ===== */

void stdio_out_chars_crlf(code **param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    (**param_1)(param_2,param_3,param_3,*param_1,param_4);
  }
  else {
    iVar1 = 0;
    for (iVar2 = 0; iVar2 < param_3; iVar2 = iVar2 + 1) {
      if (iVar2 < 1) {
        cVar3 = *(char *)(param_1 + 4);
      }
      else {
        cVar3 = *(char *)(param_2 + iVar2 + -1) == '\r';
      }
      if ((*(char *)(param_2 + iVar2) == '\n') && (cVar3 == '\0')) {
        if (iVar1 < iVar2) {
          (**param_1)(param_2 + iVar1,iVar2 - iVar1);
        }
        (**param_1)(DAT_20008a5c,2);
        iVar1 = iVar2 + 1;
      }
    }
    if (iVar1 < param_3) {
      (**param_1)(param_2 + iVar1,param_3 - iVar1);
    }
    if (0 < param_3) {
      *(bool *)(param_1 + 4) = *(char *)(param_2 + param_3 + -1) == '\r';
    }
  }
  return;
}


/* ===== stdio_stack_buffer_flush @ 20008a60 (58 bytes) ===== */

void stdio_stack_buffer_flush(int *param_1)

{
  int *piVar1;
  
  if (*param_1 != 0) {
    for (piVar1 = *DAT_20008a9c; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[3]) {
      if ((*piVar1 != 0) && ((*DAT_20008aa0 == (int *)0x0 || (*DAT_20008aa0 == piVar1)))) {
        stdio_out_chars_crlf(piVar1,param_1 + 1,*param_1);
      }
    }
    *param_1 = 0;
  }
  return;
}


/* ===== stdio_buffered_printer @ 20008aa4 (32 bytes) ===== */

void stdio_buffered_printer(undefined param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 0x80) {
    stdio_stack_buffer_flush(param_2);
  }
  iVar1 = *param_2;
  *param_2 = iVar1 + 1;
  *(undefined *)((int)param_2 + iVar1 + 4) = param_1;
  return;
}


/* ===== stdout_serialize_begin @ 20008ac4 (42 bytes) ===== */

int stdout_serialize_begin(void)

{
  int iVar1;
  int iVar2;
  int local_c;
  
  iVar2 = (int)(char)DAT_d0000000;
  iVar1 = mutex_try_enter(DAT_20008af0,&local_c);
  if ((iVar1 == 0) && (iVar2 != local_c)) {
    mutex_enter_blocking(DAT_20008af0);
    iVar1 = 1;
  }
  return iVar1;
}


/* ===== stdout_serialize_end @ 20008af4 (10 bytes) ===== */

void stdout_serialize_end(void)

{
  mutex_exit(DAT_20008b00);
  return;
}


/* ===== stdio_put_string @ 20008b04 (136 bytes) ===== */

bool stdio_put_string(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  undefined local_21 [5];
  
  iVar1 = stdout_serialize_begin();
  if (param_2 == -1) {
    param_2 = strlen(param_1);
  }
  pcVar3 = DAT_20008b94;
  if (param_4 != 0) {
    pcVar3 = DAT_20008b8c;
  }
  for (piVar2 = *DAT_20008b90; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
    if ((*piVar2 != 0) &&
       (((*DAT_20008b98 == (int *)0x0 || (*DAT_20008b98 == piVar2)) &&
        ((*pcVar3)(piVar2,param_1,param_2), param_3 != 0)))) {
      local_21[0] = 10;
      (*pcVar3)(piVar2,local_21,1);
    }
  }
  if (iVar1 != 0) {
    stdout_serialize_end();
  }
  return param_2 != 0;
}


/* ===== stdio_set_driver_enabled @ 20008b9c (52 bytes) ===== */

void stdio_set_driver_enabled(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_20008bd0;
  iVar2 = *DAT_20008bd0;
  while( true ) {
    if (iVar2 == 0) {
      if (param_2 != 0) {
        if (iVar1 == 0) {
          *DAT_20008bd0 = param_1;
        }
        else {
          *(int *)(iVar1 + 0xc) = param_1;
        }
      }
      return;
    }
    if (iVar2 == param_1) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  if (param_2 != 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


/* ===== stdio_flush @ 20008bd4 (26 bytes) ===== */

void stdio_flush(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_20008bf0; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))();
    }
  }
  return;
}


/* ===== __wrap_puts @ 20008bf4 (30 bytes) ===== */

undefined4 __wrap_puts(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = strlen();
  stdio_put_string(param_1,uVar1,1,0);
  stdio_flush();
  return uVar1;
}


/* ===== __wrap_vprintf @ 20008c14 (64 bytes) ===== */

undefined4 __wrap_vprintf(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_94 [132];
  
  iVar1 = stdout_serialize_begin();
  memset(auStack_94,0,0x84);
  uVar2 = vfctprintf(DAT_20008c54,auStack_94,param_1,param_2);
  stdio_stack_buffer_flush(auStack_94);
  stdio_flush();
  if (iVar1 != 0) {
    stdout_serialize_end();
  }
  return uVar2;
}


/* ===== __wrap_printf @ 20008c58 (24 bytes) ===== */

void __wrap_printf(undefined4 param_1)

{
  __wrap_vprintf(param_1);
  return;
}


/* ===== stdio_uart_out_chars @ 20008c70 (104 bytes) ===== */

void stdio_uart_out_chars(int param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  byte local_19 [5];
  
  for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
    puVar4 = *DAT_20008cd8;
    bVar1 = *(byte *)(param_1 + iVar5);
    if (*(ushort *)((uint)((int)puVar4 + DAT_20008cdc == 0) * 2 + DAT_20008ce0) == (ushort)bVar1) {
      pbVar3 = local_19;
      local_19[0] = 0xd;
      bVar2 = false;
      while (!bVar2) {
        do {
        } while ((int)(puVar4[6] << 0x1a) < 0);
        *puVar4 = (uint)*pbVar3;
        pbVar3 = pbVar3 + 1;
        bVar2 = true;
      }
    }
    pbVar3 = local_19;
    local_19[0] = bVar1;
    bVar2 = false;
    while (!bVar2) {
      do {
      } while ((int)(puVar4[6] << 0x1a) < 0);
      *puVar4 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
      bVar2 = true;
    }
  }
  return;
}


/* ===== stdio_uart_in_chars @ 20008ce4 (82 bytes) ===== */

int stdio_uart_in_chars(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined local_19 [5];
  
  iVar2 = 0;
  while (iVar2 < param_2) {
    puVar4 = (undefined4 *)*DAT_20008d38;
    uVar3 = puVar4[6] & 0x10;
    if ((puVar4[6] & 0x10) != 0) break;
    puVar1 = local_19;
    while (uVar3 == 0) {
      do {
      } while ((int)(puVar4[6] << 0x1b) < 0);
      *puVar1 = (char)*puVar4;
      puVar1 = puVar1 + 1;
      uVar3 = 1;
    }
    *(undefined *)(param_1 + iVar2) = local_19[0];
    iVar2 = iVar2 + 1;
  }
  if (iVar2 == 0) {
    iVar2 = -3;
  }
  return iVar2;
}


/* ===== stdio_uart_init_full @ 20008d3c (52 bytes) ===== */

void stdio_uart_init_full(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  *DAT_20008d70 = param_1;
  uart_init();
  if (-1 < param_3) {
    gpio_set_function(param_3,2);
  }
  if (-1 < param_4) {
    gpio_set_function(param_4,2);
  }
  stdio_set_driver_enabled(DAT_20008d74,1);
  return;
}


/* ===== spi_set_baudrate @ 20008d78 (146 bytes) ===== */

void spi_set_baudrate(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar2 = clock_get_hz(6);
  uVar1 = 2;
  do {
    uVar4 = uVar1;
    if (0xfe < uVar4) {
      uVar1 = 0x100;
      goto LAB_20008dba;
    }
    uVar6 = __wrap___aeabi_lmul((uVar4 + 2) * 0x100,0,param_2,0);
  } while (((int)((ulonglong)uVar6 >> 0x20) == 0) && (uVar1 = uVar4 + 2, (uint)uVar6 <= uVar2));
  uVar1 = 0x100;
LAB_20008dba:
  do {
    uVar5 = uVar1;
    if (uVar5 < 2) break;
    uVar3 = __aeabi_uidiv(uVar2,(uVar5 - 1) * uVar4);
    uVar1 = uVar5 - 1;
  } while (uVar3 <= param_2);
  param_1[4] = uVar4;
  *(uint *)((uint)param_1 | 0x1000) = ((uVar5 - 1) * 0x100 ^ *param_1) & 0xff00;
  __aeabi_uidiv(uVar2,uVar4 * uVar5);
  return;
}


/* ===== spi_init @ 20008e0c (86 bytes) ===== */

void spi_init(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == DAT_20008e64) {
    uVar1 = 0x10000;
  }
  else {
    uVar1 = 0x20000;
  }
  *DAT_20008e68 = uVar1;
  *DAT_20008e6c = uVar1;
  do {
  } while ((uVar1 & ~*(uint *)(DAT_20008e70 + 8)) != 0);
  spi_set_baudrate(param_1);
  *(uint *)((uint)param_1 | 0x1000) = (*param_1 ^ 7) & 0xcf;
  *(undefined4 *)((uint)(param_1 + 9) | 0x2000) = 3;
  *(undefined4 *)((uint)(param_1 + 1) | 0x2000) = 2;
  return;
}


/* ===== i2c_set_baudrate @ 20008e74 (214 bytes) ===== */

void i2c_set_baudrate(uint **param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = clock_get_hz(5);
  iVar2 = __aeabi_uidiv((param_2 >> 1) + iVar1,param_2);
  uVar5 = iVar2 * 3;
  uVar3 = __aeabi_uidiv(uVar5,5);
  if (DAT_20008f4c < param_2) {
    iVar4 = __aeabi_uidiv(iVar1 * 3,DAT_20008f54);
  }
  else {
    iVar4 = __aeabi_uidiv(iVar1 * 3,DAT_20008f50);
  }
  if (iVar4 + 1U <= uVar3 - 2) {
    (*param_1)[0x1b] = 0;
    *(uint *)((uint)*param_1 | 0x1000) = (**param_1 ^ 4) & 6;
    (*param_1)[7] = iVar2 - uVar3;
    (*param_1)[8] = uVar3;
    if (uVar5 < 0x50) {
      uVar5 = 1;
    }
    else {
      uVar5 = __aeabi_uidiv(uVar5,0x50);
    }
    (*param_1)[0x28] = uVar5;
    *(uint *)((uint)(*param_1 + 0x1f) | 0x1000) = (iVar4 + 1U ^ (*param_1)[0x1f]) & 0xffff;
    (*param_1)[0x1b] = 1;
    __aeabi_uidiv(iVar1,iVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20008f60,0x5f,DAT_20008f5c,DAT_20008f58);
}


/* ===== i2c_init @ 20008f64 (70 bytes) ===== */

void i2c_init(int *param_1)

{
  uint uVar1;
  
  if (param_1 == DAT_20008fac) {
    uVar1 = 8;
  }
  else {
    uVar1 = 0x10;
  }
  *DAT_20008fb0 = uVar1;
  *DAT_20008fb4 = uVar1;
  do {
  } while ((uVar1 & ~*(uint *)(DAT_20008fb8 + 8)) != 0);
  *(undefined *)(param_1 + 1) = 0;
  *(undefined4 *)(*param_1 + 0x6c) = 0;
  *(undefined4 *)*param_1 = 0x165;
  *(undefined4 *)(*param_1 + 0x3c) = 0;
  *(undefined4 *)(*param_1 + 0x38) = 0;
  *(undefined4 *)(*param_1 + 0x88) = 3;
  i2c_set_baudrate();
  return;
}


/* ===== core1_trampoline @ 20008fbc (2 bytes) ===== */

undefined8 core1_trampoline(void)

{
  undefined8 in_stack_00000000;
  
  return in_stack_00000000;
}


/* ===== core1_wrapper @ 20008fbe (12 bytes) ===== */

void core1_wrapper(code *param_1)

{
  irq_init_priorities();
  (*param_1)();
  return;
}


/* ===== multicore_fifo_push_blocking @ 20008fca (20 bytes) ===== */

void multicore_fifo_push_blocking(undefined4 param_1)

{
  do {
  } while (-1 < DAT_d0000050 << 0x1e);
  DAT_d0000054 = param_1;
  return;
}


/* ===== multicore_fifo_pop_blocking @ 20008fde (2 bytes) ===== */

undefined4 multicore_fifo_pop_blocking(void)

{
  while (-1 < DAT_d0000050 << 0x1f) {
    WaitForEvent();
  }
  return DAT_d0000058;
}


/* ===== FUN_20008fe2 @ 20008fe2 (20 bytes) ===== */

undefined4 FUN_20008fe2(void)

{
  while (-1 < DAT_d0000050 << 0x1f) {
    WaitForEvent();
  }
  return DAT_d0000058;
}


/* ===== multicore_launch_core1_raw @ 20008ff4 (110 bytes) ===== */

void multicore_launch_core1_raw(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_30 [7];
  
  uVar1 = irq_is_enabled(0xf);
  irq_set_enabled(0xf,0);
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 1;
  local_30[3] = param_3;
  local_30[4] = param_2;
  local_30[5] = param_1;
  uVar4 = 0;
  do {
    while( true ) {
      iVar3 = local_30[uVar4];
      if (iVar3 == 0) {
        do {
        } while (DAT_d0000050 << 0x1f < 0);
      }
      multicore_fifo_push_blocking(iVar3);
      iVar2 = multicore_fifo_pop_blocking();
      if (iVar3 == iVar2) break;
      uVar4 = 0;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 6);
  irq_set_enabled(0xf,uVar1);
  return;
}


/* ===== multicore_launch_core1_with_stack @ 20009064 (56 bytes) ===== */

void multicore_launch_core1_with_stack(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 & 3) == 0) {
    iVar1 = param_2 + (param_3 & 0xfffffffc);
    *(undefined4 *)(iVar1 + -0xc) = param_1;
    *(int *)(iVar1 + -8) = param_2;
    *(undefined4 *)(iVar1 + -4) = DAT_2000909c;
    multicore_launch_core1_raw
              (DAT_200090a4,(undefined4 *)(iVar1 + -0xc),*(undefined4 *)(DAT_200090a0 + 8));
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200090b0,0x6e,DAT_200090ac,DAT_200090a8);
}


/* ===== multicore_launch_core1 @ 200090b4 (28 bytes) ===== */

void multicore_launch_core1(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = DAT_200090d0;
  if (DAT_200090d0 < DAT_200090d4) {
    uVar1 = 0xffffffff;
  }
  multicore_launch_core1_with_stack(param_1,uVar1,0x800);
  return;
}


/* ===== get_dev_ep @ 200090d8 (60 bytes) ===== */

int get_dev_ep(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_20009114;
  if ((param_2 & 0x7f) != 0) {
    for (uVar2 = 1; uVar2 < 0x10; uVar2 = uVar2 + 1) {
      iVar1 = uVar2 * 0x24 + DAT_20009114;
      if (((*(char *)(uVar2 * 0x24 + DAT_20009114) != '\0') && (*(byte *)(iVar1 + 0x1f) == param_1))
         && (*(byte *)(iVar1 + 2) == param_2)) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== _next_free_interrupt_ep @ 20009118 (44 bytes) ===== */

int _next_free_interrupt_ep(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  iVar1 = 0;
  while( true ) {
    if (0xf < uVar2) {
      return iVar1;
    }
    iVar1 = uVar2 * 0x24 + DAT_20009144;
    if (*(char *)(uVar2 * 0x24 + DAT_20009144) == '\0') break;
    uVar2 = uVar2 + 1;
  }
  *(char *)(iVar1 + 0x20) = (char)uVar2 + -1;
  return iVar1;
}


/* ===== next_free_interrupt_ep @ 20009148 (36 bytes) ===== */

int next_free_interrupt_ep(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = 0xf;
      (iVar2 != 0 &&
      (iVar1 = iVar2 * 0x24 + DAT_2000916c, *(char *)(iVar2 * 0x24 + DAT_2000916c) != '\0'));
      iVar2 = iVar2 + -1) {
  }
  return iVar1;
}


/* ===== _hw_endpoint_allocate @ 20009170 (122 bytes) ===== */

void _hw_endpoint_allocate(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_200091ec;
  if (param_1 == 3) {
    iVar1 = _next_free_interrupt_ep();
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_2000920c,299,DAT_20009208,DAT_20009204);
    }
    iVar2 = (uint)*(byte *)(iVar1 + 0x20) * 8;
    *(int *)(iVar1 + 8) = iVar2 + DAT_200091fc;
    *(int *)(iVar1 + 4) = iVar2 + DAT_20009200;
    *(uint *)(iVar1 + 0xc) = (*(byte *)(iVar1 + 0x20) + 2) * 0x40 + DAT_200091f8;
  }
  else if ((param_1 - 1U & 0xff) < 2) {
    iVar1 = next_free_interrupt_ep();
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_2000920c,0x138,DAT_20009208,DAT_20009204);
    }
    *(undefined4 *)(iVar1 + 8) = DAT_200091f0;
    *(undefined4 *)(iVar1 + 4) = DAT_200091f4;
    *(int *)(iVar1 + 0xc) = DAT_200091f8;
  }
  else {
    *(undefined4 *)(DAT_200091ec + 8) = DAT_200091f0;
    *(undefined4 *)(iVar1 + 4) = DAT_200091f4;
    *(int *)(iVar1 + 0xc) = DAT_200091f8;
  }
  return;
}


/* ===== _hw_endpoint_reinit_epx @ 20009210 (144 bytes) ===== */

void _hw_endpoint_reinit_epx(char *param_1)

{
  uint uVar1;
  
  if (*(uint **)(param_1 + 4) == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200092b8,DAT_200092b4,DAT_200092b0,DAT_200092ac);
  }
  if (*(int *)(param_1 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200092b8,DAT_200092c0,DAT_200092b0,DAT_200092bc);
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200092b8,0x214,DAT_200092b0,DAT_200092c4);
  }
  if (*param_1 != '\0') {
    if ((uVar1 & 0x3f) == 0) {
      **(uint **)(param_1 + 4) =
           (uint)(byte)param_1[0x1e] << 0x1a | DAT_200092a0 ^ uVar1 | 0xa0000000;
      if (*(int *)(DAT_200092a4 + 0x50) << 3 < 0) {
        *(undefined4 *)(DAT_200092a8 + 0x50) = 0x10000000;
      }
      if (param_1[2] < '\0') {
        *(undefined4 *)(DAT_200092a4 + 0x6c) = DAT_200092d8;
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200092b8,DAT_200092d4,DAT_200092b0,DAT_200092d0);
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200092b8,DAT_200092cc,DAT_200092b0,DAT_200092c8);
}


/* ===== hw_xfer_complete @ 200092dc (36 bytes) ===== */

void hw_xfer_complete(int param_1,undefined4 param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined2 uVar3;
  
  uVar1 = *(undefined *)(param_1 + 0x1f);
  uVar2 = *(undefined *)(param_1 + 2);
  uVar3 = *(undefined2 *)(param_1 + 0x14);
  hw_endpoint_reset_transfer();
  hcd_event_xfer_complete(uVar1,uVar2,uVar3,param_2,1);
  return;
}


/* ===== _handle_buff_status_bit @ 20009300 (30 bytes) ===== */

void _handle_buff_status_bit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(DAT_20009320 + 0x58) = param_1;
  iVar1 = hw_endpoint_xfer_continue(param_2);
  if (iVar1 != 0) {
    hw_xfer_complete(param_2,0);
  }
  return;
}


/* ===== hw_handle_buff_status @ 20009324 (86 bytes) ===== */

void hw_handle_buff_status(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_2000937c + 0x58);
  if ((int)(uVar3 << 0x1f) < 0) {
    uVar3 = uVar3 & 0xfffffffe;
    _handle_buff_status_bit(1,*DAT_20009380,param_3,**(undefined4 **)(*DAT_20009380 + 4));
  }
  uVar2 = 1;
  while ((uVar2 < 0x10 && (uVar3 != 0))) {
    uVar1 = 1 << ((uVar2 & 0x7f) << 1);
    if ((uVar1 & uVar3) != 0) {
      uVar3 = uVar3 & ~uVar1;
      _handle_buff_status_bit(uVar1,uVar2 * 0x24 + DAT_20009384);
    }
    uVar2 = uVar2 + 1;
  }
  if (uVar3 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  panic(DAT_20009388,uVar3);
}


/* ===== hw_trans_complete @ 2000938c (40 bytes) ===== */

void hw_trans_complete(void)

{
  if (*(int *)(DAT_200093b4 + 0x4c) << 0x1e < 0) {
    if (*(char *)(DAT_200093b8 + 0x10) == '\0') {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_200093c4,0xb9,DAT_200093c0,DAT_200093bc);
    }
    hw_xfer_complete(DAT_200093b8,0);
  }
  return;
}


/* ===== hcd_rp2040_irq @ 200093c8 (168 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hcd_rp2040_irq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(_LAB_20009470 + 0x98);
  uVar2 = uVar1 & 1;
  if ((uVar1 & 1) != 0) {
    if ((*(uint *)(_LAB_20009470 + 0x50) >> 8 & 3) == 0) {
      hcd_event_device_remove(0,1);
    }
    else {
      hcd_event_device_attach(0,1);
    }
    *(undefined4 *)(_LAB_20009474 + 0x50) = 0x300;
    uVar2 = 1;
  }
  if ((int)(uVar1 << 0x1b) < 0) {
    uVar2 = uVar2 | 0x10;
    hw_handle_buff_status();
  }
  if ((int)(uVar1 << 0x1c) < 0) {
    uVar2 = uVar2 | 8;
    *(undefined4 *)(_LAB_20009474 + 0x50) = 0x40000;
    hw_trans_complete();
  }
  if ((int)(uVar1 << 0x15) < 0) {
    uVar2 = uVar2 | 0x400;
    *(undefined4 *)(_LAB_20009474 + 0x50) = 0x20000000;
    hw_xfer_complete(_LAB_20009478,2);
  }
  if ((int)(uVar1 << 0x19) < 0) {
    uVar2 = uVar2 | 0x40;
    *(undefined4 *)(_LAB_20009474 + 0x50) = 0x8000000;
  }
  if (-1 < (int)(uVar1 << 0x1a)) {
    if (uVar2 == uVar1) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    panic(_LAB_20009480,uVar2 ^ uVar1);
  }
  *(undefined4 *)(_LAB_20009474 + 0x50) = 0x80000000;
                    /* WARNING: Subroutine does not return */
  panic(_LAB_2000947c);
}


/* ===== hcd_init @ 20009484 (68 bytes) ===== */

undefined4 hcd_init(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    rp2040_usb_init();
    iVar1 = DAT_200094c8;
    *(undefined4 *)(DAT_200094c8 + 0x78) = 0xc;
    irq_set_exclusive_handler(5,DAT_200094cc);
    memset(DAT_200094d0,0,0x240);
    *(undefined4 *)(iVar1 + 0x40) = 3;
    *(undefined4 *)(iVar1 + 0x4c) = DAT_200094d4;
    *(undefined4 *)(iVar1 + 0x90) = DAT_200094d8;
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200094e4,0x18d,DAT_200094e0,DAT_200094dc);
}


/* ===== hcd_port_reset @ 200094e8 (22 bytes) ===== */

void hcd_port_reset(int param_1)

{
  if (param_1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_20009508,0x1ab,DAT_20009504,DAT_20009500);
}


/* ===== hcd_port_connect_status @ 2000950c (38 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool hcd_port_connect_status(int param_1)

{
  if (param_1 == 0) {
    return (*(uint *)(_LAB_20009534 + 0x50) & 0x300) != 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(_LAB_20009540,0x1b2,_LAB_2000953c,_LAB_20009538);
}


/* ===== hcd_port_speed_get @ 20009544 (56 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint hcd_port_speed_get(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(_LAB_2000958c,0x1b8,_LAB_20009588,_LAB_20009584);
  }
  uVar1 = *(uint *)(_LAB_2000957c + 0x50) >> 8 & 3;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      uVar1 = 0;
    }
    else {
      if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        panic(_LAB_20009580);
      }
      uVar1 = 0xff;
    }
  }
  return uVar1;
}


/* ===== need_pre @ 20009590 (28 bytes) ===== */

bool need_pre(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hcd_port_speed_get(0);
  iVar2 = tuh_speed_get(param_1);
  return iVar1 != iVar2;
}


/* ===== _hw_endpoint_init @ 200095ac (268 bytes) ===== */

void _hw_endpoint_init(undefined *param_1,uint param_2,uint param_3,undefined2 param_4,byte param_5,
                      byte param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)param_6;
  if (*(uint **)(param_1 + 4) == (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200096c4,0x14b,DAT_200096c0,DAT_200096bc);
  }
  if (*(int *)(param_1 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200096c4,0x14c,DAT_200096c0,DAT_200096c8);
  }
  if (*(uint *)(param_1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_200096c4,0x14d,DAT_200096c0,DAT_200096cc);
  }
  param_1[2] = (char)param_3;
  param_1[0x1f] = (char)param_2;
  param_1[1] = (char)(param_3 >> 7);
  param_1[3] = (param_3 & 0x7f) == 0;
  *(undefined2 *)(param_1 + 0x1c) = param_4;
  param_1[0x1e] = param_5;
  uVar4 = DAT_200096b8 ^ *(uint *)(param_1 + 0xc);
  uVar3 = uVar4 & 0x3f;
  if ((uVar4 & 0x3f) == 0) {
    if (uVar1 != 0) {
      uVar3 = (uVar1 - 1) * 0x10000;
    }
    **(uint **)(param_1 + 4) = uVar3 | (uint)param_5 << 0x1a | uVar4 | 0xa0000000;
    *param_1 = 1;
    if ((uVar1 != 0) && (param_1[0x1e] == '\x03')) {
      uVar1 = (param_3 & 0x7f) << 0x10 | param_2;
      if (param_3 >> 7 != 1) {
                    /* WARNING: Subroutine does not return */
        __assert_func(DAT_200096c4,0x177,DAT_200096c0,DAT_200096dc);
      }
      iVar2 = need_pre(param_2);
      if (iVar2 != 0) {
        uVar1 = uVar1 | 0x4000000;
      }
      *(uint *)((uint)(byte)param_1[0x20] * 4 + DAT_200096d4 + 4) = uVar1;
      *(int *)(DAT_200096d8 + 0x54) = 1 << ((byte)param_1[0x20] + 1 & 0xff);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_200096c4,0x161,DAT_200096c0,DAT_200096d0);
}


/* ===== hcd_device_close @ 200096e0 (114 bytes) ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hcd_device_close(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    *DAT_20009754 = 0x14;
    for (uVar3 = 1; iVar1 = _LAB_20009758, uVar3 < 0x10; uVar3 = uVar3 + 1) {
      iVar2 = uVar3 * 0x24 + _LAB_20009758;
      if ((*(byte *)(iVar2 + 0x1f) == param_2) && (*(char *)(uVar3 * 0x24 + _LAB_20009758) != '\0'))
      {
        *(int *)(_LAB_2000975c + 0x54) = 1 << (*(byte *)(iVar2 + 0x20) + 1 & 0xff);
        *(undefined4 *)((uint)*(byte *)(iVar2 + 0x20) * 4 + _LAB_20009760 + 4) = 0;
        *(undefined *)(uVar3 * 0x24 + iVar1) = 0;
        **(undefined4 **)(iVar2 + 4) = 0;
        **(undefined4 **)(iVar2 + 8) = 0;
        hw_endpoint_reset_transfer();
      }
    }
  }
  return;
}


/* ===== hcd_int_enable @ 20009764 (30 bytes) ===== */

void hcd_int_enable(int param_1)

{
  if (param_1 == 0) {
    irq_set_enabled(5,1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_2000978c,0x1ec,DAT_20009788,DAT_20009784);
}


/* ===== hcd_edpt_open @ 20009790 (56 bytes) ===== */

undefined4 hcd_edpt_open(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = _hw_endpoint_allocate(*(byte *)(param_3 + 3) & 3);
  _hw_endpoint_init(uVar1,param_2,*(undefined *)(param_3 + 2),
                    (*(byte *)(param_3 + 5) & 7) << 8 | (uint)*(byte *)(param_3 + 4),
                    *(byte *)(param_3 + 3) & 3,*(undefined *)(param_3 + 6));
  return 1;
}


/* ===== hcd_edpt_xfer @ 200097c8 (298 bytes) ===== */

undefined4
hcd_edpt_xfer(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_3 & 0x7f;
  iVar3 = get_dev_ep(param_2,param_3);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_2000990c,0x238,DAT_20009908,DAT_20009904);
  }
  if (uVar5 == 0) {
    if ((*DAT_200098f4 != DAT_200098f8) || (*(byte *)(iVar3 + 2) != param_3)) {
      _hw_endpoint_init(iVar3,param_2,param_3,*(undefined2 *)(iVar3 + 0x1c),
                        *(undefined *)(iVar3 + 0x1e),0);
    }
    *DAT_200098f4 = DAT_200098f8;
  }
  if (iVar3 == DAT_200098f8) {
    bVar1 = false;
  }
  else if ((byte)(*(char *)(iVar3 + 0x1e) - 1U) < 2) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (*DAT_200098f4 != iVar3) {
      _hw_endpoint_reinit_epx(iVar3);
    }
    *DAT_200098f4 = iVar3;
    hw_endpoint_xfer_start(iVar3,param_4,param_5);
    *DAT_200098fc = uVar5 << 0x10 | param_2;
    uVar5 = DAT_20009910;
    if (param_3 >> 7 != 0) {
      uVar5 = DAT_20009900;
    }
    iVar3 = need_pre(param_2);
    puVar2 = DAT_200098fc;
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x40;
    }
    DAT_200098fc[0x13] = uVar4 | uVar5;
    puVar2[0x13] = uVar4 | uVar5 | 1;
  }
  else if (iVar3 == DAT_200098f8) {
    hw_endpoint_xfer_start(iVar3,param_4,param_5);
    *DAT_200098fc = uVar5 << 0x10 | param_2;
    uVar5 = DAT_20009918;
    if (param_3 >> 7 != 0) {
      uVar5 = DAT_20009914;
    }
    iVar3 = need_pre(param_2);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x40;
    }
    DAT_200098fc[0x13] = uVar5 | uVar4;
  }
  else {
    hw_endpoint_xfer_start(iVar3,param_4,param_5);
  }
  return 1;
}


/* ===== hcd_setup_send @ 2000991c (96 bytes) ===== */

undefined4 hcd_setup_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  memcpy(DAT_2000997c,param_3,8);
  pcVar1 = (char *)_hw_endpoint_allocate(0);
  _hw_endpoint_init(pcVar1,param_2,0,*(undefined2 *)(pcVar1 + 0x1c),0,0);
  if (*pcVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_20009990,0x284,DAT_2000998c,DAT_20009988);
  }
  *(undefined2 *)(pcVar1 + 0x12) = 8;
  pcVar1[0x10] = '\x01';
  *DAT_20009980 = param_2;
  iVar2 = need_pre(param_2);
  uVar3 = DAT_20009994;
  if (iVar2 != 0) {
    uVar3 = DAT_20009984;
  }
  DAT_20009980[0x13] = uVar3;
  return 1;
}


/* ===== prepare_ep_buffer @ 20009998 (120 bytes) ===== */

uint prepare_ep_buffer(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x12);
  uVar3 = uVar1;
  if (*(ushort *)(param_1 + 0x1c) < uVar1) {
    uVar3 = *(ushort *)(param_1 + 0x1c);
  }
  uVar4 = (uint)uVar3;
  *(ushort *)(param_1 + 0x12) = uVar1 - uVar3;
  if (*(byte *)(param_1 + 3) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x2000;
  }
  uVar2 = uVar4 | 0x400 | uVar2;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ 1;
  if (*(char *)(param_1 + 1) == '\0') {
    memcpy(param_2 * 0x40 + *(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18),uVar4,
           *(int *)(param_1 + 0xc),param_4);
    *(uint *)(param_1 + 0x18) = uVar4 + *(int *)(param_1 + 0x18);
    uVar2 = uVar2 | 0x8000;
  }
  if ((*(short *)(param_1 + 0x12) == 0) || (*(char *)(param_1 + 0x21) != '\0')) {
    uVar2 = uVar2 | 0x4000;
  }
  if (param_2 != 0) {
    uVar2 = uVar2 << 0x10;
  }
  return uVar2;
}


/* ===== sync_ep_buffer @ 20009a10 (106 bytes) ===== */

uint sync_ep_buffer(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = **(uint **)(param_1 + 8);
  if (param_2 != 0) {
    uVar1 = uVar1 >> 0x10;
  }
  uVar2 = uVar1 & 0x3ff;
  if (*(char *)(param_1 + 1) == '\0') {
    if ((int)(uVar1 << 0x10) < 0) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20009a84,0xdb,DAT_20009a80,DAT_20009a7c);
    }
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + (short)uVar2;
  }
  else {
    if (-1 < (int)(uVar1 << 0x10)) {
                    /* WARNING: Subroutine does not return */
      __assert_func(DAT_20009a84,0xe2,DAT_20009a80,DAT_20009a88);
    }
    memcpy(*(undefined4 *)(param_1 + 0x18),param_2 * 0x40 + *(int *)(param_1 + 0xc),uVar2);
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + (short)uVar2;
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar2;
  }
  if (uVar2 < *(ushort *)(param_1 + 0x1c)) {
    *(undefined2 *)(param_1 + 0x12) = 0;
  }
  return uVar2;
}


/* ===== _hw_endpoint_xfer_sync @ 20009a8c (40 bytes) ===== */

void _hw_endpoint_xfer_sync(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = sync_ep_buffer(param_1,0,param_3,**(undefined4 **)(param_1 + 8));
  if ((**(int **)(param_1 + 4) << 1 < 0) && (*(ushort *)(param_1 + 0x1c) == uVar1)) {
    sync_ep_buffer(param_1,1);
  }
  return;
}


/* ===== rp2040_usb_init @ 20009ab4 (56 bytes) ===== */

void rp2040_usb_init(void)

{
  int iVar1;
  
  *DAT_20009aec = 0x1000000;
  *DAT_20009af0 = 0x1000000;
  iVar1 = DAT_20009af8;
  do {
  } while ((~*(uint *)(DAT_20009af4 + 8) & 0x1000000) != 0);
  memset(DAT_20009af8,0,0x9c);
  memset(DAT_20009afc,0,0x1000);
  *(undefined4 *)(iVar1 + 0x74) = 9;
  return;
}


/* ===== hw_endpoint_reset_transfer @ 20009b00 (12 bytes) ===== */

void hw_endpoint_reset_transfer(int param_1)

{
  *(undefined *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


/* ===== _hw_endpoint_buffer_control_update32 @ 20009b0c (62 bytes) ===== */

void _hw_endpoint_buffer_control_update32(int param_1,uint param_2,uint param_3)

{
  if (param_2 != 0) {
    param_2 = param_2 & **(uint **)(param_1 + 8);
  }
  if ((param_3 != 0) && (param_2 = param_2 | param_3, (int)(param_3 << 0x15) < 0)) {
    if ((int)(**(uint **)(param_1 + 8) << 0x15) < 0) {
                    /* WARNING: Subroutine does not return */
      panic(DAT_20009b54,*(byte *)(param_1 + 2) & 0x7f,
            *(undefined4 *)((uint)(*(byte *)(param_1 + 2) >> 7) * 4 + DAT_20009b50));
    }
    **(uint **)(param_1 + 8) = DAT_20009b4c & param_2;
  }
  **(uint **)(param_1 + 8) = param_2;
  return;
}


/* ===== _hw_endpoint_start_next_buffer @ 20009b58 (102 bytes) ===== */

void _hw_endpoint_start_next_buffer(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = **(uint **)(param_1 + 4);
  uVar2 = prepare_ep_buffer(param_1,0);
  uVar2 = uVar2 | 0x1000;
  if (*(int *)(DAT_20009bc0 + 0x40) << 0x1e < 0) {
    bVar1 = false;
  }
  else if (*(char *)(param_1 + 2) < '\0') {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((*(short *)(param_1 + 0x12) == 0) || (bVar1)) {
    uVar4 = uVar4 & DAT_20009bc4 | 0x20000000;
  }
  else {
    uVar3 = prepare_ep_buffer(param_1,1);
    uVar2 = uVar2 | uVar3;
    uVar4 = uVar4 & DAT_20009bc8 | 0x50000000;
  }
  **(uint **)(param_1 + 4) = uVar4;
  _hw_endpoint_buffer_control_update32(param_1,0,uVar2);
  return;
}


/* ===== hw_endpoint_xfer_start @ 20009bcc (62 bytes) ===== */

void hw_endpoint_xfer_start(int param_1,undefined4 param_2,undefined2 param_3)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    __wrap_printf(DAT_20009c10,*(byte *)(param_1 + 2) & 0x7f,
                  *(undefined4 *)((uint)(*(byte *)(param_1 + 2) >> 7) * 4 + DAT_20009c0c));
    hw_endpoint_reset_transfer(param_1);
  }
  *(undefined2 *)(param_1 + 0x12) = param_3;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  _hw_endpoint_start_next_buffer(param_1);
  return;
}


/* ===== hw_endpoint_xfer_continue @ 20009c14 (48 bytes) ===== */

char hw_endpoint_xfer_continue(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 != '\0') {
    _hw_endpoint_xfer_sync();
    if (*(short *)(param_1 + 0x12) != 0) {
      _hw_endpoint_start_next_buffer(param_1);
      cVar1 = '\0';
    }
    return cVar1;
  }
                    /* WARNING: Subroutine does not return */
  panic(DAT_20009c48,*(byte *)(param_1 + 2) & 0x7f,DAT_20009c44);
}


/* ===== get_new_address @ 20009c4c (80 bytes) ===== */

uint get_new_address(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    cVar5 = '\x01';
    bVar4 = 4;
  }
  else {
    cVar5 = '\x05';
    bVar4 = 1;
  }
  bVar2 = 0;
  uVar6 = param_4;
  while( true ) {
    if (bVar4 <= bVar2) {
      return 0xff;
    }
    uVar3 = (uint)(byte)(bVar2 + cVar5);
    if (uVar3 == 0) {
      __wrap_printf(DAT_20009ca0,DAT_20009c9c,0xdc,param_4,uVar6);
      iVar1 = 0;
    }
    else {
      iVar1 = (uVar3 - 1) * 0x50 + DAT_20009ca4;
    }
    param_4 = (uint)*(byte *)(iVar1 + 0xd);
    if (param_4 == 0) break;
    bVar2 = bVar2 + 1;
  }
  return uVar3;
}


/* ===== enum_hub_get_status0_complete @ 20009ca8 (94 bytes) ===== */

undefined4 enum_hub_get_status0_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  byte bStack_b;
  
  iVar1 = DAT_20009d0c;
  if (param_3 == 0) {
    uVar4 = *DAT_20009d08;
    if ((int)(uVar4 << 0x1f) < 0) {
      bStack_b = (byte)(uVar4 >> 8);
      if ((int)((uint)bStack_b << 0x1d) < 0) {
        bVar3 = 2;
      }
      else {
        bVar3 = bStack_b >> 1 & 1;
      }
      *(byte *)(DAT_20009d0c + 3) = bVar3;
      if ((int)((uVar4 >> 0x10) << 0x1b) < 0) {
        hub_port_clear_feature
                  (*(undefined *)(iVar1 + 1),*(undefined *)(iVar1 + 2),0x14,DAT_20009d1c);
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = hub_status_pipe_queue();
    }
  }
  else {
    __wrap_printf(DAT_20009d18,DAT_20009d14,DAT_20009d10);
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== enum_hub_get_status1_complete @ 20009d20 (74 bytes) ===== */

int enum_hub_get_status1_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    if ((int)((*DAT_20009d6c >> 0x10) << 0x1b) < 0) {
      iVar1 = hub_port_clear_feature
                        (*(undefined *)(DAT_20009d7c + 1),*(undefined *)(DAT_20009d7c + 2),0x14,
                         DAT_20009d80);
      if (iVar1 == 0) {
        __wrap_printf(DAT_20009d78,DAT_20009d74,DAT_20009d84);
      }
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    __wrap_printf(DAT_20009d78,DAT_20009d74,DAT_20009d70);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== enum_request_set_addr @ 20009d88 (182 bytes) ===== */

int enum_request_set_addr(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined local_10;
  undefined local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar2 = get_new_address(*(char *)(DAT_20009e40 + 4) == '\t');
  if (iVar2 == 0xff) {
    __wrap_printf(DAT_20009e58,DAT_20009e54,DAT_20009e50);
    iVar2 = 0;
  }
  else {
    if (iVar2 == 0) {
      __wrap_printf(DAT_20009e58,DAT_20009e5c,0xdc);
      puVar3 = (undefined *)0x0;
    }
    else {
      puVar3 = (undefined *)((iVar2 + -1) * 0x50 + DAT_20009e44);
    }
    puVar1 = DAT_20009e48;
    *puVar3 = *DAT_20009e48;
    puVar3[1] = puVar1[1];
    puVar3[2] = puVar1[2];
    puVar3[3] = puVar1[3];
    puVar3[0xc] = puVar3[0xc] | 1;
    puVar3[8] = *(undefined *)(DAT_20009e40 + 7);
    local_10 = 0;
    local_f = 5;
    local_e = (undefined2)iVar2;
    local_c = 0;
    local_a = 0;
    iVar2 = tuh_control_xfer(0,&local_10,0,DAT_20009e4c);
    if (iVar2 == 0) {
      __wrap_printf(DAT_20009e58,DAT_20009e54,0x32c);
    }
  }
  return iVar2;
}


/* ===== enum_hub_clear_reset1_complete @ 20009e60 (38 bytes) ===== */

bool enum_hub_clear_reset1_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    __wrap_printf(DAT_20009e90,DAT_20009e8c,0x26c);
  }
  else {
    enum_request_set_addr();
    hub_status_pipe_queue(*(undefined *)(DAT_20009e88 + 1));
  }
  return param_3 == 0;
}


/* ===== enum_get_device_desc_complete @ 20009e94 (116 bytes) ===== */

int enum_get_device_desc_complete(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (param_3 == 0) {
    if (param_1 == 0) {
      __wrap_printf(DAT_20009f20,DAT_20009f24,0xdc);
      iVar2 = 0;
    }
    else {
      iVar2 = (param_1 + -1) * 0x50 + DAT_20009f08;
    }
    iVar1 = DAT_20009f0c;
    *(undefined2 *)(iVar2 + 4) = *(undefined2 *)(DAT_20009f0c + 8);
    *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(iVar1 + 10);
    *(undefined *)(iVar2 + 9) = *(undefined *)(iVar1 + 0xe);
    *(undefined *)(iVar2 + 10) = *(undefined *)(iVar1 + 0xf);
    *(undefined *)(iVar2 + 0xb) = *(undefined *)(iVar1 + 0x10);
    local_18 = *DAT_20009f10;
    uStack_14 = DAT_20009f10[1];
    iVar2 = tuh_control_xfer(param_1,&local_18,iVar1,DAT_20009f14);
    if (iVar2 == 0) {
      __wrap_printf(DAT_20009f20,DAT_20009f1c,DAT_20009f28);
    }
  }
  else {
    __wrap_printf(DAT_20009f20,DAT_20009f1c,DAT_20009f18);
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== enum_get_9byte_config_desc_complete @ 20009f2c (128 bytes) ===== */

int enum_get_9byte_config_desc_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined local_10;
  undefined local_f;
  undefined2 local_e;
  undefined2 local_c;
  ushort local_a;
  
  if (param_3 == 0) {
    local_a = *(ushort *)(DAT_20009fac + 2);
    if (local_a < 0x201) {
      local_10 = 0x80;
      local_f = 6;
      local_e = 0x200;
      local_c = 0;
      iVar1 = tuh_control_xfer(param_1,&local_10,DAT_20009fac,DAT_20009fb0);
      if (iVar1 == 0) {
        __wrap_printf(DAT_20009fbc,DAT_20009fb8,DAT_20009fc4);
      }
    }
    else {
      __wrap_printf(DAT_20009fbc,DAT_20009fb8,DAT_20009fc0);
      iVar1 = 0;
    }
  }
  else {
    __wrap_printf(DAT_20009fbc,DAT_20009fb8,DAT_20009fb4);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== process_device_unplugged @ 20009fc8 (222 bytes) ===== */

void process_device_unplugged(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  while (uVar2 = uVar3, uVar2 < 5) {
    uVar3 = uVar2 + 1 & 0xff;
    if ((((*(byte *)(uVar2 * 0x50 + DAT_2000a0a8) == param_1) &&
         ((param_2 == 0 || (*(byte *)(DAT_2000a0a8 + uVar2 * 0x50 + 1) == param_2)))) &&
        ((param_3 == 0 || (*(byte *)(DAT_2000a0a8 + uVar2 * 0x50 + 2) == param_3)))) &&
       (*(char *)(DAT_2000a0a8 + uVar2 * 0x50 + 0xd) != '\0')) {
      for (uVar4 = 0; iVar1 = DAT_2000a0a8, uVar4 < 2; uVar4 = uVar4 + 1 & 0xff) {
        (**(code **)(DAT_2000a0b0 + uVar4 * 0x14 + 0x10))(uVar3);
      }
      memset(uVar2 * 0x50 + DAT_2000a0a8 + 0xe,0xff,0x10);
      memset(uVar2 * 0x50 + iVar1 + 0x1e,0xff,0x12);
      hcd_device_close(param_1,uVar3);
      *(undefined *)(uVar2 * 0x50 + iVar1 + 0xd) = 0;
    }
  }
  return;
}


/* ===== parse_configuration_descriptor @ 2000a0b4 (274 bytes) ===== */

undefined4 parse_configuration_descriptor(int param_1,byte *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  undefined *puVar7;
  byte bVar8;
  
  if (param_1 == 0) {
    __wrap_printf(DAT_2000a1d0,DAT_2000a1cc,0xdc);
    puVar7 = (undefined *)0x0;
  }
  else {
    puVar7 = (undefined *)((param_1 + -1) * 0x50 + DAT_2000a1c8);
  }
  uVar1 = *(ushort *)(param_2 + 2);
  pbVar5 = param_2 + *param_2;
  while( true ) {
    if (param_2 + uVar1 <= pbVar5) {
      return 1;
    }
    if (pbVar5[1] == 0xb) {
      bVar8 = pbVar5[3];
      pbVar5 = pbVar5 + *pbVar5;
    }
    else {
      bVar8 = 1;
    }
    if (pbVar5[1] != 4) {
      __wrap_printf(DAT_2000a1d0,DAT_2000a1d4,1000);
      return 0;
    }
    uVar2 = tu_desc_get_interface_total_len
                      (pbVar5,bVar8,(int)(param_2 + uVar1) - (int)pbVar5 & 0xffff);
    if (uVar2 < 9) {
      __wrap_printf(DAT_2000a1d0,DAT_2000a1d4,0x3f8);
      return 0;
    }
    if (pbVar5[5] != 9) break;
    if (puVar7[1] == '\0') {
      uVar6 = 0;
      goto LAB_2000a192;
    }
LAB_2000a158:
    pbVar5 = pbVar5 + uVar2;
  }
  uVar6 = 0;
LAB_2000a192:
  if (uVar6 < 2) {
    iVar3 = (**(code **)(DAT_2000a1dc + uVar6 * 0x14 + 4))(*puVar7,param_1,pbVar5,uVar2);
    if (iVar3 == 0) goto code_r0x2000a1b2;
    for (bVar4 = 0; bVar4 < bVar8; bVar4 = bVar4 + 1) {
      if (puVar7[(byte)(pbVar5[2] + bVar4) + 0xe] != -1) {
        __wrap_printf(DAT_2000a1d0,DAT_2000a1d4,DAT_2000a1d8);
        return 0;
      }
      puVar7[(byte)(pbVar5[2] + bVar4) + 0xe] = (char)uVar6;
    }
    tu_edpt_bind_driver(puVar7 + 0x1e,pbVar5,uVar2,uVar6);
  }
  goto LAB_2000a158;
code_r0x2000a1b2:
  uVar6 = uVar6 + 1 & 0xff;
  goto LAB_2000a192;
}


/* ===== enum_get_config_desc_complete @ 2000a1e0 (90 bytes) ===== */

int enum_get_config_desc_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (param_3 == 0) {
    iVar1 = parse_configuration_descriptor(param_1,DAT_2000a23c);
    if (iVar1 == 0) {
      __wrap_printf(DAT_2000a250,DAT_2000a24c,DAT_2000a254);
      iVar1 = 0;
    }
    else {
      local_18 = *(undefined4 *)(DAT_2000a240 + 8);
      uStack_14 = *(undefined4 *)(DAT_2000a240 + 0xc);
      iVar1 = tuh_control_xfer(param_1,&local_18,0,DAT_2000a244);
      if (iVar1 == 0) {
        __wrap_printf(DAT_2000a250,DAT_2000a24c,DAT_2000a258);
      }
    }
  }
  else {
    __wrap_printf(DAT_2000a250,DAT_2000a24c,DAT_2000a248);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== tuh_speed_get @ 2000a25c (26 bytes) ===== */

undefined tuh_speed_get(int param_1)

{
  undefined uVar1;
  
  if (param_1 == 0) {
    uVar1 = *(undefined *)(DAT_2000a27c + 3);
  }
  else {
    uVar1 = *(undefined *)((param_1 + -1) * 0x50 + DAT_2000a278 + 3);
  }
  return uVar1;
}


/* ===== tuh_inited @ 2000a280 (6 bytes) ===== */

undefined tuh_inited(void)

{
  return *DAT_2000a288;
}


/* ===== tuh_init @ 2000a28c (234 bytes) ===== */

uint tuh_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*DAT_2000a378;
  if (uVar3 == 0) {
    memset(DAT_2000a37c,0,400);
    memset(DAT_2000a380,0,5);
    iVar1 = DAT_2000a384;
    critical_section_init(DAT_2000a384 + 0x1c);
    tu_fifo_clear(iVar1);
    *DAT_2000a388 = iVar1;
    for (uVar3 = 0; iVar1 = DAT_2000a37c, uVar3 < 5; uVar3 = uVar3 + 1 & 0xff) {
      iVar2 = uVar3 * 0x50 + DAT_2000a37c + 0x44;
      mutex_init(iVar2);
      *(int *)(iVar1 + uVar3 * 0x50 + 0x4c) = iVar2;
      iVar1 = DAT_2000a37c;
      if (iVar2 == 0) {
        __wrap_printf(DAT_2000a390,DAT_2000a38c,0x12a);
        return 0;
      }
      memset(uVar3 * 0x50 + DAT_2000a37c + 0xe,0xff,0x10);
      memset(uVar3 * 0x50 + iVar1 + 0x1e,0xff,0x12);
    }
    for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1 & 0xff) {
      (**(code **)(uVar3 * 0x14 + DAT_2000a394))();
    }
    uVar3 = hcd_init(param_1);
    if (uVar3 == 0) {
      __wrap_printf(DAT_2000a390,DAT_2000a38c,0x138);
    }
    else {
      hcd_int_enable(param_1);
      *DAT_2000a378 = 1;
    }
  }
  return uVar3;
}


/* ===== usbh_get_rhport @ 2000a398 (24 bytes) ===== */

undefined usbh_get_rhport(int param_1)

{
  undefined uVar1;
  
  if (param_1 == 0) {
    uVar1 = *DAT_2000a3b0;
  }
  else {
    uVar1 = *(undefined *)(DAT_2000a3b4 + (param_1 + -1) * 0x50);
  }
  return uVar1;
}


/* ===== usbh_edpt_control_open @ 2000a3b8 (56 bytes) ===== */

void usbh_edpt_control_open(undefined4 param_1,ushort param_2)

{
  undefined4 uVar1;
  undefined local_18;
  undefined local_17;
  ushort local_14;
  
  memset(&local_18,0,7);
  local_18 = 7;
  local_17 = 5;
  local_14 = local_14 & 0xf800 | param_2;
  uVar1 = usbh_get_rhport(param_1);
  hcd_edpt_open(uVar1,param_1,&local_18);
  return;
}


/* ===== enum_request_addr0_device_desc @ 2000a3f0 (72 bytes) ===== */

int enum_request_addr0_device_desc(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar1 = usbh_edpt_control_open(0,8);
  if (iVar1 == 0) {
    __wrap_printf(DAT_2000a44c,DAT_2000a448,DAT_2000a444);
    iVar1 = 0;
  }
  else {
    local_10 = *(undefined4 *)(DAT_2000a438 + 0x10);
    uStack_c = *(undefined4 *)(DAT_2000a438 + 0x14);
    iVar1 = tuh_control_xfer(0,&local_10,DAT_2000a440,DAT_2000a43c);
    if (iVar1 == 0) {
      __wrap_printf(DAT_2000a44c,DAT_2000a448,DAT_2000a450);
    }
  }
  return iVar1;
}


/* ===== enum_new_device @ 2000a454 (102 bytes) ===== */

int enum_new_device(undefined *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined uVar3;
  int iVar4;
  
  puVar2 = DAT_2000a4bc;
  *DAT_2000a4bc = *param_1;
  cVar1 = param_1[4];
  puVar2[1] = cVar1;
  puVar2[2] = param_1[5];
  if (cVar1 == '\0') {
    sleep_ms(500);
    iVar4 = hcd_port_connect_status(*DAT_2000a4bc);
    puVar2 = DAT_2000a4bc;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    else {
      uVar3 = hcd_port_speed_get(*DAT_2000a4bc);
      puVar2[3] = uVar3;
      enum_request_addr0_device_desc();
    }
  }
  else {
    sleep_ms(500);
    iVar4 = hub_port_get_status(DAT_2000a4bc[1],DAT_2000a4bc[2],DAT_2000a4c4,DAT_2000a4c0);
    if (iVar4 == 0) {
      __wrap_printf(DAT_2000a4d0,DAT_2000a4cc,DAT_2000a4c8);
    }
  }
  return iVar4;
}


/* ===== tuh_task @ 2000a4d4 (282 bytes) ===== */

void tuh_task(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined local_1c;
  byte local_1b;
  byte local_1a;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = tusb_inited();
  if (iVar2 != 0) {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            iVar2 = *DAT_2000a5f0;
            uVar4 = 0;
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              uVar4 = isIRQinterruptsEnabled();
            }
            disableIRQinterrupts();
            do {
            } while (**(int **)(iVar2 + 0x1c) == 0);
            DataMemoryBarrier(0x1f);
            *(undefined4 *)(iVar2 + 0x20) = uVar4;
            iVar3 = tu_fifo_read(iVar2,&local_1c);
            uVar6 = *(uint *)(iVar2 + 0x20);
            DataMemoryBarrier(0x1f);
            **(undefined4 **)(iVar2 + 0x1c) = 0;
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              enableIRQinterrupts((uVar6 & 1) == 1);
            }
            if (iVar3 == 0) {
              return;
            }
            if (local_1b == 2) break;
            if (local_1b < 3) {
              if (local_1b == 0) {
                enum_new_device(&local_1c);
              }
              else if ((local_1b == 1) &&
                      (process_device_unplugged(local_1c,(uint)local_18 & 0xff,local_18._1_1_),
                      ((uint)local_18 & 0xff) != 0)) {
                hub_status_pipe_queue();
              }
            }
            else if ((local_1b == 3) && (local_18 != (code *)0x0)) {
              (*local_18)(local_14);
            }
          }
          uVar6 = (uint)local_18 & 0xff;
          uVar7 = (uint)local_18 >> 7 & 1;
          if (local_1a != 0) break;
          if (((uint)local_18 & 0x7f) != 0) {
            __wrap_printf(DAT_2000a5f8,DAT_2000a5f4,0x17e);
            return;
          }
          usbh_control_xfer_cb(0,uVar6,local_18._1_1_,local_14);
        }
        iVar2 = (local_1a - 1) * 0x50 + DAT_2000a5fc;
        pbVar5 = (byte *)(iVar2 + ((uint)local_18 & 0x7f) * 2 + uVar7 + 0x30);
        *pbVar5 = *pbVar5 & 0xfe;
        *pbVar5 = *pbVar5 & 0xfb;
        if (((uint)local_18 & 0x7f) != 0) break;
        usbh_control_xfer_cb(local_1a,uVar6,local_18._1_1_,local_14);
      }
      uVar7 = (uint)*(byte *)(iVar2 + ((uint)local_18 & 0x7f) * 2 + uVar7 + 0x1e);
      if (1 < uVar7) break;
      (**(code **)(DAT_2000a600 + uVar7 * 0x14 + 0xc))(local_1a,uVar6,local_18._1_1_,local_14);
    }
    __wrap_printf(DAT_2000a5f8,DAT_2000a5f4,0x18d);
  }
  return;
}


/* ===== enum_get_addr0_device_desc_complete @ 2000a604 (166 bytes) ===== */

int enum_get_addr0_device_desc_complete(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    if (param_3 == 0) {
      if (*(char *)(DAT_2000a6ac + 1) == '\x01') {
        if (DAT_2000a6b0[1] == '\0') {
          hcd_port_reset(*DAT_2000a6b0);
          sleep_ms(500);
          enum_request_set_addr();
          iVar1 = 1;
        }
        else {
          iVar1 = hub_port_reset(DAT_2000a6b0[1],DAT_2000a6b0[2],0);
          if (iVar1 == 0) {
            __wrap_printf(DAT_2000a6b8,DAT_2000a6b4,DAT_2000a6c8);
            iVar1 = 0;
          }
          else {
            sleep_ms(500);
            tuh_task();
            iVar1 = hub_port_get_status(DAT_2000a6b0[1],DAT_2000a6b0[2],DAT_2000a6ac,DAT_2000a6c0);
            if (iVar1 == 0) {
              __wrap_printf(DAT_2000a6b8,DAT_2000a6b4,DAT_2000a6c4);
            }
          }
        }
      }
      else {
        __wrap_printf(DAT_2000a6b8,DAT_2000a6b4,DAT_2000a6bc);
        iVar1 = 0;
      }
    }
    else {
      if (DAT_2000a6b0[1] != '\0') {
        hub_status_pipe_queue();
      }
      iVar1 = 0;
    }
  }
  else {
    __wrap_printf(DAT_2000a6b8,DAT_2000a6b4,0x2e0);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== enum_hub_clear_reset0_complete @ 2000a6cc (30 bytes) ===== */

bool enum_hub_clear_reset0_complete(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    __wrap_printf(DAT_2000a6f0,DAT_2000a6ec,0x264);
  }
  else {
    enum_request_addr0_device_desc();
  }
  return param_3 == 0;
}


/* ===== enum_set_address_complete @ 2000a6f4 (162 bytes) ===== */

int enum_set_address_complete(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    if (param_3 == 0) {
      uVar2 = (uint)*(byte *)(param_2 + 2);
      if (uVar2 == 0) {
        __wrap_printf(DAT_2000a7b0,DAT_2000a7b8,0xdc);
        iVar1 = 0;
      }
      else {
        iVar1 = (uVar2 - 1) * 0x50 + DAT_2000a798;
      }
      *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 2;
      hcd_device_close(*DAT_2000a79c,0);
      iVar1 = usbh_edpt_control_open(uVar2,*(undefined *)(iVar1 + 8));
      if (iVar1 == 0) {
        __wrap_printf(DAT_2000a7b0,DAT_2000a7ac,0x340);
        iVar1 = 0;
      }
      else {
        local_18 = *(undefined4 *)(DAT_2000a7a0 + 0x18);
        uStack_14 = *(undefined4 *)(DAT_2000a7a0 + 0x1c);
        iVar1 = tuh_control_xfer(uVar2,&local_18,DAT_2000a7a8,DAT_2000a7a4);
        if (iVar1 == 0) {
          __wrap_printf(DAT_2000a7b0,DAT_2000a7ac,DAT_2000a7bc);
        }
      }
    }
    else {
      __wrap_printf(DAT_2000a7b0,DAT_2000a7ac,DAT_2000a7b4);
      iVar1 = 0;
    }
  }
  else {
    __wrap_printf(DAT_2000a7b0,DAT_2000a7ac,0x334);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== hcd_event_handler @ 2000a7c0 (68 bytes) ===== */

void hcd_event_handler(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *DAT_2000a804;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**(int **)(iVar5 + 0x1c) == 0);
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(iVar5 + 0x20) = uVar2;
  iVar3 = tu_fifo_write(iVar5,param_1);
  uVar4 = *(uint *)(iVar5 + 0x20);
  DataMemoryBarrier(0x1f);
  **(undefined4 **)(iVar5 + 0x1c) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  if (iVar3 == 0) {
    __wrap_printf(DAT_2000a80c,DAT_2000a808,0xa8,uVar4);
  }
  return;
}


/* ===== hcd_event_xfer_complete @ 2000a810 (38 bytes) ===== */

void hcd_event_xfer_complete
               (undefined param_1,undefined param_2,undefined4 param_3,undefined param_4,
               undefined param_5)

{
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_18;
  undefined local_17;
  undefined4 local_14;
  
  local_1c = 0;
  local_1b = 2;
  local_1a = param_1;
  local_18 = param_2;
  local_17 = param_4;
  local_14 = param_3;
  hcd_event_handler(&local_1c,param_5);
  return;
}


/* ===== hcd_event_device_attach @ 2000a836 (34 bytes) ===== */

void hcd_event_device_attach(undefined param_1,undefined4 param_2)

{
  undefined local_1c [12];
  
  memset(local_1c,0,0xc);
  local_1c[0] = param_1;
  hcd_event_handler(local_1c,param_2);
  return;
}


/* ===== hcd_event_device_remove @ 2000a858 (40 bytes) ===== */

void hcd_event_device_remove(undefined param_1,undefined4 param_2)

{
  undefined local_1c;
  undefined local_1b;
  
  memset(&local_1c,0,0xc);
  local_1b = 1;
  local_1c = param_1;
  hcd_event_handler(&local_1c,param_2);
  return;
}


/* ===== usbh_driver_set_config_complete @ 2000a880 (94 bytes) ===== */

int usbh_driver_set_config_complete(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    iVar1 = __wrap_printf(DAT_2000a8e8,DAT_2000a8e4,0xdc);
    iVar2 = 0;
  }
  else {
    iVar2 = (param_1 + -1) * 0x50 + DAT_2000a8e0;
    iVar1 = param_1;
  }
  uVar4 = (uint)(byte)(param_2 + 1);
  do {
    if (0xf < uVar4) {
LAB_2000a8cc:
      if ((uVar4 == 0x10) && (DAT_2000a8f0 != 0)) {
        iVar1 = param_1;
      }
      return iVar1;
    }
    uVar3 = (uint)*(byte *)(iVar2 + uVar4 + 0xe);
    if (uVar3 != 0xff) {
      iVar1 = (**(code **)(DAT_2000a8ec + uVar3 * 0x14 + 8))(param_1,uVar4);
      goto LAB_2000a8cc;
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while( true );
}


/* ===== enum_set_config_complete @ 2000a8f4 (76 bytes) ===== */

undefined4 enum_set_config_complete(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    if (param_1 == 0) {
      __wrap_printf(DAT_2000a94c,DAT_2000a950,0xdc);
      iVar2 = 0;
    }
    else {
      iVar2 = (param_1 + -1) * 0x50 + DAT_2000a940;
    }
    *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) | 4;
    *(undefined *)(iVar2 + 0xd) = 1;
    usbh_driver_set_config_complete(param_1,0xff);
    uVar1 = 1;
  }
  else {
    __wrap_printf(DAT_2000a94c,DAT_2000a948,DAT_2000a944);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== usbh_edpt_xfer @ 2000a954 (152 bytes) ===== */

int usbh_edpt_xfer(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 & 0x7f;
  uVar4 = param_2 >> 7;
  if (param_1 == 0) {
    __wrap_printf(DAT_2000a9f4,DAT_2000a9f0,0xdc);
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = (undefined *)((param_1 + -1) * 0x50 + DAT_2000a9ec);
  }
  if ((int)((uint)(byte)puVar2[uVar4 + uVar5 * 2 + 0x30] << 0x1f) < 0) {
    __wrap_printf(DAT_2000a9f4,DAT_2000a9fc,DAT_2000a9f8);
    iVar1 = 0;
  }
  else {
    puVar2[uVar4 + uVar5 * 2 + 0x30] = puVar2[uVar4 + uVar5 * 2 + 0x30] | 1;
    iVar1 = hcd_edpt_xfer(*puVar2,param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      pbVar3 = puVar2 + uVar4 + uVar5 * 2 + 0x30;
      *pbVar3 = *pbVar3 & 0xfe;
      *pbVar3 = *pbVar3 & 0xfb;
    }
  }
  return iVar1;
}


/* ===== usbh_edpt_open @ 2000aa00 (78 bytes) ===== */

undefined4 usbh_edpt_open(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    __wrap_printf(DAT_2000aa58,DAT_2000aa54,0xdc,param_4,param_4);
    iVar2 = 0;
  }
  else {
    iVar2 = (param_2 + -1) * 0x50 + DAT_2000aa50;
  }
  iVar2 = tu_edpt_validate(param_3,*(undefined *)(iVar2 + 3));
  if (iVar2 == 0) {
    __wrap_printf(DAT_2000aa58,DAT_2000aa60,DAT_2000aa5c);
    uVar1 = 0;
  }
  else {
    uVar1 = hcd_edpt_open(param_1,param_2,param_3);
  }
  return uVar1;
}


/* ===== _xfer_complete @ 2000aa64 (18 bytes) ===== */

void _xfer_complete(undefined4 param_1,undefined4 param_2)

{
  if (*(code **)(DAT_2000aa78 + 0x10) != (code *)0x0) {
    (**(code **)(DAT_2000aa78 + 0x10))(param_1,DAT_2000aa78,param_2);
  }
  return;
}


/* ===== tuh_control_xfer @ 2000aa7c (78 bytes) ===== */

int tuh_control_xfer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = usbh_get_rhport();
  iVar2 = DAT_2000aacc;
  memcpy(DAT_2000aacc,param_2,8);
  *(undefined4 *)(iVar2 + 0xc) = param_3;
  *(undefined *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0x10) = param_4;
  iVar2 = hcd_setup_send(uVar1,param_1,iVar2);
  if (iVar2 == 0) {
    __wrap_printf(DAT_2000aad4,DAT_2000aad0,0x4a);
  }
  return iVar2;
}


/* ===== usbh_control_xfer_cb @ 2000aad8 (138 bytes) ===== */

undefined4 usbh_control_xfer_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined uVar5;
  
  uVar4 = usbh_get_rhport();
  pcVar3 = DAT_2000ab64;
  if (param_3 != 0) {
    _xfer_complete(param_1,param_3);
    return 1;
  }
  cVar1 = DAT_2000ab64[8];
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      _xfer_complete(param_1,0);
      return 1;
    }
    if (cVar1 != '\0') {
      return 0;
    }
    DAT_2000ab64[8] = '\x01';
    sVar2 = *(short *)(pcVar3 + 6);
    if (sVar2 != 0) {
      if (*pcVar3 < '\0') {
        uVar5 = 0x80;
      }
      else {
        uVar5 = 0;
      }
      hcd_edpt_xfer(uVar4,param_1,uVar5,*(undefined4 *)(DAT_2000ab64 + 0xc),sVar2);
      return 1;
    }
  }
  pcVar3 = DAT_2000ab64;
  DAT_2000ab64[8] = '\x02';
  if (*pcVar3 < '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x80;
  }
  hcd_edpt_xfer(uVar4,param_1,uVar5,0,0);
  return 1;
}


/* ===== connection_port_reset_complete @ 2000ab68 (66 bytes) ===== */

bool connection_port_reset_complete(undefined4 param_1,int param_2,int param_3)

{
  undefined uVar1;
  undefined local_1c [4];
  undefined local_18;
  undefined local_17;
  
  if (param_3 != 0) {
    __wrap_printf(DAT_2000abb0,DAT_2000abac,0x16e);
  }
  else {
    uVar1 = *(undefined *)(param_2 + 4);
    memset(local_1c,0,0xc);
    local_1c[0] = usbh_get_rhport(param_1);
    local_18 = (undefined)param_1;
    local_17 = uVar1;
    hcd_event_handler(local_1c,0);
  }
  return param_3 == 0;
}


/* ===== hub_port_clear_feature @ 2000abb4 (84 bytes) ===== */

int hub_port_clear_feature(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0x23;
  local_17 = 1;
  local_12 = 0;
  local_16 = param_3;
  local_14 = param_2;
  iVar1 = tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    __wrap_printf(DAT_2000ac0c,DAT_2000ac08,0x61);
  }
  return iVar1;
}


/* ===== hub_port_set_feature @ 2000ac10 (84 bytes) ===== */

int hub_port_set_feature(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0x23;
  local_17 = 3;
  local_12 = 0;
  local_16 = param_3;
  local_14 = param_2;
  iVar1 = tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    __wrap_printf(DAT_2000ac68,DAT_2000ac64,0x76);
  }
  return iVar1;
}


/* ===== config_set_port_power @ 2000ac6c (46 bytes) ===== */

undefined4 config_set_port_power(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(undefined *)(DAT_2000aca0 + (param_1 + -5) * 8 + 2) = *(undefined *)(DAT_2000ac9c + 2);
    uVar1 = hub_port_set_feature(param_1,1,8,DAT_2000aca4);
  }
  else {
    __wrap_printf(DAT_2000acac,DAT_2000aca8,0xea);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== config_port_power_complete @ 2000acb0 (110 bytes) ===== */

int config_port_power_complete(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = (param_1 + -5) * 8;
    if (*(ushort *)(param_2 + 4) == (ushort)*(byte *)(DAT_2000ad20 + iVar1 + 2)) {
      iVar1 = DAT_2000ad20 + iVar1;
      iVar1 = usbh_edpt_xfer(param_1,*(undefined *)(iVar1 + 1),iVar1 + 3,1);
      if (iVar1 == 0) {
        __wrap_printf(DAT_2000ad28,DAT_2000ad24,0x102);
      }
      else {
        usbh_driver_set_config_complete(param_1,*(undefined *)((param_1 + -5) * 8 + DAT_2000ad20));
      }
    }
    else {
      iVar1 = hub_port_set_feature(param_1,(char)*(ushort *)(param_2 + 4) + '\x01',8,DAT_2000ad2c);
    }
  }
  else {
    __wrap_printf(DAT_2000ad28,DAT_2000ad24,0xfb);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== hub_port_reset @ 2000ad30 (12 bytes) ===== */

void hub_port_reset(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  hub_port_set_feature(param_1,param_2,4,param_3);
  return;
}


/* ===== connection_clear_conn_change_complete @ 2000ad3c (96 bytes) ===== */

undefined4 connection_clear_conn_change_complete(int param_1,int param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined local_1c;
  undefined local_1b;
  undefined local_18;
  undefined local_17;
  
  if (param_3 == 0) {
    uVar1 = *(undefined *)(param_2 + 4);
    if ((int)((uint)*(byte *)(DAT_2000ad9c + (param_1 + -5) * 8 + 4) << 0x1f) < 0) {
      hub_port_reset(param_1,uVar1,DAT_2000ada0);
      uVar2 = 1;
    }
    else {
      memset(&local_1c,0,0xc);
      local_1c = usbh_get_rhport(param_1);
      local_1b = 1;
      local_18 = (undefined)param_1;
      local_17 = uVar1;
      hcd_event_handler(&local_1c,0);
      uVar2 = 1;
    }
  }
  else {
    __wrap_printf(DAT_2000ada8,DAT_2000ada4,0x14f);
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== hub_port_get_status @ 2000adac (86 bytes) ===== */

int hub_port_get_status(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined local_18;
  undefined local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = 0xa3;
  local_17 = 0;
  local_16 = 0;
  local_12 = 4;
  local_14 = param_2;
  iVar1 = tuh_control_xfer(param_1,&local_18);
  if (iVar1 == 0) {
    __wrap_printf(DAT_2000ae08,DAT_2000ae04,0x90);
  }
  return iVar1;
}


/* ===== hub_init @ 2000ae0c (14 bytes) ===== */

void hub_init(void)

{
  memset(DAT_2000ae1c,0,8);
  return;
}


/* ===== hub_open @ 2000ae20 (130 bytes) ===== */

int hub_open(undefined4 param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  if (param_3[5] == 9) {
    if (param_3[6] == 0) {
      if (param_3[7] < 2) {
        if (param_4 < 0x10) {
          __wrap_printf(DAT_2000aea8,DAT_2000aea4,0xa6,param_4,param_4);
          iVar4 = 0;
        }
        else {
          pbVar5 = param_3 + *param_3;
          bVar2 = pbVar5[1];
          if ((bVar2 == 5) && (bVar2 = pbVar5[3] & 3, bVar2 == 3)) {
            iVar4 = usbh_edpt_open(param_1,param_2,pbVar5);
            iVar1 = DAT_2000aeac;
            if (iVar4 == 0) {
              __wrap_printf(DAT_2000aea8,DAT_2000aea4,0xae);
            }
            else {
              iVar3 = (param_2 + -5) * 8;
              *(byte *)(iVar3 + DAT_2000aeac) = param_3[2];
              *(byte *)(iVar1 + iVar3 + 1) = pbVar5[2];
            }
          }
          else {
            __wrap_printf(DAT_2000aea8,DAT_2000aea4,0xab,bVar2,param_4);
            iVar4 = 0;
          }
        }
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


/* ===== hub_close @ 2000aeb0 (32 bytes) ===== */

void hub_close(uint param_1)

{
  int iVar1;
  
  if (4 < param_1) {
    iVar1 = DAT_2000aed0 + (param_1 - 5) * 8;
    if (*(char *)(iVar1 + 1) != '\0') {
      memset(iVar1,0,8);
    }
  }
  return;
}


/* ===== hub_status_pipe_queue @ 2000aed4 (22 bytes) ===== */

void hub_status_pipe_queue(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_2000aeec + (param_1 + -5) * 8;
  usbh_edpt_xfer(param_1,*(undefined *)(iVar1 + 1),iVar1 + 3,1);
  return;
}


/* ===== connection_get_status_complete @ 2000aef0 (58 bytes) ===== */

undefined4 connection_get_status_complete(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    if ((int)((uint)*(byte *)(DAT_2000af2c + (param_1 + -5) * 8 + 6) << 0x1f) < 0) {
      hub_port_clear_feature(param_1,*(undefined *)(param_2 + 4),0x10,DAT_2000af30);
      uVar1 = 1;
    }
    else {
      hub_status_pipe_queue(param_1,*(undefined *)(param_2 + 4));
      uVar1 = 1;
    }
  }
  else {
    __wrap_printf(DAT_2000af38,DAT_2000af34,0x133);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== hub_set_config @ 2000af3c (68 bytes) ===== */

int hub_set_config(int param_1,uint param_2)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if (*(byte *)((param_1 + -5) * 8 + DAT_2000af80) == param_2) {
    local_18 = *DAT_2000af8c;
    uStack_14 = DAT_2000af8c[1];
    iVar1 = tuh_control_xfer(param_1,&local_18,DAT_2000af94,DAT_2000af90);
    if (iVar1 == 0) {
      __wrap_printf(DAT_2000af88,DAT_2000af84,0xe2);
    }
  }
  else {
    __wrap_printf(DAT_2000af88,DAT_2000af84,0xd1);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== hub_xfer_cb @ 2000af98 (78 bytes) ===== */

undefined4 hub_xfer_cb(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 == 0) {
    for (uVar2 = 1; uVar2 <= *(byte *)(DAT_2000afe8 + (param_1 + -5) * 8 + 2);
        uVar2 = uVar2 + 1 & 0xff) {
      iVar3 = (param_1 + -5) * 8;
      if ((int)((uint)(*(byte *)(DAT_2000afe8 + iVar3 + 3) >> uVar2) << 0x1f) < 0) {
        hub_port_get_status(param_1,uVar2,DAT_2000afe8 + iVar3 + 4,DAT_2000aff4);
        return 1;
      }
    }
    uVar1 = 1;
  }
  else {
    __wrap_printf(DAT_2000aff0,DAT_2000afec,0x11c);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== config_read_capacity_complete @ 2000aff8 (130 bytes) ===== */

undefined4 config_read_capacity_complete(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = DAT_2000b080;
  puVar1 = DAT_2000b07c;
  if (*(char *)(param_3 + 0xc) == '\0') {
    iVar5 = param_1 + -1;
    uVar4 = *DAT_2000b07c;
    *(uint *)(DAT_2000b080 + (iVar5 * 0xc + (uint)*(byte *)(param_2 + 0xd) + 1) * 8 + 4) =
         (uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18)
         + 1;
    uVar4 = puVar1[1];
    *(uint *)((iVar5 * 0xc + (uint)*(byte *)(param_2 + 0xd) + 1) * 8 + iVar2) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    *(undefined *)(iVar2 + iVar5 * 0x60 + 5) = 1;
    if (DAT_2000b084 != 0) {
      tuh_msc_mount_cb(param_1);
    }
    usbh_driver_set_config_complete(param_1,*(undefined *)(iVar5 * 0x60 + DAT_2000b080));
    uVar3 = 1;
  }
  else {
    __wrap_printf(DAT_2000b08c,DAT_2000b088,0x1d8);
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== tuh_msc_get_block_count @ 2000b090 (22 bytes) ===== */

undefined4 tuh_msc_get_block_count(int param_1,int param_2)

{
  return *(undefined4 *)(DAT_2000b0a8 + ((param_1 + -1) * 0xc + param_2 + 1) * 8 + 4);
}


/* ===== tuh_msc_get_block_size @ 2000b0ac (20 bytes) ===== */

undefined4 tuh_msc_get_block_size(int param_1,int param_2)

{
  return *(undefined4 *)(((param_1 + -1) * 0xc + param_2 + 1) * 8 + DAT_2000b0c0);
}


/* ===== tuh_msc_scsi_command @ 2000b0c4 (120 bytes) ===== */

uint tuh_msc_scsi_command(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_2000b13c;
  iVar4 = param_1 + -1;
  bVar1 = *(byte *)(DAT_2000b13c + iVar4 * 0x60 + 4);
  uVar3 = (uint)bVar1;
  if (bVar1 != 0) {
    iVar5 = iVar4 * 0x60 + DAT_2000b13c;
    memcpy(iVar5 + 0x34,param_2,0x1f);
    *(undefined *)(iVar5 + 0x28) = 1;
    *(undefined4 *)(iVar5 + 0x2c) = param_3;
    *(undefined4 *)(iVar5 + 0x30) = param_4;
    uVar3 = usbh_edpt_xfer(param_1,*(undefined *)(iVar5 + 2),iVar4 * 0x60 + iVar2 + 0x34,0x1f);
    if (uVar3 == 0) {
      __wrap_printf(DAT_2000b144,DAT_2000b140,0x8d);
    }
  }
  return uVar3;
}


/* ===== tuh_msc_read_capacity @ 2000b148 (88 bytes) ===== */

uint tuh_msc_read_capacity(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  
  bVar1 = *(byte *)(DAT_2000b1a0 + (param_1 + -1) * 0x60 + 4);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    memset(&local_38,0,0x1f);
    local_38 = DAT_2000b1a4;
    local_34 = DAT_2000b1a8;
    local_30 = 8;
    local_2c = 0x80;
    local_2a = 10;
    local_29 = 0x25;
    local_2b = param_2;
    uVar2 = tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  }
  return uVar2;
}


/* ===== tuh_msc_inquiry @ 2000b1ac (114 bytes) ===== */

uint tuh_msc_inquiry(int param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined local_40 [4];
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [21];
  
  bVar1 = *(byte *)(DAT_2000b220 + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    memset(&local_38,0,0x1f);
    local_38 = DAT_2000b224;
    local_34 = DAT_2000b228;
    local_30 = 0x24;
    local_2c = 0x80;
    local_2a = 6;
    local_2b = param_2;
    memset(local_40,0,6);
    local_40[0] = 0x12;
    local_3c = 0x24;
    memcpy(auStack_29,local_40,6);
    uVar2 = tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  }
  return uVar2;
}


/* ===== tuh_msc_test_unit_ready @ 2000b22c (78 bytes) ===== */

uint tuh_msc_test_unit_ready(int param_1,undefined param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_2b;
  undefined local_2a;
  undefined local_28;
  
  bVar1 = *(byte *)(DAT_2000b27c + (param_1 + -1) * 0x60 + 4);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    memset(&local_38,0,0x1f);
    local_38 = DAT_2000b280;
    local_34 = DAT_2000b284;
    local_2a = 6;
    local_2b = param_2;
    local_28 = param_2;
    uVar2 = tuh_msc_scsi_command(param_1,&local_38,0,param_3);
  }
  return uVar2;
}


/* ===== config_get_maxlun_complete @ 2000b288 (44 bytes) ===== */

undefined4 config_get_maxlun_complete(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  
  if (param_3 == 0) {
    cVar2 = *DAT_2000b2b4;
  }
  else {
    cVar2 = '\0';
  }
  iVar1 = DAT_2000b2b8 + (param_1 + -1) * 0x60;
  *(char *)(iVar1 + 3) = cVar2;
  *(char *)(iVar1 + 3) = cVar2 + '\x01';
  tuh_msc_test_unit_ready(param_1,0,DAT_2000b2bc);
  return 1;
}


/* ===== config_request_sense_complete @ 2000b2c0 (54 bytes) ===== */

int config_request_sense_complete(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(char *)(param_3 + 0xc) == '\0') {
    iVar1 = tuh_msc_test_unit_ready(param_1,*(undefined *)(param_2 + 0xd),DAT_2000b2f8);
    if (iVar1 == 0) {
      __wrap_printf(DAT_2000b300,DAT_2000b2fc,0x1d2);
    }
  }
  else {
    __wrap_printf(DAT_2000b300,DAT_2000b2fc,0x1d1);
    iVar1 = 0;
  }
  return iVar1;
}


/* ===== tuh_msc_request_sense @ 2000b304 (100 bytes) ===== */

void tuh_msc_request_sense
               (undefined4 param_1,undefined param_2,undefined4 param_3,undefined4 param_4)

{
  undefined local_40 [4];
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  memset(&local_38,0,0x1f);
  local_38 = DAT_2000b368;
  local_34 = DAT_2000b36c;
  local_30 = 0x12;
  local_2c = 0x80;
  local_2a = 6;
  local_2b = param_2;
  memset(local_40,0,6);
  local_40[0] = 3;
  local_3c = 0x12;
  memcpy(auStack_29,local_40,6);
  tuh_msc_scsi_command(param_1,&local_38,param_3,param_4);
  return;
}


/* ===== config_test_unit_ready_complete @ 2000b370 (52 bytes) ===== */

int config_test_unit_ready_complete(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(char *)(param_3 + 0xc) == '\0') {
    tuh_msc_read_capacity(param_1,*(undefined *)(param_2 + 0xd),DAT_2000b3a8,DAT_2000b3a4);
    iVar1 = 1;
  }
  else {
    iVar1 = tuh_msc_request_sense(param_1,*(undefined *)(param_2 + 0xd),DAT_2000b3a8,DAT_2000b3ac);
    if (iVar1 == 0) {
      __wrap_printf(DAT_2000b3b4,DAT_2000b3b0,0x1c9);
    }
  }
  return iVar1;
}


/* ===== tuh_msc_read10 @ 2000b3b8 (186 bytes) ===== */

uint tuh_msc_read10(int param_1,int param_2,undefined4 param_3,uint param_4,ushort param_5,
                   undefined4 param_6)

{
  byte bVar1;
  uint uVar2;
  undefined local_44 [2];
  ushort local_42;
  ushort local_40;
  undefined local_3d;
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  bVar1 = *(byte *)(DAT_2000b474 + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    memset(&local_38,0,0x1f,bVar1,param_3,param_4);
    local_38 = DAT_2000b478;
    local_34 = DAT_2000b47c;
    local_2b = (undefined)param_2;
    local_30 = (uint)param_5 * *(int *)(((param_1 + -1) * 0xc + param_2 + 1) * 8 + DAT_2000b474);
    local_2c = 0x80;
    local_2a = 10;
    memset(local_44,0,10);
    local_44[0] = 0x28;
    local_40 = (ushort)((param_4 << 0x18) >> 0x10) | (ushort)(param_4 >> 8) & 0xff;
    local_42 = (ushort)((param_4 >> 0x10 & 0xff) << 8) | (ushort)(byte)(param_4 >> 0x18);
    local_3d = (undefined)(param_5 >> 8);
    local_3c = (undefined)param_5;
    memcpy(auStack_29,local_44,10);
    uVar2 = tuh_msc_scsi_command(param_1,&local_38,param_3,param_6);
  }
  return uVar2;
}


/* ===== tuh_msc_write10 @ 2000b480 (180 bytes) ===== */

uint tuh_msc_write10(int param_1,int param_2,undefined4 param_3,uint param_4,ushort param_5,
                    undefined4 param_6)

{
  byte bVar1;
  uint uVar2;
  undefined local_44 [2];
  ushort local_42;
  ushort local_40;
  undefined local_3d;
  undefined local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined local_2b;
  undefined local_2a;
  undefined auStack_29 [17];
  
  bVar1 = *(byte *)(DAT_2000b534 + (param_1 + -1) * 0x60 + 5);
  uVar2 = (uint)bVar1;
  if (bVar1 != 0) {
    memset(&local_38,0,0x1f,bVar1,param_3,param_4);
    local_38 = DAT_2000b538;
    local_34 = DAT_2000b53c;
    local_2b = (undefined)param_2;
    local_30 = (uint)param_5 * *(int *)(((param_1 + -1) * 0xc + param_2 + 1) * 8 + DAT_2000b534);
    local_2a = 10;
    memset(local_44,0,10);
    local_44[0] = 0x2a;
    local_40 = (ushort)((param_4 << 0x18) >> 0x10) | (ushort)(param_4 >> 8) & 0xff;
    local_42 = (ushort)((param_4 >> 0x10 & 0xff) << 8) | (ushort)(byte)(param_4 >> 0x18);
    local_3d = (undefined)(param_5 >> 8);
    local_3c = (undefined)param_5;
    memcpy(auStack_29,local_44,10);
    uVar2 = tuh_msc_scsi_command(param_1,&local_38,param_3,param_6);
  }
  return uVar2;
}


/* ===== msch_init @ 2000b540 (16 bytes) ===== */

void msch_init(void)

{
  memset(DAT_2000b550,0,0x180);
  return;
}


/* ===== msch_close @ 2000b554 (46 bytes) ===== */

void msch_close(uint param_1)

{
  int iVar1;
  
  if (param_1 < 5) {
    iVar1 = (param_1 - 1) * 0x60 + DAT_2000b584;
    if ((*(char *)(iVar1 + 5) != '\0') && (DAT_2000b588 != 0)) {
      tuh_msc_umount_cb();
    }
    memset(iVar1,0,0x60);
  }
  return;
}


/* ===== msch_xfer_cb @ 2000b58c (338 bytes) ===== */

int msch_xfer_cb(int param_1,uint param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = DAT_2000b6e0;
  iVar8 = param_1 + -1;
  iVar2 = iVar8 * 0x60 + DAT_2000b6e0;
  iVar4 = iVar8 * 0x60 + DAT_2000b6e0 + 0x53;
  cVar1 = *(char *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x28);
  if (cVar1 == '\x02') {
    *(undefined *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x28) = 3;
    iVar7 = usbh_edpt_xfer(param_1,*(undefined *)(iVar7 + iVar8 * 0x60 + 1),iVar4,0xd);
    if (iVar7 == 0) {
      __wrap_printf(DAT_2000b6e8,DAT_2000b6e4,0x154);
    }
  }
  else if (cVar1 == '\x03') {
    *(undefined *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x28) = 0;
    pcVar6 = *(code **)(iVar7 + iVar8 * 0x60 + 0x30);
    if (pcVar6 == (code *)0x0) {
      iVar7 = 1;
    }
    else {
      (*pcVar6)(param_1,iVar2 + 0x34);
      iVar7 = 1;
    }
  }
  else if (cVar1 == '\x01') {
    uVar3 = (uint)*(byte *)(DAT_2000b6e0 + iVar8 * 0x60 + 2);
    if (((uVar3 == param_2) && (param_3 == 0)) && (param_4 == 0x1f)) {
      uVar5 = *(uint *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x3c);
      if ((uVar5 == 0) || (iVar2 = *(int *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x2c), iVar2 == 0)) {
        *(undefined *)(DAT_2000b6e0 + iVar8 * 0x60 + 0x28) = 3;
        iVar7 = usbh_edpt_xfer(param_1,*(undefined *)(iVar7 + iVar8 * 0x60 + 1),iVar4,0xd);
        if (iVar7 == 0) {
          __wrap_printf(DAT_2000b6e8,DAT_2000b6e4,0x14d);
        }
      }
      else {
        iVar7 = DAT_2000b6e0 + iVar8 * 0x60;
        *(undefined *)(iVar7 + 0x28) = 2;
        if (*(char *)(iVar7 + 0x40) < '\0') {
          uVar3 = (uint)*(byte *)(DAT_2000b6e0 + iVar8 * 0x60 + 1);
        }
        iVar7 = usbh_edpt_xfer(param_1,uVar3,iVar2,uVar5 & 0xffff);
        if (iVar7 == 0) {
          __wrap_printf(DAT_2000b6e8,DAT_2000b6e4,0x148);
        }
      }
    }
    else {
      __wrap_printf(DAT_2000b6e8,DAT_2000b6e4,0x140);
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 1;
  }
  return iVar7;
}


/* ===== msch_open @ 2000b6ec (216 bytes) ===== */

undefined4 msch_open(undefined4 param_1,int param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  
  if (param_3[6] == 6) {
    if (param_3[7] == 0x50) {
      if (param_4 < (uint)param_3[4] * 7 + 9) {
        __wrap_printf(DAT_2000b7c8,DAT_2000b7c4,0x175);
        uVar5 = 0;
      }
      else {
        iVar4 = param_2 + -1;
        pbVar6 = param_3 + *param_3;
        for (uVar3 = 0; uVar3 < 2; uVar3 = uVar3 + 1) {
          if ((pbVar6[1] != 5) || ((pbVar6[3] & 3) != 2)) {
            __wrap_printf(DAT_2000b7c8,DAT_2000b7c4,0x17c);
            return 0;
          }
          iVar2 = usbh_edpt_open(param_1,param_2,pbVar6);
          if (iVar2 == 0) {
            __wrap_printf(DAT_2000b7c8,DAT_2000b7c4,0x17d);
            return 0;
          }
          bVar1 = pbVar6[2];
          if ((char)bVar1 < '\0') {
            *(byte *)(DAT_2000b7cc + iVar4 * 0x60 + 1) = bVar1;
          }
          else {
            *(byte *)(DAT_2000b7cc + iVar4 * 0x60 + 2) = bVar1;
          }
          pbVar6 = pbVar6 + *pbVar6;
        }
        *(byte *)(iVar4 * 0x60 + DAT_2000b7cc) = param_3[2];
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* ===== msch_set_config @ 2000b7d0 (142 bytes) ===== */

int msch_set_config(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined local_20;
  undefined local_1f;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar2 = DAT_2000b860;
  iVar1 = param_1 + -1;
  if (*(byte *)(iVar1 * 0x60 + DAT_2000b860) == param_2) {
    *(undefined *)(DAT_2000b860 + iVar1 * 0x60 + 4) = 1;
    local_20 = 0xa1;
    local_1f = 0xfe;
    local_1e = 0;
    local_1c = (undefined2)param_2;
    local_1a = 1;
    iVar2 = tuh_control_xfer(param_1,&local_20,iVar1 * 0x60 + iVar2 + 3,DAT_2000b86c);
    if (iVar2 == 0) {
      __wrap_printf(DAT_2000b868,DAT_2000b864,0x1a5);
    }
  }
  else {
    __wrap_printf(DAT_2000b868,DAT_2000b864,0x192);
    iVar2 = 0;
  }
  return iVar2;
}


/* ===== tusb_init @ 2000b870 (28 bytes) ===== */

int tusb_init(void)

{
  int iVar1;
  
  iVar1 = tuh_init(0);
  if (iVar1 == 0) {
    __wrap_printf(DAT_2000b890,DAT_2000b88c,0x2d);
  }
  return iVar1;
}


/* ===== tusb_inited @ 2000b894 (14 bytes) ===== */

int tusb_inited(void)

{
  int iVar1;
  
  iVar1 = tuh_inited();
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


/* ===== tu_edpt_validate @ 2000b8a4 (156 bytes) ===== */

undefined4 tu_edpt_validate(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  
  uVar2 = (uint)*(byte *)(param_1 + 4) | (*(byte *)(param_1 + 5) & 7) << 8;
  bVar3 = *(byte *)(param_1 + 3) & 3;
  if (bVar3 == 2) {
    if (param_2 == 2) {
      if (uVar2 == 0x200) {
        uVar1 = 1;
      }
      else {
        __wrap_printf(DAT_2000b948,DAT_2000b944,0x58);
        uVar1 = 0;
      }
    }
    else if (uVar2 < 0x41) {
      uVar1 = 1;
    }
    else {
      __wrap_printf(DAT_2000b948,DAT_2000b944,0x5c);
      uVar1 = 0;
    }
  }
  else if (bVar3 == 3) {
    if (param_2 == 2) {
      uVar4 = 0x400;
    }
    else {
      uVar4 = 0x40;
    }
    if (uVar4 < uVar2) {
      __wrap_printf(DAT_2000b948,DAT_2000b944,99);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (bVar3 == 1) {
    uVar4 = DAT_2000b940;
    if (param_2 == 2) {
      uVar4 = 0x400;
    }
    if (uVar4 < uVar2) {
      __wrap_printf(DAT_2000b948,DAT_2000b944,0x50);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== tu_edpt_bind_driver @ 2000b94c (42 bytes) ===== */

void tu_edpt_bind_driver(int param_1,byte *param_2,uint param_3,undefined param_4)

{
  byte bVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + bVar1 & 0xffff) {
    if (param_2[1] == 5) {
      *(undefined *)(param_1 + (param_2[2] & 0x7f) * 2 + (uint)(param_2[2] >> 7)) = param_4;
    }
    bVar1 = *param_2;
    param_2 = param_2 + bVar1;
  }
  return;
}


/* ===== tu_desc_get_interface_total_len @ 2000b976 (62 bytes) ===== */

void tu_desc_get_interface_total_len(byte *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar2 = 0;
  pbVar3 = param_1;
  do {
    uVar4 = param_2 - 1 & 0xff;
    if (param_2 == 0) {
      return;
    }
    pbVar3 = pbVar3 + *pbVar3;
    for (uVar2 = *param_1 + uVar2; uVar2 = uVar2 & 0xffff, param_2 = uVar4, uVar2 < param_3;
        uVar2 = bVar1 + uVar2) {
      if (pbVar3[1] == 0xb) {
        return;
      }
      if ((pbVar3[1] == 4) && (pbVar3[3] == 0)) break;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + bVar1;
    }
  } while( true );
}


/* ===== advance_pointer @ 2000b9b4 (24 bytes) ===== */

uint advance_pointer(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3 & 0xffff;
  if ((uVar1 < param_2) || (*(ushort *)(param_1 + 0xc) < uVar1)) {
    uVar1 = uVar1 + *(ushort *)(param_1 + 10) & 0xffff;
  }
  return uVar1;
}


/* ===== backward_pointer @ 2000b9cc (30 bytes) ===== */

uint backward_pointer(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_2 < param_3) ||
     (uVar1 = param_2 - param_3 & 0xffff, *(ushort *)(param_1 + 0xc) < uVar1)) {
    uVar1 = (param_2 - param_3 & 0xffff) - (uint)*(ushort *)(param_1 + 10) & 0xffff;
  }
  return uVar1;
}


/* ===== get_relative_pointer @ 2000b9ea (16 bytes) ===== */

uint get_relative_pointer(int param_1,uint param_2)

{
  for (; *(ushort *)(param_1 + 4) <= param_2; param_2 = param_2 - *(ushort *)(param_1 + 4) & 0xffff)
  {
  }
  return param_2;
}


/* ===== _tu_fifo_peek @ 2000b9fa (80 bytes) ===== */

bool _tu_fifo_peek(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_3 - param_4 & 0xffff;
  if (param_3 < param_4) {
    uVar3 = uVar3 - *(ushort *)((int)param_1 + 10) & 0xffff;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 1);
  if (uVar4 < uVar3) {
    uVar1 = backward_pointer(param_1,param_3,uVar4);
    *(undefined2 *)(param_1 + 4) = uVar1;
    uVar3 = uVar4;
  }
  if (uVar3 != 0) {
    iVar2 = get_relative_pointer(param_1,param_4);
    memcpy(param_2,*param_1 + (uint)*(ushort *)((int)param_1 + 6) * iVar2);
  }
  return uVar3 != 0;
}


/* ===== tu_fifo_read @ 2000ba4a (66 bytes) ===== */

uint tu_fifo_read(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x18),0xffffffff);
  }
  uVar2 = _tu_fifo_peek(param_1,param_2,*(undefined2 *)(param_1 + 0xe),
                        *(undefined2 *)(param_1 + 0x10));
  uVar1 = advance_pointer(param_1,*(undefined2 *)(param_1 + 0x10),uVar2 & 0xffff);
  *(undefined2 *)(param_1 + 0x10) = uVar1;
  if (*(int *)(param_1 + 0x18) != 0) {
    mutex_exit();
  }
  return uVar2;
}


/* ===== tu_fifo_write @ 2000ba8c (108 bytes) ===== */

char tu_fifo_write(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  short sVar5;
  
  if (param_1[5] != 0) {
    mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms(param_1[5],0xffffffff);
  }
  uVar1 = *(ushort *)((int)param_1 + 0xe);
  sVar5 = uVar1 - *(ushort *)(param_1 + 4);
  if (uVar1 < *(ushort *)(param_1 + 4)) {
    sVar5 = sVar5 - *(short *)((int)param_1 + 10);
  }
  if ((*(short *)(param_1 + 1) != sVar5) || (cVar2 = *(char *)(param_1 + 2), cVar2 != '\0')) {
    iVar4 = get_relative_pointer(param_1,uVar1);
    memcpy((uint)*(ushort *)((int)param_1 + 6) * iVar4 + *param_1,param_2);
    uVar3 = advance_pointer(param_1,uVar1,1);
    *(undefined2 *)((int)param_1 + 0xe) = uVar3;
    if (param_1[5] == 0) {
      cVar2 = '\x01';
    }
    else {
      mutex_exit();
      cVar2 = '\x01';
    }
  }
  return cVar2;
}


/* ===== tu_fifo_clear @ 2000baf8 (76 bytes) ===== */

undefined4 tu_fifo_clear(int param_1)

{
  ushort uVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x14),0xffffffff);
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
              (*(int *)(param_1 + 0x18),0xffffffff);
  }
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  uVar1 = *(short *)(param_1 + 4) * 2 - 1;
  *(ushort *)(param_1 + 0xc) = uVar1;
  *(ushort *)(param_1 + 10) = ~uVar1;
  if (*(int *)(param_1 + 0x14) != 0) {
    mutex_exit();
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    mutex_exit();
  }
  return 1;
}


/* ===== __aeabi_idiv0 @ 2000bb44 (2 bytes) ===== */

void __aeabi_idiv0(void)

{
  return;
}


/* ===== memcmp @ 2000bb48 (70 bytes) ===== */

int memcmp(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  
  if (3 < param_3) {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_2000bb6e;
    do {
      if (*param_1 != *param_2) goto LAB_2000bb6e;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_2000bb6e:
  iVar1 = 0;
  do {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    bVar2 = param_3 - 1 != iVar1;
    iVar1 = iVar1 + 1;
  } while (bVar2);
  return 0;
}


/* ===== strchr @ 2000bb90 (182 bytes) ===== */

uint * strchr(uint *param_1,char param_2)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == '\0') {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if (*(char *)param_1 == '\0') {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar4 = *param_1 + DAT_2000bc48 & ~*param_1;
    while ((uVar4 & DAT_2000bc4c) == 0) {
      puVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      uVar4 = *puVar1 + DAT_2000bc48 & ~*puVar1;
    }
    cVar3 = *(char *)param_1;
    while (cVar3 != '\0') {
      pcVar2 = (char *)((int)param_1 + 1);
      param_1 = (uint *)((int)param_1 + 1);
      cVar3 = *pcVar2;
    }
  }
  else {
    uVar4 = (uint)param_1 & 3;
    while (uVar4 != 0) {
      if (*(char *)param_1 == '\0') {
        return (uint *)0x0;
      }
      if (*(char *)param_1 == param_2) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar6 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    uVar5 = *param_1;
    uVar4 = uVar6 ^ uVar5;
    if (((uVar4 + DAT_2000bc48 & ~uVar4 | uVar5 + DAT_2000bc48 & ~uVar5) & DAT_2000bc4c) != 0)
    goto LAB_2000bbe6;
    do {
      uVar4 = param_1[1];
      uVar5 = uVar4 ^ uVar6;
      param_1 = param_1 + 1;
    } while (((uVar4 + DAT_2000bc48 & ~uVar4 | uVar5 + DAT_2000bc48 & ~uVar5) & DAT_2000bc4c) == 0);
    cVar3 = *(char *)param_1;
    while (cVar3 != '\0') {
      if (param_2 == cVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
LAB_2000bbe6:
      cVar3 = *(char *)param_1;
    }
    param_1 = (uint *)0x0;
  }
  return param_1;
}


/* ===== strlen @ 2000bc50 (84 bytes) ===== */

int strlen(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = (uint)param_1 & 3;
  puVar2 = param_1;
  while (uVar1 != 0) {
    if (*(char *)puVar2 == '\0') goto LAB_2000bc68;
    puVar2 = (uint *)((int)puVar2 + 1);
    uVar1 = (uint)puVar2 & 3;
  }
  uVar1 = *puVar2 + DAT_2000bca4 & ~*puVar2;
  puVar3 = puVar2;
  while ((puVar2 = puVar3, (uVar1 & DAT_2000bca8) == 0 &&
         (puVar2 = puVar3 + 1, (puVar3[1] + DAT_2000bca4 & ~puVar3[1] & DAT_2000bca8) == 0))) {
    puVar2 = puVar3 + 2;
    puVar3 = puVar3 + 2;
    uVar1 = *puVar2 + DAT_2000bca4 & ~*puVar2;
  }
  for (; *(char *)puVar2 != '\0'; puVar2 = (uint *)((int)puVar2 + 1)) {
  }
LAB_2000bc68:
  return (int)puVar2 - (int)param_1;
}


/* ===== ____get_current_exception_veneer @ 2000bcb0 (10 bytes) ===== */

void ____get_current_exception_veneer(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x2000bcb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_2000bcbc)(param_1);
  return;
}


/* ===== mutex_enter_blocking @ 2000bcc0 (72 bytes) ===== */

void mutex_enter_blocking(int **param_1)

{
  bool bVar1;
  undefined uVar2;
  uint uVar3;
  
  uVar2 = (undefined)DAT_d0000000;
  while( true ) {
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**param_1 == 0);
    DataMemoryBarrier(0x1f);
    if (*(char *)(param_1 + 1) < '\0') break;
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    WaitForEvent();
  }
  *(undefined *)(param_1 + 1) = uVar2;
  DataMemoryBarrier(0x1f);
  **param_1 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}


/* ===== mutex_try_enter @ 2000bd08 (70 bytes) ===== */

undefined4 mutex_try_enter(int **param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**param_1 == 0);
  DataMemoryBarrier(0x1f);
  if (*(char *)(param_1 + 1) < 0) {
    *(undefined *)(param_1 + 1) = (undefined)DAT_d0000000;
    uVar2 = 1;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    *param_2 = (int)*(char *)(param_1 + 1);
    uVar2 = 0;
  }
  DataMemoryBarrier(0x1f);
  **param_1 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return uVar2;
}


/* ===== mutex_enter_block_until @ 2000bd50 (126 bytes) ===== */

undefined4
mutex_enter_block_until(int **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (undefined)DAT_d0000000;
  if (*param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_2000bdd8,0x7a,DAT_2000bdd4,DAT_2000bdd0);
  }
  do {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**param_1 == 0);
    DataMemoryBarrier(0x1f);
    if (*(char *)(param_1 + 1) < '\0') {
      *(undefined *)(param_1 + 1) = uVar2;
      DataMemoryBarrier(0x1f);
      **param_1 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar4 & 1) == 1);
      }
      return 1;
    }
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    iVar3 = best_effort_wfe_or_timeout(param_3,param_4);
  } while (iVar3 == 0);
                    /* WARNING: Read-only address (ram,0xd0000000) is written */
  return 0;
}


/* ===== mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms @ 2000bddc (104 bytes) ===== */

/* WARNING: Removing unreachable block (ram,0x2000be10) */

void mutex_enter_timeout_ms__or__recursive_mutex_enter_timeout_ms
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = time_us_64();
  if ((longlong)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    __assert_func(DAT_2000be4c,0x3f,DAT_2000be48,DAT_2000be44);
  }
  lVar3 = __wrap___aeabi_lmul(param_2,0,1000,0);
  iVar1 = (int)(lVar3 + uVar2 >> 0x20);
  if (lVar3 + uVar2 < uVar2) {
    iVar1 = -1;
  }
  if (-1 < iVar1) {
    mutex_enter_block_until(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_2000be4c,0x3f,DAT_2000be48,DAT_2000be44);
}


/* ===== mutex_exit @ 2000be50 (62 bytes) ===== */

void mutex_exit(int **param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**param_1 == 0);
  DataMemoryBarrier(0x1f);
  if (-1 < *(char *)(param_1 + 1)) {
    *(undefined *)(param_1 + 1) = 0xff;
    DataMemoryBarrier(0x1f);
    **param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_func(DAT_2000be98,0xa9,DAT_2000be94,DAT_2000be90);
}


/* ===== spi_write_read_blocking @ 2000be9c (66 bytes) ===== */

uint spi_write_read_blocking(int param_1,byte *param_2,undefined *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_4;
  uVar2 = param_4;
  while ((param_4 | uVar2) != 0) {
    if (((uVar2 != 0) && (*(int *)(param_1 + 0xc) << 0x1e < 0)) && (param_4 < uVar2 + 8)) {
      *(uint *)(param_1 + 8) = (uint)*param_2;
      uVar2 = uVar2 - 1;
      param_2 = param_2 + 1;
    }
    if ((param_4 != 0) && (*(int *)(param_1 + 0xc) << 0x1d < 0)) {
      *param_3 = (char)*(undefined4 *)(param_1 + 8);
      param_4 = param_4 - 1;
      param_3 = param_3 + 1;
    }
  }
  return uVar1;
}


/* ===== spi_write_blocking @ 2000bede (58 bytes) ===== */

void spi_write_blocking(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(param_1 + 0xc) << 0x1e);
    *(uint *)(param_1 + 8) = (uint)*(byte *)(param_2 + uVar1);
  }
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1d < 0);
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1b < 0);
  do {
  } while (*(int *)(param_1 + 0xc) << 0x1d < 0);
  *(undefined4 *)(param_1 + 0x20) = 1;
  return;
}


/* ===== spi_read_blocking @ 2000bf18 (62 bytes) ===== */

uint spi_read_blocking(int param_1,undefined4 param_2,undefined *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_4;
  uVar2 = param_4;
  while ((param_4 | uVar2) != 0) {
    if (((uVar2 != 0) && (*(int *)(param_1 + 0xc) << 0x1e < 0)) && (param_4 < uVar2 + 8)) {
      *(undefined4 *)(param_1 + 8) = param_2;
      uVar2 = uVar2 - 1;
    }
    if ((param_4 != 0) && (*(int *)(param_1 + 0xc) << 0x1d < 0)) {
      *param_3 = (char)*(undefined4 *)(param_1 + 8);
      param_4 = param_4 - 1;
      param_3 = param_3 + 1;
    }
  }
  return uVar1;
}


