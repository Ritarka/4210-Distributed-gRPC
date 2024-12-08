// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/store.proto

#include "protos/store.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = ::PROTOBUF_NAMESPACE_ID::internal;
namespace store {
template <typename>
PROTOBUF_CONSTEXPR ProductQuery::ProductQuery(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.product_name_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ProductQueryDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ProductQueryDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ProductQueryDefaultTypeInternal() {}
  union {
    ProductQuery _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ProductQueryDefaultTypeInternal _ProductQuery_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR ProductReply::ProductReply(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.products_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ProductReplyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ProductReplyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ProductReplyDefaultTypeInternal() {}
  union {
    ProductReply _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ProductReplyDefaultTypeInternal _ProductReply_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR ProductInfo::ProductInfo(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.vendor_id_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_.price_)*/ 0

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ProductInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ProductInfoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ProductInfoDefaultTypeInternal() {}
  union {
    ProductInfo _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ProductInfoDefaultTypeInternal _ProductInfo_default_instance_;
}  // namespace store
static ::_pb::Metadata file_level_metadata_protos_2fstore_2eproto[3];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_protos_2fstore_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_protos_2fstore_2eproto = nullptr;
const ::uint32_t TableStruct_protos_2fstore_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::store::ProductQuery, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::store::ProductQuery, _impl_.product_name_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::store::ProductReply, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::store::ProductReply, _impl_.products_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::store::ProductInfo, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::store::ProductInfo, _impl_.price_),
    PROTOBUF_FIELD_OFFSET(::store::ProductInfo, _impl_.vendor_id_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::store::ProductQuery)},
        { 9, -1, -1, sizeof(::store::ProductReply)},
        { 18, -1, -1, sizeof(::store::ProductInfo)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::store::_ProductQuery_default_instance_._instance,
    &::store::_ProductReply_default_instance_._instance,
    &::store::_ProductInfo_default_instance_._instance,
};
const char descriptor_table_protodef_protos_2fstore_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\022protos/store.proto\022\005store\"$\n\014ProductQu"
    "ery\022\024\n\014product_name\030\001 \001(\t\"4\n\014ProductRepl"
    "y\022$\n\010products\030\001 \003(\0132\022.store.ProductInfo\""
    "/\n\013ProductInfo\022\r\n\005price\030\001 \001(\001\022\021\n\tvendor_"
    "id\030\002 \001(\t2B\n\005Store\0229\n\013getProducts\022\023.store"
    ".ProductQuery\032\023.store.ProductReply\"\000b\006pr"
    "oto3"
};
static ::absl::once_flag descriptor_table_protos_2fstore_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_protos_2fstore_2eproto = {
    false,
    false,
    244,
    descriptor_table_protodef_protos_2fstore_2eproto,
    "protos/store.proto",
    &descriptor_table_protos_2fstore_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_protos_2fstore_2eproto::offsets,
    file_level_metadata_protos_2fstore_2eproto,
    file_level_enum_descriptors_protos_2fstore_2eproto,
    file_level_service_descriptors_protos_2fstore_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_protos_2fstore_2eproto_getter() {
  return &descriptor_table_protos_2fstore_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_protos_2fstore_2eproto(&descriptor_table_protos_2fstore_2eproto);
namespace store {
// ===================================================================

class ProductQuery::_Internal {
 public:
};

ProductQuery::ProductQuery(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:store.ProductQuery)
}
ProductQuery::ProductQuery(const ProductQuery& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ProductQuery* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.product_name_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.product_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.product_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_product_name().empty()) {
    _this->_impl_.product_name_.Set(from._internal_product_name(), _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:store.ProductQuery)
}

inline void ProductQuery::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.product_name_) {}

    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.product_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.product_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ProductQuery::~ProductQuery() {
  // @@protoc_insertion_point(destructor:store.ProductQuery)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ProductQuery::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.product_name_.Destroy();
}

void ProductQuery::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ProductQuery::Clear() {
// @@protoc_insertion_point(message_clear_start:store.ProductQuery)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.product_name_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ProductQuery::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string product_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_product_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "store.ProductQuery.product_name"));
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* ProductQuery::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:store.ProductQuery)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string product_name = 1;
  if (!this->_internal_product_name().empty()) {
    const std::string& _s = this->_internal_product_name();
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "store.ProductQuery.product_name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:store.ProductQuery)
  return target;
}

::size_t ProductQuery::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:store.ProductQuery)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string product_name = 1;
  if (!this->_internal_product_name().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                                    this->_internal_product_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ProductQuery::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ProductQuery::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ProductQuery::GetClassData() const { return &_class_data_; }


void ProductQuery::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ProductQuery*>(&to_msg);
  auto& from = static_cast<const ProductQuery&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:store.ProductQuery)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_product_name().empty()) {
    _this->_internal_set_product_name(from._internal_product_name());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ProductQuery::CopyFrom(const ProductQuery& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:store.ProductQuery)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProductQuery::IsInitialized() const {
  return true;
}

void ProductQuery::InternalSwap(ProductQuery* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.product_name_, lhs_arena,
                                       &other->_impl_.product_name_, rhs_arena);
}

::PROTOBUF_NAMESPACE_ID::Metadata ProductQuery::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protos_2fstore_2eproto_getter, &descriptor_table_protos_2fstore_2eproto_once,
      file_level_metadata_protos_2fstore_2eproto[0]);
}
// ===================================================================

class ProductReply::_Internal {
 public:
};

ProductReply::ProductReply(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:store.ProductReply)
}
ProductReply::ProductReply(const ProductReply& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ProductReply* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.products_){from._impl_.products_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:store.ProductReply)
}

inline void ProductReply::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.products_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

ProductReply::~ProductReply() {
  // @@protoc_insertion_point(destructor:store.ProductReply)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ProductReply::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _internal_mutable_products()->~RepeatedPtrField();
}

void ProductReply::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ProductReply::Clear() {
// @@protoc_insertion_point(message_clear_start:store.ProductReply)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_products()->Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ProductReply::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .store.ProductInfo products = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_products(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* ProductReply::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:store.ProductReply)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .store.ProductInfo products = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_products_size()); i < n; i++) {
    const auto& repfield = this->_internal_products(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:store.ProductReply)
  return target;
}

::size_t ProductReply::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:store.ProductReply)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .store.ProductInfo products = 1;
  total_size += 1UL * this->_internal_products_size();
  for (const auto& msg : this->_internal_products()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ProductReply::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ProductReply::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ProductReply::GetClassData() const { return &_class_data_; }


void ProductReply::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ProductReply*>(&to_msg);
  auto& from = static_cast<const ProductReply&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:store.ProductReply)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_products()->MergeFrom(from._internal_products());
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ProductReply::CopyFrom(const ProductReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:store.ProductReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProductReply::IsInitialized() const {
  return true;
}

void ProductReply::InternalSwap(ProductReply* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _internal_mutable_products()->InternalSwap(other->_internal_mutable_products());
}

::PROTOBUF_NAMESPACE_ID::Metadata ProductReply::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protos_2fstore_2eproto_getter, &descriptor_table_protos_2fstore_2eproto_once,
      file_level_metadata_protos_2fstore_2eproto[1]);
}
// ===================================================================

class ProductInfo::_Internal {
 public:
};

ProductInfo::ProductInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:store.ProductInfo)
}
ProductInfo::ProductInfo(const ProductInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ProductInfo* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.vendor_id_) {}

    , decltype(_impl_.price_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.vendor_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.vendor_id_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_vendor_id().empty()) {
    _this->_impl_.vendor_id_.Set(from._internal_vendor_id(), _this->GetArenaForAllocation());
  }
  _this->_impl_.price_ = from._impl_.price_;
  // @@protoc_insertion_point(copy_constructor:store.ProductInfo)
}

inline void ProductInfo::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.vendor_id_) {}

    , decltype(_impl_.price_) { 0 }

    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.vendor_id_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.vendor_id_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ProductInfo::~ProductInfo() {
  // @@protoc_insertion_point(destructor:store.ProductInfo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ProductInfo::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.vendor_id_.Destroy();
}

void ProductInfo::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ProductInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:store.ProductInfo)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.vendor_id_.ClearToEmpty();
  _impl_.price_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ProductInfo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // double price = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 9)) {
          _impl_.price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else {
          goto handle_unusual;
        }
        continue;
      // string vendor_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_vendor_id();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "store.ProductInfo.vendor_id"));
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* ProductInfo::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:store.ProductInfo)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // double price = 1;
  static_assert(sizeof(::uint64_t) == sizeof(double), "Code assumes ::uint64_t and double are the same size.");
  double tmp_price = this->_internal_price();
  ::uint64_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        1, this->_internal_price(), target);
  }

  // string vendor_id = 2;
  if (!this->_internal_vendor_id().empty()) {
    const std::string& _s = this->_internal_vendor_id();
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "store.ProductInfo.vendor_id");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:store.ProductInfo)
  return target;
}

::size_t ProductInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:store.ProductInfo)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string vendor_id = 2;
  if (!this->_internal_vendor_id().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                                    this->_internal_vendor_id());
  }

  // double price = 1;
  static_assert(sizeof(::uint64_t) == sizeof(double), "Code assumes ::uint64_t and double are the same size.");
  double tmp_price = this->_internal_price();
  ::uint64_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    total_size += 9;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ProductInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ProductInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ProductInfo::GetClassData() const { return &_class_data_; }


void ProductInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ProductInfo*>(&to_msg);
  auto& from = static_cast<const ProductInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:store.ProductInfo)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_vendor_id().empty()) {
    _this->_internal_set_vendor_id(from._internal_vendor_id());
  }
  static_assert(sizeof(::uint64_t) == sizeof(double), "Code assumes ::uint64_t and double are the same size.");
  double tmp_price = from._internal_price();
  ::uint64_t raw_price;
  memcpy(&raw_price, &tmp_price, sizeof(tmp_price));
  if (raw_price != 0) {
    _this->_internal_set_price(from._internal_price());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ProductInfo::CopyFrom(const ProductInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:store.ProductInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProductInfo::IsInitialized() const {
  return true;
}

void ProductInfo::InternalSwap(ProductInfo* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.vendor_id_, lhs_arena,
                                       &other->_impl_.vendor_id_, rhs_arena);

  swap(_impl_.price_, other->_impl_.price_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ProductInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_protos_2fstore_2eproto_getter, &descriptor_table_protos_2fstore_2eproto_once,
      file_level_metadata_protos_2fstore_2eproto[2]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace store
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::store::ProductQuery*
Arena::CreateMaybeMessage< ::store::ProductQuery >(Arena* arena) {
  return Arena::CreateMessageInternal< ::store::ProductQuery >(arena);
}
template<> PROTOBUF_NOINLINE ::store::ProductReply*
Arena::CreateMaybeMessage< ::store::ProductReply >(Arena* arena) {
  return Arena::CreateMessageInternal< ::store::ProductReply >(arena);
}
template<> PROTOBUF_NOINLINE ::store::ProductInfo*
Arena::CreateMaybeMessage< ::store::ProductInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::store::ProductInfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
