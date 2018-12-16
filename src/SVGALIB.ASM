	.386p
	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
	endif
	?debug	V 300h
	?debug	S "SVGALIB.CPP"
	?debug	C E9E49B09250B535647414C49422E435050
	?debug	C E96B5F262509535647414C49422E48
SVGALIB_TEXT	segment byte public use16 'CODE'
SVGALIB_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:SVGALIB_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public use16 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
SVGALIB_TEXT	segment byte public use16 'CODE'
	?debug	C E8010B535647414C49422E435050E49B0925
	?debug	L 21
	assume	cs:SVGALIB_TEXT
@_tseng$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 23
	push	    bx
	?debug	L 24
	cli	
	?debug	L 26
	mov	     _curbk,ax
	?debug	L 27
	and	     al,7
	?debug	L 28
	mov	     ah,al
	?debug	L 29
	shl	     al,1
	?debug	L 30
	shl	     al,1
	?debug	L 31
	shl	     al,1
	?debug	L 32
	or	      al,ah
	?debug	L 33
	or	      al,01000000b
	?debug	L 34
	mov	     dx,3cdh
	?debug	L 35
	out	     dx,al
	?debug	L 36
	sti	
	?debug	L 37
	pop	     bx
	?debug	L 39
	jmp	short @1@450
@1@450:
	?debug	L 40
	pop	bp
	ret	
	?debug	E
	?debug	E
@_tseng$qv	endp
	?debug	L 42
	assume	cs:SVGALIB_TEXT
@_tseng4$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 44
	push	    bx
	?debug	L 45
	cli	
	?debug	L 47
	mov	     [_curbk],ax
	?debug	L 48
	mov	     ah,al
	?debug	L 49
	mov	     dx,3bfh         
	?debug	L 50
	mov	     al,3
	?debug	L 51
	out	     dx,al
	?debug	L 52
	mov	     dl,0d8h
	?debug	L 53
	mov	     al,0a0h
	?debug	L 54
	out	     dx,al
	?debug	L 55
	and	     ah,15
	?debug	L 56
	mov	     al,ah
	?debug	L 57
	shl	     al,1
	?debug	L 58
	shl	     al,1
	?debug	L 59
	shl	     al,1
	?debug	L 60
	shl	     al,1
	?debug	L 61
	or	      al,ah
	?debug	L 62
	mov	     dl,0cdh
	?debug	L 63
	out	     dx,al
	?debug	L 64
	sti	
	?debug	L 65
	pop	     bx
	?debug	L 67
	jmp	short @2@646
@2@646:
	?debug	L 68
	pop	bp
	ret	
	?debug	E
	?debug	E
@_tseng4$qv	endp
	?debug	L 69
	assume	cs:SVGALIB_TEXT
@_trident$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 72
	push	    bx
	?debug	L 73
	push	    ax
	?debug	L 74
	cli	
	?debug	L 75
	mov	     [_curbk],ax
	?debug	L 76
	mov	     dx,3ceh         
	?debug	L 77
	mov	     al,6
	?debug	L 78
	out	     dx,al
	?debug	L 79
	inc	     dl
	?debug	L 80
	in	      al,dx
	?debug	L 81
	dec	     dl
	?debug	L 82
	or	      al,4
	?debug	L 83
	mov	     ah,al
	?debug	L 84
	mov	     al,6
	?debug	L 85
	out	     dx,ax
	?debug	L 87
	mov	     dl,0c4h         
	?debug	L 88
	mov	     al,0bh
	?debug	L 89
	out	     dx,al
	?debug	L 90
	inc	     dl
	?debug	L 91
	in	      al,dx
	?debug	L 92
	dec	     dl
	?debug	L 94
	pop	     ax
	?debug	L 95
	mov	     ah,al
	?debug	L 96
	xor	     ah,2
	?debug	L 97
	mov	     dx,3c4h
	?debug	L 98
	mov	     al,0eh
	?debug	L 99
	out	     dx,ax
	?debug	L 100
	sti	
	?debug	L 101
	pop	     bx
	?debug	L 103
	jmp	short @3@842
@3@842:
	?debug	L 104
	pop	bp
	ret	
	?debug	E
	?debug	E
@_trident$qv	endp
	?debug	L 105
	assume	cs:SVGALIB_TEXT
@_video7$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 107
	push	    bx
	?debug	L 108
	cli	
	?debug	L 110
	mov	     [_curbk],ax
	?debug	L 111
	and	     ax,15
	?debug	L 112
	mov	     ch,al
	?debug	L 113
	mov	     dx,3c4h
	?debug	L 114
	mov	     ax,0ea06h
	?debug	L 115
	out	     dx,ax
	?debug	L 116
	mov	     ah,ch
	?debug	L 117
	and	     ah,1
	?debug	L 118
	mov	     al,0f9h
	?debug	L 119
	out	     dx,ax
	?debug	L 120
	mov	     al,ch
	?debug	L 121
	and	     al,1100b
	?debug	L 122
	mov	     ah,al
	?debug	L 123
	shr	     ah,1
	?debug	L 124
	shr	     ah,1
	?debug	L 125
	or	      ah,al
	?debug	L 126
	mov	     al,0f6h
	?debug	L 127
	out	     dx,al
	?debug	L 128
	inc	     dx
	?debug	L 129
	in	      al,dx
	?debug	L 130
	dec	     dx
	?debug	L 131
	and	     al,not 1111b
	?debug	L 132
	or	      ah,al
	?debug	L 133
	mov	     al,0f6h
	?debug	L 134
	out	     dx,ax
	?debug	L 135
	mov	     ah,ch
	?debug	L 136
	mov	     cl,4
	?debug	L 137
	shl	     ah,cl
	?debug	L 138
	and	     ah,100000b
	?debug	L 139
	mov	     dl,0cch
	?debug	L 140
	in	      al,dx
	?debug	L 141
	mov	     dl,0c2h
	?debug	L 142
	and	     al,not 100000b
	?debug	L 143
	or	      al,ah
	?debug	L 144
	out	     dx,al
	?debug	L 145
	sti	
	?debug	L 146
	pop	     bx
	?debug	L 148
	jmp	short @4@1150
@4@1150:
	?debug	L 149
	pop	bp
	ret	
	?debug	E
	?debug	E
@_video7$qv	endp
	?debug	L 151
	assume	cs:SVGALIB_TEXT
@_paradise$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 154
	push	    bx
	?debug	L 155
	push	    ax
	?debug	L 156
	cli	
	?debug	L 157
	mov	     [_curbk],ax
	?debug	L 158
	mov	     dx,3ceh
	?debug	L 159
	mov	     ax,50fh         
	?debug	L 160
	out	     dx,ax
	?debug	L 161
	pop	     ax
	?debug	L 162
	mov	     ah,al
	?debug	L 163
	mov	     al,9
	?debug	L 164
	out	     dx,ax
	?debug	L 165
	sti	
	?debug	L 166
	pop	     bx
	?debug	L 168
	jmp	short @5@422
@5@422:
	?debug	L 169
	pop	bp
	ret	
	?debug	E
	?debug	E
@_paradise$qv	endp
	?debug	L 171
	assume	cs:SVGALIB_TEXT
@_acumos$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 174
	push	    bx
	?debug	L 175
	push	    ax
	?debug	L 176
	cli	
	?debug	L 177
	mov	     [_curbk],ax
	?debug	L 178
	mov	     dx,3c4h         
	?debug	L 179
	mov	     ax,1206h        
	?debug	L 180
	out	     dx,ax
	?debug	L 181
	mov	     dx,3ceh
	?debug	L 182
	pop	     ax
	?debug	L 183
	mov	     ah,al
	?debug	L 184
	mov	     al,9
	?debug	L 185
	out	     dx,ax
	?debug	L 186
	sti	
	?debug	L 187
	pop	     bx
	?debug	L 189
	jmp	short @6@450
@6@450:
	?debug	L 190
	pop	bp
	ret	
	?debug	E
	?debug	E
@_acumos$qv	endp
	?debug	L 192
	assume	cs:SVGALIB_TEXT
@_chipstech$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 195
	push	    bx
	?debug	L 196
	push	    ax
	?debug	L 197
	cli	
	?debug	L 198
	mov	     [_curbk],ax
	?debug	L 199
	mov	     dx,46e8h        
	?debug	L 200
	mov	     ax,1eh
	?debug	L 201
	out	     dx,ax
	?debug	L 202
	mov	     dx,103h         
	?debug	L 203
	mov	     ax,0080h
	?debug	L 204
	out	     dx,ax
	?debug	L 205
	mov	     dx,46e8h        
	?debug	L 206
	mov	     ax,0eh
	?debug	L 207
	out	     dx,ax
	?debug	L 208
	pop	     ax
	?debug	L 209
	mov	     ah,al
	?debug	L 210
	mov	     al,10h
	?debug	L 211
	mov	     dx,3d6h
	?debug	L 212
	out	     dx,ax
	?debug	L 213
	sti	
	?debug	L 214
	pop	     bx
	?debug	L 216
	jmp	short @7@618
@7@618:
	?debug	L 217
	pop	bp
	ret	
	?debug	E
	?debug	E
@_chipstech$qv	endp
	?debug	L 220
	assume	cs:SVGALIB_TEXT
@_ativga$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 223
	push	    bx
	?debug	L 224
	cli	
	?debug	L 225
	mov	     [_curbk],ax
	?debug	L 226
	mov	     ah,al
	?debug	L 227
	mov	     dx,1ceh
	?debug	L 228
	mov	     al,0b2h
	?debug	L 229
	out	     dx,al
	?debug	L 230
	inc	     dl
	?debug	L 231
	in	      al,dx
	?debug	L 232
	shl	     ah,1
	?debug	L 233
	and	     al,0e1h
	?debug	L 234
	or	      ah,al
	?debug	L 235
	mov	     al,0b2h
	?debug	L 236
	dec	     dl
	?debug	L 237
	out	     dx,ax
	?debug	L 238
	sti	
	?debug	L 239
	pop	     bx
	?debug	L 241
	jmp	short @8@534
@8@534:
	?debug	L 242
	pop	bp
	ret	
	?debug	E
	?debug	E
@_ativga$qv	endp
	?debug	L 244
	assume	cs:SVGALIB_TEXT
@_everex$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 247
	push	    bx
	?debug	L 248
	cli	
	?debug	L 249
	mov	     [_curbk],ax
	?debug	L 250
	mov	     cl,al
	?debug	L 251
	mov	     dx,3c4h
	?debug	L 252
	mov	     al,8
	?debug	L 253
	out	     dx,al
	?debug	L 254
	inc	     dl
	?debug	L 255
	in	      al,dx
	?debug	L 256
	dec	     dl
	?debug	L 257
	shl	     al,1
	?debug	L 258
	shr	     cl,1
	?debug	L 259
	rcr	     al,1
	?debug	L 260
	mov	     ah,al
	?debug	L 261
	mov	     al,8
	?debug	L 262
	out	     dx,ax
	?debug	L 263
	mov	     dl,0cch
	?debug	L 264
	in	      al,dx
	?debug	L 265
	mov	     dl,0c2h
	?debug	L 266
	and	     al,0dfh
	?debug	L 267
	shr	     cl,1
	?debug	L 268
	jc	short @9@674
	?debug	L 269
	or	      al,20h
@9@674:
	?debug	L 272
    	out	     dx,al
	?debug	L 273
	sti	
	?debug	L 274
	pop	     bx
	?debug	L 276
	jmp	short @9@786
@9@786:
	?debug	L 277
	pop	bp
	ret	
	?debug	E
	?debug	E
@_everex$qv	endp
	?debug	L 278
	assume	cs:SVGALIB_TEXT
@_aheada$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 281
	push	    bx
	?debug	L 282
	cli	
	?debug	L 283
	mov	     [_curbk],ax
	?debug	L 284
	mov	     ch,al
	?debug	L 285
	mov	     dx,3ceh         
	?debug	L 286
	mov	     ax,200fh
	?debug	L 287
	out	     dx,ax
	?debug	L 288
	mov	     dl,0cch         
	?debug	L 289
	in	      al,dx
	?debug	L 290
	mov	     dl,0c2h
	?debug	L 291
	and	     al,11011111b
	?debug	L 292
	shr	     ch,1
	?debug	L 293
	jnc	short @10@422
	?debug	L 294
	or	      al,00100000b
@10@422:
	?debug	L 297
	out	     dx,al
	?debug	L 298
	mov	     dl,0cfh         
	?debug	L 299
	mov	     al,0
	?debug	L 300
	out	     dx,al
	?debug	L 301
	inc	     dx
	?debug	L 302
	in	      al,dx
	?debug	L 303
	dec	     dx
	?debug	L 304
	and	     al,11111000b
	?debug	L 305
	or	      al,ch
	?debug	L 306
	mov	     ah,al
	?debug	L 307
	mov	     al,0
	?debug	L 308
	out	     dx,ax
	?debug	L 309
	sti	
	?debug	L 310
	pop	     bx
	?debug	L 312
	jmp	short @10@842
@10@842:
	?debug	L 314
	pop	bp
	ret	
	?debug	E
	?debug	E
@_aheada$qv	endp
	?debug	L 315
	assume	cs:SVGALIB_TEXT
@_aheadb$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 318
	push	    bx
	?debug	L 319
	cli	
	?debug	L 320
	mov	     [_curbk],ax
	?debug	L 321
	mov	     ch,al
	?debug	L 322
	mov	     dx,3ceh         
	?debug	L 323
	mov	     ax,200fh
	?debug	L 324
	out	     dx,ax
	?debug	L 325
	mov	     ah,ch
	?debug	L 326
	mov	     cl,4
	?debug	L 327
	shl	     ah,cl
	?debug	L 328
	or	      ah,ch
	?debug	L 329
	mov	     al,0dh
	?debug	L 330
	out	     dx,ax
	?debug	L 331
	sti	
	?debug	L 332
	pop	     bx
	?debug	L 334
	jmp	short @11@478
@11@478:
	?debug	L 336
	pop	bp
	ret	
	?debug	E
	?debug	E
@_aheadb$qv	endp
	?debug	L 337
	assume	cs:SVGALIB_TEXT
@_oaktech$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 340
	push	    bx
	?debug	L 341
	cli	
	?debug	L 342
	mov	     [_curbk],ax
	?debug	L 343
	and	     al,15
	?debug	L 344
	mov	     ah,al
	?debug	L 345
	shl	     al,1
	?debug	L 346
	shl	     al,1
	?debug	L 347
	shl	     al,1
	?debug	L 348
	shl	     al,1
	?debug	L 349
	or	      ah,al
	?debug	L 350
	mov	     al,11h
	?debug	L 351
	mov	     dx,3deh
	?debug	L 352
	out	     dx,ax
	?debug	L 353
	sti	
	?debug	L 354
	pop	     bx
	?debug	L 356
	jmp	short @12@478
@12@478:
	?debug	L 357
	pop	bp
	ret	
	?debug	E
	?debug	E
@_oaktech$qv	endp
	?debug	L 358
	assume	cs:SVGALIB_TEXT
@_genoa$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 361
	push	    bx
	?debug	L 362
	cli	
	?debug	L 363
	mov	     [_curbk],ax
	?debug	L 364
	mov	     ah,al
	?debug	L 365
	shl	     al,1
	?debug	L 366
	shl	     al,1
	?debug	L 367
	shl	     al,1
	?debug	L 368
	or	      ah,al
	?debug	L 369
	mov	     al,6
	?debug	L 370
	or	      ah,40h
	?debug	L 371
	mov	     dx,3c4h
	?debug	L 372
	out	     dx,ax
	?debug	L 373
	sti	
	?debug	L 374
	pop	     bx
	?debug	L 376
	jmp	short @13@450
@13@450:
	?debug	L 377
	pop	bp
	ret	
	?debug	E
	?debug	E
@_genoa$qv	endp
	?debug	L 378
	assume	cs:SVGALIB_TEXT
@_ncr$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 381
	push	    bx
	?debug	L 382
	cli	
	?debug	L 383
	mov	     [_curbk],ax
	?debug	L 384
	mov	     ah,al
	?debug	L 385
	mov	     al,18h
	?debug	L 386
	mov	     dx,3c4h
	?debug	L 387
	out	     dx,ax
	?debug	L 388
	mov	     ax,19h
	?debug	L 389
	out	     dx,ax
	?debug	L 390
	sti	
	?debug	L 392
	jmp	short @14@338
@14@338:
	?debug	L 393
	pop	bp
	ret	
	?debug	E
	?debug	E
@_ncr$qv	endp
	?debug	L 394
	assume	cs:SVGALIB_TEXT
@_compaq$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 397
	push	    bx
	?debug	L 398
	push	    ax
	?debug	L 399
	cli	
	?debug	L 400
	mov	     [_curbk],ax
	?debug	L 401
	mov	     dx,3ceh
	?debug	L 402
	mov	     ax,50fh         
	?debug	L 403
	out	     dx,ax
	?debug	L 404
	pop	     ax
	?debug	L 405
	mov	     ah,al
	?debug	L 406
	mov	     al,45h
	?debug	L 407
	out	     dx,ax
	?debug	L 408
	sti	
	?debug	L 409
	pop	     bx
	?debug	L 411
	jmp	short @15@422
@15@422:
	?debug	L 412
	pop	bp
	ret	
	?debug	E
	?debug	E
@_compaq$qv	endp
	?debug	L 413
	assume	cs:SVGALIB_TEXT
@_vesa$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 416
	push	    bx
	?debug	L 417
	cli	
	?debug	L 418
	mov	     [_curbk],ax
	?debug	L 419
	mov	     dx,ax
	?debug	L 420
	xor	     bx,bx
	?debug	L 421
	call	    dword ptr [_vesafunc]
	?debug	L 422
	mov	     dx,[_curbk]
	?debug	L 423
	mov	     bx,1
	?debug	L 424
	call	    dword ptr [_vesafunc]
	?debug	L 425
	sti	
	?debug	L 426
	pop	     bx
	?debug	L 428
	jmp	short @16@366
@16@366:
	?debug	L 430
	pop	bp
	ret	
	?debug	E
	?debug	E
@_vesa$qv	endp
	?debug	L 431
	assume	cs:SVGALIB_TEXT
@_nobank$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 434
	cli	
	?debug	L 435
	mov	     [_curbk],ax
	?debug	L 436
	sti	
	?debug	L 438
	pop	bp
	ret	
	?debug	E
	?debug	E
@_nobank$qv	endp
	?debug	L 440
	assume	cs:SVGALIB_TEXT
@whichvga$qv	proc	far
	?debug	B
	enter	286,0
	push	si
	push	di
	?debug	B
	?debug	L 443
	cmp	     [_first],'FI'          
	?debug	L 444
	jne	short @18@142
	?debug	L 445
	mov	     ax,[_retval]
@18@114:
	?debug	L 447
	mov	ax,seg _retval
	mov	es,ax
	mov	ax,word ptr es:_retval
	jmp	@18@11986
@18@142:
	?debug	L 449
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_nobank$qv
	mov	word ptr es:_bankadr,offset @_nobank$qv
	?debug	L 451
	mov	     [_vgamem],256
	?debug	L 452
	mov	     [_bksize],64
	?debug	L 453
	xor	     ax,ax
	?debug	L 454
	mov	     [_curbk],ax
	?debug	L 455
	mov	     [_cirrus],ax
	?debug	L 456
	mov	     [_everex],ax
	?debug	L 457
	mov	     [_paradise],ax
	?debug	L 458
	mov	     [_tseng],ax
	?debug	L 459
	mov	     [_trident],ax
	?debug	L 460
	mov	     [_t8900],ax
	?debug	L 461
	mov	     [_ativga],ax
	?debug	L 462
	mov	     [_aheada],ax
	?debug	L 463
	mov	     [_aheadb],ax
	?debug	L 464
	mov	     [_oaktech],ax
	?debug	L 465
	mov	     [_video7],ax
	?debug	L 466
	mov	     [_chipstech],ax
	?debug	L 467
	mov	     [_tseng4],ax
	?debug	L 468
	mov	     [_genoa],ax
	?debug	L 469
	mov	     [_ncr],ax
	?debug	L 470
	mov	     [_compaq],ax
	?debug	L 471
	mov	     [_vesa],ax
	?debug	L 472
	mov	     [_dactype],ax
	?debug	L 473
	mov	     [_first],'FI'
	?debug	L 475
	mov	     si,1                  
	?debug	L 476
	mov	     ax,ss
	?debug	L 477
	mov	     es,ax
	?debug	L 478
	lea	     di,[bp-286][0]
	?debug	L 479
	mov	     ax,4f00h
	?debug	L 480
	int	     10h
	?debug	L 481
	cmp	     ax,4fh
	?debug	L 482
	jne	short @18@2410
	?debug	L 483
	mov	     [_bksize],64            
	?debug	L 484
	mov	     si,offset _vesamodes
	?debug	L 485
	cld	
	?debug	L 487
	mov	ax,seg _vesafunc
	mov	es,ax
	mov	word ptr es:_vesafunc+2,seg @dummyvesa$qv
	mov	word ptr es:_vesafunc,offset @dummyvesa$qv
	?debug	L 488
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_vesa$qv
	mov	word ptr es:_bankadr,offset @_vesa$qv
	?debug	L 489
	mov	ax,seg _vesa
	mov	es,ax
	mov	word ptr es:_vesa,1
@18@1150:
	?debug	L 492
	lodsw	
	?debug	L 493
	mov	     cx,ax
	?debug	L 494
	jcxz	short @18@2130
	?debug	L 495
	mov	     ax,ss
	?debug	L 496
	mov	     es,ax
	?debug	L 497
	lea	     di,[bp-286][0]
	?debug	L 498
	mov	     ax,4f01h               
	?debug	L 499
	int	     10h
	?debug	L 500
	or	      ah,ah
	?debug	L 501
	jne	short @18@2102
	?debug	L 502
	test	    byte ptr es:[di],1
	?debug	L 503
	je	short @18@2102
	?debug	L 504
	lodsw	
	?debug	L 505
	mov	     cx,ax
	?debug	L 506
	lodsw	
	?debug	L 507
	mov	     bx,ax
	?debug	L 508
	lodsw	
	?debug	L 509
	mul	     cx                     
	?debug	L 510
	shr	     dx,1                   
	?debug	L 511
	rcr	     ax,1
	?debug	L 512
	shr	     dx,1
	?debug	L 513
	rcr	     ax,1
	?debug	L 514
	shr	     dx,1
	?debug	L 515
	rcr	     ax,1
	?debug	L 516
	mul	     bx                     
	?debug	L 517
	mov	     bx,1024
	?debug	L 518
	add	     ax,bx                  
	?debug	L 519
	dec	     ax
	?debug	L 520
	adc	     dx,0
	?debug	L 521
	div	     bx
	?debug	L 522
	cmp	     ax,[_vgamem]            
	?debug	L 523
	jbe	short @18@1150
	?debug	L 524
	mov	     [_vgamem],ax            
	?debug	L 526
	mov	ax,seg _bksize
	mov	dx,word ptr [bp-280]
	mov	es,ax
	mov	word ptr es:_bksize,dx
	?debug	L 527
	jmp	@18@1150
@18@2102:
	?debug	L 529
	add	si,6
	?debug	L 530
	jmp	@18@1150
@18@2130:
	?debug	L 533
	mov	     ax,[_vgamem]
	?debug	L 534
	inc	     ah
	?debug	L 535
	dec	     ax
	?debug	L 536
	mov	     al,0                   
	?debug	L 537
	cmp	     ax,1024
	?debug	L 538
	jb	short @18@2354
	?debug	L 539
	add	     ax,1023                
	?debug	L 540
	and	     ax,not 1023
@18@2354:
	?debug	L 544
	mov	     [_vgamem],ax
	?debug	L 546
	jmp	@18@11818
@18@2410:
	?debug	L 551
	mov	     ax,0c000h              
	?debug	L 552
	mov	     es,ax
	?debug	L 553
	cmp	     word ptr es:[40h],'13' 
	?debug	L 554
	jne	short @18@3390
	?debug	L 556
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_ativga$qv
	mov	word ptr es:_bankadr,offset @_ativga$qv
	?debug	L 557
	mov	ax,seg _ativga
	mov	es,ax
	mov	word ptr es:_ativga,1
	?debug	L 558
    	mov	     [_bksize],64            
	?debug	L 559
	mov	     dx,es:[10h]            
	?debug	L 560
	mov	     bl,es:[43h]            
	?debug	L 561
	cmp	     bl,'3'                 
	?debug	L 562
	jae	short @18@2970
	?debug	L 563
	mov	     al,0bbh                
	?debug	L 564
	cli	
	?debug	L 565
	out	     dx,al
	?debug	L 566
	inc	     dx
	?debug	L 567
	in	      al,dx                  
	?debug	L 568
	sti	
	?debug	L 569
	test	    al,20h
	?debug	L 570
	je	short @18@3362
	?debug	L 571
	mov	     [_vgamem],512
	?debug	L 572
	jmp	short @18@3362
@18@2970:
	?debug	L 576
	mov	     al,0b0h                
	?debug	L 577
	cli	
	?debug	L 578
	out	     dx,al
	?debug	L 579
	inc	     dx
	?debug	L 580
	in	      al,dx                  
	?debug	L 581
	sti	
	?debug	L 582
	test	    al,10h                 
	?debug	L 583
	je	short @18@3222
	?debug	L 584
	mov	     [_vgamem],512
@18@3222:
	?debug	L 588
	cmp	     bl,'4'                 
	?debug	L 589
	jb	short @18@3362
	?debug	L 590
	test	    al,8                   
	?debug	L 591
	je	short @18@3362
	?debug	L 592
	mov	     [_vgamem],1024
@18@3362:
	?debug	L 594
	jmp	@18@11818
@18@3390:
	?debug	L 598
	mov	     ax,7000h               
	?debug	L 599
	xor	     bx,bx
	?debug	L 600
	cld	
	?debug	L 601
	int	     10h
	?debug	L 602
	cmp	     al,70h
	?debug	L 603
	jne	short @18@3698
	?debug	L 605
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_everex$qv
	mov	word ptr es:_bankadr,offset @_everex$qv
	?debug	L 606
	mov	ax,seg _everex
	mov	es,ax
	mov	word ptr es:_everex,1
	?debug	L 607
    	mov	     [_bksize],64            
	?debug	L 608
	and	     ch,11000000b           
	?debug	L 609
	je	short @18@3698
	?debug	L 610
	mov	     [_vgamem],512
@18@3698:
	?debug	L 615
	mov	     ax,0bf03h              
	?debug	L 616
	xor	     bx,bx
	?debug	L 617
	mov	     cx,bx
	?debug	L 618
	int	     10h
	?debug	L 619
	cmp	     ax,0bf03h
	?debug	L 620
	jne	short @18@4034
	?debug	L 621
	test	    cl,40h                 
	?debug	L 622
	je	short @18@4034
	?debug	L 624
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_compaq$qv
	mov	word ptr es:_bankadr,offset @_compaq$qv
	?debug	L 625
	mov	ax,seg _compaq
	mov	es,ax
	mov	word ptr es:_compaq,1
	?debug	L 626
    	mov	     [_bksize],4             
	?debug	L 627
	mov	     [_vgamem],512
	?debug	L 628
	jmp	@18@11818
@18@4034:
	?debug	L 631
	mov	     dx,3c4h                
	?debug	L 632
	mov	     ax,0ff05h
	?debug	L 633
	call	far ptr @_isport2$qv
	?debug	L 634
	jne	short @18@4454
	?debug	L 635
	mov	     ax,5                   
	?debug	L 636
	out	     dx,ax
	?debug	L 637
	mov	     ax,0ff10h              
	?debug	L 638
	call	far ptr @_isport2$qv
	?debug	L 639
	je	short @18@4454
	?debug	L 640
	mov	     ax,105h                
	?debug	L 641
	out	     dx,ax
	?debug	L 642
	mov	     ax,0ff10h
	?debug	L 643
	call	far ptr @_isport2$qv
	?debug	L 644
	jne	short @18@4454
	?debug	L 645
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg _ncr
	mov	word ptr es:_bankadr,offset _ncr
	?debug	L 646
	mov	ax,seg _ncr
	mov	es,ax
	mov	word ptr es:_ncr,1
	?debug	L 648
	mov	     [_bksize],16            
	?debug	L 649
	mov	     [_vgamem],512
	?debug	L 650
	jmp	@18@11818
@18@4454:
	?debug	L 653
	mov	     dx,3c4h                
	?debug	L 654
	mov	     al,0bh
	?debug	L 655
	out	     dx,al
	?debug	L 656
	inc	     dl
	?debug	L 657
	in	      al,dx
	?debug	L 658
	and	     al,0fh
	?debug	L 659
	cmp	     al,06h
	?debug	L 660
	ja	short @18@5210
	?debug	L 661
	cmp	     al,2
	?debug	L 662
	jb	short @18@5210
	?debug	L 664
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_trident$qv
	mov	word ptr es:_bankadr,offset @_trident$qv
	?debug	L 665
	mov	ax,seg _trident
	mov	es,ax
	mov	word ptr es:_trident,1
	?debug	L 667
	mov	     [_bksize],64            
	?debug	L 668
	cmp	     al,3
	?debug	L 669
	jb	short @18@5154
	?debug	L 670
	mov	     [_t8900],1
	?debug	L 671
	mov	     dx,3d4h
	?debug	L 672
	mov	     al,1fh
	?debug	L 673
	out	     dx,al
	?debug	L 674
	inc	     dx
	?debug	L 675
	in	      al,dx
	?debug	L 676
	and	     ax,3
	?debug	L 677
	inc	     al
	?debug	L 678
	xchg	    al,ah
	?debug	L 679
	mov	     [_vgamem],ax
	?debug	L 680
	jmp	@18@11818
@18@5154:
	?debug	L 683
	mov	     [_vgamem],512
	?debug	L 684
	jmp	@18@11818
@18@5210:
	?debug	L 687
	mov	     ax,6f00h               
	?debug	L 688
	xor	     bx,bx
	?debug	L 689
	cld	
	?debug	L 690
	int	     10h
	?debug	L 691
	cmp	     bx,'V7'
	?debug	L 692
	jne	short @18@5742
	?debug	L 693
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_video7$qv
	mov	word ptr es:_bankadr,offset @_video7$qv
	?debug	L 694
	mov	ax,seg _video7
	mov	es,ax
	?debug	L 696
	mov	     [_bksize],64            
	?debug	L 697
	mov	     ax,6f07h
	?debug	L 698
	cld	
	?debug	L 699
	int	     10h
	?debug	L 700
	and	     ah,7fh
	?debug	L 701
	cmp	     ah,1
	?debug	L 702
	jbe	short @18@5630
	?debug	L 703
	mov	     [_vgamem],512
@18@5630:
	?debug	L 706
	cmp	     ah,3
	?debug	L 707
	jbe	short @18@5714
	?debug	L 708
	mov	     [_vgamem],1024
@18@5714:
	?debug	L 710
	jmp	@18@11818
@18@5742:
	?debug	L 713
	mov	     dx,3d4h                
	?debug	L 714
	mov	     al,2eh                 
	?debug	L 715
	out	     dx,al
	?debug	L 716
	inc	     dx
	?debug	L 717
	in	      al,dx
	?debug	L 718
	dec	     dx
	?debug	L 719
	test	    al,11111100b           
	?debug	L 720
	jne	short @18@6834
	?debug	L 721
	mov	     ax,032eh               
	?debug	L 723
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@6050
	jmp	@18@6834
@18@6050:
	?debug	L 725
	mov	     dx,3c4h
	?debug	L 726
	mov	     al,7
	?debug	L 727
	out	     dx,al
	?debug	L 728
	inc	     dx
	?debug	L 729
	in	      al,dx
	?debug	L 730
	dec	     dx
	?debug	L 731
	test	    al,10001000b
	?debug	L 732
	jne	short @18@6834
	?debug	L 733
	mov	     al,10h
	?debug	L 734
	out	     dx,al
	?debug	L 735
	inc	     dx
	?debug	L 736
	in	      al,dx
	?debug	L 737
	dec	     dx
	?debug	L 738
	and	     al,00110000b
	?debug	L 739
	cmp	     al,00100000b
	?debug	L 740
	jne	short @18@6834
	?debug	L 741
	mov	     dx,3ceh
	?debug	L 742
	mov	     ax,0ff0bh
	?debug	L 744
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@6610
	jmp	short @18@6834
@18@6610:
	?debug	L 745
	mov	dx,964
	mov	ax,16134
	?debug	L 746
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@6666
	jmp	short @18@6834
@18@6666:
	?debug	L 747
	mov	 dx,3ceh
	mov	 ax,0ff0ah
	?debug	L 748
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@6778
	jmp	short @18@6834
@18@6778:
	?debug	L 749
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_genoa$qv
	mov	word ptr es:_bankadr,offset @_genoa$qv
	?debug	L 750
	mov	ax,seg _genoa
	mov	es,ax
	mov	word ptr es:_genoa,1
	?debug	L 751
	mov	ax,seg _bksize
	mov	es,ax
	mov	word ptr es:_bksize,64
	mov	ax,seg _vgamem
	mov	es,ax
	mov	word ptr es:_vgamem,512
	?debug	L 752
	jmp	@18@11818
@18@6834:
	?debug	L 753
	call	far ptr @_cirrus$qv
	?debug	L 754
	mov	ax,seg _cirrus
	mov	es,ax
	cmp	word ptr es:_cirrus,0
	jne	short @18@6890
	jmp	@18@7674
@18@6890:
	?debug	L 755
	jmp	@18@11818
	?debug	L 757
	mov	     dx,3ceh                
	?debug	L 758
	mov	     al,9                   
	?debug	L 759
	out	     dx,al
	?debug	L 760
	inc	     dx
	?debug	L 761
	in	      al,dx
	?debug	L 762
	dec	     dx
	?debug	L 763
	or	      al,al
	?debug	L 764
	jne	short @18@7674
	?debug	L 766
	mov	     ax,50fh                
	?debug	L 767
	out	     dx,ax
	?debug	L 769
	mov	dx,offset @_paradise$qv
	?debug	L 770
	mov	cx,1
	?debug	L 771
	call	far ptr @_chkbk$qv
	or	ax,ax
	je	short @18@7254
	jmp	short @18@7674
@18@7254:
	?debug	L 772
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_paradise$qv
	mov	word ptr es:_bankadr,offset @_paradise$qv
	?debug	L 773
	mov	ax,seg _paradise
	mov	es,ax
	mov	word ptr es:_paradise,1
	?debug	L 775
	mov	     [_bksize],4             
	?debug	L 776
	mov	     dx,3ceh
	?debug	L 777
	mov	     al,0bh                 
	?debug	L 778
	out	     dx,al
	?debug	L 779
	inc	     dx
	?debug	L 780
	in	      al,dx
	?debug	L 781
	test	    al,80h                 
	?debug	L 782
	je	short @18@7646
	?debug	L 783
	test	    al,40h
	?debug	L 784
	je	short @18@7618
	?debug	L 785
	mov	     [_vgamem],1024
	?debug	L 786
	jmp	@18@11818
@18@7618:
	?debug	L 789
 	mov	 [_vgamem],512 
@18@7646:
	?debug	L 790
	jmp	@18@11818
@18@7674:
	?debug	L 793
	mov	     ax,5f00h               
	?debug	L 794
	xor	     bx,bx
	?debug	L 795
	cld	
	?debug	L 796
	int	     10h
	?debug	L 797
	cmp	     al,5fh
	?debug	L 798
	jne	short @18@8010
	?debug	L 800
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_chipstech$qv
	mov	word ptr es:_bankadr,offset @_chipstech$qv
	?debug	L 801
	mov	ax,seg _chipstech
	mov	es,ax
	mov	word ptr es:_chipstech,1
	?debug	L 803
	mov	     [_bksize],16            
	?debug	L 804
	cmp	     bh,1
	?debug	L 805
	jb	short @18@7982
	?debug	L 806
	mov	     [_vgamem],512
@18@7982:
	?debug	L 808
	jmp	@18@11818
@18@8010:
	?debug	L 811
	mov	     dx,3dah                
	?debug	L 812
	in	      al,dx                  
	?debug	L 813
	mov	     ah,al                  
	?debug	L 814
	shr	     ah,1
	?debug	L 815
	shr	     ah,1
	?debug	L 816
	shr	     ah,1
	?debug	L 817
	shr	     ah,1
	?debug	L 818
	xor	     al,ah
	?debug	L 819
	test	    al,00001000b
	?debug	L 820
	je	short @18@9718
	?debug	L 821
	mov	     dx,3d4h                
	?debug	L 822
	mov	     ax,0f33h
	?debug	L 824
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@8402
	jmp	@18@9438
@18@8402:
	?debug	L 825
	mov	ax,00000FF33h
	?debug	L 826
	call	far ptr @_isport2$qv
	or	ax,ax
	je	short @18@8458
	jmp	@18@9718
@18@8458:
	?debug	L 828
	mov	     dx,3bfh                
	?debug	L 829
	mov	     al,3
	?debug	L 830
	out	     dx,al
	?debug	L 831
	mov	     dx,3d8h
	?debug	L 832
	mov	     al,0a0h
	?debug	L 833
	out	     dx,al
	?debug	L 834
	mov	     al,0ffh
	?debug	L 835
	mov	     dx,3cdh                
	?debug	L 836
	call	far ptr @_isport1$qv
	or	ax,ax
	je	short @18@8738
	jmp	@18@9438
@18@8738:
	?debug	L 837
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_tseng$qv
	mov	word ptr es:_bankadr,offset @_tseng$qv
	?debug	L 838
	mov	ax,seg _tseng
	mov	es,ax
	mov	word ptr es:_tseng,1
	?debug	L 840
	mov	     [_bksize],64            
	?debug	L 841
	mov	     ax,10f1h               
	?debug	L 842
	int	     10h
	?debug	L 843
	cmp	     ax,10h
	?debug	L 844
	jne	short @18@8962
	?debug	L 845
	mov	     bh,0
	?debug	L 846
	mov	     [_dactype],bx
@18@8962:
	?debug	L 849
    	mov	     dx,3d4h                
	?debug	L 850
	mov	     al,37h
	?debug	L 851
	out	     dx,al
	?debug	L 852
	inc	     dx
	?debug	L 853
	in	      al,dx
	?debug	L 854
	test	    al,1000b               
	?debug	L 855
	je	short @18@9354
	?debug	L 856
	and	     al,3
	?debug	L 857
	cmp	     al,1                   
	?debug	L 858
	jbe	short @18@9354
	?debug	L 859
	mov	     [_vgamem],512
	?debug	L 860
	cmp	     al,2                   
	?debug	L 861
	je	short @18@9354
	?debug	L 862
	mov	     [_vgamem],1024          
@18@9354:
	?debug	L 865
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg _tseng4
	mov	word ptr es:_bankadr,offset _tseng4
	?debug	L 866
	mov	ax,seg _tseng4
	mov	es,ax
	mov	word ptr es:_tseng4,1
	?debug	L 868
	mov	     [_bksize],64            
	?debug	L 869
	jmp	@18@11818
@18@9438:
	?debug	L 872
	mov	     dx,3d4h                
	?debug	L 873
	mov	     ax,1f25h               
	?debug	L 875
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@9550
	jmp	short @18@9718
@18@9550:
	?debug	L 877
	mov	     al,03fh                
	?debug	L 878
	mov	     dx,3cdh                
	?debug	L 880
	call	far ptr @_isport1$qv
	or	ax,ax
	jne	short @18@9662
	jmp	short @18@9718
@18@9662:
	?debug	L 881
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_tseng$qv
	mov	word ptr es:_bankadr,offset @_tseng$qv
	?debug	L 882
	mov	ax,seg _tseng
	mov	es,ax
	mov	word ptr es:_tseng,1
	?debug	L 883
	mov	ax,seg _bksize
	mov	es,ax
	mov	word ptr es:_bksize,64
	?debug	L 884
	call	far ptr @_t3memchk$qv
	?debug	L 885
	jmp	@18@11818
@18@9718:
	?debug	L 887
	mov	     dx,3ceh                
	?debug	L 888
	mov	     ax,0ff0fh              
	?debug	L 890
	call	far ptr @_isport2$qv
	or	ax,ax
	je	short @18@9830
	jmp	@18@10278
@18@9830:
	?debug	L 892
	mov	     ax,200fh
	?debug	L 893
	out	     dx,ax
	?debug	L 894
	inc	     dx
	?debug	L 896
	in	      al,dx
	?debug	L 897
	cmp	     al,21h
	?debug	L 898
	je	short @18@10166
	?debug	L 899
	cmp	     al,20h
	?debug	L 900
	jne	short @18@10278
	?debug	L 902
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_aheada$qv
	mov	word ptr es:_bankadr,offset @_aheada$qv
	?debug	L 903
	mov	ax,seg _aheada
	mov	es,ax
	mov	word ptr es:_aheada,1
	?debug	L 905
	mov	     [_bksize],64            
	?debug	L 906
	mov	     [_vgamem],512
	?debug	L 907
	jmp	@18@11818
@18@10166:
	?debug	L 910
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_aheadb$qv
	mov	word ptr es:_bankadr,offset @_aheadb$qv
	?debug	L 911
	mov	ax,seg _aheadb
	mov	es,ax
	mov	word ptr es:_aheadb,1
	?debug	L 913
	mov	     [_bksize],64            
	?debug	L 914
	mov	     [_vgamem],512
	?debug	L 915
	jmp	@18@11818
@18@10278:
	?debug	L 918
	mov	     dx,3c4h                
	?debug	L 919
	mov	     ax,0006h               
	?debug	L 920
	out	     dx,ax
	?debug	L 921
	mov	     ax,0ff09h
	?debug	L 923
	call	far ptr @_isport2$qv
	or	ax,ax
	je	short @18@10446
	jmp	@18@11314
@18@10446:
	?debug	L 924
 	mov	 ax,0ff0ah
	?debug	L 925
	call	far ptr @_isport2$qv
	or	ax,ax
	je	short @18@10530
	jmp	@18@11314
@18@10530:
	?debug	L 927
	mov	     ax,1206h
	?debug	L 928
	out	     dx,ax
	?debug	L 929
	mov	     ax,0ff09h
	?debug	L 931
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@10670
	jmp	@18@11314
@18@10670:
	?debug	L 932
 	mov	 ax,0ff0ah
	?debug	L 933
	call	far ptr @_isport2$qv
	or	ax,ax
	jne	short @18@10754
	jmp	@18@11314
@18@10754:
	?debug	L 934
	mov	dx,offset @_acumos$qv
	mov	cx,1
	?debug	L 935
	call	far ptr @_chkbk$qv
	or	ax,ax
	je	short @18@10810
	jmp	short @18@11314
@18@10810:
	?debug	L 937
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_acumos$qv
	mov	word ptr es:_bankadr,offset @_acumos$qv
	?debug	L 938
	mov	ax,seg _acumos
	mov	es,ax
	mov	word ptr es:_acumos,1
	?debug	L 940
	mov	     [_bksize],4             
	?debug	L 941
	mov	     dx,3c4h
	?debug	L 942
	mov	     al,0ah
	?debug	L 943
	out	     dx,al
	?debug	L 944
	inc	     dx
	?debug	L 945
	in	      al,dx                  
	?debug	L 946
	and	     al,3
	?debug	L 947
	cmp	     al,1
	?debug	L 948
	jb	short @18@11286
	?debug	L 949
	mov	     [_vgamem],512
	?debug	L 950
	cmp	     al,2
	?debug	L 951
	jb	short @18@11286
	?debug	L 952
	mov	     [_vgamem],1024
	?debug	L 953
	cmp	     al,3
	?debug	L 954
	jb	short @18@11286
	?debug	L 955
	mov	     [_vgamem],2048
@18@11286:
	?debug	L 957
	jmp	short @18@11818
@18@11314:
	?debug	L 960
	mov	     dx,3deh                
	?debug	L 961
	mov	     ax,0ff11h              
	?debug	L 962
	jmp	short @18@11426
	jmp	short @18@11790
@18@11426:
	?debug	L 963
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_oaktech$qv
	mov	word ptr es:_bankadr,offset @_oaktech$qv
	?debug	L 964
	mov	ax,seg _oaktech
	mov	es,ax
	mov	word ptr es:_oaktech,1
	?debug	L 966
	mov	     [_bksize],64            
	?debug	L 967
	mov	     al,0dh
	?debug	L 968
	out	     dx,al
	?debug	L 969
	inc	     dx
	?debug	L 971
	in	      al,dx
	?debug	L 972
	test	    al,11000000b
	?debug	L 973
	je	short @18@11762
	?debug	L 974
	mov	     [_vgamem],512
	?debug	L 975
	test	    al,01000000b
	?debug	L 976
	je	short @18@11762
	?debug	L 977
	mov	     [_vgamem],1024
@18@11762:
	?debug	L 979
	jmp	short @18@11818
@18@11790:
	?debug	L 981
 	mov	 si,0
@18@11818:
	?debug	L 985
	cmp	     [_vesa],0
	?debug	L 986
	je	short @18@11902
	?debug	L 988
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_vesa$qv
	mov	word ptr es:_bankadr,offset @_vesa$qv
	?debug	L 989
	mov	ax,seg _vesa
	mov	es,ax
	mov	word ptr es:_vesa,1
@18@11902:
	?debug	L 992
	mov	     ax,si
	?debug	L 993
	mov	     _retval,ax
	jmp	@18@114
@18@11986:
	?debug	L 996
	pop	di
	pop	si
	leave	
	ret	
	?debug	C E3180C766573616D6F6465696E666F1E011E01
	?debug	C E3190000011A08
	?debug	C E607766573616275661802E2FE00
	?debug	E
	?debug	E
@whichvga$qv	endp
	?debug	L 997
	assume	cs:SVGALIB_TEXT
@_t3memchk$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 998
    	mov	     dx,3dah
	?debug	L 999
	in	      al,dx        
	?debug	L 1000
	mov	     dx,03c0h
	?debug	L 1001
	mov	     al,36h
	?debug	L 1002
	out	     dx,al
	?debug	L 1003
	inc	     dx
	?debug	L 1004
	in	      al,dx        
	?debug	L 1005
	push	    ax
	?debug	L 1006
	or	      al,10h
	?debug	L 1007
	dec	     dx
	?debug	L 1008
	out	     dx,al
	?debug	L 1009
	mov	     dx,3ceh      
	?debug	L 1010
	mov	     al,6
	?debug	L 1011
	out	     dx,al
	?debug	L 1012
	inc	     dx
	?debug	L 1013
	in	      al,dx
	?debug	L 1014
	and	     ax,000Ch
	?debug	L 1015
	shr	     ax,1
	?debug	L 1017
	mov	     bx,ax
	?debug	L 1018
	push	    es
	?debug	L 1020
	shl	bx,1
	mov	ax,seg _buftbl
	mov	es,ax
	mov	ax,word ptr es:_buftbl[bx]
	?debug	L 1022
	mov	     es,ax
	?debug	L 1023
	mov	     ax,09C65h
	?debug	L 1024
	mov	     bx,1
	?debug	L 1025
	mov	     es:[bx],ax
	?debug	L 1026
	mov	     es:[bx+2],ax
	?debug	L 1027
	inc	     bx
	?debug	L 1028
	mov	     ax,es:[bx]
	?debug	L 1029
	pop	     es
	?debug	L 1030
	cmp	     ax,0659Ch
	?debug	L 1031
	jne	short @19@926
	?debug	L 1032
	mov	     [_vgamem],512
@19@926:
	?debug	L 1035
    	mov	     dx,3c0h
	?debug	L 1036
	mov	     al,36h
	?debug	L 1037
	out	     dx,al
	?debug	L 1038
	pop	     ax
	?debug	L 1039
	out	     dx,al        
	?debug	L 1041
	pop	bp
	ret	
	?debug	E
	?debug	E
@_t3memchk$qv	endp
	?debug	L 1042
	assume	cs:SVGALIB_TEXT
@_cirrus$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1043
    	mov	     dx,3d4h      
	?debug	L 1044
	mov	     al,0ch       
	?debug	L 1045
	out	     dx,al        
	?debug	L 1046
	inc	     dx           
	?debug	L 1047
	mov	     ah,al        
	?debug	L 1048
	in	      al,dx        
	?debug	L 1049
	xchg	    ah,al        
	?debug	L 1050
	push	    ax           
	?debug	L 1051
	push	    dx           
	?debug	L 1052
	xor	     al,al        
	?debug	L 1053
	out	     dx,al        
	?debug	L 1055
	mov	     al,1fh       
	?debug	L 1056
	dec	     dx           
	?debug	L 1057
	out	     dx,al        
	?debug	L 1058
	inc	     dx           
	?debug	L 1059
	in	      al,dx        
	?debug	L 1060
	mov	     bh,al        
	?debug	L 1062
	mov	     cl,4         
	?debug	L 1063
	mov	     dx,3c4h      
	?debug	L 1064
	mov	     bl,6         
	?debug	L 1066
	ror	     bh,cl        
	?debug	L 1067
	mov	     ax,bx        
	?debug	L 1068
	out	     dx,ax        
	?debug	L 1069
	inc	     dx           
	?debug	L 1070
	in	      al,dx        
	?debug	L 1071
	or	      al,al        
	?debug	L 1072
	jne	short @20@1066
	?debug	L 1074
	ror	     bh,cl        
	?debug	L 1075
	dec	     dx           
	?debug	L 1076
	mov	     ax,bx        
	?debug	L 1077
	out	     dx,ax        
	?debug	L 1078
	inc	     dx           
	?debug	L 1079
	in	      al,dx        
	?debug	L 1080
	cmp	     al,1         
	?debug	L 1081
	jne	short @20@1066
	?debug	L 1082
	mov	     [_cirrus],1
	?debug	L 1084
	mov	ax,seg _bankadr
	mov	es,ax
	mov	word ptr es:_bankadr+2,seg @_nobank$qv
	mov	word ptr es:_bankadr,offset @_nobank$qv
@20@1066:
	?debug	L 1086
    	pop	     dx           
	?debug	L 1087
	dec	     dx           
	?debug	L 1088
	pop	     ax           
	?debug	L 1089
	out	     dx,ax        
	?debug	L 1091
	pop	bp
	ret	
	?debug	E
	?debug	E
@_cirrus$qv	endp
	?debug	L 1092
	assume	cs:SVGALIB_TEXT
@_chkbk$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	push	di
	?debug	B
	?debug	L 1093
    	mov	     di,0b800h
	?debug	L 1094
	mov	     es,di
	?debug	L 1095
	xor	     di,di
	?debug	L 1096
	mov	     bx,1234h
	?debug	L 1098
	call	far ptr @_gochk$qv
	or	ax,ax
	jne	short @21@198
	jmp	short @21@338
@21@198:
	?debug	L 1099
 	mov	 bx,4321h
	?debug	L 1100
	call	far ptr @_gochk$qv
	or	ax,ax
	jne	short @21@282
	jmp	short @21@338
@21@282:
	?debug	L 1101
	xor	ax,ax
@21@310:
	jmp	short @21@366
@21@338:
	?debug	L 1103
	mov	ax,1
	jmp	short @21@310
@21@366:
	?debug	L 1104
	pop	di
	pop	bp
	ret	
	?debug	E
	?debug	E
@_chkbk$qv	endp
	?debug	L 1113
	assume	cs:SVGALIB_TEXT
@_gochk$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	push	si
	push	di
	?debug	B
	?debug	L 1115
	push	    si
	?debug	L 1116
	mov	     si,bx
	?debug	L 1118
	mov	     al,cl
	?debug	L 1119
	call	    dx
	?debug	L 1120
	xchg	    bl,es:[di]
	?debug	L 1121
	mov	     al,ch
	?debug	L 1122
	call	    dx
	?debug	L 1123
	xchg	    bh,es:[di]
	?debug	L 1125
	xchg	    si,bx
	?debug	L 1127
	mov	     al,cl
	?debug	L 1128
	call	    dx
	?debug	L 1129
	xor	     bl,es:[di]
	?debug	L 1130
	mov	     al,ch
	?debug	L 1131
	call	    dx
	?debug	L 1132
	xor	     bh,es:[di]
	?debug	L 1134
	xchg	    si,bx
	?debug	L 1136
	mov	     al,ch
	?debug	L 1137
	call	    dx
	?debug	L 1138
	mov	     es:[di],bh
	?debug	L 1139
	mov	     al,cl
	?debug	L 1140
	call	    dx
	?debug	L 1141
	mov	     es:[di],bl
	?debug	L 1143
	mov	     al,0
	?debug	L 1144
	call	    dx
	?debug	L 1145
	or	      si,si
	?debug	L 1146
	pop	     si
	?debug	L 1148
	pop	di
	pop	si
	pop	bp
	ret	
	?debug	E
	?debug	E
@_gochk$qv	endp
	?debug	L 1149
	assume	cs:SVGALIB_TEXT
@_isport2$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1151
	push	    bx
	?debug	L 1152
	mov	     bx,ax
	?debug	L 1153
	out	     dx,al
	?debug	L 1154
	mov	     ah,al
	?debug	L 1155
	inc	     dx
	?debug	L 1156
	in	      al,dx
	?debug	L 1157
	dec	     dx
	?debug	L 1158
	xchg	    al,ah
	?debug	L 1159
	push	    ax
	?debug	L 1160
	mov	     ax,bx
	?debug	L 1161
	out	     dx,ax
	?debug	L 1162
	out	     dx,al
	?debug	L 1163
	mov	     ah,al
	?debug	L 1164
	inc	     dx
	?debug	L 1165
	in	      al,dx
	?debug	L 1166
	dec	     dx
	?debug	L 1167
	and	     al,bh
	?debug	L 1168
	cmp	     al,bh
	?debug	L 1169
	jne	short @23@842
	?debug	L 1170
	mov	     al,ah
	?debug	L 1171
	mov	     ah,0
	?debug	L 1172
	out	     dx,ax
	?debug	L 1173
	out	     dx,al
	?debug	L 1174
	mov	     ah,al
	?debug	L 1175
	inc	     dx
	?debug	L 1176
	in	      al,dx
	?debug	L 1177
	dec	     dx
	?debug	L 1178
	and	     al,bh
	?debug	L 1179
	cmp	     al,0
@23@842:
	?debug	L 1182
    	pop	     ax
	?debug	L 1183
	out	     dx,ax
	?debug	L 1184
	pop	     bx
	?debug	L 1186
	pop	bp
	ret	
	?debug	E
	?debug	E
@_isport2$qv	endp
	?debug	L 1187
	assume	cs:SVGALIB_TEXT
@_isport1$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1189
	mov	     ah,al
	?debug	L 1190
	in	      al,dx
	?debug	L 1191
	push	    ax
	?debug	L 1192
	mov	     al,ah
	?debug	L 1193
	out	     dx,al
	?debug	L 1194
	in	      al,dx
	?debug	L 1195
	and	     al,ah
	?debug	L 1196
	cmp	     al,ah
	?debug	L 1197
	jne	short @24@422
	?debug	L 1198
	mov	     al,0
	?debug	L 1199
	out	     dx,al
	?debug	L 1200
	in	      al,dx
	?debug	L 1201
	and	     al,ah
	?debug	L 1202
	cmp	     al,0
@24@422:
	?debug	L 1205
	pop	     ax
	?debug	L 1206
	out	     dx,al
	?debug	L 1208
	pop	bp
	ret	
	?debug	E
	?debug	E
@_isport1$qv	endp
	?debug	L 1209
	assume	cs:SVGALIB_TEXT
@dummyvesa$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1210
	pop	bp
	ret	
	?debug	E
	?debug	E
@dummyvesa$qv	endp
	?debug	L 1214
	assume	cs:SVGALIB_TEXT
@mkadrtbl$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	push	si
	push	di
	?debug	B
	?debug	L 1216
	mov	     di,offset _adrtbl
	?debug	L 1217
	mov	     ax,ds
	?debug	L 1218
	mov	     es,ax
	?debug	L 1219
	mov	     bx,[_smaxy]
	?debug	L 1221
	mov	     ax,[_bksize]
	?debug	L 1222
	cmp	     ax,64
	?debug	L 1223
	je	short @26@898
	?debug	L 1224
	mov	     cl,10
	?debug	L 1225
	shl	     ax,cl
	?debug	L 1226
	dec	     ax
	?debug	L 1227
	mov	     si,ax
	?debug	L 1228
	mov	     cl,9
	?debug	L 1229
	mov	     ax,[_bksize]
@26@394:
	?debug	L 1232
	inc	     cl
	?debug	L 1233
	shr	     ax,1
	?debug	L 1234
	jne	short @26@394
	?debug	L 1235
	xor	     ax,ax
	?debug	L 1236
	xor	     dx,dx
@26@534:
	?debug	L 1239
	push	    ax
	?debug	L 1240
	shr	     ax,cl
	?debug	L 1241
	add	     dx,ax
	?debug	L 1242
	pop	     ax
	?debug	L 1243
	and	     ax,si
	?debug	L 1244
	stosw	
	?debug	L 1245
	xchg	    ax,dx
	?debug	L 1246
	stosw	
	?debug	L 1247
	xchg	    ax,dx
	?debug	L 1248
	add	     ax,[_scanline]
	?debug	L 1249
	dec	     bx
	?debug	L 1250
	jne	short @26@534
	?debug	L 1252
	jmp	short @26@1206
@26@898:
	?debug	L 1255
	xor	     ax,ax
	?debug	L 1256
	xor	     dx,dx
	?debug	L 1257
	mov	     si,[_scanline]
	?debug	L 1258
	mov	     cx,bx
@26@1010:
	?debug	L 1261
	stosw	
	?debug	L 1262
	xchg	    ax,dx
	?debug	L 1263
	stosw	
	?debug	L 1264
	xchg	    ax,dx
	?debug	L 1265
	add	     ax,si
	?debug	L 1266
	adc	     dx,0
	?debug	L 1267
	loop	short @26@1010
@26@1206:
	?debug	L 1269
	pop	di
	pop	si
	pop	bp
	ret	
	?debug	E
	?debug	E
@mkadrtbl$qv	endp
	?debug	L 1271
	assume	cs:SVGALIB_TEXT
@svgamode$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1273
	mov	     [_ourseg],0a000h
	?debug	L 1274
	mov	     ax,640
	?debug	L 1275
	mov	     [_smaxx],ax             
	?debug	L 1276
	mov	     [_scanline],ax
	?debug	L 1278
	cmp	     [_vesa],0
	?debug	L 1279
	je	short @27@282
	?debug	L 1280
	mov	     bx,101h
	?debug	L 1282
	call	far ptr @vesaset$qv
	?debug	L 1283
	jmp	@27@1822
@27@282:
	?debug	L 1285
	cmp	     [_compaq],0
	?debug	L 1286
	je	short @27@422
	?debug	L 1287
	mov	     [_scanline],1024
	?debug	L 1288
	mov	     ax,2eh
	?debug	L 1289
	jmp	@27@1794
@27@422:
	?debug	L 1292
	cmp	     [_genoa],0
	?debug	L 1293
	je	short @27@534
	?debug	L 1294
	mov	     ax,5ch
	?debug	L 1295
	jmp	@27@1794
@27@534:
	?debug	L 1298
	cmp	     [_ncr],0
	?debug	L 1299
	je	short @27@646
	?debug	L 1300
	mov	     ax,5fh
	?debug	L 1301
	jmp	@27@1794
@27@646:
	?debug	L 1304
	cmp	     [_oaktech],0
	?debug	L 1305
	je	short @27@758
	?debug	L 1306
	mov	     ax,53h
	?debug	L 1307
	jmp	short @27@1794
@27@758:
	?debug	L 1310
	cmp	     [_aheada],0
	?debug	L 1311
	jne	short @27@870
	?debug	L 1312
	cmp	     [_aheadb],0
	?debug	L 1313
	je	short @27@926
@27@870:
	?debug	L 1316
	mov	     ax,61h
	?debug	L 1317
	jmp	short @27@1794
@27@926:
	?debug	L 1320
	cmp	     [_everex],0
	?debug	L 1321
	je	short @27@1066
	?debug	L 1322
	mov	     ax,70h
	?debug	L 1323
	mov	     bl,30h
	?debug	L 1324
	jmp	short @27@1794
@27@1066:
	?debug	L 1327
	cmp	     [_ativga],0
	?debug	L 1328
	je	short @27@1178
	?debug	L 1329
	mov	     ax,62h
	?debug	L 1330
	jmp	short @27@1794
@27@1178:
	?debug	L 1333
	cmp	     [_trident],0
	?debug	L 1334
	je	short @27@1290
	?debug	L 1335
	mov	     ax,5dh
	?debug	L 1336
	jmp	short @27@1794
@27@1290:
	?debug	L 1339
	cmp	     [_video7],0
	?debug	L 1340
	je	short @27@1430
	?debug	L 1341
	mov	     ax,6f05h
	?debug	L 1342
	mov	     bl,67h
	?debug	L 1343
	jmp	short @27@1794
@27@1430:
	?debug	L 1346
	cmp	     [_chipstech],0
	?debug	L 1347
	je	short @27@1542
	?debug	L 1348
	mov	     ax,79h
	?debug	L 1349
	jmp	short @27@1794
@27@1542:
	?debug	L 1352
	cmp	     [_acumos],0
	?debug	L 1353
	jne	short @27@1654
	?debug	L 1354
	cmp	     [_paradise],0
	?debug	L 1355
	je	short @27@1710
@27@1654:
	?debug	L 1358
	mov	     ax,5fh
	?debug	L 1359
	jmp	short @27@1794
@27@1710:
	?debug	L 1362
	cmp	     [_tseng],0
	?debug	L 1363
	je	short @27@2046
	?debug	L 1364
	mov	     ax,2eh
@27@1794:
	?debug	L 1366
 	int	 10h
@27@1822:
	?debug	L 1369
	mov	     [_curbk],-1
	?debug	L 1370
	mov	     ax,40h
	?debug	L 1371
	mov	     es,ax
	?debug	L 1372
	mov	     al,es:[84h]          
	?debug	L 1373
	inc	     al
	?debug	L 1374
	mul	     byte ptr es:[85h]
	?debug	L 1375
	mov	     [_smaxy],ax
	?debug	L 1377
	push	cs
	call	near ptr @mkadrtbl$qv
@27@2046:
	?debug	L 1378
	jmp	short @27@2074
@27@2074:
	?debug	L 1379
	pop	bp
	ret	
	?debug	E
	?debug	E
@svgamode$qv	endp
	?debug	L 1380
	assume	cs:SVGALIB_TEXT
@vesaset$qv	proc	far
	?debug	B
	enter	286,0
	push	di
	?debug	B
	?debug	L 1383
	push	    bx
	?debug	L 1384
	mov	     ax,4f02h      
	?debug	L 1385
	int	     10h
	?debug	L 1386
	pop	     cx
	?debug	L 1387
	mov	     ax,ss
	?debug	L 1388
	mov	     es,ax
	?debug	L 1389
	lea	     di,[bp-286][0] 
	?debug	L 1390
	mov	     ax,4f01h
	?debug	L 1391
	int	     10h
	?debug	L 1393
	mov	ax,seg _bksize
	mov	dx,word ptr [bp-282]
	mov	es,ax
	mov	word ptr es:_bksize,dx
	?debug	L 1394
	mov	ax,seg _scanline
	mov	dx,word ptr [bp-270]
	mov	es,ax
	mov	word ptr es:_scanline,dx
	?debug	L 1395
	mov	ax,seg _vesafunc
	mov	edx,dword ptr [bp-274]
	mov	es,ax
	mov	dword ptr es:_vesafunc,edx
	?debug	L 1396
	pop	di
	leave	
	ret	
	?debug	C E6076D6F64656275661802E2FE00
	?debug	E
	?debug	E
@vesaset$qv	endp
	?debug	L 1398
	assume	cs:SVGALIB_TEXT
@setmany$qnucii	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	C E31A000400160800
	?debug	C E6066E756D636F6C040A0C000006626567636F6C+
	?debug	C 040A0A00000670616C6275661A0A060000
	?debug	B
	?debug	L 1399
 	push	 es
	?debug	L 1400
	?debug	L 1401
	les	dx,dword ptr [bp+6]
	?debug	L 1403
	mov	     bx,[[bp+10]]
	?debug	L 1404
	mov	     cx,[[bp+12]]
	?debug	L 1405
	mov	     ax,1012h
	?debug	L 1406
	int	     10h
	?debug	L 1408
 	pop	 es
	?debug	L 1409
	pop	bp
	ret	
	?debug	C E60670616C6275661A0A06000006626567636F6C+
	?debug	C 040A0A0000066E756D636F6C040A0C0000
	?debug	E
	?debug	E
@setmany$qnucii	endp
	?debug	L 1410
	assume	cs:SVGALIB_TEXT
@getmany$qnucii	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	C E6066E756D636F6C040A0C000006626567636F6C+
	?debug	C 040A0A00000670616C6275661A0A060000
	?debug	B
	?debug	L 1411
 	push	 es
	?debug	L 1412
	?debug	L 1413
	les	dx,dword ptr [bp+6]
	?debug	L 1415
	mov	     bx,[[bp+10]]
	?debug	L 1416
	mov	     cx,[[bp+12]]
	?debug	L 1417
	mov	     ax,1017h
	?debug	L 1418
	int	     10h
	?debug	L 1420
 	pop	 es
	?debug	L 1421
	pop	bp
	ret	
	?debug	C E60670616C6275661A0A06000006626567636F6C+
	?debug	C 040A0A0000066E756D636F6C040A0C0000
	?debug	E
	?debug	E
@getmany$qnucii	endp
	?debug	L 1423
	assume	cs:SVGALIB_TEXT
@point$qii	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	C E60479706F73040A0800000478706F73040A0600+
	?debug	C 00
	?debug	B
	?debug	L 1425
	mov	     dx,[[bp+6]]
	?debug	L 1426
	mov	     bx,[[bp+8]]
	?debug	L 1427
	shl	     bx,1
	?debug	L 1428
	shl	     bx,1
	?debug	L 1429
	add	     dx,word ptr _adrtbl[bx]
	?debug	L 1430
	mov	     ax,word ptr _adrtbl[bx+2]
	?debug	L 1431
	adc	     ax,0
	?debug	L 1432
	mov	     bx,dx
	?debug	L 1433
	cmp	     ax,[_curbk]
	?debug	L 1434
	je	short @31@338
	?debug	L 1435
	call	    _bankadr                 
@31@338:
	?debug	L 1438
	mov	     es,[_ourseg]             
	?debug	L 1439
	mov	     al,byte ptr [_dotcolor]  
	?debug	L 1440
	mov	     es:[bx],al
	?debug	L 1443
	pop	bp
	ret	
	?debug	C E60478706F73040A0600000479706F73040A0800+
	?debug	C 00
	?debug	E
	?debug	E
@point$qii	endp
	?debug	L 1444
	assume	cs:SVGALIB_TEXT
@rdpoint$qii	proc	far
	?debug	B
	enter	2,0
	?debug	C E60479706F73040A0800000478706F73040A0600+
	?debug	C 00
	?debug	B
	?debug	L 1447
	mov	     dx,[[bp+6]]
	?debug	L 1448
	mov	     bx,[[bp+8]]
	?debug	L 1449
	shl	     bx,1
	?debug	L 1450
	shl	     bx,1
	?debug	L 1451
	add	     dx,word ptr _adrtbl[bx]
	?debug	L 1452
	mov	     ax,word ptr _adrtbl[bx+2]
	?debug	L 1453
	adc	     ax,0
	?debug	L 1454
	mov	     bx,dx
	?debug	L 1455
	cmp	     ax,[_curbk]
	?debug	L 1456
	je	short @32@338
	?debug	L 1457
	call	    _bankadr           
@32@338:
	?debug	L 1460
	mov	     es,[_ourseg]       
	?debug	L 1461
	mov	     al,es:[bx]
	?debug	L 1462
	mov	     ah,0
	?debug	L 1463
	mov	     [bp-2],ax
	?debug	L 1465
	mov	ax,word ptr [bp-2]
	jmp	short @32@478
@32@478:
	?debug	L 1466
	leave	
	ret	
	?debug	C E6037274760402FEFF000478706F73040A060000+
	?debug	C 0479706F73040A080000
	?debug	E
	?debug	E
@rdpoint$qii	endp
	?debug	L 1467
	assume	cs:SVGALIB_TEXT
@waitretrace$qv	proc	far
	?debug	B
	push	bp
	mov	bp,sp
	?debug	B
	?debug	L 1470
	mov	 dx,03DAH
	?debug	L 1471
	mov	 ah,8
@33@86:
	?debug	L 1475
	in	   al,dx
	?debug	L 1476
	test	 al,ah   
	?debug	L 1477
	jne	short @33@86
@33@170:
	?debug	L 1481
	in	   al,dx
	?debug	L 1482
	test	 al,ah
	?debug	L 1483
	je	short @33@170
	?debug	L 1485
	pop	bp
	ret	
	?debug	E
	?debug	E
@waitretrace$qv	endp
	?debug	C E9
	?debug	C FA00000000
SVGALIB_TEXT	ends
_DATA	segment word public use16 'DATA'
s@	label	byte
_DATA	ends
SVGALIB_TEXT	segment byte public use16 'CODE'
SVGALIB_TEXT	ends
	public	@_nobank$qv
	public	@_vesa$qv
	public	@_compaq$qv
	public	@_ncr$qv
	public	@_genoa$qv
	public	@_oaktech$qv
	public	@_aheadb$qv
	public	@_aheada$qv
	public	@_everex$qv
	public	@_ativga$qv
	public	@_chipstech$qv
	public	@_acumos$qv
	public	@_paradise$qv
	public	@_video7$qv
	public	@_trident$qv
	public	@_tseng4$qv
	public	@_tseng$qv
	public	@waitretrace$qv
	public	@rdpoint$qii
	public	@point$qii
	public	@getmany$qnucii
	public	@setmany$qnucii
	public	@vesaset$qv
	public	@svgamode$qv
	public	@mkadrtbl$qv
	public	@_isport1$qv
	public	@_isport2$qv
	public	@_gochk$qv
	public	@_chkbk$qv
	public	@_cirrus$qv
	public	@_t3memchk$qv
	public	@whichvga$qv
	public	@dummyvesa$qv
	extrn	_adrtbl:word
	extrn	_ourseg:word
	extrn	_scanline:word
	extrn	_smaxy:word
	extrn	_smaxx:word
	extrn	_buftbl:word
	extrn	_vesamodes:word
	extrn	_vesafunc:word
	extrn	_bankadr:word
	extrn	_retval:word
	extrn	_first:word
	extrn	_dactype:word
	extrn	_vesa:word
	extrn	_compaq:word
	extrn	_ncr:word
	extrn	_genoa:word
	extrn	_tseng4:word
	extrn	_chipstech:word
	extrn	_video7:word
	extrn	_oaktech:word
	extrn	_aheadb:word
	extrn	_aheada:word
	extrn	_ativga:word
	extrn	_t8900:word
	extrn	_trident:word
	extrn	_tseng:word
	extrn	_paradise:word
	extrn	_acumos:word
	extrn	_everex:word
	extrn	_cirrus:word
	extrn	_dotcolor:byte
	extrn	_bksize:word
	extrn	_vgamem:word
	extrn	_curbk:word
_s@	equ	s@
	?debug	C EA050C
	?debug	C E31B00000023010400
	?debug	C EC0B405F6E6F62616E6B2471761B1800
	?debug	C E31C00000023010400
	?debug	C EC09405F766573612471761C1800
	?debug	C E31D00000023010400
	?debug	C EC0B405F636F6D7061712471761D1800
	?debug	C E31E00000023010400
	?debug	C EC08405F6E63722471761E1800
	?debug	C E31F00000023010400
	?debug	C EC0A405F67656E6F612471761F1800
	?debug	C E32000000023010400
	?debug	C EC0C405F6F616B74656368247176201800
	?debug	C E32100000023010400
	?debug	C EC0B405F616865616462247176211800
	?debug	C E32200000023010400
	?debug	C EC0B405F616865616461247176221800
	?debug	C E32300000023010400
	?debug	C EC0B405F657665726578247176231800
	?debug	C E32400000023010400
	?debug	C EC0B405F617469766761247176241800
	?debug	C E32500000023010400
	?debug	C EC0E405F636869707374656368247176251800
	?debug	C E32600000023010400
	?debug	C EC0B405F6163756D6F73247176261800
	?debug	C E32700000023010400
	?debug	C EC0D405F7061726164697365247176271800
	?debug	C E32800000023010400
	?debug	C EC0B405F766964656F37247176281800
	?debug	C E32900000023010400
	?debug	C EC0C405F74726964656E74247176291800
	?debug	C E32A00000023010400
	?debug	C EC0B405F7473656E67342471762A1800
	?debug	C E32B00000023010400
	?debug	C EC0A405F7473656E672471762B1800
	?debug	C E32C00000023010400
	?debug	C EC0F4077616974726574726163652471762C1800
	?debug	C E32D00000023040400
	?debug	C EC0C407264706F696E74247169692D1800
	?debug	C E32E00000023010400
	?debug	C EC0A40706F696E74247169692E1800
	?debug	C E32F00000023010400
	?debug	C EC0F406765746D616E7924716E756369692F1800
	?debug	C E33000000023010400
	?debug	C EC0F407365746D616E7924716E75636969301800
	?debug	C E33100000023010400
	?debug	C EC0B4076657361736574247176311800
	?debug	C E33200000023010400
	?debug	C EC0C40737667616D6F6465247176321800
	?debug	C E33300000023010400
	?debug	C EC0C406D6B61647274626C247176331800
	?debug	C E33400000023040400
	?debug	C EC0C405F6973706F727431247176341800
	?debug	C E33500000023040400
	?debug	C EC0C405F6973706F727432247176351800
	?debug	C E33600000023040400
	?debug	C EC0A405F676F63686B247176361800
	?debug	C E33700000023040400
	?debug	C EC0A405F63686B626B247176371800
	?debug	C E33800000023040400
	?debug	C EC0B405F636972727573247176381800
	?debug	C E33900000023040400
	?debug	C EC0D405F74336D656D63686B247176391800
	?debug	C E33A00000023040400
	?debug	C EC0C4077686963687667612471763A1800
	?debug	C E33B00000023010400
	?debug	C EC0D4064756D6D79766573612471763B1800
	?debug	C E33D0004001A04
	?debug	C E33C0000101A3D
	?debug	C EB075F61647274626C3C00
	?debug	C EB075F6F75727365670400
	?debug	C EB095F7363616E6C696E650400
	?debug	C EB065F736D6178790400
	?debug	C EB065F736D6178780400
	?debug	C E33E0000001A04
	?debug	C EB075F62756674626C3E00
	?debug	C E33F0000001A04
	?debug	C EB0A5F766573616D6F6465733F00
	?debug	C EB095F7665736166756E630600
	?debug	C EB085F62616E6B6164720600
	?debug	C EB075F72657476616C0400
	?debug	C EB065F66697273740400
	?debug	C EB085F646163747970650400
	?debug	C EB055F766573610400
	?debug	C EB075F636F6D7061710400
	?debug	C EB045F6E63720400
	?debug	C EB065F67656E6F610400
	?debug	C EB075F7473656E67340400
	?debug	C EB0A5F6368697073746563680400
	?debug	C EB075F766964656F370400
	?debug	C EB085F6F616B746563680400
	?debug	C EB075F6168656164620400
	?debug	C EB075F6168656164610400
	?debug	C EB075F6174697667610400
	?debug	C EB065F74383930300400
	?debug	C EB085F74726964656E740400
	?debug	C EB065F7473656E670400
	?debug	C EB095F70617261646973650400
	?debug	C EB075F6163756D6F730400
	?debug	C EB075F6576657265780400
	?debug	C EB075F6369727275730400
	?debug	C EB095F646F74636F6C6F720800
	?debug	C EB075F626B73697A650400
	?debug	C EB075F7667616D656D0400
	?debug	C EB065F637572626B0400
	?debug	C E34007766761696E666F16001E15
	?debug	C E3410008001A04
	?debug	C E3420004001A08
	?debug	C E60C766573616D6F6465696E666F180700077667+
	?debug	C 61696E666F400700
	?debug	C E2000E4D6F64654174747269627574657304000E+
	?debug	C 57696E414174747269627574657308000E57696E+
	?debug	C 424174747269627574657308000E57696E477261+
	?debug	C 6E756C617269747904000757696E53697A650400+
	?debug	C 0B57696E415365676D656E7404000B57696E4253+
	?debug	C 65676D656E7404000A57696E46756E6350747206+
	?debug	C 000C42797465735065724C696E6504000B585265+
	?debug	C 736F6C7574696F6E04000B595265736F6C757469+
	?debug	C 6F6E040009584368617253697A65080009594368+
	?debug	C 617253697A6508000E4E756D6265724F66506C61+
	?debug	C 6E657308000C42697473506572506978656C0800+
	?debug	C 0D4E756D6265724F6642616E6B7308000B4D656D+
	?debug	C 6F72794D6F64656C08000842616E6B53697A6508+
	?debug	C 00046275666619C01E010000
	?debug	C E2000D564553415369676E617475726541000B56+
	?debug	C 45534156657273696F6E08400A000000000C4F45+
	?debug	C 4D537472696E6750747206000C4361706162696C+
	?debug	C 697469657342000C566964656F4D6F6465507472+
	?debug	C 06C016000000
	end
