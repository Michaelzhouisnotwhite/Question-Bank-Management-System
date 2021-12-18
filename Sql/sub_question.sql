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

 Date: 18/12/2021 22:42:09
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for sub-question
-- ----------------------------
DROP TABLE IF EXISTS sub_question;
CREATE TABLE sub_question  (
  `Sub-question_id` int(0) NOT NULL,
  `shortAnswer_id` int(0) NOT NULL,
  `Sub-question_No` int(0) NOT NULL,
  `Sub-question_content` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Sub-question_answer` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Sub-question_score` int(0) NOT NULL,
  PRIMARY KEY (`Sub-question_id`, `shortAnswer_id`) USING BTREE,
  INDEX `Sub-question_SAid`(`shortAnswer_id`) USING BTREE,
  CONSTRAINT `Sub-question_SAid` FOREIGN KEY (`shortAnswer_id`) REFERENCES `short_answer_question` (`shortAnswer_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
