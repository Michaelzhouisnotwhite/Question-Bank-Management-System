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

 Date: 18/12/2021 22:41:22
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for shortanswer_question
-- ----------------------------
DROP TABLE IF EXISTS short_answer_question;
CREATE TABLE short_answer_question  (
  `shortAnswer_id` int(0) NOT NULL COMMENT '简答题题号',
  `shortAnswer_content` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '大题题干内容',
  PRIMARY KEY (`shortAnswer_id`) USING BTREE,
  CONSTRAINT `shortAnswer_Qid` FOREIGN KEY (`shortAnswer_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
