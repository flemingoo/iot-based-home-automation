-- phpMyAdmin SQL Dump
-- version 4.0.10.14
-- http://www.phpmyadmin.net
--
-- Host: localhost:3306
-- Generation Time: May 21, 2016 at 04:31 AM
-- Server version: 5.5.49-cll
-- PHP Version: 5.4.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `digitale_sHomeDb`
--

-- --------------------------------------------------------

--
-- Table structure for table `thresholds_auto`
--

CREATE TABLE IF NOT EXISTS `thresholds_auto` (
  `node` varchar(5) NOT NULL,
  `light` varchar(5) NOT NULL,
  `hvac` varchar(5) NOT NULL,
  `window` varchar(5) NOT NULL,
  `pir` varchar(5) NOT NULL,
  UNIQUE KEY `node` (`node`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `thresholds_auto`
--

INSERT INTO `thresholds_auto` (`node`, `light`, `hvac`, `window`, `pir`) VALUES
('node1', '611', '254', '869', '456'),
('node2', '763', '295', '181', '100'),
('node3', '729', '100', '293', '258');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
