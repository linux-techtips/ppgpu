#pragma once

#include <exception>
#include <future>
#include <iostream>
#include <sstream>
#include <utility>

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
        
        using Adapter = struct WGPUAdapterImpl*;
        using BindGroup = struct WGPUBindGroupImpl*;
        using BindGroupLayout = struct WGPUBindGroupLayoutImpl*;
        using Buffer = struct WGPUBufferImpl*;
        using CommandBuffer = struct WGPUCommandBufferImpl*;
        using CommandEncoder = struct WGPUCommandEncoderImpl*;
        using ComputePassEncoder = struct WGPUComputePassEncoderImpl*;
        using ComputePipeline = struct WGPUComputePipelineImpl*;
        using Device = struct WGPUDeviceImpl*;
        using Instance = struct WGPUInstanceImpl*;
        using PipelineLayout = struct WGPUPipelineLayoutImpl*;
        using QuerySet = struct WGPUQuerySetImpl*;
        using Queue = struct WGPUQueueImpl*;
        using RenderBundle = struct WGPURenderBundleImpl*;
        using RenderBundleEncoder = struct WGPURenderBundleEncoderImpl*;
        using RenderPassEncoder = struct WGPURenderPassEncoderImpl*;
        using RenderPipeline = struct WGPURenderPipelineImpl*;
        using Sampler = struct WGPUSamplerImpl*;
        using ShaderModule = struct WGPUShaderModuleImpl*;
        using Surface = struct WGPUSurfaceImpl*;
        using SwapChain = struct WGPUSwapChainImpl*;
        using Texture = struct WGPUTextureImpl*;
        using TextureView = struct WGPUTextureViewImpl*;
    } // namespace impl

    // ENUMERATIONS

    #define ENUM(Name) enum class Name : int32_t {
    #define ENUM_FORCE32 Force32 = 0x7FFFFFFF

    ENUM(AdapterType)
        DiscreteGPU,
        IntegratedGPU,
        CPU,
        Unknown,
        ENUM_FORCE32
    END

    ENUM(AddressMode)
        Repeat,
        MirrorRepeat,
        ClampToEdge,
        ENUM_FORCE32
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
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(BlendOperation)
        Add,
        Sub,
        ReverseSub,
        Min,
        Max,
        ENUM_FORCE32
    END

    ENUM(BufferBindingType)
        Undefined,
        Uniform,
        Storage,
        ReadOnlyStorage,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(BufferMapState)
        Unmapped,
        Pending,
        Mapped,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(CompilationInfoRequestStatus)
        Success,
        Error,
        DeviceLost,
        Unknown,
        ENUM_FORCE32
    END

    ENUM(CompilationMessageType)
        Error,
        Warning,
        Info,
        ENUM_FORCE32
    END

    ENUM(ComputePassTimestampLocation)
        Beginning,
        End,
        ENUM_FORCE32
    END

    ENUM(CreatePipelineAsyncStatus)
        Success,
        ValidationError,
        InternalError,
        DeviceLost,
        DeviceDestroyed,
        Unknown,
        ENUM_FORCE32
    END

    ENUM(CullMode)
        None,
        Front,
        Back,
        ENUM_FORCE32
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
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(FilterMode)
        Nearest,
        Linear,
        ENUM_FORCE32
    END

    ENUM(FrontFace)
        CCW,
        CW,
        ENUM_FORCE32
    END

    ENUM(IndexFormat)
        Undefined,
        Uint16,
        Uint32,
        ENUM_FORCE32
    END

    ENUM(LoadOp)
        Undefined,
        Clear,
        Load,
        ENUM_FORCE32
    END

    ENUM(MipmapFilterMode)
        Nearest,
        Linear,
        ENUM_FORCE32
    END

    ENUM(PipelineStatisticsName)
        VertexShaderInvocations,
        ClipperInvocations,
        ClipperPrimitivesOut,
        FragmentShaderInvocations,
        ComputeShaderInvocations,
        ENUM_FORCE32
    END

    ENUM(PowerPreference)
        Undefined,
        LowPower,
        HighPerformance,
        ENUM_FORCE32
    END

    ENUM(PresentMode)
        Immediate,
        Mailbox,
        Fifo,
        ENUM_FORCE32
    END

    ENUM(PrimitiveTopology)
        PointList,
        LineList,
        LineStrip,
        TriangleList,
        TriangleStrip,
        ENUM_FORCE32
    END

    ENUM(QueryType)
        Occlusion,
        PipelineStatistics,
        Timestamp,
        ENUM_FORCE32
    END

    ENUM(QueueWorkDoneStatus)
        Success,
        Error,
        Unknown,
        DeviceLost,
        ENUM_FORCE32
    END

    ENUM(RenderPassTimestampLocation)
        Beginning,
        End,
        ENUM_FORCE32
    END

    ENUM(RequestAdapterStatus)
        Success = 0x00000000,
        Unavailable = 0x00000001,
        Error = 0x00000002,
        Unknown = 0x00000003,
        ENUM_FORCE32
    END

    ENUM(RequestDeviceAsyncStatus)
        Success,
        Error,
        Unknown,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(SamplerBindingType)
        Undefined,
        Filtering,
        NonFiltering,
        Comparison,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(StorageTextureAccess)
        Undefined,
        WriteOnly,
        ENUM_FORCE32
    END

    ENUM(StoreOp)
        Undefined,
        Store,
        Discard,
        ENUM_FORCE32
    END

    ENUM(TextureAspect)
        All,
        StencilOnly,
        DepthOnly,
        ENUM_FORCE32
    END

    ENUM(TextureDimension)
        D1,
        D2,
        D3,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(TextureSampleType)
        Undefined,
        Float,
        UnfilterableFloat,
        Depth,
        Sint,
        Uint,
        ENUM_FORCE32
    END

    ENUM(TextureViewDimension)
        Undefined,
        D1,
        D2,
        D2Array,
        Cube,
        CubeArray,
        D3,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(VertexStepMode)
        Vertex = 0x00000000,
        Instance = 0x00000001,
        VertexBufferNotUsed = 0x00000002,
        ENUM_FORCE32
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
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(ColorWriteMaskFlags)
    END

    ENUM(MapMode)
        None,
        Read,
        Write,
        ENUM_FORCE32
    END

    ENUM(MapModeFlags)
    END

    ENUM(ShaderStage)
        None = 0x00000000,
        Vertex = 0x00000001,
        Fragment = 0x00000002,
        Compute = 0x00000004,
        ENUM_FORCE32
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
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(NativeFeature)
        PushConstants = 0x60000001,
        TextureAdapterSpecificFormatFeatures = 0x60000002,
        MultiDrawIndirect = 0x60000003,
        MultiDrawIndirectCount = 0x60000004,
        VertexWritableStorage = 0x60000005,
        ENUM_FORCE32
    END

    ENUM(LogLevel)
        Off,
        Error,
        Warn,
        Info,
        Debug,
        Trace,
        ENUM_FORCE32
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
        ENUM_FORCE32
    END

    ENUM(DX12Compiler)
        Undefined,
        Fxc,
        Dxc,
        ENUM_FORCE32
    END

    ENUM(CompositeAlphaMode)
        Auto,
        Opaque,
        PreMultiplied,
        PostMultiplied,
        Inherit,
        ENUM_FORCE32
    END

        inline auto operator<<(std::ostream& os, AdapterType value) -> std::ostream& {
            switch (value) {
                case AdapterType::DiscreteGPU: return os << "AdapterType::DiscreteGPU";
                case AdapterType::IntegratedGPU: return os << "AdapterType::IntegratedGPU";
                case AdapterType::CPU: return os << "AdapterType::CPU";
                case AdapterType::Unknown: return os << "AdapterType::Unknown";
                case AdapterType::Force32: return os << "AdapterType::Force32";
            }
        }

        inline auto operator<<(std::ostream& os, AddressMode value) -> std::ostream& {
            switch(value) {
                case AddressMode::Repeat: return os << "AddressMode::Repeat";
                case AddressMode::MirrorRepeat: return os << "AddressMode::MirrorRepeat";
                case AddressMode::ClampToEdge: return os << "AddressMode::ClampToEdge";
                case AddressMode::Force32: return os << "AddressMode::Force32";
            }
        }

        inline auto operator<<(std::ostream& os, BackendType value) -> std::ostream& {
            switch(value) {
                case BackendType::Undefined: return os << "BackendType::Undefined";
                case BackendType::Null: return os << "BackendType::Null";
                case BackendType::WebGPU: return os << "BackendType::WebGPU";
                case BackendType::D3D11: return os << "BackendType::D3D11";
                case BackendType::D3D12: return os << "BackendType::D3D12";
                case BackendType::Metal: return os << "BackendType::Metal";
                case BackendType::Vulkan: return os << "BackendType::Vulkan";
                case BackendType::OpenGL: return os << "BackendType::OpenGL";
                case BackendType::OpenGLES: return os << "BackendType::OpenGLES";
                case BackendType::Force32: return os << "BackendType::Force32";
            }
        }

        inline auto operator<<(std::ostream& os, BlendFactor value) -> std::ostream& {
            return os << (int)value; 
        }

        inline auto operator<<(std::ostream& os, BlendOperation value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, BufferBindingType value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, BufferMapAsyncStatus value) -> std::ostream& {
            switch(value) {
                case BufferMapAsyncStatus::Success: return os << "BufferMapAsyncStatus::Success";
                case BufferMapAsyncStatus::ValidationError: return os << "BufferMapAsyncStatus::ValidationError";
                case BufferMapAsyncStatus::Unknown: return os << "BufferMapAsyncStatus::Unknown";
                case BufferMapAsyncStatus::DeviceLost: return os << "BufferMapAsyncStatus::DeviceLost";
                case BufferMapAsyncStatus::DestroyedBeforeCallback: return os << "BufferMapAsyncStatus::DestroyedBeforeCallback";
                case BufferMapAsyncStatus::UnmappedBeforeCallback: return os << "BufferMapAsyncStatus::UnmappedBeforeCallback";
                case BufferMapAsyncStatus::MappingAlreadyPending: return os << "BufferMapAsyncStatus::MappingAlreadyPending";
                case BufferMapAsyncStatus::OffsetOutOfRange: return os << "BufferMapAsyncStatus::OffsetOutOfRange";
                case BufferMapAsyncStatus::SizeOutOfRange: return os << "BufferMapAsyncStatus";
                case BufferMapAsyncStatus::Force32: return os << "BufferMapAsyncStatus::Force32";
            };
        }

        inline auto operator<<(std::ostream& os, BufferMapState value) -> std::ostream& {
            return os << (int)value;
        }
        
        inline auto operator<<(std::ostream& os, CompareFunction value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, CompilationInfoRequestStatus value) -> std::ostream& {
            switch(value) {
                case CompilationInfoRequestStatus::Success: return os << "CompilationInfoRequestStatus::Success";
                case CompilationInfoRequestStatus::Error: return os << "CompilationInfoRequestStatus::Error";
                case CompilationInfoRequestStatus::DeviceLost: return os << "CompilationInfoRequestStatus::DeviceLost";
                case CompilationInfoRequestStatus::Unknown: return os << "CompilationInfoRequestStatus::Unknown";
                case CompilationInfoRequestStatus::Force32: return os << "CompilationInfoRequestStatus::Force32";
            }
        }

        inline auto operator<<(std::ostream& os, ComputePassTimestampLocation value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, CreatePipelineAsyncStatus value) -> std::ostream& {
            switch(value) {
                case CreatePipelineAsyncStatus::Success: return os << "CreatePipelineAsyncStatus::Success";
                case CreatePipelineAsyncStatus::ValidationError: return os << "CreatePipelineAsyncStatus::ValidationError";
                case CreatePipelineAsyncStatus::InternalError: return os << "CreatePipelineAsyncStatus::InternalError";
                case CreatePipelineAsyncStatus::DeviceLost: return os << "CreatePipelineAsyncStatus::DeviceLost";
                case CreatePipelineAsyncStatus::DeviceDestroyed: return os << "CreatePipelineAsyncStatus::DeviceDestroyed";
                case CreatePipelineAsyncStatus::Unknown: return os << "CreatePipelineAsyncStatus::Unknown";
                case CreatePipelineAsyncStatus::Force32 : return os << "CreatePipelineAsyncStatus::Force32";
            }
        }

        inline auto operator<<(std::ostream& os, CullMode value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, DeviceLostReason value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, ErrorFilter value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, ErrorType value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, FeatureName value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, FilterMode value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, FrontFace value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, IndexFormat value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, LoadOp value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, MipmapFilterMode value) -> std::ostream& {
            return os << (int)value;
        }

        inline auto operator<<(std::ostream& os, PipelineStatisticsName value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, PowerPreference value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, PresentMode value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, PrimitiveTopology value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, QueryType value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, QueueWorkDoneStatus value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, RenderPassTimestampLocation value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, RequestAdapterStatus value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, RequestDeviceAsyncStatus value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, SType value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, SamplerBindingType value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, StencilOperation value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, StorageTextureAccess value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, StoreOp value) -> std::ostream& {
            return os << (int)value;
        }
 
        inline auto operator<<(std::ostream& os, TextureAspect value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, TextureDimension value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, TextureFormat value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, VertexStepMode value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, BufferUsage value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, ColorWriteMask value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, MapMode value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, ShaderStage value) -> std::ostream& {
            return os << (int)value;
        }

       inline auto operator<<(std::ostream& os, TextureUsage value) -> std::ostream& {
            return os << (int)value;
        }

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
    
    using BufferMapCallback = auto(*)(BufferMapAsyncStatus, void* user_data) -> void;
    using CompilationInfoCallback = auto(*)(CompilationInfoRequestStatus status, CompilationInfo* compilation_info, void* user_data) -> void;
    using CreateComputePipelineAsyncCallback = auto(*)(CreatePipelineAsyncStatus status, impl::ComputePipeline pipeline, CStr msg, void* user_data) -> void;
    using CreateRenderPipelineAsyncCallback = auto(*)(CreatePipelineAsyncStatus status, impl::RenderPipeline pipeline, CStr msg, void* user_data) -> void;
    using DeviceLostCallback = auto(*)(DeviceLostReason reason, CStr msg, void* user_data) -> void;
    using ErrorCallback = auto(*)(ErrorType type, CStr msg, void* user_data) -> void;
    using QueueWorkDoneCallback = auto(*)(QueueWorkDoneStatus status, void* user_data) -> void;
    using RequestAdapterCallback = auto(*)(RequestAdapterStatus status, impl::Adapter adapter, CStr msg, void* user_data) -> void;
    using RequestDeviceCallback = auto(*)(RequestDeviceAsyncStatus status, impl::Device device, CStr msg, void* user_data) -> void;
    using ProcDeviceSetUncapturedErrorCallback = auto(*)(impl::Device device, ErrorCallback&& callback, void* user_data) -> void;
    using LogCallback = auto(*)(LogLevel level, CStr msg) -> void;

    namespace {

        #define CATCHME_MSG_IMPL(Status) \
            inline auto catchme(Status status, CStr msg) -> std::exception_ptr { \
                const auto msg_stream = std::stringstream{} << "[FATAL] " << status << ": " << msg; \
                return std::make_exception_ptr(std::runtime_error(msg_stream.str())); \
            }

        #define CATCHME_IMPL(Status) \
            inline auto catchme(Status status) -> std::exception_ptr { \
                const auto msg_stream = std::stringstream{} << "[FATAL] " << status; \
                return std::make_exception_ptr(std::runtime_error(msg_stream.str())); \
            }

        CATCHME_IMPL(BufferMapAsyncStatus)
        CATCHME_IMPL(CompilationInfoRequestStatus)
        CATCHME_MSG_IMPL(CreatePipelineAsyncStatus)
        CATCHME_MSG_IMPL(DeviceLostReason)
        CATCHME_MSG_IMPL(ErrorType)
        CATCHME_IMPL(QueueWorkDoneStatus)
        CATCHME_MSG_IMPL(RequestAdapterStatus)
        CATCHME_MSG_IMPL(RequestDeviceAsyncStatus)

    }

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
        ProgrammableStageDescriptor compute {};
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
   
    namespace native {
        extern "C" {
            
            auto wgpuCreateInstance(
                InstanceDescriptor const* desc
            ) -> impl::Instance;

            // Adapter Methods
            auto wgpuAdapterEnumerateFeatures(
                impl::Adapter adapter,
                FeatureName* features 
            ) -> size_t;

            auto wgpuAdapterGetLimits(
                impl::Adapter adapter,
                SupportedLimits* limits 
            ) -> bool;

            auto wgpuAdapterGetProperties(
                impl::Adapter adapter,
                AdapterProperties* props
            ) -> void;

            auto wgpuAdapterHasFeature(
                impl::Adapter adapter,
                FeatureName feature
            ) -> bool;

            auto wgpuAdapterRequestDevice(
                impl::Adapter adapter,
                DeviceDescriptor const* desc,
                RequestDeviceCallback callback,
                void* user_data
            ) -> void;

            auto wgpuAdapterReference(
                impl::Adapter adapter
            ) -> void;

            auto wgpuAdapterRelease(
                impl::Adapter adapter
            ) -> void;

            // BindGroup Methods

            auto wgpuBindGroupSetLabel(
                impl::BindGroup bind_group,
                CStr label
            ) -> void;

            auto wgpuBindGroupReference(
                impl::BindGroup bind_group
            ) -> void;

            auto wgpuBindGroupRelease(
                impl::BindGroup bind_group
            ) -> void;

            // BindGroupLayout Methods
            
            auto wgpuBindGroupLayoutSetLabel(
                impl::BindGroupLayout bind_group_layout,
                CStr label
            ) -> void;

            auto wgpuBindGroupLayoutReference(
                impl::BindGroupLayout bind_group_layout
            ) -> void;

            auto wgpuBindGroupLayoutRelease(
                impl::BindGroupLayout bind_group_layout
            ) -> void;

            // Buffer Methods
            
            auto wgpuBufferDestroy(
                impl::Buffer buffer
            ) -> void;

            auto wgpuBufferGetConstMappedRange(
                impl::Buffer buffer,
                size_t offset,
                size_t size
            ) -> void const*;

            auto wgpuBufferGetMapState(
                impl::Buffer buffer
            ) -> BufferMapState;

            auto wgpuBufferGetMappedRange(
                impl::Buffer buffer,
                size_t offset,
                size_t size
            ) -> void*;

            auto wgpuBufferGetSize(
                impl::Buffer buffer
            ) -> uint64_t;

            auto wgpuBufferGetUsage(
                impl::Buffer buffer
            ) -> BufferUsageFlags;

            auto wgpuBufferMapAsync(
                impl::Buffer buffer,
                MapModeFlags mode,
                size_t offset,
                size_t size,
                BufferMapCallback callback,
                void* user_data
            ) -> void;

            auto wgpuBufferSetLabel(
                impl::Buffer buffer,
                CStr label
            ) -> void;

            auto wgpuBufferUnmap(
                impl::Buffer buffer
            ) -> void;

            auto wgpuBufferReference(
                impl::Buffer buffer
            ) -> void;

            auto wgpuBufferRelease(
                impl::Buffer buffer
            ) -> void;

            // CommandBuffer Methods
            
            auto wgpuCommandBufferSetLabel(
                impl::CommandBuffer command_buffer,
                CStr label
            ) -> void;

            auto wgpuCommandBufferReference(
                impl::CommandBuffer command_buffer
            ) -> void;

            auto wgpuCommandBufferRelease(
                impl::CommandBuffer command_buffer
            ) -> void;

            // CommandEncoder

            auto wgpuCommandEncoderBeginComputePass(
                impl::CommandEncoder encoder,
                ComputePassDescriptor const* desc
            ) -> impl::ComputePassEncoder;

            auto wgpuCommandEncoderBeginRenderPass(
                impl::CommandEncoder encoder,
                RenderPassDescriptor const* desc
            ) -> impl::RenderPassEncoder;

            auto wgpuCommandEncoderClearBuffer(
                impl::CommandEncoder encoder,
                impl::Buffer buffer,
                uint64_t offset,
                uint64_t size
            ) -> void;

            auto wgpuCommandEncoderCopyBufferToBuffer(
               impl::CommandEncoder encoder,
               impl::Buffer src,
               uint64_t src_offset,
               impl::Buffer dest,
               uint64_t dest_offset,
               uint64_t size
            ) -> void;

            auto wgpuCommandEncoderCopyBufferToTexture(
                impl::CommandEncoder encoder,
                ImageCopyBuffer const* src,
                ImageCopyTexture const* dest,
                Extent3D const* size
            ) -> void;

            auto wgpuCommandEncoderCopyTextureToBuffer(
                impl::CommandEncoder encoder,
                ImageCopyTexture const* src,
                ImageCopyBuffer const* dest,
                Extent3D const* size
            ) -> void;

            auto wgpuCommandEncoderCopyTextureToTexture(
                impl::CommandEncoder encoder,
                ImageCopyTexture const* src,
                ImageCopyTexture const* dest,
                Extent3D const* size
            ) -> void;

            auto wgpuCommandEncoderFinish(
                impl::CommandEncoder encoder,
                CommandBufferDescriptor const* desc
            ) -> impl::CommandBuffer;

            auto wgpuCommandEncoderInsertDebugMarker(
                impl::CommandEncoder encoder,
                CStr marker_label
            ) -> void;

            auto wgpuCommandEncoderPopDebugGroup(
                impl::CommandEncoder encoder
            ) -> void;

            auto wgpuCommandEncoderPushDebugGroup(
                impl::CommandEncoder encoder,
                CStr group_label
            ) -> void;

            auto wgpuCommandEncoderResolveQuerySet(
                impl::CommandEncoder encoder,
                impl::QuerySet query_set,
                uint32_t first,
                uint32_t count,
                impl::Buffer dest,
                uint64_t offset
            ) -> void;

            auto wgpuCommandEncoderSetLabel(
                impl::CommandEncoder encoder,
                CStr label
            ) -> void;

            auto wgpuCommandEncoderWriteTimestamp(
                impl::CommandEncoder encoder,
                impl::QuerySet query_set,
                uint32_t idx
            ) -> void;

            auto wgpuCommandEncoderReference(
                impl::CommandEncoder encoder
            ) -> void;

            auto wgpuCommandEncoderRelease(
                impl::CommandEncoder encoder
            ) -> void;

            // ComputePassEncoder Methods

            auto wgpuComputePassEncoderBeginPipelineStatisticsQuery(
                impl::ComputePassEncoder encoder,
                impl::QuerySet query_set,
                uint32_t idx
            ) -> void;

            auto wgpuComputePassEncoderDispatchWorkgroups(
                impl::ComputePassEncoder encoder,
                uint32_t workgroup_count_x,
                uint32_t workgroup_count_y,
                uint32_t workgroup_count_z
            ) -> void;

            auto wgpuComputePassEncoderDispatchWorkgroupsIndirect(
                impl::ComputePassEncoder encoder,
                impl::Buffer indirect_buffer,
                uint64_t indirect_offset
            ) -> void;

            auto wgpuComputePassEncoderEnd(
                impl::ComputePassEncoder encoder
            ) -> void;

            auto wgpuComputePassEncoderEndPipelineStatisticsQuery(
                impl::ComputePassEncoder encoder
            ) -> void;

            auto wgpuComputePassEncoderInsertDebugMarker(
                impl::ComputePassEncoder encoder,
                CStr marker_label
            ) -> void;

            auto wgpuComputePassEncoderPopDebugGroup(
                impl::ComputePassEncoder encoder
            ) -> void;

            auto wgpuComputePassEncoderPushDebugGroup(
                impl::ComputePassEncoder encoder,
                CStr group_label
            ) -> void;

            auto wgpuComputePassEncoderSetBindGroup(
                impl::ComputePassEncoder encoder,
                uint32_t group_idx,
                impl::BindGroup group,
                size_t dynamic_offset_count,
                uint32_t const* dynamic_offsets
            ) -> void;

            auto wgpuComputePassEncoderSetLabel(
                impl::ComputePassEncoder encoder,
                CStr label
            ) -> void;

            auto wgpuComputePassEncoderSetPipeline(
                impl::ComputePassEncoder encoder,
                impl::ComputePipeline pipeline
            ) -> void;

            auto wgpuComputePassEncoderReference(
                impl::ComputePassEncoder encoder
            ) -> void;

            auto wgpuComputePassEncoderRelease(
                impl::ComputePassEncoder encoder
            ) -> void;

            // ComputePipeline Methods

            auto wgpuComputePipelineGetBindGroupLayout(
                impl::ComputePipeline pipeline,
                uint32_t group_idx
            ) -> impl::BindGroupLayout;

            auto wgpuComputePipelineSetLabel(
                impl::ComputePipeline pipeline,
                CStr label
            ) -> void;

            auto wgpuComputePipelineReference(
                impl::ComputePipeline pipeline
            ) -> void;

            auto wgpuComputePipelineRelease(
                impl::ComputePipeline pipeline
            ) -> void;

            // Device Methods
            
            auto wgpuDeviceCreateBindGroup(
                impl::Device device,
                BindGroupDescriptor const* desc
            ) -> impl::BindGroup;

            auto wgpuDeviceCreateBindGroupLayout(
                impl::Device device,
                BindGroupLayoutDescriptor const* desc
            ) -> impl::BindGroupLayout;

            auto wgpuDeviceCreateBuffer(
                impl::Device device,
                BufferDescriptor const * desc
            ) -> impl::Buffer;

            auto wgpuDeviceCreateCommandEncoder(
                impl::Device device,
                CommandEncoderDescriptor const* desc
            ) -> impl::CommandEncoder;

            auto wgpuDeviceCreateComputePipeline(
                impl::Device device,
                ComputePipelineDescriptor const* desc
            ) -> impl::ComputePipeline;

            auto wgpuDeviceCreateComputePipelineAsync(
                impl::Device device,
                ComputePipelineDescriptor const* desc,
                CreateComputePipelineAsyncCallback callback,
                void* user_data
            ) -> void;

            auto wgpuDeviceCreatePipelineLayout(
                impl::Device device,
                PipelineLayoutDescriptor const* desc
            ) -> impl::PipelineLayout;

            auto wgpuDeviceCreateQuerySet(
                impl::Device device,
                QuerySetDescriptor const* desc
            ) -> impl::QuerySet;

            auto wgpuDeviceCreateRenderBundleEncoder(
                impl::Device device,
                RenderBundleEncoderDescriptor const* desc
            ) -> impl::RenderBundleEncoder;

            auto wgpuDeviceCreateRenderPipeline(
                impl::Device device,
                RenderPipelineDescriptor const* desc
            ) -> impl::RenderPipeline;

            auto wgpuDeviceCreateRenderPipelineAsync(
                impl::Device device,
                RenderPipelineDescriptor const* desc,
                CreateRenderPipelineAsyncCallback callback,
                void* user_data
            ) -> void;

            auto wgpuDeviceCreateSampler(
                impl::Device device,
                SamplerDescriptor const* desc
            ) -> impl::Sampler;

            auto wgpuDeviceCreateShaderModule(
                impl::Device device,
                ShaderModuleDescriptor const* desc
            ) -> impl::ShaderModule;

            auto wgpuDeviceCreateSwapChain(
                impl::Device device,
                impl::Surface surface,
                SwapChainDescriptor const* desc
            ) -> impl::SwapChain;

            auto wgpuDeviceCreateTexture(
                impl::Device device,
                TextureDescriptor const* desc
            ) -> impl::Texture;

            auto wgpuDeviceDestroy(
                impl::Device device
            ) -> void;
 
            auto wgpuDeviceEnumerateFeatures(
                impl::Device device,
                FeatureName* features
            ) -> size_t;

            auto wgpuDeviceGetLimits(
                impl::Device device,
                SupportedLimits* limits
            ) -> bool;

            auto wgpuDeviceGetQueue(
                impl::Device device
            ) -> impl::Queue;

            auto wgpuDeviceHasFeature(
                impl::Device device,
                FeatureName feature
            ) -> bool;

            auto wgpuDevicePopErrorScope(
                impl::Device device,
                ErrorCallback callback,
                void* user_data
            ) -> void;

            auto wgpuDevicePushErrorScope(
                impl::Device device,
                ErrorFilter filter
            ) -> void;

            auto wgpuDeviceSetLabel(
                impl::Device device,
                CStr label
            ) -> void;

            auto wgpuDeviceSetUncapturedErrorCallback(
                impl::Device device,
                ErrorCallback callback,
                void* user_data
            ) -> void;

            auto wgpuDeviceReference(
                impl::Device device
            ) -> void;

            auto wgpuDeviceRelease(
                impl::Device device
            ) -> void;

            // Instance Methods

            auto wgpuInstanceCreateSurface(
                impl::Instance instance,
                SurfaceDescriptor const* desc
            ) -> impl::Surface;

            auto wgpuInstanceProcessEvents(
                impl::Instance instance
            ) -> void;

            auto wgpuInstanceRequestAdapter(
                impl::Instance instance,
                RequestAdapterOptions const* opts,
                RequestAdapterCallback callback,
                void* user_data
            ) -> impl::Adapter;

            auto wgpuInstanceReference(
                impl::Instance instance
            ) -> void;

            auto wgpuInstanceRelease(
                impl::Instance instance
            ) -> void;

            // PipelineLayout Methods
            
            auto wgpuPipelineLayoutSetLabel(
                impl::PipelineLayout layout,
                CStr label
            ) -> void;

            auto wgpuPipelineLayoutReference(
                impl::PipelineLayout layout
            ) -> void;

            auto wgpuPipelineLayoutRelease(
                impl::PipelineLayout layout
            ) -> void;

            // QuerySet Methods
            auto wgpuQuerySetDestroy(
                impl::QuerySet query_set
            ) -> void;

            auto wgpuQuerySetGetCount(
               impl::QuerySet query_set 
            ) -> uint32_t;

            auto wgpuQuerySetGetType(
                impl::QuerySet query_set
            ) -> QueryType;

            auto wgpuQuerySetReference(
                impl::QuerySet query_set
            ) -> void;

            auto wgpuQuerySetRelease(
                impl::QuerySet query_set
            ) -> void;

            // Queue Methods
            auto wgpuQueueOnSubmittedWorkDone(
                impl::Queue queue,
                QueueWorkDoneCallback callback,
                void* user_data
            ) -> void;

            auto wgpuQueueSetLabel(
                impl::Queue queue,
                CStr label
            ) -> void;

            auto wgpuQueueSubmit(
                impl::Queue queue,
                size_t command_count,
                impl::CommandBuffer const* commands
            ) -> void;

            auto wgpuQueueWriteBuffer(
                impl::Queue queue,
                impl::Buffer buffer,
                uint64_t offset,
                void const* data,
                size_t size
            ) -> void;

            auto wgpuQueueWriteTexture(
                impl::Queue queue,
                ImageCopyTexture const* dest,
                void const* data,
                size_t data_size,
                TextureDataLayout const* data_layout,
                Extent3D const* write_size
            ) -> void;

            auto wgpuQueueReference(
                impl::Queue queue
            ) -> void;

            auto wgpuQueueRelease(
                impl::Queue queue
            ) -> void;

            // RenderBundle Methods
            
            auto wgpuRenderBundleSetLabel(
                impl::RenderBundle render_bundle,
                CStr label
            ) -> void;

            auto wgpuRenderBundleReference(
                impl::RenderBundle render_bundle
            ) -> void;

            auto wgpuRenderBundleRelease(
                impl::RenderBundle render_bundle
            ) -> void;

            // RenderBundleEncoder Methods

            auto wgpuRenderBundleEncoderDraw(
                impl::RenderBundleEncoder encoder,
                uint32_t vertex_count,
                uint32_t instance_count,
                uint32_t first_vertex,
                uint32_t first_instance
            ) -> void;

            auto wgpuRenderBundleEncoderDrawIndexed(
                impl::RenderBundleEncoder encoder,
                uint32_t index_count,
                uint32_t instance_count,
                uint32_t first_index,
                int32_t base_vertex,
                int32_t first_instance
            ) -> void;

            auto wgpuRenderBundleEncoderDrawIndexedIndirect(
                impl::RenderBundleEncoder encoder,
                impl::Buffer indirect_buffer,
                uint64_t indirect_offset
            ) -> void;

            auto wgpuRenderBundleEncoderDrawIndirect(
                impl::RenderBundleEncoder encoder,
                impl::Buffer indirect_buffer,
                uint64_t indirect_offset
            ) -> void;

            auto wgpuRenderBundleEncoderFinish(
                impl::RenderBundleEncoder encoder,
                RenderBundleEncoderDescriptor const* desc
            ) -> impl::RenderBundle;

            auto wgpuRenderBundleEncoderInsertDebugMarker(
                impl::RenderBundleEncoder encoder,
                CStr marker_label
            ) -> void;

            auto wgpuRenderBundleEncoderPopDebugGroup(
                impl::RenderBundleEncoder encoder
            ) -> void;

            auto wgpuRenderBundleEncoderPushDebugGroup(
                impl::RenderBundleEncoder encoder,
                CStr group_label
            ) -> void;

            auto wgpuRenderBundleEncoderSetBindGroup(
                impl::RenderBundleEncoder encoder,
                uint32_t group_idx,
                impl::BindGroup group,
                size_t dynamic_offset_count,
                uint32_t const* dynamic_offsets
            ) -> void;

            auto wgpuRenderBundleEncoderSetIndexBuffer(
                impl::RenderBundleEncoder encoder,
                impl::Buffer buffer,
                IndexFormat fomat,
                uint64_t offset,
                uint64_t size
            ) -> void;

            auto wgpuRenderBundleEncoderSetLabel(
                impl::RenderBundleEncoder encoder,
                CStr label
            ) -> void;
            
            auto wgpuRenderBundleEncoderSetPipeline(
                impl::RenderBundleEncoder encoder,
                impl::RenderPipeline pipeline
            ) -> void;

            auto wgpuRenderBundleEncoderSetVertexBuffer(
                impl::RenderBundleEncoder encoder,
                uint32_t slot,
                impl::Buffer buffer,
                uint64_t offset,
                uint64_t size
            ) -> void;

            auto wgpuRenderBundleEncoderReference(
                impl::RenderBundleEncoder encoder
            ) -> void;

            auto wgpuRenderBundleEncoderRelease(
                impl::RenderBundleEncoder encoder
            ) -> void;

            // RenderPassEncoder Methods
            
            auto wgpuRenderPassEncoderBeginOcclusionQuery(
                impl::RenderPassEncoder encoder,
                uint32_t query_idx
            ) -> void;

            auto wgpuRenderPassEncoderBeginPipelineStatisticsQuery(
                impl::RenderPassEncoder encoder,
                impl::QuerySet query_set,
                uint32_t query_idx
            ) -> void;

            auto wgpuRenderPassEncoderDraw(
                impl::RenderPassEncoder encoder,
                uint32_t vertex_count,
                uint32_t instance_count,
                uint32_t first_vertex,
                uint32_t first_instance
            ) -> void;

            auto wgpuRenderPassEncoderDrawIndexed(
                impl::RenderPassEncoder encoder,
                uint32_t index_count,
                uint32_t instance_count,
                uint32_t first_index,
                int32_t base_vertex,
                uint32_t first_instance
            ) -> void;

            auto wgpuRenderPassEncoderDrawIndexedIndirect(
                impl::RenderPassEncoder encoder,
                impl::Buffer indirect_buffer,
                uint64_t indirect_offset
            ) -> void;

            auto wgpuRenderPassEncoderDrawIndirect(
                impl::RenderPassEncoder encoder,
                impl::Buffer indirect_buffer,
                uint64_t indirect_offset
            ) -> void;

            auto wgpuRenderPassEncoderEnd(
                impl::RenderPassEncoder encoder
            ) -> void;

            auto wgpuRenderPassEncoderEndOcclusionQuery(
                impl::RenderPassEncoder encoder
            ) -> void;

            auto wgpuRenderPassEncoderEndPipelineStatisticsQuery(
                impl::RenderPassEncoder encoder
            ) -> void;

            auto wgpuRenderPassEncoderExecuteBundles(
                impl::RenderPassEncoder encoder,
                size_t bundle_count,
                impl::RenderBundle const* bundles
            ) -> void;

            auto wgpuRenderPassEncoderInsertDebugMarker(
                impl::RenderPassEncoder encoder,
                CStr marker_label
            ) -> void;

            auto wgpuRenderPassEncoderPopDebugGroup(
                impl::RenderPassEncoder encoder
            ) -> void;

            auto wgpuRenderPassEncoderPushDebugGroup(
                impl::RenderPassEncoder encoder,
                CStr group_label
            ) -> void;

            auto wgpuRenderPassEncoderSetBindGroup(
                impl::RenderPassEncoder encoder,
                uint32_t group_idx,
                impl::BindGroup group,
                size_t dynamic_offset_count,
                uint32_t const* dynamic_offsets
            ) -> void;

            auto wgpuRenderPassEncoderSetBlendConstant(
                impl::RenderPassEncoder encoder,
                Color const* color
            ) -> void;

            auto wgpuRenderPassEncoderSetIndexBuffer(
                impl::RenderPassEncoder encoder,
                impl::Buffer buffer,
                IndexFormat format,
                uint64_t offset,
                uint64_t size
            ) -> void;

            auto wgpuRenderPassEncoderSetLabel(
                impl::RenderPassEncoder encoder,
                CStr label
            ) -> void;

            auto wgpuRenderPassEncoderSetPipeline(
                impl::RenderPassEncoder encoder,
                impl::RenderPipeline pipeline
            ) -> void;

            auto wgpuRenderPassEncoderSetScissorRect(
                impl::RenderPassEncoder encoder,
                uint32_t x,
                uint32_t y,
                uint32_t width,
                uint32_t height
            ) -> void;

            auto wgpuRenderPassEncoderSetStencilReference(
                impl::RenderPassEncoder encoder,
                uint32_t reference
            ) -> void;

            auto wgpuRenderPassEncoderSetVertexBuffer(
                impl::RenderPassEncoder encoder,
                uint32_t slot,
                impl::Buffer buffer,
                uint64_t offset,
                uint64_t size
            ) -> void;

            auto wgpuRenderPassEncoderSetViewport(
                impl::RenderPassEncoder encoder,
                float x,
                float y,
                float width,
                float height,
                float min_depth,
                float max_depth
            ) -> void;

            auto wgpuRenderPassEncoderReference(
                impl::RenderPassEncoder encoder
            ) -> void;

            auto wgpuRenderPassEncoderRelease(
                impl::RenderPassEncoder encoder
            ) -> void;
        
            // RenderPipeline Methods
            
            auto wgpuRenderPipelineGetBindGroupLayout(
                impl::RenderPipeline pipeline,
                uint32_t group_idx
            ) -> impl::BindGroupLayout;
        
            auto wgpuRenderPipelineSetLabel(
                impl::RenderPipeline pipeline,
                CStr label
            ) -> void;

            auto wgpuRenderPipelineReference(
                impl::RenderPipeline pipeline
            ) -> void;

            auto wgpuRenderPipelineRelease(
                impl::RenderPipeline pipeline
            ) -> void;

            // Sampler Methods
            
            auto wgpuSamplerSetLabel(
                impl::Sampler sampler,
                CStr label
            ) -> void;

            auto wgpuSamplerReference(
                impl::Sampler sampler
            ) -> void;

            auto wgpuSamplerRelease(
                impl::Sampler sampler
            ) -> void;

            // ShaderModue Methods
            
            auto wgpuShaderModuleGetCompilationInfo(
                impl::ShaderModule shader_module,
                CompilationInfoCallback callback,
                void* user_data
            ) -> void;

            auto wgpuShaderModuleSetLabel(
                impl::ShaderModule shader_module,
                CStr label
            ) -> void;

            auto wgpuShaderModuleReference(
                impl::ShaderModule shader_module
            ) -> void;

            auto wgpuShaderModuleRelease(
                impl::ShaderModule shader_module
            ) -> void;

            // Surface Methods
            
            auto wgpuSurfaceGetPreferredFormat(
                impl::Surface surface,
                impl::Adapter adapter
            ) -> TextureFormat;

            auto wgpuSurfaceReference(
                impl::Surface surface
            ) -> void;

            auto wgpuSurfaceRelease(
                impl::Surface surface
            ) -> void;

            // SwapChain Methods
            
            auto wgpuSwapChainGetCurrentTextureView(
                impl::SwapChain swapchain
            ) -> impl::TextureView;

            auto wgpuSwapChainPresent(
                impl::SwapChain swapchain 
            ) -> void;

            auto wgpuSwapChainReference(
                impl::SwapChain swapchain
            ) -> void;

            auto wgpuSwapChainRelease(
                impl::SwapChain swapchain
            ) -> void;

            // Texture Methods
            
            auto wgpuTextureCreateView(
                impl::Texture texture,
                TextureViewDescriptor const* descriptor
            ) -> impl::TextureView;

            auto wgpuTextureDestroy(
                impl::Texture texture
            ) -> void;

            auto wgpuTextureGetDepthOrArrayLayers(
                impl::Texture texture
            ) -> uint32_t;

            auto wgpuTextureGetDimension(
                impl::Texture texture
            ) -> TextureDimension;

            auto wgpuTextureGetFormat(
                impl::Texture texture 
            ) -> TextureFormat;

            auto wgpuTextureGetHeight(
                impl::Texture texture
            ) -> uint32_t;

            auto wgpuTextureGetMipLevelCount(
                impl::Texture texture
            ) -> uint32_t;

            auto wgpuTextureGetSampleCount(
                impl::Texture texture
            ) -> uint32_t;

            auto wgpuTextureGetUsage(
                impl::Texture texture
            ) -> TextureUsageFlags;

            auto wgpuTextureGetWidth(
                impl::Texture texture
            ) -> uint32_t;

            auto wgpuTextureSetLabel(
                impl::Texture texture,
                CStr label
            ) -> void;

            auto wgpuTextureReference(
                impl::Texture texture
            ) -> void;

            auto wgpuTextureRelease(
                impl::Texture texture
            ) -> void;

            // TextureView Methods

            auto wgpuTextureViewSetLabel(
                impl::TextureView texture,
                CStr label
            ) -> void;

            auto wgpuTextureViewReference(
                impl::TextureView texture
            ) -> void;

            auto wgpuTextureViewRelease(
                impl::TextureView texture
            ) -> void;
        }
    } // namespace native 

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
        Impl inner; \
        inline operator Impl&() { return inner; } \
        inline operator const Impl&() const { return inner; } \
        inline operator bool() const { return (inner) ? true : false; } \
        inline auto reference() -> void { native::wgpu ## Type ## Reference(*this); }; \
        inline auto release() -> void { native::wgpu ## Type ## Release(*this); }; \

    HANDLE(Adapter)
        [[nodiscard]] inline auto enumerate_features(FeatureName* features) -> size_t;
        [[nodiscard]] inline auto get_limits(SupportedLimits* limits) -> bool;
        inline auto get_properties(AdapterProperties* properties) -> void;
        [[nodiscard]] inline auto has_feature(FeatureName feature) -> bool;
        static auto request_device_callback(
            RequestDeviceAsyncStatus status,
            impl::Device device,
            CStr msg,
            void* promise_raw
        ) -> void;
        [[nodiscard]] inline auto request_device(
            const DeviceDescriptor& desc,
            RequestDeviceCallback&& callback = Adapter::request_device_callback
        ) -> Device;
        [[nodiscard]] inline auto request_device_async(
            const DeviceDescriptor& descriptor,
            RequestDeviceCallback&& callback = Adapter::request_device_callback
        ) -> std::future<Device>; 
    END

    HANDLE(BindGroup)
        inline auto label(CStr label) -> void;
    END

    HANDLE(BindGroupLayout)
        inline auto label(CStr label) -> void;
    END

    HANDLE(Buffer)
        inline auto label(CStr label) -> void;
        inline auto destroy() -> void;
        inline auto get_const_mapped_range(size_t offset, size_t size) -> void const*;
        [[nodiscard]] inline auto get_map_state() -> BufferMapState;
        [[nodiscard]] inline auto get_size() -> uint64_t;
        [[nodiscard]] inline auto get_usage() -> BufferUsageFlags;
        static auto map_callback(BufferMapAsyncStatus status, void* promise_raw) -> void;
        [[nodiscard]] inline auto map_async(
            MapModeFlags mode,
            size_t offset,
            size_t size,
            BufferMapCallback&& callback = Buffer::map_callback
        ) -> std::future<void>;
        inline auto unmap() -> void;
    END

    HANDLE(CommandBuffer)
        inline auto label(CStr label) -> void;
    END

    HANDLE(CommandEncoder)
        [[nodiscard]] inline auto begin_compute_pass(const ComputePassDescriptor& descriptor) -> ComputePassEncoder;
        [[nodiscard]] inline auto begin_render_pass(const RenderPassDescriptor& descriptor) -> RenderPassEncoder;
        inline auto clear_buffer(Buffer& buffer, uint64_t offset, uint64_t size) -> void;
        inline auto copy_buffer_to_buffer(
            const Buffer& src,
            uint64_t src_offset,
            Buffer& dest,
            uint64_t dest_offset,
            uint64_t size
        ) -> void;
        inline auto copy_buffer_to_texture(
            const ImageCopyBuffer& src,
            ImageCopyTexture& dest,
            const Extent3D& size
        ) -> void;
        inline auto copy_texture_to_buffer(
            const ImageCopyTexture& src,
            ImageCopyBuffer& dest,
            const Extent3D& size
        ) -> void;
        inline auto copy_texture_to_texture(
            const ImageCopyTexture& src,
            ImageCopyTexture& dest,
            const Extent3D& size
        ) -> void;
        [[nodiscard]] inline auto finish(const CommandBufferDescriptor& descriptor) -> CommandBuffer;
        inline auto insert_debug_marker(CStr marker_label) -> void;
        inline auto pop_debug_group() -> void;
        inline auto push_debug_group(CStr group_label) -> void;
        inline auto resolve_query_set(
            const QuerySet& query_set,
            uint32_t first_query,
            uint32_t query_count,
            Buffer& dest,
            uint64_t dest_offset
        ) -> void;
        inline auto label(CStr label) -> void;
    END

    HANDLE(ComputePassEncoder)
        inline auto begin_pipeline_statistics_query(const QuerySet& query_set, uint32_t query_idx) -> void;
        inline auto dispatch_workgroups(
            uint32_t workgroup_count_x,
            uint32_t workgroup_count_y,
            uint32_t workgroup_count_z
        ) -> void;
        inline auto dispatch_workgroups_indirect(Buffer& indirect_buffer, uint64_t indirect_offset) -> void;
        inline auto end() -> void;
        inline auto end_pipeline_statistics_query() -> void;
        inline auto insert_debug_marker(CStr marker_label) -> void;
        inline auto pop_debug_group() -> void;
        inline auto push_debug_group(CStr group_label) -> void;
        inline auto set_bind_group(
            uint32_t group_idx,
            BindGroup& group,
            size_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        inline auto label(CStr label) -> void;
        inline auto set_pipeline(ComputePipeline& pipeline) -> void;
    END

    HANDLE(ComputePipeline)
        [[nodiscard]] inline auto get_bind_group_layout(uint32_t group_idx) -> BindGroupLayout;
        inline auto label(CStr label) -> void;
    END

    HANDLE(Device)
        [[nodiscard]] inline auto create_bind_group(const BindGroupDescriptor& desc) -> BindGroup;
        [[nodiscard]] inline auto create_bind_group_layout(const BindGroupLayoutDescriptor& desc) -> BindGroupLayout;
        [[nodiscard]] inline auto create_buffer(const BufferDescriptor& desc) -> Buffer;
        [[nodiscard]] inline auto create_command_encoder(const CommandEncoderDescriptor& desc) -> CommandEncoder;
        [[nodiscard]] inline auto create_compute_pipeline(const ComputePipelineDescriptor& desc) -> ComputePipeline;
        static auto create_compute_pipeline_callback(
            CreatePipelineAsyncStatus status,
            impl::ComputePipeline pipeline,
            CStr msg,
            void* promise_raw
        ) -> void;
        [[nodiscard]] inline auto create_compute_pipeline_async(
            const ComputePipelineDescriptor& desc,
            CreateComputePipelineAsyncCallback&& callback = Device::create_compute_pipeline_callback
        ) -> std::future<ComputePipeline>; 
        [[nodiscard]] inline auto create_pipeline_layout(const PipelineLayoutDescriptor& desc) -> PipelineLayout;
        [[nodiscard]] inline auto create_query_set(const QuerySetDescriptor& desc) -> QuerySet;
        [[nodiscard]] inline auto create_render_bundle_encoder(const RenderBundleEncoderDescriptor& desc) -> RenderBundleEncoder;
        [[nodiscard]] inline auto create_render_pipeline(const RenderPipelineDescriptor& desc) -> RenderPipeline;
        static auto create_render_pipeline_callback(
            CreatePipelineAsyncStatus status,
            impl::RenderPipeline pipeline, 
            CStr msg,
            void* promise_raw
        ) -> void;
        [[nodiscard]] inline auto create_render_pipeline_async(
            const RenderPipelineDescriptor& desc,
            CreateRenderPipelineAsyncCallback&& callback = Device::create_render_pipeline_callback
        ) -> std::future<RenderPipeline>;
        [[nodiscard]] inline auto create_sampler(const SamplerDescriptor& desc) -> Sampler;
        [[nodiscard]] inline auto create_shader_module(const ShaderModuleDescriptor& desc) -> ShaderModule;
        [[nodiscard]] inline auto create_swapchain(Surface& surface, const SwapChainDescriptor& desc) -> SwapChain;
        [[nodiscard]] inline auto create_texture(const TextureDescriptor& desc) -> Texture;
        inline auto destroy() -> void;
        [[nodiscard]] inline auto enumerate_features(FeatureName* features) -> size_t;
        inline auto get_limits(SupportedLimits* limits) -> bool;
        [[nodiscard]] inline auto get_queue() -> Queue;
        [[nodiscard]] inline auto has_feature(FeatureName feature) -> bool;
        inline auto pop_error_scope(ErrorCallback&& callback, void* user_data) -> void;
        inline auto push_error_scope(ErrorFilter filter) -> void;
        inline auto label(CStr label) -> void;
        inline auto set_uncaptured_error_callback(ErrorCallback&& callback, void* user_data) -> void;
    END 

    HANDLE(Instance)
        [[nodiscard]] static inline auto init(const InstanceDescriptor& desc) -> Instance;
        [[nodiscard]] static inline auto init() -> Instance;
        [[nodiscard]] inline auto create_surface(const SurfaceDescriptor& desc) -> Surface; 
        static auto request_adapter_callback(
            RequestAdapterStatus status,
            impl::Adapter adapter,
            CStr msg,
            void* promise_raw
        ) -> void;
        [[nodiscard]] inline auto request_adapter(
            const RequestAdapterOptions& opts,
            RequestAdapterCallback&& callback = Instance::request_adapter_callback
        ) -> Adapter;
        [[nodiscard]] inline auto request_adapter_async(
            const RequestAdapterOptions& opts,
            RequestAdapterCallback&& callback = Instance::request_adapter_callback
        ) -> std::future<Adapter>;
        inline auto process_events() -> void;
    END

    HANDLE(PipelineLayout)
        inline auto label(CStr label) -> void;
    END

    HANDLE(QuerySet)
        inline auto destroy() -> void;
        [[nodiscard]] inline auto get_count() -> uint32_t;
        [[nodiscard]] inline auto get_type() -> QueryType;
        inline auto label(CStr label) -> void;
    END

    HANDLE(Queue)
        static auto on_submitted_work_done_callback(QueueWorkDoneStatus status, void* promise_raw) -> void;
        inline auto on_submitted_work_done(
            QueueWorkDoneCallback&& callback
        ) -> void;
        [[nodiscard]] inline auto on_submitted_work_done_async(
            QueueWorkDoneCallback&& callback
        ) -> std::future<void>; 
        inline auto label(CStr label) -> void;
        inline auto submit(size_t command_count, CommandBuffer const* commands) -> void;
        inline auto write_buffer(
            Buffer& buffer,
            uint64_t buffer_offset,
            void const* data,
            size_t size
        ) -> void;
        inline auto write_texture(
            ImageCopyTexture& dest,
            void const* data,
            size_t data_size,
            const TextureDataLayout& data_layout,
            const Extent3D& write_size
        ) -> void;
    END

    HANDLE(RenderBundle)
    END

    HANDLE(RenderBundleEncoder)
        inline auto draw(
            uint32_t vertex_count,
            uint32_t instance_count,
            uint32_t first_vertex,
            uint32_t first_instance
        ) -> void;
        inline auto draw_indexed(
           uint32_t index_count, 
           uint32_t instance_count,
           uint32_t first_index,
           int32_t base_vertex,
           int32_t first_instance
        ) -> void;
        inline auto draw_indexed_indirect(Buffer& indirect_buffer, uint64_t indirect_offset) -> void;
        inline auto draw_indirect(Buffer& indirect_buffer, uint64_t indirect_offset) -> void;
        [[nodiscard]] inline auto finish(const RenderBundleEncoderDescriptor& desc) -> RenderBundle;
        inline auto insert_debug_marker(CStr marker_label) -> void;
        inline auto pop_debug_group() -> void;
        inline auto push_debug_group(CStr group_label) -> void;
        inline auto set_bind_group(
            uint32_t group_idx,
            BindGroup& group,
            size_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        inline auto set_index_buffer(
            Buffer& buffer,
            IndexFormat format,
            uint64_t offset,
            uint64_t size
        ) -> void;
        inline auto label(CStr label) -> void;
        inline auto set_pipeline(RenderPipeline& pipeline) -> void;
        inline auto set_vertex_buffer(
            uint32_t slot,
            Buffer& buffer,
            uint64_t offset, uint64_t size
        ) -> void;
    END

    HANDLE(RenderPassEncoder)
        inline auto begin_occlusion_query(uint32_t query_idx) -> void;
        inline auto begin_pipeline_statistics_query(QuerySet& query_set, uint32_t query_idx) -> void;
        inline auto draw(
            uint32_t vertex_count,
            uint32_t instance_count,
            uint32_t first_vertex,
            uint32_t first_instance
        ) -> void;
        inline auto draw_indexed(
            uint32_t index_count,
            uint32_t instance_count,
            uint32_t first_index,
            int32_t base_vertex,
            uint32_t first_instance 
        ) -> void;
        inline auto draw_indexed_indirect(Buffer& indirect_buffer, uint64_t indirect_offset) -> void;
        inline auto draw_indirect(Buffer& indirect_buffer, uint64_t indirect_offset) -> void;
        inline auto end() -> void;
        inline auto end_occluion_query() -> void; 
        inline auto end_pipeline_statistics_query() -> void;
        inline auto execute_bundles(size_t bundle_count, RenderBundle const* bundles) -> void;
        inline auto insert_debug_marker(CStr marker_label) -> void;
        inline auto pop_debug_group() -> void;
        inline auto push_debug_group(CStr group_label) -> void;
        inline auto set_bind_group(
            uint32_t group_idx,
            BindGroup& group,
            size_t dynamic_offset_count,
            uint32_t const* dynamic_offsets
        ) -> void;
        inline auto set_blend_constant(const Color& color) -> void;
        inline auto set_index_buffer(
            Buffer& buffer,
            IndexFormat format,
            uint64_t offset,
            uint64_t size
        ) -> void;
        inline auto label(CStr label) -> void;
        inline auto set_pipeline(RenderPipeline& pipeline) -> void;
        inline auto set_scissor_rect(
            uint32_t x,
            uint32_t y,
            uint32_t width,
            uint32_t height
        ) -> void;
        inline auto set_stencil_reference(uint32_t reference) -> void;
        inline auto set_vertex_buffer(
            uint32_t slot,
            Buffer& buffer,
            uint64_t offset,
            uint64_t size
        ) -> void;
        inline auto set_viewport(
            float x,
            float y,
            float width,
            float height,
            float min_depth,
            float max_depth
        ) -> void;
    END

    HANDLE(RenderPipeline)
        [[nodiscard]] inline auto get_bind_group_layout(uint32_t group_idx) -> BindGroupLayout;
        inline auto label(CStr label) -> void;
    END

    HANDLE(Sampler)
        inline auto label(CStr label) -> void;
    END

    HANDLE(ShaderModule)
        static auto get_compilation_info_callback(
            CompilationInfoRequestStatus status,
            CompilationInfo* compilation_info,
            void* user_data
        ) -> void;
        [[nodiscard]] inline auto get_compilation_info(
            CompilationInfoCallback&& callback = ShaderModule::get_compilation_info_callback
        ) -> CompilationInfo;
        [[nodiscard]] inline auto get_compilation_info_async(
            CompilationInfoCallback&& callback = ShaderModule::get_compilation_info_callback
        ) -> std::future<CompilationInfo>;
        inline auto label(CStr label) -> void;
    END

    HANDLE(Surface)
        [[nodiscard]] inline auto get_preferred_format(Adapter& adapter) -> TextureFormat;
    END

    HANDLE(SwapChain)
        [[nodiscard]] inline auto get_current_texture_view() -> TextureView;
        inline auto present() -> void;
    END

    HANDLE(Texture)
        [[nodiscard]] inline auto create_view(const TextureViewDescriptor& desc) -> TextureView;
        inline auto destroy() -> void;
        [[nodiscard]] inline auto get_depth_or_array_layers() -> uint32_t;
        [[nodiscard]] inline auto get_dimension() -> TextureDimension;
        [[nodiscard]] inline auto get_format() -> TextureFormat;
        [[nodiscard]] inline auto get_height() -> uint32_t;
        [[nodiscard]] inline auto get_mip_level_count() -> uint32_t;
        [[nodiscard]] inline auto get_sample_count() -> uint32_t;
        [[nodiscard]] inline auto get_usage() -> TextureUsageFlags;
        [[nodiscard]] inline auto get_width() -> uint32_t;
        inline auto label(CStr label) -> void;
    END

    HANDLE(TextureView)
        inline auto label(CStr label) -> void;
    END

    // Adapter Methods

    auto Adapter::enumerate_features(FeatureName* features) -> size_t {
        return native::wgpuAdapterEnumerateFeatures(*this, features);
    }

    auto Adapter::get_limits(SupportedLimits* limits) -> bool {
        return native::wgpuAdapterGetLimits(*this, limits);
    }

    auto Adapter::get_properties(AdapterProperties* props) -> void {
        return native::wgpuAdapterGetProperties(*this, props);
    }

    auto Adapter::has_feature(FeatureName feature) -> bool {
        return native::wgpuAdapterHasFeature(*this, feature);
    }

    auto Adapter::request_device_callback(
        RequestDeviceAsyncStatus status,
        impl::Device device,
        CStr msg,
        void* promise_raw
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<Device>*>(promise_raw);
        if (status != RequestDeviceAsyncStatus::Success) {
            promise.set_exception(catchme(status, msg));
        } else {
            promise.set_value({device});
        }
    };

    auto Adapter::request_device(
        const DeviceDescriptor& desc,
        RequestDeviceCallback&& callback
    ) -> Device {
        return this->request_device_async(
            desc,
            std::forward<RequestDeviceCallback>(callback)
        ).get();
    }

    auto Adapter::request_device_async(
        const DeviceDescriptor& desc,
        RequestDeviceCallback&& callback
    ) -> std::future<Device> {
        auto promise = std::promise<Device>{};

        native::wgpuAdapterRequestDevice(
            *this,
            &desc,
            callback,
            &promise
        );

        return promise.get_future();
    }

    // BindGroup Methods
    auto BindGroup::label(CStr label) -> void {
        return native::wgpuBindGroupSetLabel(*this, label);
    }

    // BindGroupLayoutMethods
    
    auto BindGroupLayout::label(CStr label) -> void {
        return native::wgpuBindGroupLayoutSetLabel(*this, label);
    }

    // Buffer Methods
    
    auto Buffer::label(CStr label) -> void {
        return native::wgpuBufferSetLabel(*this, label);
    }

    auto Buffer::destroy() -> void {
        return native::wgpuBufferDestroy(*this);
    }

    auto Buffer::get_const_mapped_range(size_t offset, size_t size) -> void const* {
        return native::wgpuBufferGetConstMappedRange(*this, offset, size);
    }

    auto Buffer::get_map_state() -> BufferMapState {
        return native::wgpuBufferGetMapState(*this);
    }

    auto Buffer::get_size() -> uint64_t {
        return native::wgpuBufferGetSize(*this);
    }

    auto Buffer::get_usage() -> BufferUsageFlags {
        return native::wgpuBufferGetUsage(*this);
    }

    auto Buffer::map_callback(BufferMapAsyncStatus status, void* promise_raw) -> void {
        auto& promise = *reinterpret_cast<std::promise<void>*>(promise_raw);
        if (status != BufferMapAsyncStatus::Success) {
            promise.set_exception(catchme(status));
        } else {
            promise.set_value();
        }
    }

    auto Buffer::map_async(
        MapModeFlags mode,
        size_t offset,
        size_t size,
        BufferMapCallback&& callback
    ) -> std::future<void> {
        auto promise = std::promise<void>{};
            
        native::wgpuBufferMapAsync(
            *this,
            mode,
            offset,
            size,
            callback,
            &promise
        );

        return promise.get_future();
    }

    auto Buffer::unmap() -> void {
        return native::wgpuBufferUnmap(*this);
    }

    // CommandBuffer Methods

    auto CommandBuffer::label(CStr label) -> void {
        return native::wgpuCommandBufferSetLabel(*this, label);
    }

    // CommandEncoder Methods

    auto CommandEncoder::begin_compute_pass(const ComputePassDescriptor& desc) -> ComputePassEncoder {
        return { native::wgpuCommandEncoderBeginComputePass(*this, &desc) };
    }

    auto CommandEncoder::begin_render_pass(const RenderPassDescriptor& desc) -> RenderPassEncoder {
        return { native::wgpuCommandEncoderBeginRenderPass(*this, &desc) };
    }

    auto CommandEncoder::clear_buffer(Buffer& buffer, uint64_t offset, uint64_t size) -> void {
        return native::wgpuCommandEncoderClearBuffer(*this, buffer, offset, size);
    }

    auto CommandEncoder::copy_buffer_to_buffer(
        const Buffer& src,
        uint64_t src_offset,
        Buffer& dest,
        uint64_t dest_offset,
        uint64_t size
    ) -> void {
        return native::wgpuCommandEncoderCopyBufferToBuffer(*this, src, src_offset, dest, dest_offset, size);
    }

    auto CommandEncoder::copy_buffer_to_texture(
        const ImageCopyBuffer& src,
        ImageCopyTexture& dest,
        const Extent3D& size
    ) -> void {
        return native::wgpuCommandEncoderCopyBufferToTexture(*this, &src, &dest, &size);
    }

    auto CommandEncoder::copy_texture_to_buffer(
        const ImageCopyTexture& src,
        ImageCopyBuffer& dest,
        const Extent3D& size
    ) -> void {
        return native::wgpuCommandEncoderCopyTextureToBuffer(*this, &src, &dest, &size);
    }

    auto CommandEncoder::copy_texture_to_texture(
        const ImageCopyTexture& src,
        ImageCopyTexture& dest,
        const Extent3D& size
    ) -> void {
        return native::wgpuCommandEncoderCopyTextureToTexture(*this, &src, &dest, &size);
    }

    auto CommandEncoder::finish(const CommandBufferDescriptor& desc) -> CommandBuffer {
        return { native::wgpuCommandEncoderFinish(*this, &desc) };
    }

    auto CommandEncoder::insert_debug_marker(CStr marker_label) -> void {
        return native::wgpuCommandEncoderInsertDebugMarker(*this, marker_label);
    }

    auto CommandEncoder::pop_debug_group() -> void {
        return native::wgpuCommandEncoderPopDebugGroup(*this);
    }

    auto CommandEncoder::push_debug_group(CStr group_label) -> void {
        return native::wgpuCommandEncoderPushDebugGroup(*this, group_label);
    }

    auto CommandEncoder::resolve_query_set(
        const QuerySet& query_set,
        uint32_t first_query,
        uint32_t query_count,
        Buffer& dest,
        uint64_t dest_offset
    ) -> void {
        return native::wgpuCommandEncoderResolveQuerySet(*this, query_set, first_query, query_count, dest, dest_offset);
    }

    auto CommandEncoder::label(CStr label) -> void {
       return native::wgpuCommandEncoderSetLabel(*this, label); 
    }

    // ComputePassEncoder Methods

    auto ComputePassEncoder::begin_pipeline_statistics_query(const QuerySet& query_set, uint32_t query_idx) -> void {
        return native::wgpuComputePassEncoderBeginPipelineStatisticsQuery(*this, query_set, query_idx);
    }

    auto ComputePassEncoder::dispatch_workgroups(
        uint32_t workgroup_count_x,
        uint32_t workgroup_count_y,
        uint32_t workgroup_count_z
    ) -> void {
        return native::wgpuComputePassEncoderDispatchWorkgroups(*this, workgroup_count_x, workgroup_count_y, workgroup_count_z);
    }

    auto ComputePassEncoder::dispatch_workgroups_indirect(
       Buffer& indirect_buffer,
       uint64_t indirect_offset
    ) -> void {
        return native::wgpuComputePassEncoderDispatchWorkgroupsIndirect(*this, indirect_buffer, indirect_offset);
    }

    auto ComputePassEncoder::end() -> void {
        return native::wgpuComputePassEncoderEnd(*this);
    }

    auto ComputePassEncoder::insert_debug_marker(CStr marker_label) -> void {
        return native::wgpuComputePassEncoderInsertDebugMarker(*this, marker_label);
    }

    auto ComputePassEncoder::pop_debug_group() -> void {
        return native::wgpuComputePassEncoderPopDebugGroup(*this);
    }

    auto ComputePassEncoder::push_debug_group(CStr group_label) -> void {
        return native::wgpuComputePassEncoderPushDebugGroup(*this, group_label);
    }

    auto ComputePassEncoder::set_bind_group(
        uint32_t group_idx,
        BindGroup& bind_group,
        size_t dynamic_offset_count,
        uint32_t const* dynamic_offsets
    ) -> void {
        return native::wgpuComputePassEncoderSetBindGroup(
            *this,
            group_idx,
            bind_group,
            dynamic_offset_count,
            dynamic_offsets
        );
    }

    auto ComputePassEncoder::label(CStr label) -> void {
        return native::wgpuComputePassEncoderSetLabel(*this, label);
    }

    auto ComputePassEncoder::set_pipeline(ComputePipeline& pipeline) -> void {
        return native::wgpuComputePassEncoderSetPipeline(*this, pipeline);
    }

    // ComputePipeline Methods
    
    auto ComputePipeline::get_bind_group_layout(uint32_t group_idx) -> BindGroupLayout {
        return { native::wgpuComputePipelineGetBindGroupLayout(*this, group_idx) };
    }

    auto ComputePipeline::label(CStr label) -> void {
        return native::wgpuComputePipelineSetLabel(*this, label);
    }

    // Device Methods

    auto Device::create_bind_group(const BindGroupDescriptor& desc) -> BindGroup {
        return { native::wgpuDeviceCreateBindGroup(*this, &desc) };
    }

    auto Device::create_bind_group_layout(const BindGroupLayoutDescriptor& desc) -> BindGroupLayout {
        return { native::wgpuDeviceCreateBindGroupLayout(*this, &desc) };
    }

    auto Device::create_buffer(const BufferDescriptor& desc) -> Buffer {
        return { native::wgpuDeviceCreateBuffer(*this, &desc) };
    } 

    auto Device::create_command_encoder(const CommandEncoderDescriptor& desc) -> CommandEncoder {
        return { native::wgpuDeviceCreateCommandEncoder(*this, &desc) };
    }

    auto Device::create_compute_pipeline(const ComputePipelineDescriptor& desc) -> ComputePipeline {
        return { native::wgpuDeviceCreateComputePipeline(*this, &desc) };
    }

    auto Device::create_compute_pipeline_callback(
        CreatePipelineAsyncStatus status,
        impl::ComputePipeline pipeline,
        CStr msg,
        void* promise_raw
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<ComputePipeline>*>(promise_raw);
        if (status != CreatePipelineAsyncStatus::Success) {
            promise.set_exception(catchme(status, msg));
        } else {
            promise.set_value({pipeline});
        }
    }

    auto Device::create_compute_pipeline_async(
        const ComputePipelineDescriptor& desc, 
        CreateComputePipelineAsyncCallback&& callback
    ) -> std::future<ComputePipeline> {
        auto promise = std::promise<ComputePipeline>{};

        native::wgpuDeviceCreateComputePipelineAsync(
            *this,
            &desc,
            callback,
            &promise
        );

        return promise.get_future();
    }

    auto Device::create_pipeline_layout(const PipelineLayoutDescriptor& desc) -> PipelineLayout {
        return { native::wgpuDeviceCreatePipelineLayout(*this, &desc) };
    }

    auto Device::create_query_set(const QuerySetDescriptor& desc) -> QuerySet {
        return { native::wgpuDeviceCreateQuerySet(*this, &desc) };
    }

    auto Device::create_render_bundle_encoder(const RenderBundleEncoderDescriptor& desc) -> RenderBundleEncoder {
        return { native::wgpuDeviceCreateRenderBundleEncoder(*this, &desc) };
    }

    auto Device::create_render_pipeline(const RenderPipelineDescriptor& desc) -> RenderPipeline {
        return { native::wgpuDeviceCreateRenderPipeline(*this, &desc) };
    }

    auto Device::create_render_pipeline_callback(
        CreatePipelineAsyncStatus status,
        impl::RenderPipeline pipeline,
        CStr msg,
        void* promise_raw
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<RenderPipeline>*>(promise_raw);
        if (status != CreatePipelineAsyncStatus::Success) { 
            promise.set_exception(catchme(status, msg));
        } else {
            promise.set_value({pipeline});
        }
    }

    auto Device::create_render_pipeline_async(
        const RenderPipelineDescriptor& desc,
        CreateRenderPipelineAsyncCallback&& callback
    ) -> std::future<RenderPipeline> {
        auto promise = std::promise<RenderPipeline>{};

        native::wgpuDeviceCreateRenderPipelineAsync(
            *this,
            &desc,
            callback,
            &promise
        );

        return promise.get_future();
    }

    auto Device::create_sampler(const SamplerDescriptor& desc) -> Sampler {
        return { native::wgpuDeviceCreateSampler(*this, &desc) };
    }

    auto Device::create_shader_module(const ShaderModuleDescriptor& desc) -> ShaderModule {
        return { native::wgpuDeviceCreateShaderModule(*this, &desc) };
    }

    auto Device::create_swapchain(Surface& surface, const SwapChainDescriptor& desc) -> SwapChain {
        return { native::wgpuDeviceCreateSwapChain(*this, surface, &desc) };
    }

    auto Device::create_texture(const TextureDescriptor& desc) -> Texture {
        return { native::wgpuDeviceCreateTexture(*this, &desc) };
    }

    auto Device::destroy() -> void {
        return native::wgpuDeviceDestroy(*this);
    }

    auto Device::enumerate_features(FeatureName* features) -> size_t {
        return native::wgpuDeviceEnumerateFeatures(*this, features);
    }

    auto Device::get_limits(SupportedLimits* limits) -> bool {
        return native::wgpuDeviceGetLimits(*this, limits);
    }

    auto Device::get_queue() -> Queue {
        return { native::wgpuDeviceGetQueue(*this) };
    }

    auto Device::has_feature(FeatureName feature) -> bool {
        return native::wgpuDeviceHasFeature(*this, feature);
    }

    auto Device::pop_error_scope(
        ErrorCallback&& callback,
        void* user_data 
    ) -> void {
        native::wgpuDevicePopErrorScope(
            *this,
            callback,
            user_data
        );
    }

    auto Device::push_error_scope(ErrorFilter filter) -> void {
        return native::wgpuDevicePushErrorScope(*this, filter);
    }

    auto Device::label(CStr label) -> void {
        return native::wgpuDeviceSetLabel(*this, label);
    }

    auto Device::set_uncaptured_error_callback(ErrorCallback&& callback, void* user_data) -> void {
        return native::wgpuDeviceSetUncapturedErrorCallback(*this, callback, user_data);
    }

    // Instance Methods

    auto Instance::init(const InstanceDescriptor& desc) -> Instance {
        return { native::wgpuCreateInstance(&desc) };    
    }

    auto Instance::init() -> Instance {
        const auto desc = InstanceDescriptor{};
        return { native::wgpuCreateInstance(&desc) };
    }

    auto Instance::create_surface(const SurfaceDescriptor& desc) -> Surface {
        return { native::wgpuInstanceCreateSurface(*this, &desc) } ;
    }

    auto Instance::request_adapter_callback(
        RequestAdapterStatus status,
        impl::Adapter adapter,
        CStr msg,
        void* promise_raw 
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<Adapter>*>(promise_raw);
        if (status != RequestAdapterStatus::Success) {
            promise.set_exception(catchme(status, msg));
        } else {
            promise.set_value({adapter});
        }
    }

    auto Instance::request_adapter(
        const RequestAdapterOptions& opts,
        RequestAdapterCallback&& callback
    ) -> Adapter {
        return this->request_adapter_async(
            opts,
            std::forward<RequestAdapterCallback>(callback)
        ).get();
    }

    auto Instance::request_adapter_async(
        const RequestAdapterOptions& opts,
        RequestAdapterCallback&& callback
    ) -> std::future<Adapter> {
        auto promise = std::promise<Adapter>{};

        native::wgpuInstanceRequestAdapter(
            *this,
            &opts,
            callback,
            &promise
        );

        return promise.get_future();
    }

    // PipelineLayout Methods
    
    auto PipelineLayout::label(CStr label) -> void {
        return native::wgpuPipelineLayoutSetLabel(*this, label);
    }

    // QuerySet Methods

    auto QuerySet::destroy() -> void {
        return native::wgpuQuerySetDestroy(*this);
    }

    auto QuerySet::get_count() -> uint32_t {
        return native::wgpuQuerySetGetCount(*this);
    }

    auto QuerySet::get_type() -> QueryType {
        return native::wgpuQuerySetGetType(*this);
    }

    // Queue Methods
    
    auto Queue::on_submitted_work_done_callback(
        QueueWorkDoneStatus status,
        void* promise_raw
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<void>*>(promise_raw);
        if (status != QueueWorkDoneStatus::Success) {
            promise.set_exception(catchme(status));
        } else {
            promise.set_value();
        }
    }

    auto Queue::on_submitted_work_done(QueueWorkDoneCallback&& callback) -> void {
        this->on_submitted_work_done_async(std::forward<QueueWorkDoneCallback>(callback)).get();
    }

    auto Queue::on_submitted_work_done_async(QueueWorkDoneCallback&& callback) -> std::future<void> {
        auto promise = std::promise<void>{};

        native::wgpuQueueOnSubmittedWorkDone(
            *this,
            callback,
            &promise
        );

        return promise.get_future();
    }

    auto Queue::label(CStr label) -> void {
        return native::wgpuQueueSetLabel(*this, label);
    }

    auto Queue::submit(size_t command_count, CommandBuffer const* commands) -> void { // TODO: Might be wrong
        return native::wgpuQueueSubmit(*this, command_count, reinterpret_cast<impl::CommandBuffer const*>(commands));
    }

    auto Queue::write_buffer(
        Buffer& buffer,
        uint64_t offset,
        void const* data,
        size_t size
    ) -> void {
        return native::wgpuQueueWriteBuffer(
            *this,
            buffer,
            offset,
            data,
            size
        );
    }

    auto Queue::write_texture(
        ImageCopyTexture& dest,
        void const* data,
        size_t data_size,
        const TextureDataLayout& data_layout,
        const Extent3D& write_size
    ) -> void {
        return native::wgpuQueueWriteTexture(
            *this,
            &dest,
            data,
            data_size,
            &data_layout,
            &write_size
        );
    }

    // RenderBundle Methods
    
    auto RenderBundleEncoder::label(CStr label) -> void {
        return native::wgpuRenderBundleEncoderSetLabel(*this, label);
    }
    
    auto RenderBundleEncoder::draw(
        uint32_t vertex_count,
        uint32_t instance_count,
        uint32_t first_vertex,
        uint32_t first_instance
    ) -> void {
        return native::wgpuRenderBundleEncoderDraw(
            *this,
            vertex_count,
            instance_count,
            first_vertex,
            first_instance
        );
    }

    auto RenderBundleEncoder::draw_indexed(
        uint32_t index_count,
        uint32_t instance_count,
        uint32_t first_index,
        int32_t base_vertex,
        int32_t first_instance
    ) -> void {
        return native::wgpuRenderBundleEncoderDrawIndexed(
            *this,
            index_count,
            instance_count,
            first_index,
            base_vertex,
            first_instance
        );
    }

    auto RenderBundleEncoder::draw_indexed_indirect(
        Buffer& indirect_buffer,
        uint64_t indirect_offset
    ) -> void {
        return native::wgpuRenderBundleEncoderDrawIndexedIndirect(*this, indirect_buffer, indirect_offset);
    }

    auto RenderBundleEncoder::draw_indirect(
        Buffer& indirect_buffer,
        uint64_t indirect_offset
    ) -> void {
        return native::wgpuRenderBundleEncoderDrawIndirect(*this, indirect_buffer, indirect_offset);
    }

    auto RenderBundleEncoder::finish(const RenderBundleEncoderDescriptor& desc) -> RenderBundle {
        return { native::wgpuRenderBundleEncoderFinish(*this, &desc) };
    }

    auto RenderBundleEncoder::insert_debug_marker(CStr marker_label) -> void {
        return native::wgpuRenderBundleEncoderInsertDebugMarker(*this, marker_label);
    }

    auto RenderBundleEncoder::pop_debug_group() -> void {
        return native::wgpuRenderBundleEncoderPopDebugGroup(*this);
    }

    auto RenderBundleEncoder::push_debug_group(CStr group_label) -> void {
        return native::wgpuRenderBundleEncoderPushDebugGroup(*this, group_label); 
    }

    auto RenderBundleEncoder::set_bind_group(
        uint32_t group_idx,
        BindGroup& group,
        size_t dynamic_offset_count,
        uint32_t const* dynamic_offsets
    ) -> void {
        return native::wgpuRenderBundleEncoderSetBindGroup(
            *this,
            group_idx,
            group,
            dynamic_offset_count,
            dynamic_offsets
        );
    }

    auto RenderBundleEncoder::set_index_buffer(
        Buffer& buffer,
        IndexFormat format,
        uint64_t offset,
        uint64_t size
    ) -> void {
        return native::wgpuRenderBundleEncoderSetIndexBuffer(
            *this,
            buffer,
            format,
            offset,
            size
        );
    }

    auto RenderBundleEncoder::set_pipeline(RenderPipeline& render_pipeline) -> void {
        return native::wgpuRenderBundleEncoderSetPipeline(*this, render_pipeline);
    }

    auto RenderBundleEncoder::set_vertex_buffer(
        uint32_t slot,
        Buffer& buffer,
        uint64_t offset,
        uint64_t size
    ) -> void {
        return native::wgpuRenderBundleEncoderSetVertexBuffer(
            *this,
            slot,
            buffer,
            offset,
            size
        );
    }

    // RenderPassEncoder Methods

    auto RenderPassEncoder::begin_occlusion_query(uint32_t query_idx) -> void {
        return native::wgpuRenderPassEncoderBeginOcclusionQuery(*this, query_idx);
    }

    auto RenderPassEncoder::begin_pipeline_statistics_query(QuerySet& query_set, uint32_t query_idx) -> void {
        return native::wgpuRenderPassEncoderBeginPipelineStatisticsQuery(*this, query_set, query_idx);
    }

    auto RenderPassEncoder::draw(
        uint32_t vertex_count,
        uint32_t instance_count,
        uint32_t first_vertex,
        uint32_t first_instance
    ) -> void {
        return native::wgpuRenderPassEncoderDraw(
            *this,
            vertex_count,
            instance_count,
            first_vertex,
            first_instance
        );
    }
    
    auto RenderPassEncoder::draw_indexed(
        uint32_t index_count,
        uint32_t instance_count,
        uint32_t first_index,
        int32_t base_vertex,
        uint32_t first_instance
    ) -> void {
        return native::wgpuRenderPassEncoderDrawIndexed(
            *this,
            index_count,
            instance_count,
            first_index,
            base_vertex,
            first_instance
        );
    }

    auto RenderPassEncoder::draw_indexed_indirect(
        Buffer& indirect_buffer,
        uint64_t indirect_offset
    ) -> void {
        return native::wgpuRenderPassEncoderDrawIndexedIndirect(
            *this,
            indirect_buffer,
            indirect_offset
        );
    }

    auto RenderPassEncoder::draw_indirect(
        Buffer& indirect_buffer,
        uint64_t indirect_offset
    ) -> void {
        return native::wgpuRenderPassEncoderDrawIndirect(
            *this,
            indirect_buffer,
            indirect_offset
        );
    }

    auto RenderPassEncoder::end() -> void {
        return native::wgpuRenderPassEncoderEnd(*this);
    }

    auto RenderPassEncoder::end_occluion_query() -> void {
        return native::wgpuRenderPassEncoderEndOcclusionQuery(*this);
    }

    auto RenderPassEncoder::end_pipeline_statistics_query() -> void {
        return native::wgpuRenderPassEncoderEndPipelineStatisticsQuery(*this);
    }

    auto RenderPassEncoder::execute_bundles(size_t bundle_count, RenderBundle const* bundles) -> void {
        return native::wgpuRenderPassEncoderExecuteBundles(*this, bundle_count, reinterpret_cast<impl::RenderBundle const*>(bundles));
    }

    auto RenderPassEncoder::insert_debug_marker(CStr marker_label) -> void {
        return native::wgpuRenderPassEncoderInsertDebugMarker(*this, marker_label);
    }

    auto RenderPassEncoder::pop_debug_group() -> void {
        return native::wgpuRenderPassEncoderPopDebugGroup(*this);
    }

    auto RenderPassEncoder::push_debug_group(CStr group_label) -> void {
        return native::wgpuRenderPassEncoderPushDebugGroup(*this, group_label);
    }

    auto RenderPassEncoder::set_bind_group(
        uint32_t group_idx,
        BindGroup& group,
        size_t dynamic_offset_count,
        uint32_t const* dynamic_offsets
    ) -> void {
        return native::wgpuRenderPassEncoderSetBindGroup(
            *this,
            group_idx,
            group,
            dynamic_offset_count,
            dynamic_offsets
        );
    }

    auto RenderPassEncoder::set_blend_constant(const Color& color) -> void {
        return native::wgpuRenderPassEncoderSetBlendConstant(*this, &color);
    }

    auto RenderPassEncoder::set_index_buffer(
        Buffer& buffer,
        IndexFormat format,
        uint64_t offset,
        uint64_t size
    ) -> void {
        return native::wgpuRenderPassEncoderSetIndexBuffer(
            *this,
            buffer,
            format,
            offset,
            size
        );
    }

    auto RenderPassEncoder::label(CStr label) -> void {
        return native::wgpuRenderPassEncoderSetLabel(*this, label);
    }

    auto RenderPassEncoder::set_pipeline(RenderPipeline& pipeline) -> void {
        return native::wgpuRenderPassEncoderSetPipeline(*this, pipeline);
    }

    auto RenderPassEncoder::set_scissor_rect(
        uint32_t x,
        uint32_t y,
        uint32_t width,
        uint32_t height
    ) -> void {
        return native::wgpuRenderPassEncoderSetScissorRect(*this, x, y, width, height);
    }

    auto RenderPassEncoder::set_stencil_reference(uint32_t reference) -> void {
        return native::wgpuRenderPassEncoderSetStencilReference(*this, reference);
    }

    auto RenderPassEncoder::set_vertex_buffer(
        uint32_t slot,
        Buffer& buffer,
        uint64_t offset,
        uint64_t size
    ) -> void {
        return native::wgpuRenderPassEncoderSetVertexBuffer(
            *this,
            slot,
            buffer,
            offset,
            size
        );
    }

    auto RenderPassEncoder::set_viewport(
        float x,
        float y,
        float width,
        float height,
        float min_depth,
        float max_depth
    ) -> void {
        return native::wgpuRenderPassEncoderSetViewport(
            *this,
            x,
            y,
            width,
            height,
            min_depth,
            max_depth
        );
    }

    // RenderPipeline Methods

    auto RenderPipeline::get_bind_group_layout(uint32_t group_idx) -> BindGroupLayout {
        return { native::wgpuRenderPipelineGetBindGroupLayout(*this, group_idx) };
    }

    auto RenderPipeline::label(CStr label) -> void {
        return native::wgpuRenderPipelineSetLabel(*this, label);
    }

    // Sampler Methods
    
    auto Sampler::label(CStr label) -> void {
        return native::wgpuSamplerSetLabel(*this, label);
    }

    // ShaderModule Methods

    auto ShaderModule::get_compilation_info_callback(
        CompilationInfoRequestStatus status,
        CompilationInfo* compilation_info,
        void* promise_raw
    ) -> void {
        auto& promise = *reinterpret_cast<std::promise<CompilationInfo>*>(promise_raw);
        if (status != CompilationInfoRequestStatus::Success) {
            promise.set_exception(catchme(status));
        } else {
            promise.set_value(*compilation_info);
        }
    }

    auto ShaderModule::get_compilation_info(CompilationInfoCallback&& callback) -> CompilationInfo {
        return this->get_compilation_info_async(std::forward<CompilationInfoCallback>(callback)).get();
    }

    auto ShaderModule::get_compilation_info_async(CompilationInfoCallback&& callback) -> std::future<CompilationInfo> {
        auto promise = std::promise<CompilationInfo>{};

        native::wgpuShaderModuleGetCompilationInfo(
            *this,
            callback,
            &promise
        );

        return promise.get_future();
    }

    auto ShaderModule::label(CStr label) -> void {
        return native::wgpuShaderModuleSetLabel(*this, label);
    }

    // Surface Methods

    auto Surface::get_preferred_format(Adapter& adapter) -> TextureFormat {
        return native::wgpuSurfaceGetPreferredFormat(*this, adapter);
    }

    // SwapChain Methods

    auto SwapChain::get_current_texture_view() -> TextureView {
        return { native::wgpuSwapChainGetCurrentTextureView(*this) };
    }

    auto SwapChain::present() -> void {
        return native::wgpuSwapChainPresent(*this);
    }

    // Texture Methods

    auto Texture::create_view(const TextureViewDescriptor& desc) -> TextureView {
        return { native::wgpuTextureCreateView(*this, &desc) };
    }

    auto Texture::destroy() -> void {
        return native::wgpuTextureDestroy(*this);
    }

    auto Texture::get_depth_or_array_layers() -> uint32_t {
        return native::wgpuTextureGetDepthOrArrayLayers(*this);
    }

    auto Texture::get_dimension() -> TextureDimension {
        return native::wgpuTextureGetDimension(*this);
    }

    auto Texture::get_format() -> TextureFormat {
        return native::wgpuTextureGetFormat(*this);
    }

    auto Texture::get_height() -> uint32_t {
        return native::wgpuTextureGetHeight(*this);
    }

    auto Texture::get_mip_level_count() -> uint32_t {
        return native::wgpuTextureGetMipLevelCount(*this);
    }

    auto Texture::get_sample_count() -> uint32_t {
        return native::wgpuTextureGetSampleCount(*this);
    }

    auto Texture::get_usage() -> TextureUsageFlags {
        return native::wgpuTextureGetUsage(*this);
    }

    auto Texture::label(CStr label) -> void {
        return native::wgpuTextureSetLabel(*this, label);
    }

    // TextureView Methods
    
    auto TextureView::label(CStr label) -> void {
        return native::wgpuTextureViewSetLabel(*this, label);
    }

} // namespace wgpu
