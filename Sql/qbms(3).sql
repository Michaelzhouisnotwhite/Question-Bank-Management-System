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

 Date: 25/12/2021 17:26:27
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
  `choice_answer` enum('A','B','C','D') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`choice_id`) USING BTREE,
  CONSTRAINT `Choice_Qid` FOREIGN KEY (`choice_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of choice_question
-- ----------------------------
INSERT INTO `choice_question` VALUES (1, '题干内容', '选项A', '选项b', '选项c', '选项d', 'B');
INSERT INTO `choice_question` VALUES (2, '同一个关系模型的任意两个元组值()', '不能完全相同', '可以完全相同 ', '必须完全相同', '以上都不对\r\n\r\n', 'A');
INSERT INTO `choice_question` VALUES (4, '一个关系数据库文件中的各条记录()', '前后顺序不能任意颠倒，一个要按照输入的顺序排列', '前后顺序可以任意颠倒，不影响库中的数据关系', '前后顺序可以任意颠倒，但排列顺序不同，统计处理的结果就可能不同', '前后顺序不能任意颠倒，一定按照关键字字段值的顺序排列\r\n\r\n', 'D');
INSERT INTO `choice_question` VALUES (8, '数据库的概念模型独立于 __   ', '具体的机器和DBMS', 'E-R图', '信息世界', '现实世界', 'B');
INSERT INTO `choice_question` VALUES (11, '数据库的基本特点是 __', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余大，易移植   (4)统一管理和控制', '(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据结构化 (2)数据互换性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '(1)数据非结构化  (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制    ', 'A');
INSERT INTO `choice_question` VALUES (12, '数据库中存储的是___', '数据', '数据模型', ' 数据及数据间的联系', '信息 ', 'C');
INSERT INTO `choice_question` VALUES (13, '数据库中，数据的物理独立性是指  __', '数据库与数据库管理系统的相互独立', '用户程序与DBMS的相互独立', '用户的应用程序与存储在磁盘上数据库中的数据是相互独立的  ', '应用程序与数据库中数据的逻辑结构相互独立', 'C');
INSERT INTO `choice_question` VALUES (21, '在下列选项中，___不是基本关系的性质。', '不同列应有不同的数据类型', '不同列应有不同的列名', '行的顺序可以任意', '列的顺序可以任意', 'A');
INSERT INTO `choice_question` VALUES (22, '关系数据库和关系数据库模式之间的关系是 __', '关系数据库是型，关系数据库模式是它的值', '关系数据库模式是型，关系数据库是它的值', '关系数据库模式是关系数据库的集合', '关系数据库是关系数据库模式的集合', 'B');
INSERT INTO `choice_question` VALUES (23, '关系和关系数据库之间的关系是。', '关系数据库是型，关系是它的值', '关系是型，关系数据库是它的值', '关系数据库是关系的集合', '关系是关系数据库的集合', 'C');
INSERT INTO `choice_question` VALUES (24, '以下__不属于实现数据库系统安全性的主要技术和方法', '存取控制技术', '视图技术', '审计技术', '出入机房登记和加锁 ', 'D');
INSERT INTO `choice_question` VALUES (27, '在数据库的安全性控制中，授权的数据对象的__，授权子系统就越灵活。', '范围越小', '约束越细致', '范围越大', '约束范围大', 'A');
INSERT INTO `choice_question` VALUES (29, '台球日益成为人们喜爱的运动项目。下列关于台球受力及运动的说法，其中错误的是（ ）', '台球对桌面的压力与桌面对台球的支持力相互平衡', '球杆击球时，杆对球的力与球对杆的力是相互作用力', '击打球的不同部位，球的旋转方向不同，表明力的作用效果与力的作用点有关', '运动的台球在碰到桌边后会改变运动方向，表明力可以改变物体的运动状态', 'A');
INSERT INTO `choice_question` VALUES (30, '微分方程(y\")2+y\'+ ysinx=0的类型是( )', '四阶线性方程', '二阶线性方程', '四阶非线性方程', '二阶非线性方程', 'B');

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
INSERT INTO `completion_question` VALUES (7, '填空题题干', '空1答案', '空2答案', '空3答案', '空4答案', '空5答案');
INSERT INTO `completion_question` VALUES (9, '如图，用 100 牛的力把一个重为 10 牛的物体压在竖直墙壁上，物体处于静止状\r\n态。当压力减为 50 牛时，物体沿竖直墙壁匀速下滑，则物体下滑时受到的摩擦力大\r\n小是__\r\n', '10 牛', NULL, NULL, NULL, NULL);
INSERT INTO `completion_question` VALUES (10, '一个重为2N的长方体木块，在水平桌面上做匀速直线运动时，受到的水平拉力为0.6N，若水平拉力增大为0.8N时，此时木块受到的摩擦力与合力的大小分别为（ ）', '1.0N', '2.0N', NULL, NULL, NULL);
INSERT INTO `completion_question` VALUES (14, '数据库是长期存储在计算机内、有_____的、可 _____的数据集合', '组织', '共享', NULL, NULL, NULL);
INSERT INTO `completion_question` VALUES (15, 'DBMS是指 _______ 它是位于 _____ 和 _______ 之间的一层管理软件', 'DBMS', '用户', '操作系统', NULL, NULL);
INSERT INTO `completion_question` VALUES (16, '数据独立性又可分为_________和_________ ', '逻辑数据独立性', '物理数据独立性', NULL, NULL, NULL);
INSERT INTO `completion_question` VALUES (26, 'SQL语言的GRANT和REMOVE语句主要是用来维护数据库的', '安全性', NULL, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course`  (
  `course_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '课程号',
  `course_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '课程名',
  PRIMARY KEY (`course_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
INSERT INTO `judgment_question` VALUES (3, '判断题内容', '对');
INSERT INTO `judgment_question` VALUES (5, '数据库管理系统设计不是DBA数据库管理员的职责 ', '对');
INSERT INTO `judgment_question` VALUES (6, '数据库的概念模型独立于  具体的机器和DBMS  ', '对');
INSERT INTO `judgment_question` VALUES (17, '子模式是用户或应用程序看到的那部分局部逻辑结构和特征的描述', '对');
INSERT INTO `judgment_question` VALUES (18, '描述数据库全体数据的全局逻辑结构和特性的是外模式', '错');
INSERT INTO `judgment_question` VALUES (19, '数据库的基本特点是(1)数据结构化 (2)数据独立性  (3)数据共享性高，冗余小，易扩充   (4)统一管理和控制', '对');
INSERT INTO `judgment_question` VALUES (20, '1．在下列选项中,不同的列应有不同的数据类型不是基本关系的性质。', '对');
INSERT INTO `judgment_question` VALUES (25, 'SQL中的视图提高了数据库系统的安全性', '对');
INSERT INTO `judgment_question` VALUES (28, '物体运动状态改变时，一定受到力的作用', '对');
INSERT INTO `judgment_question` VALUES (31, '浴室脚垫做得凹凸不平目的是为了减小摩擦', '错');
INSERT INTO `judgment_question` VALUES (32, '飞轮绕定轴作匀速转动时，飞轮边缘上任一点的切向加速度为零,法向加速度不为零', '对');
INSERT INTO `judgment_question` VALUES (33, 'SQL中的视图机制提高了数据库系统的安全性', '对');

-- ----------------------------
-- Table structure for question
-- ----------------------------
DROP TABLE IF EXISTS `question`;
CREATE TABLE `question`  (
  `question_id` int(0) NOT NULL AUTO_INCREMENT,
  `question_trigger` int(0) NOT NULL DEFAULT 0,
  `question_time` timestamp(0) NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP(0),
  `question_type_id` int(0) NOT NULL,
  `question_chapter_id` int(0) NOT NULL,
  PRIMARY KEY (`question_id`) USING BTREE,
  INDEX `Question_QType`(`question_type_id`) USING BTREE,
  INDEX `Question_Chapter`(`question_chapter_id`) USING BTREE,
  CONSTRAINT `Question_Chapter` FOREIGN KEY (`question_chapter_id`) REFERENCES `chapter` (`chapter_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Question_QType` FOREIGN KEY (`question_type_id`) REFERENCES `question_type` (`question_type_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 33 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of question
-- ----------------------------
INSERT INTO `question` VALUES (1, 0, '2021-12-19 19:25:16', 1, 101);
INSERT INTO `question` VALUES (2, 0, '2021-12-02 19:25:59', 1, 102);
INSERT INTO `question` VALUES (3, 0, '2021-12-19 19:26:27', 3, 101);
INSERT INTO `question` VALUES (4, 0, '2021-12-19 19:26:49', 1, 101);
INSERT INTO `question` VALUES (5, 0, '2021-12-20 19:27:11', 3, 101);
INSERT INTO `question` VALUES (6, 0, '2021-12-09 19:27:27', 3, 102);
INSERT INTO `question` VALUES (7, 0, '2021-12-17 19:27:51', 4, 101);
INSERT INTO `question` VALUES (8, 0, '2021-12-19 19:28:28', 1, 101);
INSERT INTO `question` VALUES (9, 0, '2021-12-19 19:28:44', 4, 105);
INSERT INTO `question` VALUES (10, 0, '2021-12-19 19:29:03', 4, 106);
INSERT INTO `question` VALUES (11, 0, '2021-12-19 19:29:19', 1, 101);
INSERT INTO `question` VALUES (12, 0, '2021-12-19 19:29:57', 1, 101);
INSERT INTO `question` VALUES (13, 0, '2021-12-19 19:30:29', 1, 101);
INSERT INTO `question` VALUES (14, 0, '2021-12-19 19:30:48', 4, 101);
INSERT INTO `question` VALUES (15, 0, '2021-12-19 19:31:13', 4, 101);
INSERT INTO `question` VALUES (16, 0, '2021-12-19 19:31:40', 4, 101);
INSERT INTO `question` VALUES (17, 0, '2021-12-19 19:31:58', 3, 101);
INSERT INTO `question` VALUES (18, 0, '2021-12-19 19:32:10', 3, 101);
INSERT INTO `question` VALUES (19, 0, '2021-12-19 19:32:30', 3, 101);
INSERT INTO `question` VALUES (20, 0, '2021-12-19 19:32:43', 3, 102);
INSERT INTO `question` VALUES (21, 0, '2021-12-20 01:06:09', 1, 101);
INSERT INTO `question` VALUES (22, 0, '2021-12-20 01:06:31', 1, 102);
INSERT INTO `question` VALUES (23, 0, '2021-12-20 01:06:55', 1, 103);
INSERT INTO `question` VALUES (24, 0, '2021-12-20 01:07:09', 1, 104);
INSERT INTO `question` VALUES (25, 0, '2021-12-20 01:30:24', 3, 104);
INSERT INTO `question` VALUES (26, 0, '2021-12-20 01:31:23', 4, 104);
INSERT INTO `question` VALUES (27, 0, '2021-12-20 01:32:23', 1, 104);
INSERT INTO `question` VALUES (28, 0, '2021-12-20 01:35:13', 3, 106);
INSERT INTO `question` VALUES (29, 0, '2021-12-20 01:37:08', 1, 105);
INSERT INTO `question` VALUES (30, 0, '2021-12-20 01:38:30', 1, 108);
INSERT INTO `question` VALUES (31, 0, '2021-12-20 01:43:58', 3, 105);
INSERT INTO `question` VALUES (32, 0, '2021-12-20 01:45:56', 3, 107);
INSERT INTO `question` VALUES (33, 0, '2021-12-20 01:49:12', 3, 108);
INSERT INTO `question` VALUES (34, 0, '2021-12-25 17:25:08', 1, 101);

-- ----------------------------
-- Table structure for question_type
-- ----------------------------
DROP TABLE IF EXISTS `question_type`;
CREATE TABLE `question_type`  (
  `question_type_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '题型号',
  `question_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '题型名',
  PRIMARY KEY (`question_type_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
  INDEX `Tcourse_Teacher`(`teacher`) USING BTREE,
  CONSTRAINT `Tcourse_Course` FOREIGN KEY (`course`) REFERENCES `course` (`course_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Tcourse_Teacher` FOREIGN KEY (`teacher`) REFERENCES `teacher` (`teacher_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of tc
-- ----------------------------
INSERT INTO `tc` VALUES (1, 123);
INSERT INTO `tc` VALUES (2, 123);
INSERT INTO `tc` VALUES (1, 120191081);
INSERT INTO `tc` VALUES (4, 120191081);
INSERT INTO `tc` VALUES (1, 120191082);
INSERT INTO `tc` VALUES (3, 120191082);
INSERT INTO `tc` VALUES (1, 120191083);
INSERT INTO `tc` VALUES (5, 120191083);
INSERT INTO `tc` VALUES (2, 120191084);

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

-- ----------------------------
-- View structure for class_q_type_view
-- ----------------------------
DROP VIEW IF EXISTS class_q_type_view;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW class_q_type_view AS select `course`.`course_name` AS `course_name`,`question_type`.`question_name` AS `question_name` from ((`course_questiontype` join `course` on((`course_questiontype`.`Cqtype_course_id` = `course`.`course_id`))) join `question_type` on((`course_questiontype`.`Cqtype_Qtype_id` = `question_type`.`question_type_id`))) order by `course`.`course_name`;

SET FOREIGN_KEY_CHECKS = 1;
