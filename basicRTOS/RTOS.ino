volatile unsigned int reg_0;
volatile unsigned int reg_1;
volatile unsigned int reg_2;
volatile unsigned int reg_3;
volatile unsigned int reg_4;
volatile unsigned int reg_5;
volatile unsigned int reg_6;
volatile unsigned int reg_7;
volatile unsigned int reg_8;
volatile unsigned int reg_9;
volatile unsigned int reg_10;
volatile unsigned int reg_11;
volatile unsigned int reg_12;
volatile unsigned int reg_13;
volatile unsigned int reg_14;
volatile unsigned int reg_15;
volatile unsigned int reg_16;
volatile unsigned int reg_17;
volatile unsigned int reg_18;
volatile unsigned int reg_19;
volatile unsigned int reg_20;
volatile unsigned int reg_21;
volatile unsigned int reg_22;
volatile unsigned int reg_23;
volatile unsigned int reg_24;
volatile unsigned int reg_25;
volatile unsigned int reg_26;
volatile unsigned int reg_27;
volatile unsigned int reg_28;
volatile unsigned int reg_29;
volatile unsigned int reg_30;
volatile unsigned int reg_31;

void setup() {
  // put your setup code here, to run once:
  contextSave();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void contextSave() {
  asm ("sts (reg_0), r0 \n");
  asm ("sts (reg_1), r1 \n");
  asm ("sts (reg_2), r2 \n");
  asm ("sts (reg_3), r3 \n");
  asm ("sts (reg_4), r4 \n");
  asm ("sts (reg_5), r5 \n");
  asm ("sts (reg_6), r6 \n");
  asm ("sts (reg_7), r7 \n");
  asm ("sts (reg_8), r8 \n");
  asm ("sts (reg_9), r9 \n");
  asm ("sts (reg_10), r10 \n");
  asm ("sts (reg_11), r11 \n");
  asm ("sts (reg_12), r12 \n");
  asm ("sts (reg_13), r13 \n");
  asm ("sts (reg_14), r14 \n");
  asm ("sts (reg_15), r15 \n");
  asm ("sts (reg_16), r16 \n");
  asm ("sts (reg_17), r17 \n");
  asm ("sts (reg_18), r18 \n");
  asm ("sts (reg_19), r19 \n");
  asm ("sts (reg_20), r20 \n");
  asm ("sts (reg_21), r21 \n");
  asm ("sts (reg_22), r22 \n");
  asm ("sts (reg_23), r23 \n");
  asm ("sts (reg_24), r24 \n");
  asm ("sts (reg_25), r25 \n");
  asm ("sts (reg_26), r26 \n");
  asm ("sts (reg_27), r27 \n");
  asm ("sts (reg_28), r28 \n");
  asm ("sts (reg_29), r29 \n");
  asm ("sts (reg_30), r30 \n");
  asm ("sts (reg_31), r31 \n");
}
void contextLoad() {
  asm ("sts r0, (reg_0) \n");
  asm ("ldi r1, (reg_1) \n");
  asm ("sts r2, (reg_2) \n");
  asm ("sts r3, (reg_3) \n");
  asm ("sts r4, (reg_4) \n");
  asm ("sts r5, (reg_5) \n");
  asm ("sts r6, (reg_6) \n");
  asm ("ldi r7, (reg_7) \n");
  asm ("sts r8, (reg_8) \n");
  asm ("sts r9, (reg_9) \n");
  asm ("sts r10, (reg_10) \n");
  asm ("sts r11, (reg_11) \n");
  asm ("sts r12, (reg_12) \n");
  asm ("ldi r13, (reg_13) \n");
  asm ("sts r14, (reg_14) \n");
  asm ("sts r15, (reg_15) \n");
  asm ("sts r16, (reg_16) \n");
  asm ("sts r17, (reg_17) \n");
  asm ("sts r18, (reg_18) \n");
  asm ("ldi r19, (reg_19) \n");
  asm ("sts r20, (reg_20) \n");
  asm ("sts r21, (reg_21) \n");
  asm ("sts r22, (reg_22) \n");
  asm ("sts r23, (reg_23) \n");
  asm ("sts r24, (reg_24) \n");
  asm ("ldi r25, (reg_25) \n");
  asm ("sts r26, (reg_26) \n");
  asm ("sts r27, (reg_37) \n");
  asm ("sts r28, (reg_28) \n");
  asm ("sts r29, (reg_29) \n");
  asm ("sts r30, (reg_30) \n");
  asm ("sts r31, (reg_31) \n");
}
