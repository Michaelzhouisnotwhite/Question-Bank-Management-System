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

 Date: 19/12/2021 20:42:51
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for choice_question
-- ----------------------------
DROP TABLE IF EXISTS `choice_question`;
CREATE TABLE `choice_question`  (
  `choice_id` int(0) NOT NULL,
  `choice_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `option1` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `option2` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `option3` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `option4` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `choice_answer` enum('A','B','C','D') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`choice_id`) USING BTREE,
  CONSTRAINT `Choice_Qid` FOREIGN KEY (`choice_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of choice_question
-- ----------------------------
INSERT INTO `choice_question` VALUES (1, '在数据管理技术的发展过程中，经历了人工管理阶段、文件系统阶段和数据库系统阶段。在这几个阶段中，数据独立性最高的是  _ 阶段。', '数据库系', '文件系统', '人工管理', '数据项管理   ', 'A');
INSERT INTO `choice_question` VALUES (2, '同一个关系模型的任意两个元组值()', '不能完全相同', '可以完全相同 ', '必须完全相同', '以上都不对\r\n\r\n', 'A');
INSERT INTO `choice_question` VALUES (4, '一个关系数据库文件中的各条记录()', '前后顺序不能任意颠倒，一个要按照输入的顺序排列', '前后顺序可以任意颠倒，不影响库中的数据关系', '前后顺序可以任意颠倒，但排列顺序不同，统计处理的结果就可能不同', '前后顺序不能任意颠倒，一定按照关键字字段值的顺序排列\r\n\r\n', 'D');
INSERT INTO `choice_question` VALUES (8, '数据库的概念模型独立于 __   ', '具体的机器和DBMS', 'E-R图', '信息世界', '现实世界', 'B');
INSERT INTO `choice_question` VALUES (11, '数据库的基本特点是 __', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余大，易移植   (4)统一管理和控制', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据结构化 (2)数据互换性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据非结构化  (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制    ', 'A');
INSERT INTO `choice_question` VALUES (12, '数据库中存储的是___', '数据', '数据模型', ' 数据及数据间的联系', '信息 ', 'C');
INSERT INTO `choice_question` VALUES (13, '数据库中，数据的物理独立性是指  __', '数据库与数据库管理系统的相互独立', '用户程序与DBMS的相互独立', '用户的应用程序与存储在磁盘上数据库中的数据是相互独立的  ', '应用程序与数据库中数据的逻辑结构相互独立', 'C');

SET FOREIGN_KEY_CHECKS = 1;
