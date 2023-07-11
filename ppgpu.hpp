#pragma once

#include <memory>

extern "C" {
    #include <glfw3webgpu/glfw3webgpu.h>
}

#ifndef WEBGPU_H_ 
#error "Make sure to include the WEBGPU C header prior to this."
#endif

#define WGPU_TARGET_MACOS 1
#define WGPU_TARGET_LINUX_X11 2
#define WGPU_TARGET_WINDOWS 3
#define WGPU_TARGET_WAYLAND 4

#if defined(_WIN32)
#define WGPU_TARGET WGPU_TARGET_WINDOWS
#elif defined(__APPLE__)
#define WGPU_TARGET WGPU_TARGET_MACOS
#else
#define WGPU_TARGET WGPU_TARGET_LINUX_X11
#endif

#include <type_traits>
#include <iostream>

using CStr = char const*;

namespace wgpu {
    
    #define END };

    static constexpr auto ARRAY_LAYER_COUNT_UNDEFINED = 0xffffffffUL;
    static constexpr auto COPY_STRIDE_UNDEFINED = 0xffffffffUL;
    static constexpr auto LIMIT_U32_UNDEFINED = 0xffffffffUL;
    static constexpr auto LIMIT_U64_UNDEFINED = 0xffffffffffffffffULL;
    static constexpr auto MIP_LEVEL_COUNT_UNDEFINED = 0xffffffffUL;
    static constexpr auto WHOLE_MAP_SIZE = SIZE_MAX;
    static constexpr auto WHOLE_SIZE = 0xffffffffffffffffULL;

    using Flags = uint32_t;

    // STRUCTURE FORWARD DECLARATIONS
    struct AdapterProperties;
    struct BindGroupEntry;
    struct BlendComponent;
    struct BufferBindingLayout;
    struct BufferDescriptor;
    struct Color;
    struct CommandBufferDescriptor;
    struct CommandEncoderDescriptor;
    struct CompilationMessage;
    struct ComputePassTimestampWrite;
    struct ConstantEntry;
    struct Extent3D;
    struct InstanceDescriptor;
    struct Limits;
    struct MultisampleState;
    struct Origin3D;
    struct PipelineLayoutDescriptor;
    struct PrimitiveDepthClipControl;
    struct PrimitiveState;
    struct QuerySetDescriptor;
    struct QueueDescriptor;;
    struct RenderBundleDescriptor;
    struct RenderBundleEncoderDescriptor;
    struct RenderPassDepthStencilAttachment;
    struct RenderPassDescriptorMaxDrawCount;
    struct RenderPassTimestampWrite;
    struct RequestAdapterOptions;
    struct SamplerBindingLayout;
    struct SamplerDescriptor;
    struct ShaderModuleCompilationHint;
    struct ShaderModuleSPIRVDescriptor;
    struct ShaderModuleWGSLDescriptor;
    struct StencilFaceState;
    struct StorageTextureBindingLayout;
    struct SurfaceDescriptor;
    struct SurfaceDescriptorFromAndroidNativeWindow;
    struct SurfaceDescriptorFromCanvasHTMLSelector;
    struct SurfaceDescriptorFromMetalLayer;
    struct SurfaceDescriptorFromWaylandSurface;
    struct SurfaceDescriptorFromWindowsHWND;
    struct SurfaceDescriptorFromXcbWindow;
    struct SurfaceDescriptorFromXlibWindow;
    struct SwapChainDescriptor;
    struct TextureBindingLayout;
    struct TextureDataLayout;
    struct TextureViewDescriptor;
    struct VertextAttribute;
    struct BindGroupDescriptor;
    struct BindGroupLayoutEntry;
    struct BlendState;
    struct CompilationInfo;
    struct ComputePassDescriptor;
    struct DepthStencilState;
    struct ImageCopyBuffer;
    struct ImageCopyTexture;
    struct ProgrammableStageDescriptor;
    struct RenderPassColorAttachment;
    struct RequiredLimits;
    struct ShaderModuleDescriptor;
    struct SupportedLimits;
    struct TextureDescriptor;
    struct VertexBufferLayout;
    struct BindGroupLayoutDescriptor;
    struct ColorTargetState;
    struct ComputePipelineDescriptor;
    struct DeviceDescriptor;
    struct RenderPassDescriptor;
    struct VertexState;
    struct RenderPipelineDescriptor;

    namespace impl {
        using Adapter = WGPUAdapterImpl*;
        using BindGroup = WGPUBindGroupImpl*;
        using BindGroupLayout = WGPUBindGroupLayoutImpl*;
        using Buffer = WGPUBufferImpl*;
        using CommandBuffer = WGPUCommandBufferImpl*;
        using CommandEncoder = WGPUCommandEncoderImpl*;
        using ComputePassEncoder = WGPUComputePassEncoderImpl*;
        using ComputePipeline = WGPUComputePipelineImpl*;
        using Device = WGPUDeviceImpl*;
        using Instance = WGPUInstanceImpl*;
        using PipelineLayout = WGPUPipelineLayoutImpl*;
        using QuerySet = WGPUQuerySetImpl*;
        using Queue = WGPUQueueImpl*;
        using RenderBundle = WGPURenderBundleImpl*;
        using RenderBundleEncoder = WGPURenderBundleEncoderImpl*;
        using RenderPassEncoder = WGPURenderPassEncoderImpl*;
        using RenderPipeline = WGPURenderPipelineImpl*;
        using Sampler = WGPUSamplerImpl*;
        using ShaderModule = WGPUShaderModuleImpl*;
        using Surface = WGPUSurfaceImpl*;
        using SwapChain = WGPUSwapChainImpl*;
        using Texture = WGPUTextureImpl*;
        using TextureView = WGPUTextureViewImpl*;
    } // namespace impl

    // ENUMERATIONS

    #define ENUM(Name) enum class Name {

    template <typename T>
    static constexpr auto Force32() -> T {
        return static_cast<T>(0x7FFFFFFF);
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
        Undefined = 0x00000000,
        Null = 0x00000001,
        WebGPU = 0x00000002,
        D3D11 = 0x00000003,
        D3D12 = 0x00000004,
        Metal = 0x00000005,
        Vulkan = 0x0000006,
        OpenGL = 0x00000007,
        OpenGLES = 0x00000008,
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

    ENUM(CompilationInfoRequestStatus)
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
        SurfaceDescriptorFromMetalLayer,
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
        Vertex = 0x00000000,
        Instance = 0x00000001,
        VertexBufferNotUsed = 0x00000002,
    END

    ENUM(BufferUsage)
        None = 0x00000000,
        MapRead = 0x00000001,
        MapWrite = 0x00000002,
        CopySrc = 0x00000004,
        CopyDst = 0x00000008,
        Index = 0x00000010,
        Vertex = 0x00000020,
        Uniform = 0x00000040,
        Storage = 0x00000080,
        Indirect = 0x00000100,
        QueryResolve = 0x00000200,
    END

    ENUM(BufferUsageFlags)
    END

    ENUM(ColorWriteMask)
        None = 0x00000000,
        Red = 0x00000001,
        Green = 0x00000002,
        Blue = 0x00000004,
        Alpha = 0x00000008,
        All = 0x00000010,
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
        None = 0x00000000,
        Vertex = 0x00000001,
        Fragment = 0x00000002,
        Compute = 0x00000004,
    END

    ENUM(ShaderStageFlags)
    END

    ENUM(TextureUsage)
        None = 0x00000000,
        CopySrc = 0x00000001,
        CopyDst = 0x00000002,
        TextureBinding = 0x00000004,
        StorageBinding = 0x00000008,
        RenderAttachment = 0x00000010,
    END

    ENUM(TextureUsageFlags)
    END

    ENUM(NativeSType)
        DeviceExtras = 0x60000001,
        AdapterExtras = 0x60000002,
        RequiredLimitsExtras = 0x60000003,
        PipelineLimitsExtras = 0x60000004,
        ShaderModuleGLSLDescriptor = 0x60000005,
        SupportedLimitsExtras = 0x60000003,
        InstanceExtras = 0x60000006,
        SwapChainDeviceDescriptorExtras = 0x60000007,
    END

    ENUM(NativeFeature)
        PushConstants = 0x60000001,
        TextureAdapterSpecificFormatFeatures = 0x60000002,
        MultiDrawIndirect = 0x60000003,
        MultiDrawIndirectCount = 0x60000004,
        VertexWritableStorage = 0x60000005,
    END

    ENUM(LogLevel)
        Off,
        Error,
        Warn,
        Info,
        Debug,
        Trace,
    END

    ENUM(InstanceBackend)
        Vulkan = 1,
        GL = 1,
        Metal = 1,
        DX12 = 1,
        DX11 = 1,
        BrowserWebGPU = 1,
        Primary = InstanceBackend::Vulkan,
        Secondary = InstanceBackend::GL,
        None = 0,
    END

    ENUM(DX12Compiler)
        Undefined,
        Fxc,
        Dxc,
    END

    ENUM(CompositeAlphaMode)
        Auto,
        Opaque,
        PreMultiplied,
        PostMultiplied,
        Inherit,
    END


    // PLATFORM DEFAULTS

    template <typename T>
    static constexpr T PlatformDefault;

    template <>
    static constexpr auto PlatformDefault<BackendType> = (
        #if WGPU_TARGET == WGPU_TARGET_MACOS
            BackendType::Metal
        #elif WGPU_TARGET == WGPU_TARGET_WINDOWS
            BackendType::D3D12
        #else
            BackendType::Vulkan
        #endif
    );

    template <>
    static constexpr auto PlatformDefault<SType> = (
        #if WGPU_TARGET == WGPU_TARGET_MACOS
            SType::SurfaceDescriptorFromMetalLayer
        #elif WGPU_TARGET == WGPU_TARGET_WINDOWS
            SType::SurfaceDescriptorFromWindowsHWND
        #elif WGPU_TARGET == WGPU_TARGET_LINUX_X11
            SType::SurfaceDescriptorFromXlibWindow
        #elif WGPU_TARGET == WGPU_TARGET_WAYLAND
            SType::SurfaceSurfaceDescriptorFromWaylandSurface
        #else
            SType::Invalid
        #endif
    );

    template<>
    static constexpr auto PlatformDefault<InstanceBackend> = (
        #if WGPU_TARGET == WGPU_TARGET_MACOS
            InstanceBackend::Metal
        #elif WGPU_TARGET == WGPU_TARGET_WINDOWS
            InstanceBackend::Windows
        #else
            InstanceBackend::Vulkan
        #endif
    );

    // STRUCTURES
    
    template <typename To, typename From>
    concept NonAggregateWGPUCompatible =
        std::is_standard_layout_v<To> &&
        std::is_standard_layout_v<From> &&
        sizeof(To) == sizeof(From);

    template <typename To, typename From> 
    concept WGPUCompatible = 
        NonAggregateWGPUCompatible<To, From> &&
        std::is_trivial_v<To>;

    template <typename T>
    using RawType = std::remove_cv_t<std::remove_pointer_t<std::remove_reference_t<T>>>;

    struct DefaultWGPUCast {
        template <typename To, typename From>
        static inline auto cast(From val) -> To {
            static_assert(WGPUCompatible<RawType<To>, RawType<From>>);
            return reinterpret_cast<To>(val);
        } 
    };

    struct NonAggregateWGPUCast {
        template <typename To, typename From>
        static inline auto cast(From val) -> To {
            static_assert(NonAggregateWGPUCompatible<RawType<To>, RawType<From>>);
            return reinterpret_cast<To>(val);
        }
    };

    #define _WGPU_H_COMPAT

#ifdef _WGPU_H_COMPAT
    #define STRUCT_CAST_IMPL(Name, Cast) \
        struct Name { \
            using WSelf = WGPU ## Name; \
            inline operator WSelf*() noexcept { return Cast::template cast<WSelf*>(this); } \
            inline operator WSelf const*() const noexcept { return Cast::template cast<WSelf const*>(this); }
#else // _WGPU_H_COMPAT
    #define STRUCT_CAST_IMPL(Name, _) struct Name {
#endif // _WGPU_H_COMPAT
    
    #define STRUCT(Name) STRUCT_CAST_IMPL(Name, DefaultWGPUCast)
    #define STRUCT_NON_AGGREGATE(Name) STRUCT_CAST_IMPL(Name, NonAggregateWGPUCast)

    STRUCT(ChainedStruct)
        ChainedStruct const* next {};
        SType s_type{};
    END

    STRUCT(ChainedStructOut)
        ChainedStructOut* next {};
        SType s_type {};
    END

    STRUCT(BlendComponent)
        BlendOperation operation = BlendOperation::Add;
        BlendFactor src_factor = BlendFactor::One;
        BlendFactor dst_factor = BlendFactor::Zero;
    END

    STRUCT(Color)
        double r {};
        double g {};
        double b {};
        double a = 1.0;
    END

    STRUCT(ComputePassTimestampWrite)
        impl::QuerySet query_set {};
        uint32_t query_idx {};
        ComputePassTimestampLocation location {};
    END

    STRUCT(Extent3D)
        uint32_t width {};
        uint32_t height = 1;
        uint32_t depth_or_array_layers = 1;
    END

    STRUCT(Limits)
        uint32_t max_texture_dimension_1D {};
        uint32_t max_texture_dimension_2D {};
        uint32_t max_texture_dimension_3D {};
        uint32_t max_texture_array_layers {};
        uint32_t max_bind_groups {};
        uint32_t max_bindings_per_bind_group {};
        uint32_t max_dynamic_uniform_buffers_per_pipeline_layout {};
        uint32_t max_dynamic_storage_buffers_per_pipeline_layout {};
        uint32_t max_sampled_textures_per_shader_stage {};
        uint32_t max_samplers_per_shader_stage {};
        uint32_t max_storage_buffers_per_shader_stage {};
        uint32_t max_storage_textures_per_shader_stage {};
        uint32_t max_uniform_buffers_per_shader_stage {};
        uint64_t max_uniform_buffer_binding_size {};
        uint64_t max_storage_buffer_binding_size {};
        uint32_t min_uniform_buffer_offset_alignment = 64;
        uint32_t min_storage_buffer_offset_alignment = 16;
        uint32_t max_vertex_buffers {};
        uint64_t max_buffer_size {};
        uint32_t max_vertex_attributes {};
        uint32_t max_vertex_buffer_array_stride {};
        uint32_t max_inter_stage_shader_components {};
        uint32_t max_inter_stage_shader_variables {};
        uint32_t max_color_attachments {};
        uint32_t max_color_attachment_bytes_per_sample {};
        uint32_t max_compute_workgroup_storage_size {};
        uint32_t max_compute_invocations_per_workgroup {};
        uint32_t max_compute_workgroup_size_x {};
        uint32_t max_compute_workgroup_size_y {};
        uint32_t max_compute_workgroup_size_z {};
        uint32_t max_compute_workgroups_per_dimension {};
    END

    STRUCT(Origin3D)
        uint32_t x {};
        uint32_t y {};
        uint32_t z {};
    END

    STRUCT(PrimitiveDepthClipControl)
        ChainedStruct chain = { .s_type = SType::PrimitiveDepthClipControl };
        bool unclipped_depth {};
    END

    STRUCT(RenderPassDepthStencilAttachment)
        impl::TextureView view {};
        LoadOp depth_load_op = LoadOp::Undefined;
        StoreOp depth_store_op = StoreOp::Undefined;
        float depth_clear_value {};
        bool depth_read_only = {};
        LoadOp stencil_load_op = LoadOp::Undefined;
        StoreOp stencil_store_op = StoreOp::Undefined;
        uint32_t stencil_clear_value {};
        bool stencil_read_only = {};
    END

    STRUCT(RenderPassDescriptorMaxDrawCount)
        ChainedStruct chain = { .s_type = SType::RenderPassDescriptorMaxDrawCount };
        uint64_t max_draw_count;
    END

    STRUCT(RenderPassTimestampWrite)
        impl::QuerySet query_set {};
        uint32_t query_idx {};
        RenderPassTimestampLocation location {};
    END

    STRUCT(ShaderModuleSPIRVDescriptor)
        ChainedStruct chain = { .s_type = SType::ShaderModuleSPIRVDescriptor };
        uint32_t code_size {};
        uint32_t const* code {};
    END

    STRUCT(ShaderModuleWGSLDescriptor)
        ChainedStruct chain = { .s_type = SType::ShaderModuleWGSLDescriptor };
        CStr code;
    END

    STRUCT(StencilFaceState)
        CompareFunction compare = CompareFunction::Always;
        StencilOperation fail_op = StencilOperation::Keep;
        StencilOperation depth_fail_op = StencilOperation::Keep;
        StencilOperation pass_op = StencilOperation::Keep;
    END

    STRUCT(SurfaceDescriptorFromAndroidNativeWindow)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromAndroidNativeWindow };
        void* window {};
    END

    STRUCT(SurfaceDescriptorFromCanvasHTMLSelector)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromCanvasHTMLSelector };
        CStr selector {};
    END

    STRUCT(SurfaceDescriptorFromMetalLayer)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromMetalLayer };
        void* layer {};
    END

    STRUCT(SurfaceDescriptorFromWaylandSurface)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromWaylandSurface };
        void* display {};
        void* surface {};
    END

    STRUCT(SurfaceDescriptorFromWindowsHWND)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromWindowsHWND };
        void* hinstance {};
        void* hwnd {};
    END

    STRUCT(SurfaceDescriptorFromXcbWindow)
        ChainedStruct chain = { .s_type = SType::SurfaceDescriptorFromXcbWindow };
        void* connection {};
        uint32_t window {};
    END

    STRUCT(VertexAttribute)
        VertexFormat format = VertexFormat::Undefined;
        uint64_t offset {};
        uint32_t shader_location {};
    END

    STRUCT(BlendState)
        BlendComponent color {};
        BlendComponent alpha {};
    END

    STRUCT(RenderPassColorAttachment)
        impl::TextureView view {};
        impl::TextureView resolve_target {};
        LoadOp load_op = LoadOp::Undefined;
        StoreOp store_op = StoreOp::Undefined;
        Color clear_value {};
    END

    STRUCT(VertexBufferLayout)
        uint64_t array_stride {};
        VertexStepMode step_mode = VertexStepMode::Vertex;
        size_t attribute_count {};
        VertexAttribute const* attributes {};
    END

    // CALLBACKS
    using BufferMapCallback = auto(*)(BufferMapAsyncStatus) -> void;
    using CompilationInfoCallback = auto(*)(CompilationInfoRequestStatus status, CompilationInfo& compilation_info, void* user_data) -> void;
    using CreateComputePipelineAsyncCallback = auto(*)(CreatePipelineAsyncStatus status, impl::ComputePipeline pipeline, CStr msg, void* user_data) -> void;
    using CreateRenderPipelineAsyncCallback = auto(*)(CreatePipelineAsyncStatus status, impl::RenderPipeline pipeline, CStr msg, void* user_data) -> void;
    using DeviceLostCallback = auto(*)(DeviceLostReason reason, CStr msg, void* user_data) -> void;
    using ErrorCallback = auto(*)(ErrorType type, CStr msg, void* user_data) -> void;
    using QueueWorkDoneCallback = auto(*)(QueueWorkDoneStatus status) -> void;
    using RequestAdapterCallback = auto(*)(RequestAdapterStatus status, impl::Adapter adapter, CStr msg, void* user_data) -> void;
    using RequestDeviceCallback = auto(*)(RequestDeviceStatus status, impl::Device device, CStr msg, void* user_data) -> void;
    using ProcDeviceSetUncapturedErrorCallback = auto(*)(impl::Device device, ErrorCallback&& callback, void* user_data) -> void;
    using LogCallback = auto(*)(LogLevel level, CStr msg) -> void;

    // DESCRIPTORS
    #define DESCRIPTOR(Type) \
        STRUCT(Type) \
        ChainedStructOut* next_in_chain{}; \

    #define DESCRIPTOR_CONST(Type) \
        STRUCT(Type) \
        ChainedStruct const* next_in_chain{}; \


    DESCRIPTOR(AdapterProperties)
        uint32_t vendor_id {};
        CStr vendor_name {};
        CStr architecture {};
        uint32_t device_id {};
        CStr name {};
        CStr driver_description {};
        AdapterType adapterType {};
        BackendType backendType = PlatformDefault<BackendType>;
    END

    DESCRIPTOR_CONST(BindGroupEntry)
        uint32_t binding {};
        impl::Buffer buffer {};
        uint64_t offset {};
        uint64_t size {};
        impl::Sampler sampler {};
        impl::TextureView texture_view {};
    END

    DESCRIPTOR_CONST(BufferBindingLayout)
        BufferBindingType type = BufferBindingType::Uniform;
        bool has_dynamic_offset {};
        uint64_t min_binding_size {};
    END

    DESCRIPTOR_CONST(BufferDescriptor)
        CStr label {};
        BufferUsageFlags usage {};
        uint64_t size {};
        bool mapped_at_creation {};
    END

    DESCRIPTOR_CONST(CommandBufferDescriptor)
        CStr label {};
    END

    DESCRIPTOR_CONST(CommandEncoderDescriptor)
        CStr label {};
    END

    DESCRIPTOR_CONST(CompilationMessage)
        CStr message {};
        CompilationMessageType type {};
        uint64_t line_nun {};
        uint64_t line_pos {};
        uint64_t offset {};
        uint64_t length {};
        uint64_t utf16_line_pos {};
        uint64_t utf16_offset {};
        uint64_t uif16_length {};
    END

    DESCRIPTOR_CONST(ConstantEntry)
        CStr key {};
        double value {};
    END

    DESCRIPTOR_CONST(InstanceDescriptor)
    END

    DESCRIPTOR_CONST(MultisampleState)
        uint32_t count = 1;
        uint32_t mask = 0xFFFFFFFF;
        bool alpha_to_coverage_enabled {};
    END

    DESCRIPTOR_CONST(PipelineLayoutDescriptor)
        CStr label {};
        size_t bind_group_layout_count {};
        impl::BindGroupLayout const bind_group_layouts {};
    END

    DESCRIPTOR_CONST(PrimitiveState)
        PrimitiveTopology topology = PrimitiveTopology::TriangleList;
        IndexFormat strip_index_format = IndexFormat::Undefined;
        FrontFace front_face = FrontFace::CCW;
        CullMode cull_mode = CullMode::None;
    END

    DESCRIPTOR_CONST(QuerySetDescriptor)
        CStr label {};
        QueryType type {};
        uint32_t count {};
        PipelineStatisticsName const* pipeline_statistics {};
        size_t pipeline_statistics_count {};
    END

    DESCRIPTOR_CONST(QueueDescriptor)
        CStr label {};
    END

    DESCRIPTOR_CONST(RenderBundleDescriptor)
        CStr label {};
    END

    DESCRIPTOR_CONST(RenderBundleEncoderDescriptor)
        CStr label {};
        size_t color_formats_count {};
        TextureFormat const* color_formats {};
        TextureFormat depth_stencil_format = TextureFormat::Undefined;
        uint32_t sample_count = 1;
        bool depth_readonly {};
        bool stenci_readonly {};
    END

    DESCRIPTOR_CONST(RequestAdapterOptions)
        impl::Surface compatible_surface {};
        PowerPreference power_prefernce = PowerPreference::Undefined;
        BackendType backend_type = PlatformDefault<BackendType>;
        bool force_fallback_adapter {};
    END

    DESCRIPTOR_CONST(SamplerBindingLayout)
        SamplerBindingType type = SamplerBindingType::Filtering;
    END

    DESCRIPTOR_CONST(SamplerDescriptor)
        CStr label {};
        AddressMode address_mode_u = AddressMode::ClampToEdge;
        AddressMode address_mode_v = AddressMode::ClampToEdge;
        AddressMode address_mode_w = AddressMode::ClampToEdge;
        FilterMode mag_filter = FilterMode::Nearest;
        FilterMode min_filter = FilterMode::Nearest;
        MipmapFilterMode mipmapFilter = MipmapFilterMode::Nearest;
        float lodMinClamp {};
        float lodMaxClamp = 32.0;
        CompareFunction compare = CompareFunction::Undefined;
        uint16_t max_anisotropy {};
    END

    DESCRIPTOR_CONST(ShaderModuleCompilationHint)
        CStr entry_point {};
        impl::PipelineLayout layout {};
    END

    DESCRIPTOR_CONST(StorageTextureBindingLayout)
        StorageTextureAccess access = StorageTextureAccess::WriteOnly;
        TextureFormat format = TextureFormat::Undefined;
        TextureViewDimension view_dimension = TextureViewDimension::D2;
    END

    DESCRIPTOR_CONST(SurfaceDescriptor)
        CStr label {};
    END

    DESCRIPTOR_CONST(SwapChainDescriptor)
        CStr label {};
        TextureUsageFlags usage {};
        TextureFormat format = TextureFormat::Undefined;
        uint32_t width {};
        uint32_t height {};
        PresentMode present_mode {};
    END

    DESCRIPTOR_CONST(TextureBindingLayout)
        TextureSampleType sample_type = TextureSampleType::Float;
        TextureViewDimension view_dimension = TextureViewDimension::D2;
        bool multisampled {};
    END

    DESCRIPTOR_CONST(TextureDataLayout)
        uint64_t offset {};
        uint32_t bytes_per_row {};
        uint32_t rows_per_image {};
    END

    DESCRIPTOR_CONST(TextureViewDescriptor)
        CStr label {};
        TextureFormat format = TextureFormat::Undefined;
        TextureViewDimension dimension = TextureViewDimension::Undefined;
        uint32_t base_mip_level {};
        uint32_t mip_level_count {};
        uint32_t base_array_layer {};
        uint32_t array_layer_count {};
        TextureAspect aspect = TextureAspect::All;
    END

    DESCRIPTOR_CONST(BindGroupDescriptor)
        CStr label {};
        impl::BindGroupLayout layout {};
        size_t entryCount {};
        BindGroupEntry const* entries {};
    END

    DESCRIPTOR_CONST(BindGroupLayoutEntry)
        uint32_t binding {};
        ShaderStageFlags visibility {};
        BufferBindingLayout buffer = { .type = BufferBindingType::Undefined };
        SamplerBindingLayout sampler = { .type = SamplerBindingType::Undefined };
        TextureBindingLayout texture = { .sample_type = TextureSampleType::Undefined };
        StorageTextureBindingLayout storage_texture = { .access = StorageTextureAccess::Undefined };
    END

    DESCRIPTOR_CONST(CompilationInfo)
        size_t message_count {};
        CompilationMessage const* messages {};
    END

    DESCRIPTOR_CONST(ComputePassDescriptor)
        CStr label {};
        size_t timestamp_write_count {};
        ComputePassTimestampWrite const* timestamp_writes {};
    END

    DESCRIPTOR_CONST(DepthStencilState)
        TextureFormat format = TextureFormat::Undefined;
        bool depth_write_enabled {};
        CompareFunction depth_compare = CompareFunction::Always;
        StencilFaceState stencil_front {};
        StencilFaceState stencil_back {};
        uint32_t stencil_read_mask = 0xFFFFFFFF;
        uint32_t stencil_write_mask = 0xFFFFFFFF;
        int32_t depth_bias {};
        float depth_bias_slope_scale {};
        float depth_bias_clamp {};
    END

    DESCRIPTOR_CONST(ImageCopyBuffer)
        TextureDataLayout layout {};
        impl::Buffer buffer {};
    END

    DESCRIPTOR_CONST(ImageCopyTexture)
        impl::Texture texture {};
        uint32_t mip_level {};
        Origin3D origin {};
        TextureAspect aspect = TextureAspect::All;
    END

    DESCRIPTOR_CONST(ProgrammableStageDescriptor)
        impl::ShaderModule module {};
        CStr entry_point {};
        size_t constant_count {};
        ConstantEntry const* constants {};
    END

    DESCRIPTOR_CONST(RequiredLimits)
        Limits limits {};
    END

    DESCRIPTOR_CONST(ShaderModuleDescriptor)
        CStr label {};
        size_t hint_count {};
        ShaderModuleCompilationHint const* hints {};
    END

    DESCRIPTOR(SupportedLimits)
        Limits limits {};
    END

    DESCRIPTOR_CONST(TextureDescriptor)
        CStr label {};
        TextureUsageFlags usage {};
        TextureDimension dimension = TextureDimension::D2;
        Extent3D size {};
        TextureFormat format = TextureFormat::Undefined;
        uint32_t mipLevelCount = 1;
        uint32_t sampleCount = 1;
        size_t viewFormatCount {};
        TextureFormat const* viewFormats {};
    END

    DESCRIPTOR_CONST(BindGroupLayoutDescriptor)
        CStr label {};
        size_t entry_count {};
        BindGroupLayoutEntry const* entryies {};
    END

    DESCRIPTOR_CONST(ColorTargetState)
        TextureFormat format =  TextureFormat::Undefined;
        BlendState const* blend {};
        ColorWriteMaskFlags write_mask {};
    END

    DESCRIPTOR_CONST(ComputePipelineDescriptor)
        CStr label {};
        impl::PipelineLayout layout{};
        ProgrammableStageDescriptor compute{};
    END

    DESCRIPTOR_CONST(DeviceDescriptor)
        CStr label {};
        size_t required_features_count {};
        FeatureName const* required_features {};
        RequiredLimits const* required_limits {};
        QueueDescriptor default_queue {};
        DeviceLostCallback  device_lost_callback {}; 
        void* device_lost_user_data {};
    END

    DESCRIPTOR_CONST(RenderPassDescriptor)
        CStr label {};
        size_t color_attachment_count {};
        RenderPassColorAttachment const* color_attachments {};
        RenderPassDepthStencilAttachment const* depth_stencil_attachment {};
        impl::QuerySet occlusion_query_set {};
        size_t timestamp_write_count {};
        RenderPassTimestampWrite const* timestamp_writes {};
    END

    DESCRIPTOR_CONST(VertexState)
        impl::ShaderModule module {};
        CStr entry_point {};
        size_t constant_count {};
        ConstantEntry const* constants {};
        size_t bufferCount {};
        VertexBufferLayout const* buffers {};
    END

    DESCRIPTOR_CONST(FragmentState)
        impl::ShaderModule module {};
        CStr entry_point {};
        size_t constant_count {};
        ConstantEntry const* constants {};
        size_t target_count {};
        ColorTargetState const* targets {};
    END

    DESCRIPTOR_CONST(RenderPipelineDescriptor)
        CStr label {};
        impl::PipelineLayout layout {};
        VertexState vertex {};
        PrimitiveState primitive {};
        DepthStencilState const* depth_stencil {};
        MultisampleState multisample {};
        FragmentState const* fragment {};
    END

    // EXTERNAL DEFINITIONS
    
    extern "C" {
        auto wgpuCreateInstance(
            InstanceDescriptor const* desc
        ) -> impl::Instance;

        auto wgpuInstanceRequestAdapter(
            impl::Instance instance,
            RequestAdapterOptions const* opts,
            RequestAdapterCallback callback,
            void* user_data
        ) -> void;
    }

    // HANDLE FORWARD DECLARATIONS

    struct Adapter;
    struct BindGroup;
    struct BindGroupLayout;
    struct Buffer;
    struct CommandBuffer;
    struct CommandEncoder;
    struct ComputePassEncoder;
    struct ComputePipeline;
    struct Device;
    struct Instance;
    struct PipelineLayout;
    struct QuerySet;
    struct Queue;
    struct RenderBundle;
    struct RenderBundleEncoder;
    struct RenderPassEncoder;
    struct RenderPipeline;
    struct Sampler;
    struct ShaderModule;
    struct Surface;
    struct SwapChain;
    struct Texture;
    struct TextureView;

    // HANDLES

    #define HANDLE(Type) \
        struct Type { \
        using Impl = impl::Type; \
        [[no_unique_address]] Impl inner; \
        inline operator Impl&() { return inner; } \
        inline operator const Impl&() const { return inner; } \
        inline auto reference() -> void; \
        inline auto release() -> void; \

    HANDLE(Adapter)
        auto enumerate_features(FeatureName* features) -> size_t;
        auto get_limits(SupportedLimits* limits) -> bool;
        auto get_properties(AdapterProperties* properties) -> void;
        auto has_feature(FeatureName feature) -> bool;
        auto request_device(const DeviceDescriptor& descriptor, RequestDeviceCallback&& callback) -> std::unique_ptr<RequestDeviceCallback>;
        auto request_device(const DeviceDescriptor& descriptor) -> Device;
    END

    HANDLE(BindGroup)
        auto label(CStr label) -> void;
    END

    HANDLE(BindGroupLayout)
        auto label(CStr label) -> void;
    END

    HANDLE(Buffer)
        auto label(CStr label) -> void;
        auto destroy() -> void;
        auto get_const_mapped_range(size_t offset, size_t size) -> void const*;
        auto get_map_state() -> BufferMapState;
        auto get_size() -> uint64_t;
        auto get_usage() -> BufferUsage;
        auto map_async(
            MapModeFlags mode,
            size_t offset,
            size_t size,
            BufferMapCallback&& callback
        ) -> std::unique_ptr<BufferMapCallback>;
        auto unmap() -> void;
    END

    HANDLE(CommandBuffer)
        auto label(CStr label) -> void;
    END

    HANDLE(CommandEncoder)
        auto begin_compute_pass(const ComputePassDescriptor& descriptor) -> ComputePassEncoder;
        auto begin_render_pass(const RenderPassDescriptor& descriptor) -> RenderPassEncoder;
        auto clear_buffer(Buffer buffer, uint64_t offset, uint64_t size) -> void;
        auto copy_buffer_to_buffer(
            Buffer src,
            uint64_t src_offset,
            Buffer dest,
            uint64_t dest_offset,
            uint64_t size
        ) -> void;
        auto copy_buffer_to_texture(
            const ImageCopyBuffer& src,
            const ImageCopyTexture& dest,
            const Extent3D& size
        ) -> void;
        auto copy_texture_to_buffer(
            const ImageCopyTexture& src,
            const ImageCopyBuffer& dest,
            const Extent3D& size
        ) -> void;
        auto finish(const CommandBufferDescriptor& descriptor) -> CommandBuffer;
        auto insert_debug_marker(CStr label) -> void;
        auto pop_debug_group() -> void;
        auto push_debug_group(CStr label) -> void;
        auto resolve_query_set(
            QuerySet query_set,
            uint32_t first_query,
            uint32_t query_count,
            Buffer dest,
            uint64_t dest_offset
        ) -> void;
        auto label(CStr label) -> void;
    END

    HANDLE(ComputePassEncoder)
        auto begin_pipeline_statistics_query(QuerySet query_set, uint32_t query_idx) -> void;
        auto dispatch_workgroups(
            uint32_t workgroup_count_x,
            uint32_t workgroup_count_y,
            uint32_t workgroup_count_z
        ) -> void;
        auto dispatch_workgroups_indirect(Buffer indirect_buffer, uint64_t indirect_offset) -> void;
        auto end() -> void;
        auto end_pipeline_statistics_query() -> void;
        auto insert_debug_marker(CStr label) -> void;
        auto pop_debug_group() -> void;
        auto push_debug_group(CStr label) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            uint32_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const std::vector<uint32_t>& dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const uint32_t& dynamic_offsets
        ) -> void;
        auto label(CStr label) -> void;
        auto set_pipeline(ComputePipeline pipeline) -> void;
    END

    HANDLE(ComputePipeline)
        auto get_bind_group_layout(uint32_t group_idx) -> void;
        auto label(CStr label) -> void;
    END

    HANDLE(Device)
        auto create_bind_group(const BindGroupDescriptor& desc) -> BindGroup;
        auto create_bind_group_layout(const BindGroupLayoutDescriptor& desc) -> BindGroupLayout;
        auto create_buffer(const BufferDescriptor& desc) -> Buffer;
        auto create_command_encoder(const CommandEncoderDescriptor& desc) -> CommandEncoder;
        auto create_compute_pipeline(const ComputePipelineDescriptor& desc) -> ComputePipeline;
        auto create_compute_pipeline_async(
            const ComputePipelineDescriptor& desc,
            CreateComputePipelineAsyncCallback&& callback
        ) -> std::unique_ptr<CreateComputePipelineAsyncCallback>;
        auto create_pipeline_layout(const PipelineLayoutDescriptor& desc) -> PipelineLayout;
        auto create_query_set(const QuerySetDescriptor& desc) -> QuerySet;
        auto create_render_bundle_encoder(const RenderBundleEncoderDescriptor& desc) -> RenderBundleEncoder;
        auto create_render_pipeline(const RenderPipelineDescriptor& desc) -> RenderPipeline;
        auto create_render_pipeline_async(
            const RenderPipelineDescriptor& desc,
            CreateRenderPipelineAsyncCallback&& callback
        ) -> std::unique_ptr<CreateRenderPipelineAsyncCallback>;
        auto create_sampler(const SamplerDescriptor& desc) -> Sampler;
        auto create_shader_module(const ShaderModuleDescriptor& desc) -> ShaderModule;
        auto create_swapchain(Surface surface, const SwapChainDescriptor& desc) -> SwapChain;
        auto create_texture(const TextureDescriptor& desc) -> Texture;
        auto destroy() -> void;
        auto enumerate_features(FeatureName* features) -> size_t;
        auto get_limits(SupportedLimits* limits) -> bool;
        auto get_queue() -> Queue;
        auto has_feature(FeatureName feature) -> bool;
        auto pop_error_scope(ErrorCallback&& callback) -> std::unique_ptr<ErrorCallback>;
    END 

    HANDLE(Instance)
        static inline auto init(const InstanceDescriptor& desc) -> Instance;
        inline auto deinit() -> void;
        inline auto create_surface(GLFWwindow* window) -> Surface;
        auto process_events() -> void;
        auto request_adapter(const RequestAdapterOptions& opts) -> Adapter;
    END

    HANDLE(PipelineLayout)
        auto label(CStr label) -> void;
    END

    HANDLE(QuerySet)
        auto destroy() -> void;
        auto get_count() -> uint32_t;
        auto get_type() -> QueryType;
        auto label(CStr label) -> void;
    END

    HANDLE(Queue)
        auto on_submitted_work_done(QueueWorkDoneCallback&& callback) -> std::unique_ptr<QueueWorkDoneCallback>;
        auto label(CStr label) -> void;
        auto submit(uint32_t command_count, CommandBuffer const* commands) -> void;
        auto submit(const std::vector<CommandBuffer>& commands) -> void;
        auto submit(const CommandBuffer& commands) -> void;
        auto write_texture(
            Buffer buffer,
            uint64_t buffer_offset,
            void const* data,
            size_t size
        ) -> void;
        auto write_texture(
            const ImageCopyTexture& dest,
            void const* data,
            size_t data_size,
            const TextureDataLayout& data_layout,
            const Extent3D& write_size
        ) -> void;
    END

    HANDLE(RenderBundle)
    END

    HANDLE(RenderBundleEncoder)
        auto draw(
            uint32_t vertex_count,
            uint32_t instance_count,
            uint32_t first_vertex,
            uint32_t first_instance
        ) -> void;
        auto draw_indexed(
           uint32_t index_count, 
           uint32_t instance_count,
           uint32_t first_index,
           int32_t base_vertex,
           uint32_t first_instance
        ) -> void;
        auto draw_indexed_indirect(Buffer indirect_buffer, uint64_t indirect_offset) -> void;
        auto draw_indirect(Buffer indirect_buffer, uint64_t indirect_offset) -> void;
        auto finish(const RenderBundleDescriptor& desc) -> RenderBundle;
        auto insert_debug_marker(CStr label) -> void;
        auto pop_debug_group() -> void;
        auto push_debug_group(CStr label) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            uint32_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const std::vector<uint32_t>& dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const uint32_t& dynamic_offsets
        ) -> void;
        auto set_index_buffer(
            Buffer buffer,
            IndexFormat format,
            uint64_t offset,
            uint64_t size
        ) -> void;
        auto label(CStr label) -> void;
        auto set_pipeline(RenderPipeline pipeline) -> void;
        auto set_vertex_buffer(
            uint32_t slot,
            Buffer buffer,
            uint64_t offset, uint64_t size
        ) -> void;
    END

    HANDLE(RenderPassEncoder)
        auto begin_occlusion_query(uint32_t query_idx) -> void;
        auto begin_pipeline_statistics_query(QuerySet query_set, uint32_t query_idx) -> void;
        auto draw(
            uint32_t vertex_count,
            uint32_t instance_count,
            uint32_t first_vertex,
            uint32_t first_instance
        ) -> void;
        auto draw_indexed(
            uint32_t index_count,
            uint32_t instance_count,
            uint32_t first_index,
            int32_t base_vertex,
            uint32_t first_instance 
        ) -> void;
        auto draw_indexed_indirect(Buffer indirect_buffer, uint64_t indirect_offset) -> void;
        auto draw_indirect(Buffer indirect_buffer, uint64_t indirect_offset) -> void;
        auto end() -> void;
        auto end_occluion_query() -> void; 
        auto execute_bundles(uint32_t bundle_count, RenderBundle const* bundles) -> void;
        auto execute_bundles(const std::vector<RenderBundle>& bundles) -> void;
        auto execute_bundles(const RenderBundle& bundles) -> void;
        auto insert_debug_marker(CStr label) -> void;
        auto pop_debug_group() -> void;
        auto push_debug_group(CStr label) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            uint32_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const std::vector<uint32_t>& dynamic_offsets
        ) -> void;
        auto set_bind_group(
            uint32_t group_idx,
            BindGroup group,
            const uint32_t& dynamic_offsets
        ) -> void;
        auto set_blend_constant(const Color& color) -> void;
        auto set_index_buffer(
            Buffer buffer,
            IndexFormat format,
            uint64_t offset,
            uint64_t size
        ) -> void;
        auto label(CStr label) -> void;
        auto set_pipeline(RenderPipeline pipeline) -> void;
        auto set_scissor_rect(
            uint32_t x,
            uint32_t y,
            uint32_t width,
            uint32_t height
        ) -> void;
        auto set_stencil_reference(uint32_t reference) -> void;
        auto set_vertex_buffer(
            uint32_t slot,
            Buffer buffer,
            uint64_t offset,
            uint64_t size
        ) -> void;
        auto set_viewport(
            float x,
            float y,
            float width,
            float height,
            float min_depth,
            float max_depth
        ) -> void;
    END

    HANDLE(RenderPipeline)
        auto get_bind_group_layout(uint32_t group_idx) -> BindGroupLayout;
        auto label(CStr label) -> void;
    END

    HANDLE(Sampler)
        auto label(CStr label) -> void;
    END

    HANDLE(ShaderModule)
        auto get_compilation_info(CompilationInfoCallback&& callback) -> std::unique_ptr<CompilationInfoCallback>;
        auto label(CStr label) -> void;
    END

    HANDLE(Surface)
        auto get_preferred_format(Adapter adapter) -> TextureFormat;
    END

    HANDLE(SwapChain)
        auto get_current_texture_view() -> TextureView;
    END

    HANDLE(Texture)
        auto create_view(const TextureViewDescriptor& desc) -> TextureView;
        auto destroy() -> void;
        auto get_depth_or_array_layers() -> uint32_t;
        auto get_dimension() -> TextureDimension;
        auto get_format() -> TextureFormat;
        auto get_height() -> uint32_t;
        auto get_mip_level_count() -> uint32_t;
        auto get_sample_count() -> uint32_t;
        auto get_usage() -> TextureUsage;
        auto get_width() -> uint32_t;
        auto label(CStr label) -> void;
    END

    HANDLE(TextureView)
        auto label(CStr label) -> void;
    END

    inline auto Instance::init(const InstanceDescriptor& desc) -> Instance {
        return { .inner = wgpuCreateInstance(&desc) };    
    }

    inline auto Instance::deinit() -> void {
        wgpuInstanceRelease(this->inner);
    }

    inline auto Instance::create_surface(GLFWwindow* window) -> Surface {
        return *reinterpret_cast<Surface*>(glfwGetWGPUSurface(this->inner, window));
    }

    auto Instance::request_adapter(const RequestAdapterOptions& opts) -> Adapter {
        struct UserData {
            impl::Adapter adapter {};
            bool request_ended {};
        };

        auto callback = [](
            RequestAdapterStatus status,
            impl::Adapter adapter,
            CStr msg,
            void* user_data_ptr
        ) -> void {
            auto& user_data = *reinterpret_cast<UserData*>(user_data_ptr);
            switch (status) {
                case RequestAdapterStatus::Success: {
                    user_data.adapter = adapter;
                    break;
                }
                case RequestAdapterStatus::Unavailable: [[fallthrough]];
                case RequestAdapterStatus::Unknown: [[fallthrough]];
                case RequestAdapterStatus::Error: {
                    std::cerr << "Failed to request adapter: " << msg << std::endl;
                    std::abort();
                }
            }
        };

        auto user_data = UserData{};
        wgpuInstanceRequestAdapter(this->inner, &opts, callback, (void*)&user_data);
        
        const auto [adapter, request_ended] = user_data;
        assert(request_ended);
        return { .inner = adapter };
    }
} // namespace wgpu
