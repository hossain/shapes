//--------------------*( In the name of best Creator )*----------------------
//          Super VGA Kit ...
//
//                                                       H.Taheri
//
//---------------------------------------------------------------------------
//#include "SVGALIB.H"
//#pragma inline
#define OSEG
#include "SVGALIB.H"
//#define _nobank asm{cli;mov OSEG[curbk],ax;sti;ret}

//void newbank(int bank){        //             ;bank number is in AX
// asm call bankadr;
//if @Codesize
//      jmp     dword ptr OSEG[bankadr]
//else
//      jmp     OSEG[bankadr]
//endif
//BANKS:
void _tseng(){//                        ;Tseng 3000 series
asm{
        push    bx
        cli
//      mov     ax,axrr
        mov     curbk,ax
        and     al,7
        mov     ah,al
        shl     al,1
        shl     al,1
        shl     al,1
        or      al,ah
        or      al,01000000b
        mov     dx,3cdh
        out     dx,al
        sti
        pop     bx
        }
        return;
        }

void _tseng4(){                 //;Tseng 4000 series
asm{
        push    bx
        cli
  //    mov     ax,axrr
        mov     OSEG[curbk],ax
        mov     ah,al
        mov     dx,3bfh         //;Enable access to extended registers
        mov     al,3
        out     dx,al
        mov     dl,0d8h
        mov     al,0a0h
        out     dx,al
        and     ah,15
        mov     al,ah
        shl     al,1
        shl     al,1
        shl     al,1
        shl     al,1
        or      al,ah
        mov     dl,0cdh
        out     dx,al
        sti
        pop     bx
        }
        return;
     }
void _trident(){                        //;Trident
asm{
    //  mov     ax,axrr
        push    bx
        push    ax
        cli
        mov     OSEG[curbk],ax
        mov     dx,3ceh         //;set pagesize to 64k
        mov     al,6
        out     dx,al
        inc     dl
        in      al,dx
        dec     dl
        or      al,4
        mov     ah,al
        mov     al,6
        out     dx,ax

        mov     dl,0c4h         //;switch to BPS mode
        mov     al,0bh
        out     dx,al
        inc     dl
        in      al,dx
        dec     dl

        pop     ax
        mov     ah,al
        xor     ah,2
        mov     dx,3c4h
        mov     al,0eh
        out     dx,ax
        sti
        pop     bx
        }
        return;
}
void _video7(){                 //;Video 7
asm{
        push    bx
        cli
//      mov     ax,axrr
        mov     OSEG[curbk],ax
        and     ax,15
        mov     ch,al
        mov     dx,3c4h
        mov     ax,0ea06h
        out     dx,ax
        mov     ah,ch
        and     ah,1
        mov     al,0f9h
        out     dx,ax
        mov     al,ch
        and     al,1100b
        mov     ah,al
        shr     ah,1
        shr     ah,1
        or      ah,al
        mov     al,0f6h
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        and     al,not 1111b
        or      ah,al
        mov     al,0f6h
        out     dx,ax
        mov     ah,ch
        mov     cl,4
        shl     ah,cl
        and     ah,100000b
        mov     dl,0cch
        in      al,dx
        mov     dl,0c2h
        and     al,not 100000b
        or      al,ah
        out     dx,al
        sti
        pop     bx
        }
        return;
        }

void _paradise(){    //                 ;Paradise
asm{
//      mov     ax,axrr
        push    bx
        push    ax
        cli
        mov     OSEG[curbk],ax
        mov     dx,3ceh
        mov     ax,50fh         //;turn off write protect on VGA registers
        out     dx,ax
        pop     ax
        mov     ah,al
        mov     al,9
        out     dx,ax
        sti
        pop     bx
        }
        return;
}

void _acumos(){ //                      ;AcuMos
asm{
//      mov     ax,axrr
        push    bx
        push    ax
        cli
        mov     OSEG[curbk],ax
        mov     dx,3c4h         //;Sequencer index 6
        mov     ax,1206h        //;turn off write protect on VGA registers
        out     dx,ax
        mov     dx,3ceh
        pop     ax
        mov     ah,al
        mov     al,9
        out     dx,ax
        sti
        pop     bx
        }
        return;
}

void _chipstech(){//                    ;Chips & Tech
asm{
//      mov     ax,axrr
        push    bx
        push    ax
        cli
        mov     OSEG[curbk],ax
        mov     dx,46e8h        //;place chip in setup mode
        mov     ax,1eh
        out     dx,ax
        mov     dx,103h         //;enable extended registers
        mov     ax,0080h
        out     dx,ax
        mov     dx,46e8h        //;bring chip out of setup mode
        mov     ax,0eh
        out     dx,ax
        pop     ax
        mov     ah,al
        mov     al,10h
        mov     dx,3d6h
        out     dx,ax
        sti
        pop     bx
        }
        return;
        }


void _ativga(){       //                        ;ATI VGA Wonder
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     ah,al
        mov     dx,1ceh
        mov     al,0b2h
        out     dx,al
        inc     dl
        in      al,dx
        shl     ah,1
        and     al,0e1h
        or      ah,al
        mov     al,0b2h
        dec     dl
        out     dx,ax
        sti
        pop     bx
        }
        return;
        }

void _everex(){//                       ;Everex
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     cl,al
        mov     dx,3c4h
        mov     al,8
        out     dx,al
        inc     dl
        in      al,dx
        dec     dl
        shl     al,1
        shr     cl,1
        rcr     al,1
        mov     ah,al
        mov     al,8
        out     dx,ax
        mov     dl,0cch
        in      al,dx
        mov     dl,0c2h
        and     al,0dfh
        shr     cl,1
        jc      nob2
        or      al,20h
        }
nob2:
asm{    out     dx,al
        sti
        pop     bx
        }
        return;
        }
void _aheada(){//                       ;Ahead Systems Ver A
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     ch,al
        mov     dx,3ceh         //;Enable extended registers
        mov     ax,200fh
        out     dx,ax
        mov     dl,0cch         //      ;bit 0
        in      al,dx
        mov     dl,0c2h
        and     al,11011111b
        shr     ch,1
        jnc     skpa
        or      al,00100000b
        }
skpa:   asm{
        out     dx,al
        mov     dl,0cfh         //;bits 1,2,3
        mov     al,0
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        and     al,11111000b
        or      al,ch
        mov     ah,al
        mov     al,0
        out     dx,ax
        sti
        pop     bx
        }
        return;

     }
void _aheadb(){//                       ;Ahead Systems Ver A
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     ch,al
        mov     dx,3ceh         //;Enable extended registers
        mov     ax,200fh
        out     dx,ax
        mov     ah,ch
        mov     cl,4
        shl     ah,cl
        or      ah,ch
        mov     al,0dh
        out     dx,ax
        sti
        pop     bx
        }
        return;

      }
void _oaktech(){//                      ;Oak Technology Inc OTI-067 and OTI-077
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        and     al,15
        mov     ah,al
        shl     al,1
        shl     al,1
        shl     al,1
        shl     al,1
        or      ah,al
        mov     al,11h
        mov     dx,3deh
        out     dx,ax
        sti
        pop     bx
        }
        return;
     }
void _genoa(){//                        ;GENOA GVGA
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     ah,al
        shl     al,1
        shl     al,1
        shl     al,1
        or      ah,al
        mov     al,6
        or      ah,40h
        mov     dx,3c4h
        out     dx,ax
        sti
        pop     bx
        }
        return;
     }
void _ncr(){//                          ;NCR 77C22E
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     ah,al
        mov     al,18h
        mov     dx,3c4h
        out     dx,ax
        mov     ax,19h
        out     dx,ax
        sti
        }
        return;
     }
void _compaq(){//                       ;Compaq
asm{
//      mov     ax,axrr
        push    bx
        push    ax
        cli
        mov     OSEG[curbk],ax
        mov     dx,3ceh
        mov     ax,50fh         //;unlock extended registers
        out     dx,ax
        pop     ax
        mov     ah,al
        mov     al,45h
        out     dx,ax
        sti
        pop     bx
        }
        return;
     }
void _vesa(){//                         ;Vesa SVGA interface
asm{
//      mov     ax,axrr
        push    bx
        cli
        mov     OSEG[curbk],ax
        mov     dx,ax
        xor     bx,bx
        call    dword ptr OSEG[vesafunc]
        mov     dx,OSEG[curbk]
        mov     bx,1
        call    dword ptr OSEG[vesafunc]
        sti
        pop     bx
        }
        return;
//      _nobank
}
void _nobank(){
asm{
//      mov     ax,axrr
        cli
        mov     OSEG[curbk],ax
        sti
        }
}

int whichvga(){
        struct vesamodeinfo vesabuf;  //        ; extra large to make up for
asm{                                  //        ; bugs in some VESA VBE's
        cmp     [first],'FI'          //        ; 0x4649
        jnz     gotest
        mov     ax,[retval]
        }
        return retval;
gotest:
        bankadr=(long)&_nobank;
asm{
        mov     [vgamem],256
        mov     [bksize],64
        xor     ax,ax
        mov     [curbk],ax
        mov     [cirrus],ax
        mov     [everex],ax
        mov     [paradise],ax
        mov     [tseng],ax
        mov     [trident],ax
        mov     [t8900],ax
        mov     [ativga],ax
        mov     [aheada],ax
        mov     [aheadb],ax
        mov     [oaktech],ax
        mov     [video7],ax
        mov     [chipstech],ax
        mov     [tseng4],ax
        mov     [genoa],ax
        mov     [ncr],ax
        mov     [compaq],ax
        mov     [vesa],ax
        mov     [dactype],ax
        mov     [first],'FI'

        mov     si,1                  //        ;flag for SVGA found
        mov     ax,ss
        mov     es,ax
        lea     di,vesabuf[0]
        mov     ax,4f00h
        int     10h
        cmp     ax,4fh
        jnz     novesa
        mov     [bksize],64            //       ; (for now)
        mov     si,offset vesamodes
        cld
        }
        vesafunc=long(&dummyvesa);
        bankadr=long(&_vesa);
        vesa=1;
vesalp:
asm{
        lodsw
        mov     cx,ax
        jcxz    endvesa
        mov     ax,ss
        mov     es,ax
        lea     di,vesabuf[0]
        mov     ax,4f01h               //       ;is mode available?
        int     10h
        or      ah,ah
        jnz     notmode
        test    byte ptr es:[di],1
        jz      notmode                //       ;if mode not available skip mem size
        lodsw
        mov     cx,ax
        lodsw
        mov     bx,ax
        lodsw
        mul     cx                     //       ;multiple by bits per pixel
        shr     dx,1                   //       ;shift right 3 times to get # of bytes
        rcr     ax,1
        shr     dx,1
        rcr     ax,1
        shr     dx,1
        rcr     ax,1
        mul     bx                     //       ;multiply by number of scanlines
        mov     bx,1024
        add     ax,bx                  //       ;round up to nearest kilobyte
        dec     ax
        adc     dx,0
        div     bx
        cmp     ax,[vgamem]            //       ;if mode requires more memory
        jbe     vesalp
        mov     [vgamem],ax            //       ;increase amount of vga memory
        }
        bksize = vesabuf.WinSize ;
        goto    vesalp ;
notmode:
        _SI+=6;
        goto vesalp;
endvesa:
asm{
        mov     ax,[vgamem]
        inc     ah
        dec     ax
        mov     al,0                   //       ;round up to nearest 256k
        cmp     ax,1024
        jb      nomegs
        add     ax,1023                //       ;round up to nearest megabyte
        and     ax,not 1023
        }
nomegs:
asm{
        mov     [vgamem],ax

        jmp     fini                   //       ;uncomment to disable other tests if VESA VBE found
        }

novesa:
asm{
        mov     ax,0c000h              //       ;ATI VGA detect (largely from ATI example code)
        mov     es,ax
        cmp     word ptr es:[40h],'13' //       ;ATI Signiture on the Video BIOS
        jnz     noati
        }
        bankadr=(long)&_ativga;
        ativga=1;
asm{    mov     [bksize],64            //       ; 64k bank size
        mov     dx,es:[10h]            //       ; Get value of ATI extended register
        mov     bl,es:[43h]            //       ; Get value of ATI chip version
        cmp     bl,'3'                 //
        jae     v6up                   //       ; Use different method to determine
        mov     al,0bbh                //       ; memory size of chip version is 3 or higher
        cli
        out     dx,al
        inc     dx
        in      al,dx                  //       ; Get ramsize byte for chip versions 1 & 2
        sti
        test    al,20h
        jz      no512
        mov     [vgamem],512
        jmp     short no512
        }
v6up:
asm{
        mov     al,0b0h                //       ; Method used for newer ATI chip versions
        cli
        out     dx,al
        inc     dx
        in      al,dx                  //       ; Get ramsize byte for versions 3-5
        sti
        test    al,10h                 //       ; Check if ramsize byte indicates 256K or 512K bytes
        jz      v7up
        mov     [vgamem],512
        }
v7up:
asm{
        cmp     bl,'4'                 //       ; Check for ramsize for ATI chip versions 4 & 5
        jb      no512
        test    al,8                   //       ; Check if version 5 ATI chip has 1024K
        jz      no512
        mov     [vgamem],1024
        }
no512:  asm     jmp     fini;

noati:
asm{
        mov     ax,7000h               //       ;Test for Everex
        xor     bx,bx
        cld
        int     10h
        cmp     al,70h
        jnz     noev
        }
        bankadr=(long)&_everex;
        everex=1;
asm{    mov     [bksize],64            //       ; 64k bank size
        and     ch,11000000b           //       ;how much memory on board
        jz      skp
        mov     [vgamem],512
        }
skp:                                   //       ;fall through for Everex boards using Trident or Tseng4000

noev:   asm{
        mov     ax,0bf03h              //       ;Test for Compaq
        xor     bx,bx
        mov     cx,bx
        int     10h
        cmp     ax,0bf03h
        jnz     nocp
        test    cl,40h                 //       ;is 640x480x256 available?
        jz      nocp
        }
        bankadr=(long)&_compaq;
        compaq=1;
asm{    mov     [bksize],4             //       ; 4k bank size
        mov     [vgamem],512
        jmp     fini
        }
nocp:   asm{
        mov     dx,3c4h                //       ;Test for NCR 77C22E
        mov     ax,0ff05h
        }_isport2();asm{
        jnz     noncr
        mov     ax,5                   //       ;Disable extended registers
        out     dx,ax
        mov     ax,0ff10h              //       ;Try to write to extended register 10
        }_isport2();asm{               //       ;If it writes then not NCR
        jz      noncr
        mov     ax,105h                //       ;Enable extended registers
        out     dx,ax
        mov     ax,0ff10h
        }_isport2();asm{
        jnz     noncr                  //       ;If it does NOT write then not NCR
        }bankadr=(long)&ncr;
        ncr=1;
        asm{
        mov     [bksize],16            //       ; 16k bank size
        mov     [vgamem],512
        jmp     fini
        }
noncr:  asm{
        mov     dx,3c4h                //       ;Test for Trident
        mov     al,0bh
        out     dx,al
        inc     dl
        in      al,dx
        and     al,0fh
        cmp     al,06h
        ja      notri
        cmp     al,2
        jb      notri
        }
        bankadr=(long)&_trident;
        trident=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        cmp     al,3
        jb      no89
        mov     [t8900],1
        mov     dx,3d4h
        mov     al,1fh
        out     dx,al
        inc     dx
        in      al,dx
        and     ax,3
        inc     al
        xchg    al,ah
        mov     [vgamem],ax
        jmp     fini
        }
no89:   asm{
        mov     [vgamem],512
        jmp     fini
        }
notri:  asm{
        mov     ax,6f00h               //       ;Test for Video 7
        xor     bx,bx
        cld
        int     10h
        cmp     bx,'V7'
        jnz     nov7
        }bankadr=(long)&_video7;
        video7;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        mov     ax,6f07h
        cld
        int     10h
        and     ah,7fh
        cmp     ah,1
        jbe     skp2
        mov     [vgamem],512
        }
skp2:   asm{
        cmp     ah,3
        jbe     skp3
        mov     [vgamem],1024
        }
skp3:   asm     jmp     fini;

nov7:   asm{
        mov     dx,3d4h                //       ;Test for GENOA GVGA
        mov     al,2eh                 //       ;check for Herchi Register top 6 bits
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        test    al,11111100b           //       ;top 6 bits should be zero
        jnz     nogn
        mov     ax,032eh               //       ;check for Herchi Register
        }
        if(!_isport2())goto nogn;
        asm{
        mov     dx,3c4h
        mov     al,7
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        test    al,10001000b
        jnz     nogn
        mov     al,10h
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        and     al,00110000b
        cmp     al,00100000b
        jnz     nogn
        mov     dx,3ceh
        mov     ax,0ff0bh
        }
        if(!_isport2())goto nogn;
        _DX=0x3c4,_AX=0x3f06;
        if(!_isport2())goto nogn;
        asm{mov dx,3ceh;mov ax,0ff0ah}
        if(!_isport2())goto nogn;
        bankadr=(long)&_genoa;
        genoa=1;
        bksize=64,vgamem=512;
        goto fini;
nogn:   _cirrus();
        if(!cirrus)goto nopd;
        goto fini;
noci:   asm{
        mov     dx,3ceh                //       ;Test for Paradise
        mov     al,9                   //       ;check Bank switch register
        out     dx,al
        inc     dx
        in      al,dx
        dec     dx
        or      al,al
        jnz     nopd

        mov     ax,50fh                //       ;turn off write protect on VGA registers
        out     dx,ax
        }
        _DX=(long)&_paradise;
        _CX=1;
        if(_chkbk())goto nopd;         //       ;if bank 0 and 1 same not paradise
        bankadr=(long)&_paradise;
        paradise=1;
        asm{
        mov     [bksize],4             //       ; 4k bank size
        mov     dx,3ceh
        mov     al,0bh                 //       ;512k detect from Bob Berry
        out     dx,al
        inc     dx
        in      al,dx
        test    al,80h                 //       ;if top bit set then 512k
        jz      nop512
        test    al,40h
        jz      nop1024
        mov     [vgamem],1024
        jmp     fini
        }
nop1024:
        asm mov [vgamem],512 ;
nop512: asm jmp fini ;

nopd:   asm{
        mov     ax,5f00h               //       ;Test for Chips & Tech
        xor     bx,bx
        cld
        int     10h
        cmp     al,5fh
        jnz     noct
        }
        bankadr=(long)&_chipstech;
        chipstech=1;
        asm{
        mov     [bksize],16            //       ; 16k bank size
        cmp     bh,1
        jb      skp4
        mov     [vgamem],512
        }
skp4:   asm jmp fini;

noct:   asm{
        mov     dx,3dah                //       ;Test for Tseng 4000 & 3000
        in      al,dx                  //       ;bit 8 is opposite of bit 4
        mov     ah,al                  //       ;(vertical retrace bit)
        shr     ah,1
        shr     ah,1
        shr     ah,1
        shr     ah,1
        xor     al,ah
        test    al,00001000b
        jz      nots
        mov     dx,3d4h                //       ;check for Tseng 4000 series
        mov     ax,0f33h
        }
        if(!_isport2())goto not4;
        _AX=0xff33;                    //       ;top 4 bits should not be there
        if(_isport2())goto nots;
        asm{
        mov     dx,3bfh                //       ;Enable access to extended registers
        mov     al,3
        out     dx,al
        mov     dx,3d8h
        mov     al,0a0h
        out     dx,al
        mov     al,0ffh
        mov     dx,3cdh                //       ;test bank switch register
        }if(_isport1())goto not4;
        bankadr=(long)&_tseng;
        tseng=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        mov     ax,10f1h               //       ;Extended BIOS call to get DAC type on Tseng4000
        int     10h
        cmp     ax,10h
        jnz     nodac
        mov     bh,0
        mov     [dactype],bx
        }
nodac:
asm{    mov     dx,3d4h                //       ;Tseng 4000 memory detect 1meg
        mov     al,37h
        out     dx,al
        inc     dx
        in      al,dx
        test    al,1000b               //       ;if using 64kx4 RAMs then no more than 256k
        jz      nomem
        and     al,3
        cmp     al,1                   //       ;if 8 bit wide bus then only two 256kx4 RAMs
        jbe     nomem
        mov     [vgamem],512
        cmp     al,2                   //       ;if 16 bit wide bus then four 256kx4 RAMs
        je      nomem
        mov     [vgamem],1024          //       ;full meg with eight 256kx4 RAMs
        }
nomem:
        bankadr=(long)&tseng4;
        tseng4=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        jmp     fini
        }
not4:   asm{
        mov     dx,3d4h                //       ;Test for Tseng 3000
        mov     ax,1f25h               //       ;is the Overflow High register there?
        }
        if(!_isport2())goto nots;
        asm{
        mov     al,03fh                //       ;bottom six bits only
        mov     dx,3cdh                //       ;test bank switch register
        }
        if(!_isport1())goto nots;
        bankadr=(long)&_tseng;
        tseng=1;
        bksize=64;
        _t3memchk();
        goto fini;
nots:   asm{
        mov     dx,3ceh                //       ;Test for Ahead A or B chipsets
        mov     ax,0ff0fh              //       ;register should not be fully available
        }
        if(_isport2())goto noab;
        asm{
        mov     ax,200fh
        out     dx,ax
        inc     dx
//      nojmp
        in      al,dx
        cmp     al,21h
        jz      verb
        cmp     al,20h
        jnz     noab
        }
        bankadr=(long)&_aheada;
        aheada=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        mov     [vgamem],512
        jmp     fini
        }
verb:
        bankadr  =      (long)&_aheadb;
        aheadb=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        mov     [vgamem],512
        jmp     fini
        }
noab:   asm{
        mov     dx,3c4h                //       ;Test for AcuMos chipsets
        mov     ax,0006h               //       ;disable extended registers
        out     dx,ax
        mov     ax,0ff09h
        }
        if(_isport2())goto noacu;       //      ;is scratchpad at index 9 writeable ?
        asm mov ax,0ff0ah;
        if(_isport2())goto noacu;      //       ;is scratchpad at index 10 writable ?
        asm{
        mov     ax,1206h
        out     dx,ax
        mov     ax,0ff09h
        }
        if(!_isport2())goto noacu;
        asm mov ax,0ff0ah;
        if(!_isport2())goto noacu;
        _DX=FP_OFF(&_acumos),_CX=1;
        if(_chkbk())goto noacu;         //      ;if bank 0 and 1 same not acumos

        bankadr=(long)&_acumos;
        acumos=1;
        asm{
        mov     [bksize],4             //       ; 4k bank size
        mov     dx,3c4h
        mov     al,0ah
        out     dx,al
        inc     dx
        in      al,dx                  //       ;get scratchpad index 10
        and     al,3
        cmp     al,1
        jb      noamem
        mov     [vgamem],512
        cmp     al,2
        jb      noamem
        mov     [vgamem],1024
        cmp     al,3
        jb      noamem
        mov     [vgamem],2048
        }
noamem: asm jmp short fini;

noacu:  asm{
        mov     dx,3deh                //       ;Test for Oak Technology Inc OTI-067 and OTI-077
        mov     ax,0ff11h              //       ;look for bank switch register
        }if(!_isport2)goto nooak;
        bankadr=(long)&_oaktech;
        oaktech=1;
        asm{
        mov     [bksize],64            //       ; 64k bank size
        mov     al,0dh
        out     dx,al
        inc     dx
//      nojmp
        in      al,dx
        test    al,11000000b
        jz      no4ram
        mov     [vgamem],512
        test    al,01000000b
        jz      no4ram
        mov     [vgamem],1024
        }
no4ram: asm jmp short fini;

nooak:  asm mov si,0;

fini:
        asm{
        cmp     [vesa],0
        jz      novbank
        }
        bankadr=(long)&_vesa;                  //       ; Always use VESA bank switch
        vesa=1;
novbank:
        asm{
        mov     ax,si
        mov     retval,ax
        }
        return retval;
}
int _t3memchk(){//              ;[Charles Marslett -- ET3000 memory ck]
asm{    mov     dx,3dah
        in      al,dx        //         ;Reset the attribute flop (read 0x3DA)
        mov     dx,03c0h
        mov     al,36h
        out     dx,al
        inc     dx
        in      al,dx        //         ;Save contents of ATTR[0x16]
        push    ax
        or      al,10h
        dec     dx
        out     dx,al
        mov     dx,3ceh      //         ;Find the RAM buffer...
        mov     al,6
        out     dx,al
        inc     dx
        in      al,dx
        and     ax,000Ch
        shr     ax,1

        mov     bx,ax
        push    es
        }
        _AX=buftbl[_BX];
        asm{
        mov     es,ax
        mov     ax,09C65h
        mov     bx,1
        mov     es:[bx],ax
        mov     es:[bx+2],ax
        inc     bx
        mov     ax,es:[bx]
        pop     es
        cmp     ax,0659Ch
        jne     et3k_256
        mov     [vgamem],512
        }
et3k_256:
asm{    mov     dx,3c0h
        mov     al,36h
        out     dx,al
        pop     ax
        out     dx,al        //         ;Restore ATTR[16h]
        }
}
int _cirrus(){
asm{    mov     dx,3d4h      // ; assume 3dx addressing
        mov     al,0ch       // ; screen a start address hi
        out     dx,al        // ; select index
        inc     dx           // ; point to data
        mov     ah,al        // ; save index in ah
        in      al,dx        // ; get screen a start address hi
        xchg    ah,al        // ; swap index and data
        push    ax           // ; save old value
        push    dx           // ; save crtc address
        xor     al,al        // ; clear crc
        out     dx,al        // ; and out to the crtc

        mov     al,1fh       // ; Eagle ID register
        dec     dx           // ; back to index
        out     dx,al        // ; select index
        inc     dx           // ; point to data
        in      al,dx        // ; read the id register
        mov     bh,al        // ; and save it in bh

        mov     cl,4         // ; nibble swap rotate count
        mov     dx,3c4h      // ; sequencer/extensions
        mov     bl,6         // ; extensions enable register

        ror     bh,cl        // ; compute extensions disable value
        mov     ax,bx        // ; extensions disable
        out     dx,ax        // ; disable extensions
        inc     dx           // ; point to data
        in      al,dx        // ; read enable flag
        or      al,al        // ; disabled ?
        jnz     exitx        // ; nope, not an cirrus

        ror     bh,cl        // ; compute extensions enable value
        dec     dx           // ; point to index
        mov     ax,bx        // ; extensions enable
        out     dx,ax        // ; enable extensions
        inc     dx           // ; point to data
        in      al,dx        // ; read enable flag
        cmp     al,1         // ; enabled ?
        jne     exitx        // ; nope, not an cirrus
        mov     [cirrus],1
 }
        bankadr=(long)&_nobank;
exitx:
asm{    pop     dx           // ; restore crtc address
        dec     dx           // ; point to index
        pop     ax           // ; recover crc index and data
        out     dx,ax        // ; restore crc value
        }
}
int _chkbk(){//         ;bank switch check routine
asm{    mov     di,0b800h
        mov     es,di
        xor     di,di
        mov     bx,1234h
        }
        if(!_gochk())goto badchk;
        asm mov bx,4321h;
        if(!_gochk())goto badchk;
        return 0;
badchk:
        return 1;
}
/*
calldx  macro
if @Codesize
        push    cs
endif
        call    dx
        endm
  */
int _gochk(){
asm{
        push    si
        mov     si,bx

        mov     al,cl
        call    dx
        xchg    bl,es:[di]
        mov     al,ch
        call    dx
        xchg    bh,es:[di]

        xchg    si,bx

        mov     al,cl
        call    dx
        xor     bl,es:[di]
        mov     al,ch
        call    dx
        xor     bh,es:[di]

        xchg    si,bx

        mov     al,ch
        call    dx
        mov     es:[di],bh
        mov     al,cl
        call    dx
        mov     es:[di],bl

        mov     al,0
        call    dx
        or      si,si
        pop     si
        }
}
int _isport2(){     //  ;check for valid indexed i/o port, al is index, ah is bit mask
asm{
        push    bx
        mov     bx,ax
        out     dx,al
        mov     ah,al
        inc     dx
        in      al,dx
        dec     dx
        xchg    al,ah
        push    ax
        mov     ax,bx
        out     dx,ax
        out     dx,al
        mov     ah,al
        inc     dx
        in      al,dx
        dec     dx
        and     al,bh
        cmp     al,bh
        jnz     noport
        mov     al,ah
        mov     ah,0
        out     dx,ax
        out     dx,al
        mov     ah,al
        inc     dx
        in      al,dx
        dec     dx
        and     al,bh
        cmp     al,0
        }
noport:
asm{    pop     ax
        out     dx,ax
        pop     bx
        }
}
int _isport1(){      // ;check for valid i/o port, al is bit mask
asm{
        mov     ah,al
        in      al,dx
        push    ax
        mov     al,ah
        out     dx,al
        in      al,dx
        and     al,ah
        cmp     al,ah
        jnz     noport2
        mov     al,0
        out     dx,al
        in      al,dx
        and     al,ah
        cmp     al,0
        }
noport2:        asm{
        pop     ax
        out     dx,al
        }
}
void dummyvesa(){
}


// SVGAMODE:
void mkadrtbl(){
asm{
        mov     di,offset adrtbl
        mov     ax,ds
        mov     es,ax
        mov     bx,[smaxy]

        mov     ax,[bksize]
        cmp     ax,64
        jz      nobnk
        mov     cl,10
        shl     ax,cl
        dec     ax
        mov     si,ax
        mov     cl,9
        mov     ax,[bksize]
        }
shlp:   asm{
        inc     cl
        shr     ax,1
        jnz     shlp
        xor     ax,ax
        xor     dx,dx
        }
lp:     asm{
        push    ax
        shr     ax,cl
        add     dx,ax
        pop     ax
        and     ax,si
        stosw
        xchg    ax,dx
        stosw
        xchg    ax,dx
        add     ax,[scanline]
        dec     bx
        jnz     lp
        }
        return;

nobnk:  asm{
        xor     ax,ax
        xor     dx,dx
        mov     si,[scanline]
        mov     cx,bx
        }
nlp:    asm{
        stosw
        xchg    ax,dx
        stosw
        xchg    ax,dx
        add     ax,si
        adc     dx,0
        loop    nlp
        }
}

void svgamode (){//                     ;Set 640x480x256 on most SVGA cards
asm{
	mov     [ourseg],0a000h
        mov     ax,640
        mov     [smaxx],ax             //       ;default width to 640 for now
        mov     [scanline],ax

        cmp     [vesa],0
        jz      novs
        mov     bx,101h
        }
        vesaset();
        goto    godo2;
novs:   asm{
        cmp     [compaq],0
        jz      nocp
        mov     [scanline],1024
        mov     ax,2eh
        jmp     godo
        }
nocp:   asm{
        cmp     [genoa],0
        jz      nogn
        mov     ax,5ch
        jmp     godo
        }
nogn:   asm{
        cmp     [ncr],0
        jz      noncr
        mov     ax,5fh
        jmp     godo
        }
noncr:  asm{
        cmp     [oaktech],0
        jz      noak
        mov     ax,53h
        jmp     short godo
        }
noak:   asm{
        cmp     [aheada],0
        jnz     LL
        cmp     [aheadb],0
        jz      noab
        }
LL:     asm{
        mov     ax,61h
        jmp     short godo
        }
noab:   asm{
        cmp     [everex],0
        jz      noev
        mov     ax,70h
        mov     bl,30h
        jmp     short godo
        }
noev:   asm{
        cmp     [ativga],0
        jz      noati
        mov     ax,62h
        jmp     short godo
        }
noati:  asm{
        cmp     [trident],0
        jz      notr
        mov     ax,5dh
        jmp     short godo
        }
notr:   asm{
        cmp     [video7],0
        jz      nov7
        mov     ax,6f05h
        mov     bl,67h
        jmp     short godo
        }
nov7:   asm{
        cmp     [chipstech],0
        jz      noct
        mov     ax,79h
        jmp     short godo
        }
noct:   asm{
        cmp     [acumos],0
        jnz     dopd
        cmp     [paradise],0
        jz      nopd
        }
dopd:   asm{
        mov     ax,5fh
        jmp     short godo
        }
nopd:   asm{
        cmp     [tseng],0
        jz      nots
        mov     ax,2eh
        }
godo:   asm int 10h;

godo2:  asm{
        mov     [curbk],-1
        mov     ax,40h
        mov     es,ax
        mov     al,es:[84h]          // ;get height of screen
        inc     al
        mul     byte ptr es:[85h]
        mov     [smaxy],ax
        }
        mkadrtbl();
nots:   return;
}
void vesaset(){
        struct vesamodeinfo modebuf;
asm{
        push    bx
        mov     ax,4f02h      //        ; set the VESA videomode
        int     10h
        pop     cx
        mov     ax,ss
        mov     es,ax
        lea     di,modebuf[0] //        ; get the mode information
        mov     ax,4f01h
        int     10h
        }
        bksize=modebuf.WinGranularity; //; bank size from vesamode structure
        scanline=modebuf.BytesPerLine; //; scan line byte width from vesamode
        vesafunc=modebuf.WinFuncPtr;
}

void setmany(char *palbuf,int begcol,int numcol){
asm push es;
_ES=FP_SEG(palbuf);
_DX=FP_OFF(palbuf);
asm{
        mov     bx,[begcol]
        mov     cx,[numcol]
        mov     ax,1012h
        int     10h
        }
asm pop es;
}
void getmany(char *palbuf,int begcol,int numcol){
asm push es;
_ES=FP_SEG(palbuf);
_DX=FP_OFF(palbuf);
asm{
        mov     bx,[begcol]
        mov     cx,[numcol]
        mov     ax,1017h
        int     10h
        }
asm pop es;
}

void point(int xpos,int ypos){
asm{
        mov     dx,[xpos]
        mov     bx,[ypos]
        shl     bx,1
        shl     bx,1
        add     dx,word ptr adrtbl[bx]
        mov     ax,word ptr adrtbl[bx+2]
        adc     ax,0
        mov     bx,dx
        cmp     ax,[curbk]
        jz      nonew
        call    bankadr                 //;switch banks if a new bank entered
        }
nonew:  asm{
        mov     es,[ourseg]             //;setup screen segment
        mov     al,byte ptr [dotcolor]  //;get color of pixel to plot
        mov     es:[bx],al
        }
nope1:
}
int rdpoint(int xpos,int ypos){
int rtv;
asm{
        mov     dx,[xpos]
        mov     bx,[ypos]
        shl     bx,1
        shl     bx,1
        add     dx,word ptr adrtbl[bx]
        mov     ax,word ptr adrtbl[bx+2]
        adc     ax,0
        mov     bx,dx
        cmp     ax,[curbk]
        jz      nonew
        call    bankadr           //    ;switch banks if a new bank entered
        }
nonew:  asm{
        mov     es,[ourseg]       //    ;setup screen segment
        mov     al,es:[bx]
        mov     ah,0
        mov     rtv,ax
        }
        return rtv;
}
void waitretrace()
{
asm {
    mov dx,0x3DA
    mov ah,8
    }
l1:
asm {
    in   al,dx
    test al,ah   // TEST is 1 clock cycle, whereas AND is 2 on a 386.
    jnz   l1
    }
l2:
asm {
    in   al,dx
    test al,ah
    jz   l2
    }
}
