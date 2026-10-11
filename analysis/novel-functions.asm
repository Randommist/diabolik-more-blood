000b3dd8 addiu $sp, $sp, -0xc0
000b3ddc swc1 $f20, 0xa0($sp)
000b3de0 swc1 $f22, 0xa4($sp)
000b3de4 sw $s0, 0xa8($sp)
000b3de8 sw $s1, 0xac($sp)
000b3dec sw $s2, 0xb0($sp)
000b3df0 sw $s3, 0xb4($sp)
000b3df4 sw $ra, 0xb8($sp)
000b3df8 jal 0x45e30
000b3dfc move $a0, $sp
000b3e00 lui $s2, 0x16
000b3e04 addiu $s2, $s2, -0x5858
000b3e08 jal 0x455c8
000b3e0c move $a0, $s2
000b3e10 bgez $v0, 0xb3e28
000b3e14 ori $s1, $zero, 1
000b3e18 jal 0x6e8a0
000b3e1c nop 
000b3e20 b 0xb3f54
000b3e24 nop 
000b3e28 ori $a0, $zero, 0x80
000b3e2c sb $s1, 2($sp)
000b3e30 sh $a0, 0x10($sp)
000b3e34 jal 0x375bc
000b3e38 move $a0, $zero
000b3e3c move $a0, $v0
000b3e40 lui $s0, 0xa
000b3e44 slti $a1, $a0, 2
000b3e48 beqz $a1, 0xb3e68
000b3e4c addiu $s0, $s0, 0x7428
000b3e50 bltzl $a0, 0xb3e84
000b3e54 lh $a1, 0x204($s0)
000b3e58 blez $a0, 0xb3e78
000b3e5c ori $a0, $zero, 0x3c
000b3e60 b 0xb3e80
000b3e64 sh $s1, ($sp)
000b3e68 ori $a1, $zero, 3
000b3e6c bnel $a0, $a1, 0xb3e84
000b3e70 lh $a1, 0x204($s0)
000b3e74 ori $a0, $zero, 0x3c
000b3e78 b 0xb3e80
000b3e7c sh $a0, ($sp)
000b3e80 lh $a1, 0x204($s0)
000b3e84 lh $a0, ($sp)
000b3e88 slt $a1, $a1, $a0
000b3e8c bnel $a1, $zero, 0xb3e94
000b3e90 sh $a0, 0x204($s0)
000b3e94 ori $a0, $zero, 0xa
000b3e98 sb $a0, 0x18($sp)
000b3e9c lui $a0, 0x32
000b3ea0 addiu $s3, $a0, -0xcec
000b3ea4 lw $a1, 8($s3)
000b3ea8 lw $a0, 0x20($s3)
000b3eac lw $a2, 0x14($s3)
000b3eb0 sll $a0, $a0, 0x18
000b3eb4 mtc1 $zero, $f20
000b3eb8 sra $t0, $a0, 0x18
000b3ebc mov.s $f12, $f20
000b3ec0 lw $a3, 0x10($s3)
000b3ec4 sll $a0, $a2, 0x10
000b3ec8 sra $t1, $a0, 0x10
000b3ecc sll $a0, $a3, 0x10
000b3ed0 move $a3, $t1
000b3ed4 move $a2, $t0
000b3ed8 lui $t1, 0x3f80
000b3edc sra $t0, $a0, 0x10
000b3ee0 mtc1 $t1, $f22
000b3ee4 move $a0, $s2
000b3ee8 jal 0x45c04
000b3eec mov.s $f13, $f22
000b3ef0 lw $a0, 0x20($s3)
000b3ef4 lw $a1, 8($s3)
000b3ef8 mov.s $f12, $f20
000b3efc lw $a3, 0x14($s3)
000b3f00 mov.s $f13, $f22
000b3f04 sll $a2, $a0, 0x18
000b3f08 lw $a0, 0x10($s3)
000b3f0c sll $a3, $a3, 0x10
000b3f10 sll $t0, $a0, 0x10
000b3f14 lui $a0, 0x16
000b3f18 addiu $s3, $a0, -0x584c
000b3f1c sra $a2, $a2, 0x18
000b3f20 sra $a3, $a3, 0x10
000b3f24 sra $t0, $t0, 0x10
000b3f28 jal 0x45c04
000b3f2c move $a0, $s3
000b3f30 sb $s1, 0x1d8($s0)
000b3f34 move $a0, $s2
000b3f38 jal 0x45eb0
000b3f3c move $a1, $sp
000b3f40 sh $s1, ($sp)
000b3f44 sh $zero, 0x10($sp)
000b3f48 move $a0, $s3
000b3f4c jal 0x45eb0
000b3f50 move $a1, $sp
000b3f54 lwc1 $f20, 0xa0($sp)
000b3f58 lwc1 $f22, 0xa4($sp)
000b3f5c lw $s0, 0xa8($sp)
000b3f60 lw $s1, 0xac($sp)
000b3f64 lw $s2, 0xb0($sp)
000b3f68 lw $s3, 0xb4($sp)
000b3f6c lw $ra, 0xb8($sp)
000b3f70 jr $ra
000b3f74 addiu $sp, $sp, 0xc0
000b3f78 addiu $sp, $sp, -0xb0
000b3f7c sw $s0, 0xa0($sp)
000b3f80 sw $ra, 0xa4($sp)
000b3f84 jal 0x45e30
000b3f88 move $a0, $sp
000b3f8c lui $s0, 0xa
000b3f90 addiu $s0, $s0, 0x7428
000b3f94 lb $a1, 0x1d8($s0)
000b3f98 ori $a0, $zero, 1
000b3f9c bne $a1, $a0, 0xb3fc8
000b3fa0 ori $a0, $zero, 2
000b3fa4 sb $a0, 2($sp)
000b3fa8 jal 0x375bc
000b3fac move $a0, $zero
000b3fb0 move $a0, $v0
000b3fb4 slti $a1, $a0, 2
000b3fb8 bnez $a1, 0xb3fdc
000b3fbc nop 
000b3fc0 b 0xb3ff8
000b3fc4 ori $a1, $zero, 3
000b3fc8 move $v0, $zero
000b3fcc lw $s0, 0xa0($sp)
000b3fd0 lw $ra, 0xa4($sp)
000b3fd4 jr $ra
000b3fd8 addiu $sp, $sp, 0xb0
000b3fdc bltzl $a0, 0xb4014
000b3fe0 lh $a1, 0x204($s0)
000b3fe4 blez $a0, 0xb4004
000b3fe8 ori $a0, $zero, 0x1e
000b3fec b 0xb400c
000b3ff0 ori $a0, $zero, 6
000b3ff4 ori $a1, $zero, 3
000b3ff8 bnel $a0, $a1, 0xb4014
000b3ffc lh $a1, 0x204($s0)
000b4000 ori $a0, $zero, 0x1e
000b4004 b 0xb4010
000b4008 sh $a0, ($sp)
000b400c sh $a0, ($sp)
000b4010 lh $a1, 0x204($s0)
000b4014 lh $a0, ($sp)
000b4018 slt $a1, $a1, $a0
000b401c bnel $a1, $zero, 0xb4024
000b4020 sh $a0, 0x204($s0)
000b4024 lui $a0, 0x16
000b4028 move $a1, $sp
000b402c jal 0x45eb0
000b4030 addiu $a0, $a0, -0x5858
000b4034 lui $a0, 0x16
000b4038 move $a1, $sp
000b403c jal 0x45eb0
000b4040 addiu $a0, $a0, -0x584c
000b4044 lh $v0, ($sp)
000b4048 sb $zero, 0x1d8($s0)
000b404c lw $s0, 0xa0($sp)
000b4050 lw $ra, 0xa4($sp)
000b4054 jr $ra
000b4058 addiu $sp, $sp, 0xb0
000b405c addiu $sp, $sp, -0x20
000b4060 sw $a0, ($sp)
000b4064 lb $a0, ($sp)
000b4068 sw $s1, 8($sp)
000b406c lui $s1, 0x12b
000b4070 slti $a1, $a0, 3
000b4074 sw $s0, 4($sp)
000b4078 sw $s2, 0xc($sp)
000b407c sw $s3, 0x10($sp)
000b4080 sw $s4, 0x14($sp)
000b4084 sw $ra, 0x18($sp)
000b4088 beqz $a1, 0xb40b0
000b408c addiu $s0, $s1, -0x4c58
000b4090 blez $a0, 0xb411c
000b4094 slti $a0, $a0, 2
000b4098 bnel $a0, $zero, 0xb40d0
000b409c lb $a1, 1($sp)
000b40a0 jal 0x6ec18
000b40a4 nop 
000b40a8 b 0xb4120
000b40ac lh $a0, 0xbc8($s0)
000b40b0 slti $a1, $a0, 4
000b40b4 bnez $a1, 0xb4104
000b40b8 slti $a0, $a0, 5
000b40bc bnez $a0, 0xb4110
000b40c0 lui $a1, 8
000b40c4 b 0xb4120
000b40c8 lh $a0, 0xbc8($s0)
000b40cc lb $a1, 1($sp)
000b40d0 bltz $a1, 0xb40e4
000b40d4 lb $a0, 2($sp)
000b40d8 sll $a1, $a1, 0x18
000b40dc sra $a1, $a1, 0x18
000b40e0 sh $a1, 0xbc6($s0)
000b40e4 bltz $a0, 0xb40f4
000b40e8 sll $a0, $a0, 0x18
000b40ec sra $a0, $a0, 0x18
000b40f0 sh $a0, 0xbca($s0)
000b40f4 jal 0x6ebec
000b40f8 nop 
000b40fc b 0xb4120
000b4100 lh $a0, 0xbc8($s0)
000b4104 ori $a0, $zero, 1
000b4108 b 0xb411c
000b410c sb $a0, 0xbc4($s0)
000b4110 ori $a0, $zero, 1
000b4114 addiu $a1, $a1, 0x3f78
000b4118 sh $a0, 0xa($a1)
000b411c lh $a0, 0xbc8($s0)
000b4120 blez $a0, 0xb41a4
000b4124 addiu $s3, $s0, 0xc
000b4128 lui $a1, 0x16
000b412c sh $zero, 0xbc8($s0)
000b4130 move $a0, $s3
000b4134 jal 0x137734
000b4138 addiu $a1, $a1, -0x5840
000b413c lh $a0, 8($s0)
000b4140 addiu $a1, $zero, 0x597c
000b4144 mult $a0, $a1
000b4148 lui $s2, 0xfe
000b414c addiu $s2, $s2, -0x2a0
000b4150 addiu $a0, $s0, 0x5e8
000b4154 mflo $a1
000b4158 jal 0x137734
000b415c addu $a1, $a1, $s2
000b4160 lh $s4, 0xa($s0)
000b4164 negu $s4, $s4
000b4168 bgez $s4, 0xb419c
000b416c nop 
000b4170 lh $a0, 8($s0)
000b4174 addiu $a1, $zero, 0x597c
000b4178 addu $a0, $a0, $s4
000b417c mult $a0, $a1
000b4180 move $a0, $s3
000b4184 mflo $a1
000b4188 jal 0x1382e0
000b418c addu $a1, $a1, $s2
000b4190 addiu $s4, $s4, 1
000b4194 bltzl $s4, 0xb4174
000b4198 lh $a0, 8($s0)
000b419c jal 0x6ebec
000b41a0 sh $zero, -0x4c58($s1)
000b41a4 lw $s0, 4($sp)
000b41a8 lw $s1, 8($sp)
000b41ac lw $s2, 0xc($sp)
000b41b0 lw $s3, 0x10($sp)
000b41b4 lw $s4, 0x14($sp)
000b41b8 lw $ra, 0x18($sp)
000b41bc jr $ra
000b41c0 addiu $sp, $sp, 0x20
000b41c4 beqz $a0, 0xb41f0
000b41c8 lui $t0, 0x118
000b41cc addiu $t0, $t0, -0x6d60
000b41d0 lh $t1, 0x2a6e($t0)
000b41d4 lh $t0, 0x2a72($t0)
000b41d8 sra $t2, $t1, 1
000b41dc srl $t2, $t2, 0x1f
000b41e0 addu $t1, $t1, $t2
000b41e4 sra $t1, $t1, 1
000b41e8 addu $t0, $t0, $t1
000b41ec sh $t0, ($a0)
000b41f0 beqz $a1, 0xb421c
000b41f4 lui $a0, 0x118
000b41f8 addiu $a0, $a0, -0x6d60
000b41fc lh $t0, 0x2a70($a0)
000b4200 lh $a0, 0x2a74($a0)
000b4204 sra $t1, $t0, 1
000b4208 srl $t1, $t1, 0x1f
000b420c addu $t0, $t0, $t1
000b4210 sra $t0, $t0, 1
000b4214 addu $a0, $a0, $t0
000b4218 sh $a0, ($a1)
000b421c beqz $a2, 0xb4230
000b4220 lui $a0, 0x118
000b4224 addiu $a0, $a0, -0x6d60
000b4228 lh $a0, 0x2a6e($a0)
000b422c sh $a0, ($a2)
000b4230 beqz $a3, 0xb4244
000b4234 lui $a0, 0x118
000b4238 addiu $a0, $a0, -0x6d60
000b423c lh $a0, 0x2a70($a0)
000b4240 sh $a0, ($a3)
000b4244 jr $ra
000b4248 nop 
000b424c addiu $sp, $sp, -0x20
000b4250 ori $a0, $zero, 9
000b4254 ori $a1, $zero, 0xd
000b4258 sw $a0, ($sp)
000b425c ori $a0, $zero, 1
000b4260 sw $a1, 4($sp)
000b4264 ori $a1, $zero, 0xa
000b4268 sw $a0, 8($sp)
000b426c ori $a0, $zero, 0x20
000b4270 sw $a1, 0xc($sp)
000b4274 sw $a0, 0x10($sp)
000b4278 move $a0, $sp
000b427c ori $a1, $zero, 0x7f
000b4280 move $a2, $zero
000b4284 sw $ra, 0x14($sp)
000b4288 jal 0xa6ab8
000b428c ori $a3, $zero, 0xe6
000b4290 lw $ra, 0x14($sp)
000b4294 jr $ra
000b4298 addiu $sp, $sp, 0x20
000b429c sll $a2, $a0, 0x10
000b42a0 lui $a0, 8
000b42a4 sra $a2, $a2, 0x10
000b42a8 ori $a1, $zero, 0
000b42ac addiu $a0, $a0, 0x3f4c
000b42b0 lh $a3, ($a0)
000b42b4 beq $a3, $a2, 0xb42d0
000b42b8 addiu $a1, $a1, 1
000b42bc slti $a3, $a1, 3
000b42c0 bnez $a3, 0xb42b0
000b42c4 addiu $a0, $a0, 0xe
000b42c8 jr $ra
000b42cc ori $v0, $zero, 1
000b42d0 jr $ra
000b42d4 lh $v0, 0xa($a0)
000b42d8 addiu $sp, $sp, -0x10
000b42dc sw $s0, ($sp)
000b42e0 lui $s0, 0x1f
000b42e4 addiu $a0, $s0, -0x1928
000b42e8 lw $a0, 8($a0)
000b42ec sw $ra, 4($sp)
000b42f0 beql $a0, $zero, 0xb4304
000b42f4 lw $s0, -0x1928($s0)
000b42f8 jalr $a0
000b42fc nop 
000b4300 lw $s0, -0x1928($s0)
000b4304 beqz $s0, 0xb4314
000b4308 nop 
000b430c jalr $s0
000b4310 move $a0, $zero
000b4314 lw $s0, ($sp)
000b4318 lw $ra, 4($sp)
000b431c jr $ra
000b4320 addiu $sp, $sp, 0x10
000b4324 jr $ra
000b4328 nop 
000b432c addiu $sp, $sp, -0x10
000b4330 lui $a0, 8
000b4334 addiu $a0, $a0, 0x3f78
000b4338 sh $zero, 0xc($a0)
000b433c sh $zero, 0xe($a0)
000b4340 sh $zero, 0x10($a0)
000b4344 lui $a0, 0x16
000b4348 ori $a1, $zero, 1
000b434c addiu $a2, $zero, -2
000b4350 sw $ra, ($sp)
000b4354 jal 0x2d4f0
000b4358 addiu $a0, $a0, -0x583c
000b435c lw $ra, ($sp)
000b4360 jr $ra
000b4364 addiu $sp, $sp, 0x10
000b4368 addiu $sp, $sp, -0xe0
000b436c swc1 $f20, 0xac($sp)
000b4370 swc1 $f22, 0xb0($sp)
000b4374 swc1 $f24, 0xb4($sp)
000b4378 sw $s0, 0xb8($sp)
000b437c sw $s1, 0xbc($sp)
000b4380 sw $s2, 0xc0($sp)
000b4384 sw $s3, 0xc4($sp)
000b4388 sw $s4, 0xc8($sp)
000b438c sw $s5, 0xcc($sp)
000b4390 sw $s6, 0xd0($sp)
000b4394 sw $s7, 0xd4($sp)
000b4398 sw $fp, 0xd8($sp)
000b439c sw $ra, 0xdc($sp)
000b43a0 jal 0x45e30
000b43a4 move $a0, $sp
000b43a8 jal 0x35404
000b43ac nop 
000b43b0 ori $s7, $zero, 0xa
000b43b4 subu $a0, $s7, $v0
000b43b8 mtc1 $a0, $f12
000b43bc lui $s4, 0x12b
000b43c0 lui $a0, 0x4170
000b43c4 addiu $s4, $s4, -0x4c58
000b43c8 mtc1 $a0, $f13
000b43cc sh $zero, 0xbca($s4)
000b43d0 lh $a0, 0xbca($s4)
000b43d4 addiu $a1, $s4, 0xc
000b43d8 cvt.s.w $f20, $f12
000b43dc sw $a1, 0xa4($sp)
000b43e0 addiu $a2, $s4, 0x5e8
000b43e4 lui $s6, 0xa
000b43e8 lui $s0, 9
000b43ec lui $s3, 0x16
000b43f0 lui $s1, 0x32
000b43f4 lui $s2, 0x16
000b43f8 mtc1 $zero, $f22
000b43fc div.s $f20, $f20, $f13
000b4400 lui $a1, 0x3f80
000b4404 ori $s5, $zero, 1
000b4408 addiu $s6, $s6, 0x7428
000b440c addiu $s0, $s0, -0x5750
000b4410 addiu $s3, $s3, -0x5858
000b4414 addiu $s1, $s1, -0xcec
000b4418 addiu $s2, $s2, -0x584c
000b441c sw $a2, 0xa0($sp)
000b4420 lui $fp, 0x32
000b4424 bnez $a0, 0xb4690
000b4428 mtc1 $a1, $f24
000b442c jal 0x375bc
000b4430 move $a0, $zero
000b4434 move $a0, $v0
000b4438 slti $a1, $a0, 2
000b443c beqz $a1, 0xb4460
000b4440 ori $a1, $zero, 3
000b4444 bltzl $a0, 0xb4478
000b4448 lh $a0, ($sp)
000b444c blez $a0, 0xb446c
000b4450 ori $a0, $zero, 0x3c
000b4454 b 0xb4474
000b4458 sh $s5, ($sp)
000b445c ori $a1, $zero, 3
000b4460 bnel $a0, $a1, 0xb4478
000b4464 lh $a0, ($sp)
000b4468 ori $a0, $zero, 0x3c
000b446c b 0xb4474
000b4470 sh $a0, ($sp)
000b4474 lh $a0, ($sp)
000b4478 lh $a1, 0x204($s6)
000b447c slt $a1, $a1, $a0
000b4480 bnel $a1, $zero, 0xb4488
000b4484 sh $a0, 0x204($s6)
000b4488 addiu $a0, $sp, 4
000b448c sb $s7, 0x18($sp)
000b4490 addiu $a1, $sp, 6
000b4494 addiu $a2, $sp, 8
000b4498 jal 0xb41c4
000b449c addiu $a3, $sp, 0xa
000b44a0 sh $zero, 0xe($sp)
000b44a4 ori $a0, $zero, 0x80
000b44a8 lb $a1, 0xb($s0)
000b44ac sh $a0, 0x10($sp)
000b44b0 lb $a0, 0xd($s0)
000b44b4 sb $a1, 0x19($sp)
000b44b8 lb $a1, 0xf($s0)
000b44bc sb $a0, 0x1a($sp)
000b44c0 lb $a0, 0xc($s0)
000b44c4 sb $a1, 0x1b($sp)
000b44c8 lb $a1, 0xe($s0)
000b44cc sb $a0, 0x1c($sp)
000b44d0 lb $a0, 0x10($s0)
000b44d4 sb $a1, 0x1d($sp)
000b44d8 sb $a0, 0x1e($sp)
000b44dc lb $a2, 8($s0)
000b44e0 lb $a1, 0x18($sp)
000b44e4 ori $s7, $zero, 2
000b44e8 lh $a0, 0xbc6($s4)
000b44ec beql $a2, $s5, 0xb44f4
000b44f0 move $s7, $s5
000b44f4 sb $s7, 2($sp)
000b44f8 addiu $s0, $zero, -1
000b44fc bgtzl $a0, 0xb4504
000b4500 ori $s0, $zero, 8
000b4504 move $a0, $s3
000b4508 jal 0x4579c
000b450c ori $a2, $zero, 0x46
000b4510 move $a0, $s3
000b4514 jal 0x45a48
000b4518 move $a1, $s1
000b451c lwc1 $f12, -0xb74($fp)
000b4520 lui $s7, 0x32
000b4524 lwc1 $f13, -0xb78($s7)
000b4528 trunc.w.s $f12, $f12
000b452c sll $a0, $s0, 0x18
000b4530 trunc.w.s $f13, $f13
000b4534 sra $s0, $a0, 0x18
000b4538 move $a0, $s3
000b453c mfc1 $t2, $f12
000b4540 ori $a1, $zero, 2
000b4544 move $a2, $zero
000b4548 move $a3, $zero
000b454c mfc1 $t1, $f13
000b4550 jal 0x45af4
000b4554 move $t0, $s0
000b4558 lw $a0, 0x20($s1)
000b455c lw $a1, 8($s1)
000b4560 mov.s $f12, $f22
000b4564 lw $a2, 0x14($s1)
000b4568 mov.s $f13, $f24
000b456c sll $a0, $a0, 0x18
000b4570 sra $t0, $a0, 0x18
000b4574 lw $a3, 0x10($s1)
000b4578 sll $a0, $a2, 0x10
000b457c sra $t1, $a0, 0x10
000b4580 sll $a0, $a3, 0x10
000b4584 move $a2, $t0
000b4588 sra $t0, $a0, 0x10
000b458c move $a0, $s3
000b4590 jal 0x45c04
000b4594 move $a3, $t1
000b4598 move $a0, $s3
000b459c jal 0x45eb0
000b45a0 move $a1, $sp
000b45a4 lw $a1, 0xa4($sp)
000b45a8 jal 0x45f80
000b45ac move $a0, $s3
000b45b0 jal 0x46148
000b45b4 move $a0, $s3
000b45b8 lw $a0, 0x30($s1)
000b45bc lh $a1, 4($s4)
000b45c0 lw $a2, 0x14($s1)
000b45c4 lh $a3, 6($sp)
000b45c8 addu $a0, $a0, $a2
000b45cc mult $a1, $a0
000b45d0 sh $s5, ($sp)
000b45d4 lb $a1, 0x18($sp)
000b45d8 sh $zero, 0x10($sp)
000b45dc move $a0, $s2
000b45e0 mflo $a2
000b45e4 addu $a2, $a3, $a2
000b45e8 sh $a2, 6($sp)
000b45ec jal 0x4579c
000b45f0 ori $a2, $zero, 0x46
000b45f4 move $a0, $s2
000b45f8 jal 0x45a48
000b45fc move $a1, $s1
000b4600 lwc1 $f12, -0xb78($s7)
000b4604 lwc1 $f13, -0xb74($fp)
000b4608 trunc.w.s $f12, $f12
000b460c move $a0, $s2
000b4610 trunc.w.s $f13, $f13
000b4614 ori $a1, $zero, 2
000b4618 move $a2, $zero
000b461c move $a3, $zero
000b4620 mfc1 $t1, $f12
000b4624 move $t0, $s0
000b4628 jal 0x45af4
000b462c mfc1 $t2, $f13
000b4630 lw $a0, 0x20($s1)
000b4634 mov.s $f12, $f20
000b4638 lw $a1, 8($s1)
000b463c mov.s $f13, $f24
000b4640 lw $a3, 0x14($s1)
000b4644 sll $a2, $a0, 0x18
000b4648 lw $a0, 0x10($s1)
000b464c sll $a3, $a3, 0x10
000b4650 sll $t0, $a0, 0x10
000b4654 sra $a2, $a2, 0x18
000b4658 sra $a3, $a3, 0x10
000b465c sra $t0, $t0, 0x10
000b4660 jal 0x45c04
000b4664 move $a0, $s2
000b4668 move $a0, $s2
000b466c jal 0x45eb0
000b4670 move $a1, $sp
000b4674 lw $a1, 0xa0($sp)
000b4678 jal 0x45f80
000b467c move $a0, $s2
000b4680 jal 0x46148
000b4684 move $a0, $s2
000b4688 b 0xb48f4
000b468c lui $a1, 0xb
000b4690 jal 0x375bc
000b4694 move $a0, $zero
000b4698 move $a0, $v0
000b469c slti $a1, $a0, 2
000b46a0 beqz $a1, 0xb46c4
000b46a4 ori $a1, $zero, 3
000b46a8 bltzl $a0, 0xb46e0
000b46ac lh $a0, ($sp)
000b46b0 blez $a0, 0xb46d0
000b46b4 ori $a0, $zero, 0x3c
000b46b8 b 0xb46d8
000b46bc ori $a0, $zero, 0x3c
000b46c0 ori $a1, $zero, 3
000b46c4 bnel $a0, $a1, 0xb46e0
000b46c8 lh $a0, ($sp)
000b46cc ori $a0, $zero, 0x3c
000b46d0 b 0xb46dc
000b46d4 sh $a0, ($sp)
000b46d8 sh $a0, ($sp)
000b46dc lh $a0, ($sp)
000b46e0 lh $a1, 0x204($s6)
000b46e4 slt $a1, $a1, $a0
000b46e8 bnel $a1, $zero, 0xb46f0
000b46ec sh $a0, 0x204($s6)
000b46f0 addiu $a0, $sp, 4
000b46f4 sb $s7, 0x18($sp)
000b46f8 addiu $a1, $sp, 6
000b46fc addiu $a2, $sp, 8
000b4700 jal 0xb41c4
000b4704 addiu $a3, $sp, 0xa
000b4708 lb $a0, 0xb($s0)
000b470c sh $zero, 0xe($sp)
000b4710 sh $zero, 0x10($sp)
000b4714 lb $a1, 0xd($s0)
000b4718 sb $a0, 0x19($sp)
000b471c lb $a0, 0xf($s0)
000b4720 sb $a1, 0x1a($sp)
000b4724 lb $a1, 0xc($s0)
000b4728 sb $a0, 0x1b($sp)
000b472c lb $a0, 0xe($s0)
000b4730 sb $a1, 0x1c($sp)
000b4734 lb $a1, 0x10($s0)
000b4738 sb $a0, 0x1d($sp)
000b473c sb $a1, 0x1e($sp)
000b4740 lb $a2, 8($s0)
000b4744 lb $s7, 0x18($sp)
000b4748 ori $a1, $zero, 2
000b474c lh $a0, 0xbc6($s4)
000b4750 beql $a2, $s5, 0xb4758
000b4754 move $a1, $s5
000b4758 sb $a1, 2($sp)
000b475c addiu $s0, $zero, -1
000b4760 bgtzl $a0, 0xb4768
000b4764 ori $s0, $zero, 8
000b4768 sw $s6, 0xa8($sp)
000b476c move $a0, $s3
000b4770 move $a1, $s7
000b4774 jal 0x4579c
000b4778 ori $a2, $zero, 0x46
000b477c move $a0, $s3
000b4780 jal 0x45a48
000b4784 move $a1, $s1
000b4788 lwc1 $f12, -0xb74($fp)
000b478c lui $s7, 0x32
000b4790 lwc1 $f13, -0xb78($s7)
000b4794 trunc.w.s $f12, $f12
000b4798 sll $a0, $s0, 0x18
000b479c trunc.w.s $f13, $f13
000b47a0 sra $s0, $a0, 0x18
000b47a4 move $a0, $s3
000b47a8 mfc1 $t2, $f12
000b47ac ori $a1, $zero, 2
000b47b0 ori $a2, $zero, 2
000b47b4 move $a3, $zero
000b47b8 mfc1 $t1, $f13
000b47bc jal 0x45af4
000b47c0 move $t0, $s0
000b47c4 lw $a0, 0x20($s1)
000b47c8 lw $a1, 8($s1)
000b47cc mov.s $f12, $f22
000b47d0 lw $a2, 0x14($s1)
000b47d4 mov.s $f13, $f24
000b47d8 sll $a0, $a0, 0x18
000b47dc sra $t0, $a0, 0x18
000b47e0 lw $a3, 0x10($s1)
000b47e4 sll $a0, $a2, 0x10
000b47e8 sra $t1, $a0, 0x10
000b47ec sll $a0, $a3, 0x10
000b47f0 move $a2, $t0
000b47f4 sra $t0, $a0, 0x10
000b47f8 move $a0, $s3
000b47fc jal 0x45c04
000b4800 move $a3, $t1
000b4804 move $a0, $s3
000b4808 jal 0x45eb0
000b480c move $a1, $sp
000b4810 lw $s6, 0xa4($sp)
000b4814 sh $zero, 2($s4)
000b4818 jal 0x6ea98
000b481c move $a0, $s6
000b4820 move $a0, $s3
000b4824 jal 0x45f80
000b4828 move $a1, $s6
000b482c jal 0x46148
000b4830 move $a0, $s3
000b4834 lb $a1, 0x18($sp)
000b4838 sh $s5, ($sp)
000b483c sh $zero, 0x10($sp)
000b4840 move $a0, $s2
000b4844 jal 0x4579c
000b4848 ori $a2, $zero, 0x46
000b484c move $a0, $s2
000b4850 jal 0x45a48
000b4854 move $a1, $s1
000b4858 lwc1 $f12, -0xb78($s7)
000b485c lwc1 $f13, -0xb74($fp)
000b4860 trunc.w.s $f12, $f12
000b4864 move $a0, $s2
000b4868 trunc.w.s $f13, $f13
000b486c ori $a1, $zero, 2
000b4870 ori $a2, $zero, 2
000b4874 move $a3, $zero
000b4878 mfc1 $t1, $f12
000b487c move $t0, $s0
000b4880 jal 0x45af4
000b4884 mfc1 $t2, $f13
000b4888 lw $a0, 0x20($s1)
000b488c mov.s $f12, $f20
000b4890 lw $a1, 8($s1)
000b4894 mov.s $f13, $f24
000b4898 lw $a3, 0x14($s1)
000b489c sll $a2, $a0, 0x18
000b48a0 lw $a0, 0x10($s1)
000b48a4 sll $a3, $a3, 0x10
000b48a8 sll $t0, $a0, 0x10
000b48ac sra $a2, $a2, 0x18
000b48b0 sra $a3, $a3, 0x10
000b48b4 sra $t0, $t0, 0x10
000b48b8 jal 0x45c04
000b48bc move $a0, $s2
000b48c0 move $a0, $s2
000b48c4 jal 0x45eb0
000b48c8 move $a1, $sp
000b48cc lw $s0, 0xa0($sp)
000b48d0 jal 0x6ea98
000b48d4 move $a0, $s0
000b48d8 move $a0, $s2
000b48dc jal 0x45f80
000b48e0 move $a1, $s0
000b48e4 jal 0x46148
000b48e8 move $a0, $s2
000b48ec lw $s6, 0xa8($sp)
000b48f0 lui $a1, 0xb
000b48f4 move $a0, $s2
000b48f8 move $a2, $zero
000b48fc jal 0x470d0
000b4900 addiu $a1, $a1, 0x3dbc
000b4904 jal 0xb432c
000b4908 nop 
000b490c sb $s5, 0x1d8($s6)
000b4910 lwc1 $f20, 0xac($sp)
000b4914 lwc1 $f22, 0xb0($sp)
000b4918 lwc1 $f24, 0xb4($sp)
000b491c lw $s0, 0xb8($sp)
000b4920 lw $s1, 0xbc($sp)
000b4924 lw $s2, 0xc0($sp)
000b4928 lw $s3, 0xc4($sp)
000b492c lw $s4, 0xc8($sp)
000b4930 lw $s5, 0xcc($sp)
000b4934 lw $s6, 0xd0($sp)
000b4938 lw $s7, 0xd4($sp)
000b493c lw $fp, 0xd8($sp)
000b4940 lw $ra, 0xdc($sp)
000b4944 jr $ra
000b4948 addiu $sp, $sp, 0xe0
000b494c addiu $sp, $sp, -0x180
000b4950 sw $s4, 0x164($sp)
000b4954 lui $s4, 0x16
000b4958 addiu $s4, $s4, -0x5840
000b495c sw $a0, 0x144($sp)
000b4960 swc1 $f20, 0x14c($sp)
000b4964 swc1 $f22, 0x150($sp)
000b4968 sw $s0, 0x154($sp)
000b496c sw $s1, 0x158($sp)
000b4970 sw $s2, 0x15c($sp)
000b4974 sw $s3, 0x160($sp)
000b4978 sw $s5, 0x168($sp)
000b497c sw $s6, 0x16c($sp)
000b4980 sw $s7, 0x170($sp)
000b4984 sw $fp, 0x174($sp)
000b4988 sw $ra, 0x178($sp)
000b498c jal 0x13833c
000b4990 move $a1, $s4
000b4994 beqz $v0, 0xb4d38
000b4998 lui $s1, 0x12b
000b499c addiu $s1, $s1, -0x4c58
000b49a0 lh $a0, 0xbca($s1)
000b49a4 lh $s2, 2($s1)
000b49a8 addiu $a1, $s1, 0xc
000b49ac sw $a1, 0x140($sp)
000b49b0 lui $a2, 0x4170
000b49b4 lui $a1, 0x16
000b49b8 mtc1 $a2, $f20
000b49bc addiu $a1, $a1, -0x5858
000b49c0 lui $s3, 0x32
000b49c4 lui $s0, 9
000b49c8 lui $s5, 0x16
000b49cc lui $a2, 0x3f80
000b49d0 ori $s6, $zero, 1
000b49d4 mtc1 $a2, $f22
000b49d8 addiu $fp, $s1, 0x5e8
000b49dc ori $s7, $zero, 0xa
000b49e0 addiu $s3, $s3, -0xcec
000b49e4 addiu $s0, $s0, -0x5750
000b49e8 addiu $s5, $s5, -0x584c
000b49ec bnez $a0, 0xb4bb0
000b49f0 sw $a1, 0x148($sp)
000b49f4 jal 0x6ea24
000b49f8 move $a0, $zero
000b49fc addu $a0, $s2, $v0
000b4a00 sll $a0, $a0, 0x10
000b4a04 sra $a0, $a0, 0x10
000b4a08 slti $a0, $a0, 0xf
000b4a0c beqz $a0, 0xb4a24
000b4a10 lui $a0, 8
000b4a14 lb $a0, 0xbc4($s1)
000b4a18 beqz $a0, 0xb4a58
000b4a1c nop 
000b4a20 lui $a0, 8
000b4a24 addiu $a0, $a0, 0x3f78
000b4a28 lh $a0, 8($a0)
000b4a2c beq $a0, $s6, 0xb4a58
000b4a30 nop 
000b4a34 lw $a0, 0x140($sp)
000b4a38 sh $zero, 2($s1)
000b4a3c jal 0x137734
000b4a40 move $a1, $s4
000b4a44 move $a0, $fp
000b4a48 jal 0x137734
000b4a4c move $a1, $s4
000b4a50 sb $zero, 0xbc4($s1)
000b4a54 sh $zero, 0xa($s1)
000b4a58 jal 0x35404
000b4a5c nop 
000b4a60 subu $a0, $s7, $v0
000b4a64 mtc1 $a0, $f12
000b4a68 cvt.s.w $f12, $f12
000b4a6c div.s $f20, $f12, $f20
000b4a70 jal 0x45e30
000b4a74 move $a0, $sp
000b4a78 sb $s7, 0x18($sp)
000b4a7c sh $s6, ($sp)
000b4a80 addiu $a0, $sp, 4
000b4a84 addiu $a1, $sp, 6
000b4a88 addiu $a2, $sp, 8
000b4a8c jal 0xb41c4
000b4a90 addiu $a3, $sp, 0xa
000b4a94 lw $a0, 0x30($s3)
000b4a98 lh $s7, 2($s1)
000b4a9c lw $a1, 0x14($s3)
000b4aa0 lh $a2, 6($sp)
000b4aa4 addu $a0, $a0, $a1
000b4aa8 mult $s7, $a0
000b4aac lb $a0, 0xb($s0)
000b4ab0 sh $zero, 0xe($sp)
000b4ab4 sh $zero, 0x10($sp)
000b4ab8 lb $a1, 0xd($s0)
000b4abc mflo $a3
000b4ac0 addu $a2, $a2, $a3
000b4ac4 sh $a2, 6($sp)
000b4ac8 sb $a0, 0x19($sp)
000b4acc lb $a0, 0xf($s0)
000b4ad0 sb $a1, 0x1a($sp)
000b4ad4 lb $a1, 0xc($s0)
000b4ad8 sb $a0, 0x1b($sp)
000b4adc lb $a0, 0xe($s0)
000b4ae0 sb $a1, 0x1c($sp)
000b4ae4 lb $a1, 0x10($s0)
000b4ae8 sb $a0, 0x1d($sp)
000b4aec sb $a1, 0x1e($sp)
000b4af0 lb $a1, 8($s0)
000b4af4 ori $a0, $zero, 2
000b4af8 beql $a1, $s6, 0xb4b00
000b4afc ori $a0, $zero, 1
000b4b00 lw $s0, 0x144($sp)
000b4b04 lw $s2, 0x148($sp)
000b4b08 sb $a0, 2($sp)
000b4b0c sh $s7, 4($s1)
000b4b10 jal 0x6ea5c
000b4b14 move $a0, $s0
000b4b18 lw $a0, 0x20($s3)
000b4b1c mov.s $f12, $f20
000b4b20 lw $a1, 8($s3)
000b4b24 mov.s $f13, $f22
000b4b28 lw $a3, 0x14($s3)
000b4b2c sll $a2, $a0, 0x18
000b4b30 lw $a0, 0x10($s3)
000b4b34 sll $a3, $a3, 0x10
000b4b38 sll $t0, $a0, 0x10
000b4b3c sra $a2, $a2, 0x18
000b4b40 sra $a3, $a3, 0x10
000b4b44 sra $t0, $t0, 0x10
000b4b48 jal 0x45c04
000b4b4c move $a0, $s5
000b4b50 move $a0, $s5
000b4b54 jal 0x45eb0
000b4b58 move $a1, $sp
000b4b5c move $a0, $s5
000b4b60 jal 0x45f80
000b4b64 move $a1, $s0
000b4b68 jal 0x46148
000b4b6c move $a0, $s5
000b4b70 lw $s3, 0x140($sp)
000b4b74 move $a1, $fp
000b4b78 jal 0x1382e0
000b4b7c move $a0, $s3
000b4b80 move $a0, $s2
000b4b84 jal 0x45f80
000b4b88 move $a1, $s3
000b4b8c jal 0x46148
000b4b90 move $a0, $s2
000b4b94 move $a0, $fp
000b4b98 jal 0x137734
000b4b9c move $a1, $s0
000b4ba0 lh $a0, 0xa($s1)
000b4ba4 addiu $a0, $a0, 1
000b4ba8 b 0xb4d38
000b4bac sh $a0, 0xa($s1)
000b4bb0 jal 0x6ea24
000b4bb4 move $a0, $zero
000b4bb8 addu $a0, $s2, $v0
000b4bbc sll $a0, $a0, 0x10
000b4bc0 sra $a0, $a0, 0x10
000b4bc4 slti $a0, $a0, 0x12
000b4bc8 beqz $a0, 0xb4bdc
000b4bcc addiu $s2, $sp, 0xa0
000b4bd0 lb $a0, 0xbc4($s1)
000b4bd4 beqz $a0, 0xb4c00
000b4bd8 nop 
000b4bdc lw $a0, 0x140($sp)
000b4be0 sh $zero, 2($s1)
000b4be4 jal 0x137734
000b4be8 move $a1, $s4
000b4bec move $a0, $fp
000b4bf0 jal 0x137734
000b4bf4 move $a1, $s4
000b4bf8 sb $zero, 0xbc4($s1)
000b4bfc sh $zero, 0xa($s1)
000b4c00 jal 0x35404
000b4c04 nop 
000b4c08 subu $a0, $s7, $v0
000b4c0c mtc1 $a0, $f12
000b4c10 cvt.s.w $f12, $f12
000b4c14 div.s $f20, $f12, $f20
000b4c18 jal 0x45e30
000b4c1c move $a0, $s2
000b4c20 sh $s6, 0xa0($sp)
000b4c24 sb $s7, 0xb8($sp)
000b4c28 addiu $a0, $sp, 0xa4
000b4c2c addiu $a1, $sp, 0xa6
000b4c30 addiu $a2, $sp, 0xa8
000b4c34 jal 0xb41c4
000b4c38 addiu $a3, $sp, 0xaa
000b4c3c sh $zero, 0xae($sp)
000b4c40 ori $a0, $zero, 0x80
000b4c44 lb $a1, 0xb($s0)
000b4c48 sh $a0, 0xb0($sp)
000b4c4c lb $a0, 0xd($s0)
000b4c50 sb $a1, 0xb9($sp)
000b4c54 lb $a1, 0xf($s0)
000b4c58 sb $a0, 0xba($sp)
000b4c5c lb $a0, 0xc($s0)
000b4c60 sb $a1, 0xbb($sp)
000b4c64 lb $a1, 0xe($s0)
000b4c68 sb $a0, 0xbc($sp)
000b4c6c lb $a0, 0x10($s0)
000b4c70 sb $a1, 0xbd($sp)
000b4c74 sb $a0, 0xbe($sp)
000b4c78 lb $a0, 8($s0)
000b4c7c ori $s7, $zero, 2
000b4c80 beql $a0, $s6, 0xb4c88
000b4c84 ori $s7, $zero, 1
000b4c88 lh $a0, 2($s1)
000b4c8c lw $s0, 0x144($sp)
000b4c90 sb $s7, 0xa2($sp)
000b4c94 sh $a0, 4($s1)
000b4c98 jal 0x6ea98
000b4c9c move $a0, $s0
000b4ca0 lw $a0, 0x20($s3)
000b4ca4 mov.s $f12, $f20
000b4ca8 lw $a1, 8($s3)
000b4cac mov.s $f13, $f22
000b4cb0 lw $a3, 0x14($s3)
000b4cb4 sll $a2, $a0, 0x18
000b4cb8 lw $a0, 0x10($s3)
000b4cbc sll $a3, $a3, 0x10
000b4cc0 sll $t0, $a0, 0x10
000b4cc4 sra $a2, $a2, 0x18
000b4cc8 sra $a3, $a3, 0x10
000b4ccc sra $t0, $t0, 0x10
000b4cd0 jal 0x45c04
000b4cd4 move $a0, $s5
000b4cd8 move $a0, $s5
000b4cdc jal 0x45eb0
000b4ce0 move $a1, $s2
000b4ce4 move $a0, $s5
000b4ce8 jal 0x45f80
000b4cec move $a1, $s0
000b4cf0 jal 0x46148
000b4cf4 move $a0, $s5
000b4cf8 lw $s2, 0x140($sp)
000b4cfc move $a1, $fp
000b4d00 jal 0x1382e0
000b4d04 move $a0, $s2
000b4d08 lw $s3, 0x148($sp)
000b4d0c move $a1, $s2
000b4d10 jal 0x45f80
000b4d14 move $a0, $s3
000b4d18 jal 0x46148
000b4d1c move $a0, $s3
000b4d20 move $a0, $fp
000b4d24 jal 0x137734
000b4d28 move $a1, $s0
000b4d2c lh $a0, 0xa($s1)
000b4d30 addiu $a0, $a0, 1
000b4d34 sh $a0, 0xa($s1)
000b4d38 move $v0, $zero
000b4d3c lwc1 $f20, 0x14c($sp)
000b4d40 lwc1 $f22, 0x150($sp)
000b4d44 lw $s0, 0x154($sp)
000b4d48 lw $s1, 0x158($sp)
000b4d4c lw $s2, 0x15c($sp)
000b4d50 lw $s3, 0x160($sp)
000b4d54 lw $s4, 0x164($sp)
000b4d58 lw $s5, 0x168($sp)
000b4d5c lw $s6, 0x16c($sp)
000b4d60 lw $s7, 0x170($sp)
000b4d64 lw $fp, 0x174($sp)
000b4d68 lw $ra, 0x178($sp)
000b4d6c jr $ra
000b4d70 addiu $sp, $sp, 0x180
000b4d74 addiu $sp, $sp, -0x40
000b4d78 sw $s0, 0x10($sp)
000b4d7c sw $s1, 0x14($sp)
000b4d80 sw $s2, 0x18($sp)
000b4d84 sw $s3, 0x1c($sp)
000b4d88 sw $s4, 0x20($sp)
000b4d8c sw $s5, 0x24($sp)
000b4d90 sw $s6, 0x28($sp)
000b4d94 sw $s7, 0x2c($sp)
000b4d98 sw $fp, 0x30($sp)
000b4d9c sw $ra, 0x34($sp)
000b4da0 jal 0x1383b4
000b4da4 move $s1, $a0
000b4da8 lui $s4, 0x12b
000b4dac addiu $s4, $s4, -0x4c58
000b4db0 lui $a0, 0x16
000b4db4 sh $zero, 6($s4)
000b4db8 addiu $a0, $a0, -0x582c
000b4dbc sw $a0, 0xc($sp)
000b4dc0 lui $a0, 0x16
000b4dc4 addiu $a0, $a0, -0x5824
000b4dc8 sw $a0, 8($sp)
000b4dcc lui $a0, 0x16
000b4dd0 addiu $a0, $a0, -0x581c
000b4dd4 lui $a1, 0x16
000b4dd8 sw $a0, 4($sp)
000b4ddc addiu $a1, $a1, -0x5814
000b4de0 lb $a0, ($s1)
000b4de4 lui $s6, 8
000b4de8 lui $fp, 8
000b4dec lui $s5, 0x32
000b4df0 ori $s3, $zero, 0x5d
000b4df4 ori $s7, $zero, 1
000b4df8 addiu $s1, $s1, 1
000b4dfc sw $a1, ($sp)
000b4e00 addiu $s0, $v0, -1
000b4e04 addiu $s6, $s6, 0x3f78
000b4e08 addiu $fp, $fp, 0x3f4c
000b4e0c addiu $s5, $s5, -0xcec
000b4e10 ori $a1, $zero, 0x23
000b4e14 bne $a0, $a1, 0xb5080
000b4e18 move $s2, $s1
000b4e1c lw $a1, 0xc($sp)
000b4e20 move $a0, $s2
000b4e24 jal 0x138430
000b4e28 ori $a2, $zero, 6
000b4e2c addiu $s1, $s2, 1
000b4e30 bnez $v0, 0xb4ed4
000b4e34 addiu $s0, $s0, -1
000b4e38 lh $a0, 6($s4)
000b4e3c lh $a1, 0xc($s6)
000b4e40 sra $a2, $a0, 1
000b4e44 srl $a2, $a2, 0x1f
000b4e48 sll $a3, $a1, 4
000b4e4c addu $a0, $a0, $a2
000b4e50 subu $a2, $a3, $a1
000b4e54 lw $a3, 0x30($s5)
000b4e58 lw $t0, 0x10($s5)
000b4e5c subu $a1, $a2, $a1
000b4e60 addu $a2, $a3, $t0
000b4e64 sra $a0, $a0, 1
000b4e68 addu $a1, $a1, $fp
000b4e6c lw $t0, 0x14($s5)
000b4e70 sh $zero, ($a1)
000b4e74 mult $a0, $a2
000b4e78 lh $a2, 2($s4)
000b4e7c addu $a3, $a3, $t0
000b4e80 addiu $a0, $s2, 6
000b4e84 mflo $t0
000b4e88 nop 
000b4e8c nop 
000b4e90 mult $a2, $a3
000b4e94 sh $t0, 2($a1)
000b4e98 mflo $a2
000b4e9c jal 0x13794c
000b4ea0 sh $a2, 4($a1)
000b4ea4 lh $a0, 0xc($s6)
000b4ea8 sll $a1, $a0, 4
000b4eac subu $a1, $a1, $a0
000b4eb0 subu $a1, $a1, $a0
000b4eb4 addu $a1, $a1, $fp
000b4eb8 sh $v0, 6($a1)
000b4ebc sh $s7, 8($a1)
000b4ec0 sh $s7, 0xa($a1)
000b4ec4 addiu $a0, $a0, 1
000b4ec8 sh $zero, 0xc($a1)
000b4ecc b 0xb503c
000b4ed0 sh $a0, 0xc($s6)
000b4ed4 lw $a1, 8($sp)
000b4ed8 move $a0, $s2
000b4edc jal 0x138430
000b4ee0 ori $a2, $zero, 6
000b4ee4 bnel $v0, $zero, 0xb4f8c
000b4ee8 lw $a1, 4($sp)
000b4eec lh $a0, 6($s4)
000b4ef0 lh $a1, 0xc($s6)
000b4ef4 sra $a2, $a0, 1
000b4ef8 srl $a2, $a2, 0x1f
000b4efc sll $a3, $a1, 4
000b4f00 addu $a0, $a0, $a2
000b4f04 subu $a2, $a3, $a1
000b4f08 lw $a3, 0x30($s5)
000b4f0c lw $t0, 0x10($s5)
000b4f10 subu $a1, $a2, $a1
000b4f14 addu $a2, $a3, $t0
000b4f18 sra $a0, $a0, 1
000b4f1c addu $a1, $a1, $fp
000b4f20 lw $t0, 0x14($s5)
000b4f24 sh $s7, ($a1)
000b4f28 mult $a0, $a2
000b4f2c lh $a2, 2($s4)
000b4f30 addu $a3, $a3, $t0
000b4f34 addiu $a0, $s2, 6
000b4f38 mflo $t0
000b4f3c nop 
000b4f40 nop 
000b4f44 mult $a2, $a3
000b4f48 sh $t0, 2($a1)
000b4f4c mflo $a2
000b4f50 jal 0x13794c
000b4f54 sh $a2, 4($a1)
000b4f58 lh $a0, 0xc($s6)
000b4f5c ori $a1, $zero, 2
000b4f60 sll $a2, $a0, 4
000b4f64 subu $a2, $a2, $a0
000b4f68 subu $a2, $a2, $a0
000b4f6c addu $a2, $a2, $fp
000b4f70 sh $v0, 6($a2)
000b4f74 sh $a1, 8($a2)
000b4f78 sh $s7, 0xa($a2)
000b4f7c addiu $a0, $a0, 1
000b4f80 sh $zero, 0xc($a2)
000b4f84 b 0xb503c
000b4f88 sh $a0, 0xc($s6)
000b4f8c move $a0, $s2
000b4f90 jal 0x138430
000b4f94 ori $a2, $zero, 5
000b4f98 bnel $v0, $zero, 0xb5024
000b4f9c lw $a1, ($sp)
000b4fa0 lh $a0, 6($s4)
000b4fa4 lh $a1, 0xc($s6)
000b4fa8 sra $a2, $a0, 1
000b4fac srl $a2, $a2, 0x1f
000b4fb0 sll $a3, $a1, 4
000b4fb4 addu $a0, $a0, $a2
000b4fb8 subu $a2, $a3, $a1
000b4fbc lw $a3, 0x30($s5)
000b4fc0 lw $t1, 0x10($s5)
000b4fc4 subu $a2, $a2, $a1
000b4fc8 ori $t0, $zero, 2
000b4fcc sra $a0, $a0, 1
000b4fd0 addu $a2, $a2, $fp
000b4fd4 addu $t1, $a3, $t1
000b4fd8 lw $t2, 0x14($s5)
000b4fdc sh $t0, ($a2)
000b4fe0 mult $a0, $t1
000b4fe4 lh $a0, 2($s4)
000b4fe8 addu $a3, $a3, $t2
000b4fec sh $zero, 6($a2)
000b4ff0 sh $zero, 8($a2)
000b4ff4 mflo $t0
000b4ff8 nop 
000b4ffc nop 
000b5000 mult $a0, $a3
000b5004 sh $t0, 2($a2)
000b5008 sh $s7, 0xa($a2)
000b500c addiu $a0, $a1, 1
000b5010 sh $zero, 0xc($a2)
000b5014 mflo $a1
000b5018 sh $a1, 4($a2)
000b501c b 0xb503c
000b5020 sh $a0, 0xc($s6)
000b5024 move $a0, $s2
000b5028 jal 0x138430
000b502c ori $a2, $zero, 6
000b5030 bnel $v0, $zero, 0xb5040
000b5034 lb $s2, ($s2)
000b5038 sh $s7, 8($s6)
000b503c lb $s2, ($s2)
000b5040 ori $a0, $zero, 0x6e
000b5044 bne $s2, $a0, 0xb5060
000b5048 nop 
000b504c lh $a0, 2($s4)
000b5050 sh $zero, 6($s4)
000b5054 addiu $a0, $a0, 1
000b5058 b 0xb5078
000b505c sh $a0, 2($s4)
000b5060 beq $s2, $s3, 0xb5078
000b5064 nop 
000b5068 lb $a0, ($s1)
000b506c addiu $s1, $s1, 1
000b5070 bne $a0, $s3, 0xb5068
000b5074 addiu $s0, $s0, -1
000b5078 b 0xb5090
000b507c sltiu $a0, $s0, 3
000b5080 lh $a0, 6($s4)
000b5084 addiu $a0, $a0, 1
000b5088 sh $a0, 6($s4)
000b508c sltiu $a0, $s0, 3
000b5090 bnel $a0, $zero, 0xb50a8
000b5094 lh $a0, 2($s4)
000b5098 lb $a0, ($s1)
000b509c addiu $s1, $s1, 1
000b50a0 b 0xb4e10
000b50a4 addiu $s0, $s0, -1
000b50a8 addiu $a0, $a0, 1
000b50ac sh $a0, 2($s4)
000b50b0 lw $s0, 0x10($sp)
000b50b4 lw $s1, 0x14($sp)
000b50b8 lw $s2, 0x18($sp)
000b50bc lw $s3, 0x1c($sp)
000b50c0 lw $s4, 0x20($sp)
000b50c4 lw $s5, 0x24($sp)
000b50c8 lw $s6, 0x28($sp)
000b50cc lw $s7, 0x2c($sp)
000b50d0 lw $fp, 0x30($sp)
000b50d4 lw $ra, 0x34($sp)
000b50d8 jr $ra
000b50dc addiu $sp, $sp, 0x40
000b50e0 addiu $sp, $sp, -0x630
000b50e4 sw $s0, 0x604($sp)
000b50e8 sw $s1, 0x608($sp)
000b50ec sw $s2, 0x60c($sp)
000b50f0 sw $s3, 0x610($sp)
000b50f4 sw $s4, 0x614($sp)
000b50f8 sw $s5, 0x618($sp)
000b50fc sw $s6, 0x61c($sp)
000b5100 sw $s7, 0x620($sp)
000b5104 sw $fp, 0x624($sp)
000b5108 sw $ra, 0x628($sp)
000b510c jal 0x1383b4
000b5110 move $s0, $a0
000b5114 move $s4, $v0
000b5118 ori $a0, $zero, 0
000b511c move $a2, $s0
000b5120 addu $a1, $sp, $a0
000b5124 addiu $a0, $a0, 1
000b5128 sll $a0, $a0, 0x10
000b512c sb $zero, ($a1)
000b5130 sra $a0, $a0, 0x10
000b5134 slti $a1, $a0, 0x5dc
000b5138 bnez $a1, 0xb5124
000b513c addu $a1, $sp, $a0
000b5140 blez $s4, 0xb51e0
000b5144 lui $s6, 0x12b
000b5148 addiu $s6, $s6, -0x4c58
000b514c lui $a1, 0x32
000b5150 lh $a0, 2($s6)
000b5154 addiu $s1, $a1, -0xcec
000b5158 lw $a1, 0x30($s1)
000b515c lw $a3, 0x14($s1)
000b5160 addu $a1, $a1, $a3
000b5164 mult $a0, $a1
000b5168 ori $a0, $zero, 0x1c2
000b516c sw $a2, 0x5fc($sp)
000b5170 move $s3, $a2
000b5174 addiu $s7, $sp, 0x5dc
000b5178 mflo $a1
000b517c subu $a0, $a0, $a1
000b5180 sll $s0, $a0, 0x10
000b5184 lui $a0, 0x16
000b5188 sra $s0, $s0, 0x10
000b518c addiu $s2, $a0, -0x580c
000b5190 sh $zero, 6($s6)
000b5194 move $a0, $s7
000b5198 move $a1, $s2
000b519c jal 0x137734
000b51a0 move $a2, $s0
000b51a4 move $a0, $sp
000b51a8 jal 0x137734
000b51ac move $a1, $s7
000b51b0 ori $a0, $zero, 0x64
000b51b4 div $zero, $s0, $a0
000b51b8 lh $a0, 2($s6)
000b51bc lb $a1, ($s3)
000b51c0 lb $s5, ($s3)
000b51c4 sw $s1, 0x5f0($sp)
000b51c8 ori $a3, $zero, 0xa
000b51cc mflo $a2
000b51d0 blez $a2, 0xb5214
000b51d4 sw $s2, 0x5f8($sp)
000b51d8 b 0xb522c
000b51dc ori $s0, $zero, 0xb
000b51e0 move $v0, $zero
000b51e4 lw $s0, 0x604($sp)
000b51e8 lw $s1, 0x608($sp)
000b51ec lw $s2, 0x60c($sp)
000b51f0 lw $s3, 0x610($sp)
000b51f4 lw $s4, 0x614($sp)
000b51f8 lw $s5, 0x618($sp)
000b51fc lw $s6, 0x61c($sp)
000b5200 lw $s7, 0x620($sp)
000b5204 lw $fp, 0x624($sp)
000b5208 lw $ra, 0x628($sp)
000b520c jr $ra
000b5210 addiu $sp, $sp, 0x630
000b5214 div $zero, $s0, $a3
000b5218 mflo $a2
000b521c blez $a2, 0xb522c
000b5220 ori $s0, $zero, 9
000b5224 b 0xb522c
000b5228 move $s0, $a3
000b522c lui $a2, 0x16
000b5230 addiu $a3, $a2, -0x5800
000b5234 ori $s2, $zero, 0x5d
000b5238 ori $fp, $zero, 0x6e
000b523c addu $a2, $sp, $s0
000b5240 sw $a3, 0x5f4($sp)
000b5244 move $a3, $a1
000b5248 ori $t0, $zero, 0x23
000b524c bne $a3, $t0, 0xb5384
000b5250 ori $a1, $zero, 0
000b5254 sb $s5, ($a2)
000b5258 addiu $s3, $s3, 1
000b525c addiu $s4, $s4, -1
000b5260 addiu $s0, $s0, 1
000b5264 lb $t0, ($s3)
000b5268 addu $a2, $sp, $s0
000b526c addiu $a3, $s3, 1
000b5270 bne $t0, $fp, 0xb5294
000b5274 addiu $s4, $s4, -1
000b5278 addiu $a0, $a0, 1
000b527c sh $zero, 6($s6)
000b5280 sh $a0, 2($s6)
000b5284 lh $a0, 2($s6)
000b5288 ori $a1, $zero, 1
000b528c b 0xb52bc
000b5290 lb $s3, ($s3)
000b5294 beq $t0, $s2, 0xb52bc
000b5298 lb $s3, ($s3)
000b529c sb $s3, ($a2)
000b52a0 lb $t0, ($a3)
000b52a4 addiu $s0, $s0, 1
000b52a8 lb $s3, ($a3)
000b52ac addu $a2, $sp, $s0
000b52b0 addiu $a3, $a3, 1
000b52b4 bne $t0, $s2, 0xb529c
000b52b8 addiu $s4, $s4, -1
000b52bc sb $s3, ($a2)
000b52c0 move $s3, $a3
000b52c4 addiu $s0, $s0, 1
000b52c8 blez $a1, 0xb53b8
000b52cc slti $s5, $s4, 3
000b52d0 lw $a1, 0x5f0($sp)
000b52d4 lw $a2, 0x30($a1)
000b52d8 lw $a1, 0x14($a1)
000b52dc ori $a3, $zero, 0x1c2
000b52e0 addu $a1, $a2, $a1
000b52e4 mult $a0, $a1
000b52e8 lw $a1, 0x5f8($sp)
000b52ec move $a0, $s7
000b52f0 mflo $a2
000b52f4 subu $a2, $a3, $a2
000b52f8 sll $s1, $a2, 0x10
000b52fc sra $a2, $s1, 0x10
000b5300 jal 0x137734
000b5304 sw $a2, 0x600($sp)
000b5308 jal 0x1383b4
000b530c move $a0, $sp
000b5310 move $s1, $v0
000b5314 jal 0x1383b4
000b5318 move $a0, $s7
000b531c addu $a0, $s1, $v0
000b5320 slti $a0, $a0, 0x5dd
000b5324 bnez $a0, 0xb5338
000b5328 lw $s1, 0x600($sp)
000b532c lw $a0, 0x5f4($sp)
000b5330 jal 0x2e41c
000b5334 move $a1, $zero
000b5338 move $a0, $sp
000b533c jal 0x1382e0
000b5340 move $a1, $s7
000b5344 ori $a0, $zero, 0x64
000b5348 div $zero, $s1, $a0
000b534c mflo $a1
000b5350 blez $a1, 0xb5360
000b5354 lh $a0, 2($s6)
000b5358 b 0xb537c
000b535c addiu $s0, $s0, 0xb
000b5360 ori $a1, $zero, 0xa
000b5364 div $zero, $s1, $a1
000b5368 mflo $a1
000b536c blezl $a1, 0xb537c
000b5370 addiu $s0, $s0, 9
000b5374 b 0xb537c
000b5378 addiu $s0, $s0, 0xa
000b537c b 0xb53b8
000b5380 nop 
000b5384 sb $s5, ($a2)
000b5388 lb $a1, 1($s3)
000b538c ori $a3, $zero, 0x23
000b5390 sb $a1, 1($a2)
000b5394 sb $a3, 2($a2)
000b5398 lh $a1, 6($s6)
000b539c sb $fp, 3($a2)
000b53a0 addiu $s4, $s4, -2
000b53a4 addiu $a1, $a1, 2
000b53a8 addiu $s3, $s3, 2
000b53ac addiu $s0, $s0, 4
000b53b0 sh $a1, 6($s6)
000b53b4 slti $s5, $s4, 3
000b53b8 bnel $s5, $zero, 0xb53d0
000b53bc lw $a1, 0x5fc($sp)
000b53c0 lb $a1, ($s3)
000b53c4 lb $s5, ($s3)
000b53c8 b 0xb5244
000b53cc addu $a2, $sp, $s0
000b53d0 addiu $a0, $a0, 1
000b53d4 sh $a0, 2($s6)
000b53d8 move $a0, $a1
000b53dc jal 0x137734
000b53e0 move $a1, $sp
000b53e4 move $v0, $zero
000b53e8 lw $s0, 0x604($sp)
000b53ec lw $s1, 0x608($sp)
000b53f0 lw $s2, 0x60c($sp)
000b53f4 lw $s3, 0x610($sp)
000b53f8 lw $s4, 0x614($sp)
000b53fc lw $s5, 0x618($sp)
000b5400 lw $s6, 0x61c($sp)
000b5404 lw $s7, 0x620($sp)
000b5408 lw $fp, 0x624($sp)
000b540c lw $ra, 0x628($sp)
000b5410 jr $ra
000b5414 addiu $sp, $sp, 0x630
000b5418 addiu $sp, $sp, -0x40
000b541c sw $s3, 0x24($sp)
000b5420 lui $s3, 8
000b5424 sw $s0, 0x18($sp)
000b5428 addiu $s0, $s3, 0x3f78
000b542c lh $a0, 0x12($s0)
000b5430 sw $s1, 0x1c($sp)
000b5434 sw $s2, 0x20($sp)
000b5438 sw $s4, 0x28($sp)
000b543c sw $s5, 0x2c($sp)
000b5440 sw $ra, 0x30($sp)
000b5444 blez $a0, 0xb5458
000b5448 ori $s1, $zero, 1
000b544c addiu $a0, $a0, -1
000b5450 b 0xb5af0
000b5454 sh $a0, 0x12($s0)
000b5458 sh $zero, 0x10($sp)
000b545c sh $zero, 0x12($sp)
000b5460 sh $zero, 0x14($sp)
000b5464 sh $zero, 0x16($sp)
000b5468 addiu $a0, $sp, 0x10
000b546c addiu $a1, $sp, 0x12
000b5470 addiu $a2, $sp, 0x14
000b5474 jal 0xb41c4
000b5478 addiu $a3, $sp, 0x16
000b547c lui $a1, 0x124
000b5480 lh $a0, 0x14($sp)
000b5484 addiu $a1, $a1, -0x5ed8
000b5488 lw $a2, 0x528($a1)
000b548c sra $a3, $a0, 1
000b5490 mtc1 $a2, $f12
000b5494 srl $a2, $a3, 0x1f
000b5498 cvt.s.w $f12, $f12
000b549c lui $a3, 0x32
000b54a0 addu $a0, $a0, $a2
000b54a4 lwc1 $f13, -0xb78($a3)
000b54a8 sra $a0, $a0, 1
000b54ac mtc1 $a0, $f14
000b54b0 lw $a1, 0x52c($a1)
000b54b4 add.s $f12, $f12, $f13
000b54b8 lh $a0, 0x16($sp)
000b54bc cvt.s.w $f14, $f14
000b54c0 lh $a2, 0x10($sp)
000b54c4 mtc1 $a1, $f15
000b54c8 lui $a3, 0x32
000b54cc sra $a1, $a0, 1
000b54d0 mtc1 $a2, $f17
000b54d4 cvt.s.w $f13, $f15
000b54d8 srl $a1, $a1, 0x1f
000b54dc sub.s $f12, $f12, $f14
000b54e0 addu $a0, $a0, $a1
000b54e4 lwc1 $f16, -0xb74($a3)
000b54e8 sra $a0, $a0, 1
000b54ec add.s $f13, $f13, $f16
000b54f0 lui $a2, 0x40a0
000b54f4 mtc1 $a0, $f14
000b54f8 cvt.s.w $f14, $f14
000b54fc lh $a0, 0x12($sp)
000b5500 mtc1 $a2, $f18
