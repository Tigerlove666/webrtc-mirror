/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_SDK_ANDROID_SRC_JNI_PC_JAVA_NATIVE_CONVERSION_H_
#define WEBRTC_SDK_ANDROID_SRC_JNI_PC_JAVA_NATIVE_CONVERSION_H_

#include <vector>

#include "webrtc/api/datachannelinterface.h"
#include "webrtc/api/jsep.h"
#include "webrtc/api/jsepicecandidate.h"
#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/api/mediatypes.h"
#include "webrtc/api/peerconnectioninterface.h"
#include "webrtc/api/rtpparameters.h"
#include "webrtc/rtc_base/sslidentity.h"
#include "webrtc/sdk/android/src/jni/jni_helpers.h"

// This file contains helper methods for converting between simple C++ and Java
// PeerConnection-related structures. Similar to some methods in jni_helpers.h,
// but specifically for structures tied to the PeerConnection API.

namespace webrtc {
namespace jni {

DataChannelInit JavaToNativeDataChannelInit(JNIEnv* jni, jobject j_init);

cricket::MediaType JavaToNativeMediaType(JNIEnv* jni, jobject j_media_type);

jobject NativeToJavaMediaType(JNIEnv* jni, cricket::MediaType media_type);

cricket::Candidate JavaToNativeCandidate(JNIEnv* jni, jobject j_candidate);

jobject NativeToJavaCandidate(JNIEnv* jni,
                              jclass* candidate_class,
                              const cricket::Candidate& candidate);

jobjectArray NativeToJavaCandidateArray(
    JNIEnv* jni,
    const std::vector<cricket::Candidate>& candidates);

SessionDescriptionInterface* JavaToNativeSessionDescription(JNIEnv* jni,
                                                            jobject j_sdp);

jobject NativeToJavaSessionDescription(JNIEnv* jni,
                                       const SessionDescriptionInterface* desc);

PeerConnectionFactoryInterface::Options
JavaToNativePeerConnectionFactoryOptions(JNIEnv* jni, jobject options);

/*****************************************************
 * Below are all things that go into RTCConfiguration.
 *****************************************************/
PeerConnectionInterface::IceTransportsType JavaToNativeIceTransportsType(
    JNIEnv* jni,
    jobject j_ice_transports_type);

PeerConnectionInterface::BundlePolicy JavaToNativeBundlePolicy(
    JNIEnv* jni,
    jobject j_bundle_policy);

PeerConnectionInterface::RtcpMuxPolicy JavaToNativeRtcpMuxPolicy(
    JNIEnv* jni,
    jobject j_rtcp_mux_policy);

PeerConnectionInterface::TcpCandidatePolicy JavaToNativeTcpCandidatePolicy(
    JNIEnv* jni,
    jobject j_tcp_candidate_policy);

PeerConnectionInterface::CandidateNetworkPolicy
JavaToNativeCandidateNetworkPolicy(JNIEnv* jni,
                                   jobject j_candidate_network_policy);

rtc::KeyType JavaToNativeKeyType(JNIEnv* jni, jobject j_key_type);

PeerConnectionInterface::ContinualGatheringPolicy
JavaToNativeContinualGatheringPolicy(JNIEnv* jni, jobject j_gathering_policy);

PeerConnectionInterface::TlsCertPolicy JavaToNativeTlsCertPolicy(
    JNIEnv* jni,
    jobject j_ice_server_tls_cert_policy);

void JavaToNativeIceServers(JNIEnv* jni,
                            jobject j_ice_servers,
                            PeerConnectionInterface::IceServers* ice_servers);

void JavaToNativeRTCConfiguration(
    JNIEnv* jni,
    jobject j_rtc_config,
    PeerConnectionInterface::RTCConfiguration* rtc_config);

/*********************************************************
 * RtpParameters, used for RtpSender and RtpReceiver APIs.
 *********************************************************/
void JavaToNativeRtpParameters(JNIEnv* jni,
                               jobject j_parameters,
                               RtpParameters* parameters);

jobject NativeToJavaRtpParameters(JNIEnv* jni, const RtpParameters& parameters);

}  // namespace jni
}  // namespace webrtc

#endif  // WEBRTC_SDK_ANDROID_SRC_JNI_PC_JAVA_NATIVE_CONVERSION_H_
