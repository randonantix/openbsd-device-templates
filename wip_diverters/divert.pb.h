// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: divert.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_divert_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_divert_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_divert_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_divert_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_divert_2eproto;
class DivertMessage;
struct DivertMessageDefaultTypeInternal;
extern DivertMessageDefaultTypeInternal _DivertMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::DivertMessage* Arena::CreateMaybeMessage<::DivertMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class DivertMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:DivertMessage) */ {
 public:
  inline DivertMessage() : DivertMessage(nullptr) {}
  ~DivertMessage() override;
  explicit PROTOBUF_CONSTEXPR DivertMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DivertMessage(const DivertMessage& from);
  DivertMessage(DivertMessage&& from) noexcept
    : DivertMessage() {
    *this = ::std::move(from);
  }

  inline DivertMessage& operator=(const DivertMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline DivertMessage& operator=(DivertMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DivertMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const DivertMessage* internal_default_instance() {
    return reinterpret_cast<const DivertMessage*>(
               &_DivertMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DivertMessage& a, DivertMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(DivertMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DivertMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  DivertMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<DivertMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DivertMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const DivertMessage& from) {
    DivertMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DivertMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "DivertMessage";
  }
  protected:
  explicit DivertMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSrcHostFieldNumber = 3,
    kDestHostFieldNumber = 4,
    kSrcPortFieldNumber = 1,
    kDestPortFieldNumber = 2,
  };
  // optional string src_host = 3;
  bool has_src_host() const;
  private:
  bool _internal_has_src_host() const;
  public:
  void clear_src_host();
  const std::string& src_host() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_src_host(ArgT0&& arg0, ArgT... args);
  std::string* mutable_src_host();
  PROTOBUF_NODISCARD std::string* release_src_host();
  void set_allocated_src_host(std::string* src_host);
  private:
  const std::string& _internal_src_host() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_src_host(const std::string& value);
  std::string* _internal_mutable_src_host();
  public:

  // optional string dest_host = 4;
  bool has_dest_host() const;
  private:
  bool _internal_has_dest_host() const;
  public:
  void clear_dest_host();
  const std::string& dest_host() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_dest_host(ArgT0&& arg0, ArgT... args);
  std::string* mutable_dest_host();
  PROTOBUF_NODISCARD std::string* release_dest_host();
  void set_allocated_dest_host(std::string* dest_host);
  private:
  const std::string& _internal_dest_host() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_dest_host(const std::string& value);
  std::string* _internal_mutable_dest_host();
  public:

  // optional int32 src_port = 1;
  bool has_src_port() const;
  private:
  bool _internal_has_src_port() const;
  public:
  void clear_src_port();
  int32_t src_port() const;
  void set_src_port(int32_t value);
  private:
  int32_t _internal_src_port() const;
  void _internal_set_src_port(int32_t value);
  public:

  // optional int32 dest_port = 2;
  bool has_dest_port() const;
  private:
  bool _internal_has_dest_port() const;
  public:
  void clear_dest_port();
  int32_t dest_port() const;
  void set_dest_port(int32_t value);
  private:
  int32_t _internal_dest_port() const;
  void _internal_set_dest_port(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:DivertMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr src_host_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr dest_host_;
    int32_t src_port_;
    int32_t dest_port_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_divert_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DivertMessage

// optional int32 src_port = 1;
inline bool DivertMessage::_internal_has_src_port() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool DivertMessage::has_src_port() const {
  return _internal_has_src_port();
}
inline void DivertMessage::clear_src_port() {
  _impl_.src_port_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline int32_t DivertMessage::_internal_src_port() const {
  return _impl_.src_port_;
}
inline int32_t DivertMessage::src_port() const {
  // @@protoc_insertion_point(field_get:DivertMessage.src_port)
  return _internal_src_port();
}
inline void DivertMessage::_internal_set_src_port(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.src_port_ = value;
}
inline void DivertMessage::set_src_port(int32_t value) {
  _internal_set_src_port(value);
  // @@protoc_insertion_point(field_set:DivertMessage.src_port)
}

// optional int32 dest_port = 2;
inline bool DivertMessage::_internal_has_dest_port() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool DivertMessage::has_dest_port() const {
  return _internal_has_dest_port();
}
inline void DivertMessage::clear_dest_port() {
  _impl_.dest_port_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline int32_t DivertMessage::_internal_dest_port() const {
  return _impl_.dest_port_;
}
inline int32_t DivertMessage::dest_port() const {
  // @@protoc_insertion_point(field_get:DivertMessage.dest_port)
  return _internal_dest_port();
}
inline void DivertMessage::_internal_set_dest_port(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.dest_port_ = value;
}
inline void DivertMessage::set_dest_port(int32_t value) {
  _internal_set_dest_port(value);
  // @@protoc_insertion_point(field_set:DivertMessage.dest_port)
}

// optional string src_host = 3;
inline bool DivertMessage::_internal_has_src_host() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool DivertMessage::has_src_host() const {
  return _internal_has_src_host();
}
inline void DivertMessage::clear_src_host() {
  _impl_.src_host_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& DivertMessage::src_host() const {
  // @@protoc_insertion_point(field_get:DivertMessage.src_host)
  return _internal_src_host();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DivertMessage::set_src_host(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.src_host_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:DivertMessage.src_host)
}
inline std::string* DivertMessage::mutable_src_host() {
  std::string* _s = _internal_mutable_src_host();
  // @@protoc_insertion_point(field_mutable:DivertMessage.src_host)
  return _s;
}
inline const std::string& DivertMessage::_internal_src_host() const {
  return _impl_.src_host_.Get();
}
inline void DivertMessage::_internal_set_src_host(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.src_host_.Set(value, GetArenaForAllocation());
}
inline std::string* DivertMessage::_internal_mutable_src_host() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.src_host_.Mutable(GetArenaForAllocation());
}
inline std::string* DivertMessage::release_src_host() {
  // @@protoc_insertion_point(field_release:DivertMessage.src_host)
  if (!_internal_has_src_host()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.src_host_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.src_host_.IsDefault()) {
    _impl_.src_host_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DivertMessage::set_allocated_src_host(std::string* src_host) {
  if (src_host != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.src_host_.SetAllocated(src_host, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.src_host_.IsDefault()) {
    _impl_.src_host_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:DivertMessage.src_host)
}

// optional string dest_host = 4;
inline bool DivertMessage::_internal_has_dest_host() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool DivertMessage::has_dest_host() const {
  return _internal_has_dest_host();
}
inline void DivertMessage::clear_dest_host() {
  _impl_.dest_host_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& DivertMessage::dest_host() const {
  // @@protoc_insertion_point(field_get:DivertMessage.dest_host)
  return _internal_dest_host();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DivertMessage::set_dest_host(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.dest_host_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:DivertMessage.dest_host)
}
inline std::string* DivertMessage::mutable_dest_host() {
  std::string* _s = _internal_mutable_dest_host();
  // @@protoc_insertion_point(field_mutable:DivertMessage.dest_host)
  return _s;
}
inline const std::string& DivertMessage::_internal_dest_host() const {
  return _impl_.dest_host_.Get();
}
inline void DivertMessage::_internal_set_dest_host(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.dest_host_.Set(value, GetArenaForAllocation());
}
inline std::string* DivertMessage::_internal_mutable_dest_host() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.dest_host_.Mutable(GetArenaForAllocation());
}
inline std::string* DivertMessage::release_dest_host() {
  // @@protoc_insertion_point(field_release:DivertMessage.dest_host)
  if (!_internal_has_dest_host()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.dest_host_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.dest_host_.IsDefault()) {
    _impl_.dest_host_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DivertMessage::set_allocated_dest_host(std::string* dest_host) {
  if (dest_host != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.dest_host_.SetAllocated(dest_host, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.dest_host_.IsDefault()) {
    _impl_.dest_host_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:DivertMessage.dest_host)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_divert_2eproto