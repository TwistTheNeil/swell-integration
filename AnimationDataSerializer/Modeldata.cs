//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: AnimationDataSerializer/modeldata.proto
namespace swellanimations
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Animation")]
  public partial class Animation : global::ProtoBuf.IExtensible
  {
    public Animation() {}
    
    private readonly global::System.Collections.Generic.List<swellanimations.Node> _frames = new global::System.Collections.Generic.List<swellanimations.Node>();
    [global::ProtoBuf.ProtoMember(1, Name=@"frames", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<swellanimations.Node> frames
    {
      get { return _frames; }
    }
  
    private int _framesPerSecond = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"framesPerSecond", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int framesPerSecond
    {
      get { return _framesPerSecond; }
      set { _framesPerSecond = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Node")]
  public partial class Node : global::ProtoBuf.IExtensible
  {
    public Node() {}
    
    private string _name = "";
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"name", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue("")]
    public string name
    {
      get { return _name; }
      set { _name = value; }
    }
    private float _positionX = default(float);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"positionX", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float positionX
    {
      get { return _positionX; }
      set { _positionX = value; }
    }
    private float _positionY = default(float);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"positionY", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float positionY
    {
      get { return _positionY; }
      set { _positionY = value; }
    }
    private float _positionZ = default(float);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"positionZ", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float positionZ
    {
      get { return _positionZ; }
      set { _positionZ = value; }
    }
    private float _rotationX = default(float);
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"rotationX", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float rotationX
    {
      get { return _rotationX; }
      set { _rotationX = value; }
    }
    private float _rotationY = default(float);
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"rotationY", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float rotationY
    {
      get { return _rotationY; }
      set { _rotationY = value; }
    }
    private float _rotationZ = default(float);
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"rotationZ", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue(default(float))]
    public float rotationZ
    {
      get { return _rotationZ; }
      set { _rotationZ = value; }
    }
    private readonly global::System.Collections.Generic.List<swellanimations.Node> _children = new global::System.Collections.Generic.List<swellanimations.Node>();
    [global::ProtoBuf.ProtoMember(8, Name=@"children", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<swellanimations.Node> children
    {
      get { return _children; }
    }
  
    private swellanimations.Node _parent = null;
    [global::ProtoBuf.ProtoMember(9, IsRequired = false, Name=@"parent", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public swellanimations.Node parent
    {
      get { return _parent; }
      set { _parent = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}