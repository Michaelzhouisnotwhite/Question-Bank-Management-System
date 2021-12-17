/*
 Navicat Premium Data Transfer

 Source Server         : 1
 Source Server Type    : MySQL
 Source Server Version : 80022
 Source Host           : localhost:3306
 Source Schema         : 题目管理系统

 Target Server Type    : MySQL
 Target Server Version : 80022
 File Encoding         : 65001

 Date: 15/12/2021 19:13:38
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
-- Table structure for choicequestion
-- ----------------------------
DROP TABLE IF EXISTS choice_question;
CREATE TABLE choice_question  (
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
-- Table structure for completionquestion
-- ----------------------------
DROP TABLE IF EXISTS completion_question;
CREATE TABLE completion_question  (
  `completion_id` int(0) NOT NULL,
  `completion_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `blank1` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `blank2` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `blank3` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `blank4` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `blank5` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer1` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer2` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer3` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer4` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `completion_answer5` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`completion_id`) USING BTREE,
  CONSTRAINT `Completion_Qid` FOREIGN KEY (`completion_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course`  (
  `course_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '课程号',
  `course_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '课程名',
  PRIMARY KEY (`course_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for `course_questiontype`
-- ----------------------------
DROP TABLE IF EXISTS `course_questiontype`;
create table course_questiontype
(
    Cqtype_course_id int(0) not null,
    Cqtype_Qtype_id  int(0),
    primary key (Cqtype_course_id, Cqtype_Qtype_id),
    constraint Cqtype_Course
        foreign key (Cqtype_course_id) references course (course_id)
            on update cascade on delete cascade,
    constraint Cqtype_Qtype
        foreign key (Cqtype_Qtype_id) references question_type (question_type_id)
            on update cascade on delete cascade
)
    engine = InnoDB
    collate = utf8mb4_0900_ai_ci;

alter table course_questiontype
    modify Cqtype_Qtype_id int(0) auto_increment;



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
-- Table structure for judgmentquestion
-- ----------------------------
DROP TABLE IF EXISTS judgment_question;
CREATE TABLE judgment_question  (
  `judgment_id` int(0) NOT NULL COMMENT '判断题题号',
  `judgment_content` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '判断题内容',
  `judgment_answer` tinyint(0) NOT NULL COMMENT '判断题答案，0为错，1为对',
  PRIMARY KEY (`judgment_id`) USING BTREE,
  CONSTRAINT `Judgment_Qid` FOREIGN KEY (`judgment_id`) REFERENCES `question` (`question_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
  CONSTRAINT `Question_QType` FOREIGN KEY (`question_type_id`) REFERENCES question_type (`question_type_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Question_Chapter` FOREIGN KEY (`question_chapter_id`) REFERENCES `chapter` (`chapter_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for questiontype
-- ----------------------------
DROP TABLE IF EXISTS question_type;
CREATE TABLE question_type  (
  `question_type_id` int(0) NOT NULL AUTO_INCREMENT COMMENT '题型号',
  `question_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '题型名',
  PRIMARY KEY (`question_type_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

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
-- Table structure for teacher
-- ----------------------------
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher`  (
  `teacher_id` int(0) NOT NULL COMMENT '教师号',
  `teacher_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '教师名',
  `teacher_code` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '教师登录密码',
  `teacher_photo` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '教师照片',
  PRIMARY KEY (`teacher_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
