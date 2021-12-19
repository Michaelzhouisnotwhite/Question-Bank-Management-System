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

 Date: 19/12/2021 20:16:24
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for judgment_question
-- ----------------------------
DROP TABLE IF EXISTS `judgment_question`;
CREATE TABLE `judgment_question`  (
  `judgment_id` int(0) NOT NULL COMMENT '判断题题号',
  `judgment_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '判断题内容',
  `judgment_answer` enum('对','错') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '判断题答案',
  PRIMARY KEY (`judgment_id`) USING BTREE,
  CONSTRAINT `Judgment_Qid` FOREIGN KEY (`judgment_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of judgment_question
-- ----------------------------
INSERT INTO `judgment_question` VALUES (5, '数据库管理系统设计不是DBA数据库管理员的职责 ', '对');
INSERT INTO `judgment_question` VALUES (17, '子模式是用户或应用程序看到的那部分局部逻辑结构和特征的描述', '对');
INSERT INTO `judgment_question` VALUES (18, '描述数据库全体数据的全局逻辑结构和特性的是外模式', '错');

SET FOREIGN_KEY_CHECKS = 1;
