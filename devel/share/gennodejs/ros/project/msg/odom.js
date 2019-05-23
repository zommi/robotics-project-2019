// Auto-generated. Do not edit!

// (in-package project.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class odom {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x_value = null;
      this.y_value = null;
      this.theta = null;
    }
    else {
      if (initObj.hasOwnProperty('x_value')) {
        this.x_value = initObj.x_value
      }
      else {
        this.x_value = 0.0;
      }
      if (initObj.hasOwnProperty('y_value')) {
        this.y_value = initObj.y_value
      }
      else {
        this.y_value = 0.0;
      }
      if (initObj.hasOwnProperty('theta')) {
        this.theta = initObj.theta
      }
      else {
        this.theta = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type odom
    // Serialize message field [x_value]
    bufferOffset = _serializer.float64(obj.x_value, buffer, bufferOffset);
    // Serialize message field [y_value]
    bufferOffset = _serializer.float64(obj.y_value, buffer, bufferOffset);
    // Serialize message field [theta]
    bufferOffset = _serializer.float64(obj.theta, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type odom
    let len;
    let data = new odom(null);
    // Deserialize message field [x_value]
    data.x_value = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_value]
    data.y_value = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [theta]
    data.theta = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project/odom';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8759f9f7c1bf1b646c210b6a32c081e4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 x_value
    float64 y_value
    float64 theta
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new odom(null);
    if (msg.x_value !== undefined) {
      resolved.x_value = msg.x_value;
    }
    else {
      resolved.x_value = 0.0
    }

    if (msg.y_value !== undefined) {
      resolved.y_value = msg.y_value;
    }
    else {
      resolved.y_value = 0.0
    }

    if (msg.theta !== undefined) {
      resolved.theta = msg.theta;
    }
    else {
      resolved.theta = 0.0
    }

    return resolved;
    }
};

module.exports = odom;
