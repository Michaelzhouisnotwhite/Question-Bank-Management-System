/*
 Navicat Premium Data Transfer

 Source Server         : 1
 Source Server Type    : MySQL
 Source Server Version : 80022
 Source Host           : localhost:3306
 Source Schema         : qbms

 Target Server Type    : MySQL
 Target Server Version : 80022
 File Encoding         : 65001

 Date: 19/12/2021 21:11:37
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for teacher
-- ----------------------------
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher`  (
  `teacher_id` int(0) NOT NULL COMMENT '教师号',
  `teacher_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教师名',
  `teacher_psw` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教师登录密码',
  `teacher_photo` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '教师照片',
  PRIMARY KEY (`teacher_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of teacher
-- ----------------------------
INSERT INTO `teacher` VALUES (123, 'admin', '123', NULL);
INSERT INTO `teacher` VALUES (120191080, '马德华 ', '2222', NULL);
INSERT INTO `teacher` VALUES (120191081, '张学友', '1111', NULL);
INSERT INTO `teacher` VALUES (120191082, '猪八戒', '3333', NULL);
INSERT INTO `teacher` VALUES (120191083, '胡思鹏', '1654', NULL);
INSERT INTO `teacher` VALUES (120191084, '艾什', '4444', NULL);

SET FOREIGN_KEY_CHECKS = 1;
