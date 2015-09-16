// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgMove.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MsgMove.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)

void protobuf_ShutdownFile_MsgMove_2eproto() {
  delete CMsgMove::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_MsgMove_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_MsgMove_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  CMsgMove::default_instance_ = new CMsgMove();
  CMsgMove::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MsgMove_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_MsgMove_2eproto_once_);
void protobuf_AddDesc_MsgMove_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_MsgMove_2eproto_once_,
                 &protobuf_AddDesc_MsgMove_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MsgMove_2eproto {
  StaticDescriptorInitializer_MsgMove_2eproto() {
    protobuf_AddDesc_MsgMove_2eproto();
  }
} static_descriptor_initializer_MsgMove_2eproto_;
#endif
bool MSG_MOVE_ACTION_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int CMsgMove::kNActionFieldNumber;
const int CMsgMove::kIdRoleFieldNumber;
const int CMsgMove::kFStartXFieldNumber;
const int CMsgMove::kFStartYFieldNumber;
const int CMsgMove::kFStartZFieldNumber;
const int CMsgMove::kFEndXFieldNumber;
const int CMsgMove::kFEndYFieldNumber;
const int CMsgMove::kFEndzFieldNumber;
const int CMsgMove::kTStartTimeFieldNumber;
const int CMsgMove::kTEndTimeFieldNumber;
const int CMsgMove::kFVelecityFieldNumber;
#endif  // !_MSC_VER

CMsgMove::CMsgMove()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:CMsgMove)
}

void CMsgMove::InitAsDefaultInstance() {
}

CMsgMove::CMsgMove(const CMsgMove& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CMsgMove)
}

void CMsgMove::SharedCtor() {
  _cached_size_ = 0;
  naction_ = 0;
  idrole_ = GOOGLE_ULONGLONG(0);
  fstartx_ = 0;
  fstarty_ = 0;
  fstartz_ = 0;
  fendx_ = 0;
  fendy_ = 0;
  fendz_ = 0;
  tstarttime_ = GOOGLE_LONGLONG(0);
  tendtime_ = GOOGLE_LONGLONG(0);
  fvelecity_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CMsgMove::~CMsgMove() {
  // @@protoc_insertion_point(destructor:CMsgMove)
  SharedDtor();
}

void CMsgMove::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void CMsgMove::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const CMsgMove& CMsgMove::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_MsgMove_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_MsgMove_2eproto();
#endif
  return *default_instance_;
}

CMsgMove* CMsgMove::default_instance_ = NULL;

CMsgMove* CMsgMove::New(::google::protobuf::Arena* arena) const {
  CMsgMove* n = new CMsgMove;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CMsgMove::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<CMsgMove*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  if (_has_bits_[0 / 32] & 255u) {
    ZR_(idrole_, fendy_);
    fendz_ = 0;
  }
  if (_has_bits_[8 / 32] & 1792u) {
    ZR_(fvelecity_, tendtime_);
    tstarttime_ = GOOGLE_LONGLONG(0);
  }

#undef ZR_HELPER_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->clear();
}

bool CMsgMove::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::io::StringOutputStream unknown_fields_string(
      mutable_unknown_fields());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_string);
  // @@protoc_insertion_point(parse_start:CMsgMove)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 nAction = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &naction_)));
          set_has_naction();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_idRole;
        break;
      }

      // optional uint64 idRole = 2;
      case 2: {
        if (tag == 16) {
         parse_idRole:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &idrole_)));
          set_has_idrole();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(29)) goto parse_fStartX;
        break;
      }

      // optional float fStartX = 3;
      case 3: {
        if (tag == 29) {
         parse_fStartX:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fstartx_)));
          set_has_fstartx();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(37)) goto parse_fStartY;
        break;
      }

      // optional float fStartY = 4;
      case 4: {
        if (tag == 37) {
         parse_fStartY:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fstarty_)));
          set_has_fstarty();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_fStartZ;
        break;
      }

      // optional float fStartZ = 5;
      case 5: {
        if (tag == 45) {
         parse_fStartZ:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fstartz_)));
          set_has_fstartz();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(53)) goto parse_fEndX;
        break;
      }

      // optional float fEndX = 6;
      case 6: {
        if (tag == 53) {
         parse_fEndX:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fendx_)));
          set_has_fendx();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(61)) goto parse_fEndY;
        break;
      }

      // optional float fEndY = 7;
      case 7: {
        if (tag == 61) {
         parse_fEndY:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fendy_)));
          set_has_fendy();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(69)) goto parse_fEndz;
        break;
      }

      // optional float fEndz = 8;
      case 8: {
        if (tag == 69) {
         parse_fEndz:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fendz_)));
          set_has_fendz();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_tStartTime;
        break;
      }

      // optional int64 tStartTime = 9;
      case 9: {
        if (tag == 72) {
         parse_tStartTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &tstarttime_)));
          set_has_tstarttime();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_tEndTime;
        break;
      }

      // optional int64 tEndTime = 10;
      case 10: {
        if (tag == 80) {
         parse_tEndTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &tendtime_)));
          set_has_tendtime();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(93)) goto parse_fVelecity;
        break;
      }

      // optional float fVelecity = 11;
      case 11: {
        if (tag == 93) {
         parse_fVelecity:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &fvelecity_)));
          set_has_fvelecity();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CMsgMove)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CMsgMove)
  return false;
#undef DO_
}

void CMsgMove::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CMsgMove)
  // required int32 nAction = 1;
  if (has_naction()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->naction(), output);
  }

  // optional uint64 idRole = 2;
  if (has_idrole()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->idrole(), output);
  }

  // optional float fStartX = 3;
  if (has_fstartx()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->fstartx(), output);
  }

  // optional float fStartY = 4;
  if (has_fstarty()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->fstarty(), output);
  }

  // optional float fStartZ = 5;
  if (has_fstartz()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->fstartz(), output);
  }

  // optional float fEndX = 6;
  if (has_fendx()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->fendx(), output);
  }

  // optional float fEndY = 7;
  if (has_fendy()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(7, this->fendy(), output);
  }

  // optional float fEndz = 8;
  if (has_fendz()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(8, this->fendz(), output);
  }

  // optional int64 tStartTime = 9;
  if (has_tstarttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(9, this->tstarttime(), output);
  }

  // optional int64 tEndTime = 10;
  if (has_tendtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(10, this->tendtime(), output);
  }

  // optional float fVelecity = 11;
  if (has_fvelecity()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(11, this->fvelecity(), output);
  }

  output->WriteRaw(unknown_fields().data(),
                   unknown_fields().size());
  // @@protoc_insertion_point(serialize_end:CMsgMove)
}

int CMsgMove::ByteSize() const {
  int total_size = 0;

  // required int32 nAction = 1;
  if (has_naction()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->naction());
  }
  if (_has_bits_[1 / 32] & 254u) {
    // optional uint64 idRole = 2;
    if (has_idrole()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->idrole());
    }

    // optional float fStartX = 3;
    if (has_fstartx()) {
      total_size += 1 + 4;
    }

    // optional float fStartY = 4;
    if (has_fstarty()) {
      total_size += 1 + 4;
    }

    // optional float fStartZ = 5;
    if (has_fstartz()) {
      total_size += 1 + 4;
    }

    // optional float fEndX = 6;
    if (has_fendx()) {
      total_size += 1 + 4;
    }

    // optional float fEndY = 7;
    if (has_fendy()) {
      total_size += 1 + 4;
    }

    // optional float fEndz = 8;
    if (has_fendz()) {
      total_size += 1 + 4;
    }

  }
  if (_has_bits_[8 / 32] & 1792u) {
    // optional int64 tStartTime = 9;
    if (has_tstarttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->tstarttime());
    }

    // optional int64 tEndTime = 10;
    if (has_tendtime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->tendtime());
    }

    // optional float fVelecity = 11;
    if (has_fvelecity()) {
      total_size += 1 + 4;
    }

  }
  total_size += unknown_fields().size();

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CMsgMove::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const CMsgMove*>(&from));
}

void CMsgMove::MergeFrom(const CMsgMove& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_naction()) {
      set_naction(from.naction());
    }
    if (from.has_idrole()) {
      set_idrole(from.idrole());
    }
    if (from.has_fstartx()) {
      set_fstartx(from.fstartx());
    }
    if (from.has_fstarty()) {
      set_fstarty(from.fstarty());
    }
    if (from.has_fstartz()) {
      set_fstartz(from.fstartz());
    }
    if (from.has_fendx()) {
      set_fendx(from.fendx());
    }
    if (from.has_fendy()) {
      set_fendy(from.fendy());
    }
    if (from.has_fendz()) {
      set_fendz(from.fendz());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_tstarttime()) {
      set_tstarttime(from.tstarttime());
    }
    if (from.has_tendtime()) {
      set_tendtime(from.tendtime());
    }
    if (from.has_fvelecity()) {
      set_fvelecity(from.fvelecity());
    }
  }
  mutable_unknown_fields()->append(from.unknown_fields());
}

void CMsgMove::CopyFrom(const CMsgMove& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CMsgMove::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void CMsgMove::Swap(CMsgMove* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CMsgMove::InternalSwap(CMsgMove* other) {
  std::swap(naction_, other->naction_);
  std::swap(idrole_, other->idrole_);
  std::swap(fstartx_, other->fstartx_);
  std::swap(fstarty_, other->fstarty_);
  std::swap(fstartz_, other->fstartz_);
  std::swap(fendx_, other->fendx_);
  std::swap(fendy_, other->fendy_);
  std::swap(fendz_, other->fendz_);
  std::swap(tstarttime_, other->tstarttime_);
  std::swap(tendtime_, other->tendtime_);
  std::swap(fvelecity_, other->fvelecity_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _unknown_fields_.swap(other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string CMsgMove::GetTypeName() const {
  return "CMsgMove";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// CMsgMove

// required int32 nAction = 1;
bool CMsgMove::has_naction() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void CMsgMove::set_has_naction() {
  _has_bits_[0] |= 0x00000001u;
}
void CMsgMove::clear_has_naction() {
  _has_bits_[0] &= ~0x00000001u;
}
void CMsgMove::clear_naction() {
  naction_ = 0;
  clear_has_naction();
}
 ::google::protobuf::int32 CMsgMove::naction() const {
  // @@protoc_insertion_point(field_get:CMsgMove.nAction)
  return naction_;
}
 void CMsgMove::set_naction(::google::protobuf::int32 value) {
  set_has_naction();
  naction_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.nAction)
}

// optional uint64 idRole = 2;
bool CMsgMove::has_idrole() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void CMsgMove::set_has_idrole() {
  _has_bits_[0] |= 0x00000002u;
}
void CMsgMove::clear_has_idrole() {
  _has_bits_[0] &= ~0x00000002u;
}
void CMsgMove::clear_idrole() {
  idrole_ = GOOGLE_ULONGLONG(0);
  clear_has_idrole();
}
 ::google::protobuf::uint64 CMsgMove::idrole() const {
  // @@protoc_insertion_point(field_get:CMsgMove.idRole)
  return idrole_;
}
 void CMsgMove::set_idrole(::google::protobuf::uint64 value) {
  set_has_idrole();
  idrole_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.idRole)
}

// optional float fStartX = 3;
bool CMsgMove::has_fstartx() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void CMsgMove::set_has_fstartx() {
  _has_bits_[0] |= 0x00000004u;
}
void CMsgMove::clear_has_fstartx() {
  _has_bits_[0] &= ~0x00000004u;
}
void CMsgMove::clear_fstartx() {
  fstartx_ = 0;
  clear_has_fstartx();
}
 float CMsgMove::fstartx() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fStartX)
  return fstartx_;
}
 void CMsgMove::set_fstartx(float value) {
  set_has_fstartx();
  fstartx_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fStartX)
}

// optional float fStartY = 4;
bool CMsgMove::has_fstarty() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void CMsgMove::set_has_fstarty() {
  _has_bits_[0] |= 0x00000008u;
}
void CMsgMove::clear_has_fstarty() {
  _has_bits_[0] &= ~0x00000008u;
}
void CMsgMove::clear_fstarty() {
  fstarty_ = 0;
  clear_has_fstarty();
}
 float CMsgMove::fstarty() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fStartY)
  return fstarty_;
}
 void CMsgMove::set_fstarty(float value) {
  set_has_fstarty();
  fstarty_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fStartY)
}

// optional float fStartZ = 5;
bool CMsgMove::has_fstartz() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
void CMsgMove::set_has_fstartz() {
  _has_bits_[0] |= 0x00000010u;
}
void CMsgMove::clear_has_fstartz() {
  _has_bits_[0] &= ~0x00000010u;
}
void CMsgMove::clear_fstartz() {
  fstartz_ = 0;
  clear_has_fstartz();
}
 float CMsgMove::fstartz() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fStartZ)
  return fstartz_;
}
 void CMsgMove::set_fstartz(float value) {
  set_has_fstartz();
  fstartz_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fStartZ)
}

// optional float fEndX = 6;
bool CMsgMove::has_fendx() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
void CMsgMove::set_has_fendx() {
  _has_bits_[0] |= 0x00000020u;
}
void CMsgMove::clear_has_fendx() {
  _has_bits_[0] &= ~0x00000020u;
}
void CMsgMove::clear_fendx() {
  fendx_ = 0;
  clear_has_fendx();
}
 float CMsgMove::fendx() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fEndX)
  return fendx_;
}
 void CMsgMove::set_fendx(float value) {
  set_has_fendx();
  fendx_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fEndX)
}

// optional float fEndY = 7;
bool CMsgMove::has_fendy() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
void CMsgMove::set_has_fendy() {
  _has_bits_[0] |= 0x00000040u;
}
void CMsgMove::clear_has_fendy() {
  _has_bits_[0] &= ~0x00000040u;
}
void CMsgMove::clear_fendy() {
  fendy_ = 0;
  clear_has_fendy();
}
 float CMsgMove::fendy() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fEndY)
  return fendy_;
}
 void CMsgMove::set_fendy(float value) {
  set_has_fendy();
  fendy_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fEndY)
}

// optional float fEndz = 8;
bool CMsgMove::has_fendz() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
void CMsgMove::set_has_fendz() {
  _has_bits_[0] |= 0x00000080u;
}
void CMsgMove::clear_has_fendz() {
  _has_bits_[0] &= ~0x00000080u;
}
void CMsgMove::clear_fendz() {
  fendz_ = 0;
  clear_has_fendz();
}
 float CMsgMove::fendz() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fEndz)
  return fendz_;
}
 void CMsgMove::set_fendz(float value) {
  set_has_fendz();
  fendz_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fEndz)
}

// optional int64 tStartTime = 9;
bool CMsgMove::has_tstarttime() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
void CMsgMove::set_has_tstarttime() {
  _has_bits_[0] |= 0x00000100u;
}
void CMsgMove::clear_has_tstarttime() {
  _has_bits_[0] &= ~0x00000100u;
}
void CMsgMove::clear_tstarttime() {
  tstarttime_ = GOOGLE_LONGLONG(0);
  clear_has_tstarttime();
}
 ::google::protobuf::int64 CMsgMove::tstarttime() const {
  // @@protoc_insertion_point(field_get:CMsgMove.tStartTime)
  return tstarttime_;
}
 void CMsgMove::set_tstarttime(::google::protobuf::int64 value) {
  set_has_tstarttime();
  tstarttime_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.tStartTime)
}

// optional int64 tEndTime = 10;
bool CMsgMove::has_tendtime() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
void CMsgMove::set_has_tendtime() {
  _has_bits_[0] |= 0x00000200u;
}
void CMsgMove::clear_has_tendtime() {
  _has_bits_[0] &= ~0x00000200u;
}
void CMsgMove::clear_tendtime() {
  tendtime_ = GOOGLE_LONGLONG(0);
  clear_has_tendtime();
}
 ::google::protobuf::int64 CMsgMove::tendtime() const {
  // @@protoc_insertion_point(field_get:CMsgMove.tEndTime)
  return tendtime_;
}
 void CMsgMove::set_tendtime(::google::protobuf::int64 value) {
  set_has_tendtime();
  tendtime_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.tEndTime)
}

// optional float fVelecity = 11;
bool CMsgMove::has_fvelecity() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
void CMsgMove::set_has_fvelecity() {
  _has_bits_[0] |= 0x00000400u;
}
void CMsgMove::clear_has_fvelecity() {
  _has_bits_[0] &= ~0x00000400u;
}
void CMsgMove::clear_fvelecity() {
  fvelecity_ = 0;
  clear_has_fvelecity();
}
 float CMsgMove::fvelecity() const {
  // @@protoc_insertion_point(field_get:CMsgMove.fVelecity)
  return fvelecity_;
}
 void CMsgMove::set_fvelecity(float value) {
  set_has_fvelecity();
  fvelecity_ = value;
  // @@protoc_insertion_point(field_set:CMsgMove.fVelecity)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
