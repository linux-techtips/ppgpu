#pragma once

#include "webgpu.h"

#ifndef WEBGPU_H_
#error "Make sure to include the WEBGPU C header prior to this."
#endif

#include <type_traits>

namespace wgpu {

    #define END };

    // OUTSIDE IMPLEMENTATIONS

    using Adapter = struct WGPUAdapterImpl*;
    using BindGroup = struct WGPUBindGroupImpl*;
    using BindGroupLayout = struct WGPUBindGroupLayoutImpl*;
    using Buffer = struct WGPUBufferImpl*;
    using CommandBuffer = struct WGPUCommandBufferImpl*;
    using CommandEncoder = struct WGPUCommandEncoderImpl*;
    using CommandPassEncoder = struct WGPUCommandPassEncoderImpl*;
    using ComputePassPipeline = struct WGPUComputePassPipelineImpl*;
    using Device = struct WGPUDeviceImpl*;
    using Instance = struct WGPUInstanceImpl*;
    using PipelineLayout = struct WGPUPipelineLayoutImpl*;
    using QuerySet = struct WGPUQuerySetImpl*;
    using Queue = struct WGPUQueueImpl*;
    using RenderBundle = struct WGPURenderBundleImpl*;
    using RenderBundleEncoder = struct WGPURenderBundleEncoderImpl*;
    using RenderPassEncoder = struct WGPURenderPassEncoderImpl*;
    using RenderPipeline = struct WGPURenderPassPipelineImpl*;
    using Sampler = struct WGPUSamplerImpl*;
    using ShaderModule = struct WGPUShaderModuleImpl*;
    using Surface = struct WGPUSufaceImpl*;
    using SwapChain = struct WGPUSwapChainImpl*;
    using Texture = struct WGPUTextureImpl*;
    using TextureView = struct WGPUTextureViewImpl*;

    // ENUMERATIONS

    #define ENUM(Name) enum class Name : uint32_t {

    template <typename T>
    static constexpr auto Force32() -> T {
        return static_cast<T>(0x7FFFFFFF)
    }

    ENUM(AdapterType)
        DiscreteGPU,
        IntegratedGPU,
        CPU,
        Unknown,
    END

    ENUM(AddressMode)
        Repeat,
        MirrorRepeat,
        ClampToEdge,
    END

    ENUM(BackendType)
        Undefined,
        Null,
        WebGPU,
        D3D11,
        D3D12,
        Metal,
        Vulkan,
        OpenGL,
        OpenGLES,
    END

    ENUM(BlendFactor)
        Zero,
        One,
        Src,
        OneMinusSrc,
        SrcAlpha,
        OneMinusSrcAlpha,
        Dst,
        OneMinusDst,
        DstAlpha,
        OneMinusDstAlpha,
        SrcAlphaSaturated,
        Constant,
        OneMinusConstant,
    END

    ENUM(BlendOperation)
        Add,
        Sub,
        ReverseSub,
        Min,
        Max,
    END

    ENUM(BufferBindingType)
        Undefined,
        Uniform,
        Storage,
        ReadOnlyStorage,
    END

    ENUM(BufferMapAsyncStatus)
        Success,
        ValidationError,
        Unknown,
        DeviceLost,
        DestroyedBeforeCallback,
        UnmappedBeforeCallback,
        MappingAlreadyPending,
        OffsetOutOfRange,
        SizeOutOfRange,
    END

    ENUM(BufferMapState)
        Unmapped,
        Pending,
        Mapped,
    END

    ENUM(CompareFunction)
        Undefined,
        Never,
        Less,
        LessEqual,
        Greater,
        GreaterEqual,
        Equal,
        NotEqual,
        Always,
    END

    ENUM(CompilationRequestStatus)
        Success,
        Error,
        DeviceLost,
        Unknown,
    END

    ENUM(CompilationMessageType)
        Error,
        Warning,
        Info,
    END

    ENUM(ComputePassTimestampLocation)
        Beginning,
        End,
    END

    ENUM(CreatePipelineAsyncStatus)
        Success,
        ValidationError,
        InternalError,
        DeviceLost,
        DevicesDestroyed,
        Unknown,
    END

    ENUM(CullMode)
        None,
        Front,
        Back,
    END

    ENUM(DeviceLostReason)
        Undefined,
        Destroyed,
    END

    ENUM(ErrorFilter)
        Validation,
        OutOfMemory,
        Internal,
    END

    ENUM(ErrorType)
        NoError,
        Validation,
        OutOfMemory,
        Internal,
        Unknown,
        DeviceLost,
    END

    ENUM(FeatureName)
        Undefined,
        DepthClipControl,
        Depth32FloatStencil8,
        TimestampQuery,
        PipelineStatisticsQuery,
        TextureCompressionBC,
        TextureCompressionETC2,
        TextureCompressionASTC,
        IndirectFirstInstance,
        ShaderF16,
        RG11B10UfloatRenderable,
        BGRA8UnormStorage,
        Float32Filterable,
    END

    ENUM(FilterMode)
        Nearest,
        Linear,
    END

    ENUM(FrontFace)
        CCW,
        CW,
    END

    ENUM(IndexFormat)
        Undefined,
        Uint16,
        Uint32,
    END

    ENUM(LoadOp)
        Undefined,
        Clear,
        Load,
    END

    ENUM(MipmapFilterMode)
        Nearest,
        Linear,
    END

    ENUM(PipelineStatisticsName)
        VertexShaderInvocations,
        ClipperInvocations,
        ClipperPrimitivesOut,
        FragmentShaderInvocations,
        ComputeShaderInvocations,
    END

    ENUM(PowerPreference)
        Undefined,
        LowPower,
        HighPerformance,
    END

    ENUM(PresentMode)
        Immediate,
        Mailbox,
        Fifo,
    END

    ENUM(PrimitiveTopology)
        PointList,
        LineList,
        LineStrip,
        TriangleList,
        TriangleStrip,
    END

    ENUM(QueryType)
        Occlusion,
        PipelineStatistics,
        Timestamp,
    END

    ENUM(QueueWorkDoneStatus)
        Success,
        Error,
        Unknown,
        DeviceLost,
    END

    ENUM(RenderPassTimestampLocation)
        Beginning,
        End,
    END

    ENUM(RequestAdapterStatus)
        Success,
        Unavailable,
        Error,
        Unknown,
    END

    ENUM(RequestDeviceStatus)
        Success,
        Error,
        Unkown,
    END

    ENUM(SType)
        Invalid,
        SurfaceDescriptorFromMetaLayer,
        SurfaceDescriptorFromWindowsHWND,
        SurfaceDescriptorFromXlibWindow,
        SurfaceDescriptorFromCanvasHTMLSelector,
        ShaderModuleSPIRVDescriptor,
        ShaderModuleWGSLDescriptor,
        PrimitiveDepthClipControl,
        SurfaceDescriptorFromWaylandSurface,
        SurfaceDescriptorFromAndroidNativeWindow,
        SurfaceDescriptorFromXcbWindow,
        RenderPassDescriptorMaxDrawCount,
    END

    ENUM(SamplerBindingType)
        Undefined,
        Filtering,
        NonFiltering,
        Comparison,
    END

    ENUM(StencilOperation)
        Keep,
        Zero,
        Replace,
        Invert,
        IncrementClamp,
        DecrementClamp,
        IncrementWrap,
        DecrementWrap,
    END

    ENUM(StorageTextureAccess)
        Undefined,
        WriteOnly,
    END

    ENUM(StoreOp)
        Undefined,
        Store,
        Discard,
    END

    ENUM(TextureAspect)
        All,
        StencilOnly,
        DepthOnly,
    END

    ENUM(TextureDimension)
        D1,
        D2,
        D3,
    END

    ENUM(TextureFormat)
        Undefined,
        R8Unorm,
        R8Snorm,
        R8Uint,
        R8Sint,
        R16Uint,
        R16Sint,
        R16Float,
        RG8Unorm,
        RG8Snorm,
        RG8Uint,
        RG8Sint,
        R32Float,
        R32Uint,
        R32Sint,
        RG16Uint,
        RG16Sint,
        RG16Float,
        RGBA8Unorm,
        RGBA8UnormSrgb,
        RGBA8Snorm,
        RGBA8Uint,
        RGBA8Sint,
        BGRA8Unorm,
        BGRA8UnormSrgb,
        RGB10A2Unorm,
        RG11B10Ufloat,
        RGB9E5Ufloat,
        RG32Float,
        RG32Uint,
        RG32Sint,
        RGBA16Uint,
        RGBA16Sint,
        RGBA16Float,
        RGBA32Float,
        RGBA32Uint,
        RGBA32Sint,
        Stencil8,
        Depth16Unorm,
        Depth24Plus,
        Depth24PlusStencil8,
        Depth32Float,
        Depth32FloatStencil8,
        BC1RGBAUnorm,
        BC1RGBAUnormSrgb,
        BC2RGBAUnorm,
        BC2RGBAUnormSrgb,
        BC3RGBAUnorm,
        BC3RGBAUnormSrgb,
        BC4RUnorm,
        BC4RSnorm,
        BC5RGUnorm,
        BC5RGSnorm,
        BC6HRGBUfloat,
        BC6HRGBFloat,
        BC7RGBAUnorm,
        BC7RGBAUnormSrgb,
        ETC2RGB8Unorm,
        ETC2RGB8UnormSrgb,
        ETC2RGB8A1Unorm,
        ETC2RGB8A1UnormSrgb,
        ETC2RGBA8Unorm,
        ETC2RGBA8UnormSrgb,
        EACR11Unorm,
        EACR11Snorm,
        EACRG11Unorm,
        EACRG11Snorm,
        ASTC4x4Unorm,
        ASTC4x4UnormSrgb,
        ASTC5x4Unorm,
        ASTC5x4UnormSrgb,
        ASTC5x5Unorm,
        ASTC5x5UnormSrgb,
        ASTC6x5Unorm,
        ASTC6x5UnormSrgb,
        ASTC6x6Unorm,
        ASTC6x6UnormSrgb,
        ASTC8x5Unorm,
        ASTC8x5UnormSrgb,
        ASTC8x6Unorm,
        ASTC8x6UnormSrgb,
        ASTC8x8Unorm,
        ASTC8x8UnormSrgb,
        ASTC10x5Unorm,
        ASTC10x5UnormSrgb,
        ASTC10x6Unorm,
        ASTC10x6UnormSrgb,
        ASTC10x8Unorm,
        ASTC10x8UnormSrgb,
        ASTC10x10Unorm,
        ASTC10x10UnormSrgb,
        ASTC12x10Unorm,
        ASTC12x10UnormSrgb,
        ASTC12x12Unorm,
        ASTC12x12UnormSrgb,
    END

    ENUM(TextureSampleType)
        Undefined,
        Float,
        UnfilterableFloat,
        Depth,
        Sint,
        Uint,
    END

    ENUM(TextureViewDimension)
        Undefined,
        D1,
        D2,
        D2Array,
        Cube,
        CubeArray,
        D3,
    END

    ENUM(VertexFormat)
        Undefined,
        Uint8x2,
        Uint8x4,
        Sint8x2,
        Sint8x4,
        Unorm8x2,
        Unorm8x4,
        Snorm8x2,
        Snorm8x4,
        Uint16x2,
        Uint16x4,
        Sint16x2,
        Sint16x4,
        Unorm16x2,
        Unorm16x4,
        Snorm16x2,
        Snorm16x4,
        Float16x2,
        Float16x4,
        Float32,
        Float32x2,
        Float32x3,
        Float32x4,
        Uint32,
        Uint32x2,
        Uint32x3,
        Uint32x4,
        Sint32,
        Sint32x2,
        Sint32x3,
        Sint32x4,
    END

    ENUM(VertexStepMode)
        Vertex,
        Instance,
        VertexBufferNotUsed,
    END

    ENUM(BufferUsage)
        None,
        MapRead,
        MapWrite,
        CopySrc,
        CopyDst,
        Index,
        Vertex,
        Uniform,
        Storage,
        Indirect,
        QueryResolve,
    END

    ENUM(BufferUsageFlags)
    END

    ENUM(ColorWriteMask)
        None,
        Red,
        Green,
        Blue,
        Alpha,
        All,
    END

    ENUM(ColorWriteMaskFlags)
    END

    ENUM(MapMode)
        None,
        Read,
        Write,
    END

    ENUM(MapModeFlags)
    END

    ENUM(ShaderStage)
        None,
        Vertex,
        Fragment,
        Compute,
    END

    ENUM(ShaderStageFlags)
    END

    ENUM(TextureUsage)
        None,
        CopySrc,
        CopyDst,
        TextureBinding,
        StorageBinding,
        RenderAttachment,
    END

    ENUM(TextureUsageFlags)
    END

    // STRUCTURES

    namespace {
        struct DefaultIntoImpl {
            template <typename To, typename From>
            static inline auto into(From* from) -> To* {
                return (To*)from;
            }
        };
    } // namespace hidden

    #define STRUCT_INTO_IMPL(Type, Impl) \
        struct Type { \
            using Self = Type; \
            using WSelf = WGPU ## Type; \
            inline auto into() -> WSelf* { return Impl::into<WSelf>(this); } \

    #define STRUCT(Type) STRUCT_INTO_IMPL(Type, DefaultIntoImpl)

    STRUCT(ChainedStruct)
        ChainedStruct const* next;
        SType s_type;
    END

    STRUCT(ChainedStructOut)
        ChainedStructOut* next;
    END

    STRUCT(BlendComponent)
        BlendOperation operation;
        BlendFactor src_factor;
        BlendFactor dst_factor;
    END

    STRUCT(Color)
        double r;
        double g;
        double b;
        double a = 1.0;
    END

    STRUCT(ComputePassTimestampWrite)
        QuerySet query_set;
        uint32_t query_idx;
        ComputePassTimestampLocation location;
    END

    STRUCT(Extent3D)
        uint32_t width;
        uint32_t height;
        uint32_t depth_or_array_layers;
    END

    STRUCT(Limits)
        uint32_t max_texture_dimension_1D;
        uint32_t max_texture_dimension_2D;
        uint32_t max_texture_dimension_2D;
        uint32_t max_texture_array_layers;
        uint32_t max_bind_groups;
        uint32_t max_bindings_per_bind_groups;
        uint32_t max_dynamix_uniform_buffers_per_pipeline_layout;
        uint32_t max_dynamix_storage_buffers_per_pipeline_layout;
        uint32_t max_sampled_textures_per_shader_stage;
        uint32_t max_samplers_per_shader_stage;
        uint32_t max_storage_buffers_per_shader_stage;
        uint32_t max_storage_textures_per_shader_stage;
        uint32_t max_uniform_buffers_per_shader_stage;
        uint64_t max_uniform_buffer_binding_size;
        uint64_t max_storage_buffer_binding_size;
        uint32_t min_uniform_buffer_offset_alignment;
        uint32_t min_storage_buffer_offset_alignment;
        uint32_t max_vertex_buffers;
        uint64_t max_buffer_size;
        uint32_t max_vertex_attributes;
        uint32_t max_vertex_buffer_array_stride;
        uint32_t max_inter_stage_shader_components;
        uint32_t max_inter_stage_shader_variables;
        uint32_t max_color_attachments;
        uint32_t max_color_attachment_bytes_per_sample;
        uint32_t max_compute_workgroup_size_x;
        uint32_t max_compute_workgroup_size_y;
        uint32_t max_compute_workgroup_size_z;
        uint32_t max_compute_workgroups_per_dimension;
    END

    STRUCT(Origin3D)
        uint32_t x;
        uint32_t y;
        uint32_t z;
    END

    STRUCT(PrimitiveDepthClipControl)
        ChainedStruct chain;
        bool unclipped_depth;
    END

    STRUCT(RenderPassDepthStencilAttachment)
        TextureView view;
        LoadOp depth_load_op;
        StoreOp depth_store_op;
        float depth_clear_value;
        bool depth_read_only;
        LoadOp stencil_load_op;
        StoreOp stencil_store_op;
        uint32_t stencil_clear_value;
        bool stencil_read_only;
    END

    STRUCT(RenderPassDescriptorMaxDrawCount)
        ChainedStruct chain;
        uint64_t max_draw_count;
    END

    STRUCT(RenderPassTimestampWrite)
        QuerySet query_set;
        uint32_t query_idx;
        RenderPassTimestampLocation location;
    END

    STRUCT(ShaderModuleSPIRVDescriptor)
        ChainedStruct chain;
        char const* code;
    END

    STRUCT(ShaderModuleWGSLDescriptor)
        ChainedStruct chain;
        char const* code;
    END

    STRUCT(StencilFaceState)
        CompareFunction compare;
        StencilOperation fail_op;
        StencilOperation depth_fail_op;
        StencilOperation pass_op;
    END

    template <typename Window>
    STRUCT(SurfaceDescriptorFromAndroidNativeWindow)
        ChainedStruct chain;
        Window* window;
    END

    STRUCT(SurfaceDescriptorFromCanvasHTMLSelector)
        ChainedStruct chain;
        char const* selector;
    END

    template <typename Layer>
    STRUCT(SurfaceDescriptorFromMetaLayer)
        ChainedStruct chain;
        Layer* layer;
    END

    template <typename Display, typename Surface>
    STRUCT(WGPUSurfaceDescriptorFromWaylandSurface)
        ChainedStruct chain;
        Display* display;
        Surface* surface;
    END

    template <typename HInstance, typename HWND>
    STRUCT(SurfaceDescriptorFromWindowsHWND)
        ChainedStruct chain;
        HInstance* hinstance;
        HWND* hwnd;
    END

    template <typename Conn>
    STRUCT(WGPUSurfaceDescriptorFromXcbWindow)
        ChainedStruct chain;
        Conn* connection;
        uint32_t window;
    END

    STRUCT(VertexAttribute)
        VertexFormat format;
        uint64_t offset;
        uint32_t shader_location;
    END

    STRUCT(BlendState)
        BlendComponent color;
        BlendComponent alpha;
    END

    STRUCT(RenderPassColorAttachment)
        TextureView view;
        TextureView view;
        LoadOp load_op;
        StoreOp store_op;
        Color clear_value;
    END

    STRUCT(VertexBufferLayout)
        uint64_t array_stride;
        VertexStepMode step_mode;
        size_t attribute_count;
        VertexAttribute const* attributes;
    END

    // DESCRIPTORS
    #define DESCRIPTOR(Type) \
        STRUCT(Type) \
        ChainedStructOut* next_in_chain{}; \

    #define DESCRIPTOR_CONST(Type) \
        STRUCT(Type) \
        ChainedStruct const* next_in_chain{}; \


    DESCRIPTOR(AdapterProperties)
        uint32_t vendor_id;
        char const* vendor_name;
        char const* architecture;
        uint32_t device_id;
        char const* name;
        char const* driver_description;
        AdapterType adapterType;
        BackendType backendType;
    END

    DESCRIPTOR_CONST(BindGroupEntry)
        uint32_t binding;
        Buffer buffer;
        uint64_t offset;
        uint64_t size;
        Sampler sampler;
        TextureView texture_view;
    END

    DESCRIPTOR_CONST(BufferBindingLayout)
        BufferBindingType type;
        bool has_dynamic_offset;
        uint64_t min_binding_size;
    END

    DESCRIPTOR_CONST(BufferDescriptor)
        char const* label;
        BufferUsageFlags usage;
        uint64_t size;
        bool mapped_at_creation;
    END

    DESCRIPTOR_CONST(CommandBufferDescriptor)
        char const* label;
    END

    DESCRIPTOR_CONST(CommandEncoderDescriptor)
        char const* label;
    END

    DESCRIPTOR_CONST(CompilationMessage)
        char const* message;
        CompilationMessageType type;
        uint64_t line_nun;
        uint64_t line_pos;
        uint64_t offset;
        uint64_t length;
        uint64_t utf16_line_pos;
        uint64_t uif16_length;
    END

    DESCRIPTOR_CONST(ConstantEntry)
        char const* key;
        double value;
    END

    DESCRIPTOR_CONST(InstanceDescriptor)
    END

    DESCRIPTOR_CONST(MultisampleState)
        uint32_t count;
        uint32_t mask;
        bool alpha_to_coverage_enabled;
    END

    DESCRIPTOR_CONST(PipelineLayoutDescriptor)
        char const* label;
        size_t bind_group_layout_count;
        BindGroupLayout const* bind_group_layouts;
    END

    DESCRIPTOR_CONST(PrimitiveState)
        PrimitiveTopology topology;
        IndexFormat strip_index_format;
        FrontFace front_face;
        CullMode cull_mode;
    END

    DESCRIPTOR_CONST(QuerySetDescriptor)
        char const* label;
        QueryType type;
        uint32_t count;
        PipelineStatisticsName const* pipeline_statistics;
        size_t pipeline_statistics_count;
    END

    DESCRIPTOR_CONST(QueueDescriptor)
        char const* label;
    END

    DESCRIPTOR_CONST(RenderBundleDescriptor)
        char const* label;
    END

    DESCRIPTOR_CONST(RenderBundleEncoderDescriptor)
        char const* label;
        size_t color_formats_count;
        TextureFormat const* color_formats;
        TextureFormat depth_stencil_format;
        uint32_t sample_count;
        bool depth_readonly;
        bool stenci_readonly;
    END

    DESCRIPTOR_CONST(RequestAdapterOptions)
        Surface compatible_surface;
        PowerPreference power_prefernce;
        BackendType backend_type;
        bool force_fallback_adapter;
    END

    DESCRIPTOR_CONST(SamplerBindingLayout)
        SamplerBindingType type;
    END

    DESCRIPTOR_CONST(SamplerDescriptor)
        char const* label;
        AddressMode address_mode_u;
        AddressMode address_mode_v;
        AddressMode address_mode_w;
        FilterMode mag_filter;
        FilterMode min_filter;
        MipmapFilterMode mipmapFilter;
        float lodMinClamp;
        float lodMaxClamp;
        CompareFunction compare;
        uint16_t max_anisotropy;
    END

    DESCRIPTOR_CONST(ShaderModuleCompilationHint)
        char const* entry_point;
        PipelineLayout layout;
    END

    DESCRIPTOR_CONST(StorageTextureBindingLayout)
        StorageTextureAccess access;
        TextureFormat format;
        TextureViewDimension view_dimension;
    END

    DESCRIPTOR_CONST(SurfaceDescriptor)
        char const* label;
    END

    DESCRIPTOR_CONST(SwapChainDescriptor)
        char const* label;
        TextureUsageFlags usage;
        TextureFormat format;
        uint32_t width;
        uint32_t height;
        PresentMode present_mode;
    END

    DESCRIPTOR_CONST(TextureBindingLayout)
        TextureSampleType sample_type;
        TextureViewDimension view_dimension;
        bool multisampled;
    END

    DESCRIPTOR_CONST(TextureDataLayout)
        uint64_t offset;
        uint32_t bytes_per_row;
        uint32_t rows_per_image;
    END

    DESCRIPTOR_CONST(TextureViewDescriptor)
        char const* label;
        TextureFormat format;
        TextureViewDimension dimension;
        uint32_t base_mip_level;
        uint32_t mip_lebel_count;
        uint32_t base_array_layer;
        uint32_t array_layer_count;
        TextureAspect aspect;
    END

    DESCRIPTOR_CONST(BindGroupDescriptor)
        char const* label;
        BindGroupLayout layout;
        size_t entryCount;
        BindGroupEntry const* entries;
    END

    DESCRIPTOR_CONST(BindGroupLayoutEntry)
        uint32_t binding;
        ShaderStageFlags visibility;
        BufferBindingLayout buffer;
        SamplerBindingLayout sampler;
        TextureBindingLayout texture;
        StorageTextureBindingLayout storage_texture;
    END

    DESCRIPTOR_CONST(CompilationInfo)
        size_t message_count;
        CompilationMessage const* messages;
    END

    DESCRIPTOR_CONST(ComputePassDescriptor)
        char const* label;
        size_t timestamp_write_count;
        ComputePassTimestampWrite const* timestamp_writes;
    END

    DESCRIPTOR_CONST(DepthStencilState)
        TextureFormat format;
        bool depth_write_enabled;
        CompareFunction depth_compare;
        StencilFaceState stencil_front;
        StencilFaceState stencil_back;
        uint32_t stencil_read_mask;
        uint32_t stencil_write_mask;
        int32_t depth_bias;
        float depth_bias_slope_scale;
        float depth_bias_clamp;
    END

    DESCRIPTOR_CONST(ImageCopyBuffer)
        TextureDataLayout layout;
        Buffer buffer;
    END

    DESCRIPTOR_CONST(ImageCopyTexture)
        Texture texture;
        uint32_t mip_level;
        Origin3D origin;
        TextureAspect aspect;
    END

    DESCRIPTOR_CONST(ProgrammableStageDescriptor)
        ShaderModule module;
        size_t constant_count;
        ConstantEntry const* constants;
    END

    DESCRIPTOR_CONST(RequiredLimits)
        Limits limits;
    END

    // HANDLES

    #define HANDLE(Type) \
        STRUCT(Type) \
        inline auto reference() -> void; \
        inline auto release() -> void; \

} // namespace wgpu