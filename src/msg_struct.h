#ifndef __MSG_STRUCT_H_
#define __MSG_STRUCT_H_

#define PACK_4 __attribute((aligned(4)))
#define PACK_1 __attribute__ ((packed))

#define MAGIC 0x20171226
#define VERSION 1
struct ipc_hdr_t
{
    uint32_t magic;      
    uint32_t version;
    uint16_t msg_type;  
    uint32_t data_len;
	uint16_t hdr_len;//后续高版本添加字段都在hdr_len之后添加
    char data[0];
} PACK_4;

#define OFFSET(struct_type, member) ((size_t)&((struct_type *)0)->member)
//ptr为结构体struct_type成员member的指针，通过指针和member名字返回struct_type结构体指针
#define container_of(ptr, struct_type, member)	\
({	\
	const typeof(((struct_type *)0)->member)*__mptr = (ptr);	\
	(struct_type *)((char *)__mptr - OFFSET(struct_type, member)); \
})

#define IPC_HEADER_SZ (OFFSET(struct ipc_hdr_t, data))

#endif
