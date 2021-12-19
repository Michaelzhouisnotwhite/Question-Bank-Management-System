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

 Date: 19/12/2021 19:59:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for chapter
-- ----------------------------
DROP TABLE IF EXISTS `chapter`;
CREATE TABLE `chapter`  (
  `chapter_id` int(0) NOT NULL COMMENT '章节号',
  `chapter_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `course_id` int(0) NOT NULL,
  PRIMARY KEY (`chapter_id`) USING BTREE,
  INDEX `Chapter_Course`(`course_id`) USING BTREE,
  CONSTRAINT `Chapter_Course` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of chapter
-- ----------------------------
INSERT INTO `chapter` VALUES (101, '第一章 绪论', 1);
INSERT INTO `chapter` VALUES (102, '第二章 关系数据库', 1);
INSERT INTO `chapter` VALUES (103, '第三章 关系数据库标准语言SQL', 1);
INSERT INTO `chapter` VALUES (104, '第四章 数据库安全性', 1);
INSERT INTO `chapter` VALUES (105, '第一章 运动何莉6', 2);
INSERT INTO `chapter` VALUES (106, '第二章 运动的守恒量', 2);
INSERT INTO `chapter` VALUES (107, '第三章 刚体和流体的运动', 2);
INSERT INTO `chapter` VALUES (108, '第一章 微积分', 3);
INSERT INTO `chapter` VALUES (109, '第二章 分布积分', 3);
INSERT INTO `chapter` VALUES (110, '第一章 流密码', 4);
INSERT INTO `chapter` VALUES (111, '第二章 公钥密码', 4);
INSERT INTO `chapter` VALUES (112, '第一章 挖泥', 5);
INSERT INTO `chapter` VALUES (113, '第二章 烧火', 5);

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
  `choice_answer` char(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`choice_id`) USING BTREE,
  CONSTRAINT `Choice_Qid` FOREIGN KEY (`choice_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of choice_question
-- ----------------------------
INSERT INTO `choice_question` VALUES (1, '在数据管理技术的发展过程中，经历了人工管理阶段、文件系统阶段和数据库系统阶段。在这几个阶段中，数据独立性最高的是  _ 阶段。', '数据库系', '文件系统', '人工管理', '数据项管理   ', 'A');
INSERT INTO `choice_question` VALUES (2, '关系代数运算是以_为基础的运算', '关系运算', '谓词运算', '集合运算', '代数运算', 'C');
INSERT INTO `choice_question` VALUES (8, '数据库的概念模型独立于 __   ', '具体的机器和DBMS', 'E-R图', '信息世界', '现实世界', 'A');
INSERT INTO `choice_question` VALUES (11, '数据库的基本特点是 __', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余大，易移植   (4)统一管理和控制', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据结构化 (2)数据互换性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据非结构化  (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制    ', 'B');
INSERT INTO `choice_question` VALUES (12, '数据库中存储的是___', '数据', '数据模型', ' 数据及数据间的联系', '信息 ', 'C');
INSERT INTO `choice_question` VALUES (13, '数据库中，数据的物理独立性是指  __', '数据库与数据库管理系统的相互独立', '用户程序与DBMS的相互独立', '用户的应用程序与存储在磁盘上数据库中的数据是相互独立的  ', '应用程序与数据库中数据的逻辑结构相互独立', 'C');

-- ----------------------------
-- Table structure for completion_question
-- ----------------------------
DROP TABLE IF EXISTS `completion_question`;
CREATE TABLE `completion_question`  (
  `completion_id` int(0) NOT NULL,
  `completion_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `completion_answer1` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer2` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer3` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer4` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer5` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`completion_id`) USING BTREE,
  CONSTRAINT `Completion_Qid` FOREIGN KEY (`completion_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of completion_question
-- ----------------------------
INSERT INTO `completion_question` VALUES (7, '数据管理技术经历了 _____ 、 _____ 和 ______三个阶段', '人工管理 ', '文件系统', '数据库系统', NULL, NULL);
INSERT INTO `completion_question` VALUES (14, '数据库是长期存储在计算机内、有_____的、可 _____的数据集合', '组织', '共享', NULL, NULL, NULL);
INSERT INTO `completion_question` VALUES (15, 'DBMS是指 _______ 它是位于 _____ 和 _______ 之间的一层管理软件', 'DBMS', '用户', '操作系统', NULL, NULL);
INSERT INTO `completion_question` VALUES (16, '数据独立性又可分为_________和_________ ', '逻辑数据独立性', '物理数据独立性', NULL, NULL, NULL);

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course`  (
  `course_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '课程号',
  `course_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '课程名',
  PRIMARY KEY (`course_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES (1, '数据库');
INSERT INTO `course` VALUES (2, '大学物理');
INSERT INTO `course` VALUES (3, '高等数学');
INSERT INTO `course` VALUES (4, '计算机密码学');
INSERT INTO `course` VALUES (5, '陶艺');

-- ----------------------------
-- Table structure for course_questiontype
-- ----------------------------
DROP TABLE IF EXISTS `course_questiontype`;
CREATE TABLE `course_questiontype`  (
  `Cqtype_course_id` int(0) NOT NULL,
  `Cqtype_Qtype_id` int(0) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`Cqtype_course_id`, `Cqtype_Qtype_id`) USING BTREE,
  INDEX `Cqtype_Qtype`(`Cqtype_Qtype_id`) USING BTREE,
  CONSTRAINT `Cqtype_Course` FOREIGN KEY (`Cqtype_course_id`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Cqtype_Qtype` FOREIGN KEY (`Cqtype_Qtype_id`) REFERENCES `question_type` (`question_type_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of course_questiontype
-- ----------------------------
INSERT INTO `course_questiontype` VALUES (1, 1);
INSERT INTO `course_questiontype` VALUES (2, 1);
INSERT INTO `course_questiontype` VALUES (3, 1);
INSERT INTO `course_questiontype` VALUES (5, 1);
INSERT INTO `course_questiontype` VALUES (1, 2);
INSERT INTO `course_questiontype` VALUES (2, 2);
INSERT INTO `course_questiontype` VALUES (1, 3);
INSERT INTO `course_questiontype` VALUES (1, 4);
INSERT INTO `course_questiontype` VALUES (3, 4);

-- ----------------------------
-- Table structure for examination
-- ----------------------------
DROP TABLE IF EXISTS `examination`;
CREATE TABLE `examination`  (
  `examination_id` int(10) UNSIGNED ZEROFILL NOT NULL AUTO_INCREMENT,
  `course_id` int(0) NOT NULL,
  `examination_time` datetime(0) NOT NULL,
  `examination_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`examination_id`) USING BTREE,
  INDEX `Examination_Courseid`(`course_id`) USING BTREE,
  CONSTRAINT `Examination_Courseid` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for judgment_question
-- ----------------------------
DROP TABLE IF EXISTS `judgment_question`;
CREATE TABLE `judgment_question`  (
  `judgment_id` int(0) NOT NULL COMMENT '判断题题号',
  `judgment_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '判断题内容',
  `judgment_answer` tinyint(0) NOT NULL COMMENT '判断题答案，0为错，1为对',
  PRIMARY KEY (`judgment_id`) USING BTREE,
  CONSTRAINT `Judgment_Qid` FOREIGN KEY (`judgment_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of judgment_question
-- ----------------------------
INSERT INTO `judgment_question` VALUES (5, '数据库管理系统设计不是DBA数据库管理员的职责 ', 1);
INSERT INTO `judgment_question` VALUES (17, '子模式是用户或应用程序看到的那部分局部逻辑结构和特征的描述', 1);
INSERT INTO `judgment_question` VALUES (18, '描述数据库全体数据的全局逻辑结构和特性的是外模式', 0);

-- ----------------------------
-- Table structure for question
-- ----------------------------
DROP TABLE IF EXISTS `question`;
CREATE TABLE `question`  (
  `question_id` int(0) NOT NULL AUTO_INCREMENT,
  `question_trigger` int(0) NOT NULL,
  `question_time` datetime(0) NOT NULL,
  `question_type_id` int(0) NOT NULL,
  `question_chapter_id` int(0) NOT NULL,
  PRIMARY KEY (`question_id`) USING BTREE,
  INDEX `Question_QType`(`question_type_id`) USING BTREE,
  INDEX `Question_Chapter`(`question_chapter_id`) USING BTREE,
  CONSTRAINT `Question_Chapter` FOREIGN KEY (`question_chapter_id`) REFERENCES `chapter` (`chapter_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Question_QType` FOREIGN KEY (`question_type_id`) REFERENCES `question_type` (`question_type_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of question
-- ----------------------------
INSERT INTO `question` VALUES (1, 0, '2021-12-19 19:25:16', 1, 101);
INSERT INTO `question` VALUES (2, 0, '2021-12-02 19:25:59', 1, 102);
INSERT INTO `question` VALUES (3, 0, '2021-12-19 19:26:27', 2, 101);
INSERT INTO `question` VALUES (4, 0, '2021-12-19 19:26:49', 1, 108);
INSERT INTO `question` VALUES (5, 0, '2021-12-20 19:27:11', 3, 101);
INSERT INTO `question` VALUES (6, 0, '2021-12-09 19:27:27', 2, 102);
INSERT INTO `question` VALUES (7, 0, '2021-12-17 19:27:51', 4, 101);
INSERT INTO `question` VALUES (8, 0, '2021-12-19 19:28:28', 1, 101);
INSERT INTO `question` VALUES (9, 0, '2021-12-19 19:28:44', 2, 105);
INSERT INTO `question` VALUES (10, 0, '2021-12-19 19:29:03', 2, 106);
INSERT INTO `question` VALUES (11, 0, '2021-12-19 19:29:19', 1, 101);
INSERT INTO `question` VALUES (12, 0, '2021-12-19 19:29:57', 1, 101);
INSERT INTO `question` VALUES (13, 0, '2021-12-19 19:30:29', 1, 101);
INSERT INTO `question` VALUES (14, 0, '2021-12-19 19:30:48', 4, 101);
INSERT INTO `question` VALUES (15, 0, '2021-12-19 19:31:13', 4, 101);
INSERT INTO `question` VALUES (16, 0, '2021-12-19 19:31:40', 4, 101);
INSERT INTO `question` VALUES (17, 0, '2021-12-19 19:31:58', 3, 101);
INSERT INTO `question` VALUES (18, 0, '2021-12-19 19:32:10', 3, 101);
INSERT INTO `question` VALUES (19, 0, '2021-12-19 19:32:30', 2, 101);
INSERT INTO `question` VALUES (20, 0, '2021-12-19 19:32:43', 2, 102);

-- ----------------------------
-- Table structure for question_type
-- ----------------------------
DROP TABLE IF EXISTS `question_type`;
CREATE TABLE `question_type`  (
  `question_type_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '题型号',
  `question_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '题型名',
  PRIMARY KEY (`question_type_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of question_type
-- ----------------------------
INSERT INTO `question_type` VALUES (1, '选择题');
INSERT INTO `question_type` VALUES (2, '简答题');
INSERT INTO `question_type` VALUES (3, '判断题');
INSERT INTO `question_type` VALUES (4, '填空题');

-- ----------------------------
-- Table structure for shortanswer_question
-- ----------------------------
DROP TABLE IF EXISTS `shortanswer_question`;
CREATE TABLE `shortanswer_question`  (
  `shortAnswer_id` int(0) NOT NULL COMMENT '简答题题号',
  `shortAnswer_content` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '大题题干内容',
  PRIMARY KEY (`shortAnswer_id`) USING BTREE,
  CONSTRAINT `shortAnswer_Qid` FOREIGN KEY (`shortAnswer_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for sub-question
-- ----------------------------
DROP TABLE IF EXISTS `sub-question`;
CREATE TABLE `sub-question`  (
  `Sub-question_id` int(0) NOT NULL,
  `shortAnswer_id` int(0) NOT NULL,
  `Sub-question_No` int(0) NOT NULL,
  `Sub-question_content` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Sub-question_answer` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Sub-question_score` int(0) NOT NULL,
  PRIMARY KEY (`Sub-question_id`, `shortAnswer_id`) USING BTREE,
  INDEX `Sub-question_SAid`(`shortAnswer_id`) USING BTREE,
  CONSTRAINT `Sub-question_SAid` FOREIGN KEY (`shortAnswer_id`) REFERENCES `shortanswer_question` (`shortAnswer_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for tc
-- ----------------------------
DROP TABLE IF EXISTS `tc`;
CREATE TABLE `tc`  (
  `course` int(0) NOT NULL COMMENT '课程号',
  `teacher` int(0) NOT NULL COMMENT '教师号',
  PRIMARY KEY (`course`, `teacher`) USING BTREE,
  CONSTRAINT `Tcourse_Course` FOREIGN KEY (`course`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Tcourse_Teacher` FOREIGN KEY (`course`) REFERENCES `teacher` (`teacher_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of tc
-- ----------------------------
INSERT INTO `tc` VALUES (1, 120191081);
INSERT INTO `tc` VALUES (1, 120191082);
INSERT INTO `tc` VALUES (1, 120191083);
INSERT INTO `tc` VALUES (2, 120191084);
INSERT INTO `tc` VALUES (3, 120191082);
INSERT INTO `tc` VALUES (4, 120191081);
INSERT INTO `tc` VALUES (5, 120191083);

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
INSERT INTO `teacher` VALUES (1201910, '张学友', '1111', NULL);
INSERT INTO `teacher` VALUES (120191080, '马德华 ', '2222', NULL);
INSERT INTO `teacher` VALUES (120191082, '猪八戒', '3333', NULL);
INSERT INTO `teacher` VALUES (120191084, '艾什', '4444', NULL);

SET FOREIGN_KEY_CHECKS = 1;
