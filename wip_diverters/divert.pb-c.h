/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: divert.proto */

#ifndef PROTOBUF_C_divert_2eproto__INCLUDED
#define PROTOBUF_C_divert_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct DivertMessage DivertMessage;


/* --- enums --- */


/* --- messages --- */

/*
 * https://github.com/protobuf-c/protobuf-c/wiki/Examples
 */
struct  DivertMessage
{
  ProtobufCMessage base;
  protobuf_c_boolean has_src_port;
  int32_t src_port;
  protobuf_c_boolean has_dst_port;
  int32_t dst_port;
  char *src_host;
  char *dst_host;
};
#define DIVERT_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&divert_message__descriptor) \
    , 0, 0, 0, 0, NULL, NULL }


/* DivertMessage methods */
void   divert_message__init
                     (DivertMessage         *message);
size_t divert_message__get_packed_size
                     (const DivertMessage   *message);
size_t divert_message__pack
                     (const DivertMessage   *message,
                      uint8_t             *out);
size_t divert_message__pack_to_buffer
                     (const DivertMessage   *message,
                      ProtobufCBuffer     *buffer);
DivertMessage *
       divert_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   divert_message__free_unpacked
                     (DivertMessage *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*DivertMessage_Closure)
                 (const DivertMessage *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor divert_message__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_divert_2eproto__INCLUDED */
